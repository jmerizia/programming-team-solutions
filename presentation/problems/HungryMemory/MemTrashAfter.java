import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class MemTrashAfter {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int m = s.nextInt();
    int q = s.nextInt();
    ArrayList<Integer>[] adj = new ArrayList[n+1];
    for (int i = 0; i < adj.length; i++) adj[i] = new ArrayList<>();
    for (int i = 0; i < m; i++) {
      int u = s.nextInt();
      int v = s.nextInt();
      adj[u].add(v);
      adj[v].add(u);
    }
    StringBuilder sb = new StringBuilder();
    Collections.sort(adj[q]);
    for (int v: adj[q]) {
      sb.append(v);
      sb.append('\n');
    }
    System.out.println(sb);
  }
}
