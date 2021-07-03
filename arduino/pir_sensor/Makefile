ACC=avr-gcc
ACC_FLAGS=-mmcu=atmega328p -DF_CPU=16000000UL -Os

AOC=avr-objcopy
AOC_FLAGS=-O ihex

ASZ=avr-size
ASZ_FLAGS=-C

ADU=avrdude
#ADU_FLAGS=-V -F
ADU_MCU=-p m328p
ADU_PROG=-c arduino
#ADU_SPEED=-b 115200
ADU_TARGET=-Uflash:w:$^
ADU_PORT=-P/dev/ttyACM0

.PHONY:
default: upload

.PHONY:
build: pir.hex

upload: pir.hex
	$(ADU) $(ADU_FLAGS) $(ADU_MCU) $(ADU_PROG) $(ADU_SPEED) $(ADU_TARGET) $(ADU_PORT)
	touch $@ #make 'upload' to actual file, upload only for changes

pir.hex: pir.elf
	$(AOC) $(AOC_FLAGS) $^ $@

pir.elf: pir.c
	$(ACC) $(ACC_FLAGS) $^ -o $@
	$(ASZ) $(ASZ_FLAGS) $@

.PHONY:
clean:
	rm -f *.hex
	rm -f *.elf
	rm -f *.out
	rm -f upload

