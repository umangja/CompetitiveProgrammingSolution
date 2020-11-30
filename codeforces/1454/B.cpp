/*input
6
2
1 1
3
2 1 3
4
2 2 2 3
1
1
5
2 3 2 4 2
6
1 1 5 5 4 4

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		vector<int> a(n);
		vector<int> cnt(n+1,0);
		vector<int> idx(n+1,0);
		for(int i=0;i<n;i++) cin>>a[i],cnt[a[i]]++,idx[a[i]]=i;
		
		int ans=-1;
		for(int i=1;i<=n;i++) if(cnt[i]==1) { ans = idx[i]+1; break; }
		cout<<ans<<"\n";
	}
	return 0;
}
