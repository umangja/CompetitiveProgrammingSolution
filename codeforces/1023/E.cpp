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
ll cnt=0;
ll n;
ll query(ll x1,ll y1,ll x2,ll y2)
{
	if(cnt>=4*n || abs(x1-x2) + abs(y1-y2)<n-1) exit(0);
	cnt++;
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n"<<flush;
	string ans;
	cin>>ans;
	return (ans=="YES"?1:0);
}

int solve()
{
	cin>>n;
	ll x=1,y=1;

	string anss="";
	while(1)
	{
		if(x==n && y==n) break;
		if(y+1<=n)
		{
			ll d = n-x + n-y-1;
			if(d>=n-1)
			{
				ll ans = query(x,y+1,n,n);
				if(ans==1) y++,anss+="R";
				else x++,anss+="D";
			}
			else break;
		}
		else
		{
			ll d = n-x-1+n-y;
			if(d>=n-1)
			{
				ll ans = query(x+1,y,n,n);
				if(ans==1) x++,anss+="D";
				else y++,anss+="R";
			}
			else break;
		}
	}

	if(x==n && y==n	)
	{
		cout<<"! "<<anss<<"\n"<<flush;
		return 0;
	}

	ll cx = n,cy = n;
	string ansr="";
	while(1)
	{
		if(cx-1>=1)
		{
			ll d = cx-1+cy;
			if(d>=n-1)
			{
				ll ans = query(1,1,cx-1,cy);
				if(ans==1) cx--,ansr+="D";
				else cy--,ansr+="R";
			}
			else break;
		}
		else
		{
			ll d = cx+cy-1;
			if(d>=n-1)
			{
				ll ans = query(1,1,cx,cy-1);
				if(ans==1) cy--,ansr+="R";
				else cx--,ansr+="D";
			}
			else break;
		}

		if(cx==x && cy==y) break;
	}

	reverse(ansr.begin(), ansr.end());
	anss+=ansr;



	cout<<"! "<<anss<<"\n"<<flush;
	return 0;





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