#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
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

    int pri[100005];
    bool num[100005];
    memset(num,true,sizeof(num));
    num[0]=false;
    num[1]=false;
    int tmp=0;
    for(int i=2;i<100005;i++){
        if(num[i]){
            pri[tmp++]=i;
            for(int j=i+i;j<100005;j+=i)
                num[j]=false;
        }
    }

    ll l,r;
    while(cin>>l>>r){
        vector<ll> p;
        p.clear();
        
        bool sel[1000005];
        memset(sel,true,sizeof(sel));
        for(int i=0;i<tmp;i++){
            int mul = l/pri[i];
            if(mul<2)
                mul=2;
            for(ll j=mul*pri[i];j<=r;j+=pri[i]){
                if(j-l>=0)
                    sel[j-l]=false;
            }
        }

        for(ll i=l;i<=r;i++){
            if(sel[i-l] && i>1)
                p.push_back(i);
        }

        pair<ll,ll> mn,mx;
        int mnl=1000000,mxl=0;
        if(p.size()<2)
            cout<<"There are no adjacent primes.\n";
        else{
            for(int i=1;i<p.size();i++){
                if(p[i]-p[i-1]>mxl){
                    mx=make_pair(p[i-1],p[i]);
                    mxl=p[i]-p[i-1];
                }   
                if(p[i]-p[i-1]<mnl){
                    mn=make_pair(p[i-1],p[i]);
                    mnl=p[i]-p[i-1];
                }
            }
            cout<<mn.F<<','<<mn.S<<" are closest, "<<mx.F<<','<<mx.S<<" are most distant.\n";
        }
    }
    

    return 0;
}