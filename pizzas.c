#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
 

int NumberOfPizza=0;
pthread_mutex_t lock;

void *supply(void *vargp)
{
    pthread_mutex_lock(&lock);
   
    if(NumberOfPizza < 10)
    {
   
            NumberOfPizza= NumberOfPizza+1;
            printf("After Supplying 1 pizza we have %d pizzas\n",NumberOfPizza);
            sleep(1);
           
           
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}


   void *consume(void *vargp)
{
    pthread_mutex_lock(&lock);
   
    if(NumberOfPizza>0)
    {
            NumberOfPizza= NumberOfPizza-1;
            printf("After  eating one pizza, we have %d pizza\n",NumberOfPizza);
           
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}
   
int main()
{
    pthread_t supplyThread_id,  consumeThrea_id;
   
    while(1)
    {
       
   
    while(NumberOfPizza<10)
    {
        pthread_create(&supplyThread_id, NULL, supply,NULL);
       
         
    }
   
   
    while(NumberOfPizza>1)
    {
        pthread_create(&consumeThrea_id,NULL,consume,NULL);
       
    }
    }
   
   
    pthread_join(supplyThread_id, NULL);
    pthread_join(consumeThrea_id, NULL);
   
    exit(0);
}
