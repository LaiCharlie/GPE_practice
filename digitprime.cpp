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

int p[1000000];
bool c[1000000];

int s(int n){
    int ret = 0;
    while(n){
        ret+=(n%10);
        n/=10;
    }
    return ret;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    memset(c,true,sizeof(c));
    memset(p,0,sizeof(p));
    c[0] = false;
    c[1] = false;
    for(int i=2;i<1000000;i++){
        p[i] = p[i-1];
        if(c[i]){
            if(c[s(i)])
                p[i]++;
            for(int j=2*i;j<1000000;j+=i)
                c[j] = false;
        }
    }

    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        if(l>=1)
            cout<<p[r]-p[l-1]<<'\n';
        else
            cout<<p[r]<<'\n';
    }

    return 0;
}