#include QMK_KEYBOARD_H

enum my_keycodes {
  LYR1 = SAFE_RANGE,
  LYR2,
  LYR3,
  LYR0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LYR1, KC_2, KC_3,
        KC_4, KC_5, KC_6,
        KC_7, KC_8, KC_9
    ),
    [1] = LAYOUT(
        LYR2, KC_2, KC_3,
        KC_4, KC_5, KC_6,
        KC_7, KC_8, KC_9
    ),
    [2] = LAYOUT(
        LYR3, KC_2, KC_3,
        KC_4, KC_5, KC_6,
        KC_7, KC_8, KC_9
    ),
    [3] = LAYOUT(
        LYR0, KC_2, KC_3,
        KC_4, KC_5, KC_6,
        KC_7, KC_8, KC_9
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D)},
    [2] =   { ENCODER_CCW_CW(KC_WH_L, KC_WH_R)},
    [3] =   { ENCODER_CCW_CW(LCTL(KC_MINUS), LCTL(KC_EQUAL))},
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LYR1:
      if (record->event.pressed) {
            register_code(KC_F13);  // press the F13 key
            layer_on(1);          // turn on the layer 1
      } else {
            unregister_code(KC_F13);  // release the F13 key
      }
      return false; // Skip all further processing of this key
    case LYR2:
      if (record->event.pressed) {
            register_code(KC_F14);  // press the F13 key
            layer_on(2);          // turn on the layer 2
      } else {
            unregister_code(KC_F14);  // release the F13 key
      }
      return false; // Skip all further processing of this key
    case LYR3:
      if (record->event.pressed) {
            register_code(KC_F15);  // press the F13 key
            layer_on(3);          // turn on the layer 3
      } else {
            unregister_code(KC_F15);  // release the F13 key
      }
      return false; // Skip all further processing of this key
    case LYR0:
      if (record->event.pressed) {
            register_code(KC_F16);  // press the F13 key
            layer_on(0);          // turn on the layer 0
            layer_off(1);           // turn off the _FN layer
            layer_off(2);           // turn off the _FN layer
            layer_off(3);           // turn off the _FN layer
      } else {
            unregister_code(KC_F16);  // release the F13 key
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
