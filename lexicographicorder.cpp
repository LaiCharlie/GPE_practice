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

void t(string &s,int p,int f){
    int pos = s.size()-1-f;
    while(p--){
        char tmp = s[pos];
        s[pos] = s[pos+1];
        s[pos+1] = tmp;
        pos++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    ll f[21];
    f[0]=1;
    for(int i=1;i<21;i++){
        f[i]=ll(1);
        for(int j=2;j<=i;j++)
            f[i]*=j;
    }

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string ans,str;
        ll fac;
        cin>>str>>fac;
        int sz = str.size();
        ans = str;
        fac--;

        for(int j=1;j<sz;j++){
            ll temp = fac % f[j+1];
            fac -= temp;
            temp /= f[j];
            t(ans,temp,j);
        }

        cout<<"Case "<<i+1<<": "<<ans<<'\n';
    }

    return 0;
}