/*input
4
6
0 2 5 5 4 8
6
2 0 2 1 0 0
9
7 1 3 4 2 10 3 9 6
6
0 1 2 3 4 5

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
		for(int i=0;i<n;i++){
			int a;cin>>a;
			a%=3;
			cnt[a]++;
		}

		int ans = 0;
		int times = 3;
		while(times--){		
			for(int i=0;i<=2;i++){
				if(cnt[i]>n/3){
					int temp=cnt[i]-(n/3);
					ans+=temp;
					cnt[(i+1)%3]+=temp;
					cnt[i]-=temp;
				}
			}
		}

		// cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<"\n";
		cout<<ans<<"\n";

	}
	return 0;
}
