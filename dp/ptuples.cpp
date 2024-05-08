#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	const int Max = 1000000;
	bool isprime[Max+1];
	for(int i=0;i<=Max;i++){
	    isprime[i]=true;
	}
	isprime[0]= false;
	isprime[1]= false;
	for(int i=2;i*i<=Max;i++){
	    if( isprime[i]==true){
	        for(int j=i*i;j<=Max;j+=i){
	            isprime[j]=false;
	        }
	    }
	}
	vector<int> Tuples(Max+1);
	Tuples[0]=Tuples[1]=Tuples[2]=Tuples[3]=0;
	for(int c=4;c<=Max;c++){
	    int b = c-2;
	    Tuples[c]=Tuples[c-1];
	    if(isprime[c]==true && isprime[b]==true){
	        Tuples[c]++;
	    }
	}
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
	    int n;
	    cin>>n;
	    cout<<Tuples[n]<<endl;
	    
	}
	
	return 0;
}