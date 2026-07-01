#ifndef USER_H
#define USER_H
struct User {
	int rank, size, lamport;
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
#endif
