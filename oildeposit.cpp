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

char mp[105][105];
bool ch[105][105];

int dx[8]={0,0,1,-1,1,-1,-1,1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

void dfs(int x,int y){
    if(mp[x][y]=='@')
        ch[x][y]=true;
    else
        return;
    
    for(int i=0;i<8;i++){
        if(mp[x+dx[i]][y+dy[i]] && !ch[x+dx[i]][y+dy[i]])
            dfs(x+dx[i],y+dy[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int m,n;
    while(cin>>m>>n){
        if(m==0&&n==0)
            break;
        memset(mp,'*',sizeof(mp));
        memset(ch,false,sizeof(ch));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                cin>>mp[i][j];

        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(mp[i][j]=='@'){
                    if(ch[i][j]==false){
                        dfs(i,j);
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}