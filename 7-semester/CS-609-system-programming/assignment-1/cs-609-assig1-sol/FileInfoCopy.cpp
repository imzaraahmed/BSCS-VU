// Assignment 1 - FileInfoCopy - CS609 - Fall 2025

#include <windows.h>
#include <iostream>


using namespace std;

// Function to print errors with GetLastError()
void PrintError(const string &msg) {
    DWORD errCode = GetLastError();
    LPVOID errMsg;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&errMsg, 0, NULL);
    cout << msg << " Error Code: " << errCode << " - " << (char*)errMsg << endl;
    LocalFree(errMsg);
}

int main() {
    cout << "=== File Information and Copy Program ===\n\n";

    HANDLE hFile;
    DWORD bytesWritten, bytesRead;
    char buffer[1024];
    BOOL result;

    // Step 1: Create and open "source.txt"
    cout << "Creating or opening source.txt ...\n";
    hFile = CreateFile(
        "source.txt",              
        GENERIC_WRITE,              
        0,                         
        NULL,                       
        CREATE_ALWAYS,             
        FILE_ATTRIBUTE_NORMAL,      
        NULL);                      

    if (hFile == INVALID_HANDLE_VALUE) {
        PrintError("Failed to create file.");
        return 1;
    }

    // Step 2: student ID and name
    
    const char* content = " BC220409531 - Zara Ahmed\n";
    cout << "Writing student data into source.txt ...\n";
    result = WriteFile(hFile, content, (DWORD)strlen(content), &bytesWritten, NULL);
    if (!result) {
        PrintError("Failed to write to file.");
        CloseHandle(hFile);
        return 1;
    }

    // Step 3: Close the file
    
    CloseHandle(hFile);
    cout << "Closing source.txt after writing...\n";

    // Step 4: Reopen file for reading
    
    cout << "Opening source.txt for reading...\n";
    hFile = CreateFile(
        "source.txt",
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        PrintError("Failed to open file for reading.");
        return 1;
    }

    cout << "Reading data from source.txt...\n";

    // Step 5: Read contents and display
    
    ZeroMemory(buffer, sizeof(buffer));
    result = ReadFile(hFile, buffer, sizeof(buffer) - 1, &bytesRead, NULL);
    if (!result) {
        PrintError("Failed to read from file.");
        CloseHandle(hFile);
        return 1;
    }

    cout << "File contents:" ;
    cout << buffer << endl;
   
     //  Close file after reading
    
     CloseHandle(hFile);
    cout << "Closing source.txt after reading...\n";
   

    // Step 6: Copy file 
    
    cout << "Copying source.txt to destination.txt...\n";
    result = CopyFile("source.txt", "destination.txt", FALSE);
    if (!result) {
        PrintError("Failed to copy file.");
        return 1;
    }
   

    // Step 7: Retrieve and display file info for both files
    
    cout << "Getting file information...\n";

    HANDLE hSource = CreateFile(
        "source.txt", GENERIC_READ, FILE_SHARE_READ, NULL,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    HANDLE hDest = CreateFile(
        "destination.txt", GENERIC_READ, FILE_SHARE_READ, NULL,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hSource == INVALID_HANDLE_VALUE || hDest == INVALID_HANDLE_VALUE) {
        PrintError("Failed to open files for info retrieval.");
        return 1;
    }

    DWORD sizeSource = GetFileSize(hSource, NULL);
    DWORD sizeDest = GetFileSize(hDest, NULL);

    cout << "source.txt size: " << sizeSource << " bytes\n";
    cout << "destination.txt size: " << sizeDest << " bytes\n";

    DWORD attrSource = GetFileAttributes("source.txt");
    DWORD attrDest = GetFileAttributes("destination.txt");

    cout << "source.txt attributes: " << attrSource << endl;
    cout << "destination.txt attributes: " << attrDest << endl;

     // Step 8: Print current working directory
     
    cout << "\nCurrent working directory...\n";
    char currentDir[MAX_PATH];
    DWORD dirLen = GetCurrentDirectory(MAX_PATH, currentDir);
    if (dirLen == 0) {
        PrintError("Failed to get current directory.");
    } else {
        cout << "Current Directory: " << currentDir << endl;
    }

    cout << "\nAll tasks Completed Successfully.\n";

    return 0;
}

