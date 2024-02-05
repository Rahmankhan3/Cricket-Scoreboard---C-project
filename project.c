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
    int ballscore;
    int wicket;
    int ball;
    int over;
};
void team(struct batsman S[],struct batsman K[],int n)
{
    int choice, j, i, wide = 0, nb = 0, four = 0, six = 0, one = 0, two = 0, three = 0, D = 0, temp;
    int run = 0, wicket = 0, over = 0, ball = 0, striker = 0, nonstriker = 1, bowler;
    char select;
    printf("\nLET THE MATCH BEGIN\n");
    printf("\nScore : %d/%d\n", run, wicket);
    printf("Over : %d.%d\n", over, ball);
    printf("*\n");

    for (j = 0; j < 11; j++)
    {
        while (over < n)
        {
            while (ball < 6)
            {
                if (ball == 0)
                {
                    printf("\nSelect the bowler\n");
                    for (i = 0; i < 11; i++)
                    {
                        printf("%d. %s\n", i + 1, K[i].name);
                    }
                    scanf("%d", &bowler);
                    bowler -= 1;
                }

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
                        if (striker == nonstriker)
                            striker++;
                        K[bowler].wicket += 1;
                        K[bowler].ball += 1;
                        break;
                    case 'D':
                        ball = ball + 1;
                        K[bowler].ball += 1;
                        D += 1;

                        break;
                    case 'N':
                        printf("FREE HIT");
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
                        K[bowler].ballscore += 1;
                        S[striker].score += 1;
                        ball = ball + 1;
                        K[bowler].ball += 1;
                        temp = striker;
                        striker = nonstriker;
                        nonstriker = temp;
                        break;
                    case 'W':
                        wide = wide + 1;
                        K[bowler].ballscore += 1;
                        run = run + 1;

                        striker++;
                        wide += 1;
                        break;
                    case 'N':
                        run += 1;
                        K[bowler].ballscore += 1;
                        S[striker].score += 1;
                        nb += 1;
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
                        K[bowler].ballscore += 2;
                        run = run + 2;
                        ball = ball + 1;
                        K[bowler].ball += 1;
                        S[striker].score += 2;
                        break;
                    case 'N':
                        run += 2;
                        K[bowler].ballscore += 2;
                        nb += 1;
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
                        K[bowler].ballscore += 3;
                        S[striker].score += 3;
                        ball = ball + 1;
                        K[bowler].ball += 1;
                        temp = striker;
                        striker = nonstriker;
                        nonstriker = temp;
                        break;
                    case 'N':
                        run += 3;
                        K[bowler].ballscore += 3;
                        nb += 1;
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
                        K[bowler].ballscore += 4;
                        S[striker].score += 4;
                        ball = ball + 1;
                        K[bowler].ball += 1;
                        break;
                    case 'N':
                        run += 4;
                        K[bowler].ballscore += 4;
                        nb += 1;
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
                        K[bowler].ballscore += 6;
                        S[striker].score += 6;
                        ball = ball + 1;
                        K[bowler].ball += 1;
                        nb += 1;
                        break;
                    case 'N':
                        run += 6;
                        K[bowler].ballscore += 6;
                        S[striker].score += 6;
                        printf("FREE HIT");
                        break;
                    default:
                        printf("Invalid input\n");
                    }
                    break;
                }
                }
                if (ball == 6)
                {
                    ball = 0;
                    K[bowler].ball = 0;
                    K[bowler].over += 1;
                    over += 1;
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
                printf("\n");
                printf("%s* : %d", S[striker].name, S[striker].score);
                printf("\n%s : %d\n", S[nonstriker].name, S[nonstriker].score);
                printf("\n\n %s   %d-%d (%d.%d)", K[bowler].name, K[bowler].wicket, K[bowler].score, K[bowler].over, K[bowler].ball);
                printf("\n\n");
            }
        }
    }
    printf("\n\nMATCH ENDED\n*\n");
    printf("*\n");
    printf("\nFinal Score : %d/%d\n", run, wicket);
    printf("Over : %d.%d\n", over, ball);
    printf("\n");
    for (i = 0; i < 11; i++)
    {
        printf("%s \nScore=%d\n", S[i].name, S[i].score);
    }
}
int main()
{
int i,n;
        printf("Enter the number of over in the match\n");
        scanf("%d",&n);
    struct batsman S[11];
    struct batsman K[11];
    for (i = 0; i < 11; i++)
    {
        printf("Enter name of Batsman %d\n", i + 1);
        scanf("%s", S[i].name);
        S[i].score = 0;
        S[i].ballscore = 0;
        S[i].wicket = 0;
        S[i].over = 0;
        S[i].ball = 0;
    }
    for (i = 0; i < 11; i++)
    {
        printf("Enter name of Batsman %d\n", i + 1);
        scanf("%s", K[i].name);
        K[i].score = 0;
        K[i].ballscore = 0;
        K[i].wicket = 0;
        K[i].over = 0;
        K[i].ball = 0;
    }
   team(S,K,n);
   printf("\n\n\nTEAM 2\n\n\n");
team(K,S,n);
    return 0;
}
