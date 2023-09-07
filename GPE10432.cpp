#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

void solve(){
    int n;
    cin>>n;
    char mp[n+5][n+5];
    char re[n+5][n+5];
    int sum[n+5][n+5];
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>mp[i][j];
    bool bump = false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>re[i][j];
            if(re[i][j]=='x'&&mp[i][j]=='*')
                bump=true;
        }
    }
    
    if(bump){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<mp[i][j];
            cout<<'\n';
        }
        return;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]=='*'){
                for(int x=-1;x<=1;x++)
                    for(int y=-1;y<=1;y++)
                        sum[i+x][j+y]+=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(re[i][j]=='x')
                cout<<sum[i][j];
            else
                cout<<'.';
        }
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    cin>>n;
    while(n--)
        solve();

    return 0;
}