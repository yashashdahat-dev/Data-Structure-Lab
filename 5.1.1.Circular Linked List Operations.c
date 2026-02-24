#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL( int n      ) {
NODE first = NULL, temp = NULL, newNode = NULL;
    int data, i;
    for (i = 0; i < n; i++) {
        // Assuming simple input as per standard lab patterns
        // "Read n integers from the user"
        scanf("%d", &data);
        newNode = createNodeInCLL(data);
        
        if (first == NULL) {
            first = newNode;
            newNode->next = first;
        } else {
            temp->next = newNode;
            newNode->next = first;
        }
        temp = newNode;
    }
    return first;
// write your code here...


}

// Traverse CLL
void traverseListInCLL(NODE first      ) {
   if (first == NULL) return;
    NODE temp = first;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
// write your code here...


}

// Insert at given position in CLL
NODE insertAtPositionInCLL( NODE first, int pos, int data        ) {
    NODE newNode = createNodeInCLL(data);
    NODE temp = first;
    int count = 0;

    // Count nodes
    if (first != NULL) {
        do {
            count++;
            temp = temp->next;
        } while (temp != first);
    }

    // Check availability
    // pos > count + 1 is invalid for insertion (cannot skip nodes)
    // Note: pos <= 0 is handled in main, but we can check here too for safety
    if (pos > count + 1 || pos <= 0) {
        printf("Position not found\n");
        return first; // Or should we free newNode? Yes.
    }

    if (first == NULL) {
        if (pos == 1) {
            first = newNode;
            first->next = first;
            return first;
        } else {
            printf("Position not found\n"); 
            return first;
        }
    }

    if (pos == 1) {
        // Insert at beginning
        temp = first;
        while (temp->next != first) {
            temp = temp->next;
        }
        newNode->next = first;
        temp->next = newNode;
        return newNode;
    } else {
        temp = first;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return first;
	}
//write your code here..


	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL( NODE first, int pos      ) {
    if (first == NULL) {
        // Should be handled by main "CLL is empty", but if reached here:
        return NULL;
    }

    NODE temp = first, prev = NULL;
    int count = 0;

    do {
        count++;
        temp = temp->next;
    } while (temp != first);

    if (pos < 1 || pos > count) {
        printf("Position not found\n");
        return first;
    }

    if (pos == 1) {
        printf("Deleted element: %d\n", first->data);
        if (first->next == first) {
            free(first);
            return NULL;
        }
        // Find last node
        temp = first;
        while (temp->next != first) {
            temp = temp->next;
        }
        temp->next = first->next;
        NODE toDelete = first;
        first = first->next;
        free(toDelete);
        return first;
    } else {
        temp = first;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        NODE toDelete = temp->next;
        printf("Deleted element: %d\n", toDelete->data);
        temp->next = toDelete->next;
        free(toDelete);
        return first;
	}
	
	
}

// Reverse CLL
NODE reverseCLL( NODE first       ) {

if (first == NULL) return NULL;
    if (first->next == first) return first;
    NODE prev = NULL, current = first, next = NULL;
    
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != first);
    // Fix circular connection
    // 'first' is now the last node
    // 'prev' is the new head
    first->next = prev;
    
    return prev;


}

// Concatenate two CLLs
NODE concatCLL( NODE first, NODE second          ) {
    if (first == NULL) return second;
    if (second == NULL) return first;
    NODE last1 = first;
    while (last1->next != first) last1 = last1->next;
    NODE last2 = second;
    while (last2->next != second) last2 = last2->next;
    last1->next = second;
    last2->next = first;
    return first;
}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
