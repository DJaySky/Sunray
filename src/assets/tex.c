/*
 * Various textures used throughout the game, and some helper functions
 * See tex.h for documentation
 * 2025 Aethari
 */

#include <stdio.h>
#include <stdlib.h>

#include "util/log.h"
#include "assets/tex.h"

// textures
int empty_tex[TEX_HEIGHT][TEX_WIDTH] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

int brick_tex[TEX_HEIGHT][TEX_WIDTH] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0},
	{0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0},
	{0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0}
};

int debug_tex[TEX_HEIGHT][TEX_WIDTH] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// functions
Color tex_get_pix(int (*tex)[TEX_WIDTH], int x, int y) {
	if(
		x < TEX_WIDTH &&
		x >= 0 &&
		y < TEX_HEIGHT &&
		y >= 0
	) {
		return (Color)tex[y][x];
	} else {
		char *log_path = log_get_path();

		char msg[1000];
		char buff[] = "[ C ] [WARNING] Texture coordinate (%d, %d) out of bounds in tex_get_pix()\n";
		sprintf(msg, buff, x, y);

		log_pwrite(log_path, msg);

		free(log_path);
		return BLACK;
	}
}
