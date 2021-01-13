#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

struct tele
{
	char name[15],sir_name[15],number[15];
};
int main()
{
	FILE *fp;
	struct tele *shmptr;
	int shmid;
	struct tele temp;
	int choice,limit,beg=0,i,j,c,count=0,pid;
	shmid=shmget(IPC_PRIVATE,10*sizeof(struct tele),IPC_CREAT|0666);
	shmptr=(struct tele*)shmat(shmid,NULL,0);
	while(1)
	{
		printf("\ntelephone directory\n");
		printf("1.add\n");
		printf("2.display\n");
		printf("3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			fp=fopen("details.txt","w+");
				printf("enter the number of customers\n");
				scanf("%d",&limit);
				for(i=beg;i<limit+beg;i++)
				{
					printf("enter the name of customer no %d:\t",i+1);
					scanf("%s",shmptr[i].name);
					printf("enter the sir name:\t");
					scanf("%s",shmptr[i].sir_name);
					printf("enter the phone number\t");
					scanf("%s",shmptr[i].number);
				}
				beg=limit+beg;
				for(i=0;i<beg;i++)
				{
					for(j=0;j<beg-1;j++)
					{
						c=strcmp(shmptr[j].name,shmptr[j+1].name);
						if(c>0)
						{
							temp=shmptr[j];
							shmptr[j]=shmptr[j+1];
							shmptr[j+1]=temp;
					}}
				}
				fclose(fp);
				
				break;
			case 2:
			pid=fork();
			/*if(pid>0)
			{
				wait(NULL);
			}*/
		    if(pid==0)
			{
				printf("entered in to the child  process!\n");
			FILE *fp;
			
				printf("\ncustomer details\n");
				fp=fopen("details.txt","r");
				if(fp==NULL)
				{
					printf("error!");
					exit(1);
				}
				
				for (i=0;i<beg;i++)
				{
					fread(&shmptr,sizeof(struct tele),1,fp);
					printf("(%d) %s %s\t :%s\n",i+1,shmptr[i].name,shmptr[i].sir_name,shmptr[i].number);
				}
				fclose(fp);
			}
			else
			{
			wait(NULL);
			//exit(0);
			shmdt((void*)shmptr);
			printf("the memory detached and program exiting.......\n");
			shmctl(shmid,IPC_RMID,NULL);
			exit (0);
			}break;
			
			case 3:
			exit(0);
		}
	}
	return 0;
}
	


	