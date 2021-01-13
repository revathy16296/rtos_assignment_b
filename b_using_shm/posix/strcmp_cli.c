#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	const int SIZE =4096;
	const char* name ="os";
	int key,n;
	void* shmptr;
	key=shm_open(name,O_CREAT|O_RDWR,0666);
	  if (key < 0) {
          printf("*** shmget error (server) ***\n");
          exit(1);
     }
	 ftruncate(key,SIZE);
	shmptr=mmap(0,SIZE,PROT_WRITE,MAP_SHARED,key,0);
	shmptr=mmap(0,SIZE,PROT_WRITE,MAP_SHARED,key,0);
	printf("the length of string is \n");
	puts(shmptr);
	shm_unlink(name);
	return 0;
}