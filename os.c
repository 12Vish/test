#include<stdio.h>
#include<conio.h>
int main()
{
    int B_T[10],Process_no[10],W_T[10],T_A_T[10];
    int A_T[10],Prior[10],i,j,Number_of_Process,tot=0,flag,temp,Avg_W_T,Avg_T_A_T;
    printf("Enter Number of Process:");
    scanf("%d",&Number_of_Process);
    printf("\nEnter Burst Time and Prior\n");
    for(i=0;i<Number_of_Process;i++)
    {
        printf("\nP[%d]\n",(i+1));
        printf("Enter Burst Time:");
        scanf("%d",&B_T[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&A_T[i]);
        printf("Enter Prior:");
        scanf("%d",&Prior[i]);
        Process_no[i]=i+1;
    }
    for(i=0;i<Number_of_Process;i++)
    {
        flag=i;
        for(j=i+1;j<Number_of_Process;j++)
        {
            if(Prior[j]<Prior[flag])
            flag=j;
        }
        temp=Prior[i];
        Prior[i]=Prior[flag];
        Prior[flag]=temp;
        temp=B_T[i];
        B_T[i]=B_T[flag];
        B_T[flag]=temp;
        temp=Process_no[i];
        Process_no[i]=Process_no[flag];
        Process_no[flag]=temp;
    }
    W_T[0]=0;  
    for(i=1;i<Number_of_Process;i++)
    {
        W_T[i]=0;
        for(j=0;j<i;j++)
            W_T[i]+=B_T[j];
        tot+=W_T[i];
    }
    Avg_W_T=tot/Number_of_Process;  
    tot=0;
    printf("_______________________________________________________________");
    printf("\nProcess\t       B T              W T                T A T");
    for(i=0;i<Number_of_Process;i++)
    {
        T_A_T[i]=B_T[i]+W_T[i];  
        tot+=T_A_T[i];
        printf("\nProcess %d \t %d\t \t   %d\t\t%d",Process_no[i],B_T[i],W_T[i],T_A_T[i]);
    }
        printf("\n_______________________________________________________________");
    Avg_T_A_T=tot/Number_of_Process;
    printf("\n\nAvg W T= %d",Avg_W_T);
    printf("\nAvg T A T= %d",Avg_T_A_T);
    return 0;
    getch();
}
