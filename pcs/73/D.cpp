#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const double ERR = 1e-8;

double xs, ys, xf, yf, vs;
double dy, dx;
vector<double> angles;
vector<double> answer;

double vertex_x(double theta)
{
  double time_vertex = vs * sin(theta*M_PI/180.0) / 9.8;
  return vs * cos(theta*M_PI/180.0) * time_vertex;
}

double vertex_y(double theta)
{
  double time_vertex = vs * sin(theta*M_PI/180.0) / 9.8;
  return vs * cos(theta*M_PI/180.0) * time_vertex
    - 4.9 * time_vertex * time_vertex;
}

pair<double, double> values_on_curve(double theta, double y)
{
  double sin_ = sin(theta*M_PI/180.0);
  double time1 = (vs * sin_
      - sqrt(vs * vs * sin_ * sin_ - 2 * 9.8 * y)) / 9.8;
  double time2 = (vs * sin_
      + sqrt(vs * vs * sin_ * sin_ - 2 * 9.8 * y)) / 9.8;
  return make_pair(
      vs * cos(theta*M_PI/180.0) * time1,
      vs * cos(theta*M_PI/180.0) * time2);
}

double bsearch_curve(double target, double l, double r, bool dir, 
    bool first)
{
  double mid = 0;
  for (int i = 0; i < 500; i++) {
    mid = (l + r) / 2;
    pair<double, double> pr = values_on_curve(mid, dy);
    double guess = first ? pr.first : pr.second;
    // wow such codeforces xor skillz:
    if (dir ^ (target < guess)) r = mid;
    else l = mid;
  }
  return mid;
}

double bsearch_vertex(double target, double l, double r, bool dir)
{
  double mid = 0;
  for (int i = 0; i < 40; i++) {
    mid = (l + r) / 2;
    double guess = vertex_x(mid);
    if (dir ^ (target < guess)) r = mid;
    else l = mid;
  }
  return mid;
}


////double bsearch_vertex(double target, double l, double r, bool dir)
//void print_stuff(double target, double l, double r, bool dir)
//{
//  for (double i = l; i+5 < r; i+= 5){
//    printf("angle %3.10f : %0.10f\n", i, vertex_x(i+5) - vertex_x(i));
//  }
//}

int main()
{
  cin >> xs >> ys >> xf >> yf >> vs;
  dx = xf - xs;
  dy = yf - ys;

  double p1 = bsearch_vertex(dx, 0, 45, 0);
  double p2 = bsearch_vertex(dx, 45, 90, 1);

  if (abs(p1) > ERR && abs(p1 - 45) > ERR)
    angles.push_back(p1);
  if (abs(p2 - 45) > ERR && abs(p2 - 90) > ERR)
    angles.push_back(p2);


  //for (int i = 0; i < angles.size(); i++)
  //  cout << angles[i] << ' ';
  //cout << endl;

  if (angles.size() == 0){
    cout << "Yell at Peter instead!";
    return 0;
  }

  for (double angle: angles) { // at most two

    //if (vertex_y(angle) < dy) continue;

//double bsearch_curve(double target, double l, double r, bool dir,
//    bool first)

    double first = bsearch_curve(dx, 0, angle, 0, 1);
    double second = bsearch_curve(dx, angle, 90, 1, 0);
    double third = bsearch_curve(dx, -90, 0, 0, 0);

    if (abs(first) > ERR && abs(first - angle) > ERR)
      answer.push_back(first);
    if (abs(second - angle) > ERR && abs(second - 90) > ERR)
      answer.push_back(second);
    if (abs(third + 90) > ERR && abs(third) > ERR)
      answer.push_back(third);
    
  }

  // my best work:
  vector<double> im_too_tired_plz_work;
  for (double ans: answer) {
    bool already_in = false;
    for (double asdf: im_too_tired_plz_work) {
      if (abs(ans - asdf) < ERR){
        already_in = true;
        break;
      }
    }
    if (!already_in) im_too_tired_plz_work.push_back(ans);
  }
  sort(im_too_tired_plz_work.begin(), im_too_tired_plz_work.end());
  for (double dbbb: im_too_tired_plz_work)
    printf("%0.8f ", dbbb);

  return 0;
}
