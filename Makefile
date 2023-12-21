.PHONY: all s21_smartcalc.a

CC=gcc
FLAGS=-std=c11 -Wall -g -Werror -Wextra
TEST_FLAGS=-lm
S21_smartcalc_C=s21_*.c
S21_smartcalc_H=s21_*.h
S21_smartcalc_O=s21_*.o
TESTS=tests

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS+=-lsubunit
endif

all: s21_smartcalc.a

s21_smartcalc.a:
	$(CC) $(S21_smartcalc_C) -c $(FLAGS)
	ar rc s21_smartcalc.a $(S21_smartcalc_O)
	ranlib s21_smartcalc.a

s21_covered:
	$(CC) $(S21_smartcalc_C) -c $(FLAGS) --coverage
	ar rc s21_smartcalc.a $(S21_smartcalc_O)
	ranlib s21_smartcalc.a

style:
	clang-format -style=google -n test/*.c *.c *.h

test: clean s21_covered
	$(CC) test/$(TESTS)*.c $(TESTS).c -c $(FLAGS) --coverage
	$(CC) -o $(TESTS) $(TESTS)*.o s21_smartcalc.a -lcheck --coverage $(FLAGS) $(TEST_FLAGS) -lgcov
	./$(TESTS)

mem: test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TESTS)
else
	leaks --atExit -- ./$(TESTS)
endif

clean:
	rm -rf $(TESTS) *.a *.o *.gcda *.gcno *.gcov *.info *.html report

rebuild: clean all

gcov_report: test
	lcov -t "s21_smartcalc" -o s21_smartcalc.info -c -d .
	genhtml -o report s21_smartcalc.info
	open report/index.html

evgeniy: clean
	$(CC) $(CFLAGS) -g s21*.c evgeniy.c -o evgeniy_e
	./evgeniy_e
