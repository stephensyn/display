
// #include </home/stephen/study_c/display/include/display/test.h>
extern "C"
{
#include <oled/GUI_Paint.h>
#include <oled/GUI_BMPfile.h>
#include <oled/Debug.h>

#include <stdlib.h> // malloc() free()
#include <math.h>

#include <oled/DEV_Config.h>
#include <oled/OLED_1in5.h>
}

// #include <disdev/Disdev.h>
// Disdev *pdisdev = new Disdev();

int main(void)
{
	// pdisdev->init();

	printf("1.5inch OLED test demo\n");
	if (DEV_ModuleInit() != 0) //
	{
		return -1;
	}

	printf("OLED Init...\r\n");
	OLED_1in5_Init();
	DEV_Delay_ms(500);
	OLED_1in5_Clear();

	DEV_Delay_ms(500);
	// // 0.Create a new image cache
	UBYTE *BlackImage;
	UWORD Imagesize = ((OLED_1in5_WIDTH % 2 == 0) ? (OLED_1in5_WIDTH / 2) : (OLED_1in5_WIDTH / 2 + 1)) * OLED_1in5_HEIGHT;
	if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL)
	{
		printf("Failed to apply for black memory...\r\n");
		return -1;
	}
	// printf("Paint_NewImage\r\n");
	Paint_NewImage(BlackImage, OLED_1in5_WIDTH, OLED_1in5_HEIGHT, 0, BLACK);
	Paint_SetScale(16);
	printf("Drawing\r\n");
	// 1.Select Image
	Paint_SelectImage(BlackImage);
	DEV_Delay_ms(500);
	Paint_Clear(BLACK);
	// while (1)
	// {

	// 	// 2.Drawing on the image
	printf("Drawing:page 1\r\n");
	Paint_DrawPoint(20, 10, WHITE, DOT_PIXEL_1X1, DOT_STYLE_DFT);
	Paint_DrawPoint(30, 10, WHITE, DOT_PIXEL_2X2, DOT_STYLE_DFT);
	Paint_DrawPoint(40, 10, WHITE, DOT_PIXEL_3X3, DOT_STYLE_DFT);
	Paint_DrawLine(10, 10, 10, 20, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine(20, 20, 20, 30, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine(30, 30, 30, 40, WHITE, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
	Paint_DrawLine(40, 40, 40, 50, WHITE, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
	Paint_DrawCircle(60, 30, 15, WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
	Paint_DrawCircle(100, 40, 20, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);
	Paint_DrawRectangle(50, 30, 60, 40, WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
	Paint_DrawRectangle(90, 30, 110, 50, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
	// 	// 3.Show image on page1
	OLED_1in5_Display(BlackImage);
	// 	DEV_Delay_ms(2000);
	// 	Paint_Clear(BLACK);

	// 	// Drawing on the image
	// 	printf("Drawing:page 2\r\n");
	// 	for (UBYTE i = 0; i < 16; i++)
	// 	{
	// 		Paint_DrawRectangle(0, 8 * i, 127, 8 * (i + 1), i, DOT_PIXEL_1X1, DRAW_FILL_FULL);
	// 	}
	// 	// Show image on page2
	// 	OLED_1in5_Display(BlackImage);
	// 	DEV_Delay_ms(2000);
	// 	Paint_Clear(BLACK);

	// 	// Drawing on the image
	// 	printf("Drawing:page 3\r\n");
	// 	Paint_DrawString_EN(10, 0, "waveshare", &Font16, 0xFFFF, 0xFFFF);
	// 	Paint_DrawString_EN(10, 17, "hello world", &Font8, 0x2, 0xc);
	// 	Paint_DrawNum(10, 30, 123.456789, &Font8, 4, 0x3, 0xd);
	// 	Paint_DrawNum(10, 43, 987654, &Font12, 5, 0x4, 0xe);
	// 	// Show image on page2
	// 	OLED_1in5_Display(BlackImage);
	// 	DEV_Delay_ms(2000);
	// 	Paint_Clear(BLACK);

	// 	// Drawing on the image
	// 	printf("Drawing:page 4\r\n");
	// 	Paint_DrawString_CN(10, 0, "树莓派", &Font12CN, WHITE, WHITE);
	// 	Paint_DrawString_CN(0, 20, "微软", &Font24CN, WHITE, WHITE);
	// 	// Show image on page3
	// 	OLED_1in5_Display(BlackImage);
	// 	DEV_Delay_ms(2000);
	// 	Paint_Clear(BLACK);

	// 	// Drawing on the image
	// 	printf("Drawing:page 5\r\n");
	// 	GUI_ReadBmp_16Gray("../oled/pic/1in5.bmp", 0, 0);
	// 	// Show image on page4
	// 	OLED_1in5_Display(BlackImage);
	// 	DEV_Delay_ms(2000);
	// 	Paint_Clear(BLACK);

	// 	OLED_1in5_Clear();
	// }
}
