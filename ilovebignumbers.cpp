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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int ans[1005]={0};
    int num[100000]={0};
    
    num[0]=1;
    ans[0]=1;
    ans[1]=1;
    
    int d = 1;
    for(int i=2;i<1001;i++){
        for(int j=0;j<d;j++)
            num[j]*=i;

        for(int j=0;j<d;j++){
            num[j+1]+=num[j]/10;
            num[j]%=10;

            if(j+1>=d && num[j+1]>0)
                d++;
                
            ans[i]+=num[j];
        }
    }

    int n;
    while(cin>>n){
        cout<<ans[n]<<'\n';
    }

    return 0;
}