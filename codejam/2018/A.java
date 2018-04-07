import java.util.*;

public class A {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int cases = s.nextInt();
    for (int i = 0; i < cases; i++) {
      int damage = s.nextInt();
      String query = s.next();
      int n = query.length();
      int cur = calc(query);
      int count = 0;
      while (cur > damage) {
        for (int i = 0; i < n; i++) {
          if ()
        }
        cur = calc(query);
        count++;
      }
    }
  }

  public int calc(String s) {
    int damage = 0;
    int charge = 1;
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == 'S') damage += charge;
      else if (s.charAt(i) == 'C') charge << 1;
    }
    return damage;
  }

  public boolean isPossible(String s) {
    for (int i = 0; i < s.length(); i++) {
      
    }
  }
}
