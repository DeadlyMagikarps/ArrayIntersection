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
Node* arrayToList(int arr[], size_t arrSize);

// Function to get the size of the linked list (# of nodes)
int getLinkedListCount(Node* head);

// Function to get the intersection when one list has more nodes than the other list
void getIntersection(Node* head1, Node* head2);

// Function to get the intersection of equal length lists
void getIntersectionHelper(Node* head1, Node* head2);

int main()
{
    // Initialize variables
    int listArray[] {1, 3, 5, 10, 10, 54, 78, 82};
    int listArray2[] = {1, 3, 10, 10, 25, 78};

    // Get array sizes
    size_t arrSize1 = sizeof(listArray)/sizeof(listArray[0]);
    size_t arrSize2 = sizeof(listArray)/sizeof(listArray[0]);

    Node* list1 = arrayToList(listArray, arrSize1);
    Node* list2 = arrayToList(listArray2, arrSize2);

    // Get the intersection of the two lists
    getIntersection(list1, list2);

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

Node* arrayToList(int arr[], size_t arrSize)
{
    int index;
    Node* head = NULL;

    for(index = 0; index < arrSize; index++)
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
    // get the sizes of both linked lists
    int linkedListSize1 = getLinkedListCount(head1);
    int linkedListSize2 = getLinkedListCount(head2);

    // check if the first list has more nodes than the second list
    if(linkedListSize1 > linkedListSize2)
    {
        getIntersectionHelper(head1, head2);
    }

    // otherwise, the opposite
    else
    {
        getIntersectionHelper(head2, head1);
    }
}

// This functions starts out with the bigger list to compare and increment
void getIntersectionHelper(Node* head1, Node* head2)
{
    // Initialize variables
    int index;
    Node* current1 = head1;
    Node* current2 = head2;

    // Move the pointers of both lists till a match is found
    while(current1 != NULL && current2 != NULL)
    {
        // Check if either list is longer than the other
        if(current1->data == current2->data)
        {
            cout << current2->data << " ";
                    
            // move both pointers
            current1 = current1->next;
            current2 = current2->next;
        }

        // Compare the data itself to each other to see if they match
        // Current data in list 1 is less than the current data in list 2
        else if(current1->data < current2->data)
        {
            // return the data
            current1 = current1->next;
        }
        
        // Current data in list 2 is less than the current data in list 1
        else if(current2->data < current1->data)
        {
            current2 = current2->next;
        }
    }
}