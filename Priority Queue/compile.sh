gcc -c src/priority_queue.c -Wall -Wpedantic -Wextra -o src/priority_queue.o
gcc -c src/priority_queue_test.c -Wall -Wpedantic -Wextra -o src/priority_queue_test.o
gcc src/priority_queue.o src/priority_queue_test.o -Wall -Wpedantic -Wextra -o priority_queue

rm src/*.o
