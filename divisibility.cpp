#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
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

    int t;
    cin>>t;
    while(t--){
        int m,n,a[100005];
        cin>>m>>n;
        bool ans[105];
        bool tmp[105];
        memset(ans,false,sizeof(ans));
        memset(tmp,false,sizeof(tmp));
        for(int i=0;i<m;i++){
            int z;
            cin>>z;
            a[i]=z;
        }
        
        ans[0]=true;
        for(int i=0;i<m;i++){
            a[i]%=n;
            for(int j=0;j<n;j++){
                if(ans[j]){
                    tmp[(j+n+a[i])%n]=true;
                    tmp[(j+n-a[i])%n]=true;
                }
            }
            memset(ans,false,sizeof(ans));
            for(int j=0;j<n;j++)
                ans[j]=tmp[j];
            memset(tmp,false,sizeof(tmp));
        }

        if(ans[0])
            cout<<"Divisible\n";
        else
            cout<<"Not divisible\n";
    }

    return 0;
}