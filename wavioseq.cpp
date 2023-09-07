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

    int n;
    while(cin>>n){
        vector<int> str(n,0);
        for(int i=0;i<n;i++)
            cin>>str[i];
        vector<int> lis;
        vector<int> lds;
        lis.push_back(str[0]);
        lds.push_back(str[n-1]);

        vector<int> num1(n,0);
        vector<int> num2(n,0);
        num1[0]=1;
        num2[n-1]=1;
        int cnt1=1;
        int cnt2=1;

        for(int i=1;i<n;i++){
            if(str[i]>lis.back()){
                lis.push_back(str[i]);
                num1[i] = ++cnt1;
            }
            else{
                auto it = lower_bound(lis.begin(),lis.end(),str[i]);
                *it = str[i];
                num1[i] = (it - lis.begin() + 1);
            }
        }

        for(int i=n-2;i>=0;i--){
            if(str[i]>lds.back()){
                lds.push_back(str[i]);
                num2[i] = ++cnt2;
            }
            else{
                auto it = lower_bound(lds.begin(),lds.end(),str[i]);
                *it = str[i];
                num2[i] = (it - lds.begin() + 1);
            }
        }
        
        int t = min(cnt1,cnt2);
        bool out = false;
        for(t;t>0;t--){
            for(int i=0;i<n;i++){
                if(num1[i]>=t && num2[i]>=t){
                    cout<<2*t-1<<'\n';
                    out = true;
                    break;
                }
            }
            if(out)
                break;
        }
    }

    return 0;
}