#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"course_i.h"
struct students
{
    int id;
    char name[10];
    int course[10];
    int sorce;
    int show;
}stu[100];
int len;
void show_stu(int flag)
{
	int i,j;
	printf("%8s%8s%8s%8s\n","ID","NAME","SORCE","COURSE");
	if(flag == -1)
	{
		for(i=0;i<len;i++)
		{
			printf("%8d%8s%8d  ",stu[i].id,stu[i].name,stu[i].sorce);
			for(j=0;stu[i].course[j+1];j++)
				printf("%d,",stu[i].course[j]);
			printf("%d\n",stu[i].course[j]);
		}
	}
	else
	{
		printf("%8d%8s%8d  ",stu[flag].id,stu[flag].name,stu[flag].sorce);
		for(j=0;stu[flag].course[j+1];j++)
			printf("%d,",stu[flag].course[j]);
		printf("%d\n",stu[flag].course[j]);
	}
}
int write_stu()
{
    FILE *fp_w;
    int i,j;
	if((fp_w = fopen("./moduleB/student_i.txt","w")) == NULL)
	{
		printf("File error!\n");
		exit(0);
	}
	for(i=0;i<len;i++)
	{
		fprintf(fp_w,"%d %s %d ",stu[i].id,stu[i].name,stu[i].sorce);
		for(j=0;stu[i].course[j+1];j++)
			fprintf(fp_w,"%d,",stu[i].course[j]);
		fprintf(fp_w,"%d\n",stu[i].course[j]);
	}
	fclose(fp_w);
    return 0;
}
void log_stu(char type[],struct students tmp)
{
    FILE *fp_log;
    int j;
	if((fp_log = fopen("./moduleB/log.log","a")) == NULL)
	{
		printf("File error!\n");
		exit(0);
	}
    time_t *timep = malloc(sizeof(*timep));
    time(timep);
    char *s = ctime(timep);
    fprintf(fp_log,"%s %s %s %d %s %d ",s,"STUDENT",type,tmp.id,tmp.name,tmp.sorce);
	for(j=0;tmp.course[j+1];j++)
		fprintf(fp_log,"%d,",tmp.course[j]);
	fprintf(fp_log,"%d\n",tmp.course[j]);
    fclose(fp_log);
}
void loadin()
{
	int i=0,j,num=0,n=0,k=0;
	char course_tmp[30];
    printf("please input students' number:");
    scanf("%d",&n);
    printf("please input students' information ID NAME SORCE COURSE:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d%s%d%s",&stu[i].id,stu[i].name,&stu[i].sorce,course_tmp);	
		num=0;
		for(j=0,k=0;course_tmp[j];j++)
		{
			if(course_tmp[j] == ',')
			{
				stu[i].course[k]=num;
				k++;
				num=0;
			}
			else
				num = num*10+(course_tmp[j]-'0');
		}
		stu[i].course[k]=num;
	}
	len=n;
    write_stu();
}

int add()
{
	int i=len,c_id,j;
	printf("please input student's id:");
	scanf("%d",&c_id);
    for(j=0;j<len;j++)
        if(c_id == stu[j].id)
            break;
    if(j>=len)
        stu[i].id=c_id;
    else
    {
        printf("ID error!\n");
        return 0;
    }
	printf("please input student's name:");
	scanf("%s",stu[i].name);
	printf("please input student's score:");
	scanf("%d",&stu[i].sorce);
	printf("please input student's course(enter 0 to end it):");
	int tmp;
    j=0;
	while(1)
	{
		scanf("%d",&tmp);
		if(tmp == 0)
			break;
		stu[i].course[j++]=tmp;
	}
    for(;j<10;j++)
        stu[i].course[j]=0;
    log_stu("Add",stu[i]);
	len++;
	FILE *fp_a;
	if((fp_a = fopen("./moduleA/student_i.txt","a+")) == NULL)
	{
		printf("File error!\n");
		exit(0);
	}
	fprintf(fp_a,"%d %s %d ",stu[i].id,stu[i].name,stu[i].sorce);
	for(j=0;stu[i].course[j+1];j++)
			fprintf(fp_a,"%d,",stu[i].course[j]);
	fprintf(fp_a,"%d\n",stu[i].course[j]);
	fclose(fp_a);
}
int change()
{
	int change_num,i;
	change_num=search();
	if(change_num == -2)
	{
		printf("\nNot exist!\n");
		return 0;
	}
    log_stu("Change_before",stu[change_num]);
	show_stu(change_num);
	printf("please input student's id:");
	scanf("%d",&stu[change_num].id);
	printf("please input student's name:");
	scanf("%s",stu[change_num].name);
	printf("please input student's score:");
	scanf("%d",&stu[change_num].sorce);
	printf("please input student's course(enter 0 to end it):");
	int tmp,j=0;
	while(1)
	{
		scanf("%d",&tmp);
		if(tmp == 0)
			break;
		stu[change_num].course[j++]=tmp;
	}
    for(i=j;i<10;i++)
        stu[change_num].course[i]=0;
    log_stu("Change_after",stu[change_num]);
}
int delet()
{
	int delet_num,i,j;
	delet_num=search();
	if(delet_num == -2)
	{
		printf("\nNot exist!\n");
		return 0;
	}
    log_stu("Delet",stu[delet_num]);
	for(i=delet_num;i<len-1;i++)
	{
		stu[i]=stu[i+1];
	}
	len--;
	return 0;
}
int search()
{
	int select,i,j;
	printf("\n1.Search as student's ID\n");
	printf("\n2.Search as student's NAME\n");
	printf("\n3.Exit!\n");
	printf("\nPlease choose the function: ");
	scanf("%d",&select);
	char search_name[10];
	int search_id;
	if(select == 1)
	{
		printf("please input ID:");
		scanf("%d",&search_id);
		for(i=0;i<len;i++)
		{
			if(stu[i].id == search_id)
				return i;
		}
		return -2;
	}
	else if(select == 2)
	{
		printf("please input NAME:");
		scanf("%s",search_name);
		for(i=0;i<len;i++)
		{
			if(strcmp(stu[i].name,search_name) == 0)
				return i;
		}
		return -2;
	}
	else if(select == 3)
		return -1;
	else
		printf("Input error!\n");
}
int count_stu()
{
	int i,j,k;
    for(i=0;i<len;i++)
        stu[i].sorce = 0;
	for(i=0;i<len;i++)
	{
		j=0;
		while(stu[i].course[j] != 0)
        {
            for(k=0;k<much;k++)
                if(stu[i].course[j] == cla[k].bh)
                    break;
            if(k<much)
                stu[i].sorce += cla[k].xf;
            j++;
        }
	}
	return 0;
}
int stu_info()
{
	int select,flag;
    count_stu();
    show_stu(-1);
	while(select!=5)
	{
          printf("\t┍┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┑\n");
		  printf("\t┋  STUDENT INFORMATION SYSTEM   ┋\n");
          printf("\t┍┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┑");
		printf("\n\t┋1.Add student's information    ┋\n");
		printf("\n\t┋2.Change student's information ┋\n");
		printf("\n\t┋3.Delete student's information ┋\n");
		printf("\n\t┋4.Search student's information ┋\n");
		printf("\n\t┋5.Exit                         ┋\n");
          printf("\t┕┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┙\n");
		printf("\n\tPlease choose the function: ");
		scanf("%d",&select);
		if(select == 1)
		{
            add();
            count_stu();
            show_stu(-1);
        }
		else if(select == 2)
		{
            change();
            count_stu();
            show_stu(-1);
            write_stu();
        }
		else if(select == 3)
		{
            delet();
            count_stu();
            show_stu(-1);
            write_stu();
        }
		else if(select == 4)
		{
			flag=search();
			if(flag == -2)
				printf("\nNot exist!\n");
			else
				show_stu(flag);
		}
		else if(select>5 || select<1)
			printf("Input error! Please try again!\n");
        else if(select == 5)
            system("clear");
	}
	return 0;
}
