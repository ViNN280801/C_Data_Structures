gcc -c src/generate_keys.c -Wall -Wpedantic -Wextra -o src/generate_keys.o
gcc -c src/hash_table.c -Wall -Wpedantic -Wextra -o src/hash_table.o
gcc -c src/hash_table_test.c -Wall -Wpedantic -Wextra -o src/hash_table_test.o
gcc src/generate_keys.o src/hash_table.o src/hash_table_test.o -Wall -Wpedantic -Wextra -o hash_table

rm src/*.o
