/*input
())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10

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
ll N=1e6+6;
string s;
ll n;
vector< struct node > t(2*N+6);


struct node
{	
	ll a,b,c;
	node(ll at=0,ll bt=0,ll ct=0){
		a=at;
		b=bt;
		c=ct;
	}
};

struct node combine(struct node a1,struct node a2){
	ll tt=min(a1.c,a2.b);
	struct node ans;
	ans.a=a1.a+a2.a+tt;
	ans.b=a1.b+a2.b-tt;
	ans.c=a1.c+a2.c-tt;
	return ans;
}


void build(){
	for(ll i=n-1;i>=1;i--) t[i] = combine(t[2*i],t[2*i+1]); 
}

struct node query(ll l,ll r){
	struct node ans1,ans2;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1) ans1=combine(ans1,t[l++]);
		if(r&1) ans2=combine(t[--r],ans2);
	}
	return combine(ans1,ans2);
}


int solve()
{
	cin>>s;n=sz(s);
	struct node temp;
	rep(i,0,n)
	{
		if(s[i]=='(') temp.a=0,temp.b=0,temp.c=1;
		else temp.a=0,temp.b=1,temp.c=0;
		t[i+n]=temp;
	}
	build();
	ll q;cin>>q;
	while(q--)
	{
		ll l,r;cin>>l>>r;
		cout<<2*query(l-1,r).a<<"\n";
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
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}