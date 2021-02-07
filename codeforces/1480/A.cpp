/*input 
10
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	int T = 1; cin>>T;
	while(T--){
		string s;cin>>s;
		for(int i=0;i<(int)s.size();i++) {
			if(i%2==0) {
				if(s[i]=='a') s[i]='b';
				else s[i]='a';
			}
			else {
				if(s[i]=='z') s[i]='y';
				else s[i]='z';
			}
		} 
		cout<<s<<"\n";
	}
}