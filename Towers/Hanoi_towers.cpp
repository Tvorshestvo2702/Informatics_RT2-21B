#include <Windows.h>
#include <conio.h>
#include <iostream.h>

#define BLUE 1
#define RED 4
#define GREEN 10
#define WHITE 15
#define FORWARD 1
#define BACKWARD -1
#define ESC 27
#define ENTER 13
#define PC 0
#define MYSELF 1
#define ZERO 10
#define ONE 11
#define TWO 12

HANDLE hConsole;
int ww;
int wh;
int who_solves = -1;

class cell
{
public:
    int number;
    int color;
    bool operator==(const cell& given)
    {
        return (this->number==given.number) & (this->color==given.color);
    }
    void operator=(const cell& given)
    {
        this->number = given.number;
        this->color = given.color;
    }
    friend std::ostream& operator<<(std::ostream& out, const cell& given)
    {
        return out << given.number << ' ' << given.color;
    }
};

void print_array(cell **arr, int size, int max_row_size)
{
    for(int i=0; i<size; i++){
        for(int j=0; j<max_row_size; j++){
            cout << arr[i][j].number << ", ";
        }
        cout << '\n';
        for(int j=0; j<max_row_size; j++){
            cout << arr[i][j].color << ", ";
        }
        cout << '\n' << '\n';
    }
}

// ��������� ������ �� ������� X, Y
void GoToXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;

    if (!SetConsoleCursorPosition(hConsole, coord))
    {
        cout << "error: " << coord.X << coord.Y << endl;
    }
}



void print_colored(char *text, int color)
{
    SetConsoleTextAttribute(hConsole, color);
    cout << text;
}

void update_win_sizes()
{
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    ww = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
    wh = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
}

void clear_frame()
{
    system ("CLS");
}

// ������ ���� �������, �������� � (height-cl.numer)*2+1
void draw_cell(cell cl,int height,int x,int y,char type)
{
    int thickness = height-cl.number+1;
    if (x-thickness>0)
    {
        int color;
        if (cl.number==0)
        {
            GoToXY(x,y);
            print_colored("|",GREEN);
            // ���� ��������� ������ - ��, �� ��� ��������� � ������ ������ ����� (������)
            if (cl.color == 1)
            {
                GoToXY(x,y-2);
                print_colored("|",GREEN);
                GoToXY(x-1,y-1);
                print_colored("\ /",GREEN);
            }
        }
        else
        {
            GoToXY(x-thickness,y);
            if (cl.color==1)
            {
                color = BLUE;
            }
            else
            {
                color = RED;
            }
            for(int i=0;i<thickness*2+1;i++)
            {
                print_colored("#",color);
            }
        }
    }
}

void update_frame(cell **arr,int height,int max_row_size,int counter,char type)
{
    // ������� �����
    //int counter = 0;
    clear_frame();
    update_win_sizes();
    GoToXY(0,0);

    // ����� ������� �����
    if (who_solves==MYSELF)
    {
        print_colored("��� ������ ����� ������� - '1', '2', '3'", GREEN);
        cout << '\n';
        cout << "��� ������ ������ ��� ������ ������� - 'Esc'";
    }
    else
    {
        print_colored("��� ��������� ����� ��� ������ ������� - 'Enter'", GREEN);
        cout << '\n';
        cout << "��� ��������� ����� ��� ������ ������� - 'Esc'";
    }

    /*
      ������ ��������� ��������� ����� �� Y, ������� ������; ��� ��������� - (���������� ����� �� ������� ������ "-" (����������� ������ "+"
      ������ ������� ������ 2�)),
      ��� 6 (����� ������ � �����)
    */
    int tower_y = max(6,wh-6-height);

    // ������ �������� �� �������; ���� ������� ��������� � 1/4, 2/4, 3/4 ������, �� ������ ��������
    for(int y=0;y<max_row_size;y++){
        GoToXY(0,y);
        for(int x=1;x<ww;x++)
        {
            if ((x%(ww/4)==0) && (x/(ww/4)<=3))
            {
                //GoToXY(x-1,tower_y+y);
                //cout << "|";
                //cout << "x/(ww/4) " << x/(ww/4) << " y: " << y;
                draw_cell(arr[x/(ww/4)-1][y],height,x-1,tower_y+height-1-y,type);
            }
        }
    }
    //int bottom_y = max(wh-2,);
    GoToXY(0,tower_y+height+1);
    print_colored("���������� �����: ", GREEN);
    cout << counter;
}

void show_victory()
{
    char *victory = "������";
    int ln = 6;
    int th = 1;
    for(int y=0;y<3;y++)
    {
        GoToXY(ww/2-ln/2-th,wh/2-th+y);
        for(int x=0;x<ln+th*2;x++)
        {
            print_colored("#",GREEN);
        }
    }
    GoToXY(ww/2-ln/2,wh/2);
    print_colored(victory,WHITE);
}



/*
  �������� ������ arr1 � arr2;
  ����:
    - arr1 - ������� ������
    - arr2 - �������� ������
    - height - ������ ����� (������������)
*/
void copy_array(cell **arr1, cell **arr2, int height)
{
    for(int x=0;x<3;x++){
        for(int y=0;y<height;y++){
            arr2[x][y] = arr1[x][y];
        }
    }
}

// ���������� -1, ���� ������ Esc � +1, ���� Enter; ������ ��� ���������
int navigating()
{
    int where_to_go = -10;
    while (where_to_go == -10)
    {
        char key = getch();
        if (who_solves == PC)
        {
            if (key==ESC){
                where_to_go = BACKWARD;
            }
            else if (key==ENTER){
                where_to_go = FORWARD;
            }
        }
        else
        {
            if (key==ESC){
                where_to_go = BACKWARD;
            }
            else if (key=='1'){
                where_to_go = 0;
            }
            else if (key=='2'){
                where_to_go = 1;
            }
            else if (key=='3'){
                where_to_go = 2;
            }
        }
    }
    return where_to_go;
}

class history_list
{
public:
    unsigned int counter;
    unsigned int done_steps_counter;
    unsigned int height;
    unsigned int max_row_size;
    cell ***moves;
    cell *moved_cells;
    unsigned int len;
    void create_history(cell **arr, int height, int max_row_size)
    {
        // bicolor(10) - 12195 �����
        // magnetic(10)- 29268 �����
        len = 100000;
        this->max_row_size = max_row_size;
        this->height = height;
        moves = new cell**[len];
        for(int i=0;i<len;i++){
            moves[i] = new cell*[3];
            for(int j=0;j<3;j++){
                moves[i][j] = new cell[max_row_size];
            }
        }
        moved_cells = new cell[len];
        counter = 0;
        set_start_array(arr);
    }
    /*
      - � ������ ����� ���������� ��������� ������, �� ����� �� ������� �����
    */
    void set_start_array(cell **arr)
    {
        copy_array(arr,moves[0],max_row_size);
    }
    /*
      - ��������� ����� ������ arr (��������� �����) � ������������ ������� move (������� ��������� (���������) �����)
      - ����������� ������� ��������
    */
    void append(cell **arr, cell who_moves)
    {
        counter++;
        done_steps_counter++;
        copy_array(arr,moves[counter],max_row_size);
        moved_cells[counter] = who_moves;
    }
    /*
      �������� �� �����������
      - ��������� ����� ��� � �������, �� ����� ����:
      -- ������ ��������� ����� ��� � �������, ������ ����� ���� �� �����, ���� ������� ����� �� ���� ����������
      -- ������� ����������� ���, ���� �� ��� ����������
      ������� ������:
      ����. ���:
       2-1  |   |
       2-0  |   |
       1-0 1-1  |   2-1 ���������� �� 2� ����� �� 1�
      ������� ���:
        |   |   |
       2-0  |   |
       1-0 1-1 2-1  2-1 ���������� � 1� ����� �� 2�
      2 ���� ������ �������� 1� ������ - ����������
      - ��������� ������� ����� -> ������ ������� ����� �� ���������� ����, ��� ������������� ������� append �� �������������
      - ������ ����� ��� � �������
    */
    void append_no_useless(cell **arr, cell who_moves)
    {
        if (counter>=1){
            if (who_moves==moved_cells[counter])
            {
                counter--;
            }
        }
        append(arr, who_moves);
    }
    void print()
    {
        for(int i=0;i<=counter;i++)
        {
            cout << "----------" << '\n';
            print_array(moves[i],3,height);
            cout << "-" << '\n';
            cout << moved_cells[i] << '\n';
            cout << "----------" << '\n';
        }
    }
    void draw(type)
    {
        int i=0;
        while (i<=counter)
        {
            update_frame(moves[i],height,max_row_size,i,type);
            if (i==counter){
                show_victory();
            }
            i += navigating();
        }
    }
};

history_list history;

// ������� ����� from, ����������� �� ������ from_i, �������� ������� � ��������� ����� to, ����������� �� ������ to_i
void swap_cell_elem(cell **arr, int from, int from_i, int to, int to_i)
{
    cell per = arr[from][from_i];
    arr[from][from_i] = arr[to][to_i];
    arr[to][to_i] = per;
}

/*
  ���� ��������� �������� ����� from � ������� ����� to � ������������� ������� ������� � from �� to
  ������:
  - arr
    |   |   |
   2-0 2-1  |
   1-0 1-1  |
  - from = 1
  - to = 0
  - arr ����� ������ ���������
   2-1  |   |
   2-0  |   |
   1-0 1-1  |
*/
void move_cell(cell **arr, int from, int to)
{
    int from_i = 0;
    int i = 0;
    while (arr[from][i].number != 0)
    {
        from_i = i;
        i += 1;
    }
    int to_i = 0;
    i = 0;
    while (arr[to][i].number != 0)
    {
        i += 1;
        to_i = i;
    }

    if (who_solves==PC)
    {
        swap_cell_elem(arr,from,from_i,to,to_i);
        history.append_no_useless(arr,arr[to][to_i]);
    }
    else
    {
        // ! ���������� �������
        // ���� ������ ������ <= ������� �����, ���� ��� ��� (! ������ = ������-�����+1), ��� ����� �����, �� �����������
        if (to_i!=0)
        {
            if ((arr[from][from_i].number>=arr[to][to_i-1].number) || (arr[to][to_i-1].number == 0))
            {
                swap_cell_elem(arr,from,from_i,to,to_i);
                history.append(arr,arr[to][to_i]);
            }
        }
        else
        {
            swap_cell_elem(arr,from,from_i,to,to_i);
            history.append(arr,arr[to][to_i]);
        }
    }
}

// ������ ���� ����� �� � move + ������ ���� ������������� ������ �� ���������������
void move_magnetic_cell(cell **arr, int from, int to)
{
    int from_i = 0;
    int i = 0;
    while (arr[from][i].number != 0)
    {
        from_i = i;
        i += 1;
    }
    int to_i = 0;
    i = 0;
    while (arr[to][i].number != 0)
    {
        i += 1;
        to_i = i;
    }

    if (who_solves==PC)
    {
        swap_cell_elem(arr,from,from_i,to,to_i);
        arr[to][to_i].color = (arr[to][to_i].color != 1);
        history.append_no_useless(arr,arr[to][to_i]);
    }
    else
    {
        // ! ���������� �������
        // ���� ������ ������ <= ������� �����, ���� ��� ��� (! ������ = ������-�����+1), ��� ����� �����, �� �����������
        // � ���������� ������ � ����� �� ���������
        print_array(arr,3,4);
        if (to_i!=0)
        {
            if (((arr[from][from_i].number>=arr[to][to_i-1].number) || (arr[to][to_i-1].number == 0)))
            {
                if (arr[from][from_i].color!=arr[to][to_i-1].color)
                {
                    swap_cell_elem(arr,from,from_i,to,to_i);
                    arr[to][to_i].color = (arr[to][to_i].color != 1);
                    history.append(arr,arr[to][to_i]);
                }
            }
        }
        else
        {
            swap_cell_elem(arr,from,from_i,to,to_i);
            arr[to][to_i].color = (arr[to][to_i].color != 1);
            history.append(arr,arr[to][to_i]);
        }
    }
}


// �������� ������ ������� arr (������ - ���-�� �� ������� ���������, ������ ������ � ����)
int get_len(cell *arr)
{
    int elem = 0;
    int i = 0;
    while (arr[i].number != 0)
    {
        i += 1;
    }
    return i;
}




/*
  ������������ �����
*/
// ������� ��������� ����� ����� ��������
void solve_hanoi(cell **arr, int height, int s, int t, int u, int n)
{
    if (n == 1)
    {
        move_cell(arr,s,t);
    }
    else
    {
        solve_hanoi(arr,height,s,u,t,n-1);
        move_cell(arr,s,t);
        solve_hanoi(arr,height,u,t,s,n-1);
    }
}

void solve_simple_hanoi(cell **arr, int height, int s, int t, int u)
{
    solve_hanoi(arr, height, s, t, u, height);
}



/*
  ������� �����
*/

/*
  ������ ��������� ����������� ��������� ����� �� ����������� ��������� �����
    - ������ ������������ �������� �������:
        3-1  |   |
        3-0  |   |
        2-1  |   |
        2-0  |   |
        1-1  |   |
        1-0  |   |
        ��� 0 - ���� ����, 1 - ������
  �� ����:
    * ������ � �������
    * ������ ����� / 2 (���-�� ��������� ���������)
    * ����� ��������� ����� (� ����)
    * ����� ������� �����
    * ������ ��� - ������ ����� / 2 (���-�� ��������� ���������)
  - ������ ������������ �������� ������� � s=0, t=2:
         |   |  3-1
         |   |  3-0
         |   |  2-1
         |   |  2-0
         |   |  1-0
         |   |  1-1
*/
void DoubleTowersOfHanoi(cell **arr, int height, int s, int t, int u, int n)
{
    if (n == 1)
    {
        move_cell(arr,s,t);
        move_cell(arr,s,t);
    }
    else if (n != 0)
    {
        DoubleTowersOfHanoi(arr,height,s,u,t,n-1);
        move_cell(arr,s,t);
        move_cell(arr,s,t);
        DoubleTowersOfHanoi(arr,height,u,t,s,n-1);
    }
}


/*
  ������ ��������� ����������� ��������� ����� �� �������� ����� ��� ��������������� ������� ��������
    - ������ ������������ �������� �������:
        3-1  |  |
        3-0  |  |
        2-1  |  |
        2-0  |  |
        1-1  |  |
        1-0  |  |
        ��� 0 - ���� ����, 1 - ������
  �� ����:
    * ������ � �������
    * ���-�� �����
    * ������ �����
    * ����� ��������� ����� (� ����)
    * ����� ������� �����
  ������� ������:
    �.�. ��� ����� �� �������� ����� � ������� ��������� ������ - ��������� ������ �������, �� ����� ���������� ������ �� ���� ���������� ������
  ������ �������� � ��������� ������� � s=0, t=1, u=2:
    3-1  |  |      |  3-1  |
    3-0  |  |      |  3-0  |
    2-1  |  |      |  2-1  |
    2-0  |  |      |  2-0  |
    1-1  |  |      |  1-1  |
    1-0  |  |      |  1-0  |
    ���������� ���������� ���������, �� � ������ ������������� �� �� ������� ��������, ��� ������ ������ ����������������, � ����� �� �������, ���
    �������� ���������������� � ������������ � �����
    (1 ��� - S-��������� ��������, U-������� ��������, T-����������
     2 ��� - U-��������� ��������, T-������� ��������, S-����������)
*/
void EnhancedDoubleTowersOfHanoi(cell **arr, int height, int s, int t, int u)
{
    DoubleTowersOfHanoi(arr,height/2,s,u,t,height/2);
    if (height%2==1)
    {
        move_cell(arr,s,t);
    }
    DoubleTowersOfHanoi(arr,height/2,u,t,s,height/2);
}


/*
  ������ ��������� ����������� ��������� ����� �� ����� 2 ����� � 1
    - ������ ������������ �������� �������:
        3-0  3-1  |
        2-0  2-1  |
        1-0  1-1  |
        ��� 0 - ���� ����, 1 - ������
  �� ����:
    * ������ � �������
    * ������ ��������� ����� (������ ���_����� / ���-�� ��������� ���������)
    * ����� ������ ����� (� ����)
    * ����� ������ �����
    * ���������� �����
  ������� ������:
    - ������� ������������ ������� ������ ������ ����� �� ������ (� T �� S)
        - � ������� ������ ������������ ������������ ����� �� ���� (4�,6� � ��) ��������� ������������ �� ���������
        - ������������ ������� ������ ������ ����� �� ������ (� T �� S), ��� �� ���������� ��� ����� �� 2� (4�,6� � ��) ��������
        - � ����������� ������ ������������� ������ ����� �� 2 ��������� �� ������, ���������� ����� �� 4� (6�,8� � ��) ���������
    - ��������� ���� ������� ���, ������� ��������� � ����� ���_����� ����������, ��� �� ������� ����������� ��������� ������� �����
    -> ����������� �����
    -> ����������� ������� ������� �� ������ �� ������, ���-�� �������� � ��� 2 ��������
    -> � ����� ���������� ������� �� ������������ �������
    -> � �� �����
*/
void MergeProblem(cell **arr, int sub_height, int s, int t, int u)
{
    move_cell(arr, t, s);
    for(int step=1;step<sub_height;step++)
    {
        DoubleTowersOfHanoi(arr, step, s, u, t, step);
        move_cell(arr, t, s);
        DoubleTowersOfHanoi(arr, step, u, s, t, step);
    }
}


/*
  ������ ��������� ����������� ��������� ����� �� ������� 1 ����� �� 2 �����
    - ������ ������������ �������� �������:
        3-1  |  |
        3-0  |  |
        2-0  |  |
        2-1  |  |
        1-1  |  |
        1-0  |  |
        ��� 0 - ���� ����, 1 - ������
  �� ����:
    * ������ � �������
    * ������ ����� - ������ ������ 2�
    * ����� ������ ����� (� ����)
    * ����� ������ �����
    * ���������� �����
  ������� ������:
    - ������������� ��� ����� �� ������ ������� � ����������� ������� ������ ��������� (EDToH, ������ �� ��������� 2 ������ �������, � �� ������ �� �������)
        |  3-1  |
        |  3-0  |
        |  2-0  |
        |  2-1  |
        |  1-1  |
        |  1-0  |
        - ���������, ���� step<height/2:
        -- ������������� ����� �� height-step*2-1 (step=0) ��������� �� 2�� ������ �� ��������� ������� (���� step%2=0)
            3-1  |  |
            3-0  |  |
            2-0  |  |
            2-1  |  |
            1-1 1-0 |
        -- ������������� ����� �� height-step*2-1 (step=1) ��������� � ��������� ������� �� 2� ����� (�����)
             |  3-1 |
             |  3-0 |
            2-1 2-0 |
            1-1 1-0 |
  ������ ������������ ��������� �������:
        3-0  3-1  |
        2-0  2-1  |
        1-0  1-1  |
*/
void Disassamble(cell **arr, int height, int s, int t, int u)
{
    EnhancedDoubleTowersOfHanoi(arr,height,s,t,u); //s->t
    for(int step=0;step<height/2;step++)
    {
        if ((step%2)==0){
            EnhancedDoubleTowersOfHanoi(arr,height-step*2-1,t,s,u); //t->s
        }
        else{
            EnhancedDoubleTowersOfHanoi(arr,height-step*2-1,s,t,u); //s->t
        }
    }
}

void solve_bicolor_hanoi(cell **arr, int height, int s, int t, int u)
{
    MergeProblem(arr,height  ,s, t, u);
    Disassamble (arr,height*2,s, t, u);
}



/*
  ��������� �����
*/

/*
  ��������� ����� - ���������� ����, ��� ��������� ����� ������������� ����� (������)
  �������������� BRB - ��� S - �������������, U - �������������, T - �������������
*/
void BRB(cell **arr, int s, int t, int u, int n)
{
    if (n==1)
    {
        move_magnetic_cell(arr,s,u);
        move_magnetic_cell(arr,u,t);
    }
    /*
      ���� �� ��������� ������� ������ ����� 2�, �� ��� ������, ��� ����� 1� (������� �� ������� ������) ������� ���� �� ������� �����, � 2� �� �������� �����,
      �� ��������� ������� ������ ����� N (�����) � �� �� ����� ����� �������� �������� R (�������������) �������, ������� �� ����������� �� � S �� T ������
      ����� �������������
      (��� -, �������� �� S ���� +, ������� ���� -)
    */
    else if ((n==2) && (get_len(arr[s])==2))
    {
        BRB(arr,s,t,u,n-1);
        move_magnetic_cell(arr,s,u);
        move_magnetic_cell(arr,t,s); // BRN
        move_magnetic_cell(arr,u,t);
        move_magnetic_cell(arr,s,t); // NRB (RRB)
    }
    else
    {
        BRB(arr,s,t,u,n-1);             // ����������� ����� n-1 � S �� T
        move_magnetic_cell(arr,s,u);
        BRB(arr,t,s,u,n-1);             // ����������� ����� n-1 � T �� S
        move_magnetic_cell(arr,u,t);
        BRB(arr,s,t,u,n-1);             // ���������� ������� n-1 � S �� T
    }
}

void RNN(cell **arr, int s, int t, int u, int n)
{
    if (n==1)
    {
        move_magnetic_cell(arr,s,t);
    }
    else
    {
        RNN(arr,s,u,t,n-1);
        move_magnetic_cell(arr,s,t);
        BRB(arr,u,t,s,n-1);
    }
}

void solve_magnetic_hanoi(cell **arr, int height, int s, int t, int u)
{
    RNN(arr,s,t,u,height);
}




/*
  ������������� ������������ ��������� �����
  - ��������� ����� s ��������� ������� �������� �� 1 �� height, ����� 0
  - � ����� ������ ����� ������ ������ ���� ������ (�������) ������, ����� ��� ������ �������, ��� �� �� ���������� ������ ������ ��� ����� ���������
*/
void init_classic(cell **arr, int height, int s, int t)
{
    for(int i=0; i<height; i++){
        arr[s][i].number = i+1; // +1
        arr[s][i].color = 0;
    }
}


/*
  ������������� ����������� ��������� �����
  - ��������� ����� s ������������� ������� (0 - ���� ������� �����/������)
  - ��������� ����� t ������������� ������� (1 - ���� ������� �����/������)
*/
void init_bicolor(cell **arr, int height, int s, int t)
{
    for(int i=0; i<height; i++){
        arr[s][i].number = i+1;
        arr[s][i].color = 1-i%2;
    }

    for(int i=0; i<height; i++){
        arr[t][i].number = i+1;
        arr[t][i].color = i%2;
    }
}

void init_magnetic(cell **arr, int height, int s, int t)
{
    init_classic(arr,height,s,t);
}


bool check_win(cell **arr, int height, int s, int t, int u, char type)
{
    bool fl = false;
    if (type=='c')
    {
        if (get_len(arr[t])==height)
        {
            fl = true;
        }
    }
    else if (type=='b')
    {
        if ((get_len(arr[s])==height) && (get_len(arr[t])==height))
        {
            fl = true;
            //cout << height;
            for(int i=0;i<height;i++)
            {
                fl = fl && (arr[s][i].color==0);  // ��� �� ������ �� ������� ������ ����� 0 (���������������� ����������)
                fl = fl && (arr[t][i].color==1);  // ���������� ������ �����
                //cout << endl << (arr[t][i].color==1);
            }
        }
    }
    else
    {
        if (get_len(arr[t])==height)
        {
            fl = true;
            for(int i=0;i<height;i++)
            {
                fl = fl && (arr[t][i].color==1);  // ��� �� ������ �� �������� ������ ��������� ������� ����� (������� ������)
            }
        }
    }
    return fl;
}



int main()
{
    // �������� ���������� ������ ���� (����� ������ �� ����), ��� �� � ���������� �� ���������� (������ ���� �������/���������� ���/�������� ������ ���� � ��������)
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // ��� ����, ��� �� �������� �������
    SetConsoleOutputCP(1251);
    int height = 1;
    int s;
    int t;
    int u;
    char type = 'n';

    cell **cols;


    // ������� ���
    int in;
    GoToXY(0,0);
    print_colored("�������� ���\n'1' - ������������, '2' - �����������, '3' - ���������\n",GREEN);
    while (type=='n')
    {
        cin >> in;
        if (in==1)
        {
            type = 'c';
        }
        else if (in==2)
        {
            type = 'b';
        }
        else if (in==3)
        {
            type = 'm';
        }
    }

    clear_frame();
    GoToXY(0,0);
    print_colored("������� ������ �����\n\n",GREEN);
    cin >> height;

    clear_frame();
    GoToXY(0,0);
    print_colored("�������� ��� �������\n'1' - ���, '2' - ���������\n",GREEN);
    while (who_solves==-1)
    {
        cin >> in;
        if (in==1)
        {
            who_solves = MYSELF;
        }
        else if (in==2)
        {
            who_solves = PC;
        }
    }


    int max_row_size;
    if (type == 'b'){
        max_row_size = height*2+1;
        s = 0;
        t = 1;
        u = 2;
    }
    else{
        max_row_size = height+1;
        s = 0;
        u = 1;
        t = 2;
    }

    cols = new cell*[3];
    // ��������� ������������ 3 �� height (���-�� ����� �� ������+1), ���-�� ����� ��������� ����������������
    for(int i=0; i<3; i++){
        cols[i] = new cell[max_row_size];
        for(int j=0; j<max_row_size; j++){
            cols[i][j].number = 0;
            cols[i][j].color = 0;
        }
    }

    if (type=='c')
    {
        init_classic(cols, height, s, t);
        history.create_history(cols,height,max_row_size);
    }
    else if (type=='b')
    {
        init_bicolor(cols, height, s, t);
        history.create_history(cols,height,max_row_size);
    }
    else
    {
        init_magnetic(cols, height, s, t);
        history.create_history(cols,height,max_row_size);
    }

    if (who_solves == PC)
    {
        if (type=='c')
        {
            solve_simple_hanoi(cols,height,s,t,u);
        }
        else if (type=='b')
        {
            solve_bicolor_hanoi(cols,height,s,t,u);
        }
        else
        {
            solve_magnetic_hanoi(cols,height,s,t,u);
        }
        history.draw(type);
    }
    else
    {
        int from_to[2];
        // ���� �� �������
        while (!check_win(cols,height,s,t,u,type))
        {
            // �������� ��_���� ������ � �������, ��������� ��������
            from_to[0] = 0;
            from_to[1] = 0;
            update_frame(cols,height,max_row_size,history.done_steps_counter,type);
            // ���� ���� �� 1 ������� - ESC, ��� ������� ����� ���� �����,
            while ((from_to[0]==-1) || (from_to[1]==-1) || (from_to[0]==from_to[1]))
            {
                if (history.counter<0)
                {
                    cout << "NOO";
                    exit(1);
                }
                for(int i=0;i<2;i++)
                {
                    from_to[i] = navigating();
                    //cols[from_to[i]][max_row_size].color = 1;
                    if (from_to[i]==-1)
                    {
                        if (history.counter<=0)
                        {
                            exit(1);
                        }
                        from_to[0] = 0;
                        from_to[1] = 0;
                        history.counter-=1;
                        cols = history.moves[history.counter];
                        update_frame(cols,height,max_row_size,history.done_steps_counter,type);
                        break;
                    }
                }
            }
            if (type=='m')
            {
                move_magnetic_cell(cols,from_to[0],from_to[1]);
            }
            else
            {
                move_cell(cols,from_to[0],from_to[1]);
            }
        }
        update_frame(cols,height,max_row_size,history.done_steps_counter,type);
        show_victory();
        //check_win(cols,height,s,t,u,type);
        cin.get();
    }
    cin.get();
    return 0;
}
