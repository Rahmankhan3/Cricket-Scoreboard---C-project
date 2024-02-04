#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct batsman
{
    char name[25];
    int score;
    int single;
    int two;
    int three;
    int four;
    int six;
};
struct bowler
{
    char name[25];
    int run;
    int wicket;
    int ball;
    int over;
    int nb;
};
int main()
{
    int choice, j, i, n, wide = 0, nb = 0, four = 0, six = 0, one = 0, two = 0, three = 0, D = 0, temp;
    int run = 0, wicket = 0, over = 0, ball = 0, striker = 0, nonstriker = 1, bowler;
    char select;
    struct bowler B[5];
    struct batsman S[11];
    for (i = 0; i < 11; i++)
    {
        S[i].score = 0;
        printf("Enter name of Batsman %d\n", i + 1);
        scanf("%s", S[i].name);
    }
    for (i = 0; i < 5; i++)
    {
        printf("Enter name of Bowler %d\n", i + 1);
        scanf("%s", B[i].name);
        B[i].wicket = 0;
        B[i].run = 0;
        B[i].ball = 0;
        B[i].over = 0;
        B[i].nb = 0;
    }
    printf("Enter the Number of overs in the match");
    scanf("%d", &n);
    printf("\nLET THE MATCH BEGIN\n");
    printf("\nScore : %d/%d\n", run, wicket);
    printf("Over : %d.%d\n", over, ball);
    printf("*******************************\n");
    for (j = 0; j < 11; j++)
    {
        while (over < n)
        {
            while (ball < 6)
            {

                printf("Enter Score on this ball \n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 0:
                {
                    printf("W for wicket\nD for Dot\nN for No Ball\n");
                    scanf(" %c", &select);
                    switch (select)
                    {
                    case 'W':
                        wicket = wicket + 1;
                        ball = ball + 1;
                        striker++;
                        B[bowler].wicket += 1;
                        if (striker == nonstriker)
                            striker++;
                        break;
                    case 'D':
                        ball = ball + 1;
                        D += 1;
                        break;
                    case 'N':
                        printf("FREE HIT");
                        B[bowler].nb += 1;
                        nb += 1;
                        break;
                    }
                    break;
                }
                case 1:
                {
                    printf("S for Single\nW for Wide\nN for No Ball\n");
                    scanf(" %c", &select);
                    switch (select)
                    {
                    case 'S':
                        run = run + 1;
                        S[striker].score += 1;
                        B[bowler].run += 1;
                        ball = ball + 1;
                        temp = striker;
                        striker = nonstriker;
                        nonstriker = temp;
                        break;
                    case 'W':
                        wide = wide + 1;
                        run = run + 1;
                        striker++;
                        B[bowler].run += 1;
                        break;
                    case 'N':
                        run += 1;
                        S[striker].score += 1;
                        nb += 1;
                        B[bowler].run += 1;
                        B[bowler].nb += 1;
                        printf("FREE HIT");
                        break;
                    default:
                        printf("Invalid input\n");
                    }
                    break;
                }
                case 2:
                {
                    printf("T for Two Runs\nN for No Ball\n");
                    scanf(" %c", &select);
                    switch (select)
                    {
                    case 'T':
                        two = two + 1;
                        run = run + 2;
                        B[bowler].run += 2;
                        ball = ball + 1;
                        S[striker].score += 2;
                        break;
                    case 'N':
                        run += 2;
                        nb += 1;
                        B[bowler].run += 2;
                        B[bowler].nb += 1;
                        printf("FREE HIT");
                        break;
                    default:
                        printf("Invalid input\n");
                    }
                    break;
                }
                case 3:
                {
                    printf("T for Three Runs\nN for No Ball\n");
                    scanf(" %c", &select);
                    switch (select)
                    {
                    case 'T':
                        three = three + 1;
                        run = run + 3;
                        S[striker].score += 3;
                        B[bowler].run += 3;
                        ball = ball + 1;
                        temp = striker;
                        striker = nonstriker;
                        nonstriker = temp;
                        break;
                    case 'N':
                        run += 3;
                        nb += 1;
                        B[bowler].nb += 1;
                        B[bowler].run += 3;
                        temp = striker;
                        striker = nonstriker;
                        nonstriker = temp;
                        S[striker].score += 3;
                        printf("FREE HIT");
                        break;
                    default:
                        printf("Invalid input\n");
                    }
                    break;
                }
                case 4:
                {
                    printf("F for Four Runs\nN for No Ball\n");
                    scanf(" %c", &select);
                    switch (select)
                    {
                    case 'F':
                        four = four + 1;
                        run = run + 4;
                        S[striker].score += 4;
                        B[bowler].run += 4;
                        ball = ball + 1;
                        break;
                    case 'N':
                        run += 4;
                        nb += 1;
                        B[bowler].nb += 1;
                        B[bowler].run += 4;
                        S[striker].score += 4;
                        printf("FREE HIT");
                        break;
                    default:
                        printf("Invalid input\n");
                    }
                    break;
                }
                case 6:
                {
                    printf("S for Six Runs\nN for No Ball\n");
                    scanf(" %c", &select);
                    switch (select)
                    {
                    case 'S':
                        six = six + 1;
                        run = run + 6;
                        S[striker].score += 6;
                        B[bowler].run += 6;
                        ball = ball + 1;
                        nb += 1;
                        printf("BYE");
                        break;
                    case 'N':
                        run += 6;
                        B[bowler].run += 6;
                        B[bowler].nb += 1;
                        S[striker].score += 6;
                        printf("FREE HIT");
                        break;
                    default:
                        printf("Invalid input\n");
                    }
                    printf("HELLO");
                    break;
                }
                printf("Hello");
                }
                if (ball == 6)
                {
                    ball = 0;
                    over += 1;
                    B[bowler].over += 1;
                    temp = striker;
                    striker = nonstriker;
                    nonstriker = temp;
                    if (over == n)
                    {
                        break;
                    }
                }
                printf("\nScore : %d/%d\n", run, wicket);
                printf("Over : %d.%d\n", over, ball);
                printf("*******************************\n");
                printf("%s* : %d", S[striker].name, S[striker].score);
                printf("\n%s : %d\n\n", S[nonstriker].name, S[nonstriker].score);
                printf("%s      %d-%d  (%d.%d)\n", B[bowler].name, B[bowler].wicket, B[bowler].run, B[bowler].over, ball);
                printf("*******************************\n");
            }
        }
    }
    printf("\n**************\nMATCH ENDED\n**************\n");
    printf("*******************************\n");
    printf("\nFinal Score : %d/%d\n", run, wicket);
    printf("Over : %d.%d\n", over, ball);
    printf("*******************************\n");
    for (i = 0; i < 11; i++)
    {
        printf("%s \nScore=%d\n", S[i].name, S[i].score);
    }
    return 0;
}
