# Keyball44 Custom Firmware (KB2040)

Fork of [Yowkees/keyball QMK firmware](https://github.com/Yowkees/keyball) with modifications for the **Adafruit KB2040** controller and improved scroll behavior.

## What's different from upstream

### KB2040 Pin Remapping

The original firmware targets ProMicro. This fork remaps SPI pins for the KB2040 (RP2040-based) controller:

| Pin | Original (ProMicro) | This fork (KB2040) |
|-----|--------------------|--------------------|
| SPI_SCK | GP22 | **GP18** |
| SPI_MOSI | GP23 | **GP19** |
| SPI_MISO | GP20 | GP20 (unchanged) |
| PMW33XX_CS | GP10 | GP10 (unchanged) |

Configured in `keyboards/keyball/config.h`.

### High-Resolution Smooth Scrolling

The stock firmware sends scroll events as discrete steps (like a click wheel), making trackball scrolling feel jerky. This fork enables **HID high-resolution scrolling** for pixel-smooth scroll behavior:

- `POINTING_DEVICE_HIRES_SCROLL_ENABLE` — activates the HID Resolution Multiplier (120 units per traditional scroll line)
- `WHEEL_EXTENDED_REPORT` — int16_t scroll values instead of int8_t
- `KEYBALL_HIRES_SCROLL_SCALE 8` — scales raw sensor data to hi-res units (8/120 = 1/15 line per sensor count)
- `KEYBALL_SCROLL_DIV_DEFAULT 1` — no additional division, raw sensor data passes through
- `KEYBALL_SCROLLSNAP_ENABLE 0` — free diagonal scrolling (no axis lock)

Requires OS support for `REL_WHEEL_HI_RES` (Linux 5.0+, Windows 10+).

### OLED Disabled

Disabled to avoid GP0/GP1 I2C conflicts with WS2812 RGB and split serial on the KB2040.

## Build

### GitHub Actions (recommended)

1. Go to **Actions** → **Build Keyball44 KB2040 Firmware**
2. Click **Run workflow**
3. Download the `.uf2` artifact

### Local

```bash
qmk compile -kb keyball/keyball44 -km via
```

## Flash

1. Double-tap the **Reset** button on the KB2040 — a USB drive appears
2. Drag the `.uf2` file onto the drive
3. Keyboard reboots automatically

## VIA Support

The firmware includes VIA support. Open [usevia.app](https://usevia.app) or [Remap](https://remap-keys.app) to configure your keymap in the browser. If the keyboard isn't recognized automatically, load `keyboards/keyball/keyball44/via.json` as a draft definition.

## Tuning Scroll Speed

The scroll speed can be adjusted at runtime using the `SCRL_DVI` / `SCRL_DVD` keycodes (mapped on Layer 3 by default), then saved with `KBC_SAVE`. Higher divisor = slower scroll.

To change the hi-res scale factor, set `KEYBALL_HIRES_SCROLL_SCALE` in `keyboards/keyball/keyball44/keymaps/via/config.h` and rebuild:
- `4` = slower, very fine-grained
- `8` = default, good balance (recommended)
- `16` = faster, slightly coarser
