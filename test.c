#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

long long a;
pthread_mutex_t aLock;

void print_hello(void *arg)
{
    int i = 1;
    while( i < 500000)
    {
        pthread_mutex_lock(&aLock);
        a = a + i;
        i++;
        pthread_mutex_unlock(&aLock);
    }
}

void print_world(void *arg)
{
    int i = 500000;
    while(i <= 1000000)
    {
        pthread_mutex_lock(&aLock);
        a = a + i;
        i++;
        pthread_mutex_unlock(&aLock);
    }
}

int main()
{   
    void *arg;
    pthread_t t1, t2;

    pthread_mutex_init(&aLock, NULL);
    pthread_create(&t2, NULL, (void*)&print_hello, NULL);
    pthread_create(&t1, NULL, (void*)&print_world, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    // print_hello(arg);
    // print_world(arg);
    // int i = 1;
    // while(i <= 1000000)
    // {
    //     a = a + i;
    //     i++;
    // }
    printf("%lld\n", a);

}
