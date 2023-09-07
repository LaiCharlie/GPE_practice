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

char mp[105][105];
int x,y,z;

int mx(int a,int b){
    int xr = min(a,x-a+1);
    int yr = min(b,y-b+1);
    return min(xr,yr);
}

int ans(int a,int b){
    int ret = 1,upb=mx(a,b);
    bool r = true;

    while(r){
        int rad = (ret+1)/2;
        if(rad>upb)
            break;
        for(int i=-rad;i<=rad;i++){
            for(int j=-rad;j<=rad;j++){
                if(mp[a+i][b+j]!=mp[a][b])
                    r = false;
            }
        }
        ret+=2;
    }

    return ret-2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    cin>>n;
    while(n--){
        cin>>x>>y>>z;
        cout<<x<<' '<<y<<' '<<z<<'\n';
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cin>>mp[i][j];}}
        
        for(int i=0;i<z;i++){
            int a,b;
            cin>>a>>b;
            a+=1;
            b+=1;
            cout<<ans(a,b)<<'\n';
        }
    }

    return 0;
}