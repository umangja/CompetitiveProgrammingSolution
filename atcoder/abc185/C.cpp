/*input
17

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int  N;cin>>N; N--;
	long long int ans=1;
	for(long long int i=0;i<11;i++)
	{ 	
		ans = (ans*(N-i))/(i+1);
	}
	cout<<ans<<"\n";
	return 0;
}
