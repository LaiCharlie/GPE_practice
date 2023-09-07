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

    double x,y;
    while(cin>>x>>y){
        if(x==0.0&&y==0.0)  
            break;
        
        if(x<=y)
            cout<<"0\n";
        else if(x<=2*y)
            cout<<"1\n";
        else{
            if(0.5*x/y-int(0.5*x/y)==0.5)
                cout<<"0\n";
            else if(0.5*x/y-int(0.5*x/y)<0.5)
                cout<<int(0.5*x/y)<<'\n';
            else
                cout<<int(0.5*x/y+1)<<'\n';
        }
    }

    return 0;
}