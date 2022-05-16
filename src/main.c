#include <main.h>

void call_program(GtkWidget *widget, gpointer data) {
    char *buf = update_buffer(widget,data);
    int status = system(buf);
    free(buf);
}

void on_save_response(GtkDialog *dialog, int response) {
    if (response == GTK_RESPONSE_ACCEPT) {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        path_name = g_file_get_path(gtk_file_chooser_get_file(chooser));
        gtk_entry_buffer_set_text(gtk_entry_get_buffer(path_entry_text),path_name,-1);
        // TO DO: UPDATE THE PREVIEW ENTRY WHEN SETTING NEW PATH TO FILE
        // GtkWidget widget = gtk_dialog_get_widget_for_response(dialog,)
        // char *buf = update_buffer(widget,data);
        // gtk_entry_buffer_set_text(buf)
    }
    gtk_window_destroy(GTK_WINDOW(dialog));
}

void call_dir_dialog(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new("Open File",GTK_WINDOW(widget),GTK_FILE_CHOOSER_ACTION_OPEN,"Cancel",GTK_RESPONSE_CANCEL,"Open",GTK_RESPONSE_ACCEPT,NULL);
    gtk_widget_show(dialog);
    g_signal_connect(dialog,"response",G_CALLBACK(on_save_response),NULL);
}

int main (int argc, char **argv) {
    int status;

    app = gtk_application_new("org.gtk.example",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app,"activate",G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
