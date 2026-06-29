#include <stdio.h>
#include <mpi.h>
#include "../include/main.h"
#include "../include/types.h"
#include "../include/message_thread.h"
#include "../include/state_thread.h"

int main(int argc, char* argv[]) {
	MPI_Status status;
	int provided;
	MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);

	MPI_Comm_size(MPI_COMM_WORLD, &u.size);
	MPI_Comm_rank(MPI_COMM_WORLD, &u.rank);

	pthread_create(&messageThread, NULL, message, 0);

	MPI_Finalize();
	return 0;
}
