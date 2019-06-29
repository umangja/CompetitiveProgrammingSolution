/*input
500
bbababaabaabaabbbbbbaabbabbabbaabababababbbbabaaabbbbaaabbbbbbbabababaaaaabbbbabaababbababbaaaaaabbaaabbaabaaababbbbbabbaabaabaabbbaaabaabbaaabbaabababbaaabaaabaaaaabbbababaabbbbabbbbbababbbaabaabbabaabbabbababbbbbaababbaabbbbbbbbaabbabbbabababaaaaaaaaaabababaaabbaabbbabbabbbbabbbaabaaabbbaabbabbbbbbbaaabbbabaaaaaabaabbbabbbbaaaabbbbbbabaaaaaaabbbbbbabababbaabbbaabaabbbabbbbaaaabbbbbabaaababbababbbabaaabbbbaababaababaaaaabbbaabbababaabaaabaaabbbbbabbbabbaaabbbbbbbaaaaabaaabbabaabbabbbbbbbbabbbab

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )

ll dp[502][502];
int solve()
{
	ll n;cin>>n; 
	string s;cin>>s;
	
	vector< vector< ll > > pos(27,vector< ll > ());
	rep(i,0,n)
	{
		pos[(s[i]-'a')].pb(i);
	}

	// rep(i,0,sz(pos[0]))
	// 	cout<<pos[0][i]<<" ";

	rep(len,1,n+1)
	{
		rep(l,0,n-len+1)
		{
			ll r = l+len-1;
			if(l==r)
				dp[l][r]=1;
			else
			{
				dp[l][r]=dp[l][r-1]+1;
				vector< ll > posi(pos[s[r]-'a']);
				rep(i,0,sz(posi))
				{
					ll j = posi[i];
					if(j>=l && j<r)
					{
						//if(l==4 && r==5)
							// cout<<j<<" "<<dp[l][j]<<" "<<dp[j+1][r-1]<<" "<<r-1<<"ok\n";
						
						dp[l][r]=min(dp[l][r],dp[l][j]+dp[j+1][r-1]);
					}
				}

			}
			// if((l==4 && r==5) || (l==0 && r==0))
			// 	cout<<l<<" "<<r<<" "<<dp[l][r]<<"\n";
		}
	}

	cout<<dp[0][n-1];

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();
}