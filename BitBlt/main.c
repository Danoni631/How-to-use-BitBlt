#include "includer.h"
#include "config.h"

int main()
{
    HDC desk = GetDC(0);
    int rx;

    for (int i = 0;; i++) {
        SeedXorshift32(GetSeed());
        desk = GetDC(0);
        rx = xorshift32() % sw;
        int ry = xorshift32() % sh;
        HBRUSH brush = CreateSolidBrush(RGB(xorshift32() % 255, xorshift32() % 255, xorshift32() % 255));
        SelectObject(desk, brush);
        BitBlt(desk, rx, 10, 100, sh, desk, rx, 0, SRCCOPY);
        BitBlt(desk, rx, -10, -100, sh, desk, rx, 0, SRCCOPY);
        DeleteObject(brush);
        Sleep(1);
    }

    // YOU CAN SWITCH SRCCOPY TO SRCINVERT, SRCAND, SRCPAINT AND OTHER TO GET DIFFERENT EFFECTS
}

/*
*   SRCCOPY: Copies the source rectangle directly to the destination rectangle.
*	NOTSRCCOPY: Is the same of the SRCCOPY, but inverts source rectangle colors.
*   SRCINVERT: Combines the colors of the source and destination rectangles using a bitwise XOR operation.
*   SRCAND: Combines the colors of the source and destination rectangles using a bitwise AND operation.
*   SRCPAINT: Combines the colors of the source and destination rectangles using a bitwise OR operation.
*   NOTSRCINVERT: Combine the colors of the source and destination rectangles like SRCINVERT, but with inverted colors (NOTSRCINVERT is not
*	in windows.h, u need to define NOTSRCCOPY in "#define NOTSRCCOPY 0x999999).
*	SRCERASE: Combine the colors of the source with negative rectangle copy.
*	NOTSRCERASE: Likes SRCERASE, but with other negative forms.
*/
