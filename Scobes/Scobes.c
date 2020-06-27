#include <stdio.h>

/*
  Функция совпадения
    - Выводит кол-во незакрытых скобок (+), кол-во скобок без начала (-), или 0, если все скобки закрыты
*/
int match(char *file_name, char *Scobes, int shift)
{
    FILE *file_in = fopen(file_name, "r");
    int f_size;
    int matches = 0;
    char commented = 0;
    char Comentator = '"';
    int c;


    if (file_in == NULL) return NULL;

    fseek(file_in, 0, SEEK_END);
    f_size = ftell(file_name);
    fseek(file_in, 0, SEEK_SET);


    while ((c = fgetc(file_in)) != EOF)
    {
        if (c==Comentator)
        {
            commented = !commented;
        }
        if (!commented)
        {
            matches += (c==Scobes[shift+0]);
            matches -= (c==Scobes[shift+1]);
        }
    }

    return matches;
}


int main(int argc, char **argv)
{
    //char Parentheses[3] = "()\0";
    //char Braces[3] = "{}\0";
    //char Square_brackets[3] = "[]\0";

    char Brackets[7] = "{}[]()\0";

    int current_matches;
    int number_of_errors = 0;

    int i;

    if (argc != 2) {printf("Error: wrong number of arguements"); return 1;}
    else
    {
        printf("\n");
        for(i=0;i<3;i++)
        {
            printf("%c%c: ",Brackets[i*2+0],Brackets[i*2+1]);
            current_matches = match(argv[1],Brackets,i*2);
            if (current_matches == 0) printf("Correct");
            else
            {
                printf("Error   - ");
                if (current_matches>0) printf("%d are opened",current_matches);
                else                   printf("%d are closed without opening",-current_matches);
            }
            printf("\n");
            number_of_errors += abs(current_matches);
        }
        printf("\nNumber of incorrect usages: %d\n",number_of_errors);
    }

    getchar();
    return 0;
}
