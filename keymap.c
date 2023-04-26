// An Ergodox EZ keymap meant to be used with a bépo layout (FR ergonomic
// layout, dvorak style). The overall design is slightly inspired by the
// TypeMatrix keyboard. Switching between a TypeMatrix and an Ergodox with this
// layout should be relatively easy.
//
// See the README.md file for an image of this keymap.

#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

// The layers that we are defining for this keyboards.
#define BASE 0
#define FN 1
#define MOUSE 2
#define NUMS 3
#define SWAP 4
#define SYSLEDS 5

// The Tap Dance identifiers, used in the TD keycode and tap_dance_actions array.
#define TAP_MACRO 0

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO

// Some combined keys (one normal keycode when tapped and one modifier or layer
// toggle when held).
#define ESC_FN LT(FN, KC_ESC)         // ESC key and FN layer toggle.
#define M_RSFT MT(MOD_RSFT, BP_M)     // 'M' key and right shift modifier.
#define W_RCTL MT(MOD_RCTL, BP_W)     // 'W' key and right control modifier.
#define SPC_RALT MT(MOD_RALT, KC_SPC) // SPACE key and right alt modifier.
#define PERC_FN LT(FN, BP_PERC)       // '%' key and FN layer toggle.

// The most portable copy/paste keys (windows (mostly), linux, and some terminal emulators).
#define MK_CUT LSFT(KC_DEL)   // shift + delete
#define MK_COPY LCTL(KC_INS)  // ctrl + insert
#define MK_PASTE LSFT(KC_INS) // shift + insert

// Layers
#define BASE 0      // default layer
#define GAMING 1    // Gaming layer, without the  FNENTER, french letters, and with a few modifications
#define FNSPACE 2   // fn space layer : function and navigation
#define FNAV 3      // function / navigation keys
#define NUM 4       // numeric keypad keys
#define QWER 7      // Qwerty compatibilty layer
#define SQWER 8     // Q Shifted
#define AQWER 9     // Q alted
#define QFNSPACE 10 // fn space layer : function and navigation

/*
#define ESCM 6 //ESC and reset mods and keys
#define MSE 10
#define VNC 17
#define CTLX 18
#define COPL 19 //Copy the line
#define CAS 20 //Control-alt-suppr
#define ALTTAB 21 //Alt-tabbing macro
#define ENT_RESET 22 //Alt-tabbing macro
*/

// Macros
enum
{
  // SAFE_RANGE must be used to tag the first element of the enum.
  // DYNAMIC_MACRO_RANGE must always be the last element of the enum if other
  // values are added (as its value is used to create a couple of other keycodes
  // after it).
  DYNAMIC_MACRO_RANGE = SAFE_RANGE,
  ESCM, // ESC and reset mods and keys
  MSE,
  VNC,
  CTLX,
  COPL,     // Copy the line
  CAS,      // Control-alt-suppr
  ALTTAB,   // Alt-tabbing macro
  ENT_RESET // Alt-tabbing macro
};

// This file must be included after DYNAMIC_MACRO_RANGE is defined...
#include "dynamic_macro.h"

// In Layer declaration, add tap dance item in place of a key code
// Tap Dance Declarations
enum
{
  TD_QUOTF1 = 0,
  TD_ZF12 = 12
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ergodox(
        // Left hand
        BP_DLR, BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, KC_DEL,
        KC_TAB, BP_B, BP_EACU, BP_P, BP_O, BP_EGRV, KC_BSPC,
        KC_ESC, BP_A, BP_U, BP_I, BP_E, BP_COMM,
        KC_LCTL, BP_AGRV, BP_Y, BP_X, BP_DOT, BP_K, LALT(KC_BSPC),
        LGUI(BP_X), LGUI(BP_C), LGUI(BP_V), KC_LGUI, KC_LALT,
        TG(FNSPACE), TG(QWER),
        TG(GAMING),
        KC_ENTER, KC_LSHIFT, LCTL(LALT(BP_B)),
        // Right hand
        BP_PERC, BP_AT, BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL,
        KC_CAPSLOCK, BP_DCIR, BP_V, BP_D, BP_L, BP_J, BP_Z,
        BP_C, BP_T, BP_S, BP_R, BP_N, BP_M,
        BP_CCED, BP_QUOT, BP_Q, BP_G, BP_H, BP_F, BP_W,
        KC_RALT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
        KC_NUMLOCK, KC_INS,
        KC_VOLU,
        KC_VOLD, KC_RSHIFT, LT(FNSPACE, KC_SPACE)),

    // FNSpace layer with some cool stuff.
    /*==================================================================================================================================================================================================================================================================================================================================================================================================================================================
     */
    [FNSPACE] = LAYOUT_ergodox(
        // Left hand
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
        ALTTAB, KC_SPC, COPL, LSFT(KC_INS), G(S(BP_X)), KC_E, KC_VOLU,
        KC_F18, LGUI(KC_LEFT), LALT(KC_LEFT), LALT(KC_RIGHT), LGUI(KC_RIGHT), KC_COMMA,
        KC_TRNS, KC_TRNS, S(G(BP_W)), LGUI(BP_W), KC_DOT, KC_K, KC_VOLD,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        ENT_RESET, KC_NO, MO(FNAV),

        // Right hand
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_CAPSLOCK, CAS, LGUI(KC_LEFT), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LALT(KC_RIGHT), KC_F12,
        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, LGUI(BP_T), KC_F19,
        KC_NUMLOCK, KC_QUOT, KC_PGDOWN, KC_PGUP, LCTL(BP_R), KC_F, KC_C,
        KC_END, KC_HOME, KC_RGUI, KC_PSCREEN, KC_PAUSE,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        MO(FNAV), KC_NO, KC_TRNS),

};

// Whether the macro 1 is currently being recorded.
static bool is_macro1_recording = false;

// The current set of active layers (as a bitmask).
// There is a global 'layer_state' variable but it is set after the call
// to layer_state_set_user().
static uint32_t current_layer_state = 0;
layer_state_t layer_state_set_user(layer_state_t state);

// Method called at the end of the tap dance on the TAP_MACRO key. That key is
// used to start recording a macro (double tap or more), to stop recording (any
// number of tap), or to play the recorded macro (1 tap).
void macro_tapdance_fn(qk_tap_dance_state_t *state, void *user_data)
{
  uint16_t keycode;
  keyrecord_t record;
  dprintf("macro_tap_dance_fn %d\n", state->count);
  if (is_macro1_recording)
  {
    keycode = DYN_REC_STOP;
    is_macro1_recording = false;
    layer_state_set_user(current_layer_state);
  }
  else if (state->count == 1)
  {
    keycode = DYN_MACRO_PLAY1;
  }
  else
  {
    keycode = DYN_REC_START1;
    is_macro1_recording = true;
    layer_state_set_user(current_layer_state);
  }

  record.event.pressed = true;
  process_record_dynamic_macro(keycode, &record);
  record.event.pressed = false;
  process_record_dynamic_macro(keycode, &record);
}

// The definition of the tap dance actions:
qk_tap_dance_action_t tap_dance_actions[] = {
    // This Tap dance plays the macro 1 on TAP and records it on double tap.
    [TAP_MACRO] = ACTION_TAP_DANCE_FN(macro_tapdance_fn),
    [TD_QUOTF1] = ACTION_TAP_DANCE_DOUBLE(BP_DQUO, KC_F1),
    [TD_ZF12] = ACTION_TAP_DANCE_DOUBLE(BP_Z, KC_F12),
};

// Runs for each key down or up event.
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (keycode != TD(TAP_MACRO))
  {
    // That key is processed by the macro_tapdance_fn. Not ignoring it here is
    // mostly a no-op except that it is recorded in the macros (and uses space).
    // We can't just return false when the key is a tap dance, because
    // process_record_user, is called before the tap dance processing (and
    // returning false would eat the tap dance).
    if (!process_record_dynamic_macro(keycode, record))
    {
      return false;
    }
  }

  return true; // Let QMK send the enter press/release events
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void)
{
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void){

};

// The state of the LEDs requested by the system, as a bitmask.
static uint8_t sys_led_state = 0;

// Use these masks to read the system LEDs state.
static const uint8_t sys_led_mask_num_lock = 1 << USB_LED_NUM_LOCK;
static const uint8_t sys_led_mask_caps_lock = 1 << USB_LED_CAPS_LOCK;
static const uint8_t sys_led_mask_scroll_lock = 1 << USB_LED_SCROLL_LOCK;

// Value to use to switch LEDs on. The default value of 255 is far too bright.
static const uint8_t max_led_value = 20;

// Whether the given layer (one of the constant defined at the top) is active.
#define LAYER_ON(layer) (current_layer_state & (1 << layer))

void led_1_on(void)
{
  ergodox_right_led_1_on();
  ergodox_right_led_1_set(max_led_value);
}

void led_2_on(void)
{
  ergodox_right_led_2_on();
  ergodox_right_led_2_set(max_led_value);
}

void led_3_on(void)
{
  ergodox_right_led_3_on();
  ergodox_right_led_3_set(max_led_value);
}

void led_1_off(void)
{
  ergodox_right_led_1_off();
}

void led_2_off(void)
{
  ergodox_right_led_2_off();
}

void led_3_off(void)
{
  ergodox_right_led_3_off();
}

// Called when the computer wants to change the state of the keyboard LEDs.
void led_set_user(uint8_t usb_led)
{
  sys_led_state = usb_led;
  if (LAYER_ON(SYSLEDS))
  {
    if (sys_led_state & sys_led_mask_caps_lock)
    {
      led_1_on();
    }
    else
    {
      led_1_off();
    }
    if (sys_led_state & sys_led_mask_num_lock)
    {
      led_2_on();
    }
    else
    {
      led_2_off();
    }
    if (sys_led_state & sys_led_mask_scroll_lock)
    {
      led_3_on();
    }
    else
    {
      led_3_off();
    }
  }
}

layer_state_t layer_state_set_user(layer_state_t state)
{
  current_layer_state = state;
  swap_hands = LAYER_ON(SWAP);

  if (is_macro1_recording)
  {
    led_1_on();
    led_2_on();
    led_3_on();
    return state;
  }

  if (LAYER_ON(SYSLEDS))
  {
    led_set_user(sys_led_state);
    return state;
  }

  if (LAYER_ON(FN))
  {
    led_1_on();
  }
  else
  {
    led_1_off();
  }

  if (LAYER_ON(NUMS))
  {
    led_2_on();
  }
  else
  {
    led_2_off();
  }

  if (LAYER_ON(MOUSE))
  {
    led_3_on();
  }
  else
  {
    led_3_off();
  }

  return state;
};
