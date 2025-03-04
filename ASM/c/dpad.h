#ifndef DPAD_H
#define DPAD_H

#include "z64.h"

#define BLOCK_DPAD (0x00000001 | \
	                0x00000002 | \
                    0x00000080 | \
                    0x00000400 | \
                    0x10000000 | \
                    0x20000000)

#define BLOCK_OCARINA (0x00800000 | \
                       0x00000800 | \
                       0x00200000 | \
                       0x08000000)

//MODIFIED (Shields)
#define DISPLAY_DPAD          (((z64_file.iron_boots || z64_file.hover_boots) && z64_file.link_age==0)  || \
                               ((z64_file.hylian_shield || z64_file.deku_shield) 							          || \
																(z64_file.items[Z64_SLOT_NUT] == Z64_ITEM_NUT)) && z64_file.link_age==1 || \
                                 z64_file.items[0x07] == 0x07 || z64_file.items[0x07] == 0x08)
//ORIGINAL
//#define DISPLAY_DPAD        (((z64_file.iron_boots || z64_file.hover_boots) && z64_file.link_age==0) || \
                                 z64_file.items[0x07] == 0x07 || z64_file.items[0x07] == 0x08)

#define CAN_USE_DPAD        (((z64_link.state_flags_1 & BLOCK_DPAD) == 0) && \
                            ((uint32_t)z64_ctxt.state_dtor==z64_state_ovl_tab[3].vram_dtor) && \
                            (z64_file.game_mode == 0) && \
                            ((z64_event_state_1 & 0x20) == 0))

#define CAN_USE_OCARINA     (z64_game.pause_ctxt.state == 0 && (z64_file.items[0x07] == 0x07 || z64_file.items[0x07] == 0x08) && !z64_game.restriction_flags.ocarina && ((z64_link.state_flags_1 & BLOCK_OCARINA) == 0))

void handle_dpad();
void draw_dpad();

#endif
