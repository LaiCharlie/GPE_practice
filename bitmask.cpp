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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    ll n,l,u,ans;
    while(cin>>n>>l>>u){
        ans = 0;
        for(int i=31;i>=0;i--){
            if((ans | (ll(1)<<i)) > u)
                continue;
            if( ((ans | ll(1)<<i) <= l || (n & ll(1)<<i)==0) )
                ans |= ll(1)<<i;
        }
        cout<<ans<<'\n';
    }

    return 0;
}