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
    
    int m,n;
    int mp[105][105];
    while(cin>>m>>n){
        if(m==0&&n==0)
            break;
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                cin>>mp[i][j];

        int mxl[105][105];
        memset(mxl,0,sizeof(mxl));
        
        for(int i=1;i<=m;i++){
            if(mp[i][n]==0)
                mxl[i][n]=1;
            for(int j=n-1;j>=0;j--)
                if(mp[i][j]==0)
                    mxl[i][j]=mxl[i][j+1]+1;
        }

        int ans=0;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=m;i++){
                if(mp[i][k])
                    continue;

                int spa = mxl[i][k];
                int tmx = mxl[i][k];
                for(int j=0;j+i<=m;j++){
                    if(mp[i+j][k])
                        break;
                    tmx = min(tmx,mxl[i+j][k]);
                    spa = max(spa,tmx*(j+1));
                }
                ans = max(ans,spa);

            }
        }
        cout<<ans<<'\n';
        // cout<<'\n';
    }
    

    return 0;
}