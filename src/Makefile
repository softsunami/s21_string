.PHONY: s21_string.a

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
TESTFLAGS = -lcheck -coverage -lpthread -pthread

C_FILES = s21_*.c help.c
O_FILES = s21_*.o help.o

all:
	$(MAKE) clean
	$(MAKE) s21_string.a

s21_string.a:
	$(MAKE) clean
	$(CC) $(CFLAGS) -c $(C_FILES)
	ar rc s21_string.a $(O_FILES)
	rm $(O_FILES)

test:
	$(MAKE) clean
	$(MAKE) s21_string.a
	$(CC) $(CFLAGS) test.c tests/*.c $(TESTFLAGS) s21_string.a -o main
	./main
	rm -rf $(O_FILES) *gcno *gcda

gcov_report:
	$(MAKE) clean
	$(CC) $(CFLAGS) test.c tests/*.c $(TESTFLAGS) $(C_FILES) -o gcovreport
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	rm -rf *.o *.gcno *.gcda *.info *.txt

style: clean
	cppcheck *.h *.c
	cppcheck tests/*.h tests/*.c
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -n tests/*.c tests/*.h

valgrind:
	$(MAKE) test
	valgrind --leak-check=full --log-file=valgrind_report.txt ./main
	rm -rf *.o *.gcno *.gcda *.info main

clean:
	rm -rf *.o *.a report *.gcno *.gcda *.info *.txt gcovreport main