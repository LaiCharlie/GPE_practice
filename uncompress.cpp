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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    vector<string> dic;
    string l;
    while(getline(cin,l)){
        if(l=="0")
            break;
        for(int i=0;i<l.size();i++){
            if((l[i]>='a'&&l[i]<='z')||(l[i]>='A'&&l[i]<='Z')){
                string tmp = "";
                while((l[i]>='a'&&l[i]<='z')||(l[i]>='A'&&l[i]<='Z'))
                    tmp+=l[i++];
                i--;
                dic.push_back(tmp);
                cout<<tmp;
            }
            else if(l[i]>='0'&&l[i]<='9'){
                int val = 0;
                while(l[i]>='0'&&l[i]<='9')
                    val = val*10 + l[i++]-'0';
                i--;
                string tmp = dic[dic.size()-val];
                dic.erase(dic.end()-val);
                dic.push_back(tmp);
                cout<<tmp;
            }
            else
                cout<<l[i];
        }
        cout<<'\n';
    }

    return 0;
}