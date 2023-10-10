gcc -c src/singly_linked_list.c -Wall -Wpedantic -Wextra -o src/singly_linked_list.o
gcc -c src/singly_linked_list_test.c -Wall -Wpedantic -Wextra -o src/singly_linked_list_test.o
gcc src/singly_linked_list.o src/singly_linked_list_test.o -Wall -Wpedantic -Wextra -o singly_linked_list

rm src/*.o
