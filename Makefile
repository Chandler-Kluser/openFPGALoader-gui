CFLAGS += -g
CFLAGS += -Iinc
CFLAGS += -mfpmath=sse -msse -msse2 -pthread -I/usr/include/gtk-4.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/harfbuzz -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng16 -I/usr/include/x86_64-linux-gnu -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/graphene-1.0 -I/usr/lib/x86_64-linux-gnu/graphene-1.0/include -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
CFLAGS += `pkg-config --cflags glib-2.0`
CFLAGS += `pkg-config --cflags gtk4`
LIBS += `pkg-config --libs gtk4`
LIBS += `pkg-config --libs glib-2.0`

all:
	gcc $(CFLAGS) main.c -o openFPGALoader-gui $(LIBS)

clean:
	rm -rf openFPGALoader-gui
