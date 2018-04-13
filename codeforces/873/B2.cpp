#include <bits/stdc++.h>
using namespace std;

int ans, n, k, dp[(int)1e5+5];
string s;

int main()
{
  cin>>n>>s;
  for(int i=0;i<n;i++){
    k+=s[i]=='1'?1:-1;
    if(dp[k])ans=max(ans,i-dp[k]);
    else dp[k]=i;
  }
  cout<<ans;

  return 0;
}
