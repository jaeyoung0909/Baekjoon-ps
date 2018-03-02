#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char input1[1000];
    char input2[1000];
    int comp[1001][1001] = {};
    scanf("%s %s", input1, input2);
    for(int i=1; i < strlen(input2)+1; i++){
        for(int j=1; j< strlen(input1)+1; j++){
            if(input1[j-1]==input2[i-1])    comp[i][j]=comp[i-1][j-1]+1;
            else{
                comp[i][j] = (comp[i][j-1] > comp[i-1][j]) ? comp[i][j-1] : comp[i-1][j];
            }
        }
    }
    int len = comp[strlen(input2)][strlen(input1)];
    int row = strlen(input2);
    char result[len];
    result[len] = '\n';

    for(int j=strlen(input1); j>0; j--){
        if(comp[row][j]==comp[row][j-1]) continue;
        else if(comp[row][j] == comp[row-1][j]){
            while(comp[row][j]==comp[row-1][j]){
                row--;
            }
        }
        len--;
        result[len]=input1[j-1];
        row--;
    }
    
    printf("%d\n", comp[strlen(input2)][strlen(input1)]);
    printf("%s", result);
}