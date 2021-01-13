
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<string.h>

#define SIZE 10

int n;
void *choice_zero(void *c);
void *choice_one(void *c);
void *length(void *c);

int main(int argc,char *argv [])
{
	char s[SIZE],b[SIZE];
	int a;
	pthread_t thread1,thread2,thread3;
	if (argc<2)
	{printf("enter the format ./'name',stringFFF,choice'1 or 0'");}
	strcpy(s,argv[1]);
	strcpy(b,s);
	a=atoi(argv[2]);
	if (a==0)
	{
		pthread_create(&thread1,NULL,choice_zero,&b);
		pthread_join(thread1,NULL);
	}
	else if(a==1)
	{
		pthread_create(&thread2,NULL,choice_one,&b);
		pthread_join(thread2,NULL);
	}
	else
	{
		return 1;
	}
	pthread_create(&thread3,NULL,length,&b);
	pthread_join(thread3,NULL);
	return 0;
}

void *choice_one(void *c)
{
	char p[SIZE]="SIOSFFF";
	char *d=(char *)c;
	//printf("the coming string to 1 is %s\n",b);

		if (strcmp(d,p)==0)
		{printf("the value is matching with SIOS\n");}
		else{
		printf("the  string is not matching with SIOS\n");
		//printf("the string count is %d\n",(strlen(d)-3);}
}
		
}
	
void *choice_zero(void *c)
{
		char r[SIZE]="MCISFFF";
		char *d=(char *)c;
		if (strcmp(d,r)==0)
		{printf("the value is matching with MCIS\n");}
		else{
		printf("the  string is not matching with MCIS\n");
		//printf("the string count is %d\n",(strlen(*d)-3);}
		}
}	
		
void *length(void *c)
{
	char *e=(char*)c;
	int n=0;
	n=strlen(e);
	printf("the length of string is %d\n",(n-3));
}