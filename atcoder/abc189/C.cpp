/*input
6
2 4 4 9 4 9

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; // cin>>T;
	while(T--)
	{
		int N;cin>>N;
		vector<int> A(N);
		for(int i=0;i<N;i++) cin>>A[i];

		int ans = A[0];
		for(int i=0;i<N;i++){
			int cur = A[i];
			ans=max(ans,cur);
			for(int j=i+1;j<N;j++)
			{
				cur=min(cur,A[j]);
				ans=max(ans,cur*(j-i+1));
			} 
		} 
		cout<<ans<<"\n";

	}
	return 0;
}
