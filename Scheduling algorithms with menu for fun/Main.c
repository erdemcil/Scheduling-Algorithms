/* Function: CPU Scheduling Algorithms Evaluation                     **
** FCFS, SJF, Priority, Round Robin and Multilevel Queue Evaluations. **
** Programmers: Erdem Cil, Omer Gokdere                               */


#include "Header.h"



void delay(int milliseconds);

int main(void)
{
    int menuChooseInt;
    char menuChooseChar;
    char str[] = "Hello World...\nWelcome To CPU Scheduling Algorithms Evaluation Program version 0.12 Alpha Build\nPlease press menu keys to continue..";
    char menuDialogue1[] = "\n\n1) First-Come, First-Served (FCFS) Scheduling Evaluation\n2) Shortest-Job-First (SJF) Scheduling Evaluation\n3) Priority Scheduling Evaluation\n4) Round Robin (RR) Evaluation\n";
    char menuDialogue2[] = "\n\n If you want to continue from another evaluation enter (y), if you want to quit from CPU Scheduling Algorithms Evaluation Program version 0.12 Alpha Build please enter (n).";
    char menuDialogueError1[] ="\n\n Please enter an integer value between 1-4!!";
    char menuDialogueError2[] ="\n\n Please enter (y) to continue from another evaluation or (n) to quit from CPU Scheduling Algorithms Evaluation Program version 0.12 Alpha Build!!";


    delayedDisplay(str, 75);
    fflush(stdin);

    do{

        delayedDisplay(menuDialogue1, 25);
        fflush(stdin);
        scanf("%d", &menuChooseInt);
        if(menuChooseInt != 1 && menuChooseInt != 2 && menuChooseInt != 3 && menuChooseInt != 4)
                    delayedDisplay(menuDialogueError1, 50);

    }
    while( menuChooseInt != 1 && menuChooseInt != 2 && menuChooseInt != 3 && menuChooseInt != 4);

    if(menuChooseInt == 1)
        FirstComeFirstServed();
    else if(menuChooseInt == 2)
        ShortestJobFirst();
    else if(menuChooseInt == 3)
        PriorityQueue();
    else
        RoundRobin();



    delayedDisplay( menuDialogue2, 25 );
    fflush( stdin );
    scanf( "%c", &menuChooseChar );
    do{
            if( menuChooseChar == 'y' || menuChooseChar == 'Y' )
            {
                do{
                    delayedDisplay(menuDialogue1, 25);
                    fflush(stdin);
                    scanf("%d", &menuChooseInt);
                    if(menuChooseInt != 1 && menuChooseInt != 2 && menuChooseInt != 3 && menuChooseInt != 4)
                        delayedDisplay(menuDialogueError1, 50);
                    }
                    while( menuChooseInt != 1 && menuChooseInt != 2 && menuChooseInt != 3 && menuChooseInt != 4);

                    if(menuChooseInt == 1)
                        FirstComeFirstServed();
                    else if(menuChooseInt == 2)
                        ShortestJobFirst();
                    else if(menuChooseInt == 3)
                        PriorityQueue();
                    else
                        RoundRobin();
             }
             else
             {
             fflush( stdin );
             scanf( "%c", &menuChooseChar );
             }
        }while( menuChooseChar != 'q' && menuChooseChar != 'Q' );



    return 0;
}
