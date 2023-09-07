#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    while(cin>>n&&n){
        int m;
        cin>>m;
        vector<int> cut;
        cut.clear();
        for(int i=0;i<m;i++){
            int tmp;
            cin>>tmp;
            cut.push_back(tmp);
        }
        cut.push_back(0);
        cut.push_back(n);
        sort(cut.begin(),cut.end());

        int dp[55][55];
        memset(dp,0,sizeof(dp));
        int sz = cut.size();
        
        for(int i=2;i<sz;i++){
            for(int j=0;j+i<sz;j++){
                for(int k=j+1;k<j+i;k++){
                    if(dp[j][j+i]>0)
                        dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k][j+i]+cut[j+i]-cut[j]);
                    else
                        dp[j][j+i]=dp[j][k]+dp[k][j+i]+cut[j+i]-cut[j];
                }
            }
        }

        cout<<"The minimum cutting is "<<dp[0][sz-1]<<".\n";
    }

    return 0;
}