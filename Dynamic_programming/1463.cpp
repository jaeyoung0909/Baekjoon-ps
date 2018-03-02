#include <stdio.h>
#include <vector>

using namespace std;

int result=0;
int t = 0;
int cnt = 0;

void dfs(int n){

    if(n==1){
        if(!t){
            result=cnt;
            t++;
        } 
        if(t && cnt < result) result=cnt;
        return;
    }
    if(n%3==0){
        cnt++;
        if(t && result <= cnt){
            cnt--;
            return;
        }
        dfs(n/3);
        cnt--;
    }
    if(n%2==0){
        cnt++;
        if(t && result <= cnt){
            cnt--;
            return;
        }
        dfs(n/2);
        cnt--;
    }
    
    cnt++;
    if(t && result <= cnt){
            cnt--;
            return;
        }
    n--;
    dfs(n);
    cnt--;

}

int main(){
    int n;
    scanf("%d", &n);
    dfs(n);
    int min;
    
    printf("%d\n", result);
    
    return 0;
}