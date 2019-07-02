/*input
11
for 100
for 100
for 100
for 100
for 100
add
end
end
end
end
end


*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vppi        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			1e18;
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int solve()
{
	ll l,f=0;cin>>l;ll x=0;
	stack< ll > st;string s;
	st.push(1);

	ll of=1;
	rep(i,1,33)
		of*=2;
	of--;

	while(l--)
	{
		cin>>s;
		if(s=="add")
		{
			x+=st.top();
			if(x>of)
			{
				f=1;
				break;
			}
		}
		else if(s=="for")
		{
			ll n;cin>>n;
			if(n*st.top()>of)
				st.push(2*of);
			else
				st.push(n*st.top());
				
		}
		else
			st.pop();
	}
	if(!f)
		cout<<x;
	else
		cout<<"OVERFLOW!!!";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}