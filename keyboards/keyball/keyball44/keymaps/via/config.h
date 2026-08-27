/*
This is the c configuration file for the keymap

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

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#endif

#define TAP_CODE_DELAY 5

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 1

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

// ---------------------------------------------------------------------------
// Trackball: Grundaufloesung
// ---------------------------------------------------------------------------
// Hoeher als frueher (500), weil die Beschleunigungskurve unten HERUNTER-
// skaliert: die Kurve deckelt bei 1.0, langsame Bewegungen werden auf
// LIMIT * CPI reduziert. 1200 * 0.30 = 360 CPI im Praezisionsbereich.
// ACHTUNG: nach dem Flashen einmal KBC_RST druecken, sonst gewinnt der
// alte, im EEPROM gespeicherte CPI-Wert.
#define KEYBALL_CPI_DEFAULT 1200

// ---------------------------------------------------------------------------
// Scrolling
// ---------------------------------------------------------------------------
// Der Divisor der Keyball-Lib wird von unserer eigenen Kurve in keymap.c als
// grobe Live-Stufe weiterverwendet (SCRL_DVI / SCRL_DVD auf Layer 3):
// Stufe n teilt die Scroll-Staerke durch 2^(n-1).
#define KEYBALL_SCROLL_DIV_DEFAULT 1

// Achsen-Lock aus: freies diagonales Scrollen.
#define KEYBALL_SCROLLSNAP_ENABLE 0

// Hi-Res-Scrolling: 120 Einheiten = 1 klassischer Rasterschritt.
#define POINTING_DEVICE_HIRES_SCROLL_ENABLE
#define WHEEL_EXTENDED_REPORT

// --- Parameter der Scroll-Kurve (Auswertung in keymap.c) -------------------
// Ballweg in mm fuer einen Rasterschritt bei Lesetempo. Groesser = feiner.
#define SCR_MM_PER_DETENT_SLOW 1.6f
// Obergrenze des Geschwindigkeits-Faktors. 6.0 = schnelles Rollen scrollt
// 6x weiter pro Ballweg als langsames.
#define SCR_GAIN_MAX 6.0f
// Wendepunkt der Kurve, CPI-normalisiert wie bei maccel (1000 CPI = Referenz).
// 3.5 entspricht ungefaehr 90 mm/s Balloberflaechen-Geschwindigkeit.
#define SCR_VEL_MID 3.5f
// Steilheit der Kurve. Hoeher = abrupterer Uebergang langsam -> schnell.
#define SCR_GROWTH 0.9f
// Glaettung der Geschwindigkeitsmessung (0..1). Klein = ruhiger, traeger.
#define SCR_VEL_SMOOTH 0.30f
// Nach dieser Pause verfallen Rest-Betrag und Geschwindigkeit.
#define SCR_IDLE_RESET_MS 150

// ---------------------------------------------------------------------------
// Cursor: maccel (drashna/pointing_device_accel)
// ---------------------------------------------------------------------------
// f(v) = 1 - (1 - LIMIT) / (1 + e^[TAKEOFF*(v - OFFSET)])^(GROWTH/TAKEOFF)
// Ergebnis ist ein Faktor <= 1.0 auf die CPI oben.
// Mit diesen Werten: ~360 CPI bei langsam, ~1170 CPI bei schnell.
#define POINTING_DEVICE_ACCEL_TAKEOFF 2.0     // wie abrupt die Kurve anspringt
#define POINTING_DEVICE_ACCEL_GROWTH_RATE 0.25 // wie schnell sie ihr Maximum erreicht
#define POINTING_DEVICE_ACCEL_OFFSET 2.2      // ab welchem Tempo Beschleunigung einsetzt
#define POINTING_DEVICE_ACCEL_LIMIT 0.30      // Untergrenze = Praezisionsmodus
