#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Head pointer of the first list
struct Node* head = NULL;

// Function to display the list
void display() {
       if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
   // write your code here..
   
}

// Function to insert a number at the end
void insert(int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted successfully\n");
    
}

// Function to delete a specific number
void deleteNumber(int num) {
     if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != num) {
        temp = temp->next;
    }
    // Number not found
    if (temp == NULL) {
        printf("Number %d not found\n", num);
        return;
    }
    // Adjusting pointers to remove the node
    if (temp == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }
    free(temp);
    // Sub-requirement: "List after deletion: <elements>"
    printf("List after deletion: ");
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    
    
}

// Function to reverse the list
void reverseList() {
if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = NULL;
    struct Node* current = head;
    // Swap prev and next for all nodes of the doubly linked list
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        // Move to the next node in the original list (which is now prev)
        current = current->prev; 
    }
    // Check for empty list or list with only one node
    if (temp != NULL) {
        head = temp->prev;
    }
    // Sub-requirement: display elements after reversal
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

}

// Function to concatenate another list
void concatenate() {
int n, val;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("Second list is empty\n");
        return;
    }
    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;
    // Build the second list
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head2 == NULL) {
            head2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            newNode->prev = tail2;
            tail2 = newNode;
        }
    }
    // Concatenate the second list to the first list
    if (head == NULL) {
        head = head2;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
        head2->prev = temp;
    }
    // Sub-requirement: display the concatenated list
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
	
}

int main() {
    int choice, num;

    while (1) {
        printf("Enter operation\n1: Insert\n2: Delete\n3: Display\n4: Reverse\n5: Concatenate\n6: Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &num);
                insert(num);
                break;

            case 2:
                scanf("%d", &num);
                deleteNumber(num);
                break;

            case 3:
                display();
                break;

            case 4:
                reverseList();
                break;

            case 5:
                concatenate();
                break;

            case 6:
                printf("Exit\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
