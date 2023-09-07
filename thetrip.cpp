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

    int n;
    while(cin>>n&&n){
        int d,c,tot=0;
        char s;
        vector<int> pay;
        pay.clear();
        for(int i=0;i<n;i++){
            cin>>d>>s>>c;
            pay.push_back(d*100+c);
            tot+=(d*100+c);
        }
        sort(pay.begin(),pay.end());
        int evp = tot/n;
        int lef = tot - evp*n;
        vector<int> ave(n);
        for(int i=0;i<n;i++){
            ave[i]=evp;
            if(lef>0)
                ave[i]+=1;
            lef--;
        }
        sort(ave.begin(),ave.end());
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(pay[i]<ave[i])
                ans+=(ave[i]-pay[i]);
        }
        cout<<'$'<<ans/100<<'.'<<setw(2)<<setfill('0')<<ans%100<<'\n';
    }

    return 0;
}