// Given 2 sorted linked lists, find the intersection.
// For example - Input: List 1 - 1, 3, 5, 10, 54, 78
// List 2 - 6, 10, 54, 98, 99

// Output 10, 54

#include <iostream>
#include "Node.h"
using namespace std;

// Insert a new node to the list
void insert(Node** root, int item);

// Create a linked list with given array list
Node* arrayToList(int arr[], int size);

// Function to get the size of the linked list (# of nodes)
int getLinkedListCount(Node* head);

// Function to get the intersection when one list has more nodes than the other list
void getIntersection(Node* head1, Node* head2);

// Function to get the intersection of equal length lists
void getIntersectionHelper(int numNodes, Node* head1, Node* head2);

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

    Node* list1 = arrayToList(listArray, arrSize1);
    Node* list2 = arrayToList(listArray2, arrSize2);

    // Get the intersection of the two lists
    getIntersection(list1, list2);

    // Print the intersections found between the arrays
    //printIntersection(listArray, listArray2, arrSize1, arrSize2);

    return 0;
}

// Function Implementations
void insert(Node** head, int item)
{
    Node* temp = new Node;
    Node* ptr;

    // Set the item to the new node temp data
    // set the next item to null
    temp->data = item;
    temp->next = NULL;

    if(*head == NULL)
    {
        *head = temp;
    }

    else
    {
        ptr = *head;
        
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = temp;
    }
    
}

Node* arrayToList(int arr[], int size)
{
    int index;
    Node* head = NULL;

    for(index = 0; index < size; index++)
    {
        insert(&head, arr[index]);
    }

    return head;
}

int getLinkedListCount(Node* head)
{
    // Initialize variables
    int count = 0;

    // Set the current pointer to the head of the list
    Node* current = head;


    // start the count until it hits NULL. Break after and return count
    while(current != NULL)
    {
        // increment counter
        count++;
        
        // move the pointers
        current = current->next;
    }

    return count;
}

void getIntersection(Node* head1, Node* head2)
{
    // Initialize variables
    int numNodes;

    // get the sizes of both linked lists
    int llsize_1 = getLinkedListCount(head1);
    int llsize_2 = getLinkedListCount(head2);

    // check if the first list has more nodes than the second list
    if(llsize_1 > llsize_2)
    {
        numNodes = llsize_1 - llsize_2;
        getIntersectionHelper(numNodes, head1, head2);
    }

    // otherwise, the opposite
    else
    {
        numNodes = llsize_2 - llsize_1;
        getIntersectionHelper(numNodes, head2, head1);
    }
}

// This functions starts out with the bigger list to compare and increment
void getIntersectionHelper(int numNodes, Node* head1, Node* head2)
{
    // Initialize variables
    int index;
    Node* current1 = head1;
    Node* current2 = head2;

    // move the pointer down the list
    for(index = 0; index < numNodes; index++)
    {
        // check for null and do nothing
        if(current1 == NULL)
        {
            return;
        }

        // Move the pointer
        else
        {
            current1 = current1->next;
        }
    }

    // Move the pointers of both lists till a match is found
    while(current1 != NULL && current2 != NULL)
    {
        // Compare the data itself to each other to see if they match
        // Current data in list 1 is less than the current data in list 2
        if(current1->data < current2->data)
        {
            // return the data
            current1 = current1->next;
        }
        
        // Current data in list 2 is less than the current data in list 1
        else if(current2->data < current1->data)
        {
            current2 = current2->next;
        }

        // Current Data in both lists match!
        else
        {
            cout << current2->data << " ";
                    
            // move both pointers
            current1 = current1->next;
            current2 = current2->next;
        }
    }
}

// Array based function
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