src_files = ./src/main.c ./src/state_thread.c ./src/message_thread.c
include_files =  ./include/main.h ./include/state_thread.h ./include/message_thread.h

compile:
	mkdir bin
	mpicc $(src_files) $(include_files) -pthread -Wall -o ./bin/main

clean:
	rm -rf ./bin

run:
	mpirun -np 8 --oversubscribe ./bin/main	
