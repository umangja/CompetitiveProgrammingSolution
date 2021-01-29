/*input
4
1 5
4 3
8 8
8 17

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		ll n,k;cin>>n>>k;
		ll ans = (k+n-1)/n;

		if(ans==1){
			if(n%k!=0) ans++; 
		} 

		cout<<ans<<"\n";

	}
	return 0;
}
