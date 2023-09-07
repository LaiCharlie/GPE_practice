#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n,cas=1;
    while(cin>>n){
        vector<int> ans;
        set<int> sum;
        sum.clear();
        ans.clear();
        bool out = true;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            if(tmp<1)
                out = false;
            ans.push_back(tmp);
        }
        for(int i=1;i<n;i++)
            if(ans[i]<=ans[i-1])
                out = false;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(sum.count(ans[i]+ans[j]))
                    out = false;
                sum.insert(ans[i]+ans[j]);
            }
        }

        cout<<"Case #"<<cas;
        if(out)
            cout<<": It is a B2-Sequence.\n\n";
        else
            cout<<": It is not a B2-Sequence.\n\n";
        cas++;
    }

    return 0;
}