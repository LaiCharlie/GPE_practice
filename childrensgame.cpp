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

//  012345678 (index)
// "987654321";

bool cmp(string a,string b){
    return a+b > b+a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    while(cin>>n&&n){
        vector<string> s;
        s.clear();
        string str;
        for(int i=0;i<n;i++){
            cin>>str;
            s.push_back(str);
        }
        sort(s.begin(),s.end(),cmp);
        string mx = "";
        for(auto i:s)
            mx = mx+i;
        // cout<<s.size()<<'\n';
        cout<<mx<<'\n';
    }

    return 0;
}