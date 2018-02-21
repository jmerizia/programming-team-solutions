import java.util.Scanner;
import java.util.ArrayList;

public class MemTrashBefore {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int m = s.nextInt();
    int q = s.nextInt();
    boolean[][] adj = new boolean[n+1][n+1];
    for (int i = 0; i < m; i++) {
      int u = s.nextInt();
      int v = s.nextInt();
      adj[u][v] = true;
      adj[v][u] = true;
    }
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < n + 1; i++) {
      if (adj[q][i]) {
        sb.append(i);
        sb.append('\n');
      }
    }
    System.out.println(sb);
  }
}
