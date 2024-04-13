#include <iostream>
using namespace std;

// Define a structure for a node in linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to push a new node with given data at the beginning of the list
void push(struct Node** head, int data)
{
    // Allocate memory for new node
    struct Node* newNode = new Node;

    // Set the data for new node
    newNode->data = data;

    // Set next pointer of new node to point to current head
    newNode->next = (*head);

    // Moving the head to point to new node
    (*head) = newNode;
}

// Function to insert a new node with given data after a specified node
void insertAfter(struct Node* prevNode, int data)
{
    // Checks if the given previous node is null
    if (prevNode == NULL)
    {
        cout << "Previous node cannot be null";
        return;
    }

    // Create a new node
    struct Node* newNode = new Node;

    // Give the data to the node
    newNode->data = data;

    // Move the next of prevNode to the new node
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a new node with given data at the end of the list
void insertNode(struct Node** head, int data)
{
    // Allocate memory for node
    struct Node* newNode = new Node;

    // Setting data for the node
    newNode->data = data;

    // Set next pointer of new node to null as it's the last node
    newNode->next = NULL;

    // If the list is empty, new node becomes the first node
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Otherwise, go to the last node
    struct Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Change the next of last node to the new node
    last->next = newNode;
}

// Function to display linked list contents
void showList(struct Node *head)
{
    // Traverse the list to show each node
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    if (head == NULL)
    {
        cout << "null";
    }
}

int main()
{
    // Initialize an empty list
    struct Node* head = NULL;

    // Insert 10
    push(&head, 10);

    // Insert 20 at the beginning
    push(&head, 20);

    // Insert 30 at the beginning
    push(&head, 30);

    // Insert 40 at the end
    insertNode(&head, 40);

    // Insert 50 after 20
    insertAfter(head->next, 50);

    // Display the final linked list
    cout << "Final linked list: " << endl;
    showList(head);

    return 0;
}
