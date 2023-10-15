gcc -c src/vector.c -Wall -Wpedantic -Wextra -o src/vector.o
gcc -c src/vector_test.c -Wall -Wpedantic -Wextra -o src/vector_test.o
gcc src/vector.o src/vector_test.o -Wall -Wpedantic -Wextra -o vector

rm src/*.o
