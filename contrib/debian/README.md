
Debian
====================
This directory contains files used to package clicoind/clicoin-qt
for Debian-based Linux systems. If you compile clicoind/clicoin-qt yourself, there are some useful files here.

## clicoin: URI support ##


clicoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install clicoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your clicoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/clicoin128.png` to `/usr/share/pixmaps`

clicoin-qt.protocol (KDE)

