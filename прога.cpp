
#include "TXlib.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

struct Hero
    {
    int x , y;
    int vx, vy;

    int color, size;

    HDC  photo;

    int up, down, right, left,  stop;

    void Button   ();
    void Physics  ();
    void Draw     ();
    void Run      ();

    };

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void programm ();

void Logic (Hero hero1, Hero hero2, int area);



//------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main ()
    {
    txCreateWindow (1000, 1000);

    programm ();

    }

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void programm ()
    {
    Hero Viktor    = {300, 300, 2, 2, TX_RED,    25, txLoadImage ("carr.bmp"), VK_UP, VK_DOWN, VK_RIGHT, VK_LEFT, VK_SPACE};
    Hero Romounald = {100, 100, 3, 2, TX_GREEN,  25, NULL,                     'W',   'S',     'D',      'A',     'Q'};
    Hero Vlad      = {500, 200, 4, 3, TX_BLUE,   50, txLoadImage ("krosh.bmp")};
    Hero Ilya      = {800, 200, 5, 5, TX_YELLOW, 50};

    HDC Fon        = txLoadImage ("fon.bmp");

    while (!GetAsyncKeyState (VK_ESCAPE))
        {

        txSetFillColor (TX_BLACK);
        txClear        ();

        txBitBlt (0, 0, Fon);

        //1
        Viktor.Run     ();


        //2
        Romounald.Run  ();

        //3
        Vlad.Run       ();

        //4
        Ilya.Run       ();

       // if ()
            //{
            //int life = 5

            //printf ("life = \n", life);

            Logic (Vlad, Viktor, 50);
            //}

        txSleep        (10);
        }

    txDeleteDC (Vlad.photo);
    txDeleteDC (Viktor.photo);
    txDeleteDC (Fon);
    }

//�������� �� ��������------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hero::Physics ()
    {
    x = x + vx;
    y = y + vy;

    if (x < 50)
        {
        x  = 50;
        vx = -vx;
        }

    if (y < 50)
        {
        y  = 50;
        vy = -vy;
        }

    if (x > 950)
        {
        x  = 950;
        vx = -vx;
        }

    if (y > 950)
        {
        y  = 950;
        vy = -vy;
        }

    }

//������� ����������------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hero::Button ()
    {

    if (GetAsyncKeyState (up))    (vy)--;
    if (GetAsyncKeyState (down))  (vy)++;
    if (GetAsyncKeyState (left))  (vx)--;
    if (GetAsyncKeyState (right)) (vx)++;
    if (GetAsyncKeyState (stop))  (vx) = (vy) = 0;
    }

//��������� ������------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hero::Draw ()
    {
    if (photo != 0)
        {
        txTransparentBlt (x - 50, y - 50, photo, TX_WHITE);
        }

    if (photo == 0)
        {
        txSetFillColor (color);
        txCircle       (x,  y, size);
        }

    }

//�������� �� ����� �����------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hero::Run ()
    {
    Draw    ();
    Physics ();
    Button  ();
    }

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Logic (Hero hero1, Hero hero2, int area)
    {
    double distance = sqrt ((hero2.x-hero1.x)*(hero2.x-hero1.x) + (hero2.y-hero1.y)*(hero2.y-hero1.y));

    //printf ("distance = %lg\n", distance);


    if (distance < area)
        {
         txMessageBox ("Win Viktor");
        }

    }


//------------------------------------------------------------------------------------------------------------------------------------------------------------------


/*
                                                � ����� �. ��� ��� ��� Y?

                                            ����� (��������)         ���������

             � ����� �. �����
             �������� ���. Y ������?

             ����� (��������)                Y                         *Y

             ���������                       &Y                        Y

*/




