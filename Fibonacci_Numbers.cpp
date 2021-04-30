#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
void mult(long long a[][2],long	long b[][2]){
	long long res[2][2]={0,0,0,0};
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				res[i][j] = (res[i][j] + (a[i][k]*b[k][j])%M)%M;
			}
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			a[i][j] = res[i][j];
		}
	}
}
long long fib(long long n){
	long long a[2][2] = {1,1,1,0} , b[2][2] = {1,0,0,1};
	while(n){
		if(n&1)
			mult(b,a);
		mult(a,a);
		n>>=1;
	}
	return b[1][0];
}
int main(){
	long long n;
	cin>>n;
	cout<<fib(n);
	return 0;
} 