#include <disdev/Disdev.h>

Disdev::Disdev(/* args */)
{
    //  void init();
}

Disdev::~Disdev()
{
}
void Disdev::Paint_NewImage(UBYTE *image, UWORD Width, UWORD Height, UWORD Rotate, UWORD Color)
{
}

void Disdev::Paint_SetScale(UBYTE scale)
{
}

void Disdev::Paint_SelectImage(UBYTE *image)

{
}

void Disdev::Paint_Clear(UWORD Color)
{
}
void Disdev::init()
{
    printf("1.5inch OLED test demo\n");
    DEV_ModuleInit();
    printf("OLED Init...\r\n");
    OLED_1in5_Init();
    DEV_Delay_ms(500);
    OLED_1in5_Clear();

    DEV_Delay_ms(500);
    // // 0.Create a new image cache
    // UBYTE *BlackImage;
    UWORD Imagesize = ((OLED_1in5_WIDTH % 2 == 0) ? (OLED_1in5_WIDTH / 2) : (OLED_1in5_WIDTH / 2 + 1)) * OLED_1in5_HEIGHT;
    if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL)
    {
        printf("Failed to apply for black memory...\r\n");
        // return -1;
    }
    // printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, OLED_1in5_WIDTH, OLED_1in5_HEIGHT, 0, BLACK);
    Paint_SetScale(16);
    printf("Drawing\r\n");
    // 1.Select Image
    Paint_SelectImage(BlackImage);
    DEV_Delay_ms(500);
    Paint_Clear(BLACK);
}
