#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#define WINDOW_MARGIN 10
#define WIDGET_MARGIN 5

const char program_name[15] = "openFPGALoader\0";
const char space[2] = " \0";
const char board_flag[3] = "-b\0";
const char flash_flag[3] = "-f\0";
g_autoptr(GFile) firmware_to_burn = NULL;

typedef struct {
    int number;
    char name[10];
} board_catalog;

board_catalog fpga_names[3] = {
    {.number = 0,
    .name = "tangnano1k"},
    {.number = 1,
    .name = "tangnano4k"},
    {.number = 2,
    .name = "tangnano9k"},
};

static void call_program(GtkWidget *widget, gpointer data) {
    // ========================================================
    //
    // escrevendo na RAM
    // openFPGALoader -b <nome_da_placa> <nome_do_arquivo>
    // escrevendo na flash
    // openFPGALoader -b <nome_da_placa> -f <nome_do_arquivo>
    //
    // ========================================================
    char *path = g_file_get_path(firmware_to_burn);
    char *buf = calloc(strlen(program_name) + strlen(space) + strlen(board_flag) + strlen(space) + strlen(fpga_names[2].name) + strlen(space) + strlen(flash_flag) + strlen(space) + strlen(path) + 1, sizeof(char));

    strncpy(buf, program_name, strlen(program_name));
    strncat(buf, space, strlen(space));
    strncat(buf, board_flag, strlen(board_flag));
    strncat(buf, space, strlen(space));
    strncat(buf, fpga_names[2].name, strlen(fpga_names[2].name));
    strncat(buf, space, strlen(space));
    strncat(buf, flash_flag, strlen(flash_flag));
    strncat(buf, space, strlen(space));
    strncat(buf, path, strlen(path));

    printf("buffer is: %s\n", buf);
    int status = system(buf);
    free(path);
    free(buf);
}

static void on_save_response(GtkDialog *dialog, int response) {
    if (response == GTK_RESPONSE_ACCEPT) {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        firmware_to_burn = gtk_file_chooser_get_file(chooser);
        printf("File Path Updated to: %s\n",g_file_get_path(firmware_to_burn));
    }
    gtk_window_destroy(GTK_WINDOW(dialog));
}

static void update_entry_buffer(GtkWindow *window){
    // TO DO: add function to update entry
}

static void call_dir_dialog(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new("Open File",GTK_WINDOW(widget),GTK_FILE_CHOOSER_ACTION_OPEN,"Cancel",GTK_RESPONSE_CANCEL,"Open",GTK_RESPONSE_ACCEPT,NULL);
    gtk_widget_show(dialog);
    g_signal_connect(dialog,"response",G_CALLBACK(on_save_response),NULL);
}

static void activate (GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label;
    GtkWidget *text;
    GtkEntryBuffer *abuff;
    GtkWidget *ddown;
    GtkWidget *button;

    // ==================================================================================

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "openFPGALoader GUI");
    gtk_window_set_resizable (GTK_WINDOW(window),0);

    grid = gtk_grid_new();

    gtk_window_set_child(GTK_WINDOW(window), grid);
    gtk_widget_set_margin_start(grid,WINDOW_MARGIN);
    gtk_widget_set_margin_top(grid,WINDOW_MARGIN);

    // ==================================================================================

    label = gtk_label_new ("FPGA Model: ");

    gtk_label_set_xalign(GTK_LABEL(label),0);
    gtk_grid_attach(GTK_GRID (grid), label, 0, 0, 1, 1);

    ddown = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ddown), NULL, "Sipeed Tang Nano 1k");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ddown), NULL, "Sipeed Tang Nano 4k");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ddown), NULL, "Sipeed Tang Nano 9k");
    gtk_combo_box_set_active(GTK_COMBO_BOX(ddown), -1);

    gtk_widget_set_size_request(GTK_WIDGET(ddown),200,12);

    gtk_grid_attach(GTK_GRID(grid), ddown, 1, 0, 2, 1);
    gtk_widget_set_margin_end(ddown,WINDOW_MARGIN);
    gtk_widget_set_margin_bottom(ddown,WIDGET_MARGIN);

    // ==================================================================================

    label = gtk_label_new ("Program Mode: ");

    gtk_label_set_xalign(GTK_LABEL(label),0);
    gtk_grid_attach(GTK_GRID (grid), label, 0, 1, 1, 1);

    ddown = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ddown), NULL, "Flash Memory");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ddown), NULL, "SRAM");
    gtk_combo_box_set_active(GTK_COMBO_BOX(ddown), 0);

    gtk_widget_set_size_request(GTK_WIDGET(ddown),200,12);

    gtk_grid_attach(GTK_GRID(grid), ddown, 1, 1, 2, 1);
    gtk_widget_set_margin_end(ddown,WINDOW_MARGIN);
    gtk_widget_set_margin_bottom(ddown,WIDGET_MARGIN);

    // ==================================================================================

    label = gtk_label_new("Path to File: ");

    gtk_label_set_xalign(GTK_LABEL(label),0);
    gtk_grid_attach(GTK_GRID (grid), label, 0, 2, 1, 1);

    text = gtk_entry_new();
    gtk_grid_attach(GTK_GRID (grid), text, 1, 2, 1, 1);
    gtk_widget_set_size_request(GTK_WIDGET(text),200,12);
    gtk_widget_set_margin_end(text,WIDGET_MARGIN);

    button = gtk_button_new_with_label("Path");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(call_dir_dialog), window); // para dialogs a window mãe é obrigatória como argumento

    gtk_widget_set_size_request(GTK_WIDGET(button),70,12);

    gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);
    gtk_widget_set_margin_end(button,WINDOW_MARGIN);

    // ==================================================================================

    button = gtk_button_new_with_label("Flash");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(call_program), NULL);

    gtk_grid_attach (GTK_GRID (grid), button, 0, 3, 3, 1);
    gtk_widget_set_size_request(GTK_WIDGET(button),150,12);
    gtk_widget_set_margin_top(button,WIDGET_MARGIN);
    gtk_widget_set_margin_bottom(button,WINDOW_MARGIN);
    gtk_widget_set_margin_end(button,WINDOW_MARGIN);
    gtk_widget_show(window);
}

int main (int argc, char **argv) {
    GtkApplication *app;
    int status;    

    app = gtk_application_new("org.gtk.example",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app,"activate",G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
