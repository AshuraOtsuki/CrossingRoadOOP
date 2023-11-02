internal void
clear_screen(u32 color) {
	unsigned int* pixel = (u32*)render_state.memory;
	for (int y = 0; y < render_state.height; y++) {
		for (int x = 0; x < render_state.width; x++) {
			*pixel++ = color;
		}
	}
}


internal void
draw_rect_in_pixels(int x0, int y0, int x1, int y1, u32 color) {
	
	x0 = clamp(0, x0, render_state.width);
	x1 = clamp(0, x1, render_state.width);
	y0 = clamp(0, y0, render_state.height);
	y1 = clamp(0, y1, render_state.height);

	for (int y = y0; y < y1; y++) {
		u32* pixel = (u32*)render_state.memory + x0 + y*render_state.width;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}
	}
}

global_variable float render_scale = 0.01f;

internal void
draw_arena_borders(float arena_x, float arena_y, u32 color) {
	arena_x *= render_state.height * render_scale;
	arena_y *= render_state.height * render_scale;

	int x0 = (int)((float)render_state.width * .5f - arena_x);
	int x1 = (int)((float)render_state.width * .5f + arena_x);
	int y0 = (int)((float)render_state.height * .5f - arena_y);
	int y1 = (int)((float)render_state.height * .5f + arena_y);

	draw_rect_in_pixels(0, 0, render_state.width, y0, color);
	draw_rect_in_pixels(0, y1, x1, render_state.height, color);
	draw_rect_in_pixels(0, y0, x0, y1, color);
	draw_rect_in_pixels(x1, y0, render_state.width, render_state.height, color);
}
internal void
draw_headtrain(int x, int y, int size)//chieu cao: 28, chieu rong 33
{
	
	int tempx = x;
	int tempy = y;
	//layer 1
	tempx += 15 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 17, tempy + size, 0x000000);
	//layer 2
	tempy -= size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx+size, tempy, tempx + size * 16, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx+size*16, tempy, tempx + size * 17, tempy + size, 0x000000);
	//layer 3:
	tempx += size;
	tempy -= size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx+size, tempy, tempx + size * 2, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x032966);
	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 12, tempy + size, 0x0252d4);
	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 13, tempy + size, 0x032966);
	draw_rect_in_pixels(tempx + size*13, tempy, tempx + size * 14, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x000000);
	//layer 4:
	tempy -= size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx + size, tempy, tempx + size * 2, tempy + size, 0xA9A9A9);//
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x0252d4);//

	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 4, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 5, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 5, tempy, tempx + size * 6, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 8, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 8, tempy, tempx + size * 10, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 10, tempy, tempx + size * 11, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 11, tempy, tempx + size * 12, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 13, tempy + size, 0x032966);
	
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x000000);
	//layer 5:
	tempx = x + 16 * size;
	tempy -= size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx + size, tempy, tempx + size * 2, tempy + size, 0xA9A9A9);//
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x0252d4);//

	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 4, tempy + size, 0x4383e8);//
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 5, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 5, tempy, tempx + size * 7, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 7, tempy, tempx + size * 9, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 9, tempy, tempx + size * 10, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 10, tempy, tempx + size * 11, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 11, tempy, tempx + size * 12, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 13, tempy + size, 0x032966);
	
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x000000);
	tempx = x + 5 * size;
	draw_rect_in_pixels(tempx , tempy, tempx + size * 3, tempy + size, 0x000000);
	//layer 6
	tempy -= size;
	tempx = x + 4 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx+size, tempy, tempx + size * 3, tempy + size, 0xFA8072);
	draw_rect_in_pixels(tempx + size*3, tempy, tempx + size * 4, tempy + size, 0xFF0000);
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 5, tempy + size, 0x000000);
	tempx += size * 12;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx + size, tempy, tempx + size * 2, tempy + size, 0xA9A9A9);//
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x0252d4);//
	
	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 4, tempy + size, 0x7eabf2);//
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 6, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 8, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 8, tempy, tempx + size * 9, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 9, tempy, tempx + size * 10, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 10, tempy, tempx + size * 12, tempy + size, 0x4383e8);

	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 13, tempy + size, 0x032966);

	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x000000);
	//layer 7
	tempy -= size;
	tempx = x + 4 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx+size, tempy, tempx + size * 2, tempy + size, 0xFA8072);
	draw_rect_in_pixels(tempx + size*2, tempy, tempx + size * 4, tempy + size, 0xFF0000);
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 5, tempy + size, 0x000000);
	tempx += size * 12;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx + size, tempy, tempx + size * 2, tempy + size, 0x696969);//
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x0252d4);//

	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 5, tempy + size, 0x4383e8);//
	draw_rect_in_pixels(tempx + size * 5, tempy, tempx + size * 7, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 7, tempy, tempx + size * 8, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 8, tempy, tempx + size * 9, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 9, tempy, tempx + size * 11, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 11, tempy, tempx + size * 12, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 13, tempy + size, 0x032966);

	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x000000);
	//layer 8
	tempy -= size;
	tempx = x + 4 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 4, tempy + size, 0xFF0000);
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 5, tempy + size, 0x000000);
	tempx += size * 12;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx + size, tempy, tempx + size * 2, tempy + size, 0xA9A9A9);//
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x0252d4);//

	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 4, tempy + size, 0x4383e8);//
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 6, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 7, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 7, tempy, tempx + size * 8, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 8, tempy, tempx + size * 10, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 10, tempy, tempx + size * 12, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 13, tempy + size, 0x032966);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x000000);
	//layer 9
	tempy -= size;
	tempx = x + 5 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xFF0000);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x000000);
	tempx += 11 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 3, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size, tempy, tempx + size * 2, tempy + size, 0x696969);//
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x0252d4);//

	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 5, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 5, tempy, tempx + size * 6, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 7, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 7, tempy, tempx + size * 9, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 9, tempy, tempx + size * 12, tempy + size, 0x7eabf2);

	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 13, tempy + size, 0x0252d4);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x000000);
	//layer 10
	tempy -= size;
	tempx = x + 5 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x000000);
	tempx += 11 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 3, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size, tempy, tempx + size * 2, tempy + size, 0x696969);//
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x0252d4);//
	
	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 4, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 5, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 5, tempy, tempx + size * 6, tempy + size, 0x7eabf2);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 8, tempy + size, 0x4383e8);
	draw_rect_in_pixels(tempx + size * 8, tempy, tempx + size * 12, tempy + size, 0x7eabf2);

	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 13, tempy + size, 0x0252d4);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x000000);
	//layer 11
	tempy -= size;
	tempx = x + 5 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);//
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x000000);
	tempx += 11 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 3, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size, tempy, tempx + size * 2, tempy + size, 0x696969);//
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x032966);//
	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 12, tempy + size, 0x0252d4);//
	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 13, tempy + size, 0x0252d4);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x000000);
	//layer 12
	tempy -= size;
	tempx = x + 4 * size;
	draw_rect_in_pixels(tempx , tempy, tempx + size * 12, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 26, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 26, tempy, tempx + size * 27, tempy + size, 0x000000);
	//layer 13
	tempy -= size;
	tempx = x + 2* size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 2, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx +size*2, tempy, tempx + size * 7, tempy + size, 0xCDCDCD);
	draw_rect_in_pixels(tempx + size * 7, tempy, tempx + size * 8, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 8, tempy, tempx + size * 9, tempy + size, 0xCDCDCD);
	draw_rect_in_pixels(tempx + size * 9, tempy, tempx + size * 12, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 12, tempy, tempx + size * 13, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 17, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 26, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 26, tempy, tempx + size * 28, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 28, tempy, tempx + size * 29, tempy + size, 0x000000);
	//14
	tempy -= size;
	tempx = x +  size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xFF0000);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x463E3F);

	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 14, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 15, tempy, tempx + size * 17, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 18, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 18, tempy, tempx + size * 27, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 27, tempy, tempx + size * 28, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 28, tempy, tempx + size * 29, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 29, tempy, tempx + size * 30, tempy + size, 0x000000);

	//15
	tempy -= size;
	tempx = x + size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xFF0000);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x463E3F);

	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 14, tempy + size, 0x808080);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 15, tempy, tempx + size * 17, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 18, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 18, tempy, tempx + size * 27, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 27, tempy, tempx + size * 28, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 28, tempy, tempx + size * 29, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 29, tempy, tempx + size * 30, tempy + size, 0x000000);

	
	//16
	tempy -= size;
	tempx = x + size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xFF0000);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x463E3F);

	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 14, tempy + size, 0x808080);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 15, tempy, tempx + size * 17, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 18, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 18, tempy, tempx + size * 22, tempy + size, 0x696969);//
	draw_rect_in_pixels(tempx + size * 22, tempy, tempx + size * 27, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 27, tempy, tempx + size * 28, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 28, tempy, tempx + size * 29, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 29, tempy, tempx + size * 30, tempy + size, 0x000000);
	//17
	tempy -= size;
	tempx = x + size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xFF0000);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x463E3F);

	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 14, tempy + size, 0x808080);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 15, tempy, tempx + size * 17, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 18, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 18, tempy, tempx + size * 21, tempy + size, 0x696969);//
	draw_rect_in_pixels(tempx + size * 21, tempy, tempx + size * 22, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 22, tempy, tempx + size * 27, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 27, tempy, tempx + size * 29, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 29, tempy, tempx + size * 30, tempy + size, 0x000000);
	//18
	tempy -= size;
	tempx = x + size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xFF0000);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0x463E3F);

	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 14, tempy + size, 0x808080);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 15, tempy, tempx + size * 17, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 18, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 18, tempy, tempx + size * 21, tempy + size, 0xA9A9A9);//
	draw_rect_in_pixels(tempx + size * 21, tempy, tempx + size * 22, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 22, tempy, tempx + size * 29, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 29, tempy, tempx + size * 30, tempy + size, 0x000000);
	//19
	tempy -= size;
	tempx = x + 2*size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 13, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 16, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 16, tempy, tempx + size * 17, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 20, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 20, tempy, tempx + size * 22, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 22, tempy, tempx + size * 28, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 28, tempy, tempx + size * 29, tempy + size, 0x000000);

	//20
	tempy -= size;
	tempx = x + 2 * size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 21, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 21, tempy, tempx + size * 22, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 22, tempy, tempx + size * 28, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 28, tempy, tempx + size * 29, tempy + size, 0x000000);
	//21
	tempy -= size;
	tempx = x + size;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 6, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 9, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 9, tempy, tempx + size * 13, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 16, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 16, tempy, tempx + size * 20, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 20, tempy, tempx + size * 21, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 21, tempy, tempx + size * 22, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 22, tempy, tempx + size * 24, tempy + size, 0xFFFACD);

	draw_rect_in_pixels(tempx + size * 24, tempy, tempx + size * 28, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 28, tempy, tempx + size * 30, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 30, tempy, tempx + size * 31, tempy + size, 0x000000);
	//22
	tempy -= size;
	tempx = x ;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 7, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 7, tempy, tempx + size * 8, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 8, tempy, tempx + size * 9, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 9, tempy, tempx + size * 10, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 10, tempy, tempx + size * 14, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 15, tempy, tempx + size * 16, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 16, tempy, tempx + size * 17, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 21, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 21, tempy, tempx + size * 22, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 22, tempy, tempx + size * 24, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 24, tempy, tempx + size * 25, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 25, tempy, tempx + size * 29, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 29, tempy, tempx + size * 30, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 30, tempy, tempx + size * 32, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 32, tempy, tempx + size * 33, tempy + size, 0x000000);
	//23 
	tempy -= size;
	tempx = x;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 4, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 6, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 8, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 8, tempy, tempx + size * 9, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 9, tempy, tempx + size * 11, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 11, tempy, tempx + size * 13, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 15, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 15, tempy, tempx + size * 16, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 16, tempy, tempx + size * 18, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 18, tempy, tempx + size * 20, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 20, tempy, tempx + size * 21, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 21, tempy, tempx + size * 22, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 22, tempy, tempx + size * 23, tempy + size, 0xFFFACD);

	draw_rect_in_pixels(tempx + size * 23, tempy, tempx + size * 24, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 24, tempy, tempx + size * 26, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 26, tempy, tempx + size * 28, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 28, tempy, tempx + size * 30, tempy + size, 0x696969);

	draw_rect_in_pixels(tempx + size * 30, tempy, tempx + size *31, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 31, tempy, tempx + size * 32, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 32, tempy, tempx + size * 33, tempy + size, 0x000000);
	//24
	tempy -= size;
	tempx = x;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 4, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 6, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 7, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 7, tempy, tempx + size * 10, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 10, tempy, tempx + size * 11, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 11, tempy, tempx + size * 13, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x000000);

	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 17, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 18, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 18, tempy, tempx + size * 20, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 20, tempy, tempx + size * 21, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 21, tempy, tempx + size * 23, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 23, tempy, tempx + size * 24, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 24, tempy, tempx + size * 25, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 25, tempy, tempx + size * 29, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 29, tempy, tempx + size * 30, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 30, tempy, tempx + size * 32, tempy + size, 0x000000);

	//25
	tempy -= size;
	tempx = x;
	draw_rect_in_pixels(tempx, tempy, tempx + size * 1, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 1, tempy, tempx + size * 2, tempy + size, 0xFFFACD);
	draw_rect_in_pixels(tempx + size * 2, tempy, tempx + size * 3, tempy + size, 0xfcba03);
	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 4, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 6, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 7, tempy + size, 0x696969);

	draw_rect_in_pixels(tempx + size * 7, tempy, tempx + size * 8, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 8, tempy, tempx + size * 9, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 9, tempy, tempx + size * 10, tempy + size, 0x463E3F);

	draw_rect_in_pixels(tempx + size * 10, tempy, tempx + size * 11, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 11, tempy, tempx + size * 13, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x696969);

	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 15, tempy, tempx + size * 16, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 16, tempy, tempx + size * 17, tempy + size, 0x463E3F);

	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 18, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 18, tempy, tempx + size * 20, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 20, tempy, tempx + size * 21, tempy + size, 0x696969);

	draw_rect_in_pixels(tempx + size * 21, tempy, tempx + size * 22, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 22, tempy, tempx + size * 23, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 23, tempy, tempx + size * 24, tempy + size, 0x463E3F);
	draw_rect_in_pixels(tempx + size * 24, tempy, tempx + size * 25, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 25, tempy, tempx + size * 29, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 29, tempy, tempx + size * 30, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 30, tempy, tempx + size * 31, tempy + size, 0x000000);
	//26
	tempy -= size;
	tempx = x;
	draw_rect_in_pixels(tempx+size, tempy, tempx + size * 3, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 4, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 6, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 7, tempy + size, 0x696969);

	draw_rect_in_pixels(tempx + size * 7, tempy, tempx + size * 8, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 9, tempy, tempx + size * 10, tempy + size, 0x000000);

	draw_rect_in_pixels(tempx + size * 10, tempy, tempx + size * 11, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 11, tempy, tempx + size * 13, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x696969);

	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 15, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 16, tempy, tempx + size * 17, tempy + size, 0x000000);

	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 18, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 18, tempy, tempx + size * 20, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx +  size * 20, tempy, tempx + size * 21, tempy + size, 0x696969);

	draw_rect_in_pixels(tempx + size * 21, tempy, tempx + size * 22, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 23, tempy, tempx + size * 24, tempy + size, 0x000000);

	draw_rect_in_pixels(tempx + size * 24, tempy, tempx + size * 26, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 26, tempy, tempx + size * 28, tempy + size, 0xA9A9A9);
	draw_rect_in_pixels(tempx + size * 28, tempy, tempx + size * 30, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 30, tempy, tempx + size * 31, tempy + size, 0x000000);
	//27
	tempy -= size;
	tempx = x;
	
	draw_rect_in_pixels(tempx + size * 3, tempy, tempx + size * 4, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 4, tempy, tempx + size * 6, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 6, tempy, tempx + size * 7, tempy + size, 0x000000);
	
	draw_rect_in_pixels(tempx + size * 10, tempy, tempx + size * 11, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 11, tempy, tempx + size * 13, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 13, tempy, tempx + size * 14, tempy + size, 0x000000);

	draw_rect_in_pixels(tempx + size * 17, tempy, tempx + size * 18, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 18, tempy, tempx + size * 20, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 20, tempy, tempx + size * 21, tempy + size, 0x000000);

	draw_rect_in_pixels(tempx + size * 24, tempy, tempx + size * 25, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 25, tempy, tempx + size * 29, tempy + size, 0x696969);
	draw_rect_in_pixels(tempx + size * 29, tempy, tempx + size * 30, tempy + size, 0x000000);

	//28
	tempy -= size;
	tempx = x+size*4;

	draw_rect_in_pixels(tempx , tempy, tempx + size * 2, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx +size*7, tempy, tempx + size * 9, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 14, tempy, tempx + size * 16, tempy + size, 0x000000);
	draw_rect_in_pixels(tempx + size * 21, tempy, tempx + size * 25, tempy + size, 0x000000);

}
void draw_bat(int x, int y, int size)
{
	int a = x, b = y;
	//1
	draw_rect_in_pixels(a, b, a + 10, b + 5, 0x000000);
	draw_rect_in_pixels(a + 25, b, a + 35, b + 5, 0x000000);

	//2	
	draw_rect_in_pixels(x - 5, y - 5, x + 5, y, 0x000000);
	draw_rect_in_pixels(x + 30, y - 5, x + 40, y, 0x000000);

	//3
	draw_rect_in_pixels(x - 10, y - 10, x + 5, y - 5, 0x000000);
	draw_rect_in_pixels(x + 30, y - 10, x + 45, y - 5, 0x000000);

	//4
	draw_rect_in_pixels(x - 15, y - 15, x - 5, y - 10, 0x000000);
	draw_rect_in_pixels(x - 5, y - 15, x, y - 10, 0xff0000);
	draw_rect_in_pixels(x, y - 15, x + 5, y - 10, 0x000000);
	draw_rect_in_pixels(x + 10, y - 15, x + 15, y - 10, 0x000000);
	draw_rect_in_pixels(x + 20, y - 15, x + 25, y - 10, 0x000000);
	draw_rect_in_pixels(x + 30, y - 15, x + 35, y - 10, 0x000000);
	draw_rect_in_pixels(x + 35, y - 15, x + 40, y - 10, 0xff0000);
	draw_rect_in_pixels(x + 40, y - 15, x + 50, y - 10, 0x000000);

	//5
	draw_rect_in_pixels(x - 15, y - 20, x + 5, y - 15, 0x000000);
	draw_rect_in_pixels(x - 10, y - 20, x, y - 15, 0xff0000);
	draw_rect_in_pixels(x, y - 20, x + 20, y - 15, 0x000000);
	draw_rect_in_pixels(x + 10, y - 20, x + 15, y - 15, 0xffff00);
	draw_rect_in_pixels(x + 15, y - 20, x + 20, y - 15, 0x000000);
	draw_rect_in_pixels(x + 20, y - 20, x + 25, y - 15, 0xffff00);
	draw_rect_in_pixels(x + 25, y - 20, x + 35, y - 15, 0x000000);
	draw_rect_in_pixels(x + 35, y - 20, x + 45, y - 15, 0xff0000);
	draw_rect_in_pixels(x + 45, y - 20, x + 50, y - 15, 0x000000);

	//6
	draw_rect_in_pixels(x - 20, y - 25, x - 10, y - 20, 0x000000);
	draw_rect_in_pixels(x - 10, y - 25, x, y - 20, 0xff0000);
	draw_rect_in_pixels(x, y - 25, x + 35, y - 20, 0x000000);
	draw_rect_in_pixels(x + 35, y - 25, x + 45, y - 20, 0xff0000);
	draw_rect_in_pixels(x + 45, y - 25, x + 55, y - 20, 0x000000);

	//7
	draw_rect_in_pixels(x - 20, y - 30, x - 15, y - 25, 0x000000);
	draw_rect_in_pixels(x - 15, y - 30, x, y - 25, 0xff0000);
	draw_rect_in_pixels(x, y - 30, x + 5, y - 25, 0x000000);
	draw_rect_in_pixels(x + 5, y - 30, x + 10, y - 25, 0xff0000);
	draw_rect_in_pixels(x + 10, y - 30, x + 25, y - 25, 0x000000);
	draw_rect_in_pixels(x + 25, y - 30, x + 30, y - 25, 0xff0000);
	draw_rect_in_pixels(x + 30, y - 30, x + 35, y - 25, 0x000000);
	draw_rect_in_pixels(x + 35, y - 30, x + 50, y - 25, 0xff0000);
	draw_rect_in_pixels(x + 50, y - 30, x + 55, y - 25, 0x000000);

	//8
	draw_rect_in_pixels(x - 20, y - 35, x - 15, y - 30, 0x000000);
	draw_rect_in_pixels(x - 15, y - 35, x - 10, y - 30, 0xff0000);
	draw_rect_in_pixels(x - 5, y - 35, x, y - 30, 0xff0000);
	draw_rect_in_pixels(x, y - 35, x + 5, y - 30, 0x000000);
	draw_rect_in_pixels(x + 10, y - 35, x + 25, y - 30, 0x000000);
	draw_rect_in_pixels(x + 30, y - 35, x + 35, y - 30, 0x000000);
	draw_rect_in_pixels(x + 35, y - 35, x + 40, y - 30, 0xff0000);
	draw_rect_in_pixels(x + 45, y - 35, x + 50, y - 30, 0xff0000);
	draw_rect_in_pixels(x + 50, y - 35, x + 55, y - 30, 0x000000);

	//9
	draw_rect_in_pixels(x - 20, y - 40, x - 15, y - 35, 0x000000);
	draw_rect_in_pixels(x - 15, y - 40, x - 10, y - 35, 0xff0000);
	draw_rect_in_pixels(x, y - 40, x + 5, y - 35, 0x000000);
	draw_rect_in_pixels(x + 15, y - 40, x + 20, y - 35, 0x000000);
	draw_rect_in_pixels(x + 30, y - 40, x + 35, y - 35, 0x000000);
	draw_rect_in_pixels(x + 45, y - 40, x + 50, y - 35, 0xff0000);
	draw_rect_in_pixels(x + 50, y - 40, x + 55, y - 35, 0x000000);

	//10
	draw_rect_in_pixels(x - 20, y - 45, x - 15, y - 40, 0x000000);
	draw_rect_in_pixels(x + 50, y - 45, x + 55, y - 40, 0x000000);
}

void draw_dragon(int x, int y, int size) {
	int a = x;
	int b = y;

	//1 + 2
	a = x + 3 * 5;
	draw_rect_in_pixels(a, b, a + 3, b + 6, 0x000000);
	draw_rect_in_pixels(a + 16 * 3, b, a + 16 * 3 + 3, b + 6, 0x000000);

	//3
	a = x + 3 * 4;
	b = y - 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 9, b + 3, 0x000000);
	draw_rect_in_pixels(a + 18, b, a + 21, b + 3, 0x000000);
	draw_rect_in_pixels(a + 36, b, a + 39, b + 3, 0x000000);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0x000000);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 54, b, a + 57, b + 3, 0x000000);

	//4
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 9, b + 3, 0x000000);
	draw_rect_in_pixels(a + 15, b, a + 18, b + 3, 0x000000);
	draw_rect_in_pixels(a + 18, b, a + 21, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 21, b, a + 24, b + 3, 0x000000);
	draw_rect_in_pixels(a + 33, b, a + 36, b + 3, 0x000000);
	draw_rect_in_pixels(a + 36, b, a + 39, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 39, b, a + 42, b + 3, 0x000000);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0x000000);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 54, b, a + 57, b + 3, 0x000000);

	//5
	a = x + 3 * 3;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 9, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 9, b, a + 12, b + 3, 0x000000);
	draw_rect_in_pixels(a + 18, b, a + 21, b + 3, 0x000000);
	draw_rect_in_pixels(a + 21, b, a + 24, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 24, b, a + 27, b + 3, 0x000000);
	draw_rect_in_pixels(a + 36, b, a + 39, b + 3, 0x000000);
	draw_rect_in_pixels(a + 39, b, a + 42, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 42, b, a + 45, b + 3, 0x000000);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0x000000);
	draw_rect_in_pixels(a + 54, b, a + 60, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 60, b, a + 63, b + 3, 0x000000);

	//6
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 12, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0x000000);
	draw_rect_in_pixels(a + 18, b, a + 21, b + 3, 0x000000);
	draw_rect_in_pixels(a + 21, b, a + 24, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 24, b, a + 27, b + 3, 0x000000);
	draw_rect_in_pixels(a + 36, b, a + 39, b + 3, 0x000000);
	draw_rect_in_pixels(a + 39, b, a + 42, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 42, b, a + 45, b + 3, 0x000000);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0x000000);
	draw_rect_in_pixels(a + 51, b, a + 60, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 60, b, a + 63, b + 3, 0x000000);

	//7
	a = x + 3 * 2;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 12, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 9, b, a + 12, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 15, b, a + 18, b + 3, 0x000000);
	draw_rect_in_pixels(a + 21, b, a + 24, b + 3, 0x000000);
	draw_rect_in_pixels(a + 24, b, a + 30, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 30, b, a + 39, b + 3, 0x000000);
	draw_rect_in_pixels(a + 39, b, a + 45, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 45, b, a + 48, b + 3, 0x000000);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0x000000);
	draw_rect_in_pixels(a + 54, b, a + 57, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 57, b, a + 60, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 60, b, a + 66, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 66, b, a + 69, b + 3, 0x000000);

	//8
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 12, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 15, b, a + 18, b + 3, 0x000000);
	draw_rect_in_pixels(a + 21, b, a + 24, b + 3, 0x000000);
	draw_rect_in_pixels(a + 24, b, a + 45, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 45, b, a + 48, b + 3, 0x000000);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0x000000);
	draw_rect_in_pixels(a + 54, b, a + 57, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 57, b, a + 63, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 63, b, a + 66, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 66, b, a + 69, b + 3, 0x000000);

	//9
	a = x + 3;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 18, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 18, b, a + 21, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 21, b, a + 24, b + 3, 0x000000);
	draw_rect_in_pixels(a + 24, b, a + 51, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0x000000);
	draw_rect_in_pixels(a + 54, b, a + 57, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 57, b, a + 66, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 66, b, a + 72, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 72, b, a + 75, b + 3, 0x000000);

	//10
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 21, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 21, b, a + 24, b + 3, 0x000000);
	draw_rect_in_pixels(a + 24, b, a + 27, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 27, b, a + 30, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 30, b, a + 45, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 45, b, a + 48, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0x000000);
	draw_rect_in_pixels(a + 54, b, a + 69, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 69, b, a + 72, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 72, b, a + 75, b + 3, 0x000000);

	//11
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 21, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 21, b, a + 24, b + 3, 0x000000);
	draw_rect_in_pixels(a + 24, b, a + 27, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 27, b, a + 30, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 30, b, a + 33, b + 3, 0x000000);
	draw_rect_in_pixels(a + 33, b, a + 42, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 42, b, a + 45, b + 3, 0x000000);
	draw_rect_in_pixels(a + 45, b, a + 48, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0x000000);
	draw_rect_in_pixels(a + 54, b, a + 69, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 69, b, a + 72, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 72, b, a + 75, b + 3, 0x000000);

	//12
	a = x;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 27, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 27, b, a + 30, b + 3, 0x000000);
	draw_rect_in_pixels(a + 30, b, a + 51, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0x000000);
	draw_rect_in_pixels(a + 54, b, a + 75, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 75, b, a + 78, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 78, b, a + 81, b + 3, 0x000000);

	//13
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 15, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 15, b, a + 18, b + 3, 0x000000);
	draw_rect_in_pixels(a + 18, b, a + 30, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 30, b, a + 33, b + 3, 0x000000);
	draw_rect_in_pixels(a + 33, b, a + 48, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0x000000);
	draw_rect_in_pixels(a + 51, b, a + 63, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 63, b, a + 66, b + 3, 0x000000);
	draw_rect_in_pixels(a + 66, b, a + 75, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 75, b, a + 78, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 78, b, a + 81, b + 3, 0x000000);

	//14
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 12, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0x000000);
	draw_rect_in_pixels(a + 15, b, a + 18, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 18, b, a + 24, b + 3, 0x000000);
	draw_rect_in_pixels(a + 24, b, a + 30, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 30, b, a + 33, b + 3, 0x000000);
	draw_rect_in_pixels(a + 33, b, a + 48, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0x000000);
	draw_rect_in_pixels(a + 51, b, a + 57, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 57, b, a + 63, b + 3, 0x000000);
	draw_rect_in_pixels(a + 63, b, a + 66, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 66, b, a + 69, b + 3, 0x000000);
	draw_rect_in_pixels(a + 69, b, a + 75, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 75, b, a + 78, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 78, b, a + 81, b + 3, 0x000000);

	//15
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 12, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0x000000);
	draw_rect_in_pixels(a + 15, b, a + 18, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 18, b, a + 21, b + 3, 0x000000);
	draw_rect_in_pixels(a + 21, b, a + 24, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 24, b, a + 33, b + 3, 0x000000);
	draw_rect_in_pixels(a + 33, b, a + 36, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 36, b, a + 45, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 45, b, a + 48, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 48, b, a + 57, b + 3, 0x000000);
	draw_rect_in_pixels(a + 57, b, a + 60, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 60, b, a + 63, b + 3, 0x000000);
	draw_rect_in_pixels(a + 63, b, a + 66, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 66, b, a + 69, b + 3, 0x000000);
	draw_rect_in_pixels(a + 69, b, a + 75, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 75, b, a + 78, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 78, b, a + 81, b + 3, 0x000000);

	//16
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 9, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 9, b, a + 12, b + 3, 0x000000);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 15, b, a + 24, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 24, b, a + 27, b + 3, 0x000000);
	draw_rect_in_pixels(a + 27, b, a + 33, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 33, b, a + 36, b + 3, 0x000000);
	draw_rect_in_pixels(a + 36, b, a + 45, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 45, b, a + 48, b + 3, 0x000000);
	draw_rect_in_pixels(a + 48, b, a + 54, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 54, b, a + 57, b + 3, 0x000000);
	draw_rect_in_pixels(a + 57, b, a + 66, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 66, b, a + 69, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 69, b, a + 72, b + 3, 0x000000);
	draw_rect_in_pixels(a + 72, b, a + 75, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 75, b, a + 78, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 78, b, a + 81, b + 3, 0x000000);

	//17
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 9, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 9, b, a + 12, b + 3, 0x000000);
	draw_rect_in_pixels(a + 12, b, a + 24, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 24, b, a + 27, b + 3, 0x000000);
	draw_rect_in_pixels(a + 27, b, a + 36, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 36, b, a + 45, b + 3, 0x000000);
	draw_rect_in_pixels(a + 45, b, a + 54, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 54, b, a + 57, b + 3, 0x000000);
	draw_rect_in_pixels(a + 57, b, a + 69, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 69, b, a + 72, b + 3, 0x000000);
	draw_rect_in_pixels(a + 72, b, a + 75, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 75, b, a + 78, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 78, b, a + 81, b + 3, 0x000000);

	//18
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 12, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0x000000);
	draw_rect_in_pixels(a + 15, b, a + 21, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 21, b, a + 24, b + 3, 0x000000);
	draw_rect_in_pixels(a + 24, b, a + 57, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 57, b, a + 60, b + 3, 0x000000);
	draw_rect_in_pixels(a + 60, b, a + 66, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 66, b, a + 69, b + 3, 0x000000);
	draw_rect_in_pixels(a + 69, b, a + 75, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 75, b, a + 78, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 78, b, a + 81, b + 3, 0x000000);

	//19
	a = x + 3;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 12, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 12, b, a + 18, b + 3, 0x000000);
	draw_rect_in_pixels(a + 18, b, a + 24, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 24, b, a + 27, b + 3, 0x000000);
	draw_rect_in_pixels(a + 27, b, a + 48, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0x000000);
	draw_rect_in_pixels(a + 51, b, a + 57, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 57, b, a + 63, b + 3, 0x000000);
	draw_rect_in_pixels(a + 63, b, a + 69, b + 3, 0x0099ff);
	draw_rect_in_pixels(a + 69, b, a + 72, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 72, b, a + 75, b + 3, 0x000000);

	//20
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 6, b, a + 12, b + 3, 0x000000);
	draw_rect_in_pixels(a + 15, b, a + 24, b + 3, 0x000000);
	draw_rect_in_pixels(a + 24, b, a + 30, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 30, b, a + 45, b + 3, 0xffff66);
	draw_rect_in_pixels(a + 45, b, a + 51, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 51, b, a + 60, b + 3, 0x000000);
	draw_rect_in_pixels(a + 63, b, a + 69, b + 3, 0x000000);
	draw_rect_in_pixels(a + 69, b, a + 72, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 72, b, a + 75, b + 3, 0x000000);

	//21
	a = x + 3 * 3;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 9, b, a + 12, b + 3, 0x000000);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 15, b, a + 18, b + 3, 0x000000);
	draw_rect_in_pixels(a + 18, b, a + 21, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 21, b, a + 42, b + 3, 0xffff66);
	draw_rect_in_pixels(a + 42, b, a + 45, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 45, b, a + 48, b + 3, 0x000000);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0x000000);
	draw_rect_in_pixels(a + 60, b, a + 63, b + 3, 0x000000);

	//22
	a = x + 3 * 5;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 9, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 9, b, a + 12, b + 3, 0x000000);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 15, b, a + 36, b + 3, 0xffff66);
	draw_rect_in_pixels(a + 36, b, a + 39, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 39, b, a + 42, b + 3, 0x000000);
	draw_rect_in_pixels(a + 42, b, a + 48, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0x000000);

	//23
	a = x + 3 * 5;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 12, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0x000000);
	draw_rect_in_pixels(a + 15, b, a + 36, b + 3, 0xffff66);
	draw_rect_in_pixels(a + 36, b, a + 39, b + 3, 0x000000);
	draw_rect_in_pixels(a + 39, b, a + 48, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0x000000);

	//24
	a = x + 3 * 5;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 15, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 15, b, a + 18, b + 3, 0x000000);
	draw_rect_in_pixels(a + 18, b, a + 33, b + 3, 0xffff66);
	draw_rect_in_pixels(a + 33, b, a + 36, b + 3, 0x000000);
	draw_rect_in_pixels(a + 36, b, a + 48, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0x000000);

	//25
	a = x + 3 * 4;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 18, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 18, b, a + 39, b + 3, 0x000000);
	draw_rect_in_pixels(a + 39, b, a + 54, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 54, b, a + 57, b + 3, 0x000000);

	//26
	b = -3;
	draw_rect_in_pixels(a, b, a + 3, b + 3, 0x000000);
	draw_rect_in_pixels(a + 3, b, a + 6, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 6, b, a + 9, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 9, b, a + 12, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 12, b, a + 15, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 15, b, a + 18, b + 3, 0x000000);
	draw_rect_in_pixels(a + 18, b, a + 42, b + 3, 0x000000);
	draw_rect_in_pixels(a + 42, b, a + 45, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 45, b, a + 48, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 48, b, a + 51, b + 3, 0xcc3333);
	draw_rect_in_pixels(a + 51, b, a + 54, b + 3, 0xffffff);
	draw_rect_in_pixels(a + 54, b, a + 57, b + 3, 0x000000);

	//27
	a = x + 3 * 5;
	b -= 3;
	draw_rect_in_pixels(a, b, a + 12, b + 3, 0x000000);
	draw_rect_in_pixels(a + 18, b, a + 39, b + 3, 0x000000);
	draw_rect_in_pixels(a + 69, b, a + 81, b + 3, 0x000000);
}

void draw_penguin(int x, int y, int size) {
	int a, b = y;
	//1 
	a = x + size * 3;
	draw_rect_in_pixels(a, b, a + 8 * size, b + size, 0x000000);

	//2
	a = x + size * 2;
	b -= size;
	draw_rect_in_pixels(a, b, a + 10 * size, b + size, 0x000000);

	//3
	a = x + size;
	b -= size;
	draw_rect_in_pixels(a, b, a + 12 * size, b + size, 0x000000);

	//4 
	a = x;
	b -= size;
	draw_rect_in_pixels(a, b, a + 7 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 7 * size, b, a + 12 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 12 * size, b, a + 14 * size, b + size, 0x000000);

	//5
	b -= size;
	draw_rect_in_pixels(a, b, a + 6 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 6 * size, b, a + 13 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 13 * size, b, a + 14 * size, b + size, 0x000000);

	//6
	b -= size;
	draw_rect_in_pixels(a, b, a + 6 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 6 * size, b, a + 14 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 14 * size, b, a + 15 * size, b + size, 0x000000);

	//7
	b -= size;
	draw_rect_in_pixels(a, b, a + 6 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 6 * size, b, a + 7 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 7 * size, b, a + 9 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 9 * size, b, a + 13 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 13 * size, b, a + 15 * size, b + size, 0x000000);

	//8
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 6 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 6 * size, b, a + 8 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 8 * size, b, a + 9 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 9 * size, b, a + 10 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 10 * size, b, a + 12 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 12 * size, b, a + 14 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 14 * size, b, a + 15 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 15 * size, b, a + 16 * size, b + size, 0x000000);

	//9
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 6 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 6 * size, b, a + 10 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 10 * size, b, a + 12 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 12 * size, b, a + 16 * size, b + size, 0x000000);

	//10
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 7 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 7 * size, b, a + 9 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 9 * size, b, a + 11 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 11 * size, b, a + 13 * size, b + size, 0xffff00);
	draw_rect_in_pixels(a + 13 * size, b, a + 15 * size, b + size, 0x000000);

	//11
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 10 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 10 * size, b, a + 15 * size, b + size, 0xffff00);

	//12
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 11 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 11 * size, b, a + 17 * size, b + size, 0xffff00);

	//13
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 14 * size, b + size, 0xffffff);

	//14
	b -= size;
	draw_rect_in_pixels(a, b, a + 6 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 6 * size, b, a + 14 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 14 * size, b, a + 15 * size, b + size, 0x000000);

	//15
	b -= size;
	draw_rect_in_pixels(a, b, a + 7 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 7 * size, b, a + 14 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 14 * size, b, a + 16 * size, b + size, 0x000000);

	//16
	b -= size;
	draw_rect_in_pixels(a, b, a + 8 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 8 * size, b, a + 14 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 14 * size, b, a + 17 * size, b + size, 0x000000);

	//17
	b -= size;
	draw_rect_in_pixels(a, b, a + 9 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 9 * size, b, a + 14 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 14 * size, b, a + 18 * size, b + size, 0x000000);

	//18
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 6 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 6 * size, b, a + 9 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 9 * size, b, a + 14 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 14 * size, b, a + 18 * size, b + size, 0x000000);

	//19, 20
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + 2 * size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 14 * size, b + 2 * size, 0xffffff);
	draw_rect_in_pixels(a + 14 * size, b, a + 15 * size, b + 2 * size, 0x000000);

	//21, 22
	b -= 2 * size;
	draw_rect_in_pixels(a, b, a + 4 * size, b + 2 * size, 0x000000);
	draw_rect_in_pixels(a + 4 * size, b, a + 14 * size, b + 2 * size, 0xffffff);
	draw_rect_in_pixels(a + 14 * size, b, a + 15 * size, b + 2 * size, 0x000000);

	//23
	b -= size;
	draw_rect_in_pixels(a, b, a + 2 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 2 * size, b, a + 13 * size, b + size, 0xffffff);
	draw_rect_in_pixels(a + 13 * size, b, a + 14 * size, b + size, 0x000000);

	//24
	b -= size;
	a = x + size;
	draw_rect_in_pixels(a, b, a + 12 * size, b + size, 0x000000);

	//25
	a = x + 3 * size;
	b -= size;
	draw_rect_in_pixels(a, b, a + size, b + size, 0xcccc33);
	draw_rect_in_pixels(a + 8 * size, b, a + 9 * size, b + size, 0xcccc33);

	//26
	a = x + 2 * size;
	b -= size;
	draw_rect_in_pixels(a, b, a + 4 * size, b + size, 0xcccc33);
	draw_rect_in_pixels(a + 8 * size, b, a + 12 * size, b + size, 0xcccc33);
}

void draw_car(int x, int y, int size) {
	int a, b = y;
	//1 
	a = x + size * 19;
	draw_rect_in_pixels(a, b, a + 9 * size, b + size, 0x000000);

	//2
	a = x + size * 18;
	b -= size;
	draw_rect_in_pixels(a, b, a + size, b + size, 0x000000);
	draw_rect_in_pixels(a + size, b, a + 10 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 10 * size, b, a + 13 * size, b + size, 0x000000);

	//3
	a = x + size * 17;
	b -= size;
	draw_rect_in_pixels(a, b, a + 11 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 11 * size, b, a + 14 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 14 * size, b, a + 16 * size, b + size, 0x000000);

	//4
	a = x + size * 16;
	b -= size;
	draw_rect_in_pixels(a, b, a + size, b + size, 0x000000);
	draw_rect_in_pixels(a + size, b, a + 12 * size, b + size, 0x33cc00);
	draw_rect_in_pixels(a + 12 * size, b, a + 15 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 15 * size, b, a + 17 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 17 * size, b, a + 19 * size, b + size, 0x000000);

	//5
	a = x + 11 * size;
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 6 * size, b + size, 0x33cc00);
	draw_rect_in_pixels(a + 6 * size, b, a + 15 * size, b + size, 0x99ff99);
	draw_rect_in_pixels(a + 15 * size, b, a + 20 * size, b + size, 0x33cc00);
	draw_rect_in_pixels(a + 20 * size, b, a + 22 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 22 * size, b, a + 24 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 24 * size, b, a + 26 * size, b + size, 0x000000);

	//6
	a = x + 6 * size;
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 9 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 9 * size, b, a + 34 * size, b + size, 0x000000);

	//7 
	a = x + 3 * size;
	b -= size;
	draw_rect_in_pixels(a, b, a + 3 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 3 * size, b, a + 13 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 13 * size, b, a + 14 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 14 * size, b, a + 24 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 24 * size, b, a + 25 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 25 * size, b, a + 37 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 37 * size, b, a + 41 * size, b + size, 0x000000);

	//8
	a = x + size;
	b -= size;
	draw_rect_in_pixels(a, b, a + 2 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 2 * size, b, a + 5 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 5 * size, b, a + 12 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 12 * size, b, a + 14 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 14 * size, b, a + 15 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 15 * size, b, a + 16 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 16 * size, b, a + 23 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 23 * size, b, a + 25 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 25 * size, b, a + 26 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 26 * size, b, a + 27 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 27 * size, b, a + 40 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 40 * size, b, a + 41 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 41 * size, b, a + 42 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 42 * size, b, a + 43 * size, b + size, 0x000000);

	//9
	a = x;
	b -= size;
	draw_rect_in_pixels(a, b, a + size, b + size, 0x000000);
	draw_rect_in_pixels(a + size, b, a + 2 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 2 * size, b, a + 3 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 3 * size, b, a + 7 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 7 * size, b, a + 10 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 10 * size, b, a + 16 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 16 * size, b, a + 17 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 17 * size, b, a + 27 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 27 * size, b, a + 28 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 28 * size, b, a + 31 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 31 * size, b, a + 34 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 34 * size, b, a + 42 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 42 * size, b, a + 44 * size, b + size, 0x000000);

	//10
	a = x + size;
	b -= size;
	draw_rect_in_pixels(a, b, a + size, b + size, 0x000000);
	draw_rect_in_pixels(a + size, b, a + 3 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 3 * size, b, a + 5 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 5 * size, b, a + 6 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 6 * size, b, a + 9 * size, b + size, 0x993399);
	draw_rect_in_pixels(a + 9 * size, b, a + 10 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 10 * size, b, a + 15 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 15 * size, b, a + 16 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 16 * size, b, a + 26 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 26 * size, b, a + 27 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 27 * size, b, a + 29 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 29 * size, b, a + 30 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 30 * size, b, a + 33 * size, b + size, 0x993399);
	draw_rect_in_pixels(a + 33 * size, b, a + 34 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 34 * size, b, a + 36 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 36 * size, b, a + 41 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 41 * size, b, a + 42 * size, b + size, 0x000000);

	//11
	a = x;
	b -= size;
	draw_rect_in_pixels(a, b, a + 3 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 3 * size, b, a + 5 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 5 * size, b, a + 6 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 6 * size, b, a + 7 * size, b + size, 0x993399);
	draw_rect_in_pixels(a + 7 * size, b, a + 10 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 10 * size, b, a + 11 * size, b + size, 0x993399);
	draw_rect_in_pixels(a + 11 * size, b, a + 12 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 12 * size, b, a + 16 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 16 * size, b, a + 17 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 17 * size, b, a + 27 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 27 * size, b, a + 28 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 28 * size, b, a + 29 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 29 * size, b, a + 30 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 30 * size, b, a + 31 * size, b + size, 0x993399);
	draw_rect_in_pixels(a + 31 * size, b, a + 34 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 34 * size, b, a + 35 * size, b + size, 0x993399);
	draw_rect_in_pixels(a + 35 * size, b, a + 36 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 36 * size, b, a + 38 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 38 * size, b, a + 44 * size, b + size, 0x000000);

	//12
	b -= size;
	draw_rect_in_pixels(a, b, a + size, b + size, 0x000000);
	draw_rect_in_pixels(a + size, b, a + 2 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 2 * size, b, a + 3 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 3 * size, b, a + 4 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 4 * size, b, a + 5 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 5 * size, b, a + 6 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 6 * size, b, a + 7 * size, b + size, 0x993399);
	draw_rect_in_pixels(a + 7 * size, b, a + 8 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 8 * size, b, a + 9 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 9 * size, b, a + 10 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 10 * size, b, a + 11 * size, b + size, 0x660066);
	draw_rect_in_pixels(a + 11 * size, b, a + 12 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 12 * size, b, a + 16 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 16 * size, b, a + 17 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 17 * size, b, a + 27 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 27 * size, b, a + 28 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 28 * size, b, a + 29 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 29 * size, b, a + 30 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 30 * size, b, a + 31 * size, b + size, 0x993399);
	draw_rect_in_pixels(a + 31 * size, b, a + 32 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 32 * size, b, a + 33 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 33 * size, b, a + 34 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 34 * size, b, a + 35 * size, b + size, 0x660066);
	draw_rect_in_pixels(a + 35 * size, b, a + 36 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 36 * size, b, a + 37 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 37 * size, b, a + 38 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 38 * size, b, a + 40 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 40 * size, b, a + 42 * size, b + size, 0xc0c0c0);
	draw_rect_in_pixels(a + 42 * size, b, a + 43 * size, b + size, 0x999999);
	draw_rect_in_pixels(a + 43 * size, b, a + 44 * size, b + size, 0x000000);

	//13
	a = x + size;
	b -= size;
	draw_rect_in_pixels(a, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 5 * size, b, a + 6 * size, b + size, 0x660066);
	draw_rect_in_pixels(a + 6 * size, b, a + 9 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 9 * size, b, a + 10 * size, b + size, 0x660066);
	draw_rect_in_pixels(a + 10 * size, b, a + 29 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 29 * size, b, a + 30 * size, b + size, 0x660066);
	draw_rect_in_pixels(a + 30 * size, b, a + 33 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 33 * size, b, a + 34 * size, b + size, 0x660066);
	draw_rect_in_pixels(a + 34 * size, b, a + 42 * size, b + size, 0x000000);

	//14
	a = x + 6 * size;
	b -= size;
	draw_rect_in_pixels(a, b, a + size, b + size, 0x000000);
	draw_rect_in_pixels(a + size, b, a + 4 * size, b + size, 0x660066);
	draw_rect_in_pixels(a + 4 * size, b, a + 5 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 24 * size, b, a + 25 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 25 * size, b, a + 28 * size, b + size, 0x660066);
	draw_rect_in_pixels(a + 28 * size, b, a + 29 * size, b + size, 0x000000);

	//15
	a = x + 7 * size;
	b -= size;
	draw_rect_in_pixels(a, b, a + 3 * size, b + size, 0x000000);
	draw_rect_in_pixels(a + 24 * size, b, a + 27 * size, b + size, 0x000000);
}
internal void
draw_rect(float x, float y, float half_size_x, float half_size_y, u32 color, int chan) {

	x *= render_state.height*render_scale;
	y *= render_state.height * render_scale;
	half_size_x *= render_state.height * render_scale;
	half_size_y *= render_state.height * render_scale;

	x += render_state.width / 2.f;
	y += render_state.height / 2.f;

	// Change to pixels
	int x0 = x - half_size_x;
	int x1 = x + half_size_x+chan;
	int y0 = y - half_size_y;
	int y1 = y + half_size_y+chan;

	draw_rect_in_pixels(x0, y0, x1, y1, color);
}

const char* letters[][7] = {
    " 00",
    "0  0",
    "0  0",
    "0000",
    "0  0",
    "0  0",
    "0  0",

	"000",
	"0  0",
	"0  0",
	"000",
	"0  0",
	"0  0",
	"000",

	" 000",
	"0",
	"0",
	"0",
	"0",
	"0",
	" 000",

	"000",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"000",

	"0000",
	"0",
	"0",
	"000",
	"0",
	"0",
	"0000",

	"0000",
	"0",
	"0",
	"000",
	"0",
	"0",
	"0",

	" 000",
	"0",
	"0",
	"0 00",
	"0  0",
	"0  0",
	" 000",

	"0  0",
	"0  0",
	"0  0",
	"0000",
	"0  0",
	"0  0",
	"0  0",

	"000",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",
	"000",

	" 000",
	"   0",
	"   0",
	"   0",
	"0  0",
	"0  0",
	" 000",

	"0  0",
	"0  0",
	"0 0",
	"00",
	"0 0",
	"0  0",
	"0  0",

	"0",
	"0",
	"0",
	"0",
	"0",
	"0",
	"0000",

	"00 00",
	"0 0 0",
	"0 0 0",
	"0   0",
	"0   0",
	"0   0",
	"0   0",

	"00  0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0  00",

	"0000",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0000",

	" 000",
	"0  0",
	"0  0",
	"000",
	"0",
	"0",
	"0",

	" 000 ",
	"0   0",
	"0   0",
	"0   0",
	"0 0 0",
	"0  0 ",
	" 00 0",

	"000",
	"0  0",
	"0  0",
	"000",
	"0  0",
	"0  0",
	"0  0",

	" 000",
	"0",
	"0 ",
	" 00",
	"   0",
	"   0",
	"000 ",

	"000",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",

	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	" 00",

	"0   0",
	"0   0",
	"0   0",
	"0   0",
	"0   0",
	" 0 0",
	"  0",

	"0   0 ",
	"0   0",
	"0   0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	" 0 0 ",

	"0   0",
	"0   0",
	" 0 0",
	"  0",
	" 0 0",
	"0   0",
	"0   0",

	"0   0",
	"0   0",
	" 0 0",
	"  0",
	"  0",
	"  0",
	"  0",

	"0000",
	"   0",
	"  0",
	" 0",
	"0",
	"0",
	"0000",

	"",
	"",
	"",
	"",
	"",
	"",
	"0",

	"   0",
	"  0",
	"  0",
	" 0",
	" 0",
	"0",
	"0",
};

internal void
draw_text(const char *text, float x, float y, float size, u32 color) {
	float half_size = size * .5f;
	float original_y = y;

	while (*text) {
		if (*text != 32) {
			const char** letter;
			if (*text == 47) letter = letters[27];
			else if (*text == 46) letter = letters[26];
			else letter = letters[*text - 'A'];
			float original_x = x;

			for (int i = 0; i < 7; i++) {
				const char* row = letter[i];
				while (*row) {
					if (*row == '0') {
						draw_rect(x, y, half_size, half_size, color, 0);
					}
					x += size;
					row++;
				}
				y -= size;
				x = original_x;
			}
		}
		text++;
		x += size * 6.f;
		y = original_y;
	}
}

internal void
draw_number(int number, float x, float y, float size, u32 color) {
	float half_size = size * .5f;

	bool drew_number = false;
	while (number || !drew_number) {
		drew_number = true;

		int digit = number % 10;
		number = number / 10;

		switch (digit) {
		case 0: {
			draw_rect(x - size, y, half_size, 2.5f * size, color, 0);
			draw_rect(x + size, y, half_size, 2.5f * size, color, 0);
			draw_rect(x, y + size * 2.f, half_size, half_size, color, 0);
			draw_rect(x, y - size * 2.f, half_size, half_size, color, 0);
			x -= size * 4.f;
		} break;

		case 1: {
			draw_rect(x + size, y, half_size, 2.5f * size, color, 0);
			x -= size * 2.f;
		} break;

		case 2: {
			draw_rect(x, y + size * 2.f, 1.5f * size, half_size, color, 0);
			draw_rect(x, y, 1.5f * size, half_size, color, 0);
			draw_rect(x, y - size * 2.f, 1.5f * size, half_size, color, 0);
			draw_rect(x + size, y + size, half_size, half_size, color, 0);
			draw_rect(x - size, y - size, half_size, half_size, color, 0);
			x -= size * 4.f;
		} break;

		case 3: {
			draw_rect(x - half_size, y + size * 2.f, size, half_size, color,0);
			draw_rect(x - half_size, y, size, half_size, color,0);
			draw_rect(x - half_size, y - size * 2.f, size, half_size, color,0);
			draw_rect(x + size, y, half_size, 2.5f * size, color,0);
			x -= size * 4.f;
		} break;

		case 4: {
			draw_rect(x + size, y, half_size, 2.5f * size, color,0);
			draw_rect(x - size, y + size, half_size, 1.5f * size, color,0);
			draw_rect(x, y, half_size, half_size, color,0);
			x -= size * 4.f;
		} break;

		case 5: {
			draw_rect(x, y + size * 2.f, 1.5f * size, half_size, color,0);
			draw_rect(x, y, 1.5f * size, half_size, color,0);
			draw_rect(x, y - size * 2.f, 1.5f * size, half_size, color,0);
			draw_rect(x - size, y + size, half_size, half_size, color,0);
			draw_rect(x + size, y - size, half_size, half_size, color,0);
			x -= size * 4.f;
		} break;

		case 6: {
			draw_rect(x + half_size, y + size * 2.f, size, half_size, color,0);
			draw_rect(x + half_size, y, size, half_size, color,0);
			draw_rect(x + half_size, y - size * 2.f, size, half_size, color,0);
			draw_rect(x - size, y, half_size, 2.5f * size, color,0);
			draw_rect(x + size, y - size, half_size, half_size, color,0);
			x -= size * 4.f;
		} break;

		case 7: {
			draw_rect(x + size, y, half_size, 2.5f * size, color,0);
			draw_rect(x - half_size, y + size * 2.f, size, half_size, color,0);
			x -= size * 4.f;
		} break;

		case 8: {
			draw_rect(x - size, y, half_size, 2.5f * size, color,0);
			draw_rect(x + size, y, half_size, 2.5f * size, color,0);
			draw_rect(x, y + size * 2.f, half_size, half_size, color,0);
			draw_rect(x, y - size * 2.f, half_size, half_size, color,0);
			draw_rect(x, y, half_size, half_size, color,0);
			x -= size * 4.f;
		} break;

		case 9: {
			draw_rect(x - half_size, y + size * 2.f, size, half_size, color,0);
			draw_rect(x - half_size, y, size, half_size, color,0);
			draw_rect(x - half_size, y - size * 2.f, size, half_size, color,0);
			draw_rect(x + size, y, half_size, 2.5f * size, color,0);
			draw_rect(x - size, y + size, half_size, half_size, color,0);
			x -= size * 4.f;
		} break;
		}

	}
}
