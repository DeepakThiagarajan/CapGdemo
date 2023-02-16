#include "myheader.h"

int sum(int n)
{
	int i, prime=1;

	for(i=2;i<n;++i){
		if(n%i==0){
			prime=0;
			break;
		}
	}
	return prime;
		
}