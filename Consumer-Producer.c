#include<stdio.h>
#include<stdlib.h>

int empty=5,full=0,mutex=1,x=0;
void Producer(){
    --mutex;
    ++full;
    x++;
    --empty;
    printf("Producer produces item %d\n",x);
    ++mutex;
}
void Consumer(){
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumed item %d\n",x);
    x--;
    ++mutex;
}
int main(){
    printf("1.Producer\n2.Consumer\n3.Exit\n");
    int n;
    while(1){
        printf("Enter Your Chioce: ");
        scanf("%d",&n);
        switch(n){
            case 1: if(mutex==1&&empty!=0){
                        Producer();
                    }
                    else{
                        printf("Buffer is full\n");
                    }
                    break;
            case 2: if(mutex==1&&full!=0){
                        Consumer();
                     }
                    else{
                        printf("Buffer is empty\n");
                    }
                    break;
            case 3: exit(0);
                    break;
        }
    }
}
