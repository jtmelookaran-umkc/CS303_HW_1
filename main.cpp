#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
using namespace std;

const int MAX_SIZE = 1000;
//function to read in the data 
//add some error detection in case there is a problem opening 
void readFile(const char* filename, double arr[], int& size) {
    ifstream inFile(filename);

    cout << "Attempting to open: " << filename << endl;
    if (!inFile) {
        cerr << "Error: " << strerror(errno) << endl;
        return;
    }

    size = 0;
    while (inFile >> arr[size] && size < MAX_SIZE) {
        size++;
    }

    if (inFile.fail() && !inFile.eof()) {
        cerr << "Error reading data - check file format" << endl;
    }

    inFile.close();
}

int main() {
    //initialize the array
    double array[MAX_SIZE];
    int size = 0;

    readFile("A1input.txt", array, size);

    cout << "Read " << size << " numbers" << endl;
    //print everything in array
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;


    //sadd exceptions to catch after the user input 
    return 0;
}