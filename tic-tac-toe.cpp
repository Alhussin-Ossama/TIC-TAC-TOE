#include <iostream>
#include <ctime>
#include <random>

using namespace std;

char the_floor[3][3] = { '1','2','3','4','5','6','7','8','9' };
char player = 'X';
void print_floor();					//* print the board of xo and some design
void choose_position();				//* choose your position and switch between X & O
char winner();						//* it's check who won
void choose_mode();					//* it's make you choose your mode if wanna play with 2p or cpu
void choose_position_cpu();         //* choose your position vs cpu
void cpu_choice();                  //* it's make cpu choose his position vs player and check if this place in floor clear or not




int main()
{
    choose_mode();
    return 0;
}

//////////////////////////////////////////////////////////////////


void cpu_choice()
{
    srand(time(NULL));
    int p, i;
    while (1)
    {
        p = rand() % (8 - 0 + 1) + 0;
        if (p >= 0 && p <= 2)
        {
            i = 0;
            if (the_floor[i][p] != 'X' && the_floor[i][p] != 'O')
            {
                break;
            }

        }
        else if (p >= 3 && p <= 5)
        {
            i = 1;
            p = p % 3;
            if (the_floor[i][p] != 'X' && the_floor[i][p] != 'O')
            {

                break;
            }

        }
        else if (p >= 6 && p <= 8)
        {
            i = 2;
            p = p % 3;
            if (the_floor[i][p] != 'X' && the_floor[i][p] != 'O')
            {

                break;
            }

        }
    }
    the_floor[i][p] = 'O';


}
///////////////////////////////////////////////////////////////////////////////

void choose_position_cpu()
{
    char pos;
    cout << "Choose your position player ( " << player << " ) : ";
    cin >> pos;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (the_floor[i][j] == pos)
            {
                the_floor[i][j] = player;
            }
        }
    }


}

//////////////////////////////////////////////////////////////////////////////

void print_floor()
{
    system("cls");
    cout << "+-------------+-------------+-------------+" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "|      " << the_floor[i][j] << "      ";
        }
        cout << "|      " << endl;

        cout << "+-------------+-------------+-------------+" << endl;
    }
}


//////////////////////////////////////////////////////////////////////////////////

void choose_position()
{
    char pos;
    cout << "Choose your position ( " << player << " ) : ";
    cin >> pos;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (the_floor[i][j] == pos)
            {
                the_floor[i][j] = player;
            }
        }
    }
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}


////////////////////////////////////////////////////////////////

char winner()
{
    int xc = 0, oc = 0;
    int check_numbers = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (the_floor[i][j] != 'X' && the_floor[i][j] != 'O')
                check_numbers++;
            if (the_floor[i][j] == 'X')
                xc++;
            else if (the_floor[i][j] == 'O')
                oc++;
            if (xc == 3 || oc == 3)
            {
                return xc > oc ? 'X' : 'O';
            }
        }
        xc = 0;
        oc = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (the_floor[j][i] == 'X')
                xc++;
            else if (the_floor[j][i] == 'O')
                oc++;
            if (xc == 3 || oc == 3)
            {
                return xc > oc ? 'X' : 'O';
            }
        }
        xc = 0;
        oc = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                if (the_floor[i][j] == 'X')
                    xc++;
                else if (the_floor[i][j] == 'O')
                    oc++;
                if (xc == 3 || oc == 3)
                {
                    return xc > oc ? 'X' : 'O';
                }
            }
        }
        
    }
    if (the_floor[0][2] == 'X' && the_floor[1][1] == 'X' && the_floor[2][0] == 'X')
        return 'X';
    else if (the_floor[0][2] == 'O' && the_floor[1][1] == 'O' && the_floor[2][0] == 'O')
        return 'O';
    if (check_numbers == 0)
        return'd';
    return '.';
}


/////////////////////////////////////////////////////////////////////////////////////////////////


void choose_mode()
{
    cout << "\t \t \t \t \t WELCOME TO <TICTAC TOE> GAME (: " << endl << endl << endl;
    cout << "- If you want to play with <2P> press ===> ( 1 )" << endl << endl
        << "        <<||-----------------------------------------------------------------------------||>>"<<  endl <<endl
        << "- If you want to play with <CPU> press ===> ( 2 )" << endl;
    int number;
    cin >> number;
    if (number == 1)
    {
        while (winner() == '.')
        {
            print_floor();
            choose_position();
        }
        print_floor();
        if (winner() == 'd')
            cout << " -|NO WINNER|-!!  );" << endl;
        else
            cout << " THE WINNER IS PLAYER ( " << winner() << " ) GG " << endl;
    }
    else if (number == 2)
    {
        int i = 0;
        while (winner() == '.')
        {
            i++;
            print_floor();
            choose_position_cpu();
            if (i == 5)
                break;
            cpu_choice();
        }
        print_floor();
        if (winner() == 'd')
            cout << " -|NO WINNER|-!!  );" << endl;
        else
            cout << " THE WINNER IS PLAYER ( " << winner() << " ) GG " << endl;
    }
}