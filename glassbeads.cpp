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
    while(n--){
        string s;
        cin>>s;
        int len = s.size();
        int p=0,q=1;
        while(p<len && q<len){
            int i;
            for(i=0;i<len;i++)
                if(s[(p+i)%len] != s[(q+i)%len])
                    break;
            if(i==len)
                break;
            
            if(s[(p+i)%len] > s[(q+i)%len])
                p += (i+1);
            else
                q += (i+1);

            if(p==q)
                q++;
        }
        cout<<min(p,q)+1<<'\n';
    }

    return 0;
}