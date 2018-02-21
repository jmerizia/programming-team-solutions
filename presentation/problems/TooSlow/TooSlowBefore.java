import java.util.ArrayList;
import java.util.Scanner;

public class TooSlowBefore {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    ArrayList<Integer> queue = new ArrayList<>();
    int n = s.nextInt();
    for (int i = 0; i < n; i++) {
      char command = s.next().charAt(0);
      if (command == 'a') {
        int value = s.nextInt();
        queue.add(0, value);
      } else {
        queue.remove(0);
      }
    }
    
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < queue.size(); i++) {
      sb.append(queue.get(i));
      sb.append('\n');
    }
    System.out.println(sb);
  }
}
