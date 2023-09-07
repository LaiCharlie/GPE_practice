#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

void solve(ll A,ll B,ll &x,ll &y,ll &g){
    if(!B){
        x = 1;
        y = 0;
        g = A;
    }
    else{
        solve(B,A%B,y,x,g);
        y -= x*(A/B);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    ll A,B,x,y,g;
    while(cin>>A>>B){
        solve(A,B,x,y,g);
        cout<<x<<' '<<y<<' '<<g<<'\n';
    }

    return 0;
}