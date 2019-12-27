/*input

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
#define inf			(ll)1e18
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


int solve()
{

	map<char,pii> m;
	m['U'] = mp(0,1);
	m['D'] = mp(0,-1);
	m['R'] = mp(1,0);
	m['L'] = mp(-1,0);


	ll n;cin>>n;
	string s;cin>>s;
	ll fx,fy;
	cin>>fx>>fy;

	// vpii step(n);
	// rep(i,0,n) step[i]=m[s[i]];

	if((n<abs(fx)+abs(fy))) {cout<<"-1\n"; return 0;}

	ll low=0,high=n+1;
	while(low<high)
	{
		ll mid = low+(high-low)/2;

		ll f=0;
		ll x=0,y=0,j=0;
		while(j+mid-1<n)
		{
			if(j!=0) x+=m[s[j-1]].F,y+=m[s[j-1]].S,x-=m[s[j+mid-1]].F,y-=m[s[j+mid-1]].S;
			else rep(i,mid,n) x+=m[s[i]].F,y+=m[s[i]].S;
			if( abs(x-fx)+abs(y-fy) <= mid  && (abs(abs(x-fx)+abs(y-fy) -mid))%2==0) {f=1;break;}
			// whatis(x);
			// whatis(y);
			j++;
		}

		if(f) high=mid;
		else low=mid+1;
	}

	if(low==n+1) low=-1;
	cout<<low<<"\n";



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
