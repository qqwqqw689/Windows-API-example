#include <iostream>
#include <windows.h>

int main() {
    // Get the handle to the foreground window
    HWND foregroundWindow = GetForegroundWindow();

    // Get the length of the window title
    int titleLength = GetWindowTextLengthW(foregroundWindow) + 1;

    // Allocate memory to store the window title
    wchar_t* title = new wchar_t[titleLength];

    // Get the window title
    GetWindowTextW(foregroundWindow, title, titleLength);

    // Print the window title
    std::wcout << L"Foreground window title: " << title << std::endl;

    // Free allocated memory
    delete[] title;

    return 0;
}
