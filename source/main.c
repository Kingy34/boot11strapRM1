#include <string.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <sf2d.h>
#include <sfil.h>
#include <sftd.h>
#include <sys/stat.h>
#include <sys/types.h>
// data
#include "FreeSans_ttf.h"
#include "logo_png.h"
#include "btn_a_png.h"
#include "btn_b_png.h"

int main(int argc, char **argv) {
	gfxInitDefault();
	consoleInit(GFX_BOTTOM, NULL); 
	aptInit();
  	fsInit();
	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
	sf2d_set_vblank_wait(0);
	sftd_init();
	hidInit();
	
	sftd_font *font = sftd_load_font_mem(FreeSans_ttf, FreeSans_ttf_size);
	sf2d_texture *tex1 = sfil_load_PNG_buffer(logo_png, SF2D_PLACE_RAM);
	sf2d_texture *tex2 = sfil_load_PNG_buffer(btn_a_png, SF2D_PLACE_RAM);
	sf2d_texture *tex3 = sfil_load_PNG_buffer(btn_b_png, SF2D_PLACE_RAM);
	
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_draw_texture(tex1, 45, 10);
	sf2d_end_frame(); 
	
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_draw_texture(tex2, 10, 120);
	sf2d_end_frame(); 
	
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_draw_texture(tex3, 10, 160);
	sf2d_end_frame(); 

	sf2d_start_frame(GFX_TOP, GFX_LEFT);
			sftd_draw_text(font, 42, 122,  RGBA8(255, 0,   0,   255), 20, "Install boot11strap");
	sf2d_end_frame(); 
	
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
			sftd_draw_text(font, 42, 162,  RGBA8(255, 195,   0,   255), 20, "View changelog");
	sf2d_end_frame(); 
	
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
			sftd_draw_text(font, 5, 220,  RGBA8(255, 0,   0,   255), 10, "Created by Kingy34 (20/1/18) - Version 1.0 (Source)");
	sf2d_end_frame(); 
	
	sf2d_swapbuffers();
	
	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();


		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break;
	}
	
	gfxExit();
	aptExit();
	fsExit();
	sftd_free_font(font);
	sf2d_free_texture(tex1);
	sf2d_free_texture(tex2);
	sf2d_free_texture(tex3);
	sftd_fini();
	sf2d_fini();
	return 0;
	
}