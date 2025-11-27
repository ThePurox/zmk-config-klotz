#include "keys_de.h"
#include <behaviors.dtsi>
#include <dt-bindings/zmk/backlight.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/outputs.h>

#define NAV 1
#define NUM 2
#define SYM 3
#define MED 4
/* #define QWERTY_BASE */

#define QUICK_TAP_TIME 200

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
  macros {
  macro_sch: macro_sch {
      label = "Macro_sch";
      compatible = "zmk,behavior-macro";
#binding-cells = <0>;
      bindings = <
        &macro_tap &kp S
        &macro_release &kp RSHIFT
        &macro_tap &kp C &kp H
        >;
    };
  };
};

/ {
    combos {
        compatible = "zmk,combos";
        /* atp-combos */
        combo_v {
          timeout-ms = <20>;
          key-positions = <1 2>;
          bindings = <&kp DE_V>;
        };
        combo_q {
          timeout-ms = <20>;
          key-positions = <2 3>;
          bindings = <&kp DE_Q>;
        };
        combo_b {
          timeout-ms = <20>;
          key-positions = <12 3>;
          bindings = <&kp DE_B>;
        };
        combo_k {
          timeout-ms = <20>;
          key-positions = <12 13>;
          bindings = <&kp DE_K>;
        };
        combo_z {
          timeout-ms = <20>;
          key-positions = <21 22>;
          bindings = <&kp DE_Z>;
        };
        combo_j {
          timeout-ms = <20>;
          key-positions = <17 6>;
          bindings = <&kp DE_J>;
        };
        combo_x {
          timeout-ms = <20>;
          key-positions = <17 16>;
          bindings = <&kp DE_X>;
        };
        combo_sch {
          timeout-ms = <20>;
          key-positions = <11 13>;
          bindings = <&macro_sch>;
        };
        combo_enter {
          timeout-ms = <20>;
          key-positions = <27 26>;
          bindings = <&kp ENTER>;
        };
        /* Umlaute */
        combo_ue {
          timeout-ms = <20>;
          key-positions = <8 32>;
          bindings = <&kp DE_UE>;
        };
        combo_oe {
          timeout-ms = <20>;
          key-positions = <19 32>;
          bindings = <&kp DE_OE>;
        };
        combo_ae {
          timeout-ms = <20>;
          key-positions = <17 32>;
          bindings = <&kp DE_AE>;
        };
        combo_sz {
          timeout-ms = <20>;
          key-positions = <11 32>;
          bindings = <&kp DE_SZ>;
        };
/* caps */
        combo_caps-word {
            timeout-ms = <20>;
            key-positions = <13 16>;
            bindings = <&caps_word>;
        };
        combo_capslock {
            timeout-ms = <20>;
            key-positions = <3 6>;
            bindings = <&kp CAPSLOCK>;
        };
/* deletion */
        combo_bspc {
            timeout-ms = <20>;
            key-positions = <6 7>;
            bindings = <&kp BSPC>;
        };
        combo_del {
            timeout-ms = <20>;
            key-positions = <7 8>;
            bindings = <&kp DEL>;
        };
        combo_delword {
            timeout-ms = <20>;
            key-positions = <6 8>;
            bindings = <&kp LC(BSPC)>;
        };
    };
};


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <170>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 25 26 27 28 29 30 32 33>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <170>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 23 24 30 32 33>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <170>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29>;
        };
    };
};
