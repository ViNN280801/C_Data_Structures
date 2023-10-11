gcc -c src/doubly_linked_list.c -Wall -Wpedantic -Wextra -o src/doubly_linked_list.o
gcc -c src/doubly_linked_list_test.c -Wall -Wpedantic -Wextra -o src/doubly_linked_list_test.o
gcc src/doubly_linked_list.o src/doubly_linked_list_test.o -Wall -Wpedantic -Wextra -o doubly_linked_list

rm src/*.o
