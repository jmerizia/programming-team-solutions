#include <iostream>
#include <string>

using namespace std;

int r, c;

int main()
{
  cin >> r >> c;
  string grid[r+1];
  for (int i = 0; i < r; i++) {
    string line;
    cin >> line;
    grid[i] = line;
  }
  grid[r] = "############";

  for (int j = 0; j < c; j++) {
    int apple_count = 0;
    for (int i = 0; i < r+1; i++) {

      if (grid[i][j] == 'a') {
        grid[i][j] = '.';
        apple_count++;
      } else if (grid[i][j] == '#') {
        int k = 1;
        while (apple_count > 0) {
          grid[i - k][j] = 'a';
          k++;
          apple_count--;
        }
      }

    }
  }

  for (int i = 0; i < r; i++) {
    cout << grid[i] << endl;
  }
}
