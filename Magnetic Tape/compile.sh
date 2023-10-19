gcc -c src/magnetic_tape.c -Wall -Wpedantic -Wextra -o src/magnetic_tape.o
gcc -c src/magnetic_tape_test.c -Wall -Wpedantic -Wextra -o src/magnetic_tape_test.o
gcc src/magnetic_tape.o src/magnetic_tape_test.o -Wall -Wpedantic -Wextra -o magnetic_tape

rm src/*.o
