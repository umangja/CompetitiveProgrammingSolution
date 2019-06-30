/*input
0 0
0 1
1
L


*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )

const ll N = 1e5+5;
pii st,fi;
string s;
vi ud(N,0),lr(N,0);
ll n;


ll f(ll d)
{
	ll x = st.F,y=st.S;
	
	x+=(d/n)*lr[n-1];
	y+=(d/n)*ud[n-1];

	if((d%n)!=0)
	{
		x+=lr[(d%n)-1];
		y+=ud[(d%n)-1];
	}

	if(abs(x-fi.F)+abs(y-fi.S)<=d)
		return 1;
	else
		return 0;

}	

int solve()
{
	cin>>st.F>>st.S>>fi.F>>fi.S>>n>>s;
	rep(i,0,n)
	{
		if(i>0)
		{
			ud[i]=ud[i-1];
			lr[i]=lr[i-1];
		}

		if(s[i]=='U')
			ud[i]++;
		else if(s[i]=='D')
			ud[i]--;
		else if(s[i]=='L')
			lr[i]--;
		else 
			lr[i]++;
	}

	ll low=1,high = 1e18;
	while(low<high)
	{
		ll mid = low+(high-low)/2;
		if(f(mid))
			high=mid;
		else
			low=mid+1;
	}

	if(low==1e18)
		low=-1;

	cout<<low;	
	return 0;
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