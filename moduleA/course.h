#ifndef _COURSE_H
#define _COURSE_H

struct class
{
    int bh;
    char mc[10];
    char xz;
    int xs;
    int xf;
    int yx_num;
    int sx_num;
}cla[100];
int much;

void show_cla(int flag);
void loadin_cla();
void write_cla();
void log_cla(char type[20],struct students tmp);
int add_cla();
int search_cla();
int delet_cla();
int change_cla();
int count_cla();
int stu_cour();

#endif
