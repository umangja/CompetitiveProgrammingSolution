/*input
3 3
abc
ba
4 7
daaa

1 8


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n,T;cin>>n>>T;
	string s;cin>>s;
	reverse(s.begin(), s.end());

	vector<ll> a(n);
	for(ll i=0;i<n;i++) a[i]=(s[i]-'a');

	vector<ll> power2(26,0);
	power2[0] = 1;
	for(int i=1;i<26;i++) power2[i] = power2[i-1]*2;

	T = T - power2[a[0]] + power2[a[1]]; 

	
	vector<ll> b;
	for(ll i=2;i<n;i++) b.push_back(a[i]);
	sort(b.begin(), b.end());
	n-=2;

	map<int,int> cnt;
	for(ll i=0;i<n;i++) T+=(1ll<<b[i]),cnt[b[i]+1]++;
	// cout<<T<<"\n";

	int pos=(T>=0);
	ll i = 0;
	while(T>0 && pos==1)
	{
		if(((T>>i)&1)==1)
		{
			if(cnt[i]==0)
			{
				pos=0;
				break;
			} 
			else cnt[i]--,T^=(1ll<<i);
		}

		cnt[i+1]+=cnt[i]/2;
		i++;
	}

	cout<<(pos==1?"Yes\n":"No\n");

	return 0;
}