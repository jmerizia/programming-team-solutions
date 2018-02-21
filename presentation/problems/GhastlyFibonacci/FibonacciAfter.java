import java.util.Scanner;
import java.util.Arrays;
import java.util.HashMap;

public class FibonacciAfter {
  static HashMap<Integer, Integer> map;
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    map = new HashMap<>();
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
    if (map.containsKey(n)) return map.get(n);
    int value = fib(n-1) + fib(n-2);
    map.put(n, value);
    return value;
  }
}
