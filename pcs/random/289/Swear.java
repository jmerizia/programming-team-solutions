import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Swear{
  public static void main(String[] args){
    Scanner s = new Scanner(System.in);
    HashSet<Long> set = new HashSet<>();
    int n = s.nextInt();
    int k = s.nextInt();
    for (int i = 0; i < n; i++) {
      String word = s.next();
      HashStructure temp = new HashStructure(word);
      long hash = temp.getSubstringHash(0, k);
      set.add(hash);
    }
    String book = s.next();
    HashStructure struct = new HashStructure(book);
    int count = 0;
    for (int i = 0; i < book.length() - k+1; i++) {
      long l = struct.getSubstringHash(i, i+k);
      if (set.contains(l)) count++;
    }
    System.out.println(count);

  }

  //Collision probability: 10^-16
  //constructor is O(n)
  //getSubstringHash is O(1)
  public static class HashStructure {
    String str;
    final long chunk_size = 100000000;
    final long prime = 10000000000000061l;
    final long base = 257;
    long[] prefixHashes;
    long[] cachePower;

    public HashStructure(String in) {
      str = in;
      buildPrefixHashes();
      makePowerCache();
    }

    private void buildPrefixHashes() {
      prefixHashes = new long[str.length()+1];
      long hashStart = 0;
      prefixHashes[0] = hashStart;
      for (int a = 0; a < str.length(); a++) {
        hashStart *= base;
        hashStart += str.charAt(a);
        hashStart %= prime;
        prefixHashes[a+1] = hashStart;
      }   
    }

    private void makePowerCache(){
      cachePower = new long[str.length()+1];
      long start = 1;
      for(int a = 0; a < str.length()+1; a++){
        cachePower[a] = start;
        start *= base;
        start %= prime;
      }   
    }
    
    //Returns the hash of a substring in O(1) time
    //[inclusive, exclusive)
    public long getSubstringHash(int startIdx, int endIdx){
      long fullPrefix = prefixHashes[endIdx];
      long prefix = prefixHashes[startIdx];
      long power = cachePower[endIdx-startIdx];
      long prefixA = prefix%chunk_size;
      long prefixB = prefix/chunk_size;
      long powerA = power%chunk_size;
      long powerB = power/chunk_size;
      long smallChunk = prefixA*powerA;
      long mediumChunk = powerA*prefixB + powerB*prefixA;
      long largeChunk = prefixB*powerB;
      long mediumChunkLeft = mediumChunk/chunk_size;
      long mediumChunkRight = mediumChunk%chunk_size;
      smallChunk += mediumChunkRight*chunk_size;
      largeChunk += mediumChunkLeft;
      smallChunk += largeChunk * -61;
      long smallPrefix = smallChunk;
      long ans = fullPrefix-smallPrefix;
      return ((ans%prime)+prime)%prime;
    }   

    //Returns a list of hashes of all substrings of length x.
    //Ordered from left to right.
    public ArrayList<Long> getAllXSubstringHashes(int x){ 
      ArrayList<Long> output = new ArrayList<Long>();
      for(int a = 0; a < str.length()-x+1; a++){
        output.add(getSubstringHash(a, a+x));
      }        
      return output;
    }   
  }

}
