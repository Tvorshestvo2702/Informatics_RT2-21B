#include <iostream>
#include <SFML/Graphics.hpp>
#include<conio.h>
#include <vector>

using namespace std;
using namespace sf;

int abra;

float rotation (int start, int finish, float base);
void set_active (int HOUR_activation);
void reload_activate_connections (int Hi, int reload);
float length_of_line(int start, int finish);
void Check_connectivity_funk(int st, int fin, int ot);
void Menu(int abra);

class HEAD {
public:
    float grad1 = 15;
    int HEAD_number;
    int connection[13];
    int flag_activ = 0;
    float gradient[13];
    float coordinate_x[13];
    float coordinate_y[13];
    float center_coordinate_x[13];
    float center_coordinate_y[13];

    HEAD *had[13];

    HEAD() {

        for (int i = 1; i <= 12; i++) {
            gradient[i] = grad1;
            grad1 += 30;
            connection[i] = 0;
        }
        coordinate_x[1] = 190;
        coordinate_y[1] = 90;
        center_coordinate_x[1] = 200;
        center_coordinate_y[1] = 100;

        coordinate_x[2] = 240;
        coordinate_y[2] = 100;
        center_coordinate_x[2] = 250;
        center_coordinate_y[2] = 110;

        coordinate_x[3] = 280;
        coordinate_y[3] = 140;
        center_coordinate_x[3] = 290;
        center_coordinate_y[3] = 150;

        coordinate_x[4] = 290;
        coordinate_y[4] = 190;
        center_coordinate_x[4] = 300;
        center_coordinate_y[4] = 200;

        coordinate_x[5] = 280;
        coordinate_y[5] = 240;
        center_coordinate_x[5] = 290;
        center_coordinate_y[5] = 250;

        coordinate_x[6] = 240;
        coordinate_y[6] = 280;
        center_coordinate_x[6] = 250;
        center_coordinate_y[6] = 290;

        coordinate_x[7] = 190;
        coordinate_y[7] = 290;
        center_coordinate_x[7] = 200;
        center_coordinate_y[7] = 300;

        coordinate_x[8] = 140;
        coordinate_y[8] = 280;
        center_coordinate_x[8] = 150;
        center_coordinate_y[8] = 290;

        coordinate_x[9] = 105;
        coordinate_y[9] = 240;
        center_coordinate_x[9] = 115;
        center_coordinate_y[9] = 250;

        coordinate_x[10] = 90;
        coordinate_y[10] = 190;
        center_coordinate_x[10] = 100;
        center_coordinate_y[10] = 200;

        coordinate_x[11] = 105;
        coordinate_y[11] = 140;
        center_coordinate_x[11] = 115;
        center_coordinate_y[11] = 150;

        coordinate_x[12] = 140;
        coordinate_y[12] = 100;
        center_coordinate_x[12] = 150;
        center_coordinate_y[12] = 110;
    }

    void activate(int activ) {
        HEAD_number = activ;
        flag_activ = 1;
    }
    void activate_connections(HEAD *endHEAD, int number) {
        had[number] = endHEAD;
    }

    void set_connection(int connect) {
        if (had[connect]->flag_activ == 1)
            connection[connect] = 1;
        else
            cout << "Wrong activation!" << endl;
    }
};

class HEAD_COLOR {
public:
    int x;
    int y;
    int z;

    void init(int a) {
        if ((a == 1) || (a == 7)) {
            this->x = 255;
            this->y = 0;
            this->z = 0;
        }
        if ((a == 2) || (a == 8)) {
            this->x = 251;
            this->y = 163;
            this->z = 26;
        }
        if ((a == 3) || (a == 9)) {
            this->x = 255;
            this->y = 255;
            this->z = 0;
        }
        if ((a == 4) || (a == 10)) {
            this->x = 0;
            this->y = 255;
            this->z = 0;
        }
        if ((a == 5) || (a == 11)) {
            this->x = 0;
            this->y = 0;
            this->z = 255;
        }
        if ((a == 6) || (a == 12)) {
            this->x = 128;
            this->y = 0;
            this->z = 128;
        }
    }
};

class Check_connectivity {
public:
    int con[13];
    int all_escape_loops = 0;
    Check_connectivity() {
        for (int i = 0; i < 13; ++i) {
            con[i] = 0;
        }
    }
};

HEAD *H[13];
HEAD_COLOR HC[13];
Check_connectivity CC[13];
int number_of_active_HEADS = 0;

int main(void)
{
    for (int i = 1; i < 13; ++i) {
        H[i] = new HEAD;
        HC[i].init(i);
    }

    cout << "Welcome home, baby!" << endl << endl << endl;
    Menu(abra);
}

float rotation(int start, int finish, float base) {
    float result = 0;
    float delta;
    delta = (float) abs (start - finish);
    if (finish > start)
        result = base + (delta - 1) * 15;
    if (finish < start)
        result = base + (11 - delta) * 15;
    return result;
}

float length_of_line(int start, int finish) {
    float length_line = 0;
    float delta_1;
    delta_1 = (float) abs(start - finish);
    if (delta_1 > 7)
        length_line = 55 + (11 - delta_1) * 45;
    if (delta_1 < 5)
        length_line = 55 + (delta_1 - 1) * 45;

    if (delta_1 == 4)
        length_line = 25 + (delta_1 - 1) * 45;
    if (delta_1 == 8)
        length_line = 25 + (11 - delta_1) * 45;

    if (delta_1 == 5)
        length_line = 10 + (delta_1 - 1) * 45;
    if (delta_1 == 7)
        length_line = 10 + (11 - delta_1) * 45;

    if (delta_1 == 6)
        length_line = 200;
    return length_line;
}

void set_active(int HOUR_activation) {
    for (int i = 1; i <= HOUR_activation; i++) {
        H[i]->activate(i);
        for (int j = 1; j <= HOUR_activation; j++) {
            reload_activate_connections(i, j);
        }
    }
}

void reload_activate_connections(int Hi, int reload) {
    while (reload > 0) {
        H[Hi]->activate_connections(H[reload], reload);
        reload_activate_connections(Hi, --reload);
    }
}

void enter_func(int st, int fin) {
    H[st]->set_connection(fin);
}

void Check_connectivity_funk(int st, int fin, int ot) {
    for (int i = st; i <= number_of_active_HEADS; ++i) {
        if (H[st]->connection[i] == 1){
            CC[ot].con[i] = 1;
            if (ot != i)
                Check_connectivity_funk(i, number_of_active_HEADS, ot);
        }
    }
}

void Menu(int abra) {
    int flag_menu = 0;
    int flag_1 = 0;
    while (flag_menu != 6)
    {
        system("cls");
        cout << endl << endl;
        cout << "   THIS IS " << endl;
        cout << "    MENU    " << endl << endl ;
        cout << "1. Enter number of active hops" << endl;
        cout << "2. Enter new orient connection" << endl;
        cout << "3. Enter new not orient connection" << endl;
        cout << "4. Display all we have" << endl;
        cout << "5. Check connectionly" << endl;
        cout << "6. I will be back!" << endl;
        cin >> flag_menu;
        cout << endl;

        if (flag_menu == 1) {
            system("cls");
            cout << "Please, set number of active hops. " << endl << "I need a number from 1 to 12" << endl;
            cout << "P.S. Yes, this one loves CLOCKS." << endl;
            cin >> number_of_active_HEADS;
            cout << " Thank you very much!" << endl;
            if ( (number_of_active_HEADS >= 0) && (number_of_active_HEADS <=12)) {
                set_active(number_of_active_HEADS);
                flag_1 = 1;
                if (number_of_active_HEADS == 0) {
                    for (int i = 1; i <= 12; ++i) {
                    for (int j = 1; j <= 12; ++j) {
                        H[i]->connection[j] = 0;
                    }
                }
            }
            }
            else {
                cout << "It wants number from 0 to 12" << endl;
            }
        }

        if ((flag_menu == 2) && (flag_1 != 0)) {
            int CLOCK_IS_GOIN_ON = 0;
            int WORK_DAY_END = 0;
            system("cls");
            cout << "Enter start hop:" << endl;
            cin >> CLOCK_IS_GOIN_ON;
            if ((CLOCK_IS_GOIN_ON <= number_of_active_HEADS) && (CLOCK_IS_GOIN_ON > 0)) {
                cout << "Enter finish hop number:" << endl;
                cin >> WORK_DAY_END;
                if ((WORK_DAY_END <= number_of_active_HEADS) && (WORK_DAY_END > 0)) {
                    enter_func(CLOCK_IS_GOIN_ON, WORK_DAY_END);
                }
                else {
                   cout << "Enter finish hop number:" << endl;
                }}
            else {
                 cout << "Enter start hop:" << endl;
            }
        }

        if ((flag_menu == 3) && (flag_1 != 0)) {
            int CLOCK_IS_GOIN_ON = 0;
            int WORK_DAY_END = 0;
            system("cls");
            cout << "Enter start hop:" << endl;
            cin >> CLOCK_IS_GOIN_ON;
            if ((CLOCK_IS_GOIN_ON <= number_of_active_HEADS) && (CLOCK_IS_GOIN_ON > 0)) {
                cout << "Enter finish hop number:" << endl;
                cin >> WORK_DAY_END;
                if ((WORK_DAY_END <= number_of_active_HEADS) && (WORK_DAY_END > 0)) {
                    if (CLOCK_IS_GOIN_ON != WORK_DAY_END) {
                    enter_func(CLOCK_IS_GOIN_ON, WORK_DAY_END);
                    enter_func(WORK_DAY_END, CLOCK_IS_GOIN_ON);
                }
                else
                {
                    cout << "Mission impossible in this mode!" << endl;
                }
                }
                else {
                        cout << "Enter finish hop number:" << endl;
                }
            }
            else {
                 cout << "Enter start hop:" << endl;
            }
            }




        if (flag_menu == 4) {
            system("cls");
            cout << "CLOSE THE WINDOW!" << endl;
            cout << "JUST DO IT !!!" << endl;

            RenderWindow window(sf::VideoMode(400, 400), "Don't touch it!");
            //description of basic forms
            RectangleShape line(sf::Vector2f(200.f, 2.f));
            CircleShape main_circle(100.f);
            main_circle.setFillColor(Color::White);
            CircleShape l[13];// (10.f);
            CircleShape x[13];// (10.f);
            for (int i = 1; i < 13; ++i)
            {
                x[i].setRadius(10.f);
                x[i].setFillColor(Color(HC[i].x, HC[i].y, HC[i].z));
                l[i].setRadius(20.f);
                l[i].setFillColor(Color::Transparent);
                l[i].setOutlineColor(Color(HC[i].x, HC[i].y, HC[i].z));
                l[i].setOutlineThickness(2);
            }

            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                window.clear();
                main_circle.setPosition(100, 100);

                for (int i = 1; i <= number_of_active_HEADS; ++i) {
                    for (int j = 1; j <= number_of_active_HEADS; ++j) {
                        //lightening loops
                       if ((i == j) && (H[i]->connection[j] == 1) ){
                            l[i].setPosition((H[i]->center_coordinate_x[i]-20), (H[i]->center_coordinate_y[i]-20));
                            window.draw(l[i]);
                        }

                        // 1 <-> 2
                        if ((H[i]->connection[j] == 1) && (H[i]->had[j]->connection[i] == 1) && (i < j)) {
                            line.setFillColor(sf::Color(HC[i].x, HC[i].y, HC[i].z));
                            line.setOutlineColor(sf::Color(HC[j].x, HC[j].y, HC[j].z));
                            line.setOutlineThickness(2);
                            line.setPosition(H[i]->center_coordinate_x[i], H[i]->center_coordinate_y[i]);
                            line.setSize(sf::Vector2f(length_of_line(i, j), 2.f));
                            line.rotate(rotation(i, j, H[i]->gradient[i]));
                            window.draw(line);
                            line.rotate(-rotation(i, j, H[i]->gradient[i]));
                        }
                        // 1 ->  2
                        if ((H[i]->connection[j] == 1) && (H[i]->had[j]->connection[i] == 0) && (i != j)) {
                            line.setFillColor(sf::Color(HC[i].x, HC[i].y, HC[i].z));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setOutlineThickness(2);
                            line.setPosition(H[i]->center_coordinate_x[i], H[i]->center_coordinate_y[i]);
                            line.setSize(sf::Vector2f(length_of_line(i, j), 2.f));
                            line.rotate(rotation(i, j, H[i]->gradient[i]));
                            window.draw(line);
                            line.rotate(-rotation(i, j, H[i]->gradient[i]));
                        }
                    }
                }

                for (int i = 1; i <= number_of_active_HEADS; ++i)
                {
                    x[i].setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                    window.draw(x[i]);
                }

                window.display();
            }
        }

        if (flag_menu == 5) {
            system("cls");
            cout << "Only for not orient graf!" << endl;
            int connection_counter = 1;
            int flag_stay_alone = 0;
            int grade = 0;
            int summ = 0;

            for (int i = 1; i <= number_of_active_HEADS; ++i) {
                for (int j = 1; j <= number_of_active_HEADS; ++j) {
                    if (i != j) {
                        connection_counter += H[i]->connection[j];
                    }
                }
                CC[i].all_escape_loops = connection_counter;
                connection_counter = 0;
                summ += connection_counter;
                if (CC[i].all_escape_loops == 0) {
                    flag_stay_alone = 1;
                    cout << "Hop " << i << " is stay alone." << endl;
                }
            }

            if ((flag_stay_alone == 0) && (((number_of_active_HEADS -1)*(number_of_active_HEADS - 2))/2) >= summ) {
                cout << "Connect graf " << endl;
            }
            if ((flag_stay_alone == 0) && (summ >= (number_of_active_HEADS*number_of_active_HEADS - number_of_active_HEADS/2))) {
                cout << "Full connect graf " << endl;
            }

            cout << "enter your grade" << endl;
            cin >> grade;
        }

        if (flag_menu == 6) {
            system("cls");
            cout << "I will be back!" << endl;
            cout << "                 C TERMINATOR" << endl;
        }

        if ((flag_menu != 1) && (flag_menu != 2) && (flag_menu != 3) && (flag_menu != 4) && (flag_menu != 5) && (flag_menu != 6)) {
            cout << "Lets try again!!!" << endl;
        }
    }
}
