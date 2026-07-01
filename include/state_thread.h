#ifndef STATE_THREAD_H
#define STATE_THREAD_H
#include "../include/user.h"
#include <pthread.h>
void state(struct User* u , pthread_mutex_t* criticalMut, pthread_mutex_t* lamportMut);
#endif
