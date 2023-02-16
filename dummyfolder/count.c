#include <stdio.h>

int main()
{
       
    printf("\nEnter size of array:");
    scanf("%d",&size);
    
    int arr[size];
    printf("\nEnter array elements:");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
     
    for(i=0;i<size;++i){
        for(j=0;j<i;j++)
            left+=arr[j];
        for(j=i+1;j<size;j++)
            right+=arr[j];

    	if(left==right)
    		equili=i;
 			
 	}
 	printf("%d\nThe number is ",equili);
	
 
}
