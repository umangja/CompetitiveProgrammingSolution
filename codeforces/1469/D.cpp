/*input
2
100000
199999
200000
3
4


*/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<pair<int,int>> ans;

void opt(int x,int y)
{
	assert(ans.size()<a.size()+5);
	ans.push_back(make_pair(x,y));
	a[x] = (a[x]+a[y]-1)/a[y];
	return ;
}

void fun()
{
	while(n>2)
	{
		int cur = ceil(sqrtl(n));
		for(int i = cur+1;i<n;i++) opt(i,n);
		while(a[n]>1) opt(n,cur);
		n = cur;
	}
}

int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		cin>>n;
		a.resize(n+1);
		ans.clear();
		for(int i=1;i<=n;i++) a[i]=i;

	
		fun();


		int cnt[3] = {0};
		for(int i=1;i<=n;i++) 
		{
			assert(a[i]<=2 && a[i]>=1);
			cnt[a[i]]++;
		}
		assert(cnt[1]==n-1 && cnt[2]==1);
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";

	}
	return 0;
}
