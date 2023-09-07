#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <set>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

struct r{
    int no;
    int so;
    int ti;
}tmp;
vector<r> ans;

bool cmp(r a,r b){
    if(a.so!=b.so)
        return a.so>b.so;
    else{
        if(a.ti!=b.ti)
            return a.ti<b.ti;
        else
            return a.no<b.no;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    cin>>n;
    cin.ignore();
    cin.ignore();
    set<int> p;
    int ac[105][10];
    int wa[105][10];
    int tot[105];
    int time[105];
    for(int z=0;z<n;z++){
        p.clear();
        memset(time,0,sizeof(time));
        memset(ac,0,sizeof(ac));
        memset(wa,0,sizeof(wa));
        memset(tot,0,sizeof(tot));
        string str;
        while(getline(cin,str)){
            if(str.empty())
                break;
            reverse(str.begin(),str.end());
            char s = str[0];
            int base=1,a=0,b=0,c=0,num=0;
            for(int i=2;i<str.size();i++){
                if(str[i]==' '){
                    base=1;
                    num+=1;
                    continue;
                }
                if(num==0)       c+=base*(str[i]-'0');
                else if(num==1)  b+=base*(str[i]-'0');
                else if(num==2)  a+=base*(str[i]-'0');
                else break;
                base*=10;
            }
            p.insert(a);
            if(s=='C' && ac[a][b]==0){
                ac[a][b]=1;
                tot[a]+=1;
                time[a]+=c;
            }
            else if(s=='I' && ac[a][b]==0)
                wa[a][b]++;
        }
        ans.clear();
        for(auto it=p.begin();it!=p.end();it++){
            tmp.no=*it;
            tmp.so=tot[*it];
            tmp.ti=time[*it];
            for(int i=1;i<10;i++)
                if(ac[*it][i])
                    tmp.ti+=wa[*it][i]*20;
            ans.push_back(tmp);
        }  
        sort(ans.begin(),ans.end(),cmp);

        for(int i=0;i<ans.size();i++)
            cout<<ans[i].no<<' '<<ans[i].so<<' '<<ans[i].ti<<'\n';
        if(z!=n-1)
            cout<<'\n';
    }
    
    return 0;
}