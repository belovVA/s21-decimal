ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TEST_FLAGS = -std=c11 -g
GCOVFLAGS = -L. -ls21_decimal --coverage

LIB = -lcheck
LEAK = leaks -atExit --
TO =
LEAK_REPORT = -A 2 "leaks Report Version"
OPEN = open

ARITHMETIC_FILES = ./arithmetic/*.c
COMPARISION_FILES = ./comparison/*.c
CONVERTORS_FILES = ./convertors/*.c
HELP_FUNCS_FILES = ./help_funcs/*.c
ROUNDING_FILES = ./rounding/*.c

all: clean clang s21_decimal.a test gcov_report


clean:
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM debug s21_decimal

clang: clean
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format --style=Google -i */*.c */*.h *.h
	clang-format --style=Google -n */*.c */*.h *.h

	rm .clang-format


gcov_report: s21_decimal.a 
	rm -f *.g*
	$(CC) $(CC_FLAGS) $(TEST_FLAGS) $(ARITHMETIC_FILES) $(COMPARISION_FILES) $(CONVERTORS_FILES) $(ROUNDING_FILES) $(HELP_FUNCS_FILES) tests_decimal/*.c libs21_decimal.a $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t ./a.out -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno s21_tests s21_tests.info

s21_decimal.a: s21_decimal.o
	ar rcs libs21_decimal.a *.o
	rm -rf *.o
	ranlib libs21_decimal.a
	cp libs21_decimal.a s21_decimal.a
	cp libs21_decimal.a ls21_decimal.a


test: clean s21_decimal.a
	$(CC)  $(TEST_FLAGS) tests_decimal/*.c libs21_decimal.a $(CHECK_FLAGS) -L. -ls21_decimal
	./a.out
	

s21_decimal.o:
	$(CC) $(CFLAGS)  -c  $(ARITHMETIC_FILES) $(COMPARISION_FILES) $(CONVERTORS_FILES) $(ROUNDING_FILES) $(HELP_FUNCS_FILES)

rebuild:clean all
