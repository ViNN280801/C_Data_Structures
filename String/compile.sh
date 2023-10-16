gcc -c src/mystring.c -Wall -Wpedantic -Wextra -o src/mystring.o
gcc -c src/mystring_test.c -Wall -Wpedantic -Wextra -o src/mystring_test.o
gcc src/mystring.o src/mystring_test.o -Wall -Wpedantic -Wextra -o mystring

rm src/*.o
