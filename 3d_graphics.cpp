// 3d_graphics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <memory.h>
#include <time.h>
#include <math.h>
typedef struct {
	int color;
	char value;

}Pixel;

typedef struct {
	int color;
	char value;

}Space;

#define L 64
#define H 36

#define framerate 60

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void delayFrame();
void mapDisplay(Pixel*px);
void emptyFill(Pixel* px);
void drawLine(Pixel* px, int x0, int x1, int y0, int y1);
void mapLine(Pixel* px, double fi, int x, int y, int b);
void sphereMap(Space* sp, int R);
int main() {
	Pixel* px = (Pixel*)malloc(sizeof(Pixel)* L * H);
	Space* sp = (Space*)malloc(sizeof(Space)*L*H*L);
	emptyFill(px);
	double x = 0;
	drawLine(px,2, 10, 5, 10);	
	sphereMap(sp, 5);
	while (1) {
		//mapLine(px,x/5, 0, 0, 0);
		mapDisplay(px);
		delayFrame();
		system("CLS");
		x++;
	}


}


void mapDisplay(Pixel * px) {
	for (int j = 0; j < H; j++) {
		for (int i = 0; i < L; i++) {
			SetConsoleTextAttribute(hStdOut, px[i + j * L].color);
			printf("%c ", px[i + j*L].value);
		}
		printf("\n");
	}

}
void emptyFill(Pixel* px){
	for (int j = 0; j < H; j++) {
		for (int i = 0; i < L; i++) {
			px[i + j * L].color = 1;
			px[i + j * L].value = ' ';
		
		}
	}

}
void delayFrame() {
	time_t seconds;
	seconds = time(NULL);

	while (time(NULL) < seconds + 1);

}


void drawLine(Pixel* px, int x0, int x1, int y0, int y1) {

	// x-x0 / x1-x0

	for(int j = 0 ; j < H; j++){
		for (int i = 0; i < L; i++) {
			if (float((i - x0) / (x1 - x0)) == float((j - y0) / (y1 - y0))) {
				px[i + j*L].value = '*';
				px[i + j * L].color = 3;
			}

		}
	
	}


}
void mapLine(Pixel* px, double fi, int x, int y, int b) {
	double cosine = fi;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < L; j++) {
			if ( i == (double)(j) / cosine) {
				px[j + i * L].value = '*';
				px[j + i * L].color = i/12 % 12+1;
			}

		}
	}
}

void projectSpace(Space* sp, Pixel* px) {



}
void sphereMap(Space* sp, int R) {
	for (int j = 0; j < H; j++) {
		for (int i = 0; i < L; i++){
			for (int m = 0; m < L; m++) {
				if (pow(i, 2) + pow(j, 2) + pow(m, 2) == pow(R, 2)) {
					sp[m + i * (H * L) + j * H].value = '*';
					sp[m + i * (H * L) + j * H].color = 3;
				}
			}

		}
	}


};


