/*input
2
1
2




*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
vector<int> Primes(N,1);
vector<int> st;
int main()
{
	int T = 1; cin>>T;

	for(int i=2;i<N;i++)
	{
		if(Primes[i]){
			st.push_back(i);
			for(long long int j = (long long int)(i)*(long long int)(i);j<N;j+=i) Primes[j]=0;
		}
	}


	while(T--)
	{
		int d;cin>>d;

		int p1 = st[lower_bound(st.begin(), st.end(),d+1) - st.begin()];
		int p2 = st[lower_bound(st.begin(), st.end(),p1+d) - st.begin()];




		cout<<p1*p2<<"\n";

	}	
	return 0;
}
