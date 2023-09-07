#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <set>
#include <sstream>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

set<ll> s;

ll solve(ll n){
    ll ret = n*n;
    ret/=100;
    ret%=10000;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    ll n;
    while(cin>>n&&n){
        s.clear();
        ll num = n;
        while(true){
            if(s.count(num))
                break;
            s.insert(num);
            num = solve(num);
        }
        cout<<s.size()<<'\n';
    }

    return 0;
}