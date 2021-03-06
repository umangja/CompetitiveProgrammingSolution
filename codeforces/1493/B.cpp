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

map<string,string> re;
ll H,M;

void init(){
	re["0"] = "0";
	re["1"] = "1";
	re["2"] = "5";
	re["3"] = "-1";
	re["4"] = "-1";
	re["5"] = "2";
	re["6"] = "-1";
	re["7"] = "-1";
	re["8"] = "8";
	re["9"] = "-1";
}

string numToString(ll x){
	if(x>=10) return to_string(x);
	else return "0"+to_string(x);
}

string fun(ll h,ll m){
	string temp = numToString(h) + ":" + numToString(m);
	string ans = "";
	ll pos=1;
	repr(i,4,-1){
		if(temp[i]==':') ans+=":";
		else{
			string tt = "";
			tt+=temp[i];
			if(re[tt]=="-1") pos=0;
			else ans += re[tt][0];
		}
	} 

	if(pos==0) return "-1";
	string n = "";
	n+=ans[0];
	n+=ans[1];
	h = stoi(n);
	n="";
	n+=ans[3];
	n+=ans[4];
	m = stoi(n);

	if(h<H && m<M) return temp;
	else return "-1";

}

int solve()
{
	cin>>H>>M;
	string last = "00:00";
	map<string,string> ans;

	for(ll h = H-1;h>=0;h--){
		for(ll m = M-1;m>=0;m--){
			string s = numToString(h)+":"+numToString(m);
			string temp = fun(h,m);
			if(temp=="-1") ans[s] = last;
			else ans[s] = last = temp;
		}
	}

	string s;cin>>s;
	cout<<ans[s]<<"\n";

	return 0;
}

int main()
{
	init();
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