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

ll a[55];
void p(string s){
    int sz = s.size();
    int i;
    int n=0,sign=1;
    char op='.';
    for(i=0;i<sz;i++){
        if(s[i]>='0'&&s[i]<='9')
            n=n*10+s[i]-'0';
        else if(s[i]=='-')
            sign*=-1;
        else if(s[i]=='*'||s[i]=='+'){
            op=s[i];
            break;
        }
    }
    n*=sign;

    if(op=='+'){
        p(s.substr(i+1));
        ll tmp[55];
        for(int i=0;i<50;i++)
            tmp[i]=a[i];
        a[0]=n;
        for(int i=1;i<50;i++)
            a[i]=a[i-1]+tmp[i-1];
    }
    else if(op=='*'){
        p(s.substr(i+1));
        ll tmp[55];
        for(int i=0;i<50;i++)
            tmp[i]=a[i];
        a[0]*=n;
        for(int i=1;i<50;i++)
            a[i]=a[i-1]*tmp[i];
    }
    else if(op=='.')
        for(int i=0;i<50;i++)
            a[i]=n;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    string s;
    int N;
    while(cin>>s>>N){
        string ret="";
        for(int i=0;i<s.size();i++)
            if(s[i]!='['&&s[i]!=']')
                ret+=s[i];
        memset(a,0,sizeof(a));
        p(ret);
        for(int i=0;i<N;i++){
            cout<<a[i];
            if(i==N-1)
                cout<<'\n';
            else
                cout<<' ';
        }
        // cout<<'\n';
    }

    return 0;
}