#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
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

    map<int,pii > mp;
    vector<int> s;
    s.clear();
    int last=1;
    for(int i=0;6*i<100000;i++){
        mp[last+6*i]=make_pair(i,0);
        last+=6*i;
        s.push_back(last);
        if(last>100000)
            break;
    }
    
    int sz=int(s.size());
    for(int i=1;i<sz;i++){
        int now=s[i];
        for(int j=0;j<6;j++){
            if(j==0){
                for(int z=0;z<i;z++){
                    int tx=mp[now].first;
                    int ty=mp[now].second;
                    now--;
                    mp[now]=make_pair(tx,ty-1);
                }
            }
            else if(j==1){
                for(int z=0;z<i;z++){
                    int tx=mp[now].first;
                    int ty=mp[now].second;
                    now--;
                    mp[now]=make_pair(tx-1,ty);
                }
            }
            else if(j==2){
                for(int z=0;z<i;z++){
                    int tx=mp[now].first;
                    int ty=mp[now].second;
                    now--;
                    mp[now]=make_pair(tx-1,ty+1);
                }
            }
            else if(j==3){
                for(int z=0;z<i;z++){
                    int tx=mp[now].first;
                    int ty=mp[now].second;
                    now--;
                    mp[now]=make_pair(tx,ty+1);
                }
            }
            else if(j==4){
                for(int z=0;z<i;z++){
                    int tx=mp[now].first;
                    int ty=mp[now].second;
                    now--;
                    mp[now]=make_pair(tx+1,ty);
                }
            }
            else if(j==5){
                for(int z=0;z<i-1;z++){
                    int tx=mp[now].first;
                    int ty=mp[now].second;
                    now--;
                    mp[now]=make_pair(tx+1,ty-1);
                }
            }
        }
    }

    int n;
    while(cin>>n)
        cout<<mp[n].first<<' '<<mp[n].second<<'\n';

    return 0;
}