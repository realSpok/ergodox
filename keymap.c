// vim: tabstop=8 ft=cpp: 

#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_bepo.h"

#define BASE 0 // default layer
#define GAMING 1 //Gaming layer, without the  FNENTER, french letters, and with a few modifications
#define FNSPACE 2 // fn space layer : function and navigation
#define FNAV 3 // function / navigation keys
#define NUM 4 // numeric keypad keys

#define QWER 7 //Qwerty compatibilty layer
#define SQWER 8 //Q Shifted
#define AQWER 9 //Q alted
#define QFNSPACE 10 // fn space layer : function and navigation

#define KP_00 4 
#define CA_Fx 5
#define NT 12

#define E 13
#define EM 14

#define AN 15
#define AM 16

#define ESCM 6 //ESC and reset mods and keys
#define MSE 10
#define VNC 17
#define CTLX 18
#define COPL 19 //Copy the line 
#define CAS 20 //Control-alt-suppr
#define ALTTAB 21 //Alt-tabbing macro
#define ENT_RESET 22 //Alt-tabbing macro



/*
#undef KC_RALT
#define KC_RALT LCTL(KC_LALT) 
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
// Left hand
BP_DOLLAR,	BP_DQOT,	BP_LGIL,	BP_RGIL,	BP_LPRN,	BP_RPRN,	KC_DEL,
KC_TAB,		BP_B,   	BP_E_ACUTE,	BP_P,		BP_O,		BP_E_GRAVE,	KC_BSPC,
M(ESCM),	BP_A,		BP_U,		BP_I,		BP_E,		BP_COMMA,
KC_LCTL,	BP_A_GRAVE,	BP_Y,		BP_X,		BP_DOT,		BP_K,		LCTL(KC_BSPC),
M(CTLX),	LCTL(BP_C),	LCTL(BP_V),	KC_LGUI,	KC_LALT,
														TG(FNSPACE),	TG(QWER),
																TG(GAMING),
												KC_ENTER, 	KC_LSHIFT,	LCTL(LALT(BP_B)),
// Right hand
				BP_PERCENT,	BP_AT,		BP_PLUS,	BP_MINUS,	BP_SLASH,	BP_ASTR,	BP_EQUAL,
				KC_CAPSLOCK,	BP_DCRC,	BP_V,		BP_D,		BP_L,		BP_J,		BP_Z,
						BP_C,		BP_T,		BP_S,		BP_R,		BP_N,		BP_M,
				BP_CCED,	BP_APOS,	BP_Q,		BP_G,		BP_H,		BP_F,		BP_W,
								KC_RALT,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,
KC_NUMLOCK,	KC_INS,
KC_VOLU,
KC_VOLD,	KC_RSHIFT,	LT(FNSPACE,KC_SPACE)),
// Gaming layer 
[GAMING] = LAYOUT_ergodox(
// Left hand
BP_DOLLAR,	BP_DQOT,	BP_LGIL,	BP_RGIL,	BP_LPRN,	BP_RPRN,	KC_DEL,
KC_TAB,		BP_B,   	BP_T,		BP_P,		BP_O,		BP_G,		KC_BSPC,
KC_TRNS,	BP_A,		BP_U,		BP_I,		BP_E,		BP_COMMA,
KC_LCTL,	KC_LSFT,	BP_Y,		BP_X,		BP_DOT,		BP_K,		LCTL(KC_BSPC),
M(CTLX),	LCTL(BP_C),	LCTL(BP_V),	KC_LGUI,	KC_LALT,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_ENTER,	KC_LSHIFT,	LCTL(LALT(BP_B)),
// Right hand
				BP_PERCENT,	BP_AT,		BP_PLUS,	BP_MINUS,	BP_SLASH,	BP_ASTR,	BP_EQUAL,
				KC_CAPSLOCK,	BP_DCRC,	BP_V,		BP_D,		BP_L,		BP_J,		BP_Z,
						BP_C,		BP_T,		BP_S,		BP_R,		BP_N,		BP_M,
				BP_CCED,	BP_APOS,	BP_Q,		BP_G,		BP_H,		BP_F,		BP_W,
								KC_RALT,	KC_LEFT,	KC_LEFT,	KC_RIGHT,	KC_RIGHT,
KC_NUMLOCK,	KC_TRNS,
KC_VOLU,
KC_VOLD,	KC_RSHIFT,	LT(FNSPACE,KC_SPACE)),



//FNSpace layer with some cool stuff.
/*==================================================================================================================================================================================================================================================================================================================================================================================================================================================
 */
[FNSPACE] = LAYOUT_ergodox(
// Left hand
KC_TRNS,	S(KC_QUOT),	S(KC_COMM),	S(KC_DOT),	KC_LPRN,	KC_RPRN,	KC_DEL,
M(ALTTAB),	KC_SPC,		M(COPL),	LSFT(KC_INS),	C(S(BP_X)),	KC_E,		KC_VOLU,
KC_TRNS,	KC_HOME,	LCTL(KC_LEFT),	LCTL(KC_RIGHT),	KC_END,		KC_COMMA,
KC_TRNS, 	KC_TRNS,	LALT(KC_F4),	LCTL(BP_W),	KC_DOT,		KC_K,		KC_VOLD,
KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_LALT,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												M(ENT_RESET),	KC_NO,		MO(FNAV),

// Right hand
				KC_SLCK,	KC_AT,		KC_MINUS,	LALT(KC_TAB),	LALT(S(KC_TAB)),	KC_ASTR,	KC_EQUAL,
				KC_CAPSLOCK,	M(CAS),		LALT(KC_LEFT),	LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),LALT(KC_RIGHT),	KC_RIGHT,
						KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,	LCTL(BP_T),	KC_F6,
				KC_NUMLOCK,	KC_QUOT,	KC_PGDOWN,	KC_PGUP,	LCTL(BP_R),	KC_F,		KC_C,
								KC_END,		KC_HOME,	KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
KC_TRNS,	KC_TRNS,
KC_TRNS,
MO(FNAV),	KC_NO,		KC_TRNS),

/* Keymap 4: function / navigation layer
==================================================================================================================================================================================================================================================================================================================================================================================================================================================
 */
[FNAV] = LAYOUT_ergodox(
// Left hand
KC_F12,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_MUTE,
KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_VOLU,
KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_TRNS,	KC_UNDO,	KC_CUT,		KC_COPY,	KC_PASTE,	KC_NO,		KC_VOLD,
KC_TRNS,	KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_NO,		KC_NO,
																KC_TRNS,
												KC_ENTER,	KC_TRNS,	KC_TRNS,
// Right hand
				KC_NO,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,
				KC_NO,		KC_PGUP,	KC_HOME,	KC_UP,		KC_END,		KC_F11,		KC_F12,
						KC_PGDOWN,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_F12,		KC_NO,
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,		KC_NO,
KC_NO,		KC_NO,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_NO),
/* Keymap 1: QWERTY system compatibility layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   (  |   )  |Delete|                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   b  |   e  |   p  |   o  |   e  |Backsp|                                  |CapsLo|   ^  |   v  |   d  |   l  |   j  |   z    |
 * |--------+------+------+------+------+------|  ace |                                  |      |------+------+------+------+------+--------|
 * |   w    |   a  |   u  |   i  |   e  |   ,  |------|                                  |------|   c  |   t  |   s  |   r  |   n  |   m    |
 * |--------+------+------+------+------+------|  Tab |                                  | NumLo|------+------+------+------+------+--------|
 * |   e    |   a  |   y  |   x  |   .  |   k  |      |                                  |      |   '  |   q  |   g  |   h  |   f  |   c    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   | BEPO |      |LSuper| LCtrl|  LAlt|             |Escape| L_Mse|      |      |Insert|             | AltGr| RCtrl|RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | L_Num|      |      |      |      |
 *                                             | Space|LShift|------|      |------|RShift|Enter |
 *                                             |      |      |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[QWER] = LAYOUT_ergodox(
// Left hand
KC_DOLLAR,	S(KC_QUOT),	S(KC_COMM),	S(KC_DOT),	KC_LPRN,	KC_RPRN,	KC_DEL,
KC_TAB,		KC_B,		M(E),		KC_P,		KC_O,		KC_E,		KC_BSPC,
KC_TRNS,	KC_A,		KC_U,		KC_I,		KC_E,		KC_COMMA,
KC_LCTL,	M(AN),		KC_Y,		KC_X,		KC_DOT,		KC_K,		LALT(KC_BSPC),
KC_TRNS,	KC_COPY,	KC_PASTE,	KC_LGUI,	KC_LALT,
														KC_ESC,		KC_TRNS,
																KC_TRNS,
												KC_ENTER,	KC_LSHIFT,	MO(FNAV),
// Right hand
				KC_PERC,	KC_AT,		KC_PLUS,	KC_MINUS,	KC_SLASH,	KC_ASTR,	KC_EQUAL,
				KC_CAPSLOCK,	KC_CIRC,	KC_V,		KC_D,		KC_L,		KC_J,		KC_Z,
						KC_C,		KC_T,		KC_S,		KC_R,		KC_N,		KC_M,
				LALT(KC_C),	KC_QUOT,	KC_Q,		KC_G,		KC_H,		KC_F,		KC_W,
								MO(AQWER),	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,
KC_NO,		KC_INS,
KC_TRNS,
MO(FNAV),	MO(SQWER),	LT(QFNSPACE,KC_SPC)),
/* Keymap 2: QWERTY shifted system compatibility layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   #    |   1  |   2  |   3  |   4  |   5  |Delete|                                  |ScroLo|   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   `    |   B  |   E  |   P  |   O  |   E  |Backsp|                                  |CapsLo|   !  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|  ace |                                  |      |------+------+------+------+------+--------|
 * |   W    |   A  |   U  |   I  |   E  |   ;  |------|                                  |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------|  Tab |                                  | NumLo|------+------+------+------+------+--------|
 * |   E    |   A  |   Y  |   X  |   :  |   K  |      |                                  |      |   ?  |   Q  |   G  |   H  |   F  |   C    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   | BEPO |      |LSuper| LCtrl|  LAlt|             |Escape| L_Mse|      |      |Insert|             | AltGr| RCtrl|RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | L_Num|      |      |      |      |
 *                                             | Space|LShift|------|      |------|RShift|Enter |
 *                                             |      |      |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[SQWER] = LAYOUT_ergodox(
// Left hand
KC_HASH,	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_TRNS,
KC_TRNS,	S(KC_B),	M(EM),		S(KC_P),	S(KC_O),	S(KC_E),	KC_TRNS,
KC_TRNS,	S(KC_A),	S(KC_U),	S(KC_I),	S(KC_E),	KC_SCOLON,
KC_TRNS,	M(AM),		S(KC_Y),	S(KC_X),	KC_COLON,	S(KC_K),	S(KC_TAB),
KC_TRNS,	KC_TRNS,	S(KC_LGUI),	S(KC_LCTL),	S(KC_LALT),
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_TRNS,	KC_TRNS,	KC_TRNS,
// Right hand
				KC_TRNS,	KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_TRNS,
				KC_TRNS,	KC_EXLM,	S(KC_V),	S(KC_D),	S(KC_L),	S(KC_J),	S(KC_Z),
						S(KC_C),	S(KC_T),	S(KC_S),	S(KC_R),	S(KC_N),	S(KC_M),
				KC_TRNS,	S(KC_SLASH),	S(KC_Q),	S(KC_G),	S(KC_H),	S(KC_F),	S(KC_W),
								S(KC_RALT),	S(KC_RCTL),	S(KC_RGUI),	KC_TRNS,	KC_TRNS,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_TRNS),
/* Keymap 3: QWERTY alted system compatibility layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   [  |   ]  |Delete|                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   |  |   e  |   &  |   o  |   e  |Backsp|                                  |CapsLo|   ^  |   v  |   d  |   l  |   j  |   z    |
 * |--------+------+------+------+------+------|  ace |                                  |      |------+------+------+------+------+--------|
 * |   w    |   a  |   u  |   i  |   €  |   ,  |------|                                  |------|   c  |   t  |   s  |   r  |   n  |   m    |
 * |--------+------+------+------+------+------|  Tab |                                  | NumLo|------+------+------+------+------+--------|
 * |   e    |   \  |   {  |   }  |   .  |   ~  |      |                                  |      |   '  |   q  |   g  |   h  |   f  |   c    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   | BEPO |      |LSuper| LCtrl|  LAlt|             |Escape| L_Mse|      |      |Insert|             | AltGr| RCtrl|RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | L_Num|      |      |      |      |
 *                                             |   _  |LShift|------|      |------|RShift|Enter |
 *                                             |      |      |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[AQWER] = LAYOUT_ergodox(
// Left hand
KC_DOLLAR,	S(KC_QUOT),	S(KC_COMM),	S(KC_DOT),	KC_LBRC,	KC_RBRC,	KC_DEL,
KC_PERCENT,	KC_PIPE,	KC_E,		KC_AMPR,	KC_O,		KC_E,		KC_BSPC,
KC_TRNS,	KC_A,		KC_U,		KC_I,		RALT(KC_5),	KC_COMMA,
KC_E,		KC_BSLASH,	KC_LCBR,	KC_RCBR,	KC_DOT,		KC_TILDE,	KC_TAB,
KC_TRNS,	KC_NO,		KC_LGUI,	KC_LCTL,	KC_LALT,
														KC_ESC,		MO(MSE),
																KC_TRNS,
												KC_UNDS,	MO(SQWER),	MO(FNAV),
// Right hand
				KC_SLCK,	KC_AT,		KC_PLUS,	KC_MINUS,	KC_SLASH,	KC_ASTR,	KC_EQUAL,
				KC_CAPSLOCK,	KC_CIRC,	KC_V,		KC_D,		KC_L,		KC_J,		KC_Z,
						KC_C,		KC_T,		KC_S,		KC_R,		KC_N,		KC_M,
				KC_NUMLOCK,	KC_QUOT,	KC_Q,		KC_G,		KC_H,		KC_F,		KC_C,
								KC_TRNS,	KC_RCTL,	KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
KC_NO,		KC_INS,
KC_TRNS,
MO(FNAV),	MO(SQWER),	KC_ENTER),

[QFNSPACE] = LAYOUT_ergodox(
// Left hand
KC_TRNS,	S(KC_QUOT),	S(KC_COMM),	S(KC_DOT),	KC_LPRN,	KC_RPRN,	KC_DEL,
KC_TRNS,	KC_B,		KC_E,		KC_P,		KC_O,		KC_E,		KC_BSPC,
KC_TRNS,	LCTL(KC_LEFT),	LCTL(KC_LEFT),	LCTL(KC_RIGHT),	LCTL(KC_RIGHT),	KC_COMMA,
KC_TRNS,	KC_A,		LALT(KC_F4),	LGUI(KC_W),	KC_DOT,		KC_K,		KC_TAB,
KC_TRNS,	KC_NO,		KC_TRNS,	KC_TRNS,	KC_LALT,
														KC_ESC,		KC_NO,
																KC_TRNS,
												KC_TRNS,	KC_NO,		MO(FNAV),

// Right hand
				KC_SLCK,	KC_AT,		KC_PLUS,	KC_MINUS,	KC_SLASH,	KC_ASTR,	KC_EQUAL,
				KC_CAPSLOCK,	KC_CIRC,	LGUI(KC_LBRC),	LGUI(LALT(KC_LEFT)),LGUI(LALT(KC_RIGHT)),LGUI(KC_RBRC),KC_RIGHT,
						KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,	M(NT),		KC_TRNS,
				KC_NUMLOCK,	KC_QUOT,	KC_PGDOWN,	KC_PGUP,	LGUI(KC_R),	KC_F,		KC_TRNS,
								KC_NO,		KC_RCTL,	KC_RGUI,	KC_TRNS,	KC_TRNS,
KC_NO,		KC_INS,
KC_TRNS,
MO(FNAV),	KC_NO,		KC_TRNS),
[NUM] = LAYOUT_ergodox(
// Left hand
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_TRNS,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_TRNS,
KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_1,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_TRNS,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_NO,		KC_NO,
																KC_TRNS,
												KC_TRNS,	KC_TRNS,	KC_TRNS,
// Right hand
				KC_NO,		KC_NO,		KC_KP_PLUS,	KC_KP_MINUS,	KC_KP_SLASH,	KC_KP_ASTERISK,	KC_NO,
				KC_NO,		KC_NO,		KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_NO,		KC_NO,
						KC_NO,		KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_KP_ENTER,	KC_NO,
				KC_NO,		KC_NO,		KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_NO,		KC_NO,
								KC_KP_0,	M(KP_00),	KC_KP_COMMA,	KC_NO,		KC_NO,
KC_NO,		KC_NO,
KC_NO,
KC_TRNS,	KC_TRNS,	KC_TRNS),

};



const uint16_t PROGMEM fn_actions[] = {
};

static uint16_t key_timer = 0;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
	case CTLX: 
      if (record->event.pressed) {
                key_timer = timer_read(); // if the key is being pressed, we start the timer.
		layer_on(FNAV);
      } else {
                if (timer_elapsed(key_timer) < 250) { // 250 being 250ms, the threshhold we pick for counting something as a tap.
			layer_off(FNAV);
	                return MACRO( D(LCTL), TYPE(BP_X), U(LCTL),END  );
                }

		else{
		
			layer_off(FNAV);
		}
      }
      break;
	case CAS:
      if (record->event.pressed) {
        return MACRO( D(LCTL), D(LALT), D(DEL),  END );
      } else {
        return MACRO( U(DEL), U(LALT), U(LCTL),  END );
      }
      break;
	case COPL:
      if (record->event.pressed) {
      } else {
        return MACRO( T(HOME), D(LSFT), T(END), U(LSFT), END );
      }
      break;
	case E:
      if (record->event.pressed) {
        return MACRO( D(LALT), T(E), END );
      } else {
        return MACRO( U(LALT), T(E), END );
      }
      break;
	case EM:
      if (record->event.pressed) {
        return MACRO( D(LALT), T(E), U(LALT),END );
      } else {
        return MACRO( D(LSFT), T(E), U(LSFT), END );
      }
      break;
	case AN:
      if (record->event.pressed) {
        return MACRO( D(LALT), T(A), U(LALT),END );
      } else {
        return MACRO(  T(GRV), END );
      }
      break;
	case AM:
      if (record->event.pressed) {
        return MACRO( D(LALT), T(A), U(LALT),END );
      } else {
        return MACRO( D(LSFT), T(GRV), U(LSFT), END );
      }
      break;
	case NT:
      if (record->event.pressed) {
        return MACRO( D(LGUI), T(N), END );
      } else {
        return MACRO( T(L), U(LGUI), END );
      }
      break;
	case ESCM:
      if (record->event.pressed) {
	     clear_keyboard();
	     layer_on(0);
        return MACRO( D(ESC), END );
      } else {
        return MACRO( U(ESC), END );
      }
      break;
    case KP_00:
      if (record->event.pressed) {
        return MACRO( T(KP_0), D(KP_0), END );
      } else {
        return MACRO( U(KP_0), END );
      }
      break;
    case CA_Fx:
      if (record->event.pressed) {
        layer_on(FNAV);
        return MACRO( D(LALT), D(LCTL), END );
      } else {
        layer_off(FNAV);
        return MACRO( U(LCTL), U(LALT), END );
      }
      break;
    case ALTTAB:
      if (record->event.pressed) {
	register_code(KC_RALT);
	tap_code(KC_TAB);
//        return MACRO( D(LALT), END );
      } else {
//        return MACRO( LALT), END );
      }
      break;
    case ENT_RESET:
      if (record->event.pressed) {
	unregister_code(KC_RALT);
	tap_code(KC_ENTER);
//	clear_mods();
//	SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
//        return MACRO( T(ENT), END );
      } else {
      //  return MACRO( END );
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
//    	ergodox_right_led_1_on();

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};
