#include "mbed.h"

PwmOut PWM1(D6);
const double pi = 3.141592653589793238462;
const double offset = 7.5f;

int main() {
    int i = 0;
    double width = 0.0;
    double rads = 0.0;
    while (1) {
        PWM1.period_ms(15);

        rads = (pi * i) / 180.0f;
        width = ((offset * (cos(rads + pi))) + offset);
        // printf("%f %d\n\r", width, i);
        PWM1.pulsewidth_ms(width);
        // printf("%f\n\r", PWM1.read());
        ThisThread::sleep_for(15ms);
        i = (i + 1) % 360;
    }
}
