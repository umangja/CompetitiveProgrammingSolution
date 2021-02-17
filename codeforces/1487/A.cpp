/*input
3
3
3 2 2
2
5 5
4
1 3 3 7

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		int n;cin>>n;
		map<int,int> cnt;
		for(int i=0;i<n;i++) {
			int x;cin>>x;
			cnt[x]++;
		}
		cout<<n-cnt.begin()->second<<"\n";
	}
	return 0;
}
