CC=gcc
CFLAGS=-Wall -Werror -Wextra -g
LDFLAGS=-lcheck -pthread -lgcov -lm
ifeq ($(shell uname), Linux)
	LDFLAGS+=-lsubunit
endif

GCOVFLAGS=--coverage

OBJS_DIR=obj

GCOV_REPORT=gcov_report
GCOV_DIR=gcov
GCOV_OBJ_DIR=$(GCOV_DIR)/$(OBJS_DIR)

LIB_SRCS=realized_math.c
LIB_OBJS=$(patsubst %.c,$(OBJS_DIR)/%.o,$(LIB_SRCS))
LIB_OBJS_GCOV=$(patsubst %.c,$(GCOV_OBJ_DIR)/%.o,$(LIB_SRCS))
LIB=realized_math.a

TEST=test
TEST_SRCS=test.c

all: $(LIB)

$(TEST): $(TEST_SRCS) $(LIB_OBJS_GCOV)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(LIB): $(LIB_OBJS)
	ar rcs $(LIB) $^

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(GCOV_OBJ_DIR)/%.o: %.c
	mkdir -p $(GCOV_OBJ_DIR)
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

$(GCOV_REPORT): $(TEST)
	mkdir -p $(GCOV_DIR)
	./test > /dev/null 2>&1 || true
	gcovr --html --html-details -o $(GCOV_DIR)/$(GCOV_REPORT).html --filter $(LIB_SRCS)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST)

clean:
	rm -rf $(OBJS_DIR)/* $(LIB) $(TEST) $(GCOV_DIR)/*

rebuild: clean all

.PHONY: all clean rebuild $(GCOV_REPORT) valgrind
