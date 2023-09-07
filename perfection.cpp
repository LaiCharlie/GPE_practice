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
    cout<<"PERFECTION OUTPUT\n";
    while(cin>>n&&n){
        cout<<setw(5)<<n;
        int sum=0;
        for(int i=n/2;i>0;i--){
            if(n%i==0)
                sum+=i;
            if(sum>n)
                break;
        }
        if(sum<n)
            cout<<"  DEFICIENT\n";
        else if(sum==n)
            cout<<"  PERFECT\n";
        else
            cout<<"  ABUNDANT\n";
    }
    cout<<"END OF OUTPUT\n";

    return 0;
}