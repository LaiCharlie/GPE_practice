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
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string str;
        getline(cin,str);
        stringstream ss(str);
        vector<int> s;
        int tmp,sum=0;
        while(ss >> tmp){
            s.push_back(tmp);
            sum+=tmp;
        }
        bool dp[sum+5];
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        
        if(sum%2)
            cout<<"NO\n";
        else{
            sort(s.begin(),s.end());
            int sz = int(s.size());

            for(int i=0;i<sz;i++){
                for(int j=sum;j>=s[i];j--){
                    if(dp[j-s[i]])
                        dp[j]=true;
                }
            }
            
            if(dp[sum/2])
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        
    }
    

    return 0;
}