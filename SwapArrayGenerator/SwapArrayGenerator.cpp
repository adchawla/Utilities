
#include <stdio.h>
#include <conio.h>

#define PRIVATE static

PRIVATE unsigned char pixelSwapLut1bpp[256]=
{
  0x00,0x80,0x40,0xc0,0x20,0xa0,0x60,0xe0,    /* 0x00-0x07 */
  0x10,0x90,0x50,0xd0,0x30,0xb0,0x70,0xf0,    /* 0x08-0x0f */
  0x08,0x88,0x48,0xc8,0x28,0xa8,0x68,0xe8,    /* 0x10-0x17 */
  0x18,0x98,0x58,0xd8,0x38,0xb8,0x78,0xf8,    /* 0x18-0x1f */
  0x04,0x84,0x44,0xc4,0x24,0xa4,0x64,0xe4,    /* 0x20-0x27 */
  0x14,0x94,0x54,0xd4,0x34,0xb4,0x74,0xf4,    /* 0x28-0x2f */
  0x0c,0x8c,0x4c,0xcc,0x2c,0xac,0x6c,0xec,    /* 0x30-0x37 */
  0x1c,0x9c,0x5c,0xdc,0x3c,0xbc,0x7c,0xfc,    /* 0x38-0x3f */
  0x02,0x82,0x42,0xc2,0x22,0xa2,0x62,0xe2,    /* 0x40-0x47 */
  0x12,0x92,0x52,0xd2,0x32,0xb2,0x72,0xf2,    /* 0x48-0x4f */
  0x0a,0x8a,0x4a,0xca,0x2a,0xaa,0x6a,0xea,    /* 0x50-0x57 */
  0x1a,0x9a,0x5a,0xda,0x3a,0xba,0x7a,0xfa,    /* 0x58-0x5f */
  0x06,0x86,0x46,0xc6,0x26,0xa6,0x66,0xe6,    /* 0x60-0x67 */
  0x16,0x96,0x56,0xd6,0x36,0xb6,0x76,0xf6,    /* 0x68-0x6f */
  0x0e,0x8e,0x4e,0xce,0x2e,0xae,0x6e,0xee,    /* 0x70-0x77 */
  0x1e,0x9e,0x5e,0xde,0x3e,0xbe,0x7e,0xfe,    /* 0x78-0x7f */
  0x01,0x81,0x41,0xc1,0x21,0xa1,0x61,0xe1,    /* 0x80-0x87 */
  0x11,0x91,0x51,0xd1,0x31,0xb1,0x71,0xf1,    /* 0x88-0x8f */
  0x09,0x89,0x49,0xc9,0x29,0xa9,0x69,0xe9,    /* 0x90-0x97 */
  0x19,0x99,0x59,0xd9,0x39,0xb9,0x79,0xf9,    /* 0x98-0x9f */
  0x05,0x85,0x45,0xc5,0x25,0xa5,0x65,0xe5,    /* 0xa0-0xa7 */
  0x15,0x95,0x55,0xd5,0x35,0xb5,0x75,0xf5,    /* 0xa8-0xaf */
  0x0d,0x8d,0x4d,0xcd,0x2d,0xad,0x6d,0xed,    /* 0xb0-0xb7 */
  0x1d,0x9d,0x5d,0xdd,0x3d,0xbd,0x7d,0xfd,    /* 0xb8-0xbf */
  0x03,0x83,0x43,0xc3,0x23,0xa3,0x63,0xe3,    /* 0xc0-0xc7 */
  0x13,0x93,0x53,0xd3,0x33,0xb3,0x73,0xf3,    /* 0xc8-0xcf */
  0x0b,0x8b,0x4b,0xcb,0x2b,0xab,0x6b,0xeb,    /* 0xd0-0xd7 */
  0x1b,0x9b,0x5b,0xdb,0x3b,0xbb,0x7b,0xfb,    /* 0xd8-0xdf */
  0x07,0x87,0x47,0xc7,0x27,0xa7,0x67,0xe7,    /* 0xe0-0xe7 */
  0x17,0x97,0x57,0xd7,0x37,0xb7,0x77,0xf7,    /* 0xe8-0xef */
  0x0f,0x8f,0x4f,0xcf,0x2f,0xaf,0x6f,0xef,    /* 0xf0-0xf7 */
  0x1f,0x9f,0x5f,0xdf,0x3f,0xbf,0x7f,0xff,    /* 0xf8-0xff */
};
 
PRIVATE unsigned char pixelSwapLut2bpp[256]=
{
  0x00,0x40,0x80,0xc0,0x10,0x50,0x90,0xd0,    /* 0x00-0x07 */
  0x20,0x60,0xa0,0xe0,0x30,0x70,0xb0,0xf0,    /* 0x08-0x0f */
  0x04,0x44,0x84,0xc4,0x14,0x54,0x94,0xd4,    /* 0x10-0x17 */
  0x24,0x64,0xa4,0xe4,0x34,0x74,0xb4,0xf4,    /* 0x18-0x1f */
  0x08,0x48,0x88,0xc8,0x18,0x58,0x98,0xd8,    /* 0x20-0x27 */
  0x28,0x68,0xa8,0xe8,0x38,0x78,0xb8,0xf8,    /* 0x28-0x2f */
  0x0c,0x4c,0x8c,0xcc,0x1c,0x5c,0x9c,0xdc,    /* 0x30-0x37 */
  0x2c,0x6c,0xac,0xec,0x3c,0x7c,0xbc,0xfc,    /* 0x38-0x3f */
  0x01,0x41,0x81,0xc1,0x11,0x51,0x91,0xd1,    /* 0x40-0x47 */
  0x21,0x61,0xa1,0xe1,0x31,0x71,0xb1,0xf1,    /* 0x48-0x4f */
  0x05,0x45,0x85,0xc5,0x15,0x55,0x95,0xd5,    /* 0x50-0x57 */
  0x25,0x65,0xa5,0xe5,0x35,0x75,0xb5,0xf5,    /* 0x58-0x5f */
  0x09,0x49,0x89,0xc9,0x19,0x59,0x99,0xd9,    /* 0x60-0x67 */
  0x29,0x69,0xa9,0xe9,0x39,0x79,0xb9,0xf9,    /* 0x68-0x6f */
  0x0d,0x4d,0x8d,0xcd,0x1d,0x5d,0x9d,0xdd,    /* 0x70-0x77 */
  0x2d,0x6d,0xad,0xed,0x3d,0x7d,0xbd,0xfd,    /* 0x78-0x7f */
  0x02,0x42,0x82,0xc2,0x12,0x52,0x92,0xd2,    /* 0x80-0x87 */
  0x22,0x62,0xa2,0xe2,0x32,0x72,0xb2,0xf2,    /* 0x88-0x8f */
  0x06,0x46,0x86,0xc6,0x16,0x56,0x96,0xd6,    /* 0x90-0x97 */
  0x26,0x66,0xa6,0xe6,0x36,0x76,0xb6,0xf6,    /* 0x98-0x9f */
  0x0a,0x4a,0x8a,0xca,0x1a,0x5a,0x9a,0xda,    /* 0xa0-0xa7 */
  0x2a,0x6a,0xaa,0xea,0x3a,0x7a,0xba,0xfa,    /* 0xa8-0xaf */
  0x0e,0x4e,0x8e,0xce,0x1e,0x5e,0x9e,0xde,    /* 0xb0-0xb7 */
  0x2e,0x6e,0xae,0xee,0x3e,0x7e,0xbe,0xfe,    /* 0xb8-0xbf */
  0x03,0x43,0x83,0xc3,0x13,0x53,0x93,0xd3,    /* 0xc0-0xc7 */
  0x23,0x63,0xa3,0xe3,0x33,0x73,0xb3,0xf3,    /* 0xc8-0xcf */
  0x07,0x47,0x87,0xc7,0x17,0x57,0x97,0xd7,    /* 0xd0-0xd7 */
  0x27,0x67,0xa7,0xe7,0x37,0x77,0xb7,0xf7,    /* 0xd8-0xdf */
  0x0b,0x4b,0x8b,0xcb,0x1b,0x5b,0x9b,0xdb,    /* 0xe0-0xe7 */
  0x2b,0x6b,0xab,0xeb,0x3b,0x7b,0xbb,0xfb,    /* 0xe8-0xef */
  0x0f,0x4f,0x8f,0xcf,0x1f,0x5f,0x9f,0xdf,    /* 0xf0-0xf7 */
  0x2f,0x6f,0xaf,0xef,0x3f,0x7f,0xbf,0xff,    /* 0xf8-0xff */
};
 
PRIVATE unsigned char pixelSwapLut4bpp[256]=
{
  0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,    /* 0x00-0x07 */
  0x80,0x90,0xa0,0xb0,0xc0,0xd0,0xe0,0xf0,    /* 0x08-0x0f */
  0x01,0x11,0x21,0x31,0x41,0x51,0x61,0x71,    /* 0x10-0x17 */
  0x81,0x91,0xa1,0xb1,0xc1,0xd1,0xe1,0xf1,    /* 0x18-0x1f */
  0x02,0x12,0x22,0x32,0x42,0x52,0x62,0x72,    /* 0x20-0x27 */
  0x82,0x92,0xa2,0xb2,0xc2,0xd2,0xe2,0xf2,    /* 0x28-0x2f */
  0x03,0x13,0x23,0x33,0x43,0x53,0x63,0x73,    /* 0x30-0x37 */
  0x83,0x93,0xa3,0xb3,0xc3,0xd3,0xe3,0xf3,    /* 0x38-0x3f */
  0x04,0x14,0x24,0x34,0x44,0x54,0x64,0x74,    /* 0x40-0x47 */
  0x84,0x94,0xa4,0xb4,0xc4,0xd4,0xe4,0xf4,    /* 0x48-0x4f */
  0x05,0x15,0x25,0x35,0x45,0x55,0x65,0x75,    /* 0x50-0x57 */
  0x85,0x95,0xa5,0xb5,0xc5,0xd5,0xe5,0xf5,    /* 0x58-0x5f */
  0x06,0x16,0x26,0x36,0x46,0x56,0x66,0x76,    /* 0x60-0x67 */
  0x86,0x96,0xa6,0xb6,0xc6,0xd6,0xe6,0xf6,    /* 0x68-0x6f */
  0x07,0x17,0x27,0x37,0x47,0x57,0x67,0x77,    /* 0x70-0x77 */
  0x87,0x97,0xa7,0xb7,0xc7,0xd7,0xe7,0xf7,    /* 0x78-0x7f */
  0x08,0x18,0x28,0x38,0x48,0x58,0x68,0x78,    /* 0x80-0x87 */
  0x88,0x98,0xa8,0xb8,0xc8,0xd8,0xe8,0xf8,    /* 0x88-0x8f */
  0x09,0x19,0x29,0x39,0x49,0x59,0x69,0x79,    /* 0x90-0x97 */
  0x89,0x99,0xa9,0xb9,0xc9,0xd9,0xe9,0xf9,    /* 0x98-0x9f */
  0x0a,0x1a,0x2a,0x3a,0x4a,0x5a,0x6a,0x7a,    /* 0xa0-0xa7 */
  0x8a,0x9a,0xaa,0xba,0xca,0xda,0xea,0xfa,    /* 0xa8-0xaf */
  0x0b,0x1b,0x2b,0x3b,0x4b,0x5b,0x6b,0x7b,    /* 0xb0-0xb7 */
  0x8b,0x9b,0xab,0xbb,0xcb,0xdb,0xeb,0xfb,    /* 0xb8-0xbf */
  0x0c,0x1c,0x2c,0x3c,0x4c,0x5c,0x6c,0x7c,    /* 0xc0-0xc7 */
  0x8c,0x9c,0xac,0xbc,0xcc,0xdc,0xec,0xfc,    /* 0xc8-0xcf */
  0x0d,0x1d,0x2d,0x3d,0x4d,0x5d,0x6d,0x7d,    /* 0xd0-0xd7 */
  0x8d,0x9d,0xad,0xbd,0xcd,0xdd,0xed,0xfd,    /* 0xd8-0xdf */
  0x0e,0x1e,0x2e,0x3e,0x4e,0x5e,0x6e,0x7e,    /* 0xe0-0xe7 */
  0x8e,0x9e,0xae,0xbe,0xce,0xde,0xee,0xfe,    /* 0xe8-0xef */
  0x0f,0x1f,0x2f,0x3f,0x4f,0x5f,0x6f,0x7f,    /* 0xf0-0xf7 */
  0x8f,0x9f,0xaf,0xbf,0xcf,0xdf,0xef,0xff,    /* 0xf8-0xff */
};

PRIVATE unsigned char pixelBitRevLut[256]=
{
  0x00,0x80,0x40,0xc0,0x20,0xa0,0x60,0xe0,    /* 0x00-0x07 */
  0x10,0x90,0x50,0xd0,0x30,0xb0,0x70,0xf0,    /* 0x08-0x0f */
  0x08,0x88,0x48,0xc8,0x28,0xa8,0x68,0xe8,    /* 0x10-0x17 */
  0x18,0x98,0x58,0xd8,0x38,0xb8,0x78,0xf8,    /* 0x18-0x1f */
  0x04,0x84,0x44,0xc4,0x24,0xa4,0x64,0xe4,    /* 0x20-0x27 */
  0x14,0x94,0x54,0xd4,0x34,0xb4,0x74,0xf4,    /* 0x28-0x2f */
  0x0c,0x8c,0x4c,0xcc,0x2c,0xac,0x6c,0xec,    /* 0x30-0x37 */
  0x1c,0x9c,0x5c,0xdc,0x3c,0xbc,0x7c,0xfc,    /* 0x38-0x3f */
  0x02,0x82,0x42,0xc2,0x22,0xa2,0x62,0xe2,    /* 0x40-0x47 */
  0x12,0x92,0x52,0xd2,0x32,0xb2,0x72,0xf2,    /* 0x48-0x4f */
  0x0a,0x8a,0x4a,0xca,0x2a,0xaa,0x6a,0xea,    /* 0x50-0x57 */
  0x1a,0x9a,0x5a,0xda,0x3a,0xba,0x7a,0xfa,    /* 0x58-0x5f */
  0x06,0x86,0x46,0xc6,0x26,0xa6,0x66,0xe6,    /* 0x60-0x67 */
  0x16,0x96,0x56,0xd6,0x36,0xb6,0x76,0xf6,    /* 0x68-0x6f */
  0x0e,0x8e,0x4e,0xce,0x2e,0xae,0x6e,0xee,    /* 0x70-0x77 */
  0x1e,0x9e,0x5e,0xde,0x3e,0xbe,0x7e,0xfe,    /* 0x78-0x7f */
  0x01,0x81,0x41,0xc1,0x21,0xa1,0x61,0xe1,    /* 0x80-0x87 */
  0x11,0x91,0x51,0xd1,0x31,0xb1,0x71,0xf1,    /* 0x88-0x8f */
  0x09,0x89,0x49,0xc9,0x29,0xa9,0x69,0xe9,    /* 0x90-0x97 */
  0x19,0x99,0x59,0xd9,0x39,0xb9,0x79,0xf9,    /* 0x98-0x9f */
  0x05,0x85,0x45,0xc5,0x25,0xa5,0x65,0xe5,    /* 0xa0-0xa7 */
  0x15,0x95,0x55,0xd5,0x35,0xb5,0x75,0xf5,    /* 0xa8-0xaf */
  0x0d,0x8d,0x4d,0xcd,0x2d,0xad,0x6d,0xed,    /* 0xb0-0xb7 */
  0x1d,0x9d,0x5d,0xdd,0x3d,0xbd,0x7d,0xfd,    /* 0xb8-0xbf */
  0x03,0x83,0x43,0xc3,0x23,0xa3,0x63,0xe3,    /* 0xc0-0xc7 */
  0x13,0x93,0x53,0xd3,0x33,0xb3,0x73,0xf3,    /* 0xc8-0xcf */
  0x0b,0x8b,0x4b,0xcb,0x2b,0xab,0x6b,0xeb,    /* 0xd0-0xd7 */
  0x1b,0x9b,0x5b,0xdb,0x3b,0xbb,0x7b,0xfb,    /* 0xd8-0xdf */
  0x07,0x87,0x47,0xc7,0x27,0xa7,0x67,0xe7,    /* 0xe0-0xe7 */
  0x17,0x97,0x57,0xd7,0x37,0xb7,0x77,0xf7,    /* 0xe8-0xef */
  0x0f,0x8f,0x4f,0xcf,0x2f,0xaf,0x6f,0xef,    /* 0xf0-0xf7 */
  0x1f,0x9f,0x5f,0xdf,0x3f,0xbf,0x7f,0xff,    /* 0xf8-0xff */
};


int main(int argc, char* argv[])
{
	int value;
	printf( "{");
	for (int i = 0, j = 0; i < 256; i++, j++) {
		if (j % 8 == 0)
			printf( "\n   ");
			value = pixelBitRevLut[i];
			value = pixelSwapLut8bpp[value];
			printf("0x%02X, ", value);
	}
	printf(" \n} \n");
	getch();
	return 0;
}

