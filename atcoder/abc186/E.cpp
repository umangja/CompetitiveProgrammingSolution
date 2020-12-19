/*input
4
10 4 3
1000 11 2
998244353 897581057 595591169
10000 6 14

*/
#include<bits/stdc++.h>
using namespace std;


long long int gcdExtended(long long int a, long long int b, long long int* x, long long int* y); 
  
// Function to find modulo inverse of a 
long long int modInverse(long long int a, long long int m) 
{ 
    long long int x, y; 
    long long int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) return -1;
    else 
    { 
        // m is added to handle negative x 
        long long int res = (x % m + m) % m; 
        return res;
        // printf("Modular multiplicative inverse is %d", res); 
    } 
} 
  
// C function for extended Euclidean Algorithm 
long long int gcdExtended(long long int a, long long int b, long long int* x, long long int* y) 
{ 
    // Base Case 
    if (a == 0)  
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    long long int x1, y1; // To store results of recursive call 
    long long int gcd = gcdExtended(b % a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b / a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
  

int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		long long int N,S,K;cin>>N>>S>>K;
		// (S+x*K)%N==0
		long long int SDup = S;
		S = (-1*S)%N;
		S+=N;
		S%=N;

		long long int g = __gcd(K,N);

		long long int ans = modInverse(K/g,N/g);
		ans = (ans*S)%N;
		ans/=g;

		// cout<<ans<<"\n";

		if((SDup+(ans*K)%N)%N!=0) cout<<-1<<"\n";
		else cout<<ans<<"\n";



	}
	return 0;
}
