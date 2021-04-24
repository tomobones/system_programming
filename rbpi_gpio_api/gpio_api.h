#ifndef GPIO_API_H
#define GPIO_API_H

#define DIRECTION_IN "in"
#define DIRECTION_OUT "out"
#define VALUE_ON 1
#define VALUE_OFF 0

void gpio_init_pin(int pin);
void gpio_set_value(int pin, int value);
void gpio_set_direction(int pin, char* direction);
void gpio_cleanup(int pin);

#endif
