#include <stdio.h>

using namespace std;

int input[100000];
int dyn[100000];

int main(){
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++){
        int c;
        scanf("%d", &c);
        input[i] = c;
    }
    int max = input[0];
    for(int i=0; i<T; i++){
        if(i==0) dyn[i] = input[i];
        else dyn[i] = (dyn[i-1]+input[i] > input[i])?dyn[i-1]+input[i]:input[i];
        max = (max > dyn[i])?max:dyn[i];
    }
    printf("%d\n", max);

    return 0;
}