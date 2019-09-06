/* Basic NESLib Boilerplate */
#include "neslib/neslib.h"
#include "neshelper.h"

#pragma bss-name (push,"ZEROPAGE")
#pragma data-name (push,"ZEROPAGE")
u8 oam_off;
#pragma data-name(pop)
#pragma bss-name (pop)

const u8 text[] = "Hello Boilerplate";
const u8 palette[] = { 0x02, 0x11, 0x14, 0x30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void screenSetup(void) {
  /* Turn of the screen */
  ppu_off();

  /* Setup the palette */
  pal_bg(palette);
}

void main (void) {
  /* Setup Screen */
  screenSetup();

  vram_adr(NTADR_A(7,14)); /* Starting point */
  vram_write(text, sizeof(text)); /* Write text to the starting point */

  ppu_on_all(); /* Activate PPU */

  while (1) {
    /* Game Loop */
  }
}
