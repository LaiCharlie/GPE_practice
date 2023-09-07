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

string a,b;
int B[100005];

void kmpp(){
    int n=b.size();
    int i=0,j=-1;
    B[0]=-1;

    while(i<n){
        while(j>=0 && b[i]!=b[j])
            j = B[j];
        i++;
        j++;
        B[i] = j;
    }
}

int kmp(){
    int n = a.size();
    int i=0,j=0;
    while(i<n){
        while(j>=0 && a[i]!=b[j])
            j = B[j];
        i++;
        j++;
    }
    return j;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    while(cin>>a){
        b = a;
        reverse(b.begin(),b.end());
        kmpp();
        int n = kmp();
        cout<<a<<b.substr(n)<<'\n';
    }

    return 0;
}