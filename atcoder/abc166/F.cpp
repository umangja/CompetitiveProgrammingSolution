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
const ll N = 1e5+5;
vi a(3,0);
ll n;
vvi q(N,vi(2,0));
map<char,ll> m;
vi last(3,0);
vector<ll> ans(N,0);
ll pos=1;

ll fun2(ll st)
{
	rep(i,st,n)
	{
		if(a[q[i][0]]==1)
		{
			a[q[i][0]]=0;
			a[q[i][1]]=1;
			ans[i] = q[i][1];
		}
		else if(a[q[i][1]]==1)
		{
			a[q[i][1]]=0;
			a[q[i][0]]=1;
			ans[i] = q[i][0];
		}
		else
		{
			pos=0;
			return 0;
		} 
	}

	return 1;
}


ll fun0(ll st)
{
	rep(i,st,n)
	{
		ll th = 0;
		if((q[i][0]==0 && q[i][1]==1) ||(q[i][0]==1 && q[i][1]==0))  th=2;
		else if((q[i][0]==1 && q[i][1]==2) ||(q[i][0]==2 && q[i][1]==1)) th=0;
		else th=1;

		assert(th!=q[i][0] && th!=q[i][1]);

		if(a[q[i][0]]>0 && a[q[i][1]]>0)
		{
			if(a[q[i][0]]==1 && a[q[i][1]]==1 && a[th]==0 && i+1<n)
			{
				if(q[i+1][0]!=th && q[i+1][1]!=th)
				{
					ll sub = q[i][0];
					ll add = q[i][1];

					a[sub]--;
					a[add]++;
					ans[i]=add;
				}
				else 
				{
					ll wh = 1;
					if(q[i+1][0]!=th) wh=0;

					if(q[i][0]==q[i+1][wh])
					{
						ll sub = q[i][1];
						ll add = (q[i][0]==sub?q[i][1]:q[i][0]);

						a[sub]--;
						a[add]++;
						ans[i]=add;

					}
					else
					{
						ll sub = q[i][0];
						ll add = (q[i][0]==sub?q[i][1]:q[i][0]);

						a[sub]--;
						a[add]++;
						ans[i]=add;
					}
				}
			}
			else if(a[q[i][0]]>=a[q[i][1]])
			{
				a[q[i][0]]--;
				a[q[i][1]]++;
				ans[i] = q[i][1];
			}
			else
			{
				a[q[i][1]]--;
				a[q[i][0]]++;
				ans[i] = q[i][0];
			}
		}
		else if(a[q[i][0]]>0)
		{
			a[q[i][0]]--;
			a[q[i][1]]++;
			last[q[i][0]]--;
			last[q[i][1]]++;
			ans[i] = q[i][1];
		}
		else if(a[q[i][1]]>0) 
		{
			a[q[i][1]]--;
			a[q[i][0]]++;
			last[q[i][1]]--;
			last[q[i][0]]++;
			ans[i] = q[i][0];
		} 
		else 
		{
			pos=0;
			return 0;
		}
	}

	return 1;
}



int solve()
{
	cin>>n;
	rep(i,0,3) cin>>a[i];

	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,2) q[i][j] = s[j]-'A';
	}

	ll my = 0;
	rep(i,0,3) my+=a[i];

	if(my==0) pos=0;
	else if(my==1) fun2(0);
	else if(my>=2) fun0(0);

	if(pos)
	{
		cout<<"Yes\n";
		rep(i,0,n) cout<<(char)(ans[i]+'A')<<"\n";
	}
	else cout<<"No\n";

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
