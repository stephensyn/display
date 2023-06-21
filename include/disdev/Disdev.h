#ifndef _DISDEV_H_
#define _DISDEV_H_

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

#include <iostream>

using namespace std;

class Disdev
{
private:
    /* data */
    UBYTE *BlackImage;
    // 新建一个图像属性，这个属性包括图像缓存的名称、宽度、高度、翻转角度、颜色
    void Paint_NewImage(UBYTE *image, UWORD Width, UWORD Height, UWORD Rotate, UWORD Color);

public:
    Disdev(/* args */);
    ~Disdev();

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
};

#endif
