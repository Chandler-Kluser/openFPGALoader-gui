#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <boards.h>
#include <texts.h>
#define WINDOW_WIDTH 600
#define WINDOW_MARGIN 10
#define WIDGET_MARGIN 5

char *path_name;
GtkWidget *combobox_board;
GtkWidget *combobox_flash;
GtkWidget *path_entry_text;