#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
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
        vector<string> tmp;
        map<string,int> a;
        for(int i=0;i<n;i++){
            tmp.clear();
            for(int j=0;j<5;j++){
                string t; cin>>t;
                tmp.push_back(t);
            }
            sort(tmp.begin(),tmp.end());
            string tot="";
            for(auto k:tmp) tot+=k;
            if(a.count(tot))
                a[tot]++;
            else
                a[tot]=1;
        }
        int pop=0;
        for(auto it=a.begin();it!=a.end();it++)
            pop=max(it->second,pop);
        int ans=0;
        for(auto it=a.begin();it!=a.end();it++)
            if(it->second==pop)
                ans+=it->second;
        cout<<ans<<'\n';
    }

    return 0;
}