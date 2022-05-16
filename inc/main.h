#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <boards.h>
#include <texts.h>

// extern to not cause trouble to gnu linker
extern GtkWidget *buffer_entry;
extern GtkEntryBuffer* buffer_entry_text;
extern GtkWidget *window;
extern GtkWidget *grid;
extern GtkWidget *label;
extern GtkWidget *button;
extern void update_buffer(void);
extern void activate (GtkApplication *app, gpointer user_data);

char *path_name;
char *buffer;
GtkWidget *combobox_board;
GtkWidget *combobox_flash;
GtkWidget *path_entry_text;
GtkApplication *app;
void call_dir_dialog(GtkWidget *widget, gpointer data);
void on_save_response(GtkDialog *dialog, int response);
void call_program(GtkWidget *widget, gpointer data);

#endif