CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LDFLAGS = -static -L./$(LIB_DIR) -l:$(LIB)
INCLUDES = -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR)

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:%.c=%.o))

LIB_DIR = libmx
LIB = libmx.a

TARGET = pathfinder

.PHONY: all clean uninstall reinstall

all: $(LIB) $(TARGET)

$(LIB):
	make -C $(LIB_DIR)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LDFLAGS) -o $@

$(OBJ): $(SRC)
	mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^
	mv *.o $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean

uninstall:
	rm -f $(TARGET)
	make -C $(LIB_DIR) uninstall

reinstall:
	make -C $(LIB_DIR) reinstall
	make clean
	make uninstall
	make all
