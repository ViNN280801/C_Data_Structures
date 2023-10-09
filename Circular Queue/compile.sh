gcc -c src/circular_queue.c -Wall -Wpedantic -Wextra -o src/circular_queue.o
gcc -c src/circular_queue_test.c -Wall -Wpedantic -Wextra -o src/circular_queue_test.o
gcc src/circular_queue.o src/circular_queue_test.o -Wall -Wpedantic -Wextra -o circular_queue

rm src/*.o
