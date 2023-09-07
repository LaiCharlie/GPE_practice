#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

bool mp[105][105];
vector<int> dis;
int endp;
int ans;

void bfs(int start,int mx){
    dis.clear();
    for(int i=1;i<=mx+5;i++)
        dis.push_back(0);

    queue<int> t;
    t.push(start);
    while(!t.empty()){
        int np = t.front();
        t.pop();
        for(int i=1;i<=mx;i++){
            if(mp[np][i] && dis[np]+1>dis[i]){
                dis[i]=dis[np]+1;
                t.push(i);
            }
        }
    }

    for(int i=1;i<=mx;i++)
        ans=max(ans,dis[i]);

    for(int i=1;i<=mx;i++)
        if(dis[i]==ans){
            endp=i;
            break;
        }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int m,cas=1;
    while(cin>>m&&m){
        int start;
        cin>>start;
        int x,y;
        memset(mp,0,sizeof(mp));
        while(cin>>x>>y){
            if(x==0&&y==0)
                break;
            mp[x][y]=true;
        }
        ans=0;
        endp=0;
        bfs(start,m);

        cout<<"Case "<<cas<<": The longest path from "<<start<<" has length ";
        cout<<ans<<", finishing at "<<endp<<".\n";
        cout<<'\n';
        cas++;
    }

    return 0;
}