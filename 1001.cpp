#include <iostream>
#include <math.h>
using namespace std;
int main(void){
	int n1, n2;
	int a, b;
	double r1[1001], r2[1001];
	for(int i = 0; i <= 1000; i ++)
	{
		r1[i] = 0.0;
		r2[i] = 0.0;
	}
	cin>>n1;
	for(int i = 0; i < n1; i ++)
	{
		cin>>a;
		cin>>r1[a];
	}
	cin>>n2;
	for(int i = 0; i < n2; i ++)
	{
		cin>>b;
		cin>>r2[b];
	}
	int c = 0;
	for(int i = 0; i <= 1000; i ++)
	{
		r1[i] += r2[i];
		if(fabs(r1[i] - 0.0) > 0.001)
			c ++;
	}
	cout<<c;
	for(int i = 1000; i >= 0; i --)
	{
		if(fabs(r1[i]-0.0)>0.001)
		{
			printf(" %d %.1lf", i, r1[i]);
		}
	}
	return 0;
}