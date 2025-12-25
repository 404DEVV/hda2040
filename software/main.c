#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pio_hda_clk.pio.h"
#include "hardware/clocks.h"

int main() {
    // Safe test speed
    set_sys_clock_khz(240000, true);

    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &hda_clk_program);

    float clkdiv = 1.0f; // very slow for testing
    hda_clk_program_init(pio, sm, offset, 6, 7, clkdiv);

    while (1) pio_sm_put_blocking(pio, sm, 0xF0F0F0F0);  // shifts out 1010101010101010;
}
