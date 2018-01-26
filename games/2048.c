#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <ctime>
#include <limits.h>
#include <sstream>
using namespace std;

//clock_t bt = clock();
typedef double DB;
typedef long long LL;
typedef stringstream SS;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define F0R(i, a) for(int i=0;i<(a);i++)
#define FORd(i, a, b) for(int i=b-1;i>=a;i--)
#define F0Rd(i, a) for(int i=a-1;i>=0;i--)
#define SZ(x) (int)(x).size()
#define ALL(x) x.begin(), x.end()
#define PI M_PI
#define F first
#define S second
#define PB push_back
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int arMinIdx(int*arr,int n){return min_element(arr,arr+n)-arr;}
int arMaxIdx(int*arr,int n){return max_element(arr,arr+n)-arr;}
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return abs(a*b)/gcd(a,b);}

char key;
int board[100][100], n, score;
string brk;

void push_dr(int cr, int dir) // down:0,right:1;
{
  int c = n-1;
  F0Rd(i, n){
    int a = dir?cr:i;
    int b = dir?i:cr;
    if(board[a][b]){
      int tmp = board[a][b];
      board[a][b] = 0;
      board[dir?a:c][dir?c:b] = tmp;
      c--;
    }
  }
}

void push_ul(int cr, int dir) // up:0,left:1
{
  int c = 0;
  F0R(i, n){
    int a = dir?cr:i;
    int b = dir?i:cr;
    if(board[a][b]){
      int tmp = board[a][b];
      board[a][b] = 0;
      board[dir?a:c][dir?c:b] = tmp;
      c++;
    }
  }
}


void combine_right(int row)
{
  FORd(j, 1, n){
    if(board[row][j] && board[row][j]==board[row][j-1]){
      board[row][j]*=2;
      board[row][j-1]=0;
      j--;
    }
  }
}

void combine_down(int col)
{
  FORd(i, 1, n){
    if(board[i][col] && board[i][col]==board[i-1][col]){
      board[i][col]*=2;
      board[i-1][col]=0;
      i--;
    }
  }
}

void combine_left(int row)
{
  F0R(j, n-1){
    if(board[row][j] && board[row][j]==board[row][j+1]){
      board[row][j]*=2;
      board[row][j+1]=0;
      j++;
    }
  }
}

void combine_up(int col)
{
  F0R(i, n-1){
    if(board[i][col] && board[i][col]==board[i+1][col]){
      board[i][col]*=2;
      board[i+1][col]=0;
      i++;
    }
  }
}

void add_new()
{
  int i, j;
  do{
    i = rand() % n;
    j = rand() % n;
  }while(board[i][j]);
  board[i][j] = 2;
}

bool check_end()
{
  bool fail = 1;
  F0R(i, n) F0R(j, n) if(board[i][j]==0) fail=0;
  return fail;
}

void game_over()
{
  cout << endl << "GAME OVER" << endl;
  exit(0);
}

bool update()
{
  switch(key){
    case 'h': // left
      F0R(i, n){
        push_ul(i, 1);
        combine_left(i);
        push_ul(i, 1);
      }break;
    case 'l': // right
      F0R(i, n){
        push_dr(i, 1);
        combine_right(i);
        push_dr(i, 1);
      }break;
    case 'k': // up
      F0R(j, n){
        push_ul(j, 0);
        combine_up(j);
        push_ul(j, 0);
      }break;
    case 'j': // down
      F0R(j, n){
        push_dr(j, 0);
        combine_down(j);
        push_dr(j, 0);
      }break;
    case 'n': // repeat down, right many times
      F0R(kk, 10){
        key = 'j'; update(); if(check_end()) game_over(); add_new();
        key = 'l'; update(); if(check_end()) game_over(); add_new();
      }
  }
}

void calc_score()
{
  score = 0;
  F0R(i, n) F0R(j, n) score+=board[i][j];
}

void init()
{
  F0R(i, n) F0R(j, n) board[i][j] = 0;
  F0R(i, n) if(i%2)board[i][1] = 2;
  SS ss;
  F0R(i, n) ss << "+-----";
  ss << '+'; brk = ss.str();
}

void display_grid()
{
  system("clear");
  cout << brk << endl;
  F0R(i, n){
    F0R(j, n){
      if(board[i][j]==0) cout << "|     ";
      else cout << "|" << setw(5) << right << board[i][j] << "";
    }
    cout << "|" << endl << brk << endl;
  }
  cout << "score: " << score << endl;
}

void key_press()
{
  system("stty raw");
  cin >> key;
  system("stty cooked");
}

void turn()
{
    display_grid();
    key_press();
    if(key=='q') exit(0);
    update();
    if(check_end()) game_over();
    add_new();
    calc_score();
}

int main()
{
  cout << "size: "; cin >> n;
  init();
  while(1) turn();
  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
