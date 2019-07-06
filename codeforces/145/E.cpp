/*input
3 5
747
count
switch 1 1
count
switch 1 3
count


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
const ll N= 1e6+6;
string s;
ll n,d[N],h;
struct node{
	ll c4,c7,c47,c74;
	node(ll a=0,ll b=0,ll c=0,ll d1=0){c4=a;c7=b;c47=c;c74=d1;}
};

struct node t[2*N];
struct node combine(struct node a1,struct node a2){
	struct node ans;
	ans.c4 = a1.c4+a2.c4;
	ans.c7 = a1.c7+a2.c7;
	ans.c47= max(max(max(ans.c4,ans.c7),max(a1.c4+a2.c7,a1.c4+a2.c47)),a1.c47+a2.c7);
	ans.c74= max(max(max(ans.c4,ans.c7),max(a1.c7+a2.c4,a1.c7+a2.c74)),a1.c74+a2.c4);
	return ans;

}

void apply(ll p,ll f=0){
	swap(t[p].c47,t[p].c74);swap(t[p].c4,t[p].c7);
	if(f==0 && p<n) d[p]=1-d[p];
}

void build(ll p){
	for(;p>>=1;) {t[p]=combine(t[p<<1],t[p<<1|1]);if(d[p]) apply(p,1);}
}

void build_init(){
	struct node ans;ll el;
	rep(i,0,n) {
		el=s[i]-'0';
		ans.c4=(el==4?1:0);
		ans.c7=1-ans.c4,ans.c47=ans.c74=1,t[i+n]=ans;
	}
	for(ll i=n-1;i>=1;i--) t[i]=combine(t[i<<1],t[i<<1|1]);//,cout<<t[i].c47<<" "<<i<<"s\n";
}
void push(ll p){
	for(ll s1=h;s1>0;s1--)
	{
		ll i = p>>s1;
		if(d[i]!=0)
		{
			apply(i<<1,0);
			apply(i<<1|1,0);
			d[i]=0;
		}
	}
}

void modify(ll l,ll r){
	ll l0=l+n,r0=r+n;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1) apply(l++,0);
		if(r&1) apply(--r,0);
	}
	// cout<<t[1].c4<<" "<<t[1].c7<<" "<<t[1].c47<<" "<<t[1].c74<<"\n";
	build(l0);build(r0-1);
}

struct node query(ll l,ll r)
{
	ll l0=l,r0=r;
	struct node ans1,ans2;
	push(l0+n);push(r0+n-1);
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1) ans1=combine(ans1,t[l++]);
		if(r&1) ans2=combine(t[--r],ans2);
	}

	return combine(ans1,ans2);
}


int solve()
{
	ll m;
	cin>>n>>m>>s;
	h=(ll)ceil(log2(n));
	build_init();
	while(m--)
	{
		char r1[7];
		string temp = "switch";
		scanf("%s",r1);
		if(r1==temp){
			ll l,r;scanf("%lld %lld",&l,&r);l--;modify(l,r);
		}
		else{
			cout<<query(0,n).c47<<"\n";
		}
	}	
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}