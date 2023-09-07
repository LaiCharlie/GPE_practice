#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

bool t=false;

int solve(vector<int> arr,int n){
    int d=-100000000;
    
    for(int x=n-1;x>=0;x--){
        for(int k=0;k<n;k++){
            for(int i=k+1;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(arr[i]!=arr[x] && arr[j]!=arr[x] && arr[x]!=arr[k]){
                        if(arr[x] == arr[i]+arr[j]+arr[k]){
                            d = max(d,arr[x]);
                            t = true;
                            return d;
                        }
                    }
                }
            }
        }
    }
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    int n;
    while(cin>>n&&n){
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        t=false;
        int d = solve(arr,n);
        if(t)
            cout<<d<<'\n';
        else
            cout<<"no solution\n";
    }
    

    return 0;
}