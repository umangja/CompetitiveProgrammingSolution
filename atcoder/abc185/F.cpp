/*input
10 10
0 5 3 4 7 0 0 0 1 0
1 10 7
2 8 9
2 3 6
2 1 6
2 1 10
1 9 4
1 6 1
1 6 3
1 1 7
2 3 5

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

const int N = 3e5+5,M = 31;
vector<vector<int>> bit(M,vector<int> (N,0));

void add(int w,int idx,int val)
{
	for(int i = idx+1;i<N;i+=i&-i) bit[w][i]+=val;
	return ;
} 

ll prefixSum(int w,int idx)
{
	ll ans=0;
	for(int i = idx+1;i>0;i-=i&-i) ans+=bit[w][i];
	return ans;
}

ll rangeSum(int w,int L,int R)
{
	return prefixSum(w,R) - (L-1>=0?prefixSum(w,L-1):0);
}

ll pointQuery(int w,int L)
{
	return rangeSum(w,L,L);
}

ll getBit(ll x,ll b)
{
	return (x>>b)&1;
}

int solve()
{
	ll n,q;cin>>n>>q;
	vi a(n);
	for(int i=0;i<n;i++)
	{	
		cin>>a[i];
		for(int b=0;b<M;b++)
		{
			if(getBit(a[i],b))
			{
				// cout<<i<<" "<<b<<"\n";
				add(b,i,1);
			}
		}
	}

	// for(int b=0;b<4;b++)
	// {
	// 	cout<<"for bit "<<b<<"\n";
	// 	for(int i=0;i<n;i++) cout<<pointQuery(b,i)<<" ";
	// 	cout<<"\n";
	// }

	for(int i=0;i<q;i++)
	{
		int t;cin>>t;
		if(t==1)
		{
			ll idx,val;cin>>idx>>val;
			idx--;
			for(int b=0;b<M;b++)
			{
				int b1 = pointQuery(b,idx);
				int b2 = getBit(val,b);

				if(b1==1 && b2==1) 
				{
					// change 1 - >0
					add(b,idx,-1);
				}
				else if(b1==0 && b2==1)
				{
					// change 0 ->1
					add(b,idx,1);
				}
			}
		}
		else 
		{
			ll L,R;cin>>L>>R;
			L--,R--;
			ll ans=0;
			for(int b=0;b<M;b++)
			{
				ll tot1 = rangeSum(b,L,R);
				if( (tot1&1) )
				{
					// cout<<"b is "<<b<<"\n";
					ans|=(1ll<<b);
				} 
			}
			cout<<ans<<"\n";
		}
	}


	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	
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