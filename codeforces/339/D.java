import java.util.*;

public class D {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);

    int n = s.nextInt();
    int m = s.nextInt();
    int[] arr = new int[1<<n];
    for (int i = 0; i < (1<<n); i++) {
      arr[i] = s.nextInt();
    }

  }
}
