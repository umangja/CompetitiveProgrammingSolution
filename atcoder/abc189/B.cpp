/*input
2 10
200 5
350 3


*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; 
	while(T--)
	{
		int N,X;cin>>N>>X;
		int ans = -1;
		int cur = 0;
		for(int i=0;i<N;i++)
		{
			int v,p;cin>>v>>p;
			cur+=p*v;
			if(cur>X*100 && ans==-1){
				ans = i+1;
			}
		}

		cout<<ans<<"\n";
	}
	return 0;
}
