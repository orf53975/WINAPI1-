﻿#define STRICT 1 
#include <windows.h>
#include <iostream>
using namespace std;
VOID CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime) 
{

//  LPWSTR wallpaper_file = L"C:\\Users\\vaxoa\\OneDrive\\Documents\\GitHub\\WINAPI\\Tree View\\1200x900\\2.jpg";

	HCURSOR hCursor = LoadCursorFromFile("C:\\Users\\vaxoa\\OneDrive\\Documents\\GitHub\\WINAPI\\icon\\cur197.ani");
  int return_value = SystemParametersInfo(SPI_SETCURSORS, 0, hCursor, SPIF_UPDATEINIFILE);
  if(return_value){MessageBox(0,"set","set",0);}

SetCursor(hCursor);
SetClassLong(GetDesktopWindow(), -12, (DWORD)hCursor);





  cout << "Programmatically change the desktop wallpaper periodically: " << dwTime << '\n';
  cout.flush();
}

int main(int argc, char *argv[], char *envp[]) 
{
    int Counter=0;
    MSG Msg;

    UINT TimerId = SetTimer(NULL, 0, 2000, &TimerProc); //2000 milliseconds

    cout << "TimerId: " << TimerId << '\n';
   if (!TimerId)
    return 16;

   while (GetMessage(&Msg, NULL, 0, 0)) 
   {
        ++Counter;
        if (Msg.message == WM_TIMER)
        cout << "Counter: " << Counter << "; timer message\n";
        else
        cout << "Counter: " << Counter << "; message: " << Msg.message << '\n';
        DispatchMessage(&Msg);
    }

   KillTimer(NULL, TimerId);
return 0;
}