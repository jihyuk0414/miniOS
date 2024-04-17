#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 7 
#define NUM_POINTS 1000000

int in_circle_points = 0 ;
pthread_mutex_t mutex; //변수 동기화를 위해

void *estimate_pi()
{
    //멀티 쓰레드의 생성시, 할 작업들에 대해 작성합니다. 
    int cnt = 0 ;
    double x,y;

    unsigned int seed = time(NULL) + pthread_self();

    for (int i = 0 ; i< NUM_POINTS/ NUM_THREADS; i++)
    {
        x = (double)rand_r(&seed) / RAND_MAX *2 -1 ;
        y = (double)rand_r(&seed) / RAND_MAX *2 -1 ; 
        if (x*x + y*y <= 1 )
        {
            cnt++ ;
        }
    }
    pthread_mutex_lock(&mutex)  ;
    in_circle_points += cnt; //전역변수에, 무작위로 정한 원의 내부 점 수를 더한다.
    pthread_mutex_unlock(&mutex) ;

    pthread_exit(0);
}

void calculatepi()
{
    //여기서는, 쓰레드의 생성을 담당합니다. 
    pthread_t thread_addrs[NUM_THREADS];
    pthread_mutex_init(&mutex,NULL) ;

    for (int i = 0; i< NUM_THREADS; i++)
    {
        pthread_create(&thread_addrs[i],NULL,estimate_pi, NULL) ;
    }

    for (int i = 0 ; i< NUM_THREADS; i++)
    {
        pthread_join(thread_addrs[i],NULL) ; 
    }

    double pi_estimate = 4.0 * in_circle_points / NUM_POINTS;
    printf("calculate pi is %.10f\n", pi_estimate) ; 

    in_circle_points = 0 ; //초기화(0으로)
    pthread_mutex_destroy(&mutex);

}