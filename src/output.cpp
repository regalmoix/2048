#include "./global.h"
#include <curses.h>
#include <fstream>


int printboard(vector<vector<int>>& board, int n)
{
    //ofstream debug;
    //debug.open("test", ios::out);

    keypad(initscr(),1);
    curs_set(0);

    clear();

    move(5*n, 5*n);

    printw("SCORE : %d", score);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //string s = to_string(board[i][j]);
            //char const *c = s.c_str();


            //mvaddch(i, j, (char)(board[i][j] + 48));
            //mvprintw(6*i, 6*j, c);


            move(4*i, 4*j);

            if (board[i][j])
                printw("%d", board[i][j]);
            
            else 
                printw("%d", board[i][j]);

            //debug << board[i][j] << " ";
            
        }
        //debug << endl;
    }
    
    //debug.close();

    emptycell(board, n);

    //checks if no move possible and game ended.

    if (emptypos.empty() && !checkmove(board, n))
    {
        move(6*n, 0);
        printw("\n\nGame Ended, Out of Moves.\nFinal Score : %d \nPress any key to quit.", score);
        getch();
        return endwin();
    }

    //exected only if move possible

    tilemove(board, n); 

    //ideally control never reaches here
    return 0; 
}


int tilemove (vector<vector<int>>& board, int n)
{
    noecho();
    char dir = getch();

    emptycell(board, n);

    if (dir == ESC)
    {
        clear();
        printw("Final Score : %d \nPress any key to quit.", score);
        char x = getch();
	    return endwin();
    }
    else 
    {
        auto ogboard = board;
        switch (dir)
        {
            case UP :   up(board, n);
                        break;
                        
            case DOWN : down(board, n);
                        break;

            case LEFT : left(board, n);
                        break;

            case RIGHT: right(board, n);
                        break;

            default:
                        printboard(board, n);
                        break;
        }

        if (board != ogboard)
        {
            addrandom(board);
        }
            
        emptycell(board, n);
        /*
        if (emptypos.empty() && !checkmove(board, n))
        {
            move(6*n, 0);
            printw("\n\nGame Ended, Out of Moves.\nFinal Score : %d \nPress any key to quit.", score);
            getch();
            return endwin();
        }
        */
        printboard(board, n);
        return 0;
    }    
}
