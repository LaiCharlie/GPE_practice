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

void solve(){
    int n,pos=0;
    cin>>n;
    vector<string> p;
    while(n--){
        string op;
        cin>>op;
        if(op=="RIGHT")
            pos++;
        else if(op=="LEFT")
            pos--;
        else{
            string tmp;
            int temp;
            cin>>tmp>>temp;
            op = p[temp-1];
            if(op=="RIGHT")
                pos++;
            else if(op=="LEFT")
                pos--;
        }
        p.push_back(op);
    }
    cout<<pos<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    int n;
    cin>>n;
    while(n--){
        solve();
    }

    return 0;
}