#include<stdio.h>

void main(){
    int n,i;
    printf("enter number of processess:");
    scanf("%d",&n);
    int wt[n],B[n],P[n],ind[n],temp;
    for(i=0;i<n;i++){
        printf("enter the burst time  of Processess P%d : ",i+1);
        scanf("%d",&B[i]);
    }
    for(i=0;i<n;i++){
        printf("enter the priority of Processess P%d : ",i+1);
        scanf("%d",&P[i]);
        ind[i]=i;
    }
    for(i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(P[ind[j]]>P[ind[j+1]]){
                temp=ind[j];
                ind[j]=ind[j+1];
                ind[j+1]=temp;
            }
        }
    }
    wt[ind[0]]=0;
    int sum=0;
    float tot=0;
    for( i=1;i<n;i++){
        sum+=B[ind[i-1]];
        wt[ind[i]]=sum;
    }
    printf("PROCESSESS\tBURST TIME\tPRIORITY\tWAITING TIME\n");
    for(i=0;i<n;i++){
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n",ind[i]+1,B[ind[i]],P[ind[i]],wt[ind[i]]);
        tot+=wt[ind[i]];
    }
    printf("Average Waiting Time is: %f",tot/n);

}
