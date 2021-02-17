/*input
3
3
6
9

*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int main()
{
	int T = 1;  cin>>T;

	vector<long long int> valueC;

	for(long long int a = 3;a<N;a+=2){
		long long int c = (a*a-1)/2+1;
		valueC.push_back(c);
	}

	while(T--)
	{
		long long int n;cin>>n;
		cout<< upper_bound(valueC.begin(), valueC.end(),n) - valueC.begin()<<"\n"; 
	}
	return 0;
}
