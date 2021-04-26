#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "gpio_api.h"
#include "err_exit.h"

#define BUFFER_SIZE 256

void gpio_init_pin(int pin) {
    FILE *fp_export = NULL;
    char file_path[BUFFER_SIZE] = "/sys/class/gpio/export";
    if (!(fp_export = fopen(file_path, "w")))
        err_exit("init_pin: Couldn't open file '%s'.", file_path);
    fprintf(fp_export, "%d", pin);
    fclose(fp_export);
}

void gpio_set_direction(int pin, char* direction) {
    FILE *fp_direction = NULL;
    char file_path[BUFFER_SIZE];
    sprintf(file_path, "/sys/class/gpio/gpio%d/direction", pin);
    if (!(fp_direction = fopen(file_path, "w")))
        err_exit("set_direction: Couldn't open file '%s'.", file_path);
    fprintf(fp_direction, direction);
    fclose(fp_direction);
}

void gpio_set_value(int pin, int value) {
    FILE *fp_value = NULL;
    char file_path[BUFFER_SIZE];
    sprintf(file_path, "/sys/class/gpio/gpio%d/value", pin);
    if (!(fp_value = fopen(file_path, "w")))
        err_exit("set_value: Couldn't open file '%s'.", file_path);

    fprintf(fp_value, "%d", value);
    fclose(fp_value);
}

void gpio_get_value(int pin, char* buffer) {
    FILE *fp_value = NULL;
    char file_path[BUFFER_SIZE];
    int buffer_length = 0;
    int buffer_max = sizeof(buffer);

    sprintf(file_path, "/sys/class/gpio/gpio%d/value", pin);
    if (!(fp_value = fopen(file_path, "r")))
        err_exit("get_value: Couldn't open file '%s'.", file_path);

    while (!feof(fp_value) || buffer_length < buffer_max)
        buffer[buffer_length++] = fgetc(fp_value);

    buffer[buffer_length] = '\0';
    fclose(fp_value);
}

void gpio_cleanup(int pin) {
    gpio_set_value(pin, VALUE_OFF);
}
