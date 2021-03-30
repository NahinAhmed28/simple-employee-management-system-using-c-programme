#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int check;


struct emp
{
    int id;
    char name[20];
    int salary;
};

void append();
void display();
void modify();
void del();
void search();
void ex();


char fname[]={"mydb.dat"};

int main()
{
    system("color 2e");
    system("clr");

    int ch;
    int pass;




    while(1)
    {
        printf("=============Employee Management System=============\n\n");

        printf("1. Add\n\n");
        printf("2. Modify\n\n");
        printf("3. Delete\n\n");
        printf("4. Search\n\n");
        printf("5. Display\n\n");
        printf("0. Exit\n\n");

        printf("========================================================\n\n");

        printf("\nPlease Enter Your Choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: append();
            break;

            case 2: modify();
            break;

            case 3: del();
            break;

            case 4: search();
            break;

            case 5: display();
            break;

            case 0: ex();
            break;

            }
    }


    return 0;
}


void append()
{
    printf("========================================================\n");
    printf("\t\t\tADD MENU\n");
    printf("========================================================\n\n");
    FILE *fp;
    struct emp t1;

    fp=fopen(fname,"ab");

    printf("\nEnter ID: ");
    scanf("%d",&t1.id);

    printf("\nEnter Name: ");
    scanf("%s",t1.name);

    printf("\nEnter Salary: ");
    scanf("%d",&t1.salary);

    fwrite(&t1,sizeof(t1),1,fp);

    fclose(fp);
    printf("\n:::::Data Added Successfully::::::\n");
    printf("\nPress 1 to add again\nPress 2 to go to main screen---->");

    scanf("%d",&check);
    if(check==1){
        append();
    }
    if(check==2)
    {
        main();
    }
}




void search()
{

     printf("========================================================\n");
    printf("\t\t\tSEARCH MENU\n");
    printf("========================================================\n\n");
    FILE *fp;
    struct emp t;
    int id,found=0;

    fp=fopen(fname,"rb");

    printf("\nEnter the Employer ID:");
    scanf("%d",&id);

    while(1)
    {
        fread(&t,sizeof(t),1,fp);

        if(feof(fp))
        {
            break;
        }
        if(t.id==id)
        {
            found=1;
            printf("\n===============================================\n\n");
            printf("\t\t Employee Details of %d\n\n",t.id);
            printf("\n===============================================\n\n");

            printf("Name\tSalary\n\n");

            printf("%s\t",t.name);
            printf("%d\t\n\n",t.salary);
            printf("\n===============================================\n\n");
        }
    }

    if(found==0)
    {
        printf("\nSorry.No record found");
    }
    fclose(fp);


    printf("\nPress 1 to Search again\nPress 2 to go to main screen---->");

    scanf("%d",&check);
    if(check==1){
        search();
    }
    if(check==2)
    {
        main();
    }
}



void display()
{
    FILE *fp;
    struct emp t;
    fp=fopen(fname,"rb");

            printf("\n===============================================\n\n");
            printf("\t\t ALL Employee Details\n\n",t.id);
            printf("\n===============================================\n\n");

            printf("ID\tName\tSalary\n\n");

            while(1)
            {
                fread(&t,sizeof(t),1,fp);

                if(feof(fp))
                {
                    break;
                }
                printf("%d\t",t.id);
                printf("%s\t",t.name);
                printf("%d\t\n\n",t.salary);
            }
            printf("\n===============================================\n\n");
            fclose(fp);

            printf("\nPress 1 to go to main screen---->");

    scanf("%d",&check);
    if(check==1)
    {
        main();
    }
}



void modify()
{

    printf("========================================================\n");
    printf("\t\t\tMODIFY MENU\n");
    printf("========================================================\n\n");
    FILE *fp,*fp1;
    struct emp t,t1;
    int id,found=0,count=0;

    fp=fopen(fname,"rb");
    fp1=fopen("temp.dat","wb");

    printf("\nEnter the Empoloyee ID you want to modify:");
    scanf("%d",&id);

    while(1)
    {
        fread(&t,sizeof(t),1,fp);
        if(feof(fp))
        {
            break;
        }
        if(t.id==id)
        {
            found=1;
            printf("\nEnter Employee ID:");
            scanf("%d",&t.id);

            fflush(stdin);
            printf("\nEnter Employee Name:");
            scanf("%s",t.name);

            printf("\nEnter Employee Salary:");
            scanf("%d",&t.salary);

            fwrite(&t,sizeof(t),1,fp1);
        }
        else
        {
            fwrite(&t,sizeof(t),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if(found==0)
    {
        printf("Sorry.No record Found\n\n");
    }
    else
    {
        fp=fopen(fname,"wb");
        fp1=fopen("temp.dat","rb");

        while(1)
        {
            fread(&t,sizeof(t),1,fp1);
            if(feof(fp1))
            {
                break;
            }
            fwrite(&t,sizeof(t),1,fp);
        }

    }

    fclose(fp);
    fclose(fp1);

    printf("\nPress 1 to MOdify again\nPress 2 to go to main screen---->");

    scanf("%d",&check);
    if(check==1){
        modify();
    }
    if(check==2)
    {
        main();
    }
}



void del()
{
    FILE *fp,*fp1;
    struct emp t,t1;
    int id,found=0,count=0;

    fp=fopen(fname,"rb");
    fp1=fopen("temp.dat","wb");

    printf("\nEnter the Empoloyee ID you want to delete:");
    scanf("%d",&id);

    while(1)
    {
        fread(&t,sizeof(t),1,fp);
        if(feof(fp))
        {
            break;
        }
        if(t.id==id)
        {
            found=1;



        }
        else
        {
            fwrite(&t,sizeof(t),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if(found==0)
    {
        printf("Sorry.No record Found\n\n");
    }
    else
    {
        fp=fopen(fname,"wb");
        fp1=fopen("temp.dat","rb");

        while(1)
        {
            fread(&t,sizeof(t),1,fp1);
            if(feof(fp1))
            {
                break;
            }
            fwrite(&t,sizeof(t),1,fp);
        }

    }

    fclose(fp);
    fclose(fp1);

    printf("\nPress 1 to delete again\nPress 2 to go to main screen---->");

    scanf("%d",&check);
    if(check==1){
        del();
    }
    if(check==2)
    {
        main();
    }
}


void ex()
{
    printf("\n===========================================\n");
    printf(":::::::::::::All Right Reserved:::::::::::::::\n\n");
    printf("\t\t\tDeveloped By\n");
    printf("________________________________________________\n");

    printf("Md.Fakrul Islam\n");
    printf("Mahmudul Hasan\n");
    printf("Nahin Ahmed\n\n");
    printf("\n===========================================\n\n\n\n\n\n\n\n\n");
    printf("press 1 to exit programme---->");
    scanf("%d",&check);
    if(check==1) exit(0);



}



