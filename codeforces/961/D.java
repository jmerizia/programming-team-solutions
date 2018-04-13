import java.util.*;

public class D {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();

    if (n < 5) {
      System.out.println("YES");
      return;
    }

    ArrayList<Point> points = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      int x = s.nextInt();
      int y = s.nextInt();
      points.add(new Point(x, y));
    }

    HashSet<Line> lines = new HashSet<>();
    HashSet<Line> A = new HashSet<>();
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        Line ln = new Line(points.get(i), points.get(j));
        if (!lines.contains(ln)) {
          lines.add(ln);
        } else {
          A.add(ln);
        }
      }
    }

    if (A.size() == 0) {
      System.out.println("NO");
      return;
    }

    for (int i = 0; i < n; i++) {
      points.get(i);
    }

  }

  static class Point {
    int x, y;
    Point(int _x, int _y) {
      this.x = _x;
      this.y = _y;
    }
  }

  static class Line {
    Frac b, m;
    Point p1;
    Point p2;
    Line(Point first, Point second) {
      p1 = first;
      p2 = second;
      m = new Frac(second.y - first.y, second.x - first.x);
      b = new Frac(first.y*(second.x-first.x)-first.x*(second.y-first.y), second.x-first.x);
    }
    @Override
    public int hashCode() {
      return b.hashCode() * 37 + m.hashCode();
    }
    @Override
    public boolean equals(Object other) {
      Line o = (Line)other;
      return this.m == o.m && this.b == o.b;
    }
  }

  static class Frac {
    int a, b;
    boolean sign;
    Frac(int top, int bottom) {
      this.a = Math.abs(top);
      this.b = Math.abs(bottom);
      this.sign = top * bottom > 0;
      this.reduce();
    }
    public void reduce() {
      int gcd = this.GCD(this.a, this.b);
      if (gcd == 0) gcd = 1;
      this.a = this.a / gcd;
      this.b = this.b / gcd;
    }
    public int GCD(int x, int y) {
      while(y!=0){
        int tmp = y;
        y = x%y;
        x = tmp;
      }
      return x;
    }
    @Override
    public int hashCode() {
      return a * 19 + b * 17 + (this.sign?1:0) * 11;
    }
    @Override
    public boolean equals(Object other) {
      Frac o = (Frac)other;
      return this.a == o.a && this.b == o.b && this.sign == o.sign;
    }
  }



}
