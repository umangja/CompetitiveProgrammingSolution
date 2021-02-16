/*input
2
4
1 2 4 3
5
1 1 1 1 1

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		ll n;cin>>n;
		vector<pair<ll,ll>> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i].F;
			a[i].S = i;

		} 
		sort(a.begin(), a.end());

		vector<ll> sum(n,a[0].F);
		for(int i=1;i<n;i++) sum[i]=sum[i-1]+a[i].F;

		int st = n-1;
		for(int i=n-2;i>=0;i--){
			if(sum[i]>=a[i+1].F){
				st=i;
				continue;
			} 
			else {
				st = i+1;
				break;
			}
		}

		set<ll> s;
		for(int i=st; i<n;i++) s.insert(a[i].S);
		cout<<(int)s.size()<<"\n";
		for(auto x : s) cout<<x+1<<" ";
		cout<<"\n";
	}
	return 0;
}
