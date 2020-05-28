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
#define pii         pair<double,double >
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

const double EPS = 1e-9;
double a,b,c;
pair<double,double> st,fi;

// ax+by+c=0
ll check(pii p)
{
	return abs(p.F*a+b*p.S+c)<=EPS;
}

pair<double,double> get_on_line(pii p,ll h )
{
	if(h)
	{
		if(abs(a)>EPS) return mp((-1*b*p.S-c)/a,p.S);
		else return mp(0.0,p.S);
	} 
	else
	{
		if(abs(b)>EPS) return mp(p.F,(-1*a*p.F-c)/b);
		else return mp(p.F,0.0);
	} 
}



double dist(pii p1,pii p2,ll m=0)
{
	double dx = p1.F-p2.F;
	double dy = p1.S-p2.S;
	if(m) return abs(dx)+abs(dy);
	return sqrt(dx*dx+dy*dy);
}

int solve()
{
	cin>>a>>b>>c;
	cin>>st.F>>st.S>>fi.F>>fi.S;

	if(a==0 || b==0)
	{
		cout<<setprecision(20)<<dist(st,fi,1)<<"\n";
		return 0;
	}

	double ans = dist(get_on_line(st,0),get_on_line(fi,0)) + dist(st,get_on_line(st,0),1) + dist(fi,get_on_line(fi,0),1);
	ans=min(ans,dist(get_on_line(st,1),get_on_line(fi,1))  + dist(st,get_on_line(st,1),1) + dist(fi,get_on_line(fi,1),1));
	ans=min(ans,dist(get_on_line(st,1),get_on_line(fi,0))  + dist(st,get_on_line(st,1),1) + dist(fi,get_on_line(fi,0),1));
	ans=min(ans,dist(get_on_line(st,0),get_on_line(fi,1))  + dist(st,get_on_line(st,0),1) + dist(fi,get_on_line(fi,1),1));
	ans=min(ans,abs(st.F-fi.F)+abs(fi.S-st.S));

	cout<<setprecision(20)<<ans;
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