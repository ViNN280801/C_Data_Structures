gcc -c src/generate_keys.c -Wall -Wpedantic -Wextra -o src/generate_keys.o
gcc -c src/splay_tree.c -Wall -Wpedantic -Wextra -o src/splay_tree.o
gcc -c src/splay_tree_test.c -Wall -Wpedantic -Wextra -o src/splay_tree_test.o
gcc src/generate_keys.o src/splay_tree.o src/splay_tree_test.o -Wall -Wpedantic -Wextra -o splay_tree

rm src/*.o
