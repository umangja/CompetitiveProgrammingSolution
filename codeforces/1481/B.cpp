/*input
5
20 645651756
11 21 31 41 51 56 60 70 80 90 98 98 99 99 100 100 100 100 100 100
20 465601593
11 21 31 41 51 61 65 66 76 83 87 92 100 100 100 100 100 100 100 100
20 479141829
11 17 27 37 47 57 63 73 83 93 99 100 100 100 100 100 100 100 100 100
20 967667371
81 33 1 88 69 83 1 98 30 54 1 97 11 11 63 96 63 60 91 31
20 64564761
17 6 1 87 35 20 75 73 16 91 16 17 69 78 3 4 56 83 53 49

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 101,K = 10000+5;

int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		ll n,k;cin>>n>>k;
		vector<int> h(n+1);
		for(int i=0;i<n;i++) cin>>h[i];
		h[n] = -1;

		if(k>=K) {
			cout<<"-1\n";
			continue;
		}

		for(int j=1;j<=k;j++){
			ll i = 0;
			while(i<n){
				if(h[i]>=h[i+1]) i++;
				else {
					h[i]++;
					break;
				}
			}


			if(j==k){
				if(i==n) cout<<"-1\n";
				else cout<<i+1<<"\n";
			}
		}



	}
	return 0;
}
