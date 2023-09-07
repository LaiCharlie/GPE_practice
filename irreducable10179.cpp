#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    const ll mx = 100000;
    bool t[mx];
    memset(t,true,sizeof(t));
    t[0]=false;
    t[1]=false;
    for(int i=4;i<mx;i+=2)
        t[i]=false;
    for(int i=3;i<mx;i+=2)
        if(t[i])
            for(int j=i+i;j<mx;j+=i)
                t[j]=false;

    ll n;
    while(cin>>n&&n){
        vector<ll> mod;
        ll ans = n;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0&&t[i]){
                mod.push_back(i);
                while(n%i==0)
                    n/=i;
            }
        }
        if(n>1)
            ans=ans*(n-1)/n;
        for(int i=0;i<mod.size();i++)
            ans=ans*(mod[i]-1)/mod[i];
        cout<<ans<<'\n';
    }

    return 0;
}