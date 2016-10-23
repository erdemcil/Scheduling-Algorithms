#include "Header.h"



void RoundRobin()
{

  int numOfProcess,remaining, flag = 0,time,quantum,i,j;
  int waitingtTime = 0,turnAroundTime = 0,arrivalTime[10],burstTime[10],responseTime[10];
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
  remaining = numOfProcess;
  for(i = 0; i < numOfProcess; i++)
  {
    printf("\nEnter Arrival Time for per Processor P(%d): ",i+1);
    scanf("%d",&arrivalTime[i]);
    printf("Enter Burst   Time for per Processor P(%d): ",i+1);
    scanf("%d",&burstTime[i]);

    responseTime[i]=burstTime[i];
  }
  printf("\nEnter the time of Quantum: ");
  scanf("%d",&quantum);
  printf("\nProcess Number  Burst Time\tWaiting Time    TurnAround Time   Arrival Time\n");

  for(time = 0,i = 0; remaining != 0;)
  {
    if(responseTime[i]<=quantum && responseTime[i]>0)
    {
      time += responseTime[i];
      responseTime[i] = 0;
      flag = 1;
    }
    else if(responseTime[i]>0)
    {
      responseTime[i] -= quantum;
      time += quantum;
    }
    if(responseTime[i]==0 && flag==1)
    {
      remaining--;
      printf("\nP(%d)   \t\t%d\t\t%d\t\t%d\t\t  %d",i+1, burstTime[i],time - arrivalTime[i] - burstTime[i], time - arrivalTime[i], arrivalTime[i]);
      waitingtTime += time - arrivalTime[i] - burstTime[i];
      turnAroundTime += time - arrivalTime[i];
      flag=0;
    }
    if(i == numOfProcess - 1)
      i=0;
    else if(arrivalTime[i+1] <= time)
      i++;
    else
      i=0;
  }
  printf("\n\nAverage Waiting Time = %.2f\n",waitingtTime* 1.0 / numOfProcess);

}
