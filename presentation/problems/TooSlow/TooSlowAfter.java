import java.util.ArrayList;
import java.util.Scanner;

public class TooSlowAfter {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    ArrayList<Integer> queue = new ArrayList<>();
    int n = s.nextInt();
    for (int i = 0; i < n; i++) {
      char command = s.next().charAt(0);
      if (command == 'a') {
        int value = s.nextInt();
        queue.add(value);
      } else {
        queue.remove(queue.size() - 1);
      }
    }

    StringBuilder sb = new StringBuilder();
    for (int i = queue.size()-1; i >= 0; i--) {
      sb.append(queue.get(i));
      sb.append('\n');
    }
    System.out.println(sb);
  }
}
