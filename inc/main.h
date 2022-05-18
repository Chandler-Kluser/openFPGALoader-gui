#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <vte/vte.h>
#include <boards.h>
#include <texts.h>

// extern to not cause trouble to gnu linker
extern GtkEntryBuffer* buffer_entry_text;
extern GtkWidget *window,*grid,*label,*button,*buffer_entry,*terminal,*scrollview1;
extern void update_buffer(void);
extern void activate (GtkApplication *app, gpointer user_data);
extern void run_button(void);

char *path_name,*buffer;
GtkWidget *combobox_board,*combobox_flash,*path_entry_text;
GtkApplication *app;
void call_dir_dialog(GtkWidget *widget, gpointer data);
void on_save_response(GtkDialog *dialog, int response);
void call_program(GtkWidget *widget, gpointer data);
#endif