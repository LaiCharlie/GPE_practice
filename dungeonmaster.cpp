#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

struct p{
    int f;
    int s;
    int t;
    int dis;
};

p st,en,temp;
char mp[35][35][35];
bool vis[35][35][35];
bool reach;
int ans;

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int x,y,z;

void bfs(){
    memset(vis,false,sizeof(vis));
    queue<p> q;
    q.push(st);
    vis[st.f][st.s][st.t]=true;
    while(!q.empty()){
        p now = q.front();
        q.pop();
        if(now.f==en.f && now.s==en.s && now.t==en.t){
            reach = true;
            ans = min(ans,now.dis);
            return;
        }
        for(int i=0;i<6;i++){
            int nx = now.f + dx[i];
            int ny = now.s + dy[i];
            int nz = now.t + dz[i];
            if(nx>0&&nx<=x&&ny>0&&nz>0&&ny<=y&nz<=z){
                if(mp[nx][ny][nz]=='.' && !vis[nx][ny][nz]){
                    temp.f = nx,temp.s=ny,temp.t=nz,temp.dis=now.dis+1;
                    q.push(temp);
                    vis[nx][ny][nz]=true;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    while(cin>>x>>y>>z){
        if(x==0&&y==0&&z==0)
            break;
        memset(mp,'#',sizeof(mp));
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                for(int k=1;k<=z;k++){
                    cin>>mp[i][j][k];
                    if(mp[i][j][k]=='S'){
                        st.f=i,st.s=j,st.t=k,st.dis=0;
                        mp[i][j][k]='.';
                    }
                    if(mp[i][j][k]=='E'){
                        en.f=i,en.s=j,en.t=k,en.dis=0;
                        mp[i][j][k]='.';
                    }
                }
            }
        }

        reach = false;
        ans = x*y*z*10;
        bfs();
        if(reach)
            cout<<"Escaped in "<<ans<<" minute(s).\n";
        else
            cout<<"Trapped!\n";
    }

    return 0;
}