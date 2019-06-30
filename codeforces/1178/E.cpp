/*input
cacbac

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


int solve()
{
	string s;cin>>s;
	ll n=sz(s),i=0,j=n-1;
	string ans1="",ans2="";
	while(i<n && j>=0 && i<j)
	{
		if(s[i]==s[j]) ans1+=s[i],ans2+=s[j],i++,j--;
		else if(i+1<n && (i+1)<j && s[i+1]==s[j]) ans1+=s[i+1],ans2+=s[j],i+=2,j--;
		else if(j-1>=0 && i<(j-1) && s[i]==s[j-1]) ans1+=s[i],ans2+=s[j-1],i++,j-=2;
		else if(i+1<n && j-1>=0 && (i+1)<(j-1))ans1+=s[i+1],ans2+=s[j-1],i+=2,j-=2;
		else break;
	}
	ans1+=s[i];
	reverse(ans2.begin(), ans2.end());
	ans1+=ans2;
	cout<<ans1<<"\n";
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