#include<stdio.h>


void main(){
    int n,i,temp;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int wt[n],B[n],ind[n];
    for(i=0;i<n;i++){
        printf("Enter the burst time for processess P%d: ",i+1);
        scanf("%d",&B[i]);
        ind[i]=i;
    }
    for(i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(B[ind[j]]>B[ind[j+1]]){
                temp=ind[j];
                ind[j]=ind[j+1];
                ind[j+1]=temp;
            }
        }
    }
    
    wt[ind[0]]=0;
    int sum=0;
    for( i=1;i<n;i++){
        sum+=B[ind[i-1]];
        wt[ind[i]]=sum;
    }
    float tot=0;
    printf("PROCESSESS\tBURST TIME\t WAITING TIME\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\n",ind[i]+1,B[ind[i]],wt[ind[i]]);
        tot+=wt[ind[i]];
    }
    printf("Average Waiting Time is: %f",tot/n);


}
