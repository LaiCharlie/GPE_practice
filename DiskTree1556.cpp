#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int mx = 50005;
typedef map<string,int>::iterator iter;

struct t{
    int sz;
    map<string,int> g[mx];

    void init();
    void insert(string s);
    void put(int u,int d);
}tree;

void t::init(){
    sz = 1;
    g[0].clear();
}

void t::insert(string s){
    int u=0;
    string tmp = "";

    for(int i=0;i<s.size();i++){
        if(s[i]=='\\'){
            if(!g[u].count(tmp)){
                g[sz].clear();
                g[u][tmp] = sz++;
            }
            u = g[u][tmp];
            tmp = "";
        }
        else
            tmp+=s[i];
    }
}

void t::put(int u,int d){
    for(iter i = g[u].begin(); i!=g[u].end() ; i++){
        for(int j=0;j<d;j++)
            cout<<' ';
        cout<< i->first <<'\n';
        put(i->second,d+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    string s;
    while(cin>>n){
        tree.init();
        for(int i=0;i<n;i++){
            cin>>s;
            s+='\\';
            tree.insert(s);
        }
        tree.put(0,0);
        cout<<'\n';
    }

    return 0;
}