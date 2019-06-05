/*input
9
add
for 43
end
for 10
for 15
add
end
add
end

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

ll of=1;
int solve()
{
	rep(i,0,32)
	{
		of*=2;
	}
	of--;

	ll n;cin>>n;
	stack<  ll > d;
	stack<  ll > o; 
	d.push(1);
	o.push(0);
	ll ans=0;
	
	rep(i,0,n)
	{
		string s;cin>>s;
		if(s=="add")
		{
			ans+=d.top();
			if(ans>of || o.top()==1)
			{
				cout<<"OVERFLOW!!!";
				return 0;
			}
		}
		else if(s=="for")
		{
			ll x;cin>>x;
			ll f =1;
			f = o.top();
			if((x*d.top())>of || f==1)
				o.push(1);
			else
				o.push(0);
			d.push(x*d.top());
		}
		else
		{
			d.pop();
			o.pop();
		}
	}

	if(ans>of)
		cout<<"OVERFLOW!!!";
	else
		cout<<ans;
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