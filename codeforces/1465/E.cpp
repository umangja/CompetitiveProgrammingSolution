/*input
2 -1
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


	// b 
	ll pos=0;

	vector<ll> suf(n,0);
	for(ll i=n-1;i>=0;i--) suf[i] = (i+1<n?suf[i+1]:0)+(1ll<<b[i]);

	vector<ll> cnt(26,0);
	for(ll i=0;i<n;i++) cnt[b[i]]++;

	ll cur = 0;
	for(int i=0;i<n;i++)
	{
		cur+=(1ll<<b[i]);
		if(i+1<n && T+cur==suf[i+1]) pos=1;
		else if(i+1==n && T+cur==0) pos=1;
	} 

	if(n>0 && suf[0]==T) pos=1;
	if(n==0 && T==0) pos=1;
	cout<<(pos==1 ?"Yes\n":"No\n");
	return 0;
}