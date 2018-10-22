// With out synchronization
/*
Goal is to develop a pin tool, that detect shared data. 

*/


#include <pthread.h>
#include <stdio.h>

#define THREADS 10
 int count=1; // shared data.

static void *ThreadCode(void* arg){
	count+=1;
	int threadId=(int) arg;
	printf("Thread ID: %d, count = %d : address : %p \n",threadId,count,&count);

}




int main(){

pthread_t tid[THREADS];
int i;
for(i=0;i<THREADS;i++)
{
	pthread_create(tid+i,NULL,ThreadCode,(void *)i);

}

	printf("Last Value %d",count);

pthread_exit(NULL);


}
