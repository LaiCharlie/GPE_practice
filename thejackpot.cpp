#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <map>
#include <sstream>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    while(cin>>n&&n){
        vector<int> num;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            num.push_back(tmp);
        }
        int ans=0;
        int dp[10005]={0};
        dp[0] = max(0,num[0]);
        ans = dp[0];
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i-1]+num[i],num[i]);
            ans = max(ans,dp[i]);
        }
        
        if(ans>0)
            cout<<"The maximum winning streak is "<<ans<<".\n";
        else
            cout<<"Losing streak.\n";
    }

    return 0;
}