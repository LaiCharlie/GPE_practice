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

void solve(string s){
    int len = int(s.size());

    vector<int> f(len,0);
    f[0] = -1;
    int j = f[0]; // -1
    
    for(int i=1;i<len;i++){
        while(j>=0 && s[i]!=s[j+1])
            j=f[j];
        if(s[i]==s[j+1])
            j++;

        f[i]=j;
    }

    int rl = len - (f[len-1]+1);
    if(len%rl==0)
        cout<<len/rl<<'\n';
    else
        cout<<"1\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    string s;
    while(cin>>s){
        if(s==".")
            break;
        solve(s);
    }

    return 0;
}