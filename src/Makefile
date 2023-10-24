CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
LDFLAGS = -lcheck -lm -lpthread

SOURCES = tests.c
EXECUTABLE = tests
TEST_FLAGS = --coverage $(LDFLAGS) 

FUNC_DIR = lib_functions
OBJ_DIR = obj
GCOV_DIR = report
GCOV_OBJ_DIR = obj/$(GCOV_DIR)

SRCS = $(shell find $(FUNC_DIR) -maxdepth 1 -iname '*.c')
OBJSNAME = $(shell basename -a $(SRCS))
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJSNAME:.c=.o))

ifeq ($(shell uname), Linux)
	LDFLAGS += -lsubunit -lrt
	TEST_FLAGS += -lsubunit -lrt
	OPEN=echo 'report: MathLib/src/$(GCOV_DIR)/index.html'
else
	OPEN=open ./$(GCOV_DIR)/index.html
endif

all: clean math.a

./$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(OBJ_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

./$(OBJ_DIR)/%.o:*/%.c
	@mkdir -p $(OBJ_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

math.a: $(OBJS)
	ar rcs $@ $^
	ranlib math.a

test: math.a check
	$(CC) $(CFLAGS) $(SOURCES) math.a -o $(EXECUTABLE) $(LDFLAGS)
	./$(EXECUTABLE)

gcov_report: check
	mkdir -p $(GCOV_DIR)
	$(CC) $(SRCS) $(SOURCES) -o greport $(TEST_FLAGS)
	./greport
	lcov -t "math" -o math.info -c -d .
	genhtml -o ./$(GCOV_DIR) math.info
	$(OPEN)

check:
	checkmk clean_mode=1 test_check/headers/*.check test_check/*.check > $(SOURCES)
	cp -f ../materials/linters/.clang-format ./.clang-format
	clang-format -i *.c *.h
	rm .clang-format

rebuild: clean all

clean:
	rm -rf $(OBJ_DIR)/* $(OBJ_DIR)/*.* $(EXECUTABLE) math.a *.gcda *.gcno *.info $(GCOV_DIR) check_math.c greport $(OBJ_DIR)