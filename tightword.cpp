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
    
    int k,n;
    double ans[105][15],sum;
    while(cin>>k>>n){
        memset(ans,0.0,sizeof(ans));
        sum=0.0;

        for(int i=1;i<=k+1;i++)
            ans[1][i] = 1.0 / (double)(k+1);

        for(int i=2;i<=n;i++){
            for(int j=1;j<=k+1;j++)
                ans[i][j] = (ans[i-1][j-1] + ans[i-1][j] + ans[i-1][j+1]) / (double)(k+1);
        }
        for(int i=1;i<=k+1;i++)
            sum += ans[n][i];
        if(k==0)
            sum=1.0;
            
        cout << fixed << setprecision(5) << sum*100 <<'\n';
    }

    return 0;
}