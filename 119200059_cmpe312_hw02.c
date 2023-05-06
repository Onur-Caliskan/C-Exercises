#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Binary tree node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Global binary tree root node
struct Node* root = NULL;

// Function to create a new node with the given data
 struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with the given data into the binary tree
void insertNode(int data) {
    struct Node* node = newNode(data);
    if (root == NULL) {
        root = node;
        return;
    }
    struct Node* curr = root;
    while (1) {
        if (data < curr->data) {
            if (curr->left == NULL) {
                curr->left = node;
                break;
            }
            else {
                curr = curr->left;
            }
        }
        else {
            if (curr->right == NULL) {
                curr->right = node;
                break;
            }
            else {
                curr = curr->right;
            }
        }
    }
}

// Thread function that inserts values into the binary tree
void* insertThread(void* arg) {
    int* values = (int*)arg;
    for (int i = 0; i < 5; i++) {
        insertNode(values[i]);
    }
    pthread_exit(NULL);
}

//searchs an arg in binary tree
void *search(void *arg) {

     //starts with root to search
    int data = *(int *) arg;
    struct Node *temp = root;

    while (temp != NULL) {
        if (data == temp->data) {
            printf("%d found\n", data);
            return NULL;
        } else if (data < temp->data) {
            temp = temp->left;

        } else{
            temp = temp->right;

        }
    }
}


// Main function to test the multi-threaded binary tree program
int main() {
    // Create two threads
    pthread_t threads[2];

    // Define arrays of values to be inserted by each thread
    int thread1Values[5] = { 50, 30, 20, 40, 70 };
    int thread2Values[5] = { 60, 80, 90, 100, 110 };

    // Create the first thread and pass it the first array of values
    pthread_create(&threads[0], NULL, insertThread, (void*)thread1Values);

    // Create the second thread and pass it the second array of values
    pthread_create(&threads[1], NULL, insertThread, (void*)thread2Values);

    // Wait for the threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the in-order traversal of the binary tree
    printf("In-order traversal of the binary tree: ");
    struct Node* curr = root;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->left;
    }
    printf("\n");


//search function threads are t3,t4
    pthread_t t3, t4;
    int data1 = 50;
    int data2 = 30;

    pthread_create(&t3, NULL, search, (void*)&data1);
    pthread_create(&t4, NULL, search, (void*)&data2);


    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    return 0;
}