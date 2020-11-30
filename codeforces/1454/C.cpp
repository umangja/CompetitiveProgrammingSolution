/*input
5
3
1 1 1
5
1 2 3 4 5
5
1 2 3 2 1
7
1 2 3 1 2 3 1
11
2 2 1 2 3 2 1 2 3 1 2

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<int> a(n);
		vector<int> b;
		vector<int> cnt(n+1,0);

		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++)
		{
			int j = i;
			while(j<n && a[j]==a[i]) j++;
			b.push_back(a[i]);
			cnt[a[i]]++;
			i=j-1;
		}

		int ans = n+1;
		if(b.size()==1) ans=0;

		for(int i=1;i<=n;i++)
		{
			if(cnt[i]>0)
			{
				int temp = cnt[i]+1;
				if(b[0]==i) temp--;
				if(b.back()==i) temp--;
				ans=min(ans,temp);
			}
		}

		cout<<ans<<"\n";

	}
	return 0;
}
