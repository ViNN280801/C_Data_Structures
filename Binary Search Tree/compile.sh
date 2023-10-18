gcc -c src/binary_search_tree.c -Wall -Wpedantic -Wextra -o src/binary_search_tree.o
gcc -c src/binary_search_tree_test.c -Wall -Wpedantic -Wextra -o src/binary_search_tree_test.o
gcc src/binary_search_tree.o src/binary_search_tree_test.o -Wall -Wpedantic -Wextra -o binary_search_tree

rm src/*.o
