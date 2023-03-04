#ifndef TICKET_H
#define TICKET_H

struct ticket
{
	int bid;
	char bdate[20];
	char tdate[20];
	char src[20];
	char dest[20];
	int status;
	int sno;
	int pid;
};
typedef struct ticket TICKET;

#endif
