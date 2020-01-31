/*input

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
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct seg
{
	ll x1,y1,x2,y2;

	seg() {};

	seg(ll x,ll y,ll xx,ll yy) 
	{
		x1 = x;
		y1 = y;
		x2 = xx;
		y2 = yy;
	}

};

ll same_side(seg s1,seg s2)
{
	ll d1 = (s2.y2 - s2.y1)*(s1.x1 - s2.x1) -  (s2.x2 - s2.x1)*(s1.y1-s2.y1);
	ll d2 = (s2.y2 - s2.y1)*(s1.x2 - s2.x1) -  (s2.x2 - s2.x1)*(s1.y2-s2.y1);
	
	return ((d1>0 && d2>0) || (d1<0 && d2<0));

}

pair<ll,pii> intersec(seg s1,seg s2)
{
	ll f = (( same_side(s1,s2) || same_side(s2,s1) ));

	if(f==1) return mp(0,mp(-1,-1));

	ll a1 = s1.y2-s1.y1;
	ll b1 = s1.x1-s1.x2;
	ll c1 = s1.y1*(s1.x2-s1.x1) - s1.x1*(s1.y2-s1.y1);

	ll a2 = s2.y2-s2.y1;
	ll b2 = s2.x1-s2.x2;
	ll c2 = s2.y1*(s2.x2-s2.x1) - s2.x1*(s2.y2-s2.y1);

	f = ((((c1*a2 - c2*a1)%(b1*a2 - b2*a1))==0) && (((c1*b2 - c2*b1)%(a1*b2 - a2*b1))==0));
	if(f==0) return mp(0,mp(-1,-1));
	else
	{
		ll y = -1 * ((c1*a2 - c2*a1)/(b1*a2 - b2*a1));
		ll x = -1 * ((c1*b2 - c2*b1)/(a1*b2 - a2*b1));
		
		return mp(1,mp(x,y));

	}


}

ll pnts(seg s)
{
	ll n = abs(s.y2-s.y1);
	ll m = abs(s.x2-s.x1);
	ll g = __gcd(n,m);
	return g+1;
}

int solve()
{
	ll n;cin>>n;
	vector<  seg > a(n);
	rep(i,0,n)
	{
		ll x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		a[i] = seg(x1,y1,x2,y2);
	}

	ll cnt=0;
	// set<pii> st;
	rep(i,0,n) 
	{
		set<pii> temp;
		rep(j,i+1,n)
		{
			pair<ll,pii> p  = intersec(a[i],a[j]);
			if(p.F==1)
			{
				// cout<<j<<" ";
				temp.insert(p.S);
			} 
		}

		// cout<<sz(temp)<<"\n";

		cnt-=sz(temp);

	}
	// whatis(cnt);
	rep(i,0,n) cnt+=pnts(a[i]);
	cout<<cnt<<"\n";
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
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}