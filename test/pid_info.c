#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <stdio.h>

void print_process_info(DWORD pid) {
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
    if (!hProcess) {
        printf("Cannot open process %lu (error %lu)\n", pid, GetLastError());
        return;
    }

    char exePath[MAX_PATH];
    if (GetModuleFileNameExA(hProcess, NULL, exePath, MAX_PATH)) {
        printf("Executable Path: %s\n", exePath);
    } else {
        printf("Could not retrieve executable path.\n");
    }

    PROCESS_MEMORY_COUNTERS memInfo;
    if (GetProcessMemoryInfo(hProcess, &memInfo, sizeof(memInfo))) {
        printf("Working Set Size: %lu KB\n", memInfo.WorkingSetSize / 1024);
        printf("Pagefile Usage: %lu KB\n", memInfo.PagefileUsage / 1024);
    } else {
        printf("Could not retrieve memory info.\n");
    }

    CloseHandle(hProcess);
}

void find_process_details(DWORD pid) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return;

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(snapshot, &pe)) {
        do {
            if (pe.th32ProcessID == pid) {
                printf("Process ID: %lu\n", pid);
                printf("Parent PID: %lu\n", pe.th32ParentProcessID);
                printf("Thread Count: %lu\n", pe.cntThreads);
                printf("Process Name: %s\n", pe.szExeFile);
                break;
            }
        } while (Process32Next(snapshot, &pe));
    }

    CloseHandle(snapshot);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    DWORD pid = (DWORD)atoi(argv[1]);
    find_process_details(pid);
    print_process_info(pid);

    return 0;
}