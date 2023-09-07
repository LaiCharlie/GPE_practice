#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    while(cin>>n){
        vector<int> ans;
        int tmp;
        for(int i=0;i<n;i++){
            cin>>tmp;
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end());
        int mn,mm;
        if(n%2){
            mn=ans[n/2];
            mm=ans[n/2];
        }
        else{
            mn=ans[n/2-1];
            mm=ans[n/2];
        }
        
        int num=0;
        for(int i=0;i<n;i++){
            if(ans[i]==mn||ans[i]==mm)
                num++;
        }
        int s=0;
        if(n%2)
            s=1;
        else
            s=mm-mn+1;
        
        cout<<mn<<' '<<num<<' '<<s<<'\n';
    }

    return 0;
}