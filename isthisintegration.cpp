#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

const double pi = asin(1.0)*2.0;
const double st = sqrt(3);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    double n;
    while(cin>>n){
        double ra,rb,rc;
        ra = 4.0*n*n - 2.0*n*n*pi/3.0 - n*n*st;
        rb = 4.0*n*n - n*n*pi - 2.0*ra;
        rc = n*n-ra-rb;
        cout<<fixed<<setprecision(3)<<rc<<' '<<rb<<' '<<ra<<'\n';
    }

    return 0;
}