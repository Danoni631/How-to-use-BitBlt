#include <windows.h>
#include <intrin.h>

DWORD xs;
VOID SeedXorshift32(DWORD dwSeed) {
	xs = dwSeed;
}
DWORD xorshift32() {
	xs ^= xs << 13;
	xs ^= xs << 17;
	xs ^= xs << 5;
	return xs;
}

int main() {
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	int rx;
	for (int i = 0;; i++) {
		SeedXorshift32(__rdtsc());
		desk = GetDC(0);
		rx = xorshift32() % sw;
		int ry = xorshift32() % sh;
		SelectObject(desk, CreateSolidBrush(RGB(xorshift32() % 255, xorshift32() % 255, xorshift32() % 255)));
		BitBlt(desk, rx, 10, 100, sh, desk, rx, 0, SRCCOPY);
		BitBlt(desk, rx, -10, -100, sh, desk, rx, 0, SRCCOPY);
		Sleep(1);
	}

	// YOU CAN SWITCH SRCCOPY TO SRCINVERT, SRCAND OR SRCPAINT TO GET DIFFERENT EFFECTS
}

/*
*	SRCCOPY: Copies the source rectangle directly to the destination rectangle.
*	SRCINVERT: Combines the colors of the source and destination rectangles using a bitwise XOR operation.
*	SRCAND: Combines the colors of the source and destination rectangles using a bitwise AND operation.
*	SRCPAINT: Combines the colors of the source and destination rectangles using a bitwise OR operation.
*/