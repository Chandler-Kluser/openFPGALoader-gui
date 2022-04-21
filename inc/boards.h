typedef struct {
    char name_combobox[20];
    char name[20];
} board_catalog;

board_catalog fpga_names[3] = {
    {.name_combobox = "Sipeed Tang Nano 1k\0",
    .name = "tangnano1k\0"},
    {.name_combobox = "Sipeed Tang Nano 4k\0",
    .name = "tangnano4k\0"},
    {.name_combobox = "Sipeed Tang Nano 9k\0",
    .name = "tangnano9k\0"},
};