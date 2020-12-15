/*input
3
3 2
0 0
3 3
1 1
3 3
6 7
8 8
6 9
4 1
0 0
0 1
0 2
0 3

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n,k;cin>>n>>k;
		vector<pair<int,int>> pts(n);
		for(int i=0;i<n;i++) cin>>pts[i].first>>pts[i].second;
		int pos=-1;
		for(int i=0;i<n;i++)
		{
			int ok=1;
			for(int j=0;j<n;j++) if( abs(pts[i].first-pts[j].first)+abs(pts[i].second-pts[j].second) >k ) ok=0;
			if(ok) pos=1;
		} 
		cout<<pos<<"\n";
	}
	return 0;
}
