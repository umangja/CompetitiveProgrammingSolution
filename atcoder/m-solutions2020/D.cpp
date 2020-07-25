/*input

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;cin>>N;
	vector<long int> price(N+1);
	for(int i=1;i<=N;i++) cin>>price[i];
	long int money = 1000;
	for(int i=1;i<N;i++)
	{
		if(price[i+1]>price[i])
		{
			long int mxBuy = money/price[i];
			money+=mxBuy*(price[i+1]-price[i]);
		}
	}

	cout<<money<<"\n";

	return 0;
}
