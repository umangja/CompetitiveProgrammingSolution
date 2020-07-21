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

vector<set<ll>> pos(2);
ll p[2],s[2],v[2];


void init()
{
	pos[0].clear();
	pos[1].clear();
	
	p[0]=0;
	p[1]=1;

	v[0]=0;	
	v[1]=0;

	s[0]=0;
	s[1]=0;

}

void fun(ll k)
{
	rep(i,0,2)
	{
		if(s[i]==0)
		{
			s[i]=1;
			v[i]=k-v[i];
		}
		else
		{
			s[i]=0;
			v[i]=k-v[i];
		}
	}

	swap(p[0],p[1]);

	// cout<<"printing "<<k<<"\n";
	// all(it,pos[p[0]]) cout<<*it<<" ";
	// cout<<"\n";
	// all(it,pos[p[1]]) cout<<*it<<" ";
	// cout<<"\n";

	// rep(i,0,k+1)
	// {
	// 	if(s[i]=='1') s[i]='0';
	// 	else s[i]='1';
	// }
	// reverse(s.begin(), s.begin()+k+1);
	return ;
}


char get(ll id)
{
	ll sid = p[0];
	ll nv = (s[sid]==0?id-v[sid]:v[sid]-id);
	if(pos[sid].find(nv)!=pos[sid].end()) return '0';
	else return '1';
}

void fun2()
{
	if(get(0)=='0')
	{
		pos[p[1]].insert(0);
		pos[p[0]].erase(0);
	}
	else
	{
		pos[p[0]].insert(0);
		pos[p[1]].erase(0);
	}
	return ;
}

int solve()
{
	ll n;cin>>n;
	string st;cin>>st;
	string t;cin>>t;

	init();
	rep(i,0,n) if(st[i]=='0') pos[0].insert(i); else pos[1].insert(i);


	vi ans;
	repr(i,n-1,-1)
	{
		// cout<<get(i)<<"\n";
		if(get(i)==t[i]) continue;
		else
		{
			if(get(0)!=t[i])
			{
				ans.pb(i);
				fun(i);
			}
			else 
			{
				ans.pb(0);
				fun2();

				ans.pb(i);
				fun(i);
			}
		}
	}

	// rep(i,0,n)
	// {
	// 	if(get(i)!=t[i])
	// 	{
	// 		cout<<"NO ok\n";
	// 		cout<<i<<"\n";
	// 	} 

	// } 

	// assert(s==t && sz(ans)<=2*n);

	cout<<sz(ans)<<" ";
	rep(i,0,sz(ans)) cout<<ans[i]+1<<" ";
	cout<<"\n";




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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}