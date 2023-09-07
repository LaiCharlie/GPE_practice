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

bool cmp(pii a,pii b){
    return a.F<b.F;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;cin>>n;
    for(int z=0;z<n;z++){
        if(z) cout<<'\n';
        int en;
        cin>>en;
        vector<pii> cov,ans;
        ans.clear();
        cov.clear();
        int x,y;
        while(cin>>x>>y){
            if(x==0 && y==0)
                break;
            pii tmp;
            tmp.F=x;
            tmp.S=y;
            cov.push_back(tmp);
        }
        sort(cov.begin(),cov.end(),cmp);

        int r=0;
        for(int i=0;i<cov.size();i++){
            int p  = -1;
            int tr = r;
            while(i < cov.size() && cov[i].F <= r){
                if(cov[i].S > tr){
                    p = i;
                    tr = cov[i].S;
                }
                i++;
            }
            i--;

            if(p == -1)
                break;
            ans.push_back(cov[p]);
            r = tr;
            if(r >= en)
                break;
        }

        if(r < en)
            cout<<"0\n";
        else{
            cout<<ans.size()<<'\n';
            for(auto i:ans)
                cout<<i.F<<' '<<i.S<<'\n';
        }
    }

    return 0;
}