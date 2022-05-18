#include <gui-elements.h>

// char *argv_test[] = {"openFPGALoader\0", "--help\0", NULL};

void update_buffer(void) {
    path_name = calloc(strlen(gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(path_entry_text))))+1,sizeof(char));
    strcpy(path_name,gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(path_entry_text))));
    if (gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_board))==-1) {
        buffer = NO_BOARD_STR;
    } else {
        int board_index = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_board));
        if (gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_flash))==0) { // if flash is active
            buffer = calloc(strlen(program_name) + strlen(space) + strlen(board_flag) + strlen(space) + strlen(fpga_names[board_index].name) + strlen(space) + strlen(flash_flag) + strlen(space) + strlen(quotation_mark) + strlen(path_name) + strlen(quotation_mark) + 1, sizeof(char));
            strncpy(buffer, program_name, strlen(program_name));
            strncat(buffer, space, strlen(space));
            strncat(buffer, board_flag, strlen(board_flag));
            strncat(buffer, space, strlen(space));
            strncat(buffer, fpga_names[board_index].name, strlen(fpga_names[board_index].name));
            strncat(buffer, space, strlen(space));
            strncat(buffer, flash_flag, strlen(flash_flag));
            strncat(buffer, space, strlen(space));
            strncat(buffer, quotation_mark, strlen(quotation_mark));
            strncat(buffer, path_name, strlen(path_name));
            strncat(buffer, quotation_mark, strlen(quotation_mark));
        } else { // if flash to SRAM is active
            buffer = calloc(strlen(program_name) + strlen(space) + strlen(board_flag) + strlen(space) + strlen(fpga_names[board_index].name) + strlen(space) + strlen(quotation_mark) + strlen(path_name) + strlen(quotation_mark) + 1, sizeof(char));
            strncpy(buffer, program_name, strlen(program_name));
            strncat(buffer, space, strlen(space));
            strncat(buffer, board_flag, strlen(board_flag));
            strncat(buffer, space, strlen(space));
            strncat(buffer, fpga_names[board_index].name, strlen(fpga_names[board_index].name));
            strncat(buffer, space, strlen(space));
            strncat(buffer, quotation_mark, strlen(quotation_mark));
            strncat(buffer, path_name, strlen(path_name));
            strncat(buffer, quotation_mark, strlen(quotation_mark));
        }        
    }
    // updates the command preview entry
    gtk_entry_buffer_set_text(buffer_entry_text,buffer,strlen(buffer));
}

void activate(GtkApplication *app, gpointer user_data) {
    path_name = calloc(strlen(program_name)+1,sizeof(char));
    strcpy(path_name,program_name);
    buffer_entry_text = gtk_entry_buffer_new(path_name,strlen(path_name));

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
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);    

    combobox_board = gtk_combo_box_text_new();
    char buffer_index[200];
    for (int i = 0; i < sizeof(fpga_names)/sizeof(fpga_names[0]); i++) {
        sprintf(buffer_index,"%d",i);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combobox_board), buffer_index, fpga_names[i].name_combobox);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_board), -1);
    gtk_widget_set_size_request(GTK_WIDGET(combobox_board),200,MIN_BUTTON_HEIGHT);
    gtk_grid_attach(GTK_GRID(grid), combobox_board, 1, 0, 2, 1);
    gtk_widget_set_margin_end(combobox_board,WINDOW_MARGIN);
    gtk_widget_set_margin_bottom(combobox_board,WIDGET_MARGIN);

    // event handler:
    g_signal_connect(combobox_board,"changed",G_CALLBACK(update_buffer), NULL);

    // ==================================================================================

    label = gtk_label_new ("Program Mode: ");
    gtk_label_set_xalign(GTK_LABEL(label),0);
    gtk_grid_attach(GTK_GRID (grid), label, 0, 1, 1, 1);

    combobox_flash = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combobox_flash), "0", "Flash Memory");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combobox_flash), "1", "SRAM");
    gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_flash), 0);
    gtk_widget_set_size_request(GTK_WIDGET(combobox_flash),200,MIN_BUTTON_HEIGHT);
    gtk_grid_attach(GTK_GRID(grid), combobox_flash, 1, 1, 2, 1);
    gtk_widget_set_margin_end(combobox_flash,WINDOW_MARGIN);
    gtk_widget_set_margin_bottom(combobox_flash,WIDGET_MARGIN);

    // event handler:
    g_signal_connect(combobox_flash,"changed",G_CALLBACK(update_buffer), NULL);

    // ==================================================================================

    label = gtk_label_new("Path to File: ");
    gtk_label_set_xalign(GTK_LABEL(label),0);
    gtk_grid_attach(GTK_GRID (grid), label, 0, 2, 1, 1);

    path_entry_text = gtk_entry_new();
    gtk_grid_attach(GTK_GRID (grid), path_entry_text, 1, 2, 1, 1);
    gtk_widget_set_size_request(GTK_WIDGET(path_entry_text),MIN_PATHENTRY_WIDTH,MIN_BUTTON_HEIGHT);
    gtk_widget_set_margin_end(path_entry_text,WIDGET_MARGIN);

    // event handler:
    g_signal_connect(path_entry_text,"changed",G_CALLBACK(update_buffer), NULL);

    button = gtk_button_new_with_label("Path");
    // para dialogs a window mãe é obrigatória como argumento
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(call_dir_dialog), window);
    gtk_widget_set_size_request(GTK_WIDGET(button),MIN_PATHBUTTON_WIDTH,MIN_BUTTON_HEIGHT);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);
    gtk_widget_set_margin_end(button,WINDOW_MARGIN);

    // ==================================================================================

    buffer_entry = gtk_entry_new();
    gtk_entry_set_buffer(GTK_ENTRY(buffer_entry),buffer_entry_text);
    gtk_label_set_xalign(GTK_LABEL(buffer_entry),0);
    gtk_label_set_yalign(GTK_LABEL(buffer_entry),0);
    gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(buffer_entry), 0, 3, 3, 1);
    gtk_widget_set_size_request(buffer_entry,WINDOW_WIDTH,MIN_BUTTON_HEIGHT);
    gtk_widget_set_margin_end(buffer_entry,WINDOW_MARGIN);
    gtk_widget_set_margin_top(buffer_entry,WIDGET_MARGIN);

    // ==================================================================================

    button = gtk_button_new_with_label("Flash with shell");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(call_program_shell), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 2, 1);
    gtk_widget_set_size_request(GTK_WIDGET(button),80,MIN_BUTTON_HEIGHT);
    gtk_widget_set_margin_top(button,WIDGET_MARGIN);
    gtk_widget_set_margin_end(button,WIDGET_MARGIN);

    button = gtk_button_new_with_label("Flash with GUI");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(call_program), window);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 4, 1, 1);
    gtk_widget_set_size_request(GTK_WIDGET(button),80,MIN_BUTTON_HEIGHT);
    gtk_widget_set_margin_top(button,WIDGET_MARGIN);
    gtk_widget_set_margin_end(button,WINDOW_MARGIN);
    
    // ==================================================================================

    scrollview1 = gtk_scrolled_window_new();
	gtk_grid_attach(GTK_GRID(grid), scrollview1, 0, 5, 3, 1);
	gtk_widget_set_size_request(GTK_WIDGET(scrollview1),WINDOW_WIDTH,TERMINAL_HEIGHT);
    gtk_widget_set_margin_top(scrollview1,WIDGET_MARGIN*2);
    gtk_widget_set_margin_bottom(scrollview1,WINDOW_MARGIN);
    gtk_widget_set_margin_end(scrollview1,WINDOW_MARGIN);
    terminal = vte_terminal_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrollview1), terminal);

    // ==================================================================================

    gtk_widget_show(window);
}

void call_program_shell(void) {
    update_buffer();
    // old school way of running program
    int status = system(buffer);
}

void run_button(void) {
    vte_terminal_reset(VTE_TERMINAL(terminal),TRUE,TRUE);
    vte_terminal_set_xalign(VTE_TERMINAL(terminal),VTE_ALIGN_START);
    char *new = malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(new,buffer);
    strcat(new,"\n");
    vte_terminal_feed(VTE_TERMINAL(terminal),new,-1);
    free(new);
    get_argv_and_run_command();
}

void get_argv_and_run_command(void) {
    char *p0,*p1,*p2,*p3,*p4;
    if (gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_board))==-1) return NULL;
    else {
        int board_index = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_board));
        if (gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_flash))==0) { // if flash is active
            p0 = calloc(strlen(program_name) + 1, sizeof(char));
            strcpy(p0,program_name);
            p1 = calloc(strlen(board_flag) + 1, sizeof(char));
            strcpy(p1,board_flag);
            p2 = calloc(strlen(fpga_names[board_index].name) + 1, sizeof(char));
            strcpy(p2,fpga_names[board_index].name);
            p3 = calloc(strlen(flash_flag) + 1, sizeof(char));
            strcpy(p3,flash_flag);
            p4 = calloc(strlen(quotation_mark) + strlen(path_name) + strlen(quotation_mark) + 1, sizeof(char));
            strcat(p4,quotation_mark);
            strcat(p4,path_name);
            strcat(p4,quotation_mark);
            char *argv1[] = {p0,p1,p2,p3,p4,NULL};
            vte_terminal_spawn_async(VTE_TERMINAL(terminal),VTE_PTY_NO_HELPER,NULL,argv1,NULL,G_SPAWN_SEARCH_PATH,NULL,NULL,NULL,2000,NULL,NULL,NULL);
        } else { // if flash to SRAM is active
            p0 = calloc(strlen(program_name) + 1, sizeof(char));
            strcpy(p0,program_name);
            p1 = calloc(strlen(board_flag) + 1, sizeof(char));
            strcpy(p1,board_flag);
            p2 = calloc(strlen(fpga_names[board_index].name) + 1, sizeof(char));
            strcpy(p2,fpga_names[board_index].name);
            p3 = calloc(strlen(quotation_mark) + strlen(path_name) + strlen(quotation_mark) + 1, sizeof(char));
            strcat(p3,quotation_mark);
            strcat(p3,path_name);
            strcat(p3,quotation_mark);
            char *argv2[] = {p0,p1,p2,p3,NULL};
            vte_terminal_spawn_async(VTE_TERMINAL(terminal),VTE_PTY_NO_HELPER,NULL,argv2,NULL,G_SPAWN_SEARCH_PATH,NULL,NULL,NULL,2000,NULL,NULL,NULL);
        }        
    }
}