#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void admin();
void voting();
void show();

typedef struct voter_information{
    char roll[20];
    char name[50];
    char depertment[15];
    struct voter_information *next;
} node;
node *head;
node *space,*start=NULL;
node *search(char x[],char y[],char z[],node *,int *);
node *voter_insert(node *);
node *main_logs(node *);
int count=0,vote=0, vote1=0,vote2=0,vote3=0,vote4=0,vote5=0;

int main(){
    while(1){
        main_logs(start);
    }
    return 0;
}

node *main_logs(node *start){
    system("cls");
    printf("\t ****** WELCOME TO THE ONLINE VOTING SYSTEM ******        \n\n\n");
    printf("Enter one of the choices from below:\n");
    printf(" \t\t1. FOR VOTE ENTRY\n");
    printf(" \t\t2. FOR ADMIN PANEL\n\n");
    printf("NB: IF YOUR INFORMATION MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE, OTHERWISE YOU CAN'T\n\n");
    printf("Enter your choice : ");
    char T;
    scanf("%c",&T);
    if(T=='1') start= voter_insert(start);
    else if(T=='2') admin();
    else main_logs(start);
    return start;
}

node *voter_insert(node *start)
{
    int UNIVERSAL=0;
    int *z;
    z = &UNIVERSAL;
    node *temp;
    char name[50],depertment[15],roll[20];
    system("cls");
    printf("\n\n\t IF ROLL, YOUR NAME AND YOUR DEPERTMENT MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n");
    printf("\t\tNow Please \n");
    printf("\t\t\tEnter your ROLL number  :");
    gets(roll);
    gets(roll);
    printf("\t\t\tEnter Your NAME         :");
    gets(name);
    printf("\t\t\tEnter Your Depertment   :");
    gets(depertment);
    temp=(node *)malloc(sizeof(node));
    strcpy(temp->roll,roll);
    strcpy(temp->name,name);
    strcpy(temp->depertment,depertment);
    temp->next=NULL;
    head=temp;
    while(temp!=NULL){
        if((strcmp(temp->roll,"21CSE001")==0&& strcmp(temp->name,"Sauda Tus Sahadia")==0 &&strcmp(temp->depertment,"CSE")==0) ||
                (strcmp(temp->roll,"21CSE002")==0&& strcmp(temp->name,"Shantanu Mandal")==0 &&strcmp(temp->depertment,"CSE")==0)||
                (strcmp(temp->roll,"21CSE003")==0&& strcmp(temp->name,"Md Azom Uddin")==0 &&strcmp(temp->depertment,"CSE")==0)||
                (strcmp(temp->roll,"21CSE004")==0&& strcmp(temp->name,"Md. Abu Syeed Abdullah")==0 &&strcmp(temp->depertment,"CSE")==0)||
                (strcmp(temp->roll,"21CSE005")==0&& strcmp(temp->name,"Maria Islam")==0 &&strcmp(temp->depertment,"CSE")==0)||
                (strcmp(temp->roll,"21CSE006")==0&& strcmp(temp->name,"Farjana Haque Khan ")==0 &&strcmp(temp->depertment,"CSE")==0)||
                (strcmp(temp->roll,"21CSE007")==0&& strcmp(temp->name,"Md. Tanvir Ahmmed")==0 &&strcmp(temp->depertment,"CSE")==0)||
                (strcmp(temp->roll,"21CSE008")==0&& strcmp(temp->name,"Md.Imran sikder")==0 &&strcmp(temp->depertment,"CSE")==0)||
                (strcmp(temp->roll,"21CSE010")==0&& strcmp(temp->name,"Md. Khalid Hossen Muktadir")==0 &&strcmp(temp->depertment,"CSE")==0)||
                (strcmp(temp->roll,"21CSE011")==0&& strcmp(temp->name,"Sabiha Akter Tanny")==0 &&strcmp(temp->depertment,"CSE")==0)||
                (strcmp(temp->roll,"21CSE026")==0&& strcmp(temp->name,"Md. Sadekur Rahman Sahad")==0 &&strcmp(temp->depertment,"CSE")==0)){
                start=search(temp->roll,temp->name,temp->depertment,start,&UNIVERSAL);
                if(UNIVERSAL==0) voting();
                else{
                system("cls");
                printf("\n\nYOU HAVE ALREADY GIVEN YOUR VOTE & CAN'T VOTE AGAIN\n");
                main_logs(start);
            }
        }
        else{
            printf("\n\n\n\n\tYour ROLL or NAME or DEPERTMENT is wrong\n\n");
            printf("\tPlz Re-Enter\n\n");
            system("pause");
            start= main_logs(start);
        }
        temp=temp->next;
    }
    return start;
}
node *search(char x[],char y[],char z[],node *start,int *Y){
    *Y=0;
    node *t,*space;
    if(start==NULL){
        space=(node*)malloc(sizeof(node));
        strcpy(space->roll,x);
        strcpy(space->name,y);
        strcpy(space->depertment,z);
        start=space;
        space->next=NULL;
    }
    else{
        t=start;
        while(t!=NULL){
            if((strcmp(t->roll,x)==0&& strcmp(t->name,y)==0 &&strcmp(t->depertment,z)==0)){
                *Y=1;
                break;
            }
            t=t->next;
        }
        if(*Y==0){
            space=(node*)malloc(sizeof(node));
            strcpy(space->roll,x);
            strcpy(space->name,y);
            strcpy(space->depertment,z);
            t=space;
            space->next=NULL;
        }
    }
    return start;
}

void voting(){
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t  * * * * * * LIST OF CANDIDATES * * * * * \n\n\n");
    printf("\t\t\t NAME                             SYMBOL\n\n");
    printf("\t\t\t 1.Nizam Uddin                    1.Kite\n");
    printf("\t\t\t 2.Kalidas Boral                  2.Boat\n");
    printf("\t\t\t 3.Md. Shamim Sheikh              3.Football\n");
    printf("\t\t\t 4.Moushumi Akter                 4.Cup\n");
    printf("\t\t\t 5.Mohon Ali Biswas               5.Pineaple\n\n\n");
    printf("\t\t\t Enter Your Candidate's no : ");
    int B,j;
    for(j=1; j<=1; j++){ scanf("%d",&B);
        if(B==1){
            vote1++;
            printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Nizam Uddin\n");
            break;}
        if(B==2){
            vote2++;
            printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Kalidas Boral\n");
            break;}
        if(B==3){
            vote3++;
            printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Md. Shamim Sheikh\n");
            break;}
        if(B==4){
            vote4++;
            printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Moushumi Akter\n");
            break;}
        if(B==5){
            vote5++;
            printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Mohon Ali Biswas\n");
            break;}
        if(B!=1||B!=2||B!=3||B!=4||B!=5) printf("\n\tINVALID CHOICE ENTERED\n\n\tENTER AGAIN\n");
    }
    printf("\nTHANK YOU\n\nPress any key to finish voating");
    getch();
}

void admin(){
    int B;
    printf("Enter Your Password To Unlock The Admin Panel : ");
    scanf("%d",&B);
    if   (B==4321) show();
    else           printf("Wrong Password\n");
}

void show(){
    int G;
    system("cls");
    printf("\n\n\n");
    printf("\t\t\tPresent Vote Count :\n\n");
    printf("\t\t\t  Nizam Uddin  is on        %d Votes\n",vote1);
    printf("\t\t\t  Kalidas Boral   is on     %d Votes\n",vote2);
    printf("\t\t\t  Md. Shamim Sheikh is on   %d Votes\n",vote3);
    printf("\t\t\t  Moushumi Akter  is on     %d Votes\n",vote4);
    printf("\t\t\t  Mohon Ali Biswas  is on   %d Votes\n\n\n\n",vote5);
    printf("Enter Any Key For Main Menu\n\n OR \n\nENTER THE SPECIAL PASSWORD TO CLOSING VOTING PORTAL : ");
    scanf("%d",&G);
    if(G==1234){
        system("cls");
        printf("\n\n\t\t\t * * *The VOATING is now CLOSED* * *  \n\n\n");
        exit(0);}
    else main_logs(start);
}
