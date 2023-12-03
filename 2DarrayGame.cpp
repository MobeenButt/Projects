#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void fire(char maze[][43]);
void movePlayerright(char maze[][43], char direction);
void movePlayerleft(char maze[][43], char direction);
void printMaze(char maze[][43]);
void firemovingup(char maze[][43]);
bool Move(char maze[][43], int i, int col, char direction);
bool removefireWall(char maze[][43]);
void removeFire(char maze[][43]);
void moveEnemy(char maze[][43]);
int main()
{
    char maze[12][43] = {"#######################################",
                         "#                      e              #",
                         "#                                     #",
                         "#     x                               #",
                         "#                                     #",
                         "#                                e    #",
                         "#                                     #",
                         "#                                     #",
                         "#                                     #",
                         "#         p                           #",
                         "#######################################"};

    printMaze(maze);
    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerleft(maze, 'l');
            printMaze(maze);
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerright(maze, 'r');
            printMaze(maze);
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            fire(maze);
            printMaze(maze);
            bool op = true;
            while (op)
            {

                if (removefireWall(maze)) 
                {
                    firemovingup(maze);
                    removeFire(maze);
                    printMaze(maze);
                }
                else
                {
                    op = false;
                    printMaze(maze);
                }
            }
        }
       
    moveEnemy(maze);
        printMaze(maze);
        moveEnemy(maze);
    }
     
    return 0;
}

void printMaze(char maze[][43])
{
    system("cls");
    for (int i = 0; i < 12; i++)
    {
        for (int col = 0; col < 43; col++)
        {
            cout << maze[i][col];
        }
        cout << endl;
    }
}

void movePlayerleft(char maze[][43], char direction)
{
    for (int i = 0; i < 12; i++)
    {
        for (int col = 0; col < 43; col++)
        {
            if (maze[i][col] == 'p')
            {
                if (Move(maze, i, col, direction))
                {
                    int newMove;
                    if (direction == 'l')
                    {
                        newMove = col - 1;
                    }
                    maze[i][col] = ' ';
                    maze[i][newMove] = 'p';
                    break;
                }
            }
        }
    }
}

void movePlayerright(char maze[][43], char direction)
{
    for (int i = 0; i < 12; i++)
    {
        for (int col = 0; col < 43; col++)
        {
            if (maze[i][col] == 'p')
            {
                if (Move(maze, i, col, direction))
                {
                    int newMove;
                    if (direction == 'r')
                    {
                        newMove = col + 1;
                    }
                    maze[i][col] = ' ';
                    maze[i][newMove] = 'p';
                    break;
                }
            }
        }
    }
}

bool Move(char maze[][43], int i, int col, char direction)
{
    if (direction == 'l' && col > 0 && maze[i][col - 1] == ' ')
    {
        return true;
    }
    else if (direction == 'r' && col + 1 < 43 && maze[i][col + 1] == ' ')
    {
        return true;
    }
    return false;
}

void fire(char maze[][43])
{
    for (int i = 0; i < 12; i++)
    {
        for (int col = 0; col < 43; col++)
        {
            if (maze[i][col] == 'p')
            {
                // position above the player is empty
                if (i > 0 && maze[i - 1][col] == ' ')
                {
                    maze[i - 1][col] = 'f'; // Place fire above the player
                }
                break; 
            }
        }
    }
}

void firemovingup(char maze[][43])
{
    for (int i = 0; i < 12; i++)
    {
        for (int col = 0; col < 43; col++)
        {
            if (maze[i][col] == 'f')
            {
                // Check if the position above the fire is empty
                if (i > 0 && maze[i - 1][col] == ' ')
                {
                    maze[i][col] = ' ';    
                    maze[i - 1][col] = 'f'; 
                }
                else
                {
                    maze[i][col] = ' '; 
                }
            }
        }
    }
}

bool removefireWall(char maze[][43])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 43; j++)
        {
            if (maze[i][j] == 'f' && i - 1 >= 0 && maze[i - 1][j] == '#')
            {
                maze[i][j] = ' ';
                return false;
            }
        }
    }
    return true;
}
void removeFire(char maze[][43]){
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 43; j++)
        {
            if (maze[i][j] == 'f' && (maze[i-1][j] == 'e' || maze[i-1][j] == 'x'))
            {
                maze[i-1][j] = ' ';
            }
        }
    }
}
void moveEnemy(char maze[][43]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 43; j++) {
            if (maze[i][j] == 'e' || maze[i][j] == 'x') {
               
                if (j + 1 < 43 && maze[i][j + 1] == ' ') {
                    maze[i][j] = ' ';
                    maze[i][j + 1] = (maze[i][j] == 'e') ? 'e' : 'x';
                }
    
                else if (j - 1 >= 0 && maze[i][j - 1] == ' ') {
                    maze[i][j] = ' ';
                    maze[i][j - 1] = (maze[i][j] == 'e') ? 'e' : 'x';
                }
                }
        }
    }
}
