#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
           return 1;
    }

    DWORD pid = atoi(argv[1]);
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return 1;

    THREADENTRY32 te;
    te.dwSize = sizeof(te);

    if (Thread32First(snapshot, &te)) {
        do {
            if (te.th32OwnerProcessID == pid) {
                printf("Thread ID: %lu\n", te.th32ThreadID);
            }
        } while (Thread32Next(snapshot, &te));
    }

    CloseHandle(snapshot);
    return 0;
}