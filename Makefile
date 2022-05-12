BIN = openFPGALoader-gui
CFLAGS += -g
CFLAGS += -Iinc
CFLAGS += `pkg-config --cflags glib-2.0`
CFLAGS += `pkg-config --cflags gtk4`
LIBS += `pkg-config --libs gtk4`
LIBS += `pkg-config --libs glib-2.0`

all:
	gcc $(CFLAGS) main.c -o $(BIN) $(LIBS)

clean:
	rm -rf $(BIN)
