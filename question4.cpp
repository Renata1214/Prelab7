// Question 4. Recursion
// Given that there is an index in a sorted array of distinct integers such that A[i]=i. 
//Write a function to find this index in the most efficient way.

#include <iostream>
#include <cmath>

using namespace std;

int solution_1 (int A[], int size){
    for (int i=0; i<size; i++){
        if(A[i]==i){
            return i;
        }
    }
    return -1;
}

//Utilize 
int solution_2 (int A[], int start, int end){

int middle = (start + end)/2;

if(start>end){
    return -1;
}

if (A[middle]==middle){
    return middle;
}
else if (A[middle]> middle){
    return solution_2(A, start, middle-1);
}
else{
    return solution_2(A, middle+1, end);
}

}

int main () {


int A [5]={-4,-3,-2,3,5};


cout << "Solution 1 " << solution_1(A, 5) << endl;

cout << "Solution 2 " << solution_2(A, 0, 5) << endl;

}


// The difference between both solutions consist in the efficiency. While solution number 1 will always have a time complexity 
// of O(n), the second solution will have a constant time complexity, since the number of operations done will not be the same 
// as the number of elements due to the recursive functions called, as well as the binary search algorithm implemented 
// which allows to start the search from the middle and hence make it more efficient. 