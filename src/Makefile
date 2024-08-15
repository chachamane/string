CC = gcc 
FLAGS = -std=c11 -Wall -Wextra -Werror 
ASAN:=#-g -fsanitize=address
# TEST_FLAGS = -lcheck -I /opt/homebrew/opt/check/include -L /opt/homebrew/opt/check/lib -lpthread -pthread
#TEST_FLAGS = -lcheck -I/usr/local/include -L/usr/local/lib -lpthread -pthread
TEST_FLAGS = -lcheck -lpthread -pthread

OS = $(shell uname -s)
ifeq ($(OS), Darwin)
# TEST_FLAGS=-lcheck
OPEN=open
else ifeq ($(shell hostnamectl | grep -o 'Ubuntu'), Ubuntu)
# TEST_FLAGS=-lpthread -lcheck  -Wno-nonnull -Wno-memset-transposed-args -lm -lsubunit
OPEN=open
else
# TEST_FLAGS=-lpthread -lm -lcheck  -Wno-nonnull -Wno-memset-transposed-args
OPEN=xdg-open
endif
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

TARGET = s21_string.a

HEADER = s21_string.h 
FUNCS_SRC = $(wildcard functions/s21_*.c)
OBJ = $(patsubst %.c,%.o, ${FUNCS_SRC})
TESTS_SRC = $(wildcard tests/s21_*.c)

s21_string.a: $(FUNCS_SRC) 
	$(CC) -c $(FLAGS) $(FUNCS_SRC)
	mv *.o functions/
	ar rcs s21_string.a $(OBJ)
	ranlib s21_string.a
	rm -rf ./*/*.o

.DELETE_ON_ERROR:
all: clang $(TARGET) test gcov_report

test: $(TARGET)
	${CC} ${TESTS_SRC} $(TARGET) -o tests.out $(TEST_FLAGS) $(ASAN) -L.

test_gcov: $(TARGET)
	${CC} ${TESTS_SRC} $(TARGET) -o tests.out $(TEST_FLAGS) $(GCOV_FLAGS) -L.

gcov_report: test_gcov
	./tests.out
	lcov -o tests.info -c -d .  
	genhtml -o gcovreport tests.info
	$(OPEN) gcovreport/index.html  
	make clean

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format; \
	clang-format -style=Google -i ./*/*.c *.h; \
	rm .clang-format

stylecheck:
	cp ../materials/linters/.clang-format ../src/.clang-format; \
	clang-format -style=Google -n ./*/*.c *.h; \
	rm .clang-format

clean: 
	@rm -rf $(TARGET) *.out *.o *.gcda *.gcno *.gcov *.a *.info *.log

clean_gcov:
	@rm -rf gcovreport