#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <boards.h>
#include <texts.h>
#define WINDOW_WIDTH 600
#define WINDOW_MARGIN 10
#define WIDGET_MARGIN 5
#include <gui-elements.h>

char *path_name;
GtkWidget *combobox_board;
GtkWidget *combobox_flash;
GtkWidget *path_entry_text;
GtkApplication *app;

// extern to not cause trouble to gnu linker
extern char* update_buffer(GtkWidget *widget, gpointer data);
extern void activate (GtkApplication *app, gpointer user_data);

void call_dir_dialog(GtkWidget *widget, gpointer data);
void on_save_response(GtkDialog *dialog, int response);
void call_program(GtkWidget *widget, gpointer data);

#endif