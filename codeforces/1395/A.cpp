/*input

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		vector<long int> a(4);
		long int tot=0;
		long int o=0,e=0;
		for(int i=0;i<4;i++)
		{
			cin>>a[i];
			tot+=a[i];

			if(a[i]&1) o++;
			else if(a[i]!=0)  e++;
		}

		if(o<=1)
		{
			cout<<"Yes\n";
			continue;
		}
		else
		{
			long int op = min({a[0],a[1],a[2]});
			if(op==0)
			{
				cout<<"No\n";
				continue;
			}
			else
			{
				a[0]-=1;
				a[1]-=1;
				a[2]-=1;
				a[3]+=3*1;

				o=0,e=0;

				for(int i=0;i<4;i++)
				{
					if(a[i]&1) o++;
					else if(a[i]!=0)  e++;
				}

				if(o<=1)cout<<"Yes\n";
				else cout<<"No\n";
			}

		}




	}
	return 0;
}
