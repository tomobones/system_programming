ifndef $(MSPGCCDIR)
	MSPGCCDIR=/home/tomo/.cache/yay/mspgcc-ti/src/msp430-gcc-support-files
endif
#paths
INCLUDES_DIRECTORY = $(MSPGCCDIR)/include

DEVICE = msp430fr5969

# compiler options
CC=msp430-elf-gcc

CFLAGS = -I . -I $(INCLUDES_DIRECTORY) -mmcu=$(DEVICE) -g -mhwmult=f5series
LFLAGS = -L . -L $(INCLUDES_DIRECTORY)

# mspdebug driver -- used for installation
DRIVER:= tilib

# Compiling
all: blink.elf blinktimer.elf

%.elf : %.c
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@


# Upload to board
install.%: %.elf
		mspdebug $(DRIVER) "prog $<" --allow-fw-update

clean:
	rm -f  *.o *.elf

