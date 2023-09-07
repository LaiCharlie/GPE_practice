#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int s;
    ull d;
    while(cin>>s>>d){
        ull now=0;
        while(now<d){
            now+=s;
            s++;
        }
        cout<<s-1<<'\n';
    }

    return 0;
}