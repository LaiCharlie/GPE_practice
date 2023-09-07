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

    int n,cas=1;
    while(cin>>n){
        ll tmp,sum=1,sz=n;
        vector<ll> mul;
        mul.clear();
        while(n--){
            cin>>tmp;
            if(tmp!=0){
                sum*=tmp;
                mul.push_back(sum);
            }
            else{
                sum=1;
                mul.push_back(0);
            }
        }

        ll mx=0;
        int lwb=-1;
        for(int i=0;i<sz;i++){
            for(int j=lwb+1;j<=i;j++){
                if(mul[i]==0){
                    lwb=max(lwb,i);
                    break;
                }
                if(mul[i] && mul[j]){
                    if(i==j && mul[i]<1 && mx==0)
                        break;
                    mx = max(mx,max(mul[i],mul[i]/mul[j]));
                }
            }
        }
            
        cout<<"Case #"<<cas<<": The maximum product is "<<mx<<".\n\n";
        cas++;
    }

    return 0;
}