/*input
5
afogk
asdji


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

ll k;
string div_string(string s1)
{
	ll n = sz(s1);
	ll rem = 0;
	string ans = "";
	rep(i,0,n)
	{
		ll d = s1[i]-'a';
		d+=rem;
		ll q = (d)/2;
		rem = (d%2)*26;
		ans+='a'+q;
	}

	if(sz(ans)>k)
	{
		reverse(ans.begin(), ans.end());
		ans = ans.substr(0,k);
		reverse(ans.begin(), ans.end());
	}
	return ans;
}

string sum_string(string s1,string s2)
{
	string ans = "";
	ll carry = 0;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	while(sz(s1)!=sz(s2))
	{
		if(sz(s1)<sz(s2))
			s1+='a';
		else
			s2+='a';
	}

	rep(i,0,sz(s1))
	{
		ll c = ((s1[i]-'a')+(s2[i]-'a')+carry)%26;
		carry = ((s1[i]-'a')+(s2[i]-'a')+carry)/26;
		ans+='a'+c;
	}

	if(carry)
		ans+='a'+carry;

	reverse(ans.begin(), ans.end());
	return ans;
}

void ch(string s1)
{
	rep(i,0,sz(s1))
	cout<<(s1[i]-'a')<<" ";
	cout<<"\n";
}

int solve()
{
	cin>>k;
	string s,t;
	cin>>s>>t;
	// ch(s);ch(t);
	string s1 = sum_string(s,t);
	// cout<<s1<<"\n";
	// ch(s1);
	string ans = div_string(s1);
	cout<<ans<<"\n";
	// ch(ans);
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