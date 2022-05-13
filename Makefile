CC = gcc
SRC_DIR = src/
OBJ_DIR = obj/
BIN_DIR = bin/

BIN = openFPGALoader-gui
 
SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

# flag for debug tools
CFLAGS += -g
# including inc folder
CFLAGS += -Iinc
# including packages and libs
CFLAGS += `pkg-config --cflags glib-2.0`
CFLAGS += `pkg-config --cflags gtk4`
LIBS += `pkg-config --libs gtk4`
LIBS += `pkg-config --libs glib-2.0`

.PHONY: all clean

all: $(BIN_DIR)$(BIN)

$(BIN_DIR)$(BIN): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)
