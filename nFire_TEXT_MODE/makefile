AS = nasm
CC = gcc
LD = ld

CFLAGS = -ffreestanding -m32 -nostdlib
LDFLAGS = -m elf_i386 -T linker.ld
ASMFLAGS = -f elf32

KERNEL_C = Starter.c
KERNEL_ASM = kernel.asm

KERNEL_OBJ_C_DIR = kernel_c_
KERNEL_OBJ_ASM_DIR = kernel_asm
BOOTLOADER_DIR = Booloader_end

KERNEL_OBJ_C = $(KERNEL_OBJ_C_DIR)/kernel_c.o
KERNEL_OBJ_ASM = $(KERNEL_OBJ_ASM_DIR)/kernel_asm.o
KERNEL_BIN = $(KERNEL_OBJ_C_DIR)/kernel.bin
BOOTLOADER_IMG = $(BOOTLOADER_DIR)/Bootloader49.img

GREEN = \033[32m
RESET = \033[0m
YELLOW = \033[33m

all: dirs $(BOOTLOADER_IMG) run

dirs:
	@mkdir -p $(KERNEL_OBJ_C_DIR) $(KERNEL_OBJ_ASM_DIR) $(BOOTLOADER_DIR)

$(KERNEL_OBJ_ASM): $(KERNEL_ASM)
	@echo "$(YELLOW)Compilando $(KERNEL_ASM)...$(RESET)"
	$(AS) $(ASMFLAGS) $(KERNEL_ASM) -o $(KERNEL_OBJ_ASM)
	@if [ $$? -eq 0 ]; then echo "$(GREEN)Compilazione $(KERNEL_ASM) riuscita.$(RESET)"; fi

$(KERNEL_OBJ_C): $(KERNEL_C)
	@echo "$(YELLOW)Compilando $(KERNEL_C)...$(RESET)"
	$(CC) $(CFLAGS) -c $(KERNEL_C) -o $(KERNEL_OBJ_C)
	@if [ $$? -eq 0 ]; then echo "$(GREEN)Compilazione $(KERNEL_C) riuscita.$(RESET)"; fi

$(KERNEL_BIN): $(KERNEL_OBJ_ASM) $(KERNEL_OBJ_C)
	@echo "$(YELLOW)Linkando $(KERNEL_OBJ_ASM) e $(KERNEL_OBJ_C) per creare $(KERNEL_BIN)...$(RESET)"
	$(LD) $(LDFLAGS) -o $(KERNEL_BIN) $(KERNEL_OBJ_ASM) $(KERNEL_OBJ_C)
	@if [ $$? -eq 0 ]; then echo "$(GREEN)Creazione del kernel $(KERNEL_BIN) riuscita.$(RESET)"; fi

$(BOOTLOADER_IMG): $(KERNEL_BIN) elf_loader.bin
	@echo "$(YELLOW)Creando immagine $(BOOTLOADER_IMG)...$(RESET)"
	cat elf_loader.bin $(KERNEL_BIN) > $(BOOTLOADER_IMG)

run: $(BOOTLOADER_IMG)
	@echo "$(YELLOW)Avviando $(BOOTLOADER_IMG) su QEMU...$(RESET)"
	clear
	qemu-system-i386 -hda $(BOOTLOADER_IMG) 

