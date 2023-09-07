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

ll mx(string str){
    ll ret = 1;
    vector<int> num;
    vector<char> op;
    ll n = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0' && str[i]<='9')
            n = n*10 + str[i]-'0';
        else{
            num.push_back(n);
            n = 0;
            op.push_back(str[i]);
        }
    }
    num.push_back(n);

    ll now = num[0];
    vector<ll> after;
    for(int i=0;i<op.size();i++){
        if(op[i]=='+')
            now+=num[i+1];
        else if(op[i]=='*'){
            after.push_back(now);
            now=num[i+1];
        }
    }
    after.push_back(now);

    for(auto i:after)
        ret*=i;

    return ret;
}

ll mn(string str){
    ll ret = 0;
    vector<int> num;
    vector<char> op;
    ll n = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0' && str[i]<='9')
            n = n*10 + str[i]-'0';
        else{
            num.push_back(n);
            n = 0;
            op.push_back(str[i]);
        }
    }
    num.push_back(n);

    ll now = num[0];
    vector<ll> after;
    for(int i=0;i<op.size();i++){
        if(op[i]=='+'){
            after.push_back(now);
            now=num[i+1];
        }
        else if(op[i]=='*')
            now*=num[i+1];
    }
    after.push_back(now);

    for(auto i:after)
        ret+=i;

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string str;
        getline(cin,str);
        cout<<"The maximum and minimum are "<<mx(str)<<" and "<<mn(str)<<".\n";
    }

    return 0;
}