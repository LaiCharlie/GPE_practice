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

ll fac(ll n){
    ll ret=1;
    for(ll i=2;i<=n;i++)
        ret*=i;
    return ret;
}

ll ans(ll n){
    return (fac(2*n)/fac(n)/fac(n))/(n+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    ll n;
    bool f=true;
    while(cin>>n){
        if(f) f=false;
        else cout<<'\n';
        cout<<ans(n)<<'\n';
    }

    return 0;
}