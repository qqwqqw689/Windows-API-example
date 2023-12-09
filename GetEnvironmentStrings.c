#include <windows.h>
#include <tchar.h>
#include <stdio.h>

// _tmain()
// a preprocessor macro defined in tchar.h. _tmain resolves to main unless _UNICODE 
// is defined. In that case, _tmain resolves to wmain.
int _tmain()
{
    LPTSTR lpszVariable;
    // An LPWSTR if UNICODE is defined, an LPSTR otherwise.
    LPTCH lpvEnv;
    // typedef TCHAR *LPTSTR, *LPTCH;
    // TCHAR : A WCHAR if UNICODE is defined, a CHAR otherwise.
    // typedef wchar_t WCHAR;

    // Get a pointer to the environment block. 

    lpvEnv = GetEnvironmentStrings();

    // If the returned pointer is NULL, exit.
    if (lpvEnv == NULL)
    {
        printf("GetEnvironmentStrings failed (%d)\n", GetLastError());
        return 0;
    }

    // Variable strings are separated by NULL byte, and the block is 
    // terminated by a NULL byte. 

    lpszVariable = (LPTSTR)lpvEnv;
    while (*lpszVariable)
    {
        _tprintf(TEXT("%s\n"), lpszVariable);
        // _tprintf : Generic-text routine mappings
        // void TEXT(quote);
        // Identifies a string as Unicode when UNICODE is defined by a preprocessor directive 
        // during compilation. Otherwise, the macro identifies a string as an ANSI string.
        lpszVariable += lstrlen(lpszVariable) + 1;
        // int lstrlenA(
        // [in] LPCSTR lpString
        //  );
        // Determines the length of the specified string (not including the terminating null character).
    }
    FreeEnvironmentStrings(lpvEnv);
    return 1;
}
