/*
 * bmp.h
 *
 *  Created on: 14.11.2016
 *      Author: Manuel Scholz
 *
 *      Diese Datei enthält alle Infos zu einer BMP Datei
 */

#ifndef BMP_H_
#define BMP_H_

typedef struct tagRGBTRIPLE {
	unsigned char rgbtBlue;
	unsigned char rgbtGreen;
	unsigned char rgbtRed;
} RGBTRIPLE;

typedef struct tagRGBQUAD {
	unsigned char rgbBlue;
	unsigned char rgbGreen;
	unsigned char rgbRed;
	unsigned char rgbReserved;
} RGBQUAD;

typedef char CHAR;
typedef short SHORT;
typedef long LONG;
typedef unsigned long DWORD;
typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;

typedef struct tagBITMAPFILEHEADER {
	WORD bfType;
	DWORD bfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

/*
 wobei
 bfType: Specifies the file type, must be BM (0x4d42).
 bfSize: Specifies the size, in bytes, of the bitmap file.
 bfReserved1: Reserved; must be zero.
 bfReserved2: Reserved; must be zero.
 bfOffBits: Specifies the offset, in bytes, from the beginning of the
 BITMAPFILEHEADER structure to the bitmap bits.

 */

typedef struct tagBITMAPINFOHEADER {
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

/*
 wobei
 biSize: Specifies the number of bytes required by the structure (==40).
 biWidth:Specifies the width of the bitmap, in pixels.
 biHeight: Specifies the height of the bitmap, in pixels.
 biPlanes: Specifies the number of planes for the target device. This value
 must be set to 1.
 biBitCount: Specifies the number of bits-per-pixel. The biBitCount member of
 the BITMAPINFOHEADER structure determines the number of bits that define
 each pixel and the maximum number of colors in the bitmap. This member
 must be one of the following values.

 Value Meaning
 8 The bitmap has a maximum of 256 colors, and the bmiColors
 member of BITMAPINFO contains up to 256 entries. In this case,
 each byte in the array represents a single pixel.
 24 The bitmap has a maximum of 2^24 colors, and the bmiColors
 member of BITMAPINFO is NULL. Each 3-byte triplet in the bitmap
 array represents the relative intensities of blue, green, and red,
 respectively, for a pixel.

 biCompression: Specifies the type of compression for a compressed bottomup
 bitmap (top-down DIBs cannot be compressed). This member can be one
 of the following values.
 Value Meaning
 BI_RGB
 (=0)
 An uncompressed format.
 BI_RLE8
 (=1)
 A run-length encoded (RLE) format for bitmaps with 8 bpp. The
 compression format is a 2-byte format consisting of a count byte
 followed by a byte containing a color index. For more information,
 see Bitmap Compression.


 biSizeImage: Specifies the size, in bytes, of the image. This may be set to
 zero for BI_RGB bitmaps.
 biXPelsPerMeter: Specifies the horizontal resolution, in pixels-per-meter, of
 the target device for the bitmap. An application can use this value to select a
 bitmap from a resource group that best matches the characteristics of the
 current device.
 biYPelsPerMeter: Specifies the vertical resolution, in pixels-per-meter, of the
 target device for the bitmap

 biClrUsed: Specifies the number of color indexes in the color table that are
 actually used by the bitmap. If this value is zero, the bitmap uses the
 maximum number of colors corresponding to the value of the biBitCount
 member for the compression mode specified by biCompression.
 biClrImportant: Specifies the number of color indexes that are required for
 displaying the bitmap. If this value is zero, all colors are required.

 */

#endif /* BMP_H_ */
