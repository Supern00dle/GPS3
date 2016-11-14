/*
 * import.c
 *
 *  Created on: 14.11.2016
 *      Author: manue
 *
 *      Diese Datei liest BMP Dateien ein und legt sie auf den HEAP
 */

#include <stdio.h>
#include "import.h"
#include "bmp.h"

void init(void) {
	//TODO: Init stuff

}

int import(void) {

	char path[] = "aufgabe3_bild1.bmp";

	FILE* bmppointer;
	unsigned char *bitmapImage;
	int imageIdx = 0;
	unsigned char tempRGB;
	BITMAPFILEHEADER bitmapFileHeader;

	bmppointer = fopen(path, 'rb');

	if (bmppointer == 0)
		return 0;

	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, bmppointer);

	if (bitmapFileHeader.bfType != 0x4D42) {
		fclose(bmppointer);
		return 0;
	}

	//read the bitmap info header
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

	fclose(bmppointer);
}
