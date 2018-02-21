import java.util.Scanner;
import java.util.Arrays;

public class FibonacciBefore {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < n; i++) {
      int query = s.nextInt();
      sb.append(fib(query));
      sb.append('\n');
    }
    System.out.println(sb);
  }

  public static int fib(int n) {
    if (n < 3) return 1;
    int value = fib(n-1) + fib(n-2);
    return value;
  }
}
