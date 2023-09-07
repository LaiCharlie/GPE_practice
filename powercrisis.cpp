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
    while(cin>>n&&n){
        for(int j=1;j<n;j++){
            int ans=0;
            for(int i=1;i<n;i++)
                ans = (ans+j)%i;

            if(ans==11){
                cout<<j<<'\n';
                break;
            }
        }
    }

    return 0;
}