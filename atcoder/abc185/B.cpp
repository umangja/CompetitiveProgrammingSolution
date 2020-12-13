/*input
20 1 30
1 10



*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,M,T;cin>>N>>M>>T;
	int last = 0;
	int pos=1;
	int mx = N;
	for(int i=0;i<M;i++)
	{
		int A,B;cin>>A>>B;
		int dec = A-last;

		N-=dec;
		if(N<=0) pos=0;
		else N+=(B-A);

		N = min(mx,N);

		last = B;
	}

	int dec = T-last;


	N-=dec;
	if(N<=0) pos=0;

	cout<<(pos?"Yes":"No");

	return 0;
}
