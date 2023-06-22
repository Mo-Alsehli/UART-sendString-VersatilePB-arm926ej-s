## UART send string project using versatilePB board with arm926ej-s.
![VersatilePB](https://github.com/Mo-Alsehli/UART-sendString-VersatilePB-arm926ej-s/assets/98949843/195ca245-b52b-4f06-95d1-e895067c8859)

**Procedure Of This Project**

- main.c file.
- uart.c & uart.h files
- I made static library from uart.c and uart.h which is can.a.
- Wrote startup.s file.
- Wrote linker_script.ld file.
- Compiled main.c.
- Assembled startup.s.
- Linked linker_script.ld with main.o, startup.o and can.a object files.
- Got the final executable.elf file.
- Got the final executable.bin file.

### Tools Used With This Project:

- Arm Cross-toolchain.
- Qemu System Arm to run the executable on.

### Commands used with the tools:
```
// Creation Of Static Liberary.
arm-none-eabi-gcc -c -mcpu=arm926ej-s -I . uart.c -o uart.o
arm-none-eabi-ar rcs can.a uart.o
// Compilation Process To Generate .elf file
arm-none-eabi-gcc -c -mcpu=arm926ej-s main.c -o main.o
arm-none-eabi-as -mcpu=arm926ej-s startup.s startup.o`
arm-none-eabi-ld -T linker_script.ld startup.o main.c can.a -o executable.elf -Map=map_file
arm-none-eabi-objcopy -O binary executable.elf executable.bin
// Running Code On Qemu Simulator
qemu-system-arm -M versatilepb -m 128M -nographic -kernel executable.bin
```
### Working Code Image:
![Working_code](https://github.com/Mo-Alsehli/UART-sendString-VersatilePB-arm926ej-s/assets/98949843/db957607-be2b-4af9-a8b3-3437722b9d5f)
