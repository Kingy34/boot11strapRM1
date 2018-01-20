#include <string.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <sf2d.h>
#include <sfil.h>
#include <sftd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	gfxInitDefault();
	consoleInit(GFX_BOTTOM, NULL); 
	aptInit();
  	fsInit();
	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
	sf2d_set_vblank_wait(0);
	sftd_init();
	hidInit();

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();


		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break;

		// Flush and swap frame-buffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}

	gfxExit();
	return 0;
}