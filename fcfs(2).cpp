#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,n,temp=0,GC=0,P[100],AT[100],BT[100],TAT[100],WT[100],CT[100],tTAT,tWT,avgtTAT,avgtWT;
    float tp;
    printf("Enter The Number Of Processes");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        P[i]=i;
        printf("Enter The AT Of %d \n",i);
        scanf("%d",&AT[i]);
        printf("Enter The BT Of %d ",i);
        scanf("%d",&BT[i]);
    }
    for (i=0 ; i < n - 1; i++)
    {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (AT[j] > AT[j+1])
      {
        temp       = AT[j];
        AT[j]   = AT[j+1];
        AT[j+1] = temp;
        temp       = BT[j];
        BT[j]   = BT[j+1];
        BT[j+1] = temp;
        temp       = P[j];
        P[j]   = P[j+1];
        P[j+1] = temp;
        }
        }
    }
    for(i=0;i<n;i++){
        GC=GC+BT[i];
        CT[i]=GC;
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-BT[i];
        tTAT=tTAT+TAT[i];
        tWT=tWT+WT[i];
    }
    printf("P AT BT TAT WT CT\n");
    for(i=0;i<n;i++){
        printf("%d %d  %d  %d   %d  %d\n",P[i],AT[i],BT[i],TAT[i],WT[i],CT[i]);
    }
    avgtTAT=tTAT/n;
    avgtWT=tWT/n;
    tp=n/GC;
    printf("Total TAT Is %d ",tTAT);
    printf("Total TAT Is %d ",avgtTAT);
    printf("Total WT Is %d ",tWT);
    printf("Total TAT Is %d ",avgtWT);
    printf("Throughput  Is %f ",tp);
    return 0;
}