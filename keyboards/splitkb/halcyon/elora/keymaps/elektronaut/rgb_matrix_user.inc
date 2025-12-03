RGB_MATRIX_EFFECT(home_row_indicators)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static bool home_row_indicators(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t home_row_leds[] = {20, 21, 22, 23, 57, 58, 59, 60};

    hsv_t hsv = rgb_matrix_get_hsv();
    rgb_t rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, RGB_OFF);
    }

    for (uint8_t i = 0; i < sizeof(home_row_leds); i++) {
        rgb_matrix_set_color(home_row_leds[i], rgb.r, rgb.g, rgb.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
