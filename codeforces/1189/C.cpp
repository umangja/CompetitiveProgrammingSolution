/*input
6
0 1 2 3 3 5
3
1 2
1 4
3 6

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
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 1e5+5;
ll n;
vi a(N);

struct node{
	ll a,c;
};

struct node t[2*N];


struct node combine(struct node a1,struct node b1)
{
	struct node ans;
	ans.a = a1.a+b1.a;
	ans.c = a1.c+b1.c;
	if(ans.a>=10)
	{
		ans.a-=10;
		ans.c++;
	}
	return ans;
}
void build(){
	struct node ans;
	rep(i,0,n) ans.a=a[i],ans.c=0,t[i+n]=ans;
	for(ll i=n-1;i>0;i--) t[i]=combine(t[2*i],t[2*i+1]);
}

struct node query(ll l,ll r){
	struct node ans1,ans2;ans1.a=ans2.a=0;ans1.c=ans2.c=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1) 
	{
		if(l&1) ans1=combine(ans1,t[l++]);
		if(r&1) ans2=combine(t[--r],ans2);
	}
	return combine(ans1,ans2);
}

int solve()
{
	cin>>n;
	rep(i,0,n)
		cin>>a[i];
	ll q;cin>>q;
	build();
	while(q--)
	{
		ll l,r;cin>>l>>r;
		cout<<query(--l,r).c<<"\n";
	}
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
// 	cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}