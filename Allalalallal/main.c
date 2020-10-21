#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int counter = 0;
int a;
int j;

struct stro {
    int number;
    int task_1;
    int task_2;
    struct stro *prev;
};
int Add_New_Element(int j);
int Delete_Element(int j);
int Show_all_elements(int j);
int menu(int flag);

struct stro *previous;
struct stro *current;
struct stro *safe_ball;

int main()
{   previous = (struct stro*)malloc(sizeof(struct stro));
    current = (struct stro*)malloc(sizeof(struct stro));
    previous->number = counter;
    previous->task_1 = 1;
    previous->task_2 = 2;
    counter++;
    current->prev = previous;
    previous = current;
    int flag = 0;
 while (flag != 4) {
    system("cls");
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


 int menu(int flag) {
    if (flag == 1) { Add_New_Element(j); }
    else if (flag == 2) { Delete_Element(j); }
    else if (flag == 3) { Show_all_elements(j); }
    else if (flag == 4) {}
    else {
        printf("Incorrect value. \n");
    }
}

int Add_New_Element(int j) {
        current = (struct stro*)malloc(sizeof(struct stro));
        scanf("%d", &current->task_1);
        scanf("%d", &current->task_2);
        current->number = counter;
        counter++;
        current->prev = previous;
        previous = current;
    }

int Delete_Element(int j) {
    safe_ball = current;
    current = current->prev;
    previous = current;
    free(safe_ball);
    counter--;
}

int Show_all_elements(int j) {
    safe_ball = current;
    while (safe_ball->prev->number >= 1) {
        printf("Nomer: %d \n", safe_ball->number);
        printf("%d \n", safe_ball->task_1);
        printf("%d \n", safe_ball->task_2);
        safe_ball = safe_ball->prev;
    }
    scanf("%d \n", &a);
}

