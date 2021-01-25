/*input
5
1
4041
4042
8081
8079

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

	const int N = 1e6+1;
	vector<int> pos(N,0);

	pos[0] = 1;
	for(int i=0;i<N;i++) 
	{
		if(i-2020>=0) pos[i]|=pos[i-2020];
		if(i-2021>=0) pos[i]|=pos[i-2021];
	}


	int T = 1; 
	cin>>T;
	while(T--)
	{
		int x;cin>>x;
		cout<<(pos[x]?"YES":"NO")<<"\n";
	}
	return 0;
}
