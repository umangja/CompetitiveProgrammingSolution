/*input
6
4
4 2 10 1
2
1 3
2
6 1
3
1 4 2
5
1 2 3 4 3
12
4 31 25 50 30 20 34 46 42 16 15 16

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
		for(int i=0;i<n;i++) cin>>a[i];

		int ans = 0;
		for(int i=1;i<n;i++){
			int last = a[i-1];
			while(a[i]>2*last){
				ans++;
				last*=2;
			}
		}

		for(int i=n-2;i>=0;i--){
			int last = a[i+1];
			while(a[i]>2*last){
				ans++;
				last*=2;
			}
		}

		cout<<ans<<"\n";
	}	
	return 0;
}
