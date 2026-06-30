#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "../include/main.h"
#include "../include/message_thread.h"
#include "../include/state_thread.h"

int main(int argc, char* argv[]) {
	pthread_t messageThread;
	MPI_Status status;
	int provided;
	struct User {
		int rank, size;
		enum STATES {
			REST,
			WAIT,
			HELD
		} stat;
		enum MESSAGES {
			REQUEST,
			ACK
		} msg;
	};	

	struct User* u = malloc(sizeof(struct User));
	pthread_mutex_t criticalMut = PTHREAD_MUTEX_INITIALIZER, lamportMut = PTHREAD_MUTEX_INITIALIZER;

	MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);

	MPI_Comm_size(MPI_COMM_WORLD, &u->size);
	MPI_Comm_rank(MPI_COMM_WORLD, &u->rank);

	pthread_create(&messageThread, NULL, message, 0);

	state(u, &criticalMut, &lamportMut);

	free(u);
	MPI_Finalize();
	return 0;
}
