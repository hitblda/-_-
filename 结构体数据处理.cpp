#include "header.h"


void copy_teacher_deep(struct teacher* to, struct teacher* from)
{
	//两种方法
	//方法1
	to->name = (char*)malloc(sizeof(char)*NAME_LEN);
	memset(to->name, 0, sizeof(char)*NAME_LEN);
	strcpy(to->name, from->name);

	to->id = from->id;

	//方法2
/*
	memcpy(to, from, sizeof(struct teacher));
	to->name = (char*)malloc(sizeof(char) * NAME_LEN);
	strcpy(to->name, from->name);*/
}


void print_teacher(struct teacher tp)
{
	struct teacher tmp = tp;
	printf("id : %d, name : %s\n", tmp.id, tmp.name);
}