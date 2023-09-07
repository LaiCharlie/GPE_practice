#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

double r[10];
double d[10];

void calc(int idx){
    double x;
    for(int i=0;i<idx;i++){
        x = sqrt((r[idx]+r[i])*(r[idx]+r[i])-(r[idx]-r[i])*(r[idx]-r[i]))+d[i];
        d[idx] = max(d[idx],x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    int i;
    double tmp,ans;
    cin>>n;
    while(n--){
        cin>>m;
        for(i=0;i<m;i++)
            cin>>r[i];
            
        sort(r,r+m);
        ans = 1e100;

        memcpy(d,r,sizeof(r));
        for(i=1;i<m;i++) 
            calc(i);
        tmp = 0.0;
        for(i=0;i<m;i++) 
            tmp = max(tmp,d[i]+r[i]);
        ans = min(ans,tmp);

        while(next_permutation(r,r+m)){
            memcpy(d,r,sizeof(r));
            for(i=1;i<m;i++) 
                calc(i);
            tmp = 0.0;
            for(i=0;i<m;i++) 
                tmp = max(tmp,d[i]+r[i]);
            ans = min(ans,tmp);
        }
        
        cout<<fixed<<setprecision(3)<<ans<<'\n';
    }

    return 0;
}