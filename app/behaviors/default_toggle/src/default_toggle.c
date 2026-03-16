#include <zephyr.h>
#include <device.h>
#include <sys/printk.h>
#include <zmk/behavior.h>
#include <zmk/keymap.h>

static int default_toggle_binding_pressed(struct zmk_behavior_binding *binding,
                                          struct zmk_behavior_binding_event event) {
    ARG_UNUSED(binding);
    ARG_UNUSED(event);

    /* Read current default layer */
    uint8_t cur = zmk_keymap_layer_default_get();

    /* Toggle between layer 0 and layer 4 */
    if (cur == 0) {
        zmk_keymap_layer_default_set(4);
    } else {
        zmk_keymap_layer_default_set(0);
    }

    return ZMK_BEHAVIOR_OPAQUE;
}

static int default_toggle_binding_released(struct zmk_behavior_binding *binding,
                                           struct zmk_behavior_binding_event event) {
    ARG_UNUSED(binding);
    ARG_UNUSED(event);
    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct zmk_behavior_driver_api default_toggle_driver_api = {
    .binding_pressed = default_toggle_binding_pressed,
    .binding_released = default_toggle_binding_released,
};

ZMK_BEHAVIOR_DRIVER(default_toggle, default_toggle_driver_api);
