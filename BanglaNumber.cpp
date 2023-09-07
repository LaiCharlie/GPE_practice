#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

string m[4]={"shata","hajar","lakh","kuti"};


void solve(ll n,int c){
    if(n==0&&c==2)
        return;
    ll k = n/10000000;
    n%=10000000;
    ll l = n/100000;
    n%=100000;
    ll h = n/1000;
    n%=1000;
    ll s = n/100;
    n%=100;
    if(k)
        cout<<' '<<k<<' '<<m[3];
    if(l)
        cout<<' '<<l<<' '<<m[2];
    if(h)
        cout<<' '<<h<<' '<<m[1];
    if(s)
        cout<<' '<<s<<' '<<m[0];
    if(n)
        cout<<' '<<n;
    if(k==0&&l==0&&h==0&&s==0&&n==0)
        cout<<" 0";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    ll n,cas=1;
    while(cin>>n){
        cout<<setw(4)<<setfill(' ')<<cas<<'.';
        if(n>=1000000000){
            solve(n/10000000,1);
            if((n/10000000))
                cout<<" kuti";
            n%=10000000;
            solve(n,2);
            cout<<'\n';
            cas++;
        }
        else if(n>0){
            solve(n,2);
            cout<<'\n';
            cas++;
        }
        else if(n==0){
            cout<<" 0\n";
            cas++;
        }
    }


    return 0;
}

