#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

bool path[12][12];
char map[12][12];
int sx,sy;
int ex,ey;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool reach;

void dfs(int x,int y){
    if(x==ex && y==ey){
        reach = true;
        return;
    }

    for(int i=0;i<4;i++){
        if(map[x+dx[i]][y+dy[i]]=='.' && path[x+dx[i]][y+dy[i]]==false){
            path[x+dx[i]][y+dy[i]] = true;
            dfs(x+dx[i],y+dy[i]);
            if(reach)
                return;
            path[x+dx[i]][y+dy[i]] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    memset(path,false,sizeof(path));
    for(int i=1;i<11;i++){
        for(int j=1;j<11;j++){
            cin>>map[i][j];
            if(map[i][j]=='S')
                sx=i,sy=j;
            if(map[i][j]=='G')
                ex=i,ey=j;
        }
    }
    map[sx][sy]='.';
    map[ex][ey]='.';
    path[sx][sy]=true;
    reach = false;
    dfs(sx,sy);
    
    if(reach){
        for(int i=1;i<11;i++){
            for(int j=1;j<11;j++){
                if(path[i][j])
                    cout<<'+';
                else
                    cout<<map[i][j];
            }
            cout<<'\n';
        }
    }
    else
        cout<<"No solution\n";

    return 0;
}