#include <stdio.h>
#include <algorithm>

using namespace std;

int Stair[300];
int Result[300];

void dynamic(int n){
    
    for(int i = 0; i<n; i++){
        if(i==0){
            Result[i] = Stair[0];
            
        }   
        else if(i==1){
            Result[i] = Stair[i] + Result[i-1]; 
        }
        else if(i==2){
            Result[i] = Stair[i] + ((Stair[i-1]>Stair[i-2]) ? Stair[i-1] : Stair[i-2]);
        }
        
        else{
            Result[i] = Stair[i]+max(Result[i-3]+Stair[i-1],Result[i-2]);
        }
        
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int cost;
        scanf("%d", &cost);
        Stair[i] = cost;
    }
    dynamic(n);
    printf("%d\n", Result[n-1]);
    return 0;
}