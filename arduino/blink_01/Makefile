# compiler options
CC=avr-gcc
CFLAGS= -Os -DF_CPU=16000000UL -mmcu=atmega328p

# compiling
all: blink.out

# detect what port my arduino is on.
# might have to change this if you have two connected or are not using macOS

#USBPORT=/dev/tty.usbmodem14401
#USBPORT:=$(shell ls /dev/tty.usbmodem*)
#USBPORT=/dev/bus/usb/001/007
USBPORT=/dev/ttyACM0
#USBPORT=/dev/ttyACM0

%.out: %.c
	$(CC) $(CFLAGS) $< -o $@

%.hex: %.out
	avr-objcopy -O ihex -R .eeprom $< $@

# upload to the board
install.%: %.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P $(USBPORT) -b 115200 -U flash:w:$<

clean:
	rm -f *.hex *.out
