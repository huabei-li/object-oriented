#include<stdio.h>
#include<math.h>
int main()
{
  int a,b,sum,temp,m,k,left;
  scanf("%d %d",&a,&b);
  sum=a+b;
  temp=abs(sum);
  if(temp>=1000000) 
  {
  	m=temp/1000000;
  	k=temp/1000%1000;
  	left=temp%1000;
  	if(sum>0) printf("%d,%03d,%03d",m,k,left);
  	else printf("%d,%03d,%03d",-m,k,left);
  }
  else if(temp>=1000)
  {
  	k=temp/1000;
  	left=temp%1000;
	if(sum>0) printf("%d,%03d",k,left);
	else printf("%d,%03d",-k,left);
  }
  else printf("%d",sum);
  return 0;
}
