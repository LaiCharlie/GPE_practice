#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

double p[1000000];
double z[1000000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    memset(p,0.0,sizeof(p));
    memset(p,0.0,sizeof(z));
    p[1] = 0.5;
    z[1] = log10(2);
    for(int i=2;i<1000000;i++){
        p[i] = 1 - (1.0 - p[i-1])*(1 - (1.0/i * 1.0/(i+1.0)));
        z[i] = z[i-1] + log10(1.0*i*(i+1.0));
    }
    int n;
    while(cin>>n){
        cout<<fixed<<setprecision(6)<<p[n]<<' ';
        cout.unsetf(ios::fixed);
        cout<<int(z[n])<<'\n';
    }

    return 0;
}