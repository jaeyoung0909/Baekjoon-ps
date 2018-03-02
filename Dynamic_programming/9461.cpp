#include <stdio.h>

using namespace std;

long long test[101] = {};

void P(int n){
    for(int i=0; i<n;i++){
        if(test[i]) continue;
        else if(i==0) test[0]=1;
        else if(i==1) test[1]=1;
        else if(i==2) test[i]=1;
        else if(i==3) test[i]=2;
        else if(i==4) test[i]=2;
        else test[i] = test[i-1]+test[i-5];
    }
}

int main(){
  
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int n;
        scanf("%d", &n);
        P(n);
        printf("%lld\n", test[n-1]);
    }
    
    return 0;
}