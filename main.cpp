//  The MIT License(MIT)
//  Copyright(c) <2015> <Martin Šinkovec>

//  Permission is hereby granted, free of charge, to any person obtaining a 
//  copy of this software and associated documentation files (the "Software"), 
//  to deal in the Software without restriction, including without limitation 
//  the rights to use, copy, modify, merge, publish, distribute, sublicense, 
//  and/or sell copies of the Software, and to permit persons to whom the 
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in 
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
//  DEALINGS IN THE SOFTWARE.

#include <iostream>
#include <windows.h>
#include <winuser.h>
#pragma comment(lib, "user32.lib")

using namespace std;

int main()
{
	int i = 0, *MouseSpeed = &i;
	int aMouseInfo[3];

	SystemParametersInfo(SPI_GETMOUSESPEED, 0, MouseSpeed, 0);
	SystemParametersInfo(SPI_GETMOUSE, 0, &aMouseInfo, 0);

	cout << "\nPrevious Mouse Speed was : " << *MouseSpeed;
	if (aMouseInfo[2] >= 1)
		cout << "\nMouse Accel is ON";
	else
		cout << "\nMouse Accel is OFF";

	i = 10; // change mouse speed here. 
	MouseSpeed = &i;

	SystemParametersInfo(SPI_SETMOUSESPEED,
		0,
		(LPVOID)i,
		SPIF_UPDATEINIFILE ||
		SPIF_SENDCHANGE ||
		SPIF_SENDWININICHANGE);

	cout << "\n\nCurrent Mouse Speed is : " << *MouseSpeed;

	aMouseInfo[2] = 0; // accel on/off use 0 or 1

	SystemParametersInfo(
		SPI_SETMOUSE,
		0,
		aMouseInfo,
		SPIF_SENDCHANGE);

	if (aMouseInfo[2] >= 1)
		cout << "\nMouse Accel is ON";
	else
		cout << "\nMouse Accel is OFF";

	return 0;
}