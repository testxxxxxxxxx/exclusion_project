#include <stdio.h>
#include <mpi.h>
#include <pthread.h>
#include "../include/main.h"

int main(int argc, char* argv[]) {
	MPI_Status status;
	int provided;
	MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);


	return 0;
}
