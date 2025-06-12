#include <windows.h>

DWORD WINAPI ShowMessageThread(LPVOID lpParam) {
    MessageBoxW(NULL, L"<Injected Message>", L"Message", MB_OK);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        HANDLE hThread = CreateThread(NULL, 0, ShowMessageThread, NULL, 0, NULL);
        if (hThread) {
            CloseHandle(hThread); 
        }
    }
    return TRUE;
}
