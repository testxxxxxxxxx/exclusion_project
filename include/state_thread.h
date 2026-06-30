#include <pthread.h>
extern struct User;

void state(struct User* u, pthread_mutex_t* criticalMut, pthread_mutex_t* lamportMut);
