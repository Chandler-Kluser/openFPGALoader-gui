#ifndef BOARDS_H
#define BOARDS_H

typedef struct {
    char name_combobox[40];
    char name[40];
} board_catalog;

extern board_catalog fpga_names[76];

#endif