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

void twodlcs(string a,string b){
    a = '0'+a;
    b = '0'+b;
    int sza = int(a.size());
    int szb = int(b.size());
    int l[sza+1][szb+1];
    memset(l,0,sizeof(l));
    for(int i=0;i<sza;i++)
        l[i][0]=0;
    for(int i=0;i<szb;i++)
        l[0][i]=0;

    for(int i=1;i<sza;i++){
        for(int j=1;j<szb;j++){
            if(a[i]==b[j])
                l[i][j] = l[i-1][j-1] + 1;
            else
                l[i][j] = max(l[i-1][j],l[i][j-1]);
        }
    }
    cout<< l[sza-1][szb-1]<<'\n';
}


void onedlcs(string a,string b){
    int sza = int(a.size());
    int szb = int(b.size());
    int l[1005];
    memset(l,0,sizeof(l));
    for(int i=1;i<=sza;i++){
        for(int j=szb;j>=1;j--){
            if(a[i-1]==b[j-1])
                l[j] = l[j-1] + 1;
        }
        for(int j=1;j<=szb;j++){
            if(a[i-1]!=b[j-1])
                l[j] = max(l[j],l[j-1]);
        }
    }
    cout<< l[szb]<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    string s1,s2;
    while(getline(cin,s1)){
        getline(cin,s2);
        twodlcs(s1,s2);
    }

    return 0;
}