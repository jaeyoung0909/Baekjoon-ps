#include <iostream>
#include <algorithm>

using namespace std;

int main(){ 
    int dwarfs[9] = {0};
    int sum =0 ;
    for(int i=0; i<9; i++){
        int dwarf;
        cin >> dwarf;
        sum+= dwarf;
        dwarfs[i] = dwarf;
    }
    sort(dwarfs, dwarfs+9);
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(sum - dwarfs[i]-dwarfs[j]==100){
                for(int k=0; k<9; k++){
                    if(k !=i && k!=j){
                        cout << dwarfs[k] << endl;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}