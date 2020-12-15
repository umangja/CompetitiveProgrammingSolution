/*input
4
5
3 1 6 6 2
4
1 2 2 1
3
2 2 2
4
6 3 2 1



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
		int sum = 0;
		for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
		int ans = n+5;
		for(int L=1;L<n;L++)
		{
			if(sum%L==0)
			{
				int tar = sum/L;
				int cur = 0;
				int pos=1;
				for(int i=0;i<n;i++)
				{
					cur+=a[i];
					if(cur==tar) cur=0;
					else if(cur>tar) pos=0;
				}

				if(pos && cur==0) ans=min(ans,n-L);

			}
		}



		sort(a.begin(), a.end());
		if(a[0]==a[n-1]) ans=0;
		ans = min(ans,n-1);
		cout<<ans<<"\n";
	}
	return 0;
}


		// vector<int> pf(n,0);
		// pf[0]=a[0];
		// for(int i=1;i<n;i++) pf[i]=pf[i-1]+a[i];
