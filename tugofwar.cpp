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

ll f[23005];
int h[105];

int gcd(int a,int b){
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int t,n,sum,r;
    while(cin>>t){
        while(t--){
            cin>>n;
            sum=0;
            for(int i=1;i<=n;i++){
                cin>>h[i];
                sum+=h[i];
            }
            r = 1;
            if(n){
                r = h[1];
                for(int i=2;i<=n;i++)
                    r = gcd(r,h[i]);
                sum/=r;
                for(int i=1;i<=n;i++)
                    h[i]/=r;
            }

            for(int i=sum/2;i>=0;i--)
                f[i] = 0LL;
            f[0] = 1LL;
            for(int i=1;i<=n;i++)
                for(int j=sum/2;j>=h[i];j--)
                    f[j] |= (f[j-h[i]]<<1);
            
            int move = sum/2+1;
            while(move--){
                if(n%2==0 && f[move]&(1LL<<((n+1)/2))) break;
                if(n%2==1 && f[move]&(1LL<<((n+0)/2))) break;
                if(n%2==1 && f[move]&(1LL<<((n+1)/2))) break;
            }
            cout<<move*r<<' '<<(sum-move)*r<<'\n';
            if(t)
                cout<<'\n';
        }
    }

    return 0;
}