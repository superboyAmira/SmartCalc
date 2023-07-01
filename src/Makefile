# Common
SYS = $(shell uname)
CC = gcc
DEBUG_FLAGS =-Wall -Wextra -Werror #-g -fsanitize=adress # dont work with gcov and verter faild with him
FLAGS = -c $(DEBUG_FLAGS) -std=c11
LEAKS = nothing

# Library
LIB_SRC = 
SRCS = $(addprefix $(LIB_SRC), s21_calc.c s21_credit.c s21_deposit.c)
OBJS = $(SRCS:%.c=%.o)

LIB_NAME = s21_calc.a
LIB_FLAGS = -lcheck -lm -lpthread

# UI
APP_DIR = UIKIT
APP = SmarCalc.app
# Testing
TEST_SRC = s21_calc_tests.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_FLAGS_GCOV = --coverage -Wall -Wextra -Werror
REPORT_NAME = gcov_result
GCOV_INFO = gcov_result.info

ifeq ($(SYS), Darwin)
	LIB_FLAGS = -lcheck
	LEAKS = leaks --atExit -- test
	APP = UIKIT.app
else
	LIB_FLAGS = -lcheck -lsubunit -pthread -lrt -lm
	LEAKS = CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test
	APP = UIKIT
endif

all: clean dvi install

s21_calc.a: $(OBJS)
	ar rc $(LIB_NAME) $(OBJS)
	ranlib $(LIB_NAME)
	rm -rf *.o

%.o: %.c s21_calc.h
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -rf lib_obj lib/*.o ./*.a ./*.o ./a.out gcov_test report lib/*.dSYM ./*.gcno ./*.gcda ./*.info ./*.dSYM ./CPPLINT*

test: s21_calc.a
	$(CC) $(TEST_FLAGS_GCOV) $(TEST_SRC) $(SRCS) $(LIB_NAME) $(LIB_FLAGS) -o gcov_test $(shell pkg-config --libs --cflags check)
	chmod +x *
	./gcov_test

gcov_report: s21_calc.a
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d . # -t отвечает за имя теста https://stackoverflow.com/questions/837639/is-there-a-way-to-focus-lcov-code-coverage-reports-to-just-one-or-two-directorie
	genhtml -o report/ gcov_test.info # генерирует html страницу
	open ./report/index.html

dvi:
	open readme.html

install:
	rm -rf build
	mkdir build
	cd $(APP_DIR) && qmake && make && mv $(APP) ../build && cd ..

uninstall: clean
	rm -rf build*
	rm -rf $(APP_DIR)/moc*
	rm -rf $(APP_DIR)/*.o
	rm -rf $(APP_DIR)/ui*

dist: install
	rm -rf Archive_calc_v1.0/
	mkdir Archive_calc_v1.0/
	mkdir Archive_calc_v1.0/src
	cp -r ./build/$(APP).app Archive_calc_v1.0/src/
	tar cvzf Archive_calc_v1.0.tgz Archive_calc_v1.0/
	rm -rf Archive_calc_v1.0/

check: test
	cp ../materials/linters/.clang-format .
	clang-format -style=google -n *.c
	rm -rf .clang-format
	# cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h lib/*.c
	# cp ../materials/linters/CPPLINT.cfg .
	# python3 ../materials/linters/cpplint.py --extension=c lib/*.c lib/*.h
	# rm -rf CPPLINT.cfg

leaks: test
	$(LEAKS)