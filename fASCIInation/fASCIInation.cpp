#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
#include <windows.h>

#include "coord.h"
#include "bodyobj.h"

#define X_SIZE (int)40 // 6
#define Y_SIZE (int)24 // 3

char usr_map [Y_SIZE][X_SIZE];

void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void init_scene(char* scene, int size)
{
    memset((void*)scene, '.', size);
}

void print_scene(bodyobj usr)
{
    std::cout << "##########################################" << std::endl;

    for (int y = 0; y < Y_SIZE; y++)
    {
        std::cout << "#";

        for (int x = 0; x < X_SIZE; x++)
        {
            if (y == usr.get_coord_y() && x == usr.get_coord_x())
                std::cout << usr.get_skin();
            else
                std::cout << usr_map[y][x];
        }

        std::cout << "#" << std::endl;
    }

    std::cout << "##########################################" << std::endl;
}

int usr_action(int pressed_key, bodyobj * usr)
{
    int ret = 0;

    switch (pressed_key)
    {
    case 'q':
    case 'Q':
        ret = -1;
        break;

    case 'd':
    case 'D':
    case VK_RIGHT:
        if ((usr->get_coord_x() + 1 < X_SIZE) && (usr->get_drct_look_x() == 1))
            usr->set_drct_move_x(1);
        usr->set_drct_look_x(1);
        ret = 1;
        break;

    case 'a':
    case 'A':
    case VK_LEFT:
        if ((usr->get_coord_x() - 1 >= 0) && (usr->get_drct_look_x() == -1))
            usr->set_drct_move_x(-1);
        usr->set_drct_look_x(-1);
        ret = 1;
        break;

    case 'w':
    case 'W':
    case VK_UP:
        if ((usr->get_coord_y() - 1 >= 0) && (usr->get_drct_look_y() == -1))
            usr->set_drct_move_y(-1);
        usr->set_drct_look_y(-1);
        ret = 1;
        break;

    case 's':
    case 'S':
    case VK_DOWN:
        if ((usr->get_coord_y() + 1 < Y_SIZE) && (usr->get_drct_look_y() == 1))
            usr->set_drct_move_y(1);
        usr->set_drct_look_y(1);
        ret = 1;
        break;

    case VK_SPACE:
        if (usr_map[usr->get_coord_y()][usr->get_coord_x()] == ' ')
            usr_map[usr->get_coord_y()][usr->get_coord_x()] = '~';
        else
            usr_map[usr->get_coord_y()][usr->get_coord_x()] = ' ';

        ret = 1;
        break;

    default:
        break;
    }

    usr->update_coord();

    return ret;
}

int main()
{
    hidecursor();
    init_scene(&usr_map[0][0], sizeof(usr_map));
    bodyobj user_fig = bodyobj(coord(X_SIZE / 2, Y_SIZE / 2), coord(), 'X');
    int c = 0;
    int action_res = 0;

    while (-1 != action_res)
    {
        system("cls");
        print_scene(user_fig);

        do
        {
            c = _getch();
            action_res = usr_action(c, &user_fig);
        } 
        while (0 == action_res);
    }

    system("cls");

    return 0;
}
