# openFPGALoader-gui
A small [gtk4](https://www.gtk.org/) GUI to flash your FPGA projects
<p align="center">
  <img src="media\window.png">
</p>

## Building
- Make sure you have `gcc`, `make` and `gtk4` in your system
- Install [openFPGALoader](https://github.com/trabucayre/openFPGALoader) and have it available on your user `$PATH` variable
- Download this repository
- Make sure gtk libs are correctly described in `Makefile`, if you are not sure run:
```
pkg-config --cflags gtk4
```
to get the CFLAGS, and 
```
pkg-config --libs gtk4
```
to get the LIBS, then update `Makefile`
- Go to repository root folder and run `make` in your shell
## Release
If you do not want to build it in your computer, you can also download a built program and run it.

**ATTENTION**: Even using a binary release directly, you **must** have [openFPGALoader](https://github.com/trabucayre/openFPGALoader) installed and written in your `$PATH` variable
## Observations
I kept my [Visual Studio Code](https://code.visualstudio.com/) Setting files in the repository to help developers add more functionalities to the GUI