#include <iostream>
#include <algorithm>
using namespace std;

int input[500][500] ={};
int result[500][500] = {};

int dynamic(int n){
    int idx = 0;
    int output = 0;
    for(int i = 0; i<n;i++){
        if(idx < i){
            i=0;
            idx++;
        }
        if(i == 0 && idx == 0)  result[idx][i] = input[idx][i];
        else{
            if(i==0)    result[idx][i] = result[idx-1][i] + input[idx][i];
            else result[idx][i] = max(result[idx-1][i-1], result[idx-1][i]) + input[idx][i];
        }
        if(idx == n-1){
            if(i == 0)  output = result[idx][i];
            else{
                output = (output > result[idx][i]) ? output : result[idx][i];
            }
        }
    }
    return output;
}

int main(){
    int n;
    int idx = 0;
    cin >> n;
    for(int i=0; i < n; i++){
        int in;
        cin >> in;
        if(idx < i){
            i = 0;
            idx++;
        } 
        input[idx][i] = in;
    }
    cout << dynamic(n) << endl;
    return 0;
}