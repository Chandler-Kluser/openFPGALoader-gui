#ifndef GUIELEMENTS_H
#define GUIELEMENTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <boards.h>
#include <texts.h>
#define WINDOW_WIDTH 600
#define WINDOW_MARGIN 10
#define WIDGET_MARGIN 5

extern char *path_name;
extern GtkWidget *combobox_board;
extern GtkWidget *combobox_flash;
extern GtkWidget *path_entry_text;
int sum1(int a);
#endif