#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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

    ll n;
    while(cin>>n&&n){
        ll tmp=sqrt(n);
        if(n==tmp*tmp)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }

    return 0;
}