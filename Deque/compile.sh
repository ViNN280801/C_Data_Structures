gcc -c src/deque.c -Wall -Wpedantic -Wextra -o src/deque.o
gcc -c src/deque_test.c -Wall -Wpedantic -Wextra -o src/deque_test.o
gcc src/deque.o src/deque_test.o -Wall -Wpedantic -Wextra -o deque

rm src/*.o
