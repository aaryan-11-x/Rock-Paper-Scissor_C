#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

void delay(int a){
int i, add, time;
time = a*80000000;
for(i=0; i<time; i++){
    add *= i;
    add++;
    add++;
 }
}
int main(){
    char play1[20];
    printf("Please Enter Your Name : ");
    scanf("%s", &play1);

    int n, choice, play1pts=0, cpupts=0;
    printf("Enter How Many Times You Want To Play The Game : ");
    scanf("%d", &n);

    printf("\nRules Of The Game :-\n1) %d Rounds Will Be Played\n2) Commands:-\n   0 For Rock\n   1 For Paper\n   2 For Scissor\n", n);
    printf("\nGame Starts In 3.....2....1... ");
    delay(3);
    printf("\nGame Begins");
    for(int i=0; i<n; i++){
        printf("\n\nRound %d:-\n", i+1);
        printf("\nRock, Paper Or Scissor : ");
        scanf("%d", &choice);
        if(choice==0)
            printf("\nYou Chose : Rock\n");
        else if(choice==1)
            printf("\nYou Chose : Paper\n");
        else if(choice==2)
            printf("\nYou Chose : Scissor\n");
        else{
            printf("Wrong Option, Please Select The Correct One");
            break;
        }

        srand(time(NULL));
        int cpu = rand()%2;

        if(cpu==0)
            printf("CPU Chose : Rock\n");
        else if(cpu==1)
            printf("CPU Chose : Paper\n");
        else if(cpu==2)
            printf("CPU Chose : Scissor\n");

        if(choice==0&&cpu==0 || choice==1&&cpu==1 || choice==2&&cpu==2){
            printf("\nRound %d Result : Draw!", i+1);
        }
        else if(choice==0&&cpu==1 || choice==1&&cpu==2 || choice==2&&cpu==0){
            printf("\nRound %d Result : CPU Won!", i+1);
            cpupts++;
        }
        else if(choice==0&&cpu==2 || choice==1&&cpu==0 || choice==2&&cpu==1){
            printf("\nRound %d Result : %s Won!", i+1, play1);
            play1pts++;
        }
    }
    printf("\n\nFinal Result:-\n");
    printf("Points %s Won : %d\n", play1, play1pts);
    printf("Points CPU Won : %d\n\n", cpupts);

    if(play1pts>cpupts)
        printf("Congratulations, %s Has Won!\n", play1);
    else if (play1pts<cpupts)
        printf("CPU Won, Better Luck Next Time:(\n");
    else
        printf("It's A Draw!\n");

    printf("\nThank You For Playing The Game!\n");
}
