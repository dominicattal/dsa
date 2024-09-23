export TEMP := ./.git/info/tmp
export TMP := ./.git/info/tmp

CC=gcc
CFLAGS=
NAME=a
OBJ_DIR=objs
SRCS = $(shell find * -name "\*.c")
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Istructs -Ialgs

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $^ -o $@ -Istructs -Ialgs

clean:
	rm -r $(OBJ_DIR) a.exe

.PHONY: clean