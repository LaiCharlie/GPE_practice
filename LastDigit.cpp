#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

int a[20]={1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,5,4,4};
// 21      5
// 41      9
// 61      3
// 81      7
// 101     1

ll f(ll b,ll n){
    ll base = b%10;
    ll ans = 1;
    while(n){
        if(n%2)
            ans*=base;
        ans%=10;
        n/=2;
        base*=base;
        base%=10;
    }
    return ans%10;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    string s;
    while(cin>>s){
        if(s=="0")
            break;
        int n=0;
        if(s.length()<=2)
            n=stoi(s);
        else{
            int l = s.length();
            n+=10*(s[l-2]-'0');
            n+=(s[l-1]-'0'); 
        }
        n%=100;
        int ans=0;
        if(n){
            ans+=a[(n-1)%20];
            while(n>20){
                ans+=4;
                n-=20;
            }
        }
        cout<<ans%10<<'\n';
    }

    return 0;
}