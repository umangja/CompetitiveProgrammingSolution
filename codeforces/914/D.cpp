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

const ll N = 2e6+6;
vi a;
struct node
{
	ll g;
	ll s;

	node(ll gx,ll gs) : g(gx),s(gs) {};
};

vector<struct node> seg(N,node(0,0));
vi lazy(N,0);

struct node combine(node n1,node n2)
{

	node ans(__gcd(n1.g,n2.g),0);
	return ans;
}

void build(ll id,ll s,ll e)
{
	lazy[id]=0;
	if(s==e)
	{
		seg[id] = node(a[s],a[s]); 
		return ;
	}

	ll mid = (s+e)/2;
	build(2*id,s,mid);
	build(2*id+1,mid+1,e);

	seg[id] = combine(seg[2*id],seg[2*id+1]);
}

void modify(ll id,ll s,ll e,ll l,ll r,ll val)
{
	// cout<<id<<" "<<s<<" "<<e<<"\n";
	if(lazy[id]!=0)
	{
		seg[id].s=seg[id].g=lazy[id]; 
		if(s!=e)
		{
			lazy[2*id] = lazy[id];
			lazy[2*id+1] = lazy[id];
		}
		lazy[id]=0;
	}

	if(r<s || l>e) return ;
	if(s>=l && e<=r)
	{
		lazy[id]=val;
		seg[id].s=seg[id].g=lazy[id]; 
		if(s!=e)
		{
			lazy[2*id] = lazy[id];
			lazy[2*id+1] = lazy[id];
		}
		lazy[id]=0;
		return ;
	}

	ll mid = (s+e)/2;
	// whatis(mid);
	modify(2*id,s,mid,l,r,val);
	modify(2*id+1,mid+1,e,l,r,val);

	seg[id] = combine(seg[2*id],seg[2*id+1]);
	return ;

}

ll cnt=0; 
ll seg_id = -1;
ll segl = -1;
ll segr = -1;
ll ans=0;

void checknode(ll id,ll s,ll e,ll x)
{
	if(s==e)
	{
		if(seg[id].g%x!=0) cnt++;
		return ;
	}

	ll mid = (s+e)/2;
	if(seg[2*id].g%x!=0)
	{
		if(seg[2*id+1].g%x!=0)
		{
			cnt+=2;
			return ;
		}
		else
		{
			checknode(2*id,s,mid,x);
			return ;
		}
	}
	else checknode(2*id+1,mid+1,e,x); 
	return ;
}

void query(ll id,ll s,ll e,ll l,ll r,ll x)
{
	if(lazy[id]!=0)
	{
		seg[id].s=seg[id].g=lazy[id]; 
		if(s!=e)
		{
			lazy[2*id] = lazy[id];
			lazy[2*id+1] = lazy[id];
		}
		lazy[id]=0;
	}


	if(r<s || l>e) return ;
	if(s>=l && e<=r)
	{
		if(seg[id].g%x!=0) cnt++,seg_id = id,segl=s,segr=e;
		return;
	} 

	ll mid = (s+e)/2;
	query(2*id,s,mid,l,r,x);
	query(2*id+1,mid+1,e,l,r,x);
	return ;

	// if(n1.g%x!=0) left=1,cnt++;
	// if(n2.g%x!=0) right=1,cnt++;

	// if(cnt>=2) return false;
	// if(cnt==0) return true;
	// return (right==1?checknode(2*id+1,mid+1,e):checknode(2*id,s,mid));


}



int solve()
{
	ll n;cin>>n;
	a.assign(n,0);
	rep(i,0,n) cin>>a[i];

	build(1,0,n-1);
	// cout<<query(1,0,n-1,1,1).g<<"\n";
	// rep(i,0,n) rep(j,i,n) cout<<i+1<<" "<<j+1<<" "<<query(1,0,n-1,i,j).g<<"\n";



	ll q;cin>>q;
	while(q--)
	{
		ll t;cin>>t;
		if(t==1)
		{
			ll l,r,x;cin>>l>>r>>x;
			l--,r--;
			cnt=0;
			ans=0;
			query(1,0,n-1,l,r,x);
			if(cnt==0 ) cout<<"YES\n";
			else if(cnt>=2) cout<<"NO\n";
			else
			{
				cnt=0;
				checknode(seg_id,segl,segr,x);
				if(cnt==1) cout<<"YES\n";
				else cout<<"NO\n";

			} 
		}
		else
		{
			ll pos,y;cin>>pos>>y;
			pos--;
			a[pos]=y;
			modify(1,0,n-1,pos,pos,y);
		}
	}
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