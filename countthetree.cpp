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

    int c[305][2005];
    memset(c,0,sizeof(c));
    c[1][0]=1;
    for(int i=2;i<301;i++){
        for(int j=0;j<2000;j++)
            c[i][j]+=c[i-1][j]*(4*i-2);
        for(int j=0;j<2000;j++){
            c[i][j+1]+=c[i][j]/10;
            c[i][j]%=10;
        }
        for(int j=1999;j>=0;j--){
            c[i][j-1]+=c[i][j]%(i+1)*10;
            c[i][j]/=(i+1);
        }

        for(int j=0;j<2000;j++)
            c[i][j]*=i;
        for(int j=0;j<2000;j++){
            c[i][j+1]+=c[i][j]/10;
            c[i][j]%=10;
        }
    }
    
    int n;
    while(cin>>n&&n){
        int endp = 2000;
        while(c[n][endp]==0)
            endp--;
        for(int i=endp;i>=0;i--)
            cout<<c[n][i];
        cout<<'\n';
    }

    return 0;
}