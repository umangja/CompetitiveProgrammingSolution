/*input
15 2
4
UURL
8
LRLLLLLLLL

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vpii        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll x,n;
string s;
ll power_2[66];

void preprocess()
{
	power_2[0]=1;
	rep(i,1,66) power_2[i]=power_2[i-1]*2;
}

string binary_rep(ll no)
{
	string r="";
	while(no) r+=char('0'+no%2),no/=2;
	return r;
}



int solve()
{
	preprocess();
	ll q;cin>>n>>q;
	while(q--)
	{
		cin>>x>>s;
		string rep = binary_rep(x);
		ll h=0;
		while(rep[h]=='0') h++;
		rep(i,0,sz(s))
		{
			if(x%2==1 && (s[i]=='L' || s[i]=='R')) continue;
			if(x==(n+1)/2 && s[i]=='U') continue;

			ll left=0;
			if((x&power_2[h+1])==0) left=1;
			if(s[i]=='U')
			{
				if(left==1) x+=power_2[h];
				else x-=power_2[h];
				h++;
			}
			else
			{
				if(s[i]=='L') x-=power_2[h-1];
				else x+=power_2[h-1];
				h--;
			}
		}

		cout<<x<<"\n";
	}
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}