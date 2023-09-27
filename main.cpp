#include <iostream>
#include <random>
#include <time.h>
using namespace std;

void gen(int [], int); // generate initial array function
void display(int [], int); // display curent array function
void sort(int [], int); // sort array in ascending order function
void revsort(int [], int); // sort array in descending order function
void reverse(int [], int); // reverse elements in current array function

int main() {
    int NUM, loop1 = 1, loop2 = 1; char ch1,ch2; // initializing variables
    
    cout << "Please enter the size of your array: ";
    cin >> NUM;
    int *arr  = new int[NUM];
    
    while (loop1 > 0){
        cout << "Please choose one of the following options:" << endl;
        cout << "m) Manually enter the elements of your array" << endl;
        cout << "s) Generate random elements in the range of [0, 100]" << endl;
        cin >> ch1; // takes user input and puts it in variable ch1
        
        if (ch1 == 'm' || ch1 == 'M'){ // if user inputted an m or M
            for (int i = 0; i < NUM; i++){ // loops through array
                cout << "Please enter value " << i << " of your array: ";
                cin >> arr[i]; // assigns value in array to user input
            }
            cout << "Here is your manually inputted array with size (" <<  NUM << "):" << endl;
            display(arr, NUM); // displays the array
            loop1 = 0; // jumps out of this while statement
            
        } else if (ch1 == 's' || ch1 == 'S'){ // if user inputted an s or S
            gen(arr, NUM); // generates the initial array with random numbers
            cout << "\nHere is your randomly generated array with size (" <<  NUM << "):" << endl;
            display(arr, NUM); // displays the array
            loop1 = 0; // jumps out of this while statement
        } else { // if anything besides one of the aforementioned options is inputted
            cout << "Invalid input!\n" << endl; // error message
        }
    }
    
    while (loop2 > 0){
        cout << "Please choose one of the following operations:" << endl;
        cout << "a) Sort the elements of the array into ascending order" << endl;
        cout << "d) Sort the elements of the array into descending order" << endl;
        cout << "r) Reverse the order of the elements in the array" << endl;
        cout << "q) Quit program" << endl;
        cin >> ch2; // takes user input and puts it in variable ch2
        
        if (ch2 == 'a' || ch2 == 'A'){ // if user inputted an a or A
            sort(arr, NUM); // sorts array in ascending order
            display(arr, NUM); // displays array
        } else if (ch2 == 'd' || ch2 == 'D'){ // if user inputted a d or D
            revsort(arr, NUM); // sorts array in descending order
            display(arr, NUM); // displays array
        } else if (ch2 == 'r' || ch2 == 'R'){ // if user inputted an r or R
            reverse(arr, NUM); // reverses order of current array
            display(arr, NUM); // displays array
        } else if (ch2 == 'q' || ch2 == 'Q'){ // if user inputted a q or Q
            loop2 = 0; // jumps out of this while statement
        } else {
            cout << "Invalid input for operator expression!" << endl; // error message
        }
    }
    
    delete arr; // deletes memory allocated for the array
    return 0; // exits program
}

void gen(int z[], int a){ // function that generates a random number and assigns that to each value in array
    srand(time(NULL)); // generates new random seed
    for (int i = 0; i < a; i++){ // loops however many times the user set initially with array size
        z[i] = rand()%101; // sets each value between 0 and 100
    }
}

void display(int z[], int a){ // function that displays current array
    cout << "[";
    for (int i = 0; i < a; i++){ // loops through array
        if (i == a-1){ // if last element in array, then don't put a space afterward (formatting)
            cout << z[i];
        } else {
            cout << z[i] << " ";
        }
    }
    cout << "]" << endl;
}

void sort(int array[], int len){ // function that sorts elements in array in ascending order
    for(int i=0; i < len -1; i++){ // loops through each element in array
        for(int j=0; j < len -1-i; j++){ // more efficient loop that doesn't reiterate on previous checks
            if (array[j]>array[j+1]){ // if element is bigger than the element to the right, then swap
                int temp; int *num1 = &array[j], *num2 = &array[j+1]; // initializing swapper variables
                temp = *num1; // swapper
                *num1 = *num2; // swapper
                *num2 = temp; // swapper
            }
        }
    }
}

void revsort(int array[], int len){ // function that sorts elements in array in descending order
    for(int i=0; i < len -1; i++){
        for(int j=0; j < len -1-i; j++){
            if (array[j]<array[j+1]){ // everything same as sort() function, except > swapped with <
                int temp; int *num1 = &array[j], *num2 = &array[j+1];
                temp = *num1;
                *num1 = *num2;
                *num2 = temp;
            }
        }
    }
}

void reverse(int array[], int len){ // function that reverses current elements in array (not just initial array)
    int temp; // temporary variable
    for (int i = 0; i < len / 2; i++){ // loops through halfway
        temp = array[i];
        array[i] = array[len - i - 1];
        array[len - i - 1] = temp; // this algorithm swaps the elements into reversed order
    }
}
