#ifndef GUIELEMENTS_H
#define GUIELEMENTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <boards.h>
#include <texts.h>

// extern to not cause trouble to gnu linker
extern char *path_name;
extern char *buffer;
extern GtkWidget *combobox_board;
extern GtkWidget *combobox_flash;
extern GtkWidget *path_entry_text;
extern GtkApplication *app;
extern void call_dir_dialog(GtkWidget *widget, gpointer data);
extern void on_save_response(GtkDialog *dialog, int response);
extern void call_program(GtkWidget *widget, gpointer data);

GtkWidget *buffer_entry;
GtkEntryBuffer* buffer_entry_text;
GtkWidget *window;
GtkWidget *grid;
GtkWidget *label;
GtkWidget *button;
void update_buffer(void);
void activate (GtkApplication *app, gpointer user_data);

#endif