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

    int n,m;
    while(cin>>n>>m){
        vector<int> stone(m,0);
        for(int i=0;i<m;i++)
            cin>>stone[i];
        sort(stone.begin(),stone.end());

        bool win[n+5];
        memset(win,false,sizeof(win));
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                if(i-stone[j]>=0)
                    if(win[i-stone[j]]==false)
                        win[i]=true;
            }
        }
        if(win[n])
            cout<<"Stan wins\n";
        else
            cout<<"Ollie wins\n";
    }

    return 0;
}