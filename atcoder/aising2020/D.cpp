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


ll fun(string str, ll k)  
{  
  	ll n=sz(str);
    vi pwrTwo(n,0);  
    pwrTwo[0] = 1 % k;  
    for (ll i = 1; i < n; i++)  
    {  
        pwrTwo[i] = pwrTwo[i - 1] * (2 % k);  
        pwrTwo[i] %= k;  
    }  
  
    ll res = 0;  
    ll i = 0, j = n - 1;  
    while (i < n)  
    {  
  
        if (str[j] == '1')  
        {  
            res += (pwrTwo[i]);  
            res %= k;  
        }  
        i++;  
        j--;  
    }  
    return res;  
}  


int solve()
{
	const ll N = 1000000;
	vi f(N,0);
	rep(x,1,N)
	{
		ll n = x;
		ll cnt=0;
		while(n>0)
		{
			ll c = __builtin_popcount((unsigned int)n);
			n = n%c;
			cnt++;
		}
		f[x]=cnt;
	}

	ll n;cin>>n;
	string s;cin>>s;

	ll cnt1=0;
	rep(i,0,n) cnt1+=(s[i]=='1');

	vi p2a(N,1);
	vi p2s(N,1);

	p2a[0] = (1%(cnt1+1));
	rep(i,1,N) p2a[i]=(p2a[i-1]*2)%(cnt1+1);

	if(cnt1-1>0)
	{
		p2s[0] = (1%(cnt1-1));
		rep(i,1,N) p2s[i]=(p2s[i-1]*2)%(cnt1-1);
	} 


	ll preva = fun(s,cnt1+1);
	ll prevs = (cnt1-1>0?fun(s,cnt1-1):0);

	assert(preva>=0);
	assert(prevs>=0);


	rep(i,0,n)
	{
		if(s[i]=='1')
		{	
			if(cnt1-1>0)
			{
				ll m = (prevs - p2s[n-1-i] + (cnt1-1))%(cnt1-1);
				m+=(cnt1-1);
				m%=(cnt1-1);
				if(m>=0) cout<<f[m]+1<<"\n";
				else cout<<inf<<"\n";
			}
			else
			{
				cout<<"0\n";
			}
		}
		else
		{
			ll m = (preva + p2a[n-1-i])%(cnt1+1);
			if(m>=0) cout<<f[m]+1<<"\n";
			else cout<<inf<<"\n";
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