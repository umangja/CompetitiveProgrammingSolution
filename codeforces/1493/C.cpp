/*input
4
4 2
abcd
3 1
abc
4 3
aaaa
9 3
abaabaaaa

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
ll n,k;
string s;
int solve()
{
	vector<ll> cnt(26,0);
	cin>>n>>k>>s;
	if(n%k!=0){
		cout<<"-1\n";
		return 0;
	}

	ll ok=1;
	rep(i,0,n) cnt[s[i]-'a']++;
	rep(ch,0,26) if(cnt[ch]%k!=0) ok=0;

	if(ok){
		cout<<s<<"\n";
		return 0;
	}

	string r = "-1";
	for(ll i = n-1;i>=0;i--){
		// cout<<"pk\n";
		vi cnt2 = cnt;
		cnt2[s[i]-'a']--;

		for(ll cur = s[i]-'a'+1;cur<26;cur++) {
			ll pos = 1;
			cnt2[cur]++;

			ll left = n-i-1;
			for(int ch=0;ch<26 && pos==1;ch++){
				ll more = ((k - cnt2[ch])%k + k)%k;
				if(left>=more) left-=more;
				else pos=0;
			}

			if(pos==1 && r=="-1" && left%k==0){
				r = "";
				rep(j,0,i) r+=s[j];
				r+=(char)(cur+'a');
				
				ll dup = n-i-1;
				for(int ch=0;ch<26 && pos==1;ch++){
					ll more = ((k - cnt2[ch])%k+k)%k + left;
					dup-=more;
					left=0;
					while(more--) r+=(char)(ch+'a');
				}

				while(dup--) r+='a';


			}
			cnt2[cur]--;	
		}
 
		--cnt[s[i]-'a'];
	}

	cout<<r<<"\n";
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