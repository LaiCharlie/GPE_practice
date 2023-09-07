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

    string s;
    int cas=1;
    while(cin>>s){
        cout<<"Case "<<cas<<":\n";
        cas++;

        int n;
        cin>>n;
        int ans[1000005];
        ans[0] = 0;
        for(int i=1;i<s.size();i++){
            ans[i]=i;
            if(s[i]==s[i-1])
                ans[i]=ans[i-1];
        }
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            if(x>y)
                swap(x,y);
            if(ans[y]<=x)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }

    return 0;
}