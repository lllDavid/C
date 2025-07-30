#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

int main() {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        printf("Failed to take process snapshot.\n");
        return 1;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(snapshot, &pe)) {
        printf("Failed to get first process.\n");
        CloseHandle(snapshot);
        return 1;
    }

    printf("List of running processes:\n");
    do {
        printf("PID: %lu\tProcess Name: %s\n", pe.th32ProcessID, pe.szExeFile);
    } while (Process32Next(snapshot, &pe));

    CloseHandle(snapshot);
    return 0;
}