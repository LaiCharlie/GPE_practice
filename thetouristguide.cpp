#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    int N,R;
    int S,D,T;
	int c1,c2,p;
    int x=0;
	queue<int> q;
	while(cin>>N>>R){
		if(N==0&&R==0) 
            break;
		int limit[N+1][N+1];
		int end[N+1];
		memset(limit,0,sizeof(limit));
		memset(end,0,sizeof(end));
		for(int i=0;i<R;i++){
			cin>>c1>>c2>>p;
			limit[c1][c2]=p-1;
			limit[c2][c1]=p-1;
		}
			
		cin>>S>>D>>T;
		q.push(S);
		end[S]=INT_MAX;

		while(!q.empty()){
			int cur=q.front();
            q.pop();
			for(int i=1;i<=N;i++){
				if(limit[cur][i]){
					if(min(limit[cur][i],end[cur]) > end[i]){
						end[i] = min(limit[cur][i],end[cur]);
						q.push(i);
					}
				}
			}
		}

		x++;
		cout<<"Scenario #"<<x<<'\n';
		
		if(T%end[D]==0)
            cout<<"Minimum Number of Trips = "<<T/end[D]<<'\n'<<'\n';
		else 
            cout<<"Minimum Number of Trips = "<<T/end[D]+1<<'\n'<<'\n';
	}

    return 0;
}