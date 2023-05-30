#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void* thread1(void* arg) {
  pthread_mutex_lock(&mutex1); printf("Thread 1 locked mutex1.\n");
  // Здесь поток 1 забывает освободить mutex2 pthread_mutex_lock(&mutex2);
  printf("Thread 1 locked mutex2.\n");
  // Делаем что-то с общим ресурсом...
  pthread_mutex_unlock(&mutex1); printf("Thread 1 unlocked mutex1.\n");
  pthread_mutex_unlock(&mutex2);
  printf("Thread 1 unlocked mutex2.\n"); 
  }

void* thread2(void* arg) {
  pthread_mutex_lock(&mutex2); printf("Thread 2 locked mutex2.\n");
  // Здесь поток 2 ждет, пока поток 1 освободит mutex1 pthread_mutex_lock(&mutex1);
  printf("Thread 2 locked mutex1.\n");
  // Делаем что-то с общим ресурсом...
  pthread_mutex_unlock(&mutex1); printf("Thread 2 unlocked mutex1.\n");
  pthread_mutex_unlock(&mutex2);
  printf("Thread 2 unlocked mutex2.\n"); 
  }

int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL); pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
  }
