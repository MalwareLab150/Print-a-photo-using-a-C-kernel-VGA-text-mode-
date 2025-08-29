Print a photo using a C kernel (VGA text mode).

First step

put your photo in the same folder (TEST.png).

Second step

open your terminal and type "python convert.py".

Third step
Open the wsl and run these commands.

sudo apt install gcc
sudo apt install nasm
sudo apt install qemu-system-i386
sudo apt installl make

Then run
make .

(each time you will have to delete the Booloader_end, kernel_asm, kernel_c_ folders).

It's still in beta and the colors are often distorted.
