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
int main()
{
    int choice, j, i, n, wide = 0, nb = 0, four = 0, six = 0, one = 0, two = 0, three = 0, D = 0;
    int run = 0, wicket = 0, over = 0, ball = 0,striker=0,nonstriker=0;
    char select;

    struct batsman S[11];
    for (i = 0; i < 11; i++)
    {
        printf("Enter name of Batsman %d\n", i + 1);
        scanf("%s", S[i].name);
    }
    printf("Enter the Number of overs in the match");
    scanf("%d", &n);

    printf("\nLET THE MATCH BEGIN\n");
    printf("\nScore : %d/%d\n", run, wicket);
    printf("Over : %d.%d\n", over, ball);
    printf("*******************************\n");

    for (j = 0; j < 11; j++)
    {
        int runb = 0;
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
                        goto label;
                    case 'D':
                        ball = ball + 1;
                        D+=1;
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
                        runb += 1;
                        ball = ball + 1;
                        break;
                    case 'W':
                        wide = wide + 1;
                        run = run + 1;
                      wide+=1;
                        break;
                    case 'N':
                        run += 1;
                        runb += 1;
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
                        run = run + 2;
                        runb += 2;
                        ball = ball + 1;
                        break;
                    case 'N':
                        run += 2;
                        runb += 2;
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
                        runb += 3;
                        ball = ball + 1;
                        break;
                    case 'N':
                        run += 3;
                        runb += 3;
                        nb += 1;
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
                        runb += 4;
                        ball = ball + 1;
                        break;
                    case 'N':
                        run += 4;
                        runb += 4;
                        nb += 1;
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
                        runb += 6;
                        ball = ball + 1;
                        nb += 1;
                        break;
                    case 'N':
                        run += 6;
                        runb += 6;
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
                    over += 1;
                    if (over == n)
                    {
                        break;
                    }
                }
                printf("\nScore : %d/%d\n", run, wicket);
                printf("Over : %d.%d\n", over, ball);
                printf("*******************************\n");
            }
        }
    label:
        S[j].score = runb;
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
