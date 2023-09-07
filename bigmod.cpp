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

ll b,p,m;

void solve(){
    ll ret = 1;
    b %= m;
    while(p){
        if(p&1)
            ret *= b;
        ret %= m;
        b *= b;
        b %= m;
        p /= 2;
    }
    cout<<ret<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    while(cin>>b>>p>>m){
        solve();
    }

    return 0;
}