#include <stdio.h>
using namespace std;

int main(){
    int A;
    int B;
    int C;
    int cnt = 0;
    scanf("%d %d %d",&A, &B, &C);
    while(C-B != 1 || B-A != 1){
        if(C-B > B-A){
            A = B;
            B = C-1;
        }
        else{
            C = B;
            B = A+1;
        }
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}