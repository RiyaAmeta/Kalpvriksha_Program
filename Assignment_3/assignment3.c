#include<stdio.h>
#include<math.h>
int main(){
    int B;
    int N;
    int M;
    int answer=1;
    
    scanf("%d",&B);
    scanf("%d",&N);
    scanf("%d",&M);
    if(M<1){
        printf("Modulus value M should be greater than 1\n");
        return 0;
    }
    B = B %  M;
    while(N>0){
        if(N%2 ==1){
            answer = (answer*B) % M;
        }
        N = N/2;
        B = (B*B) % M;
    }
    printf("%d",answer);
    return 0;
}
