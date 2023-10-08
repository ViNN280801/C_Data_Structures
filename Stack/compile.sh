gcc -c src/stack.c -Wall -Wpedantic -Wextra -o src/stack.o
gcc -c src/stack_test.c -Wall -Wpedantic -Wextra -o src/stack_test.o
gcc src/stack.o src/stack_test.o -Wall -Wpedantic -Wextra -o stack

rm src/*.o
