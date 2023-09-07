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
    
    ll n,A,B,ca,cb,x,y,g;
    while(cin>>n&&n){
        cin>>ca>>A>>cb>>B;
        solve(A,B,x,y,g);
        if(n%g){
            cout<<"failed\n";
            continue;
        }
        ll mn = ceil(1.0 * (-x) * n / B);
        ll mx = floor(1.0 * y * n / A);

        if(mn>mx){
            cout<<"failed\n";
            continue;
        }
        ll aa,ab;
        if(A*cb < B*ca){
            aa = x * n / g + mn * B / g;
            ab = y * n / g - mn * A / g;
        }
        else{
            aa = x * n / g + mx * B / g;
            ab = y * n / g - mx * A / g;
        }
        cout<<aa<<' '<<ab<<'\n';
    }

    return 0;
}