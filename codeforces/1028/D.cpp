#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,ans=1,res=1,x,mn=0,mx=1e9;
set<int>S;
set<int>::iterator it;
char s[10];
int main(){
	scanf("%d",&n);
	S.insert(1e9),S.insert(0);
	for(int i=1;i<=n;++i){
		scanf("%s%d",s,&x);
		if(s[1]=='D')S.insert(x),res+=(x>=mn&&x<=mx)?1:0;
		else{
			if(x<mn||x>mx)ans=0;
			if(x!=mn&&x!=mx)ans=2*ans%mod;
			S.erase(x);res=1;
			it=S.lower_bound(x); 
			mx=*it;
			mn=*(--it);
		}
	}
	printf("%d\n",1ll*ans*res%mod);
}