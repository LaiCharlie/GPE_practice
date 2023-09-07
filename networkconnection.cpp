#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

const int mx=1005;
int F[mx];

int find(int x){
    if(F[x]==x)
        return x;
    return F[x]=find(F[x]);
}

void uni(int x,int y){
    int fx=find(x);
    int fy=find(y);
    F[fy]=fx;
}

int ac,wa;

void solve(string str){
    char op = str[0];
    int x=0,y=0,i=2;
    for(i;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9')
            x=x*10+str[i]-'0';
        else
            break;
    }
    y = stoi(str.substr(i));

    if(op=='c')
        uni(x,y);

    if(op=='q'){
        if(find(x)==find(y))
            ac++;
        else
            wa++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    string num,temp;
    getline(cin,num);
    int n = stoi(num);
    getline(cin,temp);

    for(int t=0;t<n;t++){
        if(t)
            cout<<'\n';
        string str,mum;
        getline(cin,mum);
        int m = stoi(mum);
        for(int i=0;i<m+5;i++)
            F[i]=i;
        ac=0;
        wa=0;
        
        while(getline(cin,str)){
            if(str.empty())
                break;
            solve(str);
        }
        cout<<ac<<','<<wa<<'\n';
    }

    return 0;
}