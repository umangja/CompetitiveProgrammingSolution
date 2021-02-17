/*input
7
2 1
2 2
3 1
3 2
3 3
5 5
69 1337

*/
#include<bits/stdc++.h>
using namespace std;


// _ _ A B _  ----> 2 

// A B _ _ _  ----> 4



int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
	
		if(n%2==0){
			cout<<((k-1)%n)+1<<"\n";
		}
		else{

			// will collide after n/2 hours
			int gap = n/2;
			int numberOfCollisions =( k-1 ) / gap;

			k = k - 1 + numberOfCollisions;
			cout<< k%n + 1<<"\n";

		}

	}
	return 0;
}
