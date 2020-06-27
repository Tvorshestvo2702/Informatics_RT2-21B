#include <stdio.h>



int circle(int a, int start, int end)
{
    int circled_a;
    if (a<start)
    {
        /*
          - end-start+1 - кол-во символов между началом и концом

          ‘ормула (start-a)%(end-start) даЄт последовательность чисел, котора€ заканчиваетс€ еденицей
          - когда a на 1 меньше start  (start-a)%(end-start)==1 -> если end-start+1==3, то у (start-a)%(end-start) получаетс€ последовательность ...2,1,0,2,1,0,2,1

          ‘ормула (start-a-1)%(end-start) даЄт последовательность чисел, котора€ заканчиваетс€ нулЄм
          - когда a на 1 меньше start  (start-a-1)%(end-start)==0 -> если end-start+1==3, то у (start-a-1)%(end-start) получаетс€ последовательность ...1,0,2,1,0,2,1,0

        */
        circled_a = end - (start-a-1)%(end-start+1);
    }
    else
    {
        circled_a = start + (a-start)%(end-start+1);
    }
    return circled_a;
}

int encode_int(int a, int shift)
{
    int encoded_a;
    if (('A'<=a) && (a<='Z'))
    {
        encoded_a = circle(a+shift, (int) 'A', (int) 'Z');
    }
    else if (('a'<=a) && (a<='z'))
    {
        encoded_a = circle(a+shift, (int) 'a', (int) 'z');
    }
    else
    {
        encoded_a = a;
    }
    return encoded_a;
}

void *encode(char *file_name_in, char *file_name_out, int shift)
{
    FILE *file_in = fopen(file_name_in, "r");
    FILE *file_out = fopen(file_name_out, "w");
    char encoded_char;
    size_t n = 0;
    int c;
    long f_size;

    if (file_in == NULL) return NULL;


    fseek(file_in, 0, SEEK_END);
    f_size = ftell(file_in);
    fseek(file_in, 0, SEEK_SET);

    while ((c = fgetc(file_in)) != EOF)
    {
        encoded_char = (char) encode_int(c, shift);
        fprintf(file_out,"%c", encoded_char);
    }

    fclose (file_out);
}

void decode(char *file_name_in, char *file_name_out, int shift)
{
    encode(file_name_in, file_name_out, -shift);
}

void help()
{
    printf("\nCommands\n");
    printf("  -encode [code] [file_to_encode] [encoded_file]\n");
    printf("  -decode [code] [file_to_decode] [decoded_file]\n");
    printf("  -help\n");
}

int main(int argc, char **argv)
{
    int shift;
    char *result;
    char *start_file;
    char *end_file;


    if (argc == 5)
    {
        sscanf(argv[2], "%d", &shift);
        start_file = argv[3];
        end_file = argv[4];
        if (strcmp(argv[1],"-encode") == 0)
        {
            encode(start_file, end_file, shift);
        }
        else if (strcmp(argv[1],"-decode") == 0)
        {
            decode(start_file, end_file, shift);
        }
        else
        {
            help();
        }
    }
    else
    {
        help();
    }

    return 0;
}
