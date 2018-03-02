#include <iostream>

using namespace std;

int one = 0;
int zero = 0;



int fib_rec(int n){
    if(n == 0){
        zero++;
        return 0;
    }
    else if(n==1){
        one++;
        return 1;
    }
    else return fib_rec(n-1)+fib_rec(n-2);
}

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int num;
        cin >> num;
        fib_rec(num);
        cout << zero << " " << one << endl;
        zero = 0;
        one = 0;
    }
    return 0;

}