#ifndef _STUDENT_H
#define _STUDENT_H

struct students
{
    int id;
    char name[10];
    int course[10];
    int sorce;
    int show;
}stu[100];
int len;

void show_stu(int flag);
void loadin();
int write_stu();
void log_stu(char type[20],struct students tmp);
int add();
int change();
int delet();
int search();
int stu_info();

#endif
