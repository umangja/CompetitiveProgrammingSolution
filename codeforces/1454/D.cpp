/*input
4
2
360
4999999937
4998207083

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	const int N = 1e5+5;
	vector<int> isPrime(N,1);
	vector<int> primes;

	for(int i=2;i<N;i++)
	{
		if(isPrime[i]==1)
		{
			primes.push_back(i);
			for(long long int j=(long long)i*(long long)i;j<N;j+=i) isPrime[j]=0;
		}
	}



	int T;cin>>T;
	while(T--)
	{
		long long int n;cin>>n;
		int mx=1;
		long long int P=n;
		for(long long int p:primes)
		{
			int cnt = 0;
			long long int dup = n;
			while(dup%p==0)
			{
				cnt++;
				dup/=p;
			}

			if(cnt>mx)
			{
				mx=cnt;
				P =p; 
			}

		}	

		cout<<mx<<"\n";
		for(int i=0;i<mx-1;i++) cout<<P<<" ",n/=P;
		cout<<n<<"\n";	


	}
	return 0;
}
