#ifndef _DISDEV_H_
#define _DISDEV_H_

extern "C"
{
#include <stdlib.h> // malloc() free()
#include <math.h>
#include <oled/OLED_1in5.h>
#include <oled/fonts.h>
}

/**
 * Image attributes
 **/
typedef struct
{
    UBYTE *Image;
    UWORD Width;
    UWORD Height;
    UWORD WidthMemory;
    UWORD HeightMemory;
    UWORD Color;
    UWORD Rotate;
    UWORD Mirror;
    UWORD WidthByte;
    UWORD HeightByte;
    UWORD Scale;
} PAINT;
extern PAINT Paint;

/**
 * Display rotate
 **/
#define ROTATE_0 0
#define ROTATE_90 90
#define ROTATE_180 180
#define ROTATE_270 270

/**
 * Display Flip
 **/
typedef enum
{
    MIRROR_NONE = 0x00,
    MIRROR_HORIZONTAL = 0x01,
    MIRROR_VERTICAL = 0x02,
    MIRROR_ORIGIN = 0x03,
} MIRROR_IMAGE;
#define MIRROR_IMAGE_DFT MIRROR_NONE

/**
 * image color
 **/
#define WHITE 0xFFFF
#define BLACK 0x0000
#define BLUE 0x001F
#define BRED 0XF81F
#define GRED 0XFFE0
#define GBLUE 0X07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define GREEN 0x07E0
#define CYAN 0x7FFF
#define YELLOW 0xFFE0
#define BROWN 0XBC40
#define BRRED 0XFC07
#define GRAY 0X8430

#define IMAGE_BACKGROUND WHITE
#define FONT_FOREGROUND BLACK
#define FONT_BACKGROUND WHITE

/**
 * The size of the point
 **/
typedef enum
{
    DOT_PIXEL_1X1 = 1, // 1 x 1
    DOT_PIXEL_2X2,     // 2 X 2
    DOT_PIXEL_3X3,     // 3 X 3
    DOT_PIXEL_4X4,     // 4 X 4
    DOT_PIXEL_5X5,     // 5 X 5
    DOT_PIXEL_6X6,     // 6 X 6
    DOT_PIXEL_7X7,     // 7 X 7
    DOT_PIXEL_8X8,     // 8 X 8
} DOT_PIXEL;
#define DOT_PIXEL_DFT DOT_PIXEL_1X1 // Default dot pilex

/**
 * Point size fill style
 **/
typedef enum
{
    DOT_FILL_AROUND = 1, // dot pixel 1 x 1
    DOT_FILL_RIGHTUP,    // dot pixel 2 X 2
} DOT_STYLE;
#define DOT_STYLE_DFT DOT_FILL_AROUND // Default dot pilex

/**
 * Line style, solid or dashed
 **/
typedef enum
{
    LINE_STYLE_SOLID = 0,
    LINE_STYLE_DOTTED,
} LINE_STYLE;

/**
 * Whether the graphic is filled
 **/
typedef enum
{
    DRAW_FILL_EMPTY = 0,
    DRAW_FILL_FULL,
} DRAW_FILL;

/**
 * Custom structure of a time attribute
 **/
typedef struct
{
    UWORD Year;  // 0000
    UBYTE Month; // 1 - 12
    UBYTE Day;   // 1 - 30
    UBYTE Hour;  // 0 - 23
    UBYTE Min;   // 0 - 59
    UBYTE Sec;   // 0 - 59
} PAINT_TIME;
extern PAINT_TIME sPaint_time;

#include <iostream>

using namespace std;

class Disdev
{
private:
public:
    Disdev(/* args */);
    ~Disdev();
    /* data */
    UBYTE *BlackImage;

    // 新建一个图像属性，这个属性包括图像缓存的名称、宽度、高度、翻转角度、颜色
    void Paint_NewImage(UBYTE *image, UWORD Width, UWORD Height, UWORD Rotate, UWORD Color);

    void init();

    // 设置像素点的尺寸
    void Paint_SetScale(UBYTE scale);

    // 选择图像缓存，选择的目的是你可以创建多个图像属性，图像缓存可以存在多个，你可以选择你所创建的每一张图像
    void Paint_SelectImage(UBYTE *image);

    // 设置点在缓存中显示位置和颜色：这里是GUI最核心的一个函数、处理点在缓存中显示位置和颜色；
    void Paint_SetPixel(UWORD Xpoint, UWORD Ypoint, UWORD Color);

    // 图像缓存填充颜色:把图像缓存填充为某颜色，一般作为屏幕刷白的作用
    void Paint_Clear(UWORD Color);

    // 图像缓存部分窗口填充颜色：把图像缓存的某部分窗口填充为某颜色，一般作为窗口刷白的作用，常用于时间的显示，刷白上一秒
    void Paint_ClearWindows(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD Color);

    // 画点:在图像缓存中，在（Xpoint, Ypoint）上画点，可以选择颜色，点的大小，点的风格
    void Paint_DrawPoint(UWORD Xpoint, UWORD Ypoint, UWORD Color, DOT_PIXEL Dot_Pixel, DOT_STYLE Dot_Style);

    // 画线：在图像缓存中，从 (Xstart, Ystart) 到 (Xend, Yend) 画线，可以选择颜色，线的宽度，线的风格
    void Paint_DrawLine(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend,
                        UWORD Color, DOT_PIXEL Line_width, LINE_STYLE Line_Style);

    // 写Ascii字符:在图像缓存中，在 (Xstart Ystart) 为左顶点，写一个Ascii字符，可以选择Ascii码可视字符字库、字体前景色、字体背景色
    void Paint_DrawChar(UWORD Xstart, UWORD Ystart, const char Ascii_Char, sFONT *Font,
                        UWORD Color_Foreground, UWORD Color_Background);

    // 写英文字符串:在图像缓存中，在 (Xstart Ystart) 为左顶点，写一串英文字符，可以选择Ascii码可视字符字库、字体前景色、字体背景色
    void Paint_DrawString_EN(UWORD Xstart, UWORD Ystart, const char *pString, sFONT *Font,
                             UWORD Color_Foreground, UWORD Color_Background);

    // 写中文字符串：在图像缓存中，在 (Xstart Ystart) 为左顶点，写一串中文字符，可以选择GB2312编码字符字库、字体前景色、字体背景色；
    void Paint_DrawString_CN(UWORD Xstart, UWORD Ystart, const char *pString, cFONT *font,
                             UWORD Color_Foreground, UWORD Color_Background);

    // 写数字:在图像缓存中，在 (Xstart Ystart) 为左顶点，写一串数字，可以选择Ascii码可视字符字库、字体前景色、字体背景色
    void Paint_DrawNum(UWORD Xpoint, UWORD Ypoint, double Nummber, sFONT *Font, UWORD Digit,
                       UWORD Color_Foreground, UWORD Color_Background);

    // 显示时间:在图像缓存中，在 (Xstart Ystart) 为左顶点，显示一段时间，可以选择Ascii码可视字符字库、字体前景色、字体背景色；
    void Paint_DrawTime(UWORD Xstart, UWORD Ystart, PAINT_TIME *pTime, sFONT *Font,
                        UWORD Color_Background, UWORD Color_Foreground);
    void Paint_SetRotate(UWORD Rotate);
    void Paint_SetMirroring(UBYTE mirror);
    void Paint_DrawRectangle(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend,
                             UWORD Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill);
    void Paint_DrawCircle(UWORD X_Center, UWORD Y_Center, UWORD Radius,
                          UWORD Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill);
    void Paint_DrawBitMap(const unsigned char *image_buffer);
    void Paint_DrawBitMap_Block(const unsigned char *image_buffer, UBYTE Region);
};

#endif
