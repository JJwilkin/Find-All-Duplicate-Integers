//Joshua Wilkinson
// Return all elements appearing more than once
// [3,1,5,3,2,3,5,4,1]
// returns [3,1,5]
#include <iostream>
#include <vector>
using namespace std;

//FUNCTION DECLARATION
vector <int> non_duplicate(vector <int> arr);

//MAIN DRIVER
int main() {
    int myints[] = {3,1,5,3,2,3,5,4,1};
    vector<int> vec (myints, myints + sizeof(myints) / sizeof(int) );//Intializing a vector from an array
    
    vector<int> output = non_duplicate(vec);

     for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}

//FUNCTION DEFINITION
vector <int> non_duplicate (vector <int> arr) {

    bool repeated = false; //Keeps track if an element appears multiple times in array
    vector <int> duplicate; //Store duplicated elements

    for (int i = 0 ; i < arr.size(); i++) {
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[i] == arr[j] && arr[i] != 0) { //Skip over duplicated elements indicated by a 0
                arr[j] = 0 ; //set repeat element equal to 0

                if(!repeated) duplicate.push_back(arr[i]); //if this is the first duplicate found, add element to duplicate array, if 2nd,3rd, 4th, etc. do not add element again
                repeated = true;
            }
        }
        if (!repeated) {// if no repeats found set current element equal to zero
            arr[i] = 0;
        }
        repeated = false;
       
    }
    return duplicate;
}