/*****************************************************************************
* Filename:          D:\work\lprs2\2013_2014\Resene_vezbe\lab56\basic_system/drivers/vga_periph_mem_v1_00_a/src/vga_periph_mem.c
* Version:           1.00.a
* Description:       vga_periph_mem Driver Source File
* Date:              Wed Mar 05 10:25:21 2014 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "vga_periph_mem.h"
#define BRZINA 20000

Xuint32 cursor_position;
/************************** Function Definitions ***************************/

void set_cursor(Xuint32 new_value){
	cursor_position = new_value;
}


void print_char(Xuint32 BaseAddress, unsigned char c, int lenght){


	VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + cursor_position, lenght);

}

void print_string(Xuint32 BaseAddress, unsigned char string_s[], int lenght){
	int i;
	for (i = 0; i < lenght; i++){
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + cursor_position + i*4, (string_s[i]-0x40));
	}
}

void clear_text_screen(Xuint32 BaseAddress){
	int i;
	for (i = 0; i < 4800; i++){
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + i*4, 0x20);
	}
}


void clear_graphics_screen(Xuint32 BaseAddress){
	int i;
	for (i = 0; i < 9600; i++){
	    VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
	}
}

void clear_screen(Xuint32 BaseAddress){
	int i;
	for (i = 0; i < 4800; i++){
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + i*4, 0x20);
	}
	for (i = 0; i < 9600; i++){
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
	}
}

void set_forground_color(Xuint32 BaseAddress, int colour){
	VGA_PERIPH_MEM_mWriteMemory(BaseAddress, colour);


}

void set_background_color(Xuint32 BaseAddress, int colour){
	VGA_PERIPH_MEM_mWriteMemory(BaseAddress, colour);


}

void set_font_size(Xuint32 BaseAddress, int font){
	VGA_PERIPH_MEM_mWriteMemory(BaseAddress, font);


}

void draw_square(Xuint32 BaseAddress){
	int i, j, k;
		for (j = 0; j < 480; j++){
			for (k = 0; k<(640/32); k++){
				i = j*(640/32) + k;
				if ((j > 200) && (j < 280) && (k > 8) && (k < 12)) {
					VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
				}
				else{
					VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
				}
			}
		}
}

void draw_square2(Xuint32 BaseAddress){
	int i, j, k;
	int x,y;
	x = -1;
	y = 3;
	int br = 0;

T:	while(1){
		br++;
		if(br %BRZINA == 0){
			br = 0;
			for (j = 0; j < 480; j++){
				for (k = 0; k<(640/32); k++){
					i = j*(640/32) + k;
					if ((j > 200) && (j < 280) && (k > x) && (k < y)) {
						VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);

					}
					else{
						VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
					}
				}

			}
			if(x < 16){
				x++;
				y++;
			}else{
				break;
			}
		}
	}
	while(1){
		br++;
		if(br %BRZINA == 0){
			for (j = 0; j < 480; j++){
				for (k = 0; k<(640/32); k++){
					i = j*(640/32) + k;
					if ((j > 200) && (j < 280) && (k > x) && (k < y)) {
						VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);

					}
					else{
						VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
					}
				}

			}
			if(x >= 0){
						x--;
						y--;
			}else{
						break;
			}
		}
	}
	goto T;



}

void draw_rectangle(Xuint32 BaseAddress){
	int i, j, k;
		for (j = 0; j < 480; j++){
			for (k = 0; k<(640/32); k++){
				i = j*(640/32) + k;
				if ((j > 100) && (j < 180) && (k > 5) && (k < 11)) {
					VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
				}
				else{
					VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
				}
			}
		}
}

void draw_smt(Xuint32 BaseAddress){
	int i, j, k;
			for (j = 0; j < 480; j++){
				for (k = 0; k<(640/32); k++){
					i = j*(640/32) + k;
					if ((j > 100) && (j < 280)  /*(k > 5) && (k < 11)*/) {
						if(j > 100 && j < 120){
							if(k >8 && k < 10){
								VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
							}
						}else if(j >= 120 && j < 140){
							if(k >7 && k < 11){
									VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
							}

						}else if(j >= 140 && j < 160){
							if(k >6 && k < 12){
									VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
							}
						}else if(j >= 160 && j < 180){
							if(k >5 && k < 13){
									VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
							}

						}else if(j >= 180 && j < 200){
							if(k >4 && k < 14){
								VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
							}
						}else if(j >= 200 && j < 220){
							if(k >5 && k < 13){
								VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
							}
						}else if(j >= 220 && j < 240){
							if(k >6 && k < 12){
								VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
							}
						}else if(j >= 240 && j < 260){
							if(k >7 && k < 11){
								VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
							}
						}else if(j >= 260 && j < 280){
							if(k >8 && k < 10){
								VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
							}
						}else{
							VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
						}



					}

				}
			}
}

int get_resolution(Xuint32 BaseAddress){
	int i = 0;
	int kraj_ekrana = 0;

	while(i != kraj_ekrana ){
		i++;
	}
	return i;
}































