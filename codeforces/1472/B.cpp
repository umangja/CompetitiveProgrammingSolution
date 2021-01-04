/*input
5
2
1 1
2
1 2
4
1 2 1 2
3
2 2 2
3
2 1 2

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		int n;cin>>n;
		int cnt[3] = {0};
		int tot=0;
		for(int i=0;i<n;i++)
		{
			int x;cin>>x;
			cnt[x]++;
			tot+=x;
		}	

		int pos=1;
		if(tot%2==1) pos=0;

		if(cnt[2]%2==1 && cnt[1]==0) pos=0;

		cout<<(pos==1?"YES":"NO")<<"\n";
	}
	return 0;
}
