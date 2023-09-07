#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

map<string,int> ans;

void f(string s){
    string tmp="";
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z')
            tmp+=s[i];
        else if(s[i]>='A'&&s[i]<='Z')
            tmp+=(s[i]-'A'+'a');
        else{
            if(!tmp.empty()){
                if(ans.count(tmp))
                    ans[tmp]++;
                else
                    ans[tmp]=1;
                tmp="";
            }
        }
    }
    if(!tmp.empty()){
        if(ans.count(tmp))
            ans[tmp]++;
        else
            ans[tmp]=1;
        tmp="";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    bool first=false;
    while(cin>>n){
        if(first)
            cout<<'\n';
        first=true;
        string tmp;
        
        ans.clear();

        while(getline(cin,tmp)){
            if(tmp=="EndOfText")
                break;
            f(tmp);
        }

        bool out = false;
        for(auto it=ans.begin();it!=ans.end();it++){
            if(it->second==n){
                cout<<it->first<<'\n';
                out=true;
            }
        }
        if(out==false)
            cout<<"There is no such word.\n";
    }

    return 0;
}