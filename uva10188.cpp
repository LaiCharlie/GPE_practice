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

string w(string s){
    string str="";
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            str+=s[i];
    }
    return str;
}

void solve(const int n){
    string acc[n];
    string per="";
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        per+=s;
        acc[i]=s;
    }
    per = w(per);
    int m;
    cin>>m;
    cin.ignore();
    string ac[m];
    string pe="";
    for(int i=0;i<m;i++){
        string s;
        getline(cin,s);
        pe+=s;
        ac[i]=s;
    }
    pe=w(pe);
    bool AC=true;
    bool PE=true;
    if(n!=m)
        AC=false;
    if(AC){
        for(int i=0;i<n;i++){
            if(acc[i].size()!=ac[i].size())
                AC=false;
            else{
                int len=int(acc[i].size());
                for(int j=0;j<len;j++)
                    if(acc[i][j]!=ac[i][j])
                        AC=false;
            }
        }
    }
    if(pe.size()!=per.size())
        PE=false;
    else{
        int len=int(per.size());
        for(int j=0;j<len;j++)
            if(per[j]!=pe[j])
                PE=false;
    }

    if(AC&&PE)
        cout<<"Accepted\n";
    else if(PE)
        cout<<"Presentation Error\n";
    else
        cout<<"Wrong Answer\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n,cas=1;
    while(cin>>n&&n){
        cin.ignore();
        cout<<"Run #"<<cas<<": ";
        solve(n);
        cas++;
    }

    return 0;
}