/*input
100 999

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; // cin>>T;
	while(T--)
	{
		int A,B;cin>>A>>B;
		int s1=0,s2=0;
		while(A>0)
		{
			s1+=A%10;
			A/=10;
		}

		while(B>0)
		{
			s2+=B%10;
			B/=10;
		}

		cout<<max(s1,s2)<<"\n";

	}
	return 0;
}
