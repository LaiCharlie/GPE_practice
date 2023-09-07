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

int coin[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    ll dp[30005]={0};
    dp[0]=1;
    for(int i=0;i<11;i++){
        for(int j=coin[i];j<=30000;j++){
            dp[j] += dp[j-coin[i]];
        }
    }
    
    int b,s;
    char p;
    while(cin>>b>>p>>s){
        if(b==0&&s==0)
            break;

        int tot = b*100+s;
        cout<<setw(3)<<setfill(' ')<<b<<p<<setw(2)<<setfill('0')<<s<<setw(17)<<setfill(' ')<<dp[tot]<<'\n';
    }

    return 0;
}