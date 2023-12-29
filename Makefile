.PHONY: all calc
SHELL = /bin/sh
FLAGS=-std=c11 -Wextra -Wall -Werror
C_SOURCES=$(wildcard s21_*.c)
LCHECK=-lcheck -lsubunit -lm
GCOV=-fprofile-arcs -ftest-coverage
TARGET = Calculator_v1.0
OUTNAME = smart_calc_qt
CC=gcc
FLAGS=-std=c11 -g -Wall -Werror -Wextra #-fsanitize=address
TEST_FLAGS=-lm
S21_CALC_C=s21_*.c
S21_CALC_H=s21_*.h
S21_CALC_O=s21_*.o
TESTS=tests
OS := $(shell uname -s)
OS_TITLE=:=$(shell cat /etc/os-release)

ifeq ($(OS),Darwin) # Darwin это системное имя для macOS
    LCHECK := -lcheck #-mmacosx-version-min=13.0 
	OUTNAME := front.app/Contents/MacOS/front 
endif
ifeq ($(findstring Ubuntu, $(OS_TITLE)), Ubuntu)
    LCHECK=-lcheck -lsubunit -lm
else ifeq ($(findstring Manjaro, $(OS_TITLE)), Manjaro)
	LCHECK=-lcheck -lm
endif


all: install
	../build/Calculator_v1.0.app

run:
	../build/Calculator_v1.0.app

install:       
	echo "Installation of $(TARGET).app:"
	mkdir -p ../build
	cd smart_calc_qt/ && qmake && make && make clean && rm -rf Makefile && mv calculator.app ../../build/$(TARGET).app
	echo "Installation completed! You can find app in the ../build/ folder!"

uninstall:
	rm -rf ../build
	echo "Uninstall completed!"
	
dist: install
	mkdir -p ../dist
	@cp -R ../build/$(TARGET).app ../dist
	@cp -R . ../dist/src
	@cd ../dist && tar cvzf $(TARGET).tgz *
	@cd ../dist && rm -rf $(TARGET).app
	@rm -rf ../dist/src
	echo "Archive creation completed successfully!"	

dvi: clean
	@doxygen Doxyfile
	open doxygen/html/index.html
	
s21_covered:
	$(CC) s21_*.c -c $(FLAGS) --coverage
	ar rc s21_calc.a s21_*.o
	ranlib s21_calc.a

test: clean s21_covered
	$(CC) test/$(TESTS)*.c $(TESTS).c -c $(FLAGS) --coverage
	$(CC) -o $(TESTS) $(TESTS)*.o s21_calc.a -lcheck --coverage $(FLAGS) $(TEST_FLAGS)
	./$(TESTS)

gcov_report: test
	lcov -t "s21_smartcalc" -o s21_smartcalc.info -c -d .
	genhtml -o report s21_smartcalc.info
	open report/index.html

check: 
	@gcc $(FLAGS) $(C_SOURCES) unit_tests.c -g $(LCHECK) -o vtest
	@valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./vtest 2> valgrind.out
	@rm -f vtest
	@cat -n valgrind.out | grep ERROR


clean:
	rm -rf *.o *.info *.a report a.out $(TESTS) lexeme_parser *.gcda *.gcno coverage.info coverage_html doxygen valgrind.out build*

open: install
	open $(APP)

