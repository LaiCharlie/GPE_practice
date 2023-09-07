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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    int n;
    while(cin>>n){
        int drink = n;
        int empty = 0;
        while(n>=3){
            drink += n/3;
            empty = n%3;
            n/=3;
            n+=empty;
        }
        if(n==2)
            drink++;
        cout<<drink<<'\n';
    }


    return 0;
}