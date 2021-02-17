/*input
2
4
3

*/
#include<bits/stdc++.h>
using namespace std;

// W L W L 
#define rep(i,a,b) for(int i=a;i<b;i++)

int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<vector<int>> mat(n,vector<int> (n,0));
		int numWins = (n-1)/2;

		int norg = n;
		// if((n&1)==0) n--;

		rep(i,0,n){
			int cur = (i+1)%n;
			int cnt = 0;
			while(cnt<numWins){
				mat[i][cur] = 1;
				mat[cur][i] = -1;
				cur = (cur+1)%n;
				cnt++;
			} 
		}


		rep(i,0,norg) rep(j,i+1,norg) cout<<mat[i][j]<<" ";
		cout<<"\n";

	}
	return 0;
}
