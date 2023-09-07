#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

const int maxn = 10;
int t, n;
int b[maxn], c[maxn];
double a[maxn], w;

double check(){
    double x[maxn] = {0};
    double m = 0;

    for(int i = 0; i < n; i++){
        x[i] = a[c[i]];

        for (int j = i - 1; j >= 0; j--)
            x[i] = max(x[i], x[j] + 2 * sqrt(a[c[i]] * a[c[j]]));
    }

    for(int i = 0; i < n; i++)
        m = max(m, x[i] + a[c[i]]);
    
    return m;
}

void work(int x){
    if (x == n){
        double k = check();
        w = min(k, w);
        return;
    }

    for(int i = 1; i <= n;i++){
        if(b[i]){
            b[i] = 0; 
            c[x] = i;
            work(x + 1);
            b[i] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    cin >> t;
    while (t--){
        cin >> n; 
        w = 1000000000;
        for(int i = 1; i <= n; i++) 
            cin >> a[i], b[i] = 1;

        work(0);

        cout<<fixed<<setprecision(3)<<w<<'\n';
    }

  return 0;
}