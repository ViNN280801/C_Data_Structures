gcc -c src/graph.c -Wall -Wpedantic -Wextra -o src/graph.o
gcc -c src/graph_test.c -Wall -Wpedantic -Wextra -o src/graph_test.o
gcc src/graph.o src/graph_test.o -Wall -Wpedantic -Wextra -o graph

rm src/*.o
