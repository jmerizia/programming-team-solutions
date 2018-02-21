import java.util.Scanner;

public class BinaryPoopBefore {
  static int[] arr;
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int q = s.nextInt();
    arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = s.nextInt();
    }
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < q; i++) {
      int query = s.nextInt();
      if (arrContains(query)) sb.append("yes\n");
      else sb.append("no\n");
    }
    System.out.println(sb);
  }

  public static boolean arrContains(int value) {
    for (int i = 0; i < arr.length; i++) {
      if (arr[i] == value) return true;
    }
    return false;
  }
}
