#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct stroka {
    int number;
    int task;
    struct stroka *lasty;
    struct stroka *nexty;
};

struct stroka *these;
struct stroka *last;
struct stroka *next;
struct stroka *forfree;
int n1, n2, k = 1;


int main() {
 int flag = 0;
 while (flag != 4) {
    //system("cls");
    printf("Menu \n");
    printf("1. Add new element. \n");
    printf("2. Delete element. \n");
    printf("3. Show all elements. \n");
    printf("4. Exit the program. \n");
    printf("Please select menu point:");
    scanf("%d", &flag);
    menu (flag);
 }

 printf ("Finished! Thank you for using our programm!  \nPlease press key Enter");
 return 0;

}

 void menu (int flag){
     if (flag == 1) {Add_New_Element();}
     else if (flag == 2) {Delete_Element();}
     else if (flag == 3) {Show_all_elements();}
     else if (flag == 4) {}
 else {
     printf ("Incorrect value. \n");
 }
 }


Add_New_Element(){
    if (k == 1) {
        these = (struct stroka*)malloc(sizeof(struct stroka));
        last = (struct stroka*)malloc(sizeof(struct stroka));
        next = (struct stroka*)malloc(sizeof(struct stroka));
        scanf("%d", &n1);
        scanf("%d", &n2);
        these->number = n1;
        these->task = n2;
        printf("%d \n", these->number);
        printf("%d \n ", these->task);
        printf("%d \n", last->number);
        printf("%d \n", last->number);
        k = k+1;
        these->lasty = 3;
        last = these;
        these = next;
    }
    else {
        next = (struct stroka*)malloc(sizeof(struct stroka));
        scanf("%d", &n1);
        scanf("%d", &n2);
        these->number = n1;
        these->task = n2;
        printf("%d \n", these->number);
        printf("%d \n ", these->task);
        printf("%d \n", last->number);
        printf("%d \n", last->task);
        k = k+1;
        these->lasty = last;
        last = these;
        these = next;
    }
}

Delete_Element(){
    forfree = these;
    these = these->lasty;
    free(forfree);
    forfree = NULL;
}
Show_all_elements(){
 while (these->lasty != 3) {
    printf("%d \n", these->number);
    printf("%d \n", these->task);
    these = these->lasty;
 }
}

