#include <zephyr/kernel.h>
#include <zephyr/drivers/pwm.h>
#include "motor.h"

#define ANGLE 30

static const struct pwm_dt_spec pwm_servo = PWM_DT_SPEC_GET(DT_NODELABEL(servo));
static const uint32_t min_pulse = DT_PROP(DT_NODELABEL(servo), min_pulse);
static const uint32_t max_pulse = DT_PROP(DT_NODELABEL(servo), max_pulse);

void turn_on_switch() {
    if (!pwm_is_ready_dt(&pwm_servo)) {
		printk("Error: PWM device %s is not ready\n", pwm_servo.dev->name);
		return;
	}

    uint32_t pulse_width = min_pulse + ((max_pulse - min_pulse) * ANGLE) / 180;

    // move forward
    if (pwm_set_pulse_dt(&pwm_servo, pulse_width) < 0) {
        printk("Error %d: failed to set pulse width\n");
        return 0;
    }
    k_msleep(500);
    // move back
    if (pwm_set_pulse_dt(&pwm_servo, min_pulse) < 0) {
        printk("Error: failed to set pulse width to 0 degrees\n");
    }
    k_msleep(500); 
};

void turn_off_switch() {
        if (!pwm_is_ready_dt(&pwm_servo)) {
		printk("Error: PWM device %s is not ready\n", pwm_servo.dev->name);
		return;
	}

    uint32_t pulse_width = min_pulse + ((max_pulse - min_pulse) * ANGLE) / 180;

    // move forward
    if (pwm_set_pulse_dt(&pwm_servo, pulse_width) < 0) {
        printk("Error %d: failed to set pulse width\n");
        return 0;
    }
    k_msleep(500);
    // move back
    if (pwm_set_pulse_dt(&pwm_servo, min_pulse) < 0) {
        printk("Error: failed to set pulse width to 0 degrees\n");
    }
    k_msleep(500); 
};
