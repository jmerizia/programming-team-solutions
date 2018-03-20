#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

double xs, ys, xf, yf, vs;

double dist(double theta)
{
  double half_time = vs * sin(theta*M_PI/180) / 9.8;
  double d = 2 * half_time * vs * cos(theta*M_PI/180);
  return d;
}

int main()
{
  cin >> xs >> ys >> xf >> yf >> vs;
  double target = xf - xs;
  if (dist(45.0) < target){
    cout << "Yell at Peter instead!";
    return 0;
  }

  double l = 0, r = 45.0, mid = 0.0;
  for (int i = 0; i < 50; i++) {
    mid = (l + r) / 2.0;
    //printf("%0.10f\n", mid);
    double guess = dist(mid);
    if (target < guess) r = mid;
    else l = mid;
  }

  printf("%0.10f\n", mid);

  l = 45.0, r = 90.0, mid = 0.0;
  for (int i = 0; i < 50; i++) {
    mid = (l + r) / 2.0;
    //printf("%0.10f\n", mid);
    double guess = dist(mid);
    if (target > guess) r = mid;
    else l = mid;
  }

  printf("%0.10f\n", mid);

  return 0;
}
