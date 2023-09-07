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

struct sudoku{
    int mp[9][9];
    bool sol = false;

    vector<int> select(int r,int c);
    void print();
    void scan();
    int next(int r,int c);
    void solve();
    void dfs(int row,int col);
};
sudoku ANS;

void sudoku::print(){
    for(int i=0;i<9;i++){
        for(int j=0;j<8;j++)
            cout<<mp[i][j]<<' ';
        cout<<mp[i][8]<<'\n';
    }
}

vector<int> sudoku::select(int r,int c){
    bool box[9]={false};

    for(int i=0;i<9;i++){
        if(mp[i][c]>0)
            box[mp[i][c]-1] = true;
        if(mp[r][i]>0)
            box[mp[r][i]-1] = true;
    }
    int row_start = 3*(r/3);
    int col_start = 3*(c/3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mp[row_start+i][col_start+j]>0)
                box[mp[row_start+i][col_start+j]-1] = true;
        }
    }

    vector<int> ret;
    for(int i=0;i<9;i++){
        if(!box[i])
            ret.push_back(i+1);
    }
    return ret;
}

int sudoku::next(int r,int c){
    int j = c;
    for(int i=r;i<9;i++){
        while(j<9){
            if(mp[i][j]==0){
                int pos = i*9+j;
                return pos;
            }
            j++;
        }
        j=0;
    }
    return -1;
}

void sudoku::dfs(int row,int col){
    int pos = next(row,col);
    if(pos==-1){
        sol = true;
        return;
    }

    vector<int> tmp = select(row,col);
    int len = int(tmp.size());

    for(int i=0;i<len;i++){
        mp[row][col] = tmp[i];

        pos = next(row,col);
        int nr = pos/9;
        int nc = pos%9;
        dfs(nr,nc);
        
        if(sol)
            return;
    }
    mp[row][col]=0;
}

void sudoku::solve(){
    int firstempty = next(0,0);
    int nr = firstempty/9;
    int nc = firstempty%9;
    dfs(nr,nc);

    bool f = false;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            vector<int> v = select(i,j);
            if(!v.empty())
                f = true;
        }
    }

    if(!sol || f)
        cout << "NO\n";
    else
        print();
    sol = false;
}

void sudoku::scan(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin>>mp[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    cin>>n;
    while(n--){
        ANS.scan();
        ANS.solve();
    }

    return 0;
}