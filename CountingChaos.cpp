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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    cin>>n;
    while(n--){
        string time;
        cin>>time;
        int h,m;
        int tot=600*(time[0]-'0')+60*(time[1]-'0')+10*(time[3]-'0')+(time[4]-'0');
        while(true){
            tot++;
            if(tot>=1440)
                tot=0;
            h=tot/60;
            m=tot%60;
            if(h==0){
                if(m<10 || m%10==m/10)
                    break;
            }
            else if(h<10 && (h==m%10)){
                break;
            }
            else if(h>=10 && (h%10==m/10) && (h/10==m%10)){
                break;
            }
        }
        cout<<setw(2)<<setfill('0')<<h<<':'<<setw(2)<<setfill('0')<<m<<"\n";
    }

    return 0;
}