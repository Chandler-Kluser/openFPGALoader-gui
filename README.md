# openFPGALoader-gui
A small [gtk4](https://www.gtk.org/) GUI to flash your FPGA projects
<p align="center">
  <img src="media\window.png">
</p>

## Building
- Install [openFPGALoader](https://github.com/trabucayre/openFPGALoader) and have it available on your user `$PATH` variable
- Make sure you have `gcc`, `make`, `glib-2.0`, `pkg-config`, `vte-2.91-gtk4` and `gtk4` in your system, for Debian based systems:
```
sudo apt update
sudo apt install gcc make glib-2.0 pkg-config gtk4
```
- Download this repository, go to repository root folder and run `make` in your shell
```
git clone https://github.com/Chandler-Kluser/openFPGALoader-gui.git
cd openFPGALoader-gui
make
```
- Binary file will be at `bin` folder
## Release
If you do not want to build it in your computer, you can also download a built program and run it.
## Attention
openFPGALoader-gui just assembles the shell command and runs that in terminal. Even using a binary release directly, you **must** have [openFPGALoader](https://github.com/trabucayre/openFPGALoader) installed and written in your `$PATH` variable
## TO DOs
Only the option `Flash with shell` is fully functional. Notice that `Flash with GUI` option is not working properly, because:
- path parsing not supporting UTF-8 characters yet, using file paths with non UTF-8 charset can avoid this problem; and
- GUI Terminal (made with [VTE Terminal](https://github.com/GNOME/vte)) is not reading binaries with UTF-8 characters inside, depending on your FPGA model binary the problem cannot be avoided.