// Prelab7: Interview Style Questions. Sorting Algorithms
// Question 1. Given a matrix that is sorted in ascendent order for both rows and columns, code a function that finds an element 
// making use of the fact that both rows and columns are sorted. 
#include <iostream>
#include <stdexcept>

using namespace std;

pair<int, int> findElement(int matrix[][4], int rows, int cols, int target) {
    int rowcounter = 0;
    int colcounter = cols - 1; 

    while (rowcounter < rows && colcounter >= 0) {
        if (matrix[rowcounter][colcounter] == target) {
            return {rowcounter, colcounter}; 
        } else if (matrix[rowcounter][colcounter] < target) {
            rowcounter++;
        } else {
            colcounter--;
        }
    }
    throw ("Element not found in the matrix");
}

int main() {
    int matrix[4][4] = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {11, 14, 15, 18}
    };

    int rows = 4;
    int columns = 4;
    int target = 6;

        pair<int, int> result = findElement(matrix, rows, columns, target);
        cout << "Element " << target << " found at position: (" << result.first << ", " << result.second << ")\n";

    return 0;
}
