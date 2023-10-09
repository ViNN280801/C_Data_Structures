gcc -c src/queue.c -Wall -Wpedantic -Wextra -o src/queue.o
gcc -c src/queue_test.c -Wall -Wpedantic -Wextra -o src/queue_test.o
gcc src/queue.o src/queue_test.o -Wall -Wpedantic -Wextra -o queue

rm src/*.o
