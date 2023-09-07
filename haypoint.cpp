#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
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

    int m,n;
    cin>>m>>n;
    map<string,int> v;
    for(int i=0;i<m;i++){
        string str;
        int val;
        cin>>str>>val;
        v[str]=val;
    }
    for(int i=0;i<n;i++){
        ll tot=0;
        string inp;
        while(cin>>inp){
            if(inp==".")
                break;
            if(v.count(inp))
                tot+=v[inp];
        }
        cout<<tot<<'\n';
    }

    return 0;
}