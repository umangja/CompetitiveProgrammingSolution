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

ll can(ll m,ll s)
{
	return s>=0 && s<=9*m;
}

int solve()
{
	ll m,s;cin>>m>>s;
	ll s1=s;
	string ans1="";
	string ans2="";

	rep(i,0,m)
	{
		ll j=0;
		while(j<10)
		{
			if((i>0||j>0||(m==1 && j==0)) && (can(m-i-1,s-j)))
			{
				// cout<<i<<" "<<j<<"\n";
				ans1+=char('0'+j);
				s-=j;
				break;
			}
			j++;
		}

		if(j==10)
		{
			ans1="-1";
			break;
		} 
		j=9;
		while(j>=0)
		{
			if((i>0||j>0||(m==1 && j==0)) && (can(m-i-1,s1-j)))
			{
				ans2+=char('0'+j);
				s1-=j;
				break;
			}
			j--;
		}
	}

	if(ans1=="-1") ans2="-1";
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}