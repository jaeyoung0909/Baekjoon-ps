#include <iostream>
#include <string.h>
#include <vector>


using namespace std;

int Find_ant(int N, int L, int K);
int find_result(int target, int N, int L, int* ants_p, int *ants_a);
void swap(int *arr, int a, int b);
int partition(int *arr_p, int *arr_a, int left, int right);
int quickselect(int *arr_p, int *arr_a, int left, int right, int select);


int main(){
    int T;
    cin >> T;
    int *kth_ant = new int[T];
    for(int i = 0; i < T; i++){
        int N, L, K;
        cin >> N;
        cin >> L;
        cin >> K;
        cout <<Find_ant(N, L, K) << endl;
    }
    delete [] kth_ant;

    return 0;
}

int Find_ant(int N, int L, int K){
    int target = 0;
    int *ants_p = new int[N];
    int *ants_a = new int[N];

    for(int i = 0; i < N; i++){
        int p, a;
        cin >> p;
        cin >> a;
        if(a < 0)   ants_p[i] = p;
        else    ants_p[i] = L - p;
        ants_a[i] = a;

   }
//
//    for(int i = 0; i < N; i++)
//        int temp = i;
//        for(int j = i; j < N; j++){
//            if(ants_p[temp] > ants_p[j]){
//                temp = j;
//            }       
//        }
//        swap(ants_p, temp, i);
//        swap(ants_a, temp, i);
//
//    }
//
    cout << "K+1th number : "<<quickselect(ants_p, ants_a, 0, N-1, K+1)<<endl;
//    cout << quickselect(ants_p, ants_a, 0, N-1, K)<<endl; 
//    cout << quickselect(ants_p, ants_a, 0, N-1, K+1)<<endl; 
    cout << "these are arr_p value : "<< ants_a[K-1] << endl;
    cout << "these are arr_p value : "<< ants_a[K] << endl;
    cout << "these are arr_p value : "<< ants_a[K+1] << endl;


    if(K != 0 && N > 1 && ants_p[K] == ants_p[K-1]){
 
        if(ants_a[find_result(K, N, L, ants_p, ants_a)] < ants_a[find_result(K-1, N, L, ants_p, ants_a)]){
            swap(ants_p, K, K-1);
            swap(ants_a, K, K-1);
        }
    }
    else if(K > 1 && N > 2 && ants_p[K-1] == ants_p[K-2]){
        if(ants_a[find_result(K-1, N, L, ants_p, ants_a)] < ants_a[find_result(K-2, N, L, ants_p, ants_a)]){
            swap(ants_p, K-2, K-1);
            swap(ants_a, K-2, K-1);
        }
    }

    int result = ants_a[find_result(K-1, N, L, ants_p, ants_a)]; 
    
    delete [] ants_p;
    delete [] ants_a;
    
    return result;
}


void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int *arr_p, int *arr_a, int left, int right){
    int pos = arr_p[left];
    int low = left + 1, high = right;
    while(low<=high)
    {
        while(low <= right && arr_p[low] <= pos)  low++;
        while(high >= (left+1) && arr_p[high] >= pos) high--;
        if(low <= high){
            swap(arr_p, high, low);
            swap(arr_a, high, low);
        }
    }
    swap(arr_p, high, low);
    swap(arr_a, high, low);
    return high;
}

int quickselect(int *arr_p, int*arr_a, int left, int right, int select){
    if (select > 0 && select <= right - left + 1){
        int pos = partition(arr_p, arr_a, left, right);
        if(pos - left == select - 1)    return arr_p[pos];
        else if (pos-left > select -1)  return quickselect(arr_p, arr_a, left, pos-1, select);
        else    return quickselect(arr_p, arr_a, pos+1, right, select -pos + left -1 );
        
    }
    return -1;
}


int find_result(int target, int N, int L, int* ants_p, int *ants_a){

    
    int result = target;
    for(int i = 0; i < N; i++){
        if(ants_a[target] < 0){
            if(ants_p[target]%2 == 0){
                if(i == target) continue;
                if(ants_p[i]%2 !=0) continue;
                if(ants_p[i] < ants_p[target])  continue;
                if((ants_a[i] < 0 && ants_p[target] < ants_p[i]) || (ants_a[i] > 0 && ants_p[target] < (L-ants_p[i]))) continue;
                else {
                    if(ants_p[result] <= ants_p[i]) result = i;
                }
            
            }
            else{
            
                if(i == target) continue;
                if(ants_p[i]%2 ==0) continue;
                if(ants_p[i] < ants_p[target])  continue;
                if((ants_a[i] < 0 && ants_p[target] < ants_p[i]) || (ants_a[i] > 0 && ants_p[target] < L-ants_p[i])) continue;
                else {
                    if(ants_p[result] <= ants_p[i]) result = i;
                }
            
            }
        }
        else{
            if(ants_p[target]%2 == 0){
     
                if(i == target) continue;
                if(ants_p[i]%2 !=0) continue;
                if(ants_p[i] < ants_p[target])  continue;
                if((ants_a[i] < 0 && L-ants_p[target] > ants_p[i]) || (ants_a[i] > 0 && L - ants_p[target] > L-ants_p[i])) continue;
                else {
                    if(ants_p[result] <= ants_p[i]) result = i;
                    if(ants_a[target] == -3) cout << "check : " << ants_a[result] << endl;
                }
            
            }
            else{
     
                if(i == target) continue;       
                if(ants_p[i]%2 ==0) continue;
                if(ants_p[i] < ants_p[target])  continue;
                if((ants_a[i] < 0 && L - ants_p[target] > ants_p[i]) || (ants_a[i] > 0 && L - ants_p[target] > L-ants_p[i])) continue;
                else {
                    if(ants_p[result] <= ants_p[i]) result = i;
                }
            
            }
        }
    }
    return result;
}


