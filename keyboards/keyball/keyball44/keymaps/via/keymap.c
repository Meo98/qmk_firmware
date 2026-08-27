/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

#include <math.h>

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_DEL   ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , S(KC_7)  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
              KC_LALT,KC_LGUI,LCTL_T(KC_LNG2)     ,LT(1,KC_SPC),LT(3,KC_LNG1),                  KC_BSPC,LT(2,KC_ENT), RCTL_T(KC_LNG2),     KC_RALT  , KC_PSCR
  ),

  [1] = LAYOUT_universal(
    SSNP_FRE ,  KC_F1   , KC_F2    , KC_F3   , KC_F4    , KC_F5    ,                                         KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    SSNP_VRT ,  _______ , _______  , KC_UP   , KC_ENT   , KC_DEL   ,                                         KC_PGUP  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_BTN3  , KC_F12   ,
    SSNP_HOR ,  _______ , KC_LEFT  , KC_DOWN , KC_RGHT  , KC_BSPC  ,                                         KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
                  _______  , _______ , _______  ,         _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______  ,S(KC_QUOT), KC_7     , KC_8    , KC_9     , S(KC_8)  ,                                         S(KC_9)  , S(KC_1)  , S(KC_6)  , KC_LBRC  , S(KC_4)  , _______  ,
    _______  ,S(KC_SCLN), KC_4     , KC_5    , KC_6     , KC_RBRC  ,                                         KC_NUHS  , KC_MINS  , S(KC_EQL), S(KC_3)  , KC_QUOT  , S(KC_2)  ,
    _______  ,S(KC_MINS), KC_1     , KC_2    , KC_3     ,S(KC_RBRC),                                        S(KC_NUHS),S(KC_INT1), KC_EQL   ,S(KC_LBRC),S(KC_SLSH),S(KC_INT3),
                  KC_0     , KC_DOT  , _______  ,         _______  , _______  ,                   KC_DEL   , _______  , _______       , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  ),

  [4] = LAYOUT_universal(
    _______  , _______   , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______ ,                                        _______  , _______  , _______  , _______ , _______  , _______  ,
    _______ , _______  , _______  , _______  , _______  , _______ ,                                        _______  , _______ , _______ , _______  , _______  , _______ ,
                  _______  , _______  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  ),

  [5] = LAYOUT_universal(
    _______  , _______   , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______ ,                                        _______  , _______  , _______  , _______ , _______  , _______  ,
    _______ , _______  , _______  , _______  , _______  , _______ ,                                        _______  , _______ , _______ , _______  , _______  , _______ ,
                  _______  , _______  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  ),

  [6] = LAYOUT_universal(
    _______  , _______   , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______ ,                                        _______  , _______  , _______  , _______ , _______  , _______  ,
    _______ , _______  , _______  , _______  , _______  , _______ ,                                        _______  , _______ , _______ , _______  , _______  , _______ ,
                  _______  , _______  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  ),

  [7] = LAYOUT_universal(
    _______  , _______   , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______ ,                                        _______  , _______  , _______  , _______ , _______  , _______  ,
    _______ , _______  , _______  , _______  , _______  , _______ ,                                        _______  , _______ , _______ , _______  , _______  , _______ ,
                  _______  , _______  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  ),
};
// clang-format on

// ---------------------------------------------------------------------------
// Geschwindigkeitsabhaengige Scroll-Kurve
// ---------------------------------------------------------------------------
// Ersetzt die schwache Default-Implementierung der Keyball-Lib. Zwei
// Unterschiede:
//
//   1. Float-Akkumulator statt Integer-Division. Die Lib wirft in
//      motion_to_mouse() den Divisions-Rest weg (report->x = 0), wodurch
//      alles unterhalb der Divisor-Schwelle ersatzlos verloren geht. Hier
//      ueberlebt der Rest-Betrag den Poll-Zyklus, langsames Scrollen bleibt
//      dadurch aufgeloest statt tot.
//
//   2. Sigmoid-Kurve auf der Ballgeschwindigkeit: langsames Rollen erzeugt
//      kleine Schritte (Lesen), schnelles Rollen grosse (Navigieren).
//
// Die Geschwindigkeit wird wie bei maccel auf 1000 CPI normalisiert, damit
// die Kurve bei jeder CPI-Einstellung gleich reagiert.

static float    scr_acc_h  = 0.0f;  // Rest-Betrag horizontal (v120-Einheiten)
static float    scr_acc_v  = 0.0f;  // Rest-Betrag vertikal
static float    scr_vel    = 0.0f;  // geglaettete Geschwindigkeit
static uint32_t scr_last   = 0;     // Zeitpunkt des letzten Bewegungs-Reports

static inline float scr_sigmoid(float v) {
    return 1.0f / (1.0f + expf(-SCR_GROWTH * (v - SCR_VEL_MID)));
}

void keyball_on_apply_motion_to_mouse_scroll(report_mouse_t *report, report_mouse_t *output, bool is_left) {
    // Die Lib ruft diese Funktion einmal pro Haelfte auf; die ballfreie
    // Seite liefert einen Null-Report, den wir nicht als Bewegung werten.
    if (report->x == 0 && report->y == 0) {
        return;
    }

    const uint32_t now = timer_read32();
    const uint32_t dt  = TIMER_DIFF_32(now, scr_last);
    scr_last           = now;

    // Nach einer Pause faengt eine neue Geste an: alter Zustand verfaellt.
    if (dt > SCR_IDLE_RESET_MS) {
        scr_acc_h = 0.0f;
        scr_acc_v = 0.0f;
        scr_vel   = 0.0f;
    }

    const uint16_t cpi = keyball_get_cpi();

    // Geschwindigkeit in Counts/ms, auf 1000 CPI normalisiert.
    const float dist    = sqrtf((float)report->x * report->x + (float)report->y * report->y);
    const float raw_vel = (1000.0f / (float)cpi) * dist / (float)(dt == 0 ? 1 : dt);

    // Bei 1 ms Poll-Intervall ist dt nur 1 oder 2 -- die rohe Geschwindigkeit
    // springt dadurch stark. Der gleitende Mittelwert laesst die Kurve der
    // Hand folgen statt dem Quantisierungsrauschen.
    scr_vel += SCR_VEL_SMOOTH * (raw_vel - scr_vel);

    // Faktor 1.0 (bei Stillstand) bis SCR_GAIN_MAX (bei schnellem Rollen).
    // Die Normalisierung auf sigmoid(0) sorgt dafuer, dass der Faktor unten
    // tatsaechlich bei 1.0 startet und SCR_MM_PER_DETENT_SLOW stimmt.
    const float s0   = scr_sigmoid(0.0f);
    const float gain = 1.0f + (SCR_GAIN_MAX - 1.0f) * (scr_sigmoid(scr_vel) - s0) / (1.0f - s0);

    // v120-Einheiten pro Sensor-Count, so dass bei gain == 1 genau
    // SCR_MM_PER_DETENT_SLOW Millimeter Ballweg einen Rasterschritt ergeben.
    // 120 Einheiten pro Rasterschritt, 25.4 mm pro Zoll.
    float scale = (120.0f * 25.4f) / (SCR_MM_PER_DETENT_SLOW * (float)cpi);

    // SCRL_DVI / SCRL_DVD bleiben als grobe Live-Stufe nutzbar.
    scale /= (float)(1 << (keyball_get_scroll_div() - 1));

    scale *= gain;

    // Richtungswechsel: Rest-Betrag der Gegenrichtung verwerfen.
    if ((float)report->x * scr_acc_h < 0.0f) scr_acc_h = 0.0f;
    if ((float)report->y * scr_acc_v < 0.0f) scr_acc_v = 0.0f;

    scr_acc_h += (float)report->x * scale;
    scr_acc_v += (float)report->y * scale;

    // Ganzzahligen Anteil senden, Nachkommastelle aufheben.
    const int16_t h = (int16_t)scr_acc_h;
    const int16_t v = (int16_t)scr_acc_v;
    scr_acc_h -= (float)h;
    scr_acc_v -= (float)v;

    // Vorzeichen-Konvention der Keyball-Lib beibehalten.
    output->h = is_left ? h : -h;
    output->v = is_left ? -v : v;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
