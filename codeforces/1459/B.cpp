/*input
3
*/

// URURURUR
// rurururu

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; // cin>>T;
	while(T--)
	{
		int n;cin>>n;
		int d1 = n/2;
		int d2 = (n+1)/2;

		int UD = ((d1&1)==1? 2*((d1+1)/2) : d1+1);
		int LR = ((d2&1)==1? 2*((d2+1)/2) : d2+1);

		int ans = ((n&1)==1?2:1);
		ans*=UD*LR;
		cout<<ans<<"\n";
	}
	return 0;
}
