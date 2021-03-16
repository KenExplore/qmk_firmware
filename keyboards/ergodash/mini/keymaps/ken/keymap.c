#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_L1 SFT_T(KC_UP)
// #define KC_L2 LT(_LOWER, KC_LANG2)
// #define KC_L3 LT(_RAISE, KC_LANG1)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ESC |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  GUI |   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   :  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  TAB |                    | Space|   N  |   M  |   ,  |   .  |   '  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      | Space| Ctrl |||||||| Lower|  TAB |      ||||||||      | Space| Raise||||||||  Alt | Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC ,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  _______,                       _______,   KC_Y,    KC_U,    KC_I,   KC_O,     KC_P, KC_BSPC, \
    KC_LGUI,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  _______,                       _______,   KC_H,    KC_J,    KC_K,   KC_L,  KC_COLN, KC_ENT , \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_TAB ,                       KC_SPC ,   KC_N,    KC_M, KC_COMM, KC_DOT,  KC_QUOT, KC_L1  , \
    _______, _______,  KC_SPC, KC_LCTL,            LOWER,  KC_TAB , _______,     _______, KC_SPC ,  RAISE,          KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ESC |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  GUI |      |      |      |      |      |      |                    |      | Left | Down |  Up  | Right|      | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      | TAB  |                    | Space|      |      |      |      |      | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      | Ctrl |||||||| Lower| TAB  |      ||||||||      | Space| Raise||||||||  Alt |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_ESC ,   KC_1 ,   KC_2 ,    KC_3,    KC_4,    KC_5, _______,                        _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
    KC_LGUI, _______, _______, _______, _______, _______, _______,                        _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, KC_ENT , \
    KC_LSFT, _______, _______, _______, _______, _______, KC_TAB ,                        KC_SPC , _______, _______, _______, _______, _______, KC_RSFT, \
    _______, _______, _______, KC_LCTL,            LOWER, KC_TAB , _______,      _______, KC_SPC , RAISE,            KC_RALT, _______, _______, _______  \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |  ESC |   !  |   @  |   #  |   $  |   %  |      |                    |      |   *  |   <  |   >  |   (  |   )  | Bksp |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |  GUI |   ?  |   ^  |   &  |      |      |      |                    |      |   -  |   =  |   [  |   ]  |   ;  |   /  |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Shift|   `  |   ~  |   |  |      |      |  TAB |                    | Space|   +  |   _  |   {  |   }  |   "  |   \  |
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * |      |      |      | Ctrl |||||||| Lower|  TAB |      ||||||||      | Space| Raise||||||||  Alt |      |      |      |
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_ESC , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                       _______, KC_ASTR, KC_LT  , KC_GT  , KC_LPRN, KC_RPRN, KC_BSPC, \
    KC_LGUI, KC_QUES, KC_CIRC, KC_AMPR, _______, _______, _______,                       _______, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_SCLN, KC_SLSH, \
    KC_LSFT, KC_GRV , KC_TILD, KC_PIPE, _______, _______,  KC_TAB,                       KC_SPC , KC_PLUS, KC_UNDS, KC_LCBR, KC_RCBR, KC_DQUO, KC_BSLS, \
    _______, _______, _______, KC_LCTL,             LOWER, KC_TAB, _______,     _______, KC_SPC , RAISE,            KC_RALT, _______, _______, _______  \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|      |      |      |      |      |                    |      | Mute | Vol- | Vol+ |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | Play | Prev | Next |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      | Bri- | Bri+ |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , _______, _______, _______, _______,_______,                       _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, KC_MPLY, KC_MRWD, KC_MFFD, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, KC_BRID, KC_BRIU, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};


// ref: https://okapies.hateblo.jp/entry/2019/02/02/133953
static bool lower_pressed = false;
static bool raise_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
          
        if (lower_pressed) {
          register_code(KC_LANG2);
          unregister_code(KC_LANG2);
        }
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
          
        if (raise_pressed) {
          register_code(KC_LANG1);
          unregister_code(KC_LANG1);
        }
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        // reset the flag
        lower_pressed = false;
        raise_pressed = false;
      }
      break;
  }
  return true;
}
