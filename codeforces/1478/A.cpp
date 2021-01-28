/*input
5
6
1 1 1 2 3 4
5
1 1 2 2 3
4
2 2 2 2
3
1 2 3
1
1

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<int> a(n);
		int ans = 1;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++){
			int j = i;
			while(j<n && a[j]==a[i]) j++;
			ans=max(ans,j-i);
			i=j-1;
		} 

		cout<<ans<<"\n";

	}
	return 0;
}
