## UART send string project using versatilePB board with arm926ej-s.

\*\*Procedure Of This Project

- main.c file.
- uart.c & uart.h files
- I made static liberary from uart.c and uart.h which is can.a.
- Wrote startup.s file.
- Wrote linker_script.ld file.
- Compiled main.c.
- Assembeled startup.s.
- Linked linker_script.ld with main.o, startup.o and can.a object files.
- Got the final executable.elf file.
- Got the final executable.bin file.\*\*

### Tools Used With This Project:

- Arm Cross-toolchain.
- Qemu System Arm to run the executable on.

### Commands used with the tools:

`// Creation Of Static Liberary.
arm-none-eabi-gcc -c -mcpu=arm926ej-s -I . uart.c -o uart.o
arm-none-eabi-ar rcs can.a uart.o
// Compilation Process To Generate .elf file
arm-none-eabi-gcc -c -mcpu=arm926ej-s main.c -o main.o
arm-none-eabi-as -mcpu=arm926ej-s startup.s startup.o
arm-none-eabi-ld -T linker_script.ld startup.o main.c can.a -o executable.elf -Map=map_file
arm-none-eabi-objcopy -O binary executable.elf executable.bin
// Running Code On Qemu Simulator
qemu-system-arm -M versatilepb -m 128M -nographic -kernel executable.bin`

### Working Code Image: