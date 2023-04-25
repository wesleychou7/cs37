#include<iostream>
#include<vector>
using namespace std;

// pass user int and a reference to the vector, check for duplicate, if no duplicate, insert into vector
void userInput(vector<int>& numbers){

    int input;
    cout << "Enter integers between 10-100. Enter 0 to stop." << endl;
    cin >> input;

    bool isDuplicate = false;

    while(input != 0){

        if (input > 100 || input < 10){
            cout << "Invalid input. Enter integers between 10-100. Enter 0 to stop." << endl;
            cin >> input;
            continue;
        }

        for (int i=0; i<numbers.size(); i++){
            if (input == numbers[i]){
                isDuplicate = true;
                break;
            }
        } 
        if (!isDuplicate){
            numbers.push_back(input);
        }
        isDuplicate = false;

        cin >> input;
    } 
}

// pass a reference to the vector, sort the vector
void sortVector(vector<int>& numbers){
    sort(numbers.begin(), numbers.end());
}

// pass a constant reference to the vector, print the vector
void printVector(const vector<int>& numbers){
    cout << "Sorted vector: ";
    for (int num : numbers){
        cout << num << " ";
    }
}

int main(){

    vector<int> nums;
    userInput(nums);
    sortVector(nums);
    printVector(nums);
}