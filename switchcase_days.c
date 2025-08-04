#include<stdio.h>
int main()
{
    int day;
    int s=0;
    while(!s)
    {
        printf("enter any day between 1to7 : ");
        scanf("%d",&day);
        switch(day)
        {
            case 1:
                printf("Monday");
                s=1;
                break;
            case 2:
                printf("Tuesday");
                s=1;
                break;
            case 3:
                printf("Wednesday");
                s=1;
                break;
            case 4:
                printf("Thursday");
                s=1;
                break;
            case 5:
                printf("Friday");
                s=1;
                break;
            case 6:
                printf("Saturday");
                s=1;
                break;
            case 7:
                printf("Sunday");
                s=1;
                break;
            default:
                printf("It's an invalid choice\nEnter a Correct Choice\n");
        }
    }
    return 0;
}
