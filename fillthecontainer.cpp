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

int milk[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int m,n;
    while(cin>>m>>n){
        memset(milk,0,sizeof(milk));
        ll l=0,r=0,mid;
        for(int i=0;i<m;i++){
            cin>>milk[i];
            if(milk[i]>l)
                l = milk[i];
            r += milk[i];
        }
        while(l<r){
            mid = (l+r)/2;
            int num=0;
            int vol=0;
            for(int i=0;i<m;i++){
                vol+=milk[i];
                if(vol>mid){
                    num++;
                    vol=milk[i];
                }
                else if(vol==mid){
                    num++;
                    vol=0;
                }
            }
            if(vol)
                num++;

            if(num>n)
                l = mid+1;
            else
                r = mid;
        }
        cout<<l<<'\n';
    }
    

    return 0;
}