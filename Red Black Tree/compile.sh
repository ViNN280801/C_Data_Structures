gcc -c src/red_black_tree.c -Wall -Wpedantic -Wextra -o src/red_black_tree.o
gcc -c src/red_black_tree_test.c -Wall -Wpedantic -Wextra -o src/red_black_tree_test.o
gcc src/red_black_tree.o src/red_black_tree_test.o -Wall -Wpedantic -Wextra -o red_black_tree

rm src/*.o
