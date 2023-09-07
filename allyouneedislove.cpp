#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

ll gcd(ll a,ll b){
    if(a<b)
        swap(a,b);
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

void solve(string a,string b){
    ll x=0,y=0,base;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    base=1;
    for(int i=0;i<a.size();i++){
        x+=(a[i]-'0')*base;
        base*=2;
    }
    base=1;
    for(int i=0;i<b.size();i++){
        y+=(b[i]-'0')*base;
        base*=2;
    }
    if(gcd(x,y)==1)
        cout<<"Love is not all you need!\n";
    else
        cout<<"All you need is love!\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n,cas=1;
    cin>>n;
    while(n--){
        string x,y;
        cin>>x>>y;
        cout<<"Pair #"<<cas<<": ";
        solve(x,y);
        cas++;
    }

    return 0;
}