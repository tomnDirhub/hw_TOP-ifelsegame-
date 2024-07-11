#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <string>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <vector>

using namespace std;

#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <ctime>
#include <vector>
using namespace std;

#define TREASURE_HUNT

void Print(char map[][20], int collectedTreasures)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
#ifdef TREASURE_HUNT
    cout << "Собрано кладов: " << collectedTreasures << endl;
#endif
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    const int x = 20;
    const int y = 20;
    int userX = 1;
    int userY = 1;

    char mass[y][x] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}

    };
    mass[userY][userX] = '@';

#ifdef TREASURE_HUNT
    vector<pair<int, int>> treasures;
    int collectedTreasures = 0;
    for (int i = 0; i < 5; i++) {
        int treasureX = rand() % x;
        int treasureY = rand() % y;
        if (mass[treasureY][treasureX] == ' ') {
            mass[treasureY][treasureX] = '$';
            treasures.push_back({ treasureY, treasureX });
        }
    }
#endif

    while (true)
    {
        system("cls");
        Print(mass, collectedTreasures);
        int code = _getch();
        if (code == 0 || code == 224)
            code = _getch();
        switch (code)
        {
        case 75://влево 
            if (mass[userY][userX - 1] != '#')
            {
                --userX;
                swap(mass[userY][userX], mass[userY][userX + 1]);
            }
            break;
        case 77://вправо
            if (mass[userY][userX + 1] != '#')
            {
                ++userX;
                swap(mass[userY][userX], mass[userY][userX - 1]);
            }

            break;
        case 72://вверх
            if (mass[userY - 1][userX] != '#')
            {
                --userY;
                swap(mass[userY][userX], mass[userY + 1][userX]);
            }
            break;
        case 80://вниз
            if (mass[userY + 1][userX] != '#')
            {
                ++userY;
                swap(mass[userY][userX], mass[userY - 1][userX]);
            }
            break;
        }
#ifdef TREASURE_HUNT
        for (auto it = treasures.begin(); it != treasures.end(); )
        {
            if (userY == it->first && userX == it->second) {
                cout << "Клад собран!" << endl;
                collectedTreasures++;
                mass[it->first][it->second] = ' ';
                it = treasures.erase(it);
            }
            else {
                ++it;
            }
        }
#endif

        mass[userY][userX] = '@';

        system("cls");
        Print(mass, collectedTreasures);
    }
    return 0;
}
