/* thread_temp.c
   
   lance 2 threads : le premier simule des temperatures, le deuxieme affiche une alarme lorsque la temperature est > 24
ou < 16 le programme s'arrete lorsque l'on tape ^C  */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static pthread_mutex_t mutex_alarme;

static void* thread_temperature (void *inutile) ;
static void * thread_alarme (void *inutile) ;
static int limit;

int main(void)
{
	limit = 5;
	pthread_t thr1, thr2 ;
	pthread_create (&thr1, NULL, thread_temperature, NULL) ;
	pthread_create (&thr2, NULL, thread_alarme, NULL) ;
	pthread_mutex_lock(&mutex_alarme);
	pthread_join(thr1,NULL);
	pthread_cancel(thr2);
	pthread_exit (NULL) ;
	return 0;
}

double aleatoire (const int limit)
{
	return (((double)rand() / RAND_MAX)* limit);
}

static void * thread_temperature (void *inutile)
{
	pthread_mutex_init(&mutex_alarme, NULL);
	pthread_mutex_lock(&mutex_alarme);
	int temperature = 20 ;
	while (1) {
		temperature += aleatoire(5) -2 ;
		fprintf(stdout, " Temperature : %d \n ", temperature) ;
		if ((temperature < 16 ) || (temperature > 24 ))
		{
			pthread_mutex_unlock(&mutex_alarme);
			limit--;
		}
		sleep(1) ;
		if(limit <=0)pthread_exit (0) ;
	}
	return (NULL) ;
}

static void * thread_alarme (void * inutile)
{
	pthread_mutex_lock(&mutex_alarme);
	while (1) 
	{
		fprintf(stdout, " ALARME \n ") ;
		pthread_mutex_lock(&mutex_alarme);
	}
	return (NULL) ;
}
