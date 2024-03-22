#include <iostream>
#include <windows.h>

int main() {
    // Get the handle to the foreground window
    HWND foregroundWindow = GetForegroundWindow();

    // HWND : A handle to a window.

    // Get the length of the window title
    int titleLength = GetWindowTextLengthW(foregroundWindow) + 1;

    // Allocate memory to store the window title
    wchar_t* title = new wchar_t[titleLength];

    // wchar_t : type for wide character representation 

    // Get the window title
    GetWindowTextW(foregroundWindow, title, titleLength);

    /*
    int GetWindowTextW(
      [in]  HWND   hWnd,
      [out] LPWSTR lpString,
      [in]  int    nMaxCount    : The maximum number of characters to copy to the buffer, including the null character. 
    );
    */

    // Print the window title
    std::wcout << L"Foreground window title: " << title << std::endl;

    // L"s-char-seq (optional)" : wide string literal

    // extern basic_ostream<wchar_t> wcout;
    // Standard output stream (wide)

    // Free allocated memory
    delete[] title;

    return 0;
}
