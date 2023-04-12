#include<persons.h>
#ifndef LOGIN_H
#define LOGIN_H

struct login
{
	int uid;
	int pid;
	char password[25];

};
typedef struct login LOGIN;

int checkCrid(PERSON *, int,char *,int *);

#endif
