// Given 2 sorted linked lists, find the intersection.
// For example - Input: List 1 - 1, 3, 5, 10, 54, 78
// List 2 - 6, 10, 54, 98, 99

// Output 10, 54

#include <iostream>
using namespace std;

// Assuming that these are sorted arrays

// Function to print intersection
void printIntersection(int arr[], int arr2[], int arrSize, int arrSize2);

int main()
{
    int listArray[] = {1, 3, 5, 10, 54, 78};
    int listArray2[] = {6, 10, 54, 98, 99};

    int arrSize1 = sizeof(listArray)/sizeof(listArray[0]);
    int arrSize2 = sizeof(listArray2)/sizeof(listArray2[0]);

    // Print the intersections found between the arrays
    printIntersection(listArray, listArray2, arrSize1, arrSize2);

    return 0;
}

void printIntersection(int arr[], int arr2[], int arrSize, int arrSize2)
{
    int innerIndex = 0, outerIndex = 0;

    while(innerIndex < arrSize && outerIndex < arrSize2)
    {
        if(arr[innerIndex] < arr2[outerIndex])
        {
            innerIndex++;
        }

        else if(arr2[outerIndex] < arr[innerIndex])
        {
            outerIndex++;
        }

        else
        {
            cout << arr2[outerIndex] << " ";

            innerIndex++;
            outerIndex++;
        }
    }
}