/*input
3
101


*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define is_empty(v) v.empty()
#define vs			vector< string >
#define vvi			vector< vector< ll,ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define reprr(i,a,b) for(ll int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define sum(v)      accumulate(v.begin(),v.end(),(ll)0)
//map <long long int,long long int> ma;
//set <long long int, greater <long long int> > s;

ll n;
string s;

string cmp1(string s1,string s2)
{
	if(s1==".")
		return s2;
	else if(s2==".")
		return s1;

	if(sz(s1)>sz(s2))
		return s2;
	else if(sz(s1)<sz(s2))
		return s1;
	else
	{
		ll i=0;
		while(i<n && s1[i]==s2[i])
			i++;

		if(i==n || s1[i]<s2[i])
			return s1;
		else
			return s2;
		
	}
}

string sum1(ll k)
{
	string s1 = s.substr(0,k);
	string s2 = s.substr(k,n-k);

	if(s1[0]=='0' || s2[0]=='0')
		return ".";
	string ans="";

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	while(sz(s2)!=sz(s1))
	{
		if(sz(s1)<sz(s2))
			s1+='0';
		else
			s2+='0';
	}

	ll c=0;
	rep(i,0,sz(s2))
	{
		ll t = (s1[i]-'0')+(s2[i]-'0')+c;
		ans+=t%10+'0';
		c=t/10;
	}

	if(c)
		ans+=c+'0';

	reverse(ans.begin(), ans.end());
	return ans;
}
int solve()
{
	cin>>n>>s;

	ll i=n/2;
	while(i<n && s[i]=='0')
		i++;
	ll j=n/2;
	while(j>=0 && s[j]=='0')
		j--;

	// cout<<i<<j;

	string ans1=sum1(i),ans2=sum1(j);
	if(i+1<=n-1)
		ans1 = cmp1(ans1,sum1(i+1));
	if(j-1>=1)
		ans2 = cmp1(ans2,sum1(j-1));

	// cout<<ans1<<" "<<ans2<<" \n";

	cout<<cmp1(ans1,ans2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();
}