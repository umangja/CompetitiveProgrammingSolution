/*input
3

4 4
2 3
1 2
2 2
1 1


6 3
2 1
1 3
2 5


3 2
2 1
2 3

6 4
2 1
2 3
2 4
2 6

*/
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		int n,m;cin>>n>>m;
		int pos=1;
		vector<pair<int,int>> a(m);
		map<int,int> cnt;
		for(int i=0;i<m;i++) cin>>a[i].S>>a[i].F,cnt[a[i].F]++;	
		sort(a.begin(), a.end());
		for(int i=0;i<m && pos==1;i++)
		{
			if(i<m && cnt[a[i].F]==2) i++;
			else if(i>=m-1) pos=0;
			else
			{
				int j = i+1;
				if(j<m && cnt[a[j].F]==2)  pos=0;
				int d = a[j].F - a[i].F;
				if(abs(a[i].S-a[j].S)==(d%2)) pos=0;
				i=j;
			}

		}

		cout<<(pos==1?"YES":"NO")<<"\n";

	}
	return 0;
}
