# openFPGALoader-gui
A small [gtk4](https://www.gtk.org/) GUI to flash your FPGA projects
<p align="center">
  <img src="media\window.png">
</p>

## Building
- Install [openFPGALoader](https://github.com/trabucayre/openFPGALoader) and have it available on your user `$PATH` variable
- Make sure you have `gcc`, `make`, `glib-2.0`, `pkg-config` and `gtk4` in your system
### Debian based systems
```
sudo apt update
sudo apt install gcc make glib-2.0 pkg-config gtk4
```
### Arch based systems
```
sudo pacman -Syyu
sudo pacman -S gcc make glib-2.0 pkg-config gtk4
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