#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t mutex; 

void* thread(void *num) { 

	int *t = (int *) num;
	int tid = *t;

	//wait 
	sem_wait(&mutex); 
	printf("\nthread %d entrou\n",tid ); 

	//critical section 
	sleep(1); 
	
	//signal 
	printf("\nthread %d saiu\n",tid); 
	sem_post(&mutex); 
} 


int main() { 
	int i=0;
	pthread_t t1,t2; 
	
	sem_init(&mutex, 0, 1); 
	
	while(1){
		i=0;
		pthread_create(&t1,NULL,thread,&i); 
	
		sleep(2); 
		i=1;
	
		pthread_create(&t2,NULL,thread,&i); 
	
		pthread_join(t1,NULL); 
	
		pthread_join(t2,NULL); 	
	}
	
	sem_destroy(&mutex); 
	return 0; 
} 
