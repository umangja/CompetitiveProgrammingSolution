/*input
7
1
2
4
34
35
16
703657519796

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N  = 1e4+1;
ll fun(ll a){
	ll low = 1, high = N;
	while(low<high){
		ll mid = low + (high-low+1)/2;
		if(mid*mid*mid == a) return 1;
		else if( mid*mid*mid < a) low = mid+1;
		else high = mid-1; 
	}
	if(low*low*low == a) return 1;
	return 0;
}
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		ll x;cin>>x;
		ll pos=0;
		for(ll a = 1;a<=N;a++){
			ll b = x - a*a*a;
			if(fun(b)) pos=1;
		}
		cout<<(pos==1?"YES\n":"NO\n");

	}
	return 0;
}
