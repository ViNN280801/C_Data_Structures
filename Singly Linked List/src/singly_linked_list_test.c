#include <stdio.h>

#include "../include/singly_linked_list.h"

int main()
{
    SinglyLinkedList *list = initSinglyLinkedList();

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

    printf("\nDeleting from the beginning:\n");
    deleteElement(list, 33);
    display(list);

    printf("\nList size: %d\n", size(list));

    destroySinglyLinkedList(list);

    return 0;
}
