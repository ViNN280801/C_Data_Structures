gcc -c src/circular_singly_linked_list.c -Wall -Wpedantic -Wextra -o src/circular_singly_linked_list.o
gcc -c src/circular_singly_linked_list_test.c -Wall -Wpedantic -Wextra -o src/circular_singly_linked_list_test.o
gcc src/circular_singly_linked_list.o src/circular_singly_linked_list_test.o -Wall -Wpedantic -Wextra -o circular_singly_linked_list

rm src/*.o
