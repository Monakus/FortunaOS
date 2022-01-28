# FortunaOS

An operating system made based on:
* [OSDev] (https://wiki.osdev.org/Expanded_Main_Page)
* [The little book about OS development] (https://littleosbook.github.io/)
* [JamesM's kernel development tutorials] (http://www.jamesmolloy.co.uk/tutorial_html/)

# General info
FortunaOS is a simple operating system made as an university project.
Unfortunately I couldn't get multitasking to work so the system is incomplete.
Still, it has got:
* [x] Serial ports driver
* [x] VGA driver
* [x] Paging
* [x] Interrupts
* [x] Dynamic memory allocation
* [x] Heap


# Technologies
The project was created using:
* GCC
* NASM
* Makefile

# Setup
I've emulated the system using [Bochs] https://bochs.sourceforge.io/

To compile and run the project use:
```shell
$ make run
```