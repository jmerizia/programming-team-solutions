import java.util.*;

static class RaindropMadness {
  public static void main(String[] args) {
    Scanner s = new Scanner();
    String givenStr = s.next();
    int n = givenStr.length();
    int given = parseInt(givenStr, 2);

    int ones = 0;
    for (int i = 0; i < n; i++) if (givenStr.charAt(i) == '1') ones++;

    for (int i = 0; i < ones; i++) {

    }
      
  }
}
