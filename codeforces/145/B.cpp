/*input

*/


// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll          long long int
#define pb          push_back
#define pii         pair<ll ,ll >
#define vpii        vector< pii >
#define vi          vector<ll >
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repr(i,a,b) for(ll  i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)     cout << #x << " " << x << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}

int solve()
{
	vi cnt(4,0);
	rep(i,0,4) cin>>cnt[i];

	string ans = "";
	ll pos=1;
	if(abs(cnt[2]-cnt[3])>1) 
	{
		cout<<"-1\n";
		return 0;
	}

	if(cnt[2]==cnt[3])
	{
		ll k = cnt[2]; //47 or 74
	

		if(cnt[0]-1-k>=0)
		{
			if(!(cnt[0]>=k+1 && cnt[1]>=k)) pos=0;
			string temp = "47";
			cnt[0]--;		

			cnt[0]-=(k);
			cnt[1]-=(k);

			rep(i,0,cnt[0]) ans+="4";
			rep(i,0,k) ans+=temp;
			rep(i,0,cnt[1]) ans+="7";
			ans+="4";
		}
		else
		{
			if(!(cnt[0]>=k && cnt[1]>=k+1)) pos=0;

			string temp = "74";
			cnt[1]--;		

			cnt[0]-=(k);
			cnt[1]-=(k);

			ans+=temp;
			rep(i,0,cnt[0]) ans+="4";
			rep(i,1,k) ans+=temp;
			rep(i,0,cnt[1]) ans+="7";
			ans+="7";
		}
	}
	else if(cnt[2]>cnt[3])
	{
		ll k = cnt[2]; //47 or 74
		
		if(!(cnt[0]>=k && cnt[1]>=k)) pos=0;
		string temp = "47";

		cnt[0]-=(k);
		cnt[1]-=(k);

		rep(i,0,cnt[0]) ans+="4";
		rep(i,0,k) ans+=temp;
		rep(i,0,cnt[1]) ans+="7";
	}
	else 
	{
		ll k = cnt[3]; //47 or 74
		if(!(cnt[0]>=k && cnt[1]>=k)) pos=0;
		string temp = "74";

		cnt[0]-=(k);
		cnt[1]-=(k);

		ans+=temp;
		rep(i,0,cnt[0]) ans+="4";
		rep(i,1,k-1) ans+=temp;
		rep(i,0,cnt[1]) ans+="7";
		ans+=temp;
	}

	if(cnt[0]<0 || cnt[1]<0 || pos==0) ans="-1";
	cout<<ans<<"\n";

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
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}