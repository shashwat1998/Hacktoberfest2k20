#include<stdio.h>
#include<math.h>
int isprime(int n);
int main()
{int n;
printf("Enter a no:");
scanf("%d",&n);
if(isprime(n))
printf("prime no");
else
printf("not prime");
return 0;
}
int isprime(int n)
{int i;
for(i=2;i<=sqrt(n);i++)
{if(n%i==0)
{return 0;
}
else
return 1;
}
}
