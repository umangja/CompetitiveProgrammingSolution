/*input
5 2
aaaaa
aa


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
// hard to go greedy 
// try dp


int solve()
{
	ll n,m;cin>>n>>m;
	string s,t;cin>>s>>t;

	vvi pos(26, vi ());
	rep(i,0,n) pos[s[i]-'a'].pb(i);

	vi done(26,0);
	vvi R(26,vi (m,0));

	rep(ch,0,26){
		repr(i,m-1,-1){
			if(t[i]-'a'==ch) R[ch][i]++;
			R[ch][i] += (i+1<m?R[ch][i+1]:0);
		}
	}

	// debug_v_v(R);

	vi R2(m,0);

	ll tt = inf;
	repr(i,m-1,-1){
		ll c1 = t[i]-'a';
		ll R1 = sz(pos[c1]) - R[c1][i];
		ll temp = lower_bound(pos[c1].begin(), pos[c1].end(),tt) - pos[c1].begin()-1;
		if(!(temp>=0 && temp<sz(pos[c1]))){
			cout<<"Error\n";
			break;
		}
		R2[i] = pos[c1][min(temp,R1)];
// 		cout<<i+1<<" "<<R2[i]+1<<"\n";
		tt = min(tt,R2[i]);

	}

	ll mx = -1;	
	ll mn = -inf;
	rep(i,0,m-1){
		ll c1 = t[i]-'a';
		ll L1 = done[c1];
		ll temp1 = upper_bound(pos[c1].begin(), pos[c1].end(),mn) - pos[c1].begin();
		if(!(temp1>=0 && temp1<sz(pos[c1]))){
			cout<<"Error\n";
			break;
		}
		ll mnPos = pos[c1][max(temp1,L1)];
		ll mxPos = R2[i+1];
// 		cout<<i+1<<" "<<mnPos+1<<" "<<mxPos+1<<"\n";
		mx = max(mx,mxPos-mnPos);
		mn = mnPos;
		done[c1]++;
	}

	cout<<mx<<"\n";


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