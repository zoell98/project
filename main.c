#include<stdio.h>
int main()
{
	printf("\nWelcome to Students' course selection management system!\n");
	int select=0;
    loadin();
    loadin_cla();
	while(select!=3)
	{
          printf("\t┍┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┑\n");
		  printf("\t┋               MENU                ┋\n");
          printf("\t┍┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┑");
		printf("\n\t┋1.Student information management.  ┋\n");
		printf("\n\t┋2.Students' course management.     ┋\n");
		printf("\n\t┋3.Exit.                            ┋\n");
          printf("\t┕┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┙\n");
		printf("\nPlease choose the function: ");
		scanf("%d",&select);
        system("clear");
		if(select == 1)
			stu_info();
		else if(select == 2)
			stu_cour();
		else if(select > 3 || select < 1)
			printf("\n\tInput error! Please try again!\n");
	}
	printf("\n\tThank you for using!\n");
	return 0;
}
