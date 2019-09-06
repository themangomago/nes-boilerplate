@echo off
cc65 -Ors hello.c --add-source
ca65 neslib/crt0.s
ca65 hello.s -g

ld65 -C nrom.cfg -o hello.nes neslib/crt0.o hello.o nes.lib -Ln debug.txt
