#include <windows.h>
#include <stdio.h>

int main() {
    WCHAR buffer[32767];

    DWORD result = GetEnvironmentVariable(L"PATH", buffer, sizeof(buffer));
    // wchar_t : L""

    if (result == 0) {
        printf("The environment variable \"PATH\" was not found.\n");
        return 1;
    }

    wprintf(L"The value of the environment variable \"PATH\" is: %s\n", buffer);
    // int wprintf (const wchar_t* format, ...);
    // wprintf is a wide-character version of printf; format is a wide-character string.

    return 0;
}
