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

int rec[30];
char mp[25][25];
bool ch[25][25];

void dfs(int x,int y,char ele){
    if(mp[x][y]==ele && ch[x][y]==false){
        ch[x][y] = true;
        dfs(x+1,y,ele);
        dfs(x-1,y,ele);
        dfs(x,y+1,ele);
        dfs(x,y-1,ele);
    }
}

bool cmp(pair<char,int> a,pair<char,int> b){
    if(a.S!=b.S)
        return a.S > b.S;
    else
        return a.F < b.F;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    
    int t,cas=1;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        
        memset(ch,false,sizeof(ch));
        memset(rec,0,sizeof(rec));
        for(int i=0;i<25;i++)
            for(int j=0;j<25;j++)
                mp[i][j]='0';


        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                cin>>mp[i][j];

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(ch[i][j]==false){
                    rec[mp[i][j]-'a']++;
                    dfs(i,j,mp[i][j]);
                }
            }
        }
        cout<<"World #"<<cas++<<'\n';
        vector<pair<char,int> > outp;
        for(int i=0;i<26;i++){
            if(rec[i])
                outp.push_back(make_pair((i+'a'),rec[i]));
        }
        sort(outp.begin(),outp.end(),cmp);
        for(int i=0;i<outp.size();i++){
            cout<<outp[i].F<<": "<<outp[i].S<<'\n';
        }
    }

    return 0;
}
