import java.util.*;
import static java.lang.Math.*;

public class E {
public static void main(String[] args) {

Scanner s = new Scanner(System.in);
int n = s.nextInt();
P[] circles = new P[n];
for (int i = 0; i < n; i++) {
    double x = s.nextDouble();
    double y = s.nextDouble();
    Circle c = new Circle(new P(x, y), 1);
    circles[i] = c;
}

for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        // find line through centers
        P p1 = circles[i].c;
        P p2 = circles[j].c;
        Line l = new Line(p1, p2);
        // count the number of other circles that are close to this line
        int mx = -1;
        for (int k = 0; k < n; k++) {
            int cnt = 2;
            if (k == i || k == j) continue;
            P idk = circles[k].c;
            if ((l.distance(idk) - 2.0) <= EPS) cnt++;
            
        }
    }
}

}

//------------ START of Geometry classes ------------
static class P implements Comparable<P> {
    final double x, y;
    P(double x, double y)    { this.x = x; this.y = y; }
    P sub(P that)            { return new P(x - that.x, y - that.y); }
    P add(P that)            { return new P(x + that.x, y + that.y); }
    double dot(P that)       { return x * that.x + y * that.y; }
    P scale(double s)        { return new P(x * s, y * s); }
    // Use hypot() only if intermediate overflow must be avoided; very slow
    double length()          { return sqrt(x*x + y*y); }    
    double length2()         { return x * x + y * y; }
    P leftNormal()           { return new P(-y, x); }   // rotateCCW(90deg)
    P rightNormal()          { return new P(y, -x); }   // rotateCW(90deg)
    P normalize()            { double n = length(); return n > 0 ? new P(x/n, y/n) : origin(); }
    P scaleToLength(double l) { return normalize().scale(l); }
    P project(P a)           { return scale(a.dot(this) / length2()); }
    P reflect(P a)           { return project(a).scale(2.0).sub(a); }
    // use if sin, cos are known
    P rotateCCW(double sinT, double cosT) {
        return new P(x * cosT - y * sinT,
                     x * sinT + y * cosT); }
    P rotateCW(double sinT, double cosT) { return rotateCCW(-sinT, cosT); }
    P rotate(double theta)   { return rotateCCW(sin(theta), cos(theta)); }
    // angle to horizontal (1, 0); result is in [-pi, pi] rad or (-180-180) deg
    double theta()           { return atan2(y, x); }
    // angle between two vectors, result is in [0, pi] rad (0-180 deg)
    double angleTo(P a)      { return acos(this.dot(a) / this.length() / a.length()); }
    boolean isOrigin()       { return x == 0 && y == 0; }
    public String toString() { return String.format("(%f,%f)", this.x, this.y); }
    static P read(Scanner s) { return new P(s.nextDouble(), s.nextDouble()); }
    static P origin()        { return new P(0, 0); }
    double det(P that)       { return this.x * that.y - this.y * that.x; }
    double crossproduct(P that) { return this.det(that); }
    P half(P q)              { return normalize().add(q.normalize()); }

    double dist(P to)        { return sub(to).length(); }
    double signedParallelogramArea(P b, P c) { return (b.sub(this).crossproduct(c.sub(this))); }
    boolean isCollinearWith(P b, P c) { return abs(signedParallelogramArea(b, c)) <= EPS; }
    // is going from this to b to c a CCW turn? Do not use if points may be collinear
    boolean isCCW(P b, P c)  { return signedParallelogramArea(b, c) > 0; }
    double signedTriangleArea(P b, P c) { return signedParallelogramArea(b, c) / 2.0; }

    // memory-optimized version of this.sub(to).length2() that avoids an intermediate object
    double dist2(P to)       {
        double dx = this.x - to.x;
        double dy = this.y - to.y;
        return dx * dx + dy * dy;
    }

    /**
     * Compute x for a * x + b = 0 and ||x|| = C
     * where 'this' is a.  
     * Care must be taken to handle the case where
     * either a.x or a.y is near zero.
     */
    P [] solveDotProductConstrainedByNorm(double b, double C) {
        P a = this;
        if (a.isOrigin())
            throw new Error("degenerate case");

        boolean transpose = abs(a.x) > abs(a.y);
        a = transpose ? new P(a.y, a.x) : a;

        Double [] x = solvequadratic(a.length2(), 2.0 * b * a.x, b * b - a.y * a.y * C * C);
        P [] p = new P[x.length];
        for (int i = 0; i < x.length; i++) {
            double x1 = x[i];
            double x2 = ((-b - a.x * x1) / a.y);
            p[i] = transpose ? new P(x2, x1) : new P(x1, x2);
        }
        return p;
    }

    @Override
    public int compareTo(P that) {
        if (abs(this.x - that.x) > EPS) return Double.compare(this.x, that.x);
        return Double.compare(this.y, that.y);
    }
}

static class HP extends P { // Hashable Point
    HP(double x, double y) { super(x, y); }
    @Override
    public int hashCode() { return Double.hashCode(x + 32768*y); }
    @Override
    public boolean equals (Object _that) {
        HP that = (HP)_that;
        return this.x == that.x && this.y == that.y;
    }
}

/**
 * Sort points by polar angle relative to center, using trig.
 * This is a counter-clockwise sort with zero at 3 o'clock.
 */
static Comparator<P> makePolarAngleComparatorTrig(final P center) {
    return new Comparator<P>() {
        public int compare(P a, P b) {
            double thetaa = a.sub(center).theta();
            double thetab = b.sub(center).theta();
            if (thetaa < 0) thetaa += 2 * PI;
            if (thetab < 0) thetab += 2 * PI;
            int c = Double.compare(thetaa, thetab);
            if (c != 0)
                return c;
            return Double.compare(b.x, a.x);    // arbitrary tie-breaker
        }
    };
}

/**
 * Sort points by polar angle relative to center, w/o trig.
 * This is a counter-clockwise sort with zero at 3 o'clock.
 */
static Comparator<P> makePolarAngleComparator(final P center) {
    return new Comparator<P>() {
        public int compare(P a, P b) {
            // orientation() requires that a and b lie in the same half-plane
            if (a.y >= center.y && b.y < center.y) return -1;
            if (b.y >= center.y && a.y < center.y) return 1;
            int orientation = (int) Math.signum(center.signedParallelogramArea(b, a));
            if (orientation != 0) return orientation;
            return Double.compare(b.x, a.x);    // arbitrary tie-breaker
        }
    };
}

/* Solve a * x^2 + b * x + c == 0 
 * Returns 0, 1, or 2 solutions. If 2 solutions x1, x2, guarantees that x1 < x2
 */
static Double [] solvequadratic(double a, double b, double c) {
    double D = b * b - 4 * a * c;
    if (D < -EPS)
        return new Double [] { };
    D = max(D, 0);
    if (D == 0)
        return new Double [] { -b / 2.0 / a };
    double d = sqrt(D);
    // Numerically more stable, see
    // https://en.wikipedia.org/wiki/Loss_of_significance#A_better_algorithm
    if (signum(b) == 0)
        return new Double[] { d / 2.0 / a, -d / 2.0 / a };
    double x1 = (-b - signum(b) * d) / (2 * a);
    double x2 = c / (a * x1);
    return new Double[] { Math.min(x1, x2), Math.max(x1, x2) };
}

/* The Line/Circle classes provide a number of methods that require dealing
 * with floating point precision issues.  Default EPS to a suitable value,
 * such as 1e-6, which should work for many problems in which the input
 * coordinates are in integers and subsequently inexact floating point
 * values are being computed.
 */
static double EPS = 1e-6;

/* A line denoted by two points p and q.
 * For internal computations, we use the parametric representation
 * of the line as p + t d where d = q - p.
 * For convenience, we compute and store d in the constructor. 
 * Most methods hide the parametric representation of the
 * line, but it is exposed via getPointFromParameter and 
 * intersectionParameters for those problems that need it.
 *
 * The line may be interpreted either as a line segment denoted
 * by the two end points, or as the infinite line determined
 * by these two points.  Intersection methods are provided
 * for both cases.
 */ 
static class Line {
    P p, q, d;
    Line(P p, P q) { this.p = p; this.q = q; d = q.sub(p); }

    P getPointFromParameter(double t) { return p.add(d.scale(t)); }

    // reflect vector across vector (as if line originated at (0, 0))
    P reflect(P d2) { return d.reflect(d2); }

    // reflect point across (infinite) line 
    P reflectPoint(P r) { return reflect(r.sub(p)).add(p); }

    // project p onto this (infinite) line. Returns point on line
    P project(P a) { return p.add(d.project(a.sub(p))); }

    // return distance of point P from this (infinite) line.
    double distance(P a) { return project(a).dist(a); }

    @Override
    public String toString() { return String.format("[%s => %s]", p, q); }

    /* Point of intersection of this line segment
     * with another line segment.  Returns only points
     * that lie inside both line segments, else null.
     *
     * Result may include points "just outside" the bounds,
     * given EPS.
     */
    P intersectsInBounds(Line l) {
        double [] st = intersectionParameters(l);
        if (st == null)
            return null;

        // check that point of intersection is in direction 'd' 
        // and within segment bounds
        double s = st[0];
        double t = st[1];
        if (s >= -EPS && s <= 1+EPS && -EPS <= t && t <= 1+EPS)
            return getPointFromParameter(s);

        return null;
    }

    /* Point of intersection of this (infinite) line 
     * with other (infinite) line.  Return null if collinear.
     */
    P intersects(Line l) {
        double [] st = intersectionParameters(l);
        if (st != null)
            return getPointFromParameter(st[0]);
        return null;
    }

    /* Intersect this line with that line
     * Solves:  this.p + s * this.d == l.p + t l.d
     * Return null if lines are collinear
     * Else returns [s, t].
     */
    double [] intersectionParameters(Line l) {
        P dneg = p.sub(q);
        double D = l.d.det(dneg);
        // Use Cramer's rule; see text
        if (D == 0.0)
            return null;

        P rp = p.sub(l.p);
        return new double[] { l.d.det(rp) / D, rp.det(dneg) / D };
    }

    /* Compute points of intersection of this infinite line
     * with a circle.
     * Computes projection 'x' of c.c onto line, then computes
     * x +/- d.scaleToLength(h) where h is computed via Pythagoras.
     * Sorted by decreasing 't' (as would be used in getPointFromParameter)
     *
     * May return two points even if line is a tangent.
     */
    P [] intersectsCircle(Circle c) {
        P x = project(c.c);
        double D = x.dist(c.c);
        // outside by more than EPS
        if (D > c.R + EPS) return new P[0];       
        double h = sqrt(max(0, c.R * c.R - D * D));
        if (h == 0) return new P[] { x };   // EPS (!?)
        return new P[] { x.add(d.scaleToLength(h)), x.add(d.scaleToLength(-h)) };
    }

    /* Compute points of intersection of this infinite line
     * with a circle.
     *
     * Solves a + t * b = c + r subject to ||r|| = R
     * Returns zero, one, or two points on the periphery, 
     * e.g. c + r[0,1], sorted by decreasing 't'.
     * Alternative version which requires solving quadratic
     * equation.
     *
     * Careful: set EPS if you need to handle round-off error
     * in discriminant.
     */
    P [] intersectsCircleAlternative(Circle c) {
        P ca = c.c.sub(p);
        P d = q.sub(p);
        Double [] t = solvequadratic(d.length2(), -2 * d.dot(ca), ca.length2() - c.R * c.R);
        P [] r = new P[t.length];
        for (int i = 0; i < t.length; i++)
            r[i] = p.add(d.scale(t[i]));
        return r;
    }

    /**
     * Is r contained within the line segment spanned by p/q,
     * including their endpoints?
     */
    boolean isInBounds(P r) {
        return abs(p.dist(q) - p.dist(r) - q.dist(r)) <= EPS;
    }

    /**
     * Is r on the infinite line?
     */
    boolean isOnLine(P r) { return r.isCollinearWith(p, q); }
}

/**
 * Alternative line implementation using the "general form" equation.
 *
 *   a * x + b * y + c = 0
 *
 * This is provided for problems in which a line may be given in general form
 * in the input.
 * Compared to class Line, GLine:
 * - is shorter, particularly when only line/line and line/circle intersections
 *   are required.
 * - does not support those functions of Line that relate to LineSegment.
 */
static class GLine {
    // we represent a, b as a vector to benefit from the available dot/det routines.
    P n;           // n = new P(a, b) --- this is the (right) normal vector to the line
    double c;
    GLine(double a, double b, double c) {
        this.n = new P(a, b);
        if (a == 0 && b == 0) throw new Error("a and b cannot both be zero");
        this.c = c;
    }

    GLine(P p, P q) {
        this(p.y-q.y, q.x-p.x, p.det(q));
    }

    P intersects(GLine that) {
        double D = n.det(that.n);
        if (D == 0.0)
            return null;
        return new P((this.n.y * that.c - that.n.y * this.c) / D,
                     (that.n.x * this.c - this.n.x * that.c) / D);
    }

    double signedDistance(P p) {
        return (n.dot(p) + c)/n.length();
    }

    double distance(P p) {
        return abs(signedDistance(p));
    }

    // checks if on (infinite) line.
    boolean isOnLine(P p) {
        return signedDistance(p) <= EPS;
    }

    // checks if on the same side, no EPS
    boolean onSameSide(P p, P q) {
        return signum(signedDistance(p)) == signum(signedDistance(q));
    }

    // angle of inclination to horizontal; result is in [0, pi] rad
    // XXX untested
    double theta() {
        double angle = atan2(n.x, -n.y);
        return angle < 0 ? (angle + PI) : angle;
    }

    // XXX untested
    boolean parallelWith(GLine that) {
        return n.det(that.n) <= EPS;
    }

    // XXX untested
    boolean perpendicularTo(GLine that) {
        return n.dot(that.n) <= EPS;
    }

    // circle-line intersection, refactored from
    // https://e-maxx-eng.appspot.com/geometry/circle-line-intersection.html
    P [] intersectsCircle(Circle C) {
        // shift line to center, this is undone by adding C.c before returning.
        double c = n.dot(C.c) + this.c;
        double n2 = n.length2();
        double r = C.R;

        P p = n.scale(-c/n2).add(C.c);  // undo shift to center
        if (c*c > r*r*n2+EPS) {
            return new P [] { };
        } else if (abs (c*c - r*r*n2) < EPS) {
            return new P [] { p };
        } else {
            double d = r*r - c*c/n2;
            double m = sqrt (d / n2);
            P q = n.rightNormal().scale(m);
            return new P[] { p.add(q), p.sub(q) };
        }
    }

    @Override
    public String toString() {
        return String.format("Line:(n=%s C=%f)", n, c);
    }
}

static class Circle {
    P c;
    double R;
    Circle(P c, double R) { this.c = c; this.R = R; }
    @Override
    public String toString() { return String.format("{%s, %.03f}", c, R); }
    /* Is this point inside the circle */
    boolean isInside(P p) { return R > p.dist(c) - EPS; }
    /* Is this point on the circle's periphery */
    boolean isOnCircle(P p) { return abs(p.dist(c) - R) <= EPS; }

    /* a line segment is outside a circle if both end points are outside and
     * if any intersection points are outside the bounds of the line segment. */
    boolean isOutside(Line l) {
        if (isInside(l.p) || isInside(l.q))
            return false;
        P [] _is = l.intersectsCircle(this);
        if (_is.length > 1)
            for (P is : _is)
                if (l.isInBounds(is))
                    return false;
        return true;
    }

    /* Returns the tangent lines that the point p makes with this circle, if any. */
    Line [] tangentLines(P p)
    {
        // Let c +/- r be the tangent points.  Then there's a 'd' such that
        // p + d - r = c 
        // Since d r = 0, we multiply by r and get
        // (p - c) r - ||r|| = 0  subject to ||r|| = R
        P [] r = p.sub(c).solveDotProductConstrainedByNorm(-R*R, R);
        Line [] tangents = new Line[r.length];
        for (int i = 0; i < tangents.length; i++)
            tangents[i] = new Line(p, c.add(r[i]));
        return tangents;
    }

    /* Compute points of intersection of this circle (c1, r1) with that circle (c2, r2).
     * Model as triangle equation m = c2 - c1 = r1 - r2
     * m = r1 - r2  -> m^2 = r1^2 + r2^2 - 2 r1 r2          (squaring)
     *              -> r1 r2 = (r1^2 + r2^2 - m^2)/2
     * and by multiplying by r1 we obtain
     * m = r1 - r2  -> m r1 = r1^2 - r1 r2
     *              -> m r1 = r1^2 - (r1^2 + r2^2 - m^2)/2
     *              -> m r1 + (r2^2 - r1^2 - m^2)/2 = 0
     * and ready for solveDotProductConstrainedByNorm
     *
     * Note that if the circles are (apprx) touching, this function may
     * return 0, 1, or 2 intersection points, depending on which side of 0
     * the discriminant falls.  You will not get NaN.
     *
     * If the circles coincidence (same center and radius) this will throw an
     * 'degenerate case' error in solveDotProductConstrainedByNorm !!!
     */
    P [] intersectsCircle(Circle that) {
        double r1 = this.R;
        double r2 = that.R;
        P m = that.c.sub(this.c);
        P [] r1sol = m.solveDotProductConstrainedByNorm((r2*r2 - r1*r1 - m.length2())/2, r1);
        // compute [c +/- r1] to obtain intersection points
        P [] is = new P[r1sol.length];
        for (int i = 0; i < r1sol.length; i++)
            is[i] = this.c.add(r1sol[i]);
        return is;
    }

    /* Shorter version of intersectsCircle that solves quadratic equation inline.
     * Assumes there are 2 intersection points. 
     * The vector 'mid' is where the altitude of the triangle formed by the centers
     * and the intersection point hits the line connecting the centers.  Its length
     * is e.  midn is normal to it and its length is f.
     */
    P [] intersectsCircleAlternative(Circle that) {
        P m = that.c.sub(this.c);
        double b = this.R * this.R;
        // div-by-zero if circles share center
        double e = (m.length2() + b - that.R * that.R)/2/m.length();
        double f = sqrt(b - e * e);     // NaN if circles don't intersect
        P [] is = new P[2];
        P mid = this.c.add(m.scaleToLength(e));
        P midn = m.rightNormal();
        for (int i = 0; i < is.length; i++) {
            is[i] = mid.add(midn.scaleToLength(f));
            f *= -1;
        }
        return is;
    }

    // returns true if this circle is outside that circle
    boolean isOutside(Circle that) {
        return this.c.dist(that.c) > (this.R + that.R);
    }

    // returns true if this circle is entirely contained inside that circle
    boolean isContainedIn(Circle that) {
        // extend line from that.c to this.c by radius R
        P m = this.c.sub(that.c);
        return that.isInside(this.c.add(m.scaleToLength(this.R)));
    }

    /* Construct smallest circle that circumscribes 2 points a and b. */
    static Circle getCircumCircle(P a, P b) {
        P c = a.add(b).scale(.5);
        return new Circle(c, c.dist(a));
    }

    /* Construct circle circumscribed by 3 points a, b, c */
    static Circle getCircumCircle(P a, P b, P c) {
        P B = b.sub(a);
        P C = c.sub(a);
        double d = 2 * B.crossproduct(C);
        if (abs(d) < EPS)   // points are collinear
            return getCircumCircle(
                new P(min(a.x, min(b.x, c.x)), min(a.y, min(b.y, c.y))),
                new P(max(a.x, max(b.x, c.x)), max(a.y, max(b.y, c.y))));

        double z1 = B.length2();
        double z2 = C.length2();
        P cc = new P(C.y * z1 - B.y * z2, B.x * z2 - C.x * z1).scale(1.0 / d);
        return new Circle(cc.add(a), cc.length());
    }

    /* Find minimum enclosing circle for a set of points.
     * Peter, we need a source for this algorithm and its expected complexity.
     */
    static Circle minEnclosingCircle(P[] p) {
        if (p.length == 0) return new Circle(new P(0, 0), 0);
        if (p.length == 1) return new Circle(p[0], 0);
        Collections.shuffle(Arrays.asList(p));
        Circle circle = getCircumCircle(p[0], p[1]);
        for (int i = 2; i < p.length; i++) {
            if (!circle.isInside(p[i])) {
                circle = getCircumCircle(p[0], p[i]);
                for (int j = 1; j < i; j++) {
                    if (!circle.isInside(p[j])) {
                        circle = getCircumCircle(p[j], p[i]);
                        for (int k = 0; k < j; k++) {
                            if (!circle.isInside(p[k])) {
                                circle = getCircumCircle(p[i], p[j], p[k]);
                            }
                        }
                    }
                }
            }
        }
        return circle;
    }
}

/**
 * Some basic operations on Polygons.
 */
static class Polygon {
    P [] p;         // open form, p[0] connects to p[n-1]

    // Constructors clone original array/collection
    Polygon(Collection<P> c) { this.p = c.toArray(new P[c.size()]); }
    Polygon(P []p) { this.p = (P [])p.clone(); }

    /* Absolute of signed triangle areas */
    double signedArea() {
        double area = 0.0;
        for (int i = 0; i < p.length; i++) {
            area += p[i].det(p[(i+1) % p.length]);
        }
        return area/2.0;
    }

    double absoluteArea() {
        return abs(signedArea());
    }

    /*
     *  Returns an P[] array representing an open shape that is
     *  the convex hull of the given array of points, or
     *  null if less than 2 points were given.
     */
    public Polygon convexHull()
    {
        if (p.length < 2)
            return null;

        // (0) find the lowest point, breaking ties to the right
        final P min = Collections.min(Arrays.asList(p), new Comparator<P>() {
            public int compare(P p1, P p2) {
                int y = Double.compare(p1.y, p2.y);
                return y != 0 ? y : Double.compare(p1.x, p2.x);
            }
        });

        // (1) sort points by angle from pivot
        Arrays.sort(p, new Comparator<P>() {
            public int compare(P p1, P p2) {
                double o = min.signedParallelogramArea(p1, p2); // crossproduct
                if (o != 0)
                    return - (int) Math.signum(o);

                // if collinear, use distance to break tie
                return Double.compare(min.dist(p1), min.dist(p2));
            }
        });

        // (3) create stack
        Stack<P> hull = new Stack<P>();
        assert p[0] == min;
        hull.push(p[0]);
        hull.push(p[1]);

        // (4) select points that maintain left turns
        for (int i = 2; i < p.length; i++) { 
            P next = p[i];
            while (hull.size() >= 2) {
                P snd = hull.get(hull.size() - 2);
                P top = hull.peek();
                if (snd.isCCW(top, next))  // keep
                    break;

                hull.pop(); // discard
            }
            // keep current point
            hull.push(next);
        }
        return new Polygon(hull);
    }

    /*
     * "Point-in-Polygon" PIP tests.
     * Return true if point is contained in this polygon
     *
     * All of these tests may return 0 or 1 for points
     * on the boundary.  A separate test is required to
     * determine if a point is on the boundary.
     */
    public boolean contains(P q) { return contains_WN(q); }

    /*
     * Crossing-number based algorith 
     * due to Wm. Randolph Franklin. 
     * Works only for simple polygons. */
    private boolean contains_CN(P q)
    {
        boolean c = false;
        for (int i = 0, j = p.length-1; i < p.length; j = i++) {
            if ((((p[i].y<=q.y) && (q.y<p[j].y)) || ((p[j].y<=q.y) && (q.y<p[i].y))) &&
                (q.x < (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x))
                c = !c;
        }
        return c;
    }

    /* Winding numbers based algorithm,
     * which also works for self-intersecting polygons.
     * http://geomalgorithms.com/a03-_inclusion.html describes
     * this as the always preferred algorithm.
     *
     *  Return:  wn = the winding number (=0 only when P is outside)
     */
    public boolean contains_WN(P q)
    {
        int wn = 0;    // the  winding number counter

        // loop through all edges of the polygon
        int n = p.length;
        for (int i = 0; i < n; i++) {   // edge from V[i] to  V[i+1]
            P p = this.p[i], pn = this.p[(i+1)%n];
            if (p.y <= q.y) {           // start y <= P.y
                if (pn.y > q.y)           // an upward crossing
                     if (p.isCCW(pn, q))  // P left of  edge
                         ++wn;            // have  a valid up intersect
            } else {                      // start y > P.y (no test needed)
                if (pn.y <= q.y)          // a downward crossing
                     if (!p.isCCW(pn, q)) // P right of  edge
                         --wn;            // have a valid down intersect
            }
        }
        return wn != 0;
    }

    /**
     * Is q on the boundary of this polygon?
     */
    public boolean onBoundary(P q) {
        int n = p.length;
        for (int i = 0; i < n; i++) {
            P pi = this.p[i], pj = this.p[(i+1)%n];
            if (new Line(pi, pj).isInBounds(q))
                return true;
        }
        return false;
    }

    @Override
    public String toString() { return Arrays.toString(p); }
}


}
