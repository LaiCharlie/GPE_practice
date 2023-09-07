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
    
    int dp[27][27][360];

    int l,s,cas=1;
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1;i<=26;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=351;k++){
                dp[i][j][k] = dp[i-1][j][k];
                if(j && k>=i)
                    dp[i][j][k]+=dp[i-1][j-1][k-i]; 
            }
        }
    }

    while(cin>>l>>s){
        if(l==0&&s==0)
            break;
        if(l<27&&s<352)
            cout<<"Case "<<cas++<<": "<<dp[26][l][s]<<'\n';
        else
            cout<<"Case "<<cas++<<": 0\n";
    }

    return 0;
}