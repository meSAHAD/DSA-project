#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAX_VOTERS 11

typedef struct {
    char roll[20];
    char name[50];
    char department[15];
    int hasVoted; 
} Voter;

Voter voters[MAX_VOTERS] = {
    {"21CSE001", "Sauda Tus Sahadia", "CSE"},
    {"21CSE002", "Shantanu Mandal", "CSE"},
    {"21CSE003", "Md Azom Uddin", "CSE"},
    {"21CSE004", "Md. Abu Syeed Abdullah", "CSE"},
    {"21CSE005", "Maria Islam", "CSE"},
    {"21CSE006", "Farjana Haque Khan ", "CSE"},
    {"21CSE007", "Md. Tanvir Ahmmed", "CSE"},
    {"21CSE008", "Md.Imran sikder", "CSE"},
    {"21CSE010", "Md. Khalid Hossen Muktadir", "CSE"},
    {"21CSE011", "Sabiha Akter Tanny", "CSE"},
    {"21CSE026", "Md. Sadekur Rahman Sahad", "CSE"}
};

int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0, vote5 = 0;

void main_logs();
void voting();
void admin();
void show();
int search_voter(char[], char[], char[]);
void voter_insert();

int main() {
    while (1) {
        main_logs();
    }
    return 0;
}

void main_logs() {
    system("cls");
    printf("\t ****** WELCOME TO THE VOTING SYSTEM ******        \n\n\n");
    printf("Enter one of the choices from below:\n");
    printf(" \t\t1. FOR VOTE ENTRY\n");
    printf(" \t\t2. FOR ADMIN PANEL\n\n");
    printf("NB: IF YOUR INFORMATION MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE, OTHERWISE YOU CAN'T\n\n");
    printf("Enter your choice : ");

    char T;
    fflush(stdin);
    scanf("%c", &T);

    if (T == '1') {
        voter_insert();
    } else if (T == '2') {
        admin();
    } else {
        main_logs();
    }
}

void voter_insert() {
    char name[50], department[15], roll[20];
    system("cls");
    printf("\n\n\t IF ROLL, YOUR NAME AND YOUR DEPARTMENT MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n");
    printf("\t\tNow Please \n");
    printf("\t\t\tEnter your ROLL number  :");
    fflush(stdin);
    gets(roll);
    printf("\t\t\tEnter Your NAME         :");
    gets(name);
    printf("\t\t\tEnter Your Department   :");
    gets(department);

    if (search_voter(roll, name, department) != -1) 
    {
        voting();
    } 
    else 
    {
        printf("\n\n\n\n\tYour ROLL or NAME or DEPARTMENT is wrong\n\n");
        printf("\tPlease Re-Enter\n\n");
        system("pause");
        main_logs();
    }
}

int search_voter(char roll[], char name[], char department[]) {
    for (int i = 0; i < MAX_VOTERS; i++) {
        if (strcmp(voters[i].roll, roll) == 0 && strcmp(voters[i].name, name) == 0 && strcmp(voters[i].department, department) == 0) {
            return i;
        }
    }
    return -1;
}

void voting() {
    system("cls");
    int B;
    
     if (voters[B - 1].hasVoted == 1) {
        printf("\n\nYOU HAVE ALREADY VOTED ONCE. DUPLICATE VOTING IS NOT ALLOWED.\n");
    } 
    else {
    printf("\n\n\n\n");
    printf("\t\t\t  * * * * * * LIST OF CANDIDATES * * * * * \n\n\n");
    printf("\t\t\t NAME                             SYMBOL\n\n");
    printf("\t\t\t 1.Nizam Uddin                    1.Kite\n");
    printf("\t\t\t 2.Kalidas Boral                  2.Boat\n");
    printf("\t\t\t 3.Md. Shamim Sheikh              3.Football\n");
    printf("\t\t\t 4.Moushumi Akter                 4.Cup\n");
    printf("\t\t\t 5.Mohon Ali Biswas               5.Pineaple\n\n\n");
    printf("\t\t\t Enter Your Candidate's no : ");
    scanf("%d", &B);
    switch (B) {
        case 1:
            vote1++;
            printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Nizam Uddin\n");
            break;
        case 2:
            vote2++;
            printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Kalidas Boral\n");
            break;
        case 3:
            vote3++;
            printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Md. Shamim Sheikh\n");
            break;
        case 4:
            vote4++;
            printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Moushumi Akter\n");
            break;
        case 5:
            vote5++;
            printf("\n\nYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Mohon Ali Biswas\n");
            break;
        default:
            printf("\n\tINVALID CHOICE ENTERED\n\n\tENTER AGAIN\n");
    }
    printf("\nTHANK YOU\n\nPress any key to finish voting");
        getch();
        // Update the hasVoted flag for the voter
        voters[B - 1].hasVoted = 1;
    }
}

void admin() {
    int B;
    printf("Enter Your Password To Unlock The Admin Panel : ");
    scanf("%d", &B);
    if (B == 4321) {
        show();
    } else {
        printf("Wrong Password\n");
    }
}

void show() {
    int G;
    system("cls");
    printf("\n\n\n");
    printf("\t\t\tPresent Vote Count :\n\n");
    printf("\t\t\t  Nizam Uddin  is on        %d Votes\n", vote1);
    printf("\t\t\t  Kalidas Boral   is on     %d Votes\n", vote2);
    printf("\t\t\t  Md. Shamim Sheikh is on   %d Votes\n", vote3);
    printf("\t\t\t  Moushumi Akter  is on     %d Votes\n", vote4);
    printf("\t\t\t  Mohon Ali Biswas  is on   %d Votes\n\n\n\n", vote5);
    printf("Enter Any Key For Main Menu\n\n OR \n\nENTER THE SPECIAL PASSWORD TO CLOSING VOTING PORTAL : ");
    scanf("%d", &G);
    if (G == 1234) {
        system("cls");
        printf("\n\n\t\t\t * * *The VOTING is now CLOSED* * *  \n\n\n");
        exit(0);
    } else {
        main_logs();
    }
}
