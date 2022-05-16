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

// extern to not cause trouble to gnu linker
extern char *path_name;
extern GtkWidget *combobox_board;
extern GtkWidget *combobox_flash;
extern GtkWidget *path_entry_text;
extern GtkApplication *app;

extern void call_dir_dialog(GtkWidget *widget, gpointer data);
extern void on_save_response(GtkDialog *dialog, int response);
extern void call_program(GtkWidget *widget, gpointer data);

char* update_buffer(GtkWidget *widget, gpointer data);
void activate (GtkApplication *app, gpointer user_data);
#endif