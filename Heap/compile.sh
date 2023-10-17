gcc -c src/heap.c -Wall -Wpedantic -Wextra -o src/heap.o
gcc -c src/heap_test.c -Wall -Wpedantic -Wextra -o src/heap_test.o
gcc src/heap.o src/heap_test.o -Wall -Wpedantic -Wextra -o heap

rm src/*.o
