#include <gtk/gtk.h>
#include <stdlib.h>
#define WINDOW_MARGIN 10
#define WIDGET_MARGIN 5
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 300

static void call_program(GtkWidget *widget, gpointer data) {
    g_print("Calling Program...\n");
    int status = system("lite-xl");
}

static void call_dir_dialog(GtkWidget *widget, gpointer data, GtkWindow *window) {
    GtkWidget *dialog;
    GtkDialogFlags flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;
    gtk_dialog_new_with_buttons ("Select File to Flash",window,flags,"First Button");
    int status = system("lite-xl");
}

static void activate (GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label;
    GtkWidget *ddown;
    GtkWidget *button;

    // ==================================================================================

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "openFPGALoader GUI");
    // gtk_window_set_default_size(GTK_WINDOW(window),WINDOW_WIDTH,WINDOW_HEIGHT);
    gtk_window_set_resizable (GTK_WINDOW(window),0);

    grid = gtk_grid_new();

    gtk_window_set_child(GTK_WINDOW (window), grid);
    gtk_widget_set_margin_start(grid,WINDOW_MARGIN);
    gtk_widget_set_margin_top(grid,WINDOW_MARGIN);

    // ==================================================================================

    label = gtk_label_new ("FPGA Model: ");

    gtk_label_set_xalign(label,0);
    gtk_grid_attach(GTK_GRID (grid), label, 0, 0, 1, 1);

    ddown = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ddown), NULL, "Sipeed Tang Nano 1k");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ddown), NULL, "Sipeed Tang Nano 4k");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ddown), NULL, "Sipeed Tang Nano 9k");
    gtk_combo_box_set_active(GTK_COMBO_BOX(ddown), -1);

    gtk_widget_set_size_request(GTK_WIDGET(ddown),200,12);

    gtk_grid_attach(GTK_GRID(grid), ddown, 1, 0, 1, 1);
    gtk_widget_set_margin_end(ddown,WINDOW_MARGIN);
    gtk_widget_set_margin_bottom(ddown,WIDGET_MARGIN);

    // ==================================================================================

    label = gtk_label_new ("Program Mode: ");

    gtk_label_set_xalign(label,0);
    gtk_grid_attach(GTK_GRID (grid), label, 0, 1, 1, 1);

    ddown = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ddown), NULL, "Flash Memory");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ddown), NULL, "SRAM");
    gtk_combo_box_set_active(GTK_COMBO_BOX(ddown), 0);

    gtk_widget_set_size_request(GTK_WIDGET(ddown),200,12);

    gtk_grid_attach(GTK_GRID(grid), ddown, 1, 1, 1, 1);
    gtk_widget_set_margin_end(ddown,WINDOW_MARGIN);
    gtk_widget_set_margin_bottom(ddown,WIDGET_MARGIN);

    // ==================================================================================

    label = gtk_label_new ("Path to File: ");

    gtk_label_set_xalign(label,0);
    gtk_grid_attach(GTK_GRID (grid), label, 0, 2, 1, 1);

    // GtkTreePath *path;

    // path = gtk_tree_path_new();
    // gtk_tree_path_append_type (path, GTK_TYPE_WINDOW);
    // gtk_tree_path_append_type (path, GTK_TYPE_BUTTON);

    button = gtk_button_new_with_label ("Path");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(call_dir_dialog), window);

    gtk_widget_set_size_request(GTK_WIDGET(button),200,12);

    gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);
    gtk_widget_set_margin_end(button,WINDOW_MARGIN);

    // ==================================================================================

    button = gtk_button_new_with_label("Flash");
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (call_program), window);

    gtk_grid_attach (GTK_GRID (grid), button, 0, 3, 2, 1);
    gtk_widget_set_size_request(GTK_WIDGET(button),150,12);
    gtk_widget_set_margin_top(button,WIDGET_MARGIN);
    gtk_widget_set_margin_bottom(button,WINDOW_MARGIN);
    gtk_widget_set_margin_end(button,WINDOW_MARGIN);

    gtk_widget_show (window);

}

int main (int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
