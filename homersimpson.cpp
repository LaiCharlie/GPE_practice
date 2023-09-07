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
    
    int m,n,t;
    while(cin>>m>>n>>t){
        int mxt = max(m,n);
        int mnt = min(m,n);

        int mxh = t / mnt;
        int ans;
        int rem=t+1;

        for(int i = mxh;i>=0;i--){
            int fast = i;
            int div  = t - mnt*i;
            int slow = div/mxt;
            if(t - slow*mxt - fast*mnt < rem){
                ans = slow + fast;
                rem = t - slow*mxt - fast*mnt;
            }
            else if(t - slow*mxt - fast*mnt == rem){
                ans = max(slow + fast, ans);
            }
            else if(t - slow*mxt - fast*mnt==0){
                ans = slow+fast;
                rem = 0;
                break;
            }
        }

        cout<<ans;
        if(rem)
            cout<<' '<<rem;
        cout<<'\n';
    }

    return 0;
}