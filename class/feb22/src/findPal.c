#include<stdio.h>
#include<string.h>

int main()
{
	char str[20]="abcdMADAMxyz";
	int i,j,k,l;
	int ie,is,flag=0;

	int lenStr=strlen(str);

		for(i=0;i<lenStr;i++)
		{
			for(j=lenStr-1;j>i;j--)
			{
				if(str[i]==str[j])
				{
					if(flag==0){
						is=i;
						ie=j;
					}
					flag=1;
		
 				//	printf("\nis= %c\tj= %c",is,ie);
					for(k=is+1,l=ie-1;(k<ie) && (l>k);k++,l--)
					{
						if(str[k]!=str[l])
						{
							flag=0;
							break;
						}
					}
					if(flag==1)
						break;

			
				}
				else
				{
					flag=0;
					is=0;
					ie=0;
				}
			}
			if(flag==1)
				break;
		}
//	}
	
	printf("\n is= %d \t ie= %d",is,ie);
	for(i=is;i<=ie;i++)
		printf("\n%c",str[i]);

	printf("\n\n");

	return 0;

}



