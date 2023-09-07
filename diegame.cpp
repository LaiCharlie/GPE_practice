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

//   N
// W   E
//   S
//            up   d   n   s   e   w
int dice[6] = {1 , 6 , 5 , 2 , 4 , 3};
//             0   1   2   3   4   5

void init(){
    dice[0]=1;
    dice[1]=6;
    dice[2]=5;
    dice[3]=2;
    dice[4]=4;
    dice[5]=3;
}

void s(string op){
    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[1];
    dice[1] = dice[2];
    dice[2] = tmp;
}
void e(string op){
    int tmp = dice[0];
    dice[0] = dice[5];
    dice[5] = dice[1];
    dice[1] = dice[4];
    dice[4] = tmp;
}
void w(string op){
    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[1];
    dice[1] = dice[5];
    dice[5] = tmp;
}
void n(string op){
    int tmp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[1];
    dice[1] = dice[3];
    dice[3] = tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    int t;
    while(cin>>t&&t){
        init();
        for(int i=0;i<t;i++){
            string op;
            cin>>op;
            if(op=="north")
                n(op);
            else if(op=="east")
                e(op);
            else if(op=="west")
                w(op);
            else if(op=="south")
                s(op);
        }
        cout<<dice[0]<<'\n';
    }

    return 0;
}