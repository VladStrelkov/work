#include "Books/TXlib.h"

struct Hero
    {
    int x, y;


    };


void Game ();
void DrawFood (Hero Eat[]);
void RandFood (Hero Eat[]);

const int N = 500;

int main ()
    {
    txCreateWindow (1000, 1000);

    Game ();
    }


void Game ()
    {

    Hero Eat [N] = {};

    RandFood (Eat);

    while (!GetAsyncKeyState (VK_ESCAPE))
        {

        txSetFillColor (TX_RED);

        DrawFood (Eat);
        }

    }

void DrawFood (Hero Eat[])
    {
    int n = 0;

    while (n < N)
            {
            txCircle (Eat[n].x, Eat[n].y, 10);

            n++;
            }

    }

void RandFood (Hero Eat[])
    {
    int n = 0;

    while (n < N)
        {

        Eat[n].x = rand ()%17 * 60;
        Eat[n].y = rand ()%17 * 60;

        // 0 1   2   3   4   5   6   7   8   9
        // 0 100 200 300 400 500 600 700 800 900

        n++;
        }

    }

/*

1. �����  ������� �� 10
2. ����� ��������� ������� �������� ��  100
3. �������, ��� �� ����� � ������� ����� ���������� ������ ����� 100


*/

