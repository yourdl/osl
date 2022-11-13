#include <stdio.h>
#include <pthread.h>

pthread_mutex_t wr, mutex;
int a=10, readcount=0;

void * reader (void *arg){
    long int num = (long int)arg;
    pthread_mutex_lock(&mutex);
    readcount++;
    pthread_mutex_unlock(&mutex);
    
    if (readcount==1){
        pthread_mutex_lock(&wr);
    }
    printf("\nReader %d is in critical section", num);
    printf("\nReader %d is reading data %d", num, a);
    sleep(1);
    pthread_mutex_lock(&mutex);
    readcount--;
    pthread_mutex_unlock(&mutex);
    if (readcount==0){
        pthread_mutex_unlock(&wr);
    }
    printf("\nReader %d left critical section", num);
}

void * writer (void *arg){
    long int num = (long int)arg;
    pthread_mutex_lock(&wr);
    printf("\nWriter %d is in critical section", num);
    printf("\nThe writer %d has written data %d", num, ++a);
    sleep(1);

    pthread_mutex_unlock(&wr);
    printf("\nWriter %d left the critical section", num);
}

int main(){
    pthread_t r[10],w[10];
    long int i, j;
    int nor, now;

    pthread_mutex_init(&wr, NULL);
    pthread_mutex_init(&mutex, NULL);

    printf("\nEnter no of readers and writers: ");
    scanf("%d %d", &nor, &now);

    for(i=0; i<nor; i++){
        pthread_create(&r[i], NULL, reader, (void *)i);
    }
    for(j=0; j<now; j++){
        pthread_create(&w[j], NULL, writer, (void *)j);
    }
    for(i=0; i<nor; i++){
        pthread_join(r[i], NULL);
    }
    for(j=0; j<now; j++){
        pthread_join(w[j],NULL);
    }
    return 0;

}
