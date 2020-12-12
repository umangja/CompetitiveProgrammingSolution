/*input
3
7
4 6 11 11 15 18 20
4
10 10 10 11
3
1 1 1000000000

*/
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<pair<long long int,int>> a(n);
		for(int i=0;i<n;i++) cin>>a[i].F,a[i].S=i+1;
		sort(a.begin(), a.end());

		if(a[0].F+a[1].F<=a[n-1].F)
		{
			vector<int> temp;
			temp.push_back(a[0].S);
			temp.push_back(a[1].S);
			temp.push_back(a[n-1].S);
			sort(temp.begin(), temp.end());
			cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<"\n";
		}
		else cout<<"-1\n";


	}
	return 0;
}
