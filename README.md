# openFPGALoader-gui
A small [gtk4](https://www.gtk.org/) GUI to flash your FPGA projects
<p align="center">
  <img src="media\window.png">
</p>

## Building
- Make sure you have `gcc`, `make`, `glib-2.0`, `pkg-config` and `gtk4` in your system
- Install [openFPGALoader](https://github.com/trabucayre/openFPGALoader) and have it available on your user `$PATH` variable
- Download this repository
```
git clone https://github.com/Chandler-Kluser/openFPGALoader-gui.git
```
- Go to repository root folder and run `make` in your shell
```
cd openFPGALoader-gui
make
```
## Release
If you do not want to build it in your computer, you can also download a built program and run it.

**ATTENTION**: Even using a binary release directly, you **must** have [openFPGALoader](https://github.com/trabucayre/openFPGALoader) installed and written in your `$PATH` variable