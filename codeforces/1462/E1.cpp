/*input
4
4
1 2 4 3
4
1 1 1 1
1
1
10
5 6 1 3 2 9 8 1 2 4


*/
#include<bits/stdc++.h>
using namespace std;
long long int fun(long long int x,long long int k)
{
	long long int ans=1;
	for(long long int i=0;i<k;i++) ans*=(x-i);
	for(long long int i=1;i<=k;i++) ans/=i; 
	return ans;
}

int main()
{
	long long int T;cin>>T;
	while(T--)
	{
		long long int n;cin>>n;
		vector<long long int> a(n);
		map<long long int,long long int> cnt;
		for(long long int i=0;i<n;i++) cin>>a[i],cnt[a[i]]++;

		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()),a.end());

		long long int ans=0;
		for(long long int i=0;i<a.size();i++)
		{
			long long int mn = a[i];
			ans+=fun(cnt[mn],3);
			ans+=fun(cnt[mn],2)*(cnt[mn+1]+cnt[mn+2]);
			ans+=fun(cnt[mn],1)*(fun(cnt[mn+1],2)+fun(cnt[mn+2],2)+cnt[mn+1]*cnt[mn+2]);
			
		}

		cout<<ans<<"\n";




	}
	return 0;
}


