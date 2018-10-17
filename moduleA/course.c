#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"student.h"
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
void show_cla(int flag)
{
	int i,j;
    printf("%8s%10s%8s%8s%8s%8s%8s\n","NUMBER","LESSON","KIND","TIME","POINT","STUDENT","TOTAL");
	if(flag == -1)
	{
		for(i=0;i<much;i++)
		{
			printf("%8d%10s%8c%8d%8d%8d%8d\n",cla[i].bh,cla[i].mc,cla[i].xz,cla[i].xs,cla[i].xf,cla[i].yx_num,cla[i].sx_num);	
		}
	}
	else
	{
		printf("%8d%10s%8c%8d%8d%8d%8d\n",cla[flag].bh,cla[flag].mc,cla[flag].xz,cla[flag].xs,cla[flag].xf,cla[flag].yx_num,cla[flag].sx_num);	
	}
}
void loadin_cla()
{
	int i=0,j,num=0,n=0;
	FILE *fp;
	if((fp = fopen("./moduleA/class.txt","r"))==NULL)
	{
		printf("File error!\n");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %c %d %d %d %d",&cla[i].bh,cla[i].mc,&cla[i].xz,&cla[i].xs,
			&cla[i].xf,&cla[i].yx_num,&cla[i].sx_num);
		i++;
	}
	much=i-1;
	fclose(fp);
}
int write_cla()
{
    FILE *fp_w;
    int i;
	if((fp_w = fopen("./moduleA/class.txt","w")) == NULL)
	{
		printf("File error!\n");
		exit(0);
	}
	for(i=0;i<much;i++)
	{
		fprintf(fp_w,"%8d %10s %8c %8d %8d %8d %8d\n",cla[i].bh,cla[i].mc,cla[i].xz,cla[i].xs,
		cla[i].xf,cla[i].yx_num,cla[i].sx_num);
	}
	fclose(fp_w);
    return 0;
}
void log_cla(char type[],struct class tmp)
{
    FILE *fp_log;
	if((fp_log = fopen("./moduleA/log.log","a")) == NULL)
	{
		printf("File error!\n");
		exit(0);
	}
    time_t *timep = malloc(sizeof(*timep));
    time(timep);
    char *s = ctime(timep);
    fprintf(fp_log,"%s %s %s %d %s %c %d %d %d %d\n",s,"COURSE",type,tmp.bh,tmp.mc,tmp.xz,tmp.xs,
		tmp.xf,tmp.yx_num,tmp.sx_num);
    fclose(fp_log);
}
int add_cla()
{
	int i=much,c_bh,j;
	printf("please input course number:");
	scanf("%d",&c_bh);
    for(j=0;j<much;j++)
        if(c_bh == cla[j].bh)
            break;
    if(j>=much)
        cla[i].bh=c_bh;
    else
    {
        printf("NUMBER error!\n");
        return 0;
    }
	printf("please input course name:");
	scanf("%s",cla[i].mc);
	getchar();
	printf("please input course kind:");
	scanf("%c",&cla[i].xz);
	printf("please input course time:");
	scanf("%d",&cla[i].xs);
	printf("please input course sorce:");
	scanf("%d",&cla[i].xf);
	printf("please input course students:");
	scanf("%d",&cla[i].yx_num);
	printf("please input course total number:");
	scanf("%d",&cla[i].sx_num);
	much++;
    log_cla("Add",cla[i]);
	FILE *fp_a;
	if((fp_a = fopen("./moduleA/class.txt","a")) == NULL)
	{
		printf("File error!\n");
		exit(0);
	}
	fprintf(fp_a,"%8d %10s %8c %8d %8d %8d %8d",cla[i].bh,cla[i].mc,cla[i].xz,cla[i].xs,
		cla[i].xf,cla[i].yx_num,cla[i].sx_num);
	fclose(fp_a);
}
int search_cla()
{
	int i;
	printf("\nPlease input the course NUMBER:");
	int search_bh;
	scanf("%d",&search_bh);
	for(i=0;i<much;i++)
	{
		if(cla[i].bh == search_bh)
			return i;
	}
	return -2;
}
int delet_cla()
{
	int delet_i,i,j,k;
	delet_i=search_cla();
	if(delet_i == -2)
	{
		printf("\nNot exist!\n");
		return 0;
	}
    log_cla("Delet",cla[delet_i]);
	for(i=delet_i;i<much-1;i++)
	{
		cla[i]=cla[i+1];
	}
    much--;
    for(i=0;i<len;i++)
    {
        for(j=0;stu[i].course[j];j++)
            if(stu[i].course[j] == cla[delet_i].bh)
            {
               for(k=j;stu[i].course[k];k++)
                    stu[i].course[k] = stu[i].course[k+1];
            }                        
    }
	return 0;
}
int change_cla()
{
	int change_i,i;
	change_i=search_cla();
	if(change_i == -2)
	{
		printf("\nNot exist!\n");
		return 0;
	}
    log_cla("Change_before",cla[change_i]);
	show_cla(change_i);
	printf("please input course number:");
	scanf("%d",&cla[change_i].bh);
	printf("please input course name:");
	scanf("%s",cla[change_i].mc);
	getchar();
	printf("please input course kind:");
	scanf("%c",&cla[change_i].xz);
	printf("please input course time:");
	scanf("%d",&cla[change_i].xs);
	printf("please input course sorce:");
	scanf("%d",&cla[change_i].xf);
	printf("please input course students:");
	scanf("%d",&cla[change_i].yx_num);
	printf("please input course total number:");
	scanf("%d",&cla[change_i].sx_num);
    
    log_cla("Change_after",cla[change_i]);
	
	return 0;
}
int count_cla()
{
	int i,j,k;
    for(i=0;i<much;i++)
        cla[i].yx_num = 0;
	for(i=0;i<len;i++)
	{
		j=0;
		while(stu[i].course[j]!=0)
		{
			for(k=0;k<much;k++)
				if(stu[i].course[j] == cla[k].bh)
					break;
            if(k<much)
			    cla[k].yx_num++;
            j++;
		}
	}
	return 0;
}
int stu_cour()
{
	int select,flag;
    count_cla();
    show_cla(-1);
	while(select!=5)
	{
          printf("\t┍┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┑\n");
		  printf("\t┋   STUDENT COURSE SYSTEM   ┋\n");
          printf("\t┍┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┑");
		printf("\n\t┋1.Add course information   ┋\n");
		printf("\n\t┋2.Change course information┋\n");
		printf("\n\t┋3.Delete course information┋\n");
		printf("\n\t┋4.Search course information┋\n");
		printf("\n\t┋5.Exit                     ┋\n");
          printf("\t┕┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┙\n");
		printf("\n\tPlease choose the function: ");
		scanf("%d",&select);
		if(select == 1)
		{
            add_cla();
            show_cla(-1);
        }
		else if(select == 2)
        {
            change_cla();
            count_cla();
            show_cla(-1);
            write_cla();
        }
		else if(select == 3)
	    {
            delet_cla();
            show_cla(-1);
            write_cla();
        }
		else if(select == 4)
		{
			flag=search_cla();
			if(flag == -2)
				printf("\nNot exist!\n");
			else
				show_cla(flag);
		}
		else if(select>5 || select<1)
			printf("\tInput error! Please try again!\n");
        else if(select == 5)
            system("clear");
	}
	return 0;
}
