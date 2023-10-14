#include <stdio.h>

#include "../include/priority_queue.h"

int main()
{
    PriorityQueue *queue = initPriorityQueue();

    // Inserting elements with priorities
    insert(queue, 10, 9);
    insert(queue, 14, 10);
    insert(queue, 12, 17);
    insert(queue, 60, 30);
    insert(queue, 13, 46);

    printf("Priority Queue Contents:\n");

    while (!isEmpty(queue))
    {
        int data = extractMax(queue);
        printf("Data: %d\n", data);
    }

    destroyPriorityQueue(queue);

    return 0;
}
