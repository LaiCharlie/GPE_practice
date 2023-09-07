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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    string a,b;
    while(getline(cin,a)){
        getline(cin,b);
        int ca[26];
        int cb[26];
        memset(ca,0,sizeof(ca));
        memset(cb,0,sizeof(cb));
        for(int i=0;i<a.size();i++)
            if(a[i]>='a'&&a[i]<='z')
                ca[a[i]-'a']++;
        for(int i=0;i<b.size();i++)
            if(b[i]>='a'&&b[i]<='z')
                cb[b[i]-'a']++;
        for(int i=0;i<26;i++){
            int com = min(ca[i],cb[i]);
            while(com--)
                cout<<char('a'+i);
        }
        cout<<'\n';
    }
    

    return 0;
}