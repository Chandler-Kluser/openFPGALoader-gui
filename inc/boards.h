typedef struct {
    char name_combobox[40];
    char name[40];
} board_catalog;

board_catalog fpga_names[76] = {
    {.name_combobox = "Sipeed Tang Nano GW1N-1",
    .name = "tangnano"},
    {.name_combobox = "Sipeed Tang Nano 1k GW1NZ-1",
    .name = "tangnano1k"},
    {.name_combobox = "Sipeed Tang Nano 4k GW1NSR-4C",
    .name = "tangnano4k"},
    {.name_combobox = "Sipeed Tang Nano 9k GW1NR-9C",
    .name = "tangnano9k"},
    {.name_combobox = "Artix xc7a200t2fbg676c",
    .name = "ac701"},
    {.name_combobox = "Artix xc7a200tsbg484",
    .name = "acornCle215"},
    {.name_combobox = "Artix xc7a35tftg256",
    .name = "alchitry_au"},
    {.name_combobox = "Artix xc7a35ticsg324",
    .name = "arty_a7_35t"},
    {.name_combobox = "Artix xc7a100tcsg324",
    .name = "arty_a7_100t"},
    {.name_combobox = "Spartan7 xc7s25csga324",
    .name = "arty_s7_25"},
    {.name_combobox = "Spartan7 xc7s50csga324",
    .name = "arty_s7_50"},
    {.name_combobox = "Zynq7000 xc7z010csg400",
    .name = "arty_z7_10"},
    {.name_combobox = "Zynq7000 xc7z020csg400",
    .name = "arty_z7_20"},
    {.name_combobox = "Spartan6 xc6slx25",
    .name = "arty"},
    {.name_combobox = "Spartan6 xc6slx25",
    .name = "arty"},
    {.name_combobox = "ZynqMPSoC XCZU2CG",
    .name = "axu2cga"},
    {.name_combobox = "Artix xc7a35tcpg236",
    .name = "basys3"},
    {.name_combobox = "Cologne Chip GateMate Series",
    .name = "gatemate_evb_jtag"},
    {.name_combobox = "Cologne Chip GateMate Series",
    .name = "gatemate_evb_spi"},
    {.name_combobox = "Cologne Chip GateMate Series",
    .name = "gatemate_pgm_spi"},
    {.name_combobox = "ECP5 LFE5U-25F-6BG256C",
    .name = "colorlight"},
    {.name_combobox = "ECP5 LFE5U-25F-6BG381C",
    .name = "colorlight-i5"},
    {.name_combobox = "ECP5 LFE5U-45F-6BG381C",
    .name = "colorlight-i9"},
    {.name_combobox = "Nexus LIFCL-40",
    .name = "crosslinknx_evn"},
    {.name_combobox = "Cyclone 10 LP 10CL025YU256C8G",
    .name = "cyc1000"},
    {.name_combobox = "Cyclone III EP3C16F484C6",
    .name = "de0"},
    {.name_combobox = "Cyclone IV E EP4CE22F17C6",
    .name = "de0nano"},
    {.name_combobox = "Cyclone V SoC 5CSEMA4U23C6",
    .name = "de0nanoSoc"},
    {.name_combobox = "Cyclone V SoC 5CSEBA6U23I7",
    .name = "de10nano"},
    {.name_combobox = "Cyclone V SoC 5CSEMA5F31C6",
    .name = "de1Soc"},
    {.name_combobox = "ECP5G LFE5UM5G-85F",
    .name = "ecp5_evn"},
    {.name_combobox = "ECP5 LFE5UM5G-85F",
    .name = "ecpix5"},
    {.name_combobox = "Trion T8F81",
    .name = "fireant"},
    {.name_combobox = "iCE40UltraPlus UP5K",
    .name = "fomu"},
    {.name_combobox = "littleBee GW1NS-2C",
    .name = "honeycomb"},
    {.name_combobox = "iCE40UltraPlus UP5K",
    .name = "ice40_generic"},
    {.name_combobox = "iCE40UltraPlus UP5K",
    .name = "icebreaker-bitsy"},
    {.name_combobox = "iCE40 HX1k",
    .name = "ice40_generic"},
    {.name_combobox = "iCE40 HX8k",
    .name = "ice40_generic"},
    {.name_combobox = "iCE40 HX1k",
    .name = "ice40_generic"},
    {.name_combobox = "iCE40 HX8k",
    .name = "ice40_generic"},
    {.name_combobox = "iCE40-UP5K",
    .name = "ice40_generic"},
    {.name_combobox = "iCE40 HX4k",
    .name = "ice40_generic"},
    {.name_combobox = "Kintex7 xc7k325t",
    .name = "kc705"},
    {.name_combobox = "eagle s20 EG4S20BG256",
    .name = "licheeTang"},
    {.name_combobox = "MachXO2 LCMXO2-7000HE",
    .name = "machXO2EVN"},
    {.name_combobox = "MachXO3D LCMXO3D-9400HC",
    .name = "machXO3EVN"},
    {.name_combobox = "MachXO3 LCMX03LF-6900C",
    .name = "machXO3SK"},
    {.name_combobox = "Artix xc7a200tsbg484",
    .name = "nexysVideo"},
    {.name_combobox = "ECP5 LFE5U-25F-8MG285C",
    .name = "orangeCrab"},
    {.name_combobox = "Spartan3E xc3s500e-vq100",
    .name = "papilio_one"},
    {.name_combobox = "Spartan6 xc6slx45-csg324",
    .name = "pipistrello"},
    {.name_combobox = "Zynq7000 xc7z020clg400",
    .name = "pynq_z2"},
    {.name_combobox = "Cyclone IV EP4CE15F23C8N",
    .name = "qmtechCycloneIV"},
    {.name_combobox = "Cyclone V 5CEFA2F23I7",
    .name = "qmtechCycloneV"},
    {.name_combobox = "Cyclone V 5CEFA5F23I7",
    .name = "qmtechCycloneV_5ce523"},
    {.name_combobox = "Kintex xc7k325tffg676",
    .name = "qmtechKintex7"},
    {.name_combobox = "Kintex xc7k325tffg900",
    .name = "genesys2"},
    {.name_combobox = "littleBee GW1N-4",
    .name = "runber"},
    {.name_combobox = "Spartan6 xc6slx25-3-ftg256",
    .name = "runber"},
    {.name_combobox = "Spartan7 xc7s15ftgb196",
    .name = "spartanEdgeAccelBoard"},
    {.name_combobox = "Spartan6 xc6slx150Tfgg484",
    .name = "SPEC150"},
    {.name_combobox = "littleBee GW1NR-9",
    .name = "tec0117"},
    {.name_combobox = "ECP5 LFE5U",
    .name = "ulx3s"},
    {.name_combobox = "ECP5 LFE5U",
    .name = "ulx3s_dfu"},
    {.name_combobox = "Artix xc7a50tcpg236",
    .name = "xtrx"},
    {.name_combobox = "Trion T8F81",
    .name = "xyloni_spi"},
    {.name_combobox = "Trion T120BGA576",
    .name = "trion_t120_bga576_spi"},
    {.name_combobox = "Titanium Ti60F225",
    .name = "trion_ti60_f225_spi"},
    {.name_combobox = "Xilinx xc3s200ft256, xcf01s",
    .name = "xmf3"},
    {.name_combobox = "zynq7000 xc7z020clg484",
    .name = "zc702"},
    {.name_combobox = "zynq7000 xc7z045ffg900",
    .name = "zc706"},
    {.name_combobox = "zynqMPSoC XCZU9EG",
    .name = "zcu102"},
    {.name_combobox = "zynq7000 xc7z020clg484",
    .name = "zedboard"},
    {.name_combobox = "zynq7000 xc7z010clg400",
    .name = "zybo_z7_10"},
    {.name_combobox = "zynq7000 xc7z020clg400",
    .name = "zybo_z7_20"},
};