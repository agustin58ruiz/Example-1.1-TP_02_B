#include "mbed.h"
#include "arm_book_lib.h"
#include "hal/gpio_api.h"

int main()
{

    gpio_t gas_detector;
    gpio_t alarm_led;

    gpio_init_in(&gas_detector, D2);
    //DigitalIn gasDetector(D2);

    gpio_init_out(&alarm_led, LED1);
    
    //DigitalOut alarmLed(LED1);

    gpio_mode(&gas_detector, PullDown);
    //gasDetector.mode(PullDown);

    //alarmLed = OFF;
    gpio_write(&alarm_led, OFF);

    while (true) {

        
        if ( gpio_read(&gas_detector) == ON ) {
            gpio_write(&alarm_led, ON);
            //alarmLed = ON;
        }
        
        if ( gpio_read(&gas_detector) == OFF ) {
            gpio_write(&alarm_led, OFF);
            //alarmLed = OFF;
        }
    }
}