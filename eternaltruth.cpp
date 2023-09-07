#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <queue>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

char mp[305][305];
int dp[305][305][3];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int now=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        memset(mp,'#',sizeof(mp));
        memset(dp,0,sizeof(dp));
        pii s,e;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cin>>mp[i][j];
                if(mp[i][j]=='S')
                    s=make_pair(i,j);
                if(mp[i][j]=='E')
                    e=make_pair(i,j);
            }
        }
        now=1;
        queue<pii> walk;
        queue<int> seq;

        walk.push(s);
        seq.push(now); 

        dp[s.F][s.S][0]=1;
        dp[s.F][s.S][1]=1;
        dp[s.F][s.S][2]=1;

        while(!walk.empty()){
            pii fp = walk.front();
            int time = seq.front();
            seq.pop();
            walk.pop(); 
            int nx=fp.F,ny=fp.S;
            int base = dp[nx][ny][time-1];
            
            for(int i=0;i<4;i++){
                bool ww = true;
                for(int j=1;j<=time;j++){
                    if(mp[nx+j*dx[i]][ny+j*dy[i]]=='#' || (nx+j*dx[i]) > x || (nx+j*dx[i]) <1 || (ny+j*dy[i])<1 || (ny+j*dy[i])>y)
                        ww=false;
                }
                if(ww){
                    if(dp[nx+time*dx[i]][ny+time*dy[i]][time%3]==0){
                        dp[nx+time*dx[i]][ny+time*dy[i]][time%3] = base + 1;
                        walk.push(make_pair(nx+time*dx[i],ny+time*dy[i]));
                        seq.push(time%3+1);
                    }
                }
            }
        }

        int ret=x*y*10;
        for(int i=0;i<3;i++)
            if(dp[e.F][e.S][i])
                ret = min(ret,dp[e.F][e.S][i]);

        if(ret==x*y*10)
            cout<<"NO\n";
        else
            cout<<ret-1<<'\n';
    }

    return 0;
}