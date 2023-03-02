#include<iostream>
#include<array>
using namespace std;

int main(){

    array<int,300> arr;

    for (size_t i=0; i < arr.size(); i++){
        arr[i] = 1;
    }

    for (size_t i=2; i < arr.size(); i++){

        if (arr[i]){ // arr[i] is prime; arr[i] == 1

            for (size_t j=i+1; j < arr.size(); j++){
                if (j % i == 0){
                    arr[j] = 0;
                }
            }
        }
    }

    int count = 0;
    for (size_t i=2; i < arr.size(); i++){
        if (arr[i]){
            cout << i << " ";
            count ++;
        }
    }
    cout << "\nNumber of prime numbers: " << count;

    return 0;
}