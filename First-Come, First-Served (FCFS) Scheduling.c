#include<stdio.h>

int main()
{
    int numOfProcess,burstTime[10],waitingTime[10],turnAroundTime[10],averageWaitingTime=0,i,j;
    do{
        printf("Number of processes:");
        scanf("%d",&numOfProcess);
        if (numOfProcess>10 || numOfProcess <1)
        {
            printf("Please enter a process number between 1 and 10 !!!\n");
            printf("\n");
        }

    }
    while(numOfProcess>10 || numOfProcess <1);

    printf("\nEnter Burst Times for per Processor\n");

    for(i=0; i<numOfProcess; i++)
    {
        printf("P(%d):",i+1);
        scanf("%d",&burstTime[i]);
    }
    waitingTime[0]=0;//waiting time first unit is 0

    //Waiting time evaluations
    for(i=1; i<numOfProcess; i++)
    {
        waitingTime[i]=0;
        for(j=0;j<i;j++)
            waitingTime[i]+=burstTime[j];
    }

    printf("\nProcess Number          Burst Time      Waiting Time    TurnAround Time");

    //Turnaround time evaluating
    for(i=0; i<numOfProcess; i++)
    {
        turnAroundTime[i]= burstTime[i]+ waitingTime[i];
        averageWaitingTime += waitingTime[i];
        printf("\nP(%d)  \t\t\t%d\t\t%d\t\t%d",i+1,burstTime[i],waitingTime[i],turnAroundTime[i]);
    }

    averageWaitingTime /= i;
    printf("\n\nAverage Waiting Time: %d",averageWaitingTime);
    printf("\n");

    return 0;
}
