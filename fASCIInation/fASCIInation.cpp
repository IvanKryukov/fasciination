#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
#include <windows.h>

#define X_SIZE (int)40 // 6
#define Y_SIZE (int)24 // 3

char usr_map [Y_SIZE][X_SIZE];

typedef struct
{
    int x;
    int y;
    char skin;
    int direction;
} t_usr;
t_usr user_fig = { X_SIZE / 2, Y_SIZE / 2, 'X', 4 };

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
    memset((void*)scene, ' ', size);
}

void print_scene(t_usr usr)
{
    std::cout << "##########################################" << std::endl;

    for (int i = 0; i < Y_SIZE; i++)
    {
        std::cout << "#";

        for (int j = 0; j < X_SIZE; j++)
        {
            if (i == usr.y && j == usr.x)
                std::cout << usr.skin;
            else
                std::cout << usr_map[i][j];
            /*
            switch (usr.direction)
            {
            case 1:
                if (i == usr.y && j == usr.x + 1)
                    std::cout << '>';
                break;
            case 2:
                if (i == usr.y + 1 && j == usr.x)
                    std::cout << 'v';
                break;
            case 3:
                if (i == usr.y && j == usr.x - 1)
                    std::cout << '<';
                break;
            case 4:
                if (i == usr.y - 1 && j == usr.x)
                    std::cout << '^';
                break;
            default:
                break;
            }
            */
        }

        std::cout << "#" << std::endl;
    }

    std::cout << "##########################################" << std::endl;
}

int usr_action(int pressed_key, t_usr * usr)
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
        if ((usr->x + 1 <= X_SIZE - 1) && (usr_map[usr->y][usr->x + 1] != '~'))
            usr->x += 1;
        usr->direction = 1;
        ret = 1;
        break;

    case 'a':
    case 'A':
    case VK_LEFT:
        if ((usr->x - 1 >= 0) && (usr_map[usr->y][usr->x - 1] != '~'))
            usr->x -= 1;
        usr->direction = 3;
        ret = 1;
        break;

    case 'w':
    case 'W':
    case VK_UP:
        if ((usr->y - 1 >= 0) && (usr_map[usr->y - 1][usr->x] != '~'))
            usr->y -= 1;
        usr->direction = 4;
        ret = 1;
        break;

    case 's':
    case 'S':
    case VK_DOWN:
        if ((usr->y + 1 <= Y_SIZE - 1) && (usr_map[usr->y + 1][usr->x] != '~'))
            usr->y += 1;
        usr->direction = 2;
        ret = 1;
        break;

    case VK_SPACE:
        if (usr_map[user_fig.y][user_fig.x] == ' ')
            usr_map[user_fig.y][user_fig.x] = '~';
        else
            usr_map[user_fig.y][user_fig.x] = ' ';

        ret = 1;
        break;


    default:
        break;
    }

    return ret;
}

int main()
{
    hidecursor();
    init_scene(&usr_map[0][0], sizeof(usr_map));
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
