#include <iostream>
#include <stdio.h>
using namespace std;

int input[1000][3];
int result[1000][3];

int rgb(int n){
    for(int i=0; i<n; i++){
        if(i == 0){
            result[0][0] = input[0][0];
            result[0][1] = input[0][1];
            result[0][2] = input[0][2];

        }
        else{
            int a = result[i-1][0];
            int b = result[i-1][1];
            int c = result[i-1][2];
            result[i][0] += (input[i][0]+((b>c) ? c:b));
            result[i][1] += (input[i][1]+((a>c) ? c:a));
            result[i][2] += (input[i][2]+((a>b) ? b:a));
        }
    }
    int small = result[n-1][0];
    if(small > result[n-1][1]) small = result[n-1][1];
    if(small > result[n-1][2]) small = result[n-1][2];
    return small;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j=0; j<3; j++){
            int k;
            cin >>k;
            input[i][j] = k;
        }
    }
    
    cout << rgb(N) << endl;

    return 0;
}