CC = gcc
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
# binary name
BIN = openFPGALoader-gui

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# flag for debug tools
CFLAGS += -g
# including inc folder
CFLAGS += -Iinc
# including packages and libs
CFLAGS += `pkg-config --cflags gtk4 glib-2.0 vte-2.91-gtk4`
LIBS += `pkg-config --libs gtk4 glib-2.0 vte-2.91-gtk4`

.PHONY: all clean

all: $(BIN_DIR)/$(BIN)

$(BIN_DIR)/$(BIN): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -rv $(BIN_DIR) $(OBJ_DIR)