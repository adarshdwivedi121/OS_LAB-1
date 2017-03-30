#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex,writeblock;
int data = 0,rcount = 0;

void *reader()
{
	sem_wait(&mutex);
	rcount = rcount + 1;
	if(rcount==1)	sem_wait(&writeblock);
	sem_post(&mutex);
	printf("Reader read data: %d\n", data--);
	sleep(1);
	sem_wait(&mutex);
	rcount = rcount - 1;
	if(rcount==0)	sem_post(&writeblock);
	sem_post(&mutex);
}

void *writer()
{
	sem_wait(&writeblock);
	data++;
	printf("Writer written data: %d\n", data);
	sleep(1);
	sem_post(&writeblock);
}

main()
{
	int nw, nr, i;  
	pthread_t rtid[5],wtid[5];

	sem_init(&mutex,0,1);
	sem_init(&writeblock,0,1);

	printf("\nEnter No. of Readers: ");
	scanf("%d", &nr);
	printf("Enter No. of Writers: ");
	scanf("%d", &nw);

	for(i=0; i<nw; i++)
	pthread_create(&wtid[i],NULL,writer, NULL);
	for(i=0; i<nr; i++)
	pthread_create(&rtid[i],NULL,reader, NULL);

	for(i=0; i<nw; i++)
	pthread_join(wtid[i],NULL);
	for(i=0; i<nr; i++)
	pthread_join(rtid[i],NULL);
}
