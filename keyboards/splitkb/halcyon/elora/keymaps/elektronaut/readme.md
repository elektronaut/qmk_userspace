# elektronaut's Halcyon Elora keymap

A Norwegian Colemak-DH keymap with home row mods, built around five layers:

| # | Layer | Access |
|---|-------|--------|
| 0 | `_COLEMAK_DH` — base, Colemak-DH with Norwegian extras | default layer |
| 1 | `_QWERTY` — base, Norwegian QWERTY | `QWRTY` / `CMKDH` keys |
| 2 | `_EXT` — navigation, media, editing | hold `Ext` (left thumb) |
| 3 | `_SYM` — symbols | hold `Sym` (right thumb) |
| 4 | `_NUMP` — numpad and function keys | hold `Tab` or `Enter` (inner thumbs) |

Alphas and symbols are Norwegian: the keymap includes `keymap_norwegian.h` and uses
`NO_*` keycodes, so the host must be set to a Norwegian layout. The symbol legends
below are what the keys produce on the **macOS** Norwegian layout — a few of them
(`\`, `@`, `*`, `<`, `>`, `§`) land on different characters under the Windows/Linux
variant of the same layout.

In the diagrams, a blank cell is transparent (falls through to the layer below) and
the bottom strip is the Halcyon module row: the first key on each half is the encoder
push button, the other four belong to modules that aren't used here.

## Base layer: Colemak-DH

```
,-------------------------------------------.                              ,-------------------------------------------.
|  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |        |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|CapsLock|   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   Å  |   Æ    |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|  LCtrl |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |   Ø    |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
| LShift |   Z  |   X  |   C  |   D  |   V  |LayLok|QWRTY |  |      |      |   K  |   H  |   ,  |   .  |  -   |   ¨    |
`----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
                       | LAlt | LGUI | Ext  | Space|Tab/  |  |Enter/| Bksp | Sym  | RGUI | RAlt |
                       |      |      |      |      | Nump |  | Nump |      |      |      |      |
                       `----------------------------------'  `----------------------------------'
,-----------------------------------.                                              ,-----------------------------------.
| Mute |      |       |      |      |                                              | Mute |      |       |      |      |
`-----------------------------------'                                              `-----------------------------------'
```

`LayLok` (`QK_LLCK`) locks the next layer you activate, so Ext, Sym and Nump can be
used as one-shot sticky layers instead of being held. `QWRTY` switches the default
layer to QWERTY; the mirrored `CMKDH` key switches back. Neither is stored in EEPROM,
so the board always boots into Colemak-DH.

### Home row mods

Both base rows carry mods on hold, mirrored across the halves:

| Hold | `A` | `R` | `S` | `T` | | `N` | `E` | `I` | `O` |
|------|-----|-----|-----|-----|-|-----|-----|-----|-----|
|      | Alt | GUI | Ctrl | Shift | | Shift | Ctrl | GUI | AltGr |

Tapping term is 175 ms with `PERMISSIVE_HOLD` and `CHORDAL_HOLD`, so a mod only
triggers on a hold when it's chorded with a key on the *opposite* half — same-hand
rolls stay letters. The QWERTY layer deliberately has no home row mods; it exists for
gaming and for handing the board to someone else.

The two inner thumb keys are also dual-role: `Tab` and `Enter` on tap, Nump on hold.

## Base layer: QWERTY

```
,-------------------------------------------.                              ,-------------------------------------------.
|  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |        |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|CapsLock|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   Å    |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|  LCtrl |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ø  |   Æ    |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
| LShift |   Z  |   X  |   C  |   V  |   B  |LayLok|CMKDH |  |      |      |   N  |   M  |   ,  |   .  |  -   |   ¨    |
`----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
                       | LAlt | LGUI | Ext  | Space|Tab/  |  |Enter/| Bksp | Sym  | RGUI | RAlt |
                       |      |      |      |      | Nump |  | Nump |      |      |      |      |
                       `----------------------------------'  `----------------------------------'
,-----------------------------------.                                              ,-----------------------------------.
| Mute |      |       |      |      |                                              | Mute |      |       |      |      |
`-----------------------------------'                                              `-----------------------------------'
```

## Ext layer: navigation, media, editing

```
,-------------------------------------------.                              ,-------------------------------------------.
|        |      |      |      |      |      |                              |      |      |      |      |      |        |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
| CapsWrd|      |M Prev|M Play|M Next| VolUp|                              | PgUp | Home |   ↑  | End  |Insert| PrtSc  |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        | LAlt | LGUI | LCtrl|LShift| VolDn|                              | PgDn |  ←   |   ↓  |   →  |Delete| ScLck  |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
|        |      |      |      |      |VolMut|      |      |  |      |      |      |      | dired|      |  F12 | Pause  |
`----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
                       |      |      |      |      |      |  |      |      |      |      |      |
                       |      |      |      |      |      |  |      |      |      |      |      |
                       `----------------------------------'  `----------------------------------'
```

The navigation cluster sits under the right hand in the usual inverted-T, with the
left home row turned into plain modifiers so shortcuts like Ctrl+→ or Shift+Home can
be chorded without leaving the layer. `CapsWrd` toggles Caps Word, and `dired` sends
<kbd>Ctrl</kbd>+<kbd>X</kbd> <kbd>Ctrl</kbd>+<kbd>J</kbd> for Emacs' `dired-jump`.

The `Sym` thumb key is disabled here, so Ext+Sym does nothing by accident.

## Sym layer: symbols

```
,-------------------------------------------.                              ,-------------------------------------------.
|        |      |      |      |      |      |                              |      |      |      |      |      |        |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        |  ~   |  <   |  (   |  $   |  \   |                              |   `  |  '   |  #   |  ?   |  ^   |        |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|   §    |  [   |  {   |  >   |  )   |  &   |                              |   *  |  "   |  /   |  =   |  %   |   `    |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
|   £    |  €   |  ]   |  }   |  |   |  !   |      |      |  |      |      |   +  |  @   |  ;   |  :   |  _   |   ´    |
`----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
                       |      |      |      |  _   |      |  |      |      |      |      |      |
                       |      |      |      |      |      |  |      |      |      |      |      |
                       `----------------------------------'  `----------------------------------'
```

Every symbol that needs AltGr or a dead key on a Norwegian layout gets a single
unshifted key here, which is the whole point of the layer. The left hand holds the
pairs, each closing symbol one key down and to the right of its opening one —
`<` `>`, `(` `)`, `[` `]`, `{` `}` — while the right hand keeps the operators and the
punctuation used in prose and code.

Space becomes `_` while Sym is held, so `snake_case` is one rolling motion. The `Ext`
key is disabled on this layer.

## Nump layer: numpad and function keys

```
,-------------------------------------------.                              ,-------------------------------------------.
|        |      |      |      |      |      |                              |      |      |      |      |      |        |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        |  F1  |  F2  |  F3  |  F4  | F5   |                              | NLock|   7  |   8  |   9  |   =  |        |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        |  F6  |  F7  |  F8  |  F9  | F10  |                              |   /  |   4  |   5  |   6  |   +  | Enter  |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
|        | F11  | F12  | F13  | F14  | F15  |      |      |  |      | HRow |   *  |   1  |   2  |   3  |   -  |        |
`----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
                       |      |      |      |      |      |  |      |      |   0  |   ,  |   .  |
                       |      |      |      |      |      |  |      |      |      |      |      |
                       `----------------------------------'  `----------------------------------'
,-----------------------------------.                                              ,-----------------------------------.
| RGB  |      |       |      |      |                                              | RGB  |      |       |      |      |
`-----------------------------------'                                              `-----------------------------------'
```

The numpad is laid out as on a real one, with `0` on the thumb. Both home rows keep
their mods (`F6`–`F9` on the left, `4`–`6` and `+` on the right), so Alt+F4 and
Ctrl+F5 work without switching layers.

`HRow` switches the RGB matrix to the custom `home_row_indicators` effect, which
turns off every LED except the eight home row mod keys — handy when relearning where
the mods live. Pressing either encoder toggles the RGB matrix on and off.

## Hardware

### Encoders

Both encoders do the same thing, and what they do depends on the active layer:

| Layer | Turn | Press |
|-------|------|-------|
| Base | Mouse wheel up/down | Mute |
| Ext | → / ← | Mute |
| Sym | Mouse wheel up/down | Mute |
| Nump | RGB brightness | Toggle RGB |

On the Nump layer, holding a modifier while turning changes what is adjusted:

| Modifier | Adjusts |
|----------|---------|
| *(none)* | Brightness |
| Shift | Hue |
| Ctrl | Saturation |
| GUI | Animation speed |
| Alt | Effect |

Hue, saturation and value steps are set to 1 so the encoder gives fine control
instead of jumping between a handful of presets.

### RGB matrix

Lighting turns itself off after 10 minutes of inactivity
(`RGB_MATRIX_TIMEOUT`). The keymap adds one custom effect,
`home_row_indicators`, defined in [`rgb_matrix_user.inc`](rgb_matrix_user.inc).

## Building

Both build targets are registered in the userspace `qmk.json`, so:

```sh
qmk userspace-compile
```

builds the firmware for the Elora rev2 with either the TFT display module or the
encoder module. To build just one:

```sh
qmk compile -kb splitkb/halcyon/elora/rev2 -km elektronaut -e HLC_ENCODER=1
```
