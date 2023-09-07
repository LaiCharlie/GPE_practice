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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    bool p[40005];
    int pri[5000];
    memset(pri,0,sizeof(pri));
    memset(p,true,sizeof(p));
    int sz=0;
    p[0]=false;p[1]=false;
    for(int i=2;i<40005;i++){
        if(p[i]){
            pri[sz++]=i;
            for(int j=i*2;j<40005;j+=i)
                p[j]=false;
        }
    }
    
    int n;
    while(cin>>n&&n){
        int ans=0;
        for(int i=2;i<=n;i++)
            ans = (ans + pri[n-i])%i;
        cout<<ans+1<<'\n';
    }

    return 0;
}