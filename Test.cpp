// Given 2 sorted linked lists, find the intersection.
// For example - Input: List 1 - 1, 3, 5, 10, 54, 78
// List 2 - 6, 10, 54, 98, 99

// Output 10, 54

#include <iostream>
using namespace std;

// Assuming that these are sorted arrays

// Function to print intersection
/*
*   Function needs to have 2 arrays and their sizes to complete their task
*/
void printIntersection(int arr[], int arr2[], int arrSize, int arrSize2);

int main()
{
    // Initialize variables
    int listArray[] = {1, 3, 5, 10, 54, 78};
    int listArray2[] = {6, 10, 54, 98, 99};

    // Get array sizes
    int arrSize1 = sizeof(listArray)/sizeof(listArray[0]);
    int arrSize2 = sizeof(listArray2)/sizeof(listArray2[0]);

    // Print the intersections found between the arrays
    printIntersection(listArray, listArray2, arrSize1, arrSize2);

    return 0;
}

void printIntersection(int arr[], int arr2[], int arrSize, int arrSize2)
{
    // Initialize variables
    int arrIndex = 0, arr2Index = 0;

    // while both arrays are less than their own size
    while(arrIndex < arrSize && arr2Index < arrSize2)
    {
        // check if the value at the current index in the first array is less than
        // the value at the current index of the second array
        if(arr[arrIndex] < arr2[arr2Index])
        {
            // If so, go to the next index of the first array
            arrIndex++;
        }

        // otherwise check if the current index in the second array is less than
        // the value at the current index of the first array
        else if(arr2[arr2Index] < arr[arrIndex])
        {
            // if so, go to the next index of the second array
            arr2Index++;
        }


        // otherwise, we have found and intersection from the second array at the current index
        else
        {
            cout << arr2[arr2Index] << " ";

            // Increment both array indicies
            arrIndex++;
            arr2Index++;
        }
    }
}