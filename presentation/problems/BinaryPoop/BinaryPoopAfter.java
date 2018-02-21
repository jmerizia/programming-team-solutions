import java.util.Scanner;

public class BinaryPoopAfter {
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
    int left = 0, right = arr.length - 1, mid = 0;
    for (int i = 0; i < 20; i++) {
      mid = (left + right) / 2;
      if (arr[mid] < value) left = mid;
      else right = mid;
    }
    return arr[right] == value;
  }
}
