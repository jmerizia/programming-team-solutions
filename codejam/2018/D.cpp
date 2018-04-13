#include <bits/stdc++.h>
using namespace std;

#define TR(a, b, c) make_pair(a, make_pair(b, c))
#define FOR(i, a, b) for(int i=a;i<b;i++)

pair<double, pair<double, double>> p[20];
vector<pair<double, double>> coords;
double rt2 = sqrt(2);
double rt3 = sqrt(3);

double calc_area()
{
  double area = 0;
  cout << coords.size() << endl;
  FOR(i, 0, coords.size()-1) {
    area += coords[i].first * coords[i+1].second - coords[i+1].first * coords[i].second;
  }
  return 0.5*area;
}

void calc_coords()
{
  coords.clear();
  FOR(i, 0, 6) {
    double x = p[i].first;
    double len = p[i].second.first;
    double thet = p[i].second.second;
    double y = len*cos((M_PI/180)*thet);
    coords.push_back(make_pair(x+6, y+6));
  }
  printf("coords: \n");
  FOR(i, 0, coords.size()) printf("%2.4f %2.4f \n", coords[i].first, coords[i].second);
}

void test_coords()
{
  coords.clear();
  coords.push_back(make_pair(0, 0));
  coords.push_back(make_pair(1, 0));
  coords.push_back(make_pair(1, 1));
  coords.push_back(make_pair(0, 1));
  //FOR(i, 0, coords.size()) printf("%2.4f %2.4f \n", coords[i].first, coords[i].second);
}

void init()
{
  p[0] = TR(0, rt2, 0);//f
  p[1] = TR(-rt2/2, rt3/rt2, tan((M_PI/180)*(2/rt2)));//d
  p[2] = TR(-1*rt2/2, rt2/2, 0);//a
  p[3] = TR(0, 1, 90);//c
  p[4] = TR(rt2/2, rt2/2, 0);//b
  p[5] = TR(-rt2/2, rt3/rt2, tan((M_PI/180)*(2/rt2)));//e

  //p[8] = TR(0, rt2/2, 0);
  //p[9] = TR(-rt2/2, rt3/2, tan((M_PI/180)*(1/rt2)));
  //p[10] = TR(rt2/2, rt3/2, tan((M_PI/180)*(1/rt2)));
  //FOR(i, 0, 6) printf("%0.4f %0.4f %0.4f \n", p[i].first, p[i].second.first, p[i].second.second);
}

int main()
{
  init();
  calc_coords();
  double area = calc_area();
  cout << area << endl;
  return 0;
}
