#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <pthread.h>
#include "../include/main.h"
#include "../include/user.h"
#include "../include/message_thread.h"
#include "../include/state_thread.h"

int main(int argc, char* argv[]) {
	pthread_t messageThread;
	MPI_Status status;
	int provided;	

	struct User* u = malloc(sizeof(struct User));
	pthread_mutex_t criticalMut = PTHREAD_MUTEX_INITIALIZER, lamportMut = PTHREAD_MUTEX_INITIALIZER;
	u->lamport = 0;

	typedef struct {
		struct User *u;
		pthread_mutex_t criticalMut;
		pthread_mutex_t lamportMut;
	} ThrData;

	ThrData thrData = {u, criticalMut, lamportMut};	

	MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);

	MPI_Comm_size(MPI_COMM_WORLD, &u->size);
	MPI_Comm_rank(MPI_COMM_WORLD, &u->rank);

	pthread_create(&messageThread, NULL, message, &thrData);

	state(u, &criticalMut, &lamportMut);

	free(u);
	MPI_Finalize();
	return 0;
}
