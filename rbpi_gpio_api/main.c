#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdarg.h>

#include "gpio_api.h"
#include "err_exit.h"

int pin = 14;

void sig_handler(int sig) {
    gpio_cleanup(14);
    err_exit("Signal %d caught.", sig);
}

int main(void) {
    signal(SIGINT, sig_handler);

    gpio_init_pin(pin);
    gpio_set_direction(pin, DIRECTION_OUT);
    gpio_set_value(pin, VALUE_OFF);

    while(1) {
        gpio_set_value(pin, VALUE_ON);
        usleep(50000);
        gpio_set_value(pin, VALUE_OFF);
        usleep(50000);
    }

    return 0;
}
