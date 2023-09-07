#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <cstdio>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

int ans = 0;
vector<pii> road[10005];

int dfs(int from,int now){
    int mx = 0;
    for(auto &u:road[now]){
        if(u.first==from)
            continue;
        int route = u.second + dfs(now,u.first);
        if(ans < mx+route)
            ans = mx+route;
        if(mx<route)
            mx = route;
    }
    return mx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int a,b,c;
    string tmp;
    stringstream ss;
    while(!cin.eof()){
        for(int i=0;i<10005;i++)
            road[i].clear();
        ans = 0;
        while(getline(cin,tmp) && !tmp.empty()){
            ss.str("");
            ss.clear();
            ss<<tmp;
            ss>>a>>b>>c;
            tmp = "";
            road[a].push_back(make_pair(b,c));
            road[b].push_back(make_pair(a,c));
        }
        dfs(-1,1);
        cout<<ans<<'\n';
    }
    

    return 0;
}