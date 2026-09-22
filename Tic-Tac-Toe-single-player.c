#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gameManual();
void gameManual()
{
    printf("Game Manual: \n");
    printf("\n 1 | 2 | 3 \n");
    printf("---|---|---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---|---|---\n");
    printf(" 7 | 8 | 9 \n\n");
}

void printBoard(char arr[]);
void printBoard(char arr[])
{
    printf("\n %c | %c | %c \n", arr[0], arr[1], arr[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", arr[3], arr[4], arr[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", arr[6], arr[7], arr[8]);
}

int playerChance(char arr[], int player);
int playerChance(char arr[], int player)
{
    if ((player > 0 && player < 10))
    {
        if (arr[player - 1] != ' ')
        {
            printf("Position already occupied!\n");
            return 0;
        }
        else
        {
            arr[player - 1] = 'O';
            return -1;
        }
    }
    else
    {
        printf("Something went wrong!\n");
        return 0;
    }

    return -1;
}

int compChance(char arr[], int comp);
int compChance(char arr[], int comp)
{
    if ((comp > 0 && comp < 10))
    {
        if (arr[comp - 1] != ' ')
        {
            return 0;
        }
        else
        {
            arr[comp - 1] = 'X';
            return -1;
        }
    }
    else
    {
        printf("Something went wrong!\n");
        return 0;
    }

    return -1;
}

void printOutput(char arr[]);
void printOutput(char arr[])
{
    system("cls");
    gameManual();
    printBoard(arr);
}

int win(char arr[]);
int win(char arr[])
{
    if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0] != ' ')
        return 1;
    if (arr[3] == arr[4] && arr[4] == arr[5] && arr[3] != ' ')
        return 1;
    if (arr[6] == arr[7] && arr[7] == arr[8] && arr[6] != ' ')
        return 1;
    if (arr[0] == arr[3] && arr[3] == arr[6] && arr[0] != ' ')
        return 1;
    if (arr[1] == arr[4] && arr[4] == arr[7] && arr[1] != ' ')
        return 1;
    if (arr[2] == arr[5] && arr[5] == arr[8] && arr[2] != ' ')
        return 1;
    if (arr[0] == arr[4] && arr[4] == arr[8] && arr[0] != ' ')
        return 1;
    if (arr[2] == arr[4] && arr[4] == arr[6] && arr[2] != ' ')
        return 1;

    if (arr[0] != ' ' && arr[1] != ' ' && arr[2] != ' ' &&
        arr[3] != ' ' && arr[4] != ' ' && arr[5] != ' ' &&
        arr[6] != ' ' && arr[7] != ' ' && arr[8] != ' ')
        return 0;

    return -1;
}

// Main Function
int main()
{
    srand(time(0));
    int player, comp, result;
    int count = 1;
    char arr[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    gameManual();
    printf("Play Tic-Tac-Toe:\n");
    printBoard(arr);
    while (1)
    {
        if (count % 2 != 0)
        {
            printf("Player turn: ");
            scanf("%d", &player);
            while (getchar() != '\n');
            if (playerChance(arr, player) == 0)
            {
                continue;
            }
            printOutput(arr);
        }
        else
        {
            printf("Computer turn: ");
            comp = (rand() % 9) + 1;
            if (compChance(arr, comp) == 0)
            {
                continue;
            }
            printOutput(arr);
        }

        result = win(arr);
        if (result == 1)
        {
            if (count % 2 != 0)
            {
                printf("Player Wins!\n");
            }
            else
            {
                printf("Computer Wins!\n");
            }
            break;
        }
        else if (result == 0)
        {
            printf("Game was Draw!\n");
            break;
        }

        count++;
    }

    return 0;
}