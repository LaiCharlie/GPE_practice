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

struct ele{
    int iq;
    int w;
    int id;
}elep;

bool cmp(ele a,ele b){
    return a.iq < b.iq;
}

vector<int> lis;
vector<int> pre;
vector<ele> s;

void print(int index){
    if(pre[index] == index){
        cout<<s[index].id<<'\n';
        return;
    }
    print(pre[index]);
    cout<<s[index].id<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    s.clear();
    int IQ,WEI,ID=1;
    while(cin>>IQ>>WEI){
        elep.iq = IQ;
        elep.w = WEI;
        elep.id = ID++;
        s.push_back(elep);
    }
    sort(s.begin(),s.end(),cmp);
    int sz = int(s.size());
    lis.clear();
    for(int i=0;i<sz;i++)
        lis.push_back(1);
    pre.clear();
    for(int i=0;i<sz;i++)
        pre.push_back(i);


    for(int i=1;i<sz;i++){
        for(int j=0;j<i;j++){
            if(s[i].w < s[j].w && s[i].iq > s[j].iq){
                if(lis[i] < lis[j]+1){
                    lis[i] = lis[j]+1;
                    pre[i] = j;
                }
            }
        }
    }
    int mxl=1;
    int mxi=0;
    for(int i=0;i<sz;i++)
        if(lis[i]>mxl){
            mxl = lis[i];
            mxi = i;
        }
    cout<<mxl<<'\n';
    print(mxi);

    return 0;
}