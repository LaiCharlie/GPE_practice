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

bool pri[100005];
vector<int> p;

int d(ll n){
    int ret = 0;
    while(n){
        ret+=n%10;
        n/=10;
    }
    return ret;
}

int com(ll n){
    int ret = 0;
    for(auto i:p){
        if(n<i)
            break;
        while(n%i==0){
            n/=i;
            ret += d(i);
        }
    }
    if(n>1)
        ret += d(n);
    return ret;
}

bool check(ll n){
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    p.clear();
    memset(pri,true,sizeof(pri));
    pri[0]=false; pri[1]=false;
    for(int i=2;i<100005;i++){
        if(pri[i]){
            p.push_back(i);
            for(int j=i+i;j<100005;j+=i)
                pri[j]=false;
        }
    }

    int n;
    cin>>n;
    while(n--){
        ll tmp;
        vector<int> mod;
        cin>>tmp;
        
        while(true){
            tmp++;
            if(check(tmp))
                continue;
            if(d(tmp)==com(tmp)){
                cout<<tmp<<'\n';
                break;
            }
        }
    }


    return 0;
}