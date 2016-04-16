#include "planck.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _FN 1
#define _LW 2
#define _RS 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty Swe shifted
 * ,-----------------------------------------------------------------------------------.
 * | Bksp |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   .  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  FN  | Mod4 | Alt  |Lower |    Space    |Raise |AltGr | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QW] = {
  {KC_BSPC,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,        KC_LBRC},
  {KC_TAB,   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,     KC_QUOT},
  {KC_LSFT,  KC_DOT,   KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_UP,       KC_ENT },
  {KC_LCTL,  MO(_FN),  KC_LGUI, KC_LALT, MO(_LW), KC_SPC,   KC_SPC,  MO(_RS), KC_RALT, KC_LEFT,  KC_DOWN,     KC_RIGHT}
},
/* Function layer
 * ,-----------------------------------------------------------------------------------.
 * |BkLght|   F  |      |      |      |      |MBtn1 | MUp  |MBtn2 | MWUp |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |MLeft |MDown |MRight| MWDn |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      | PGUP |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  FN  | Mod4 | Alt  |Lower |    Space    |Raise |AltGr | Home | PGDN | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = {
  {BL_STEP,  KC_F,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,  XXXXXXX,     XXXXXXX},
  {XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,  XXXXXXX,     XXXXXXX},
  {KC_LSFT,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_PGUP,     XXXXXXX},
  {KC_LCTL,  MO(_FN),  KC_LGUI, KC_LALT, MO(_LW), KC_SPC,   KC_SPC,  MO(_RS), KC_RALT, KC_HOME,  KC_PGDN,     KC_END}
},
/* Raised
 * ,-----------------------------------------------------------------------------------.
 * | Bksp |   R  |      |      |      |   +  |   7  |   8  |   9  |   -  |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |      |      |      |   '  |   4  |   5  |   6  |   ´  |   `  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   <  |      |      |      |   0  |   1  |   2  |   3  |   ¨  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Mod4 | Alt  |      |             |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RS] = {
  {KC_BSPC,  KC_R,     XXXXXXX, XXXXXXX, XXXXXXX, KC_MINUS, KC_7,    KC_8,    KC_9,    KC_SLSH,  XXXXXXX,     KC_DEL},
  {KC_ESC,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_NUHS,  KC_4,    KC_5,    KC_6,    KC_EQL,   KC_PLUS,     XXXXXXX},
  {KC_LSFT,  KC_NUBS,  XXXXXXX, XXXXXXX, XXXXXXX, KC_0,     KC_1,    KC_2,    KC_3,    KC_RBRC,  XXXXXXX,     XXXXXXX},
  {KC_LCTL,  XXXXXXX,  KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX,  XXXXXXX, MO(_RS), XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX}
},
/* Lowered
 * ,-----------------------------------------------------------------------------------.
 * | Bksp |   L  |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |RESET |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |ScrLck|      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |  F9  |  F10 |  F11 |  F12 |      |Qwerty|  FN  |      |VolUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Mod4 | Alt  |Lower |             |      |PlNxt | Mute |VolDn | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LW] = {
  {KC_BSPC,  KC_L,     KC_F1,    KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,     RESET},
  {KC_SLCK,  XXXXXXX,  KC_F5,    KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX},
  {KC_LSFT,  XXXXXXX,  KC_F9,    KC_F10,  KC_F11,  KC_F12,  XXXXXXX, DF(_QW), DF(_FN), XXXXXXX,  KC__VOLUP,   XXXXXXX},
  {KC_LCTL,  XXXXXXX,  KC_LGUI,  KC_LALT, MO(_LW), XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT, KC__MUTE, KC__VOLDOWN, KC_MPLY}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this  function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
	break;
      }
    return MACRO_NONE;
};
