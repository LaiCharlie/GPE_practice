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

vector<int> l2,l4,l6,l8;

void init2(){
    l2.clear();
    for(int i=0;i<100;i++){
        int l=i/10;
        int r=i%10;
        if(i == (l+r)*(l+r))
            l2.push_back(i);
    }
}

void init4(){
    l4.clear();
    l4.push_back(0);
    l4.push_back(1);
    for(ll i=100;i<10000;i++){
        ll l=i/100;
        ll r=i%100;
        if(i == (l+r)*(l+r))
            l4.push_back(i);
    }
}

void init6(){
    l6.clear();
    l6.push_back(0);
    l6.push_back(1);
    for(ll i=10000;i<1000000;i++){
        ll l=i/1000;
        ll r=i%1000;
        if(i == (l+r)*(l+r))
            l6.push_back(i);
    }
}

void init8(){
    l8.clear();
    l8.push_back(0);
    l8.push_back(1);
    for(ll i=1000000;i<100000000;i++){
        ll l=i/10000;
        ll r=i%10000;
        if(i == (l+r)*(l+r))
            l8.push_back(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    init2();
    init4();
    init6();
    init8();
    int n;
    while(cin>>n){
        if(n==2)
            for(auto i:l2)
                cout<<setw(2)<<setfill('0')<<i<<'\n';
        else if(n==4)
            for(auto i:l4)
                cout<<setw(4)<<setfill('0')<<i<<'\n';
        else if(n==6)
            for(auto i:l6)
                cout<<setw(6)<<setfill('0')<<i<<'\n';
        else
            for(auto i:l8)
                cout<<setw(8)<<setfill('0')<<i<<'\n';
    }

    return 0;
}