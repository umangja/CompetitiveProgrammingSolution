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



const int NN = 1e6+5;
int SPF[NN];

void init()
{
	SPF[1]=1;
	for(int i=2;i<NN;i++)
	{
		if(SPF[i]==0)
		{
			SPF[i] = i;
			for(long long int j = (long long int)i*i;j<NN;j+=(long long int)i) if(SPF[j]==0) SPF[j]=i;
		}
	}
}

int findPrimeFactors(int x)
{
	int ans = 1;
	while(x>1)
	{
		int  p = SPF[x];
		int cnt = 0;
		while(x%p==0) x/=p,cnt++;
		if((cnt&1)) ans*=p;
	}
	return ans;
}

int solve()
{
	int TC = 1; 
	cin>>TC;

	init();

	while(TC--)
	{
		int N;cin>>N;

		// N = 3e5;

		vector<int> a(N);
		for(int i=0;i<N;i++) cin>>a[i];
		// for(int i=0;i<N;i++) a[i] = i+2;


		for(int i=0;i<N;i++) a[i] = findPrimeFactors(a[i]);
		sort(a.begin(), a.end());

		int ansForw0 = 0;
		unordered_map<int,int> cnt;
		for(int i=0;i<N;i++)
		{
			int j = i+1;
			while(j<N && a[j]==a[i]) j++;
			ansForw0 = max(ansForw0,j-i);
			cnt[a[i]] = j-i;
			i = j-1;
		} 

		int ansForw1 = 0;
		int cnt1 = cnt[1];
		for(auto it : cnt) if(it.first>1 && (it.second%2==0)) cnt1+=it.second;

		ansForw1 = max(ansForw0,cnt1);


		int Q;cin>>Q;
		for(int i=0;i<Q;i++)
		{
			long long int x;cin>>x;
			if(x==0) cout<<ansForw0<<"\n";
			else cout<<ansForw1<<"\n";
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
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}