#include <iostream>
#include <SFML/Graphics.hpp>
#include<conio.h>
using namespace std;
using namespace sf;

float rotation (int start, int finish, float base);
void set_active (int HOUR_activation);
void reload_activate_connections (int Hi, int reload);
void Menu();

class HEAD {

public:
    float grad1 = 15;
    HEAD() {
        for (int i = 0; i <= 12; i++) {
            gradient[i] = grad1;
            grad1 += 30;
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
        coordinate_y[5] = 140;
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

    HEAD *had[13];
    int HEAD_number;
    int connection [13];
    int flag_activ = 0;
    float gradient[13];
    float coordinate_x[13];
    float coordinate_y[13];
    float center_coordinate_x[13];
    float center_coordinate_y[13];


    void activate(int activ) {
        HEAD_number = activ;
        flag_activ = 1;
    }
    void activate_connections(HEAD* endHEAD, int number) {
        had[number] = endHEAD;
    }
    void set_connection(int connect) {
        if (had[connect]->flag_activ == 1)
            connection[connect] == 1;
        else
            cout << "Wrong activation!" << endl;
    }
};

HEAD *H[13];
int number_of_active_HEADS = 0;

int main()
{
    for (int i = 0; i <= 12; i++) {
        H[i] = new HEAD;
    }


    cout << "Welcome home, baby!" << endl << endl << endl;
    Menu();
        /*
        //lines
        float x = 150;
        float y = 290;
        float current = 8;
        float next = 2;
        float gradA = 225;
        //Это надо проверять графику
        //diam
        next = 2 ;
        sf::RectangleShape line(sf::Vector2f(200.f, 2.f));
        line.setFillColor(sf::Color::Magenta);
        line.setPosition(x, y);
        line.rotate(rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));


        //x10->x11
        next = 9;
        line.setSize(sf::Vector2f(55.f, 2.f));
        line.setFillColor(sf::Color::Blue);
        line.setPosition(x, y);
        line.rotate(rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));
        //x10 -> x9
        next = 7;
        line.setSize(sf::Vector2f(55.f, 2.f));
        line.setFillColor(sf::Color::Cyan);
        line.setPosition(x, y);
        line.rotate(+rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));
        //x10 -> x12
        next = 10;
        line.setSize(sf::Vector2f(100.f, 2.f));
        line.setFillColor(sf::Color::Green);
        line.setPosition(x, y);
        line.rotate(rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));
        //x10 -> x8
        next = 6;
        line.setSize(sf::Vector2f(100.f, 2.f));
        line.setFillColor(sf::Color::Green);
        line.setPosition(x, y);
        line.rotate(rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));
        //x10 -> x1
        next = 11;
        line.setSize(sf::Vector2f(145.f, 2.f));
        line.setFillColor(sf::Color::Green);
        line.setPosition(x, y);
        line.rotate(rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));
        //x10 -> x7
        next = 5;
        line.setSize(sf::Vector2f(145.f, 2.f));
        line.setFillColor(sf::Color::Green);
        line.setPosition(x, y);
        line.rotate(rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));
        //x10 -> x2
        next = 12;
        line.setSize(sf::Vector2f(185.f, 2.f));
        line.setFillColor(sf::Color::Green);
        line.setPosition(x, y);
        line.rotate(rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));
        //x10 -> x6
        next = 4;
        line.setSize(sf::Vector2f(185.f, 2.f));
        line.setFillColor(sf::Color::Green);
        line.setPosition(x, y);
        line.rotate(rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));
        //x10 -> x3
        next = 1;
        line.setSize(sf::Vector2f(205.f, 2.f));
        line.setFillColor(sf::Color::Green);
        line.setPosition(x, y);
        line.rotate(rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));
        //x10 -> x5
        next = 3;
        line.setSize(sf::Vector2f(205.f, 2.f));
        line.setFillColor(sf::Color::Green);
        line.setPosition(x, y);
        line.rotate(rotation(current, next, gradA));
        window.draw(line);
        line.rotate(-rotation(current, next, gradA));
        */
    }

float rotation(int start, int finish, float base) {
    float result = 0;
    float delta;
    delta = abs (start - finish);
    if (finish > start)
        result = base + (delta - 1) * 15;
    if (finish < start)
        result = base + (11 - delta) * 15;
    return result;
}

float length_of_line(int start, int finish) { //опасная функция
    float length_line = 0;
    float delta_l;
    delta_l = abs (start - finish);
    if (delta_1 > 6)
        length_line = 200 - (delta_1 - 6) * 45;
    if (delta_1 < 6)
        length_line = 55 + (delta_1 - 1) * 45;
     if (delta_1 == 6)
        length_line = 200;
    return length_line;


}

void set_active(int HOUR_activation) {
    for (int i = 0; i <= HOUR_activation; i++) {
        H[i]->activate(i);
    }
    for (int i = 0; i <= HOUR_activation; i++) {
        reload_activate_connections(i, i);
    }
}

void reload_activate_connections(int Hi, int reload) {
    while (reload >= 0) {
        H[Hi]->activate_connections(H[reload], reload);
        reload_activate_connections(Hi, reload--);
    }
}

void enter_func(int st, int fin) {
    H[st]->set_connection(fin);
}

void Menu() {
    int flag_menu = 0;
    while (flag_menu != 4)
    {
        system("cls");
        cout << "1. Enter number of active hops" << endl;
        cout << "2. Enter new connection" << endl;
        cout << "3. Display all we have" << endl;
        cout << "4. I will be back!" << endl;
        cin >> flag_menu;
        cout << endl;

        if (flag_menu == 1) {
            system("cls");
            cout << "Please, set number of active hops. " << endl << "I need a number from 1 to 12" << endl;
            cout << "P.S. Yes, this one loves CLOCKS." << endl;
            cin >> number_of_active_HEADS;
            cout << " Thank you very much!" << endl;
            set_active(number_of_active_HEADS);
        }

        if (flag_menu == 2) {
            int CLOCK_IS_GOIN_ON = 0;
            int WORK_DAY_END = 0;
            system("cls");
            cout << "Enter start hop:" << endl;
            cin >> CLOCK_IS_GOIN_ON;
            cout << "Enter finish hop number:" << endl;
            cin >> WORK_DAY_END;
            enter_func(CLOCK_IS_GOIN_ON, WORK_DAY_END);
        }

        if (flag_menu == 3) {
            system("cls");
            cout << "CLOSE THE WINDOW!" << endl;
            cout << "JUST DO IT !!!" << endl;

            RenderWindow window(sf::VideoMode(400, 400), "Don't touch it!");
            //description of basic forms
            sf::RectangleShape line(sf::Vector2f(200.f, 2.f));// проримовка линии
            CircleShape main_circle(100.f);
            main_circle.setFillColor(Color::White);
            CircleShape x1(10.f);
            x1.setFillColor(Color::Red);
            CircleShape x2(10.f);
            x2.setFillColor(Color(251, 163, 26));
            sf::CircleShape x3(10.f);
            x3.setFillColor(Color::Yellow);
            sf::CircleShape x4(10.f);
            x4.setFillColor(sf::Color::Green);
            sf::CircleShape x5(10.f);
            x5.setFillColor(sf::Color::Blue);
            sf::CircleShape x6(10.f);
            x6.setFillColor(sf::Color(128, 0, 128));
            sf::CircleShape x7(10.f);
            x7.setFillColor(sf::Color::Red);
            sf::CircleShape x8(10.f);
            x8.setFillColor(sf::Color(251, 163, 26));
            sf::CircleShape x9(10.f);
            x9.setFillColor(sf::Color::Yellow);
            sf::CircleShape x10(10.f);
            x10.setFillColor(sf::Color::Green);
            sf::CircleShape x11(10.f);
            x11.setFillColor(sf::Color::Blue);
            sf::CircleShape x12(10.f);
            x12.setFillColor(sf::Color(128, 0, 128));
            sf::CircleShape looper(40.f); //это лупер!!! аккуратно


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
                window.draw(main_circle);

                if (H[1]->flag_activ == 1) {    //для первой вершинки
                    if (H[1]->connection[1] == 1) {
                            //window.draw(main_circle); //пропиши луп
                            looper.setPosition(coordinate_x[1] - 40, coordinate_y[1] - 40);
                            window.draw(looper); //аккуратно!!!
                    }
                    if (H[1]->connection[2] == 1) {
                        if (H[1]->had[2]->connection[2] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 2)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color(251, 163, 26));
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 2, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 2, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 2)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 2, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 2, H[1]->gradient[1]));
                        }
                    }
                    if (H[1]->connection[3] == 1) {
                        if (H[1]->had[3]->connection[3] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 3)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Yellow);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 3, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 3, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 3)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 3, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 3, H[1]->gradient[1]));
                        }
                    }
                     if (H[1]->connection[4] == 1) {
                        if (H[1]->had[4]->connection[4] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 4)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Green);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 4, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 4, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 4)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 4, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 4, H[1]->gradient[1]));
                        }
                    }
                    if (H[1]->connection[5] == 1) {
                        if (H[1]->had[5]->connection[5] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 5)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 5, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 5, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 5)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 5, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 5, H[1]->gradient[1]));
                        }
                    }
                    if (H[1]->connection[6] == 1) {
                        if (H[1]->had[6]->connection[6] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 6)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 6, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 6, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 6)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 6, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 6, H[1]->gradient[1]));
                        }
                    }
                    if (H[1]->connection[7] == 1) {
                        if (H[1]->had[7]->connection[7] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 7)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Red);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 7, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 7, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 7)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 7, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 7, H[1]->gradient[1]));
                        }
                    }
                    if (H[1]->connection[8] == 1) {
                        if (H[1]->had[8]->connection[8] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 8)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color(251, 163, 26));
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 8, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 8, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 8)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 8, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 8, H[1]->gradient[1]));
                        }
                    }
                    if (H[1]->connection[9] == 1) {
                        if (H[1]->had[9]->connection[9] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 9)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Yellow);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 9, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 9, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 9)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 9, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 9, H[1]->gradient[1]));
                        }
                    }
                    if (H[1]->connection[10] == 1) {
                        if (H[1]->had[10]->connection[10] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 10)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Green);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 10, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 10, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 10)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 10, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 10, H[1]->gradient[1]));
                        }
                    }
                    if (H[1]->connection[11] == 1) {
                        if (H[1]->had[11]->connection[11] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 11)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 11, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 11, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 11)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 11, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 11, H[1]->gradient[1]));
                        }
                    }
                    if (H[1]->connection[12] == 1) {
                        if (H[1]->had[12]->connection[12] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(1, 12)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 12, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 12, H[1]->gradient[1]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(1, 12)));//функция определения размера
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[1]->coordinate_x[1], H[1]->coordinate_y[1]);
                            line.rotate(rotation(1, 12, H[1]->gradient[1]));
                            window.draw(line);
                            line.rotate(-rotation(1, 12, H[1]->gradient[1]));
                        }
                    }
                }
                if (H[2]->flag_activ == 1) {    //для второй вершинки
                    if (H[2]->connection[2] == 1) {
                            //window.draw(main_circle); //пропиши луп
                            looper.setPosition(coordinate_x[2] - 40, coordinate_y[2] - 40);
                            window.draw(looper); //аккуратно!!!
                    }
                    if (H[2]->connection[3] == 1) {
                        if (H[2]->had[3]->connection[3] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(2, 3)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Yellow);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 3, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 3, H[2]->gradient[2]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(2, 3)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 3, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 3, H[2]->gradient[2]));
                        }
                    }
                    if (H[2]->connection[4] == 1) {
                        if (H[2]->had[4]->connection[4] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(2, 4)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Green);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 4, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 4, H[2]->gradient[2]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(2, 4)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 4, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 4, H[2]->gradient[2]));
                        }
                    }
                    if (H[2]->connection[5] == 1) {
                        if (H[2]->had[5]->connection[5] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(2, 5)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 5, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 5, H[2]->gradient[2]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(2, 5)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 5, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 5, H[2]->gradient[2]));
                        }
                    }
                    if (H[2]->connection[6] == 1) {
                        if (H[2]->had[6]->connection[6] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(2, 6)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 6, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 6, H[2]->gradient[2]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(2, 6)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 6, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 6, H[2]->gradient[2]));
                        }
                    }
                    if (H[2]->connection[7] == 1) {
                        if (H[2]->had[7]->connection[7] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(2, 7)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Red);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 7, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 7, H[2]->gradient[2]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(2, 7)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 7, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 7, H[2]->gradient[2]));
                        }
                    }
                    if (H[2]->connection[8] == 1) {
                        if (H[2]->had[8]->connection[8] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(2, 8)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color(251, 163, 26));
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 8, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 8, H[2]->gradient[2]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(2, 8)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 8, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 8, H[2]->gradient[2]));
                        }
                    }
                    if (H[2]->connection[9] == 1) {
                        if (H[2]->had[9]->connection[9] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(2, 9)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Yellow);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 9, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 9, H[2]->gradient[2]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(2, 9)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 9, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 9, H[2]->gradient[2]));
                        }
                    }
                    if (H[2]->connection[10] == 1) {
                        if (H[2]->had[10]->connection[10] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(2, 10)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Green);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 10, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 10, H[2]->gradient[2]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(2, 10)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 10, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 10, H[2]->gradient[2]));
                        }
                    }
                    if (H[2]->connection[11] == 1) {
                        if (H[2]->had[11]->connection[11] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(2, 11)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 11, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 11, H[2]->gradient[2]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(2, 11)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 11, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 11, H[2]->gradient[2]));
                        }
                    }
                    if (H[2]->connection[12] == 1) {
                        if (H[2]->had[12]->connection[12] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(2, 12)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 12, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 12, H[2]->gradient[2]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(2, 12)));//функция определения размера
                            line.setFillColor(sf::Color(251, 163, 26));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[2]->coordinate_x[2], H[2]->coordinate_y[2]);
                            line.rotate(rotation(2, 12, H[2]->gradient[2]));
                            window.draw(line);
                            line.rotate(-rotation(2, 12, H[2]->gradient[2]));
                        }
                    }
                }
                if (H[3]->flag_activ == 1) {
                    if (H[3]->connection[3] == 1) {
                            //window.draw(main_circle); //пропиши луп
                            looper.setPosition(coordinate_x[3] - 40, coordinate_y[3] - 40);
                            window.draw(looper); //аккуратно!!!
                    }
                    if (H[3]->connection[4] == 1) {
                        if (H[3]->had[4]->connection[4] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(3, 4)));//функция определения размера
                            line.setFillColor(sf::Color::Yelllow);
                            line.setOutlineColor(sf::Color::Green);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 4, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 4, H[3]->gradient[3]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(3, 4)));//функция определения размера
                            line.setFillColor(sf::Color::Yellow);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 4, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 4, H[3]->gradient[3]));
                        }
                    }
                    if (H[3]->connection[5] == 1) {
                        if (H[3]->had[5]->connection[5] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(3, 5)));//функция определения размера
                            line.setFillColor(sf::Color::Yelllow);
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 5, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 5, H[3]->gradient[3]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(3, 5)));//функция определения размера
                            line.setFillColor(sf::Color::Yellow);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 5, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 5, H[3]->gradient[3]));
                        }
                    }
                    if (H[3]->connection[6] == 1) {
                        if (H[3]->had[6]->connection[6] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(3, 6)));//функция определения размера
                            line.setFillColor(sf::Color::Yelllow);
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 6, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 6, H[3]->gradient[3]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(3, 6)));//функция определения размера
                            line.setFillColor(sf::Color::Yellow);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 6, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 6, H[3]->gradient[3]));
                        }
                    }
                    if (H[3]->connection[7] == 1) {
                        if (H[3]->had[7]->connection[7] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(3, 7)));//функция определения размера
                            line.setFillColor(sf::Color::Yelllow);
                            line.setOutlineColor(sf::Color::Red);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 7, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 7, H[3]->gradient[3]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(3, 7)));//функция определения размера
                            line.setFillColor(sf::Color::Yellow);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 7, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 7, H[3]->gradient[3]));
                        }
                    }
                    if (H[3]->connection[8] == 1) {
                        if (H[3]->had[8]->connection[8] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(3, 8)));//функция определения размера
                            line.setFillColor(sf::Color::Yelllow);
                            line.setOutlineColor(sf::Color(251, 163, 26));
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 8, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 8, H[3]->gradient[3]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(3, 8)));//функция определения размера
                            line.setFillColor(sf::Color::Yellow);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 8, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 8, H[3]->gradient[3]));
                        }
                    }
                    if (H[3]->connection[9] == 1) {
                        if (H[3]->had[9]->connection[9] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(3, 9)));//функция определения размера
                            line.setFillColor(sf::Color::Yelllow);
                            line.setOutlineColor(sf::Color::Yellow);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 9, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 9, H[3]->gradient[3]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(3, 9)));//функция определения размера
                            line.setFillColor(sf::Color::Yellow);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 9, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 9, H[3]->gradient[3]));
                        }
                    }
                    if (H[3]->connection[10] == 1) {
                        if (H[3]->had[10]->connection[10] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(3, 10)));//функция определения размера
                            line.setFillColor(sf::Color::Yelllow);
                            line.setOutlineColor(sf::Color::Green);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 10, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 10, H[3]->gradient[3]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(3, 10)));//функция определения размера
                            line.setFillColor(sf::Color::Yellow);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 10, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 10, H[3]->gradient[3]));
                        }
                    }
                    if (H[3]->connection[11] == 1) {
                        if (H[3]->had[11]->connection[11] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(3, 11)));//функция определения размера
                            line.setFillColor(sf::Color::Yelllow);
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 11, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 11, H[3]->gradient[3]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(3, 11)));//функция определения размера
                            line.setFillColor(sf::Color::Yellow);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 11, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 11, H[3]->gradient[3]));
                        }
                    }
                    if (H[3]->connection[12] == 1) {
                        if (H[3]->had[12]->connection[12] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(3, 12)));//функция определения размера
                            line.setFillColor(sf::Color::Yelllow);
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 12, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 12, H[3]->gradient[3]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(3, 12)));//функция определения размера
                            line.setFillColor(sf::Color::Yellow);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[3]->coordinate_x[3], H[3]->coordinate_y[3]);
                            line.rotate(rotation(3, 12, H[3]->gradient[3]));
                            window.draw(line);
                            line.rotate(-rotation(3, 12, H[3]->gradient[3]));
                        }
                    }
                }
                if (H[4]->flag_activ == 1) {
                    if (H[4]->connection[4] == 1) {
                            //window.draw(main_circle); //пропиши луп
                            looper.setColor(sf::Color::Green);
                            looper.setPosition(coordinate_x[4] - 40, coordinate_y[4] - 40);
                            window.draw(looper); //аккуратно!!!
                    }
                    if (H[4]->connection[5] == 1) {
                        if (H[4]->had[5]->connection[5] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(4, 5)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 5, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 5, H[4]->gradient[4]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(4, 5)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 5, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 5, H[4]->gradient[4]));
                        }
                    }
                    if (H[4]->connection[6] == 1) {
                        if (H[4]->had[6]->connection[6] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(4, 6)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 6, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 6, H[4]->gradient[4]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(4, 6)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 6, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 6, H[4]->gradient[4]));
                        }
                    }
                    if (H[4]->connection[7] == 1) {
                        if (H[4]->had[7]->connection[7] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(4, 7)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Red);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 7, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 7, H[4]->gradient[4]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(4, 7)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 7, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 7, H[4]->gradient[4]));
                        }
                    }
                    if (H[4]->connection[8] == 1) {
                        if (H[4]->had[8]->connection[8] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(4, 8)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color(251, 163, 26));
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 8, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 8, H[4]->gradient[4]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(4, 8)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 8, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 8, H[4]->gradient[4]));
                        }
                    }
                    if (H[4]->connection[9] == 1) {
                        if (H[4]->had[9]->connection[9] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(4, 9)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Yellow);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 9, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 9, H[4]->gradient[4]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(4, 9)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 9, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 9, H[4]->gradient[4]));
                        }
                    }
                    if (H[4]->connection[10] == 1) {
                        if (H[4]->had[10]->connection[10] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(4, 10)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Green);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 10, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 10, H[4]->gradient[4]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(4, 10)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 10, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 10, H[4]->gradient[4]));
                        }
                    }
                    if (H[4]->connection[11] == 1) {
                        if (H[4]->had[11]->connection[11] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(4, 11)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 11, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 11, H[4]->gradient[4]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(4, 11)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 11, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 11, H[4]->gradient[4]));
                        }
                    }
                    if (H[4]->connection[12] == 1) {
                        if (H[4]->had[12]->connection[12] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(4, 12)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 12, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 12, H[4]->gradient[4]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(4, 12)));//функция определения размера
                            line.setFillColor(sf::Color::Green);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[4]->coordinate_x[4], H[4]->coordinate_y[4]);
                            line.rotate(rotation(4, 12, H[4]->gradient[4]));
                            window.draw(line);
                            line.rotate(-rotation(4, 12, H[4]->gradient[4]));
                        }
                    }
                }
                if (H[5]->flag_activ == 1) {
                    if (H[5]->connection[5] == 1) {
                            //window.draw(main_circle); //пропиши луп
                            looper.setColor(sf::Color::Blue);
                            looper.setPosition(coordinate_x[5] - 40, coordinate_y[5] - 40);
                            window.draw(looper); //аккуратно!!!
                    }
                    if (H[5]->connection[6] == 1) {
                        if (H[5]->had[6]->connection[6] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(5, 6)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 6, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 6, H[5]->gradient[5]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(5, 6)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 6, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 6, H[5]->gradient[5]));
                        }
                    }
                    if (H[5]->connection[7] == 1) {
                        if (H[5]->had[7]->connection[7] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(5, 7)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Red);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 7, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 7, H[5]->gradient[5]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(5, 7)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 7, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 7, H[5]->gradient[5]));
                        }
                    }
                    if (H[5]->connection[8] == 1) {
                        if (H[5]->had[8]->connection[8] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(5, 8)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color(251, 163, 26));
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 8, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 8, H[5]->gradient[5]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(5, 8)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 8, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 8, H[5]->gradient[5]));
                        }
                    }
                    if (H[5]->connection[9] == 1) {
                        if (H[5]->had[9]->connection[9] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(5, 9)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Yellow);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 9, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 9, H[5]->gradient[5]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(5, 9)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 9, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 9, H[5]->gradient[5]));
                        }
                    }
                    if (H[5]->connection[10] == 1) {
                        if (H[5]->had[10]->connection[10] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(5, 10)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Green);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 10, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 10, H[5]->gradient[5]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(5, 10)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 10, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 10, H[5]->gradient[5]));
                        }
                    }
                    if (H[5]->connection[11] == 1) {
                        if (H[5]->had[11]->connection[11] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(5, 11)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 11, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 11, H[5]->gradient[5]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(5, 11)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 11, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 11, H[5]->gradient[5]));
                        }
                    }
                    if (H[5]->connection[12] == 1) {
                        if (H[5]->had[12]->connection[12] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(5, 12)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 12, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 12, H[5]->gradient[5]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(5, 12)));//функция определения размера
                            line.setFillColor(sf::Color::Blue);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[5]->coordinate_x[5], H[5]->coordinate_y[5]);
                            line.rotate(rotation(5, 12, H[5]->gradient[5]));
                            window.draw(line);
                            line.rotate(-rotation(5, 12, H[5]->gradient[5]));
                        }
                    }
                }
                if (H[6]->flag_activ == 1) {
                    if (H[6]->connection[6] == 1) {
                            //window.draw(main_circle); //пропиши луп
                            looper.setColor(sf::Color(128, 0, 128));
                            looper.setPosition(coordinate_x[6] - 40, coordinate_y[6] - 40);
                            window.draw(looper); //аккуратно!!!
                    }
                    if (H[6]->connection[7] == 1) {
                        if (H[6]->had[7]->connection[7] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(6, 7)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color::Red);
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 7, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 7, H[6]->gradient[6]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(6, 7)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 7, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 7, H[6]->gradient[6]));
                        }
                    }
                    if (H[6]->connection[8] == 1) {
                        if (H[6]->had[8]->connection[8] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(6, 8)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color(251, 163, 26));
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 8, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 8, H[6]->gradient[6]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(6, 8)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 8, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 8, H[6]->gradient[6]));
                        }
                    }
                    if (H[6]->connection[9] == 1) {
                        if (H[6]->had[9]->connection[9] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(6, 9)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color::Yellow);
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 9, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 9, H[6]->gradient[6]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(6, 9)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 9, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 9, H[6]->gradient[6]));
                        }
                    }
                    if (H[6]->connection[10] == 1) {
                        if (H[6]->had[10]->connection[10] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(6, 10)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color::Green);
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 10, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 10, H[6]->gradient[6]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(6, 10)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 10, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 10, H[6]->gradient[6]));
                        }
                    }
                    if (H[6]->connection[11] == 1) {
                        if (H[6]->had[11]->connection[11] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(6, 11)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 11, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 11, H[6]->gradient[6]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(6, 11)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 11, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 11, H[6]->gradient[6]));
                        }
                    }
                    if (H[6]->connection[12] == 1) {
                        if (H[6]->had[12]->connection[12] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(6, 12)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 12, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 12, H[6]->gradient[6]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(6, 12)));//функция определения размера
                            line.setFillColor(sf::Color(128, 0, 128));
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[6]->coordinate_x[6], H[6]->coordinate_y[6]);
                            line.rotate(rotation(6, 12, H[6]->gradient[6]));
                            window.draw(line);
                            line.rotate(-rotation(6, 12, H[6]->gradient[6]));
                        }
                    }
                }
                if (H[7]->flag_activ == 1) {
                    if (H[7]->connection[7] == 1) {
                            //window.draw(main_circle); //пропиши луп
                            looper.setColor(sf::Color::Red);
                            looper.setPosition(coordinate_x[7] - 40, coordinate_y[7] - 40);
                            window.draw(looper); //аккуратно!!!
                    }
                    if (H[7]->connection[8] == 1) {
                        if (H[7]->had[8]->connection[8] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(7, 8)));
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color(251, 163, 26));
                            line.setPosition(H[7]->coordinate_x[7], H[7]->coordinate_y[7]);
                            line.rotate(rotation(7, 8, H[7]->gradient[7]));
                            window.draw(line);
                            line.rotate(-rotation(7, 8, H[7]->gradient[7]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(7, 8)));
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[7]->coordinate_x[7], H[7]->coordinate_y[7]);
                            line.rotate(rotation(7, 8, H[7]->gradient[7]));
                            window.draw(line);
                            line.rotate(-rotation(7, 8, H[7]->gradient[7]));
                        }
                    }
                    if (H[7]->connection[9] == 1) {
                        if (H[7]->had[9]->connection[9] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(7, 9)));
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Yellow);
                            line.setPosition(H[7]->coordinate_x[7], H[7]->coordinate_y[7]);
                            line.rotate(rotation(7, 9, H[7]->gradient[7]));
                            window.draw(line);
                            line.rotate(-rotation(7, 9, H[7]->gradient[7]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(7, 9)));
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[7]->coordinate_x[7], H[7]->coordinate_y[7]);
                            line.rotate(rotation(7, 9, H[7]->gradient[7]));
                            window.draw(line);
                            line.rotate(-rotation(7, 9, H[7]->gradient[7]));
                        }
                    }
                    if (H[7]->connection[10] == 1) {
                        if (H[7]->had[10]->connection[10] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(7, 10)));
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Green);
                            line.setPosition(H[7]->coordinate_x[7], H[7]->coordinate_y[7]);
                            line.rotate(rotation(7, 10, H[7]->gradient[7]));
                            window.draw(line);
                            line.rotate(-rotation(7, 10, H[7]->gradient[7]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(7, 10)));
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[7]->coordinate_x[7], H[7]->coordinate_y[7]);
                            line.rotate(rotation(7, 10, H[7]->gradient[7]));
                            window.draw(line);
                            line.rotate(-rotation(7, 10, H[7]->gradient[7]));
                        }
                    }
                    if (H[7]->connection[11] == 1) {
                        if (H[7]->had[11]->connection[11] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(7, 11)));
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Blue);
                            line.setPosition(H[7]->coordinate_x[7], H[7]->coordinate_y[7]);
                            line.rotate(rotation(7, 11, H[7]->gradient[7]));
                            window.draw(line);
                            line.rotate(-rotation(7, 11, H[7]->gradient[7]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(7, 11)));
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[7]->coordinate_x[7], H[7]->coordinate_y[7]);
                            line.rotate(rotation(7, 11, H[7]->gradient[7]));
                            window.draw(line);
                            line.rotate(-rotation(7, 11, H[7]->gradient[7]));
                        }
                    }
                    if (H[7]->connection[12] == 1) {
                        if (H[7]->had[12]->connection[12] == 1) {
                            line.setSize(sf::Vector2f(length_of_line(7, 12)));
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color(128, 0, 128));
                            line.setPosition(H[7]->coordinate_x[7], H[7]->coordinate_y[7]);
                            line.rotate(rotation(7, 11, H[7]->gradient[7]));
                            window.draw(line);
                            line.rotate(-rotation(7, 11, H[7]->gradient[7]));
                        }
                        else {
                            line.setSize(sf::Vector2f(length_of_line(7, 11)));
                            line.setFillColor(sf::Color::Red);
                            line.setOutlineColor(sf::Color::Transparent);
                            line.setPosition(H[7]->coordinate_x[7], H[7]->coordinate_y[7]);
                            line.rotate(rotation(7, 11, H[7]->gradient[7]));
                            window.draw(line);
                            line.rotate(-rotation(7, 11, H[7]->gradient[7]));
                        }
                    }

                // запихни сюда кусок кода, который включает вершины
                //TOPs activathion
                for (int i = 1; i < 13; i++) {
                    if (H[i]->flag_activ == 1) {
                        if (i == 1) {
                            x1.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x1);
                        }
                        if (i == 2) {
                            x2.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x2);
                        }
                        if (i == 3) {
                            x3.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x3);
                        }
                        if (i == 4) {
                            x4.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x4);
                        }
                        if (i == 5) {
                            x5.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x5);
                        }
                        if (i == 6) {
                            x6.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x6);
                        }
                        if (i == 7) {
                            x7.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x7);
                        }
                        if (i == 8) {
                            x8.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x8);
                        }
                        if (i == 9) {
                            x9.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x9);
                        }
                        if (i == 10) {
                            x10.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x10);
                        }
                        if (i == 11) {
                            x11.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x11);
                        }
                        if (i == 12) {
                            x12.setPosition(H[i]->coordinate_x[i], H[i]->coordinate_y[i]);
                            window.draw(x12);
                        }
                    }
                }

                window.display();
            }
        }

        if (flag_menu == 4) {
            system("cls");
            cout << "                 C TERMINATOR" << endl;
        }
        if ((flag_menu != 1) && (flag_menu != 2) && (flag_menu != 3) && (flag_menu != 4)) {
            cout << "Lets try again!!!" << endl;
        }
    }
}
