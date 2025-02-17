#include <stdio.h>

int main() {
    int n;
    printf("enter no of processes:");
    scanf("%d",&n);
    int BT[n],indices[n],k=0,WT[n];
    float res=0,avg;
    for(int i=0;i<n;i++){
        printf("enter burst time of p%d:",i+1);
        scanf("%d",&BT[i]);
        indices[i]=i;
    }
     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (BT[indices[j]] > BT[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        WT[indices[i]]=k;
        res+=k;
        k+=BT[indices[i]];
    }
    avg=res/n;
    printf("Processes\tBurst Time\tWaiting Time\n");
    for(int i=0;i<n;i++){
        printf("\tP%d\t\t\t %d\t\t\t %d\t\n",i+1,BT[i],WT[i]);
    }
    printf("Average WAiting time :%f",avg);
}
