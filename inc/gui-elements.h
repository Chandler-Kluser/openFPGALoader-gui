#ifndef GUIELEMENTS_H
#define GUIELEMENTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <vte/vte.h>
#include <boards.h>
#include <texts.h>

// extern to not cause trouble to gnu linker
extern char *path_name,*buffer;
extern GtkWidget *combobox_board,*combobox_flash,*path_entry_text;
extern GtkApplication *app;
extern void call_dir_dialog(GtkWidget *widget, gpointer data);
extern void on_save_response(GtkDialog *dialog, int response);
extern void call_program(GtkWidget *widget, gpointer data);

char *argv_test[];
GtkEntryBuffer *buffer_entry_text;
GtkWidget *window,*grid,*label,*button,*buffer_entry,*terminal,*scrollview1;
void update_buffer(void);
void activate (GtkApplication *app, gpointer user_data);
void run_button(void);
#endif