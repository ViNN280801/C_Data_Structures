#include <stdio.h>

#include "../include/doubly_linked_list.h"

int main()
{
    DoublyLinkedList *list = initDoublyLinkedList();

    printf("Inserting 10, 20, 30 at the beginning:\n");
    insertAtBeginning(list, 10);
    insertAtBeginning(list, 20);
    insertAtBeginning(list, 30);
    display(list);

    printf("\nInserting 40, 50, 60 at the end:\n");
    insertAtEnd(list, 40);
    insertAtEnd(list, 50);
    insertAtEnd(list, 60);
    display(list);

    printf("\nDeleting element 20:\n");
    deleteElement(list, 20);
    display(list);

    printf("\nList size: %d\n", size(list));

    destroyDoublyLinkedList(list);

    return 0;
}
