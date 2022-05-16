#include <gui-elements.h>

char* update_buffer(GtkWidget *widget, gpointer data) {
    char *buf;
    path_name = gtk_entry_buffer_get_text(gtk_entry_get_buffer(path_entry_text));
    if (gtk_combo_box_get_active(combobox_board)==-1) {
        printf("No board choosen, pick a board to flash.\n");
    }
    else {
        int board_index = gtk_combo_box_get_active(combobox_board);
        if (gtk_combo_box_get_active(combobox_flash)==0) { // if flash is active
            buf = calloc(strlen(program_name) + strlen(space) + strlen(board_flag) + strlen(space) + strlen(fpga_names[2].name) + strlen(space) + strlen(flash_flag) + strlen(space) + strlen(quotation_mark) + strlen(path_name) + strlen(quotation_mark) + 1, sizeof(char));
            strncpy(buf, program_name, strlen(program_name));
            strncat(buf, space, strlen(space));
            strncat(buf, board_flag, strlen(board_flag));
            strncat(buf, space, strlen(space));
            strncat(buf, fpga_names[board_index].name, strlen(fpga_names[board_index].name));
            strncat(buf, space, strlen(space));
            strncat(buf, flash_flag, strlen(flash_flag));
            strncat(buf, space, strlen(space));
            strncat(buf, quotation_mark, strlen(quotation_mark));
            strncat(buf, path_name, strlen(path_name));
            strncat(buf, quotation_mark, strlen(quotation_mark));
        } else { // if flash to SRAM is active
            buf = calloc(strlen(program_name) + strlen(space) + strlen(board_flag) + strlen(space) + strlen(fpga_names[2].name) + strlen(space) + strlen(quotation_mark) + strlen(path_name) + strlen(quotation_mark) + 1, sizeof(char));
            strncpy(buf, program_name, strlen(program_name));
            strncat(buf, space, strlen(space));
            strncat(buf, board_flag, strlen(board_flag));
            strncat(buf, space, strlen(space));
            strncat(buf, fpga_names[board_index].name, strlen(fpga_names[board_index].name));
            strncat(buf, space, strlen(space));
            strncat(buf, quotation_mark, strlen(quotation_mark));
            strncat(buf, path_name, strlen(path_name));
            strncat(buf, quotation_mark, strlen(quotation_mark));
        }
        printf("buffer is: %s\n", buf);
    }
    return *buf;
}

void activate (GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label;
    GtkWidget *buffer_entry;
    path_name = "openFPGALoader";
    GtkEntryBuffer* buffer_entry_text = gtk_entry_buffer_new(path_name,strlen(path_name));
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

    combobox_board = gtk_combo_box_text_new();
    char buffer_index[200];
    for (int i = 0; i < sizeof(fpga_names)/sizeof(fpga_names[0]); i++) {
        sprintf(buffer_index,"%d",i);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combobox_board), buffer_index, fpga_names[i].name_combobox);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_board), -1);
    gtk_widget_set_size_request(GTK_WIDGET(combobox_board),200,12);
    gtk_grid_attach(GTK_GRID(grid), combobox_board, 1, 0, 2, 1);
    gtk_widget_set_margin_end(combobox_board,WINDOW_MARGIN);
    gtk_widget_set_margin_bottom(combobox_board,WIDGET_MARGIN);

    // ==================================================================================

    label = gtk_label_new ("Program Mode: ");
    gtk_label_set_xalign(GTK_LABEL(label),0);
    gtk_grid_attach(GTK_GRID (grid), label, 0, 1, 1, 1);

    combobox_flash = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combobox_flash), "0", "Flash Memory");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combobox_flash), "1", "SRAM");
    gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_flash), 0);
    gtk_widget_set_size_request(GTK_WIDGET(combobox_flash),200,12);
    gtk_grid_attach(GTK_GRID(grid), combobox_flash, 1, 1, 2, 1);
    gtk_widget_set_margin_end(combobox_flash,WINDOW_MARGIN);
    gtk_widget_set_margin_bottom(combobox_flash,WIDGET_MARGIN);

    // ==================================================================================

    label = gtk_label_new("Path to File: ");
    gtk_label_set_xalign(GTK_LABEL(label),0);
    gtk_grid_attach(GTK_GRID (grid), label, 0, 2, 1, 1);

    path_entry_text = gtk_entry_new();
    gtk_grid_attach(GTK_GRID (grid), path_entry_text, 1, 2, 1, 1);
    gtk_widget_set_size_request(GTK_WIDGET(path_entry_text),200,12);
    gtk_widget_set_margin_end(path_entry_text,WIDGET_MARGIN);

    button = gtk_button_new_with_label("Path");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(call_dir_dialog), window); // para dialogs a window mãe é obrigatória como argumento
    gtk_widget_set_size_request(GTK_WIDGET(button),70,12);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);
    gtk_widget_set_margin_end(button,WINDOW_MARGIN);

    // ==================================================================================

    buffer_entry = gtk_entry_new();
    gtk_entry_set_buffer(buffer_entry,buffer_entry_text);
    gtk_label_set_xalign(GTK_LABEL(buffer_entry),0);
    gtk_label_set_yalign(GTK_LABEL(buffer_entry),0);
    gtk_grid_attach(GTK_GRID (grid), buffer_entry, 0, 3, 3, 1);
    gtk_widget_set_size_request(buffer_entry,WINDOW_WIDTH,12);
    gtk_widget_set_margin_end(buffer_entry,WINDOW_MARGIN);
    gtk_widget_set_margin_top(buffer_entry,WIDGET_MARGIN);

    // ==================================================================================

    button = gtk_button_new_with_label("Flash");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(call_program), window);
    gtk_grid_attach(GTK_GRID (grid), button, 0, 4, 3, 1);
    gtk_widget_set_size_request(GTK_WIDGET(button),150,12);
    gtk_widget_set_margin_top(button,WIDGET_MARGIN);
    gtk_widget_set_margin_bottom(button,WINDOW_MARGIN);
    gtk_widget_set_margin_end(button,WINDOW_MARGIN);
    gtk_widget_show(window);
}