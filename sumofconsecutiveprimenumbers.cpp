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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    bool pri[10005];
    int dig[5000],sz=0;
    memset(pri,true,sizeof(pri));
    memset(dig,0,sizeof(dig));
    pri[0]=false;pri[1]=false;
    for(int i=2;i<10005;i++){
        if(pri[i]){
            dig[sz++]=i;
            for(int j=i+i;j<10005;j+=i)
                pri[j]=false;
        }
    }
    int n;
    while(cin>>n&&n){
        int sum=0,ans=0,l=0;
        for(int i=0;dig[i]<=n;i++){
            sum+=dig[i];

            while(sum>n)
                sum-=dig[l++];

            if(sum==n)
                ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}