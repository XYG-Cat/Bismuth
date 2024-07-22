// This program is free software: you can redistribute it and/or 
// modify it under the terms of the license, subject to the author"s approval.
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
// e-mail : mcyyds1145141919810@outlook.com， 2940206071@qq.com。
// QQ : 2940206071
// Copyright (c) 2023, 2024 POINT Org. All Rights Reserved.


#include "Bismuth/TuiTools.h"

#include <iostream>
#include <vector>
#include <thread>   // 实现timeSleep()
#include <chrono>   // 单位转换
#include <cstdlib>  // 用到system()实现clearScreen()


#ifdef _WIN32
#include <windows.h>
#endif

using std::chrono::milliseconds;
using std::this_thread::sleep_for;

using std::vector;
using std::cout;
using std::endl;
using std::string;

// private
#ifdef _WIN32
std::unique_ptr<string> TuiTools::pCaseWindowsVersion(OSVERSIONINFOEX& osvi) {
    // 使用 switch 判断主版本号 使用 if-else 判断次版本号
    switch (osvi.dwMajorVersion) {

    case 10: // nt10
        if (osvi.dwMinorVersion == 0) return std::make_unique<string>("Windows 10");
        break;

    case 6: // nt6
        if (osvi.dwMinorVersion == 3) return std::make_unique<string>("Windows 8.1");        // nt 6.3
        else if (osvi.dwMinorVersion == 2) return std::make_unique<string>("Windows 8");     // nt 6.2
        else if (osvi.dwMinorVersion == 1) return std::make_unique<string>("Windows 7");     // nt 6.1
        else if (osvi.dwMinorVersion == 0) return std::make_unique<string>("Windows Vista"); // nt 6.0
        break;

    case 5:
        if (osvi.dwMinorVersion == 1) return std::make_unique<string>("Windows XP");   // nt 5.1
        if (osvi.dwMinorVersion == 0) return std::make_unique<string>("Windows 2000"); // nt 5.0
        break;

    default:
        break;
    }
    return std::make_unique<string>("Unknown");
}


//public
void TuiTools::hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;  // 设置光标不可见
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void TuiTools::showCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = TRUE;  // 设置光标可见
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void TuiTools::movCursorTo(const int x, const int y) {
    // 获取标准输出句柄
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 设置光标位置
    COORD pos;
    pos.X = static_cast<short>(x);
    pos.Y = static_cast<short>(y);

    SetConsoleCursorPosition(hConsole, pos);
}

#endif

string TuiTools::systemVersion() {
#ifdef _WIN32
    // 初始化 OSVERSIONINFOEX 结构体，并设置大小
    OSVERSIONINFOEX osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    // 调用 GetVersionEx 函数获取操作系统版本信息
    if (GetVersionEx(reinterpret_cast<OSVERSIONINFO*>(&osvi))) {
        return *TuiTools::pCaseWindowsVersion(osvi);
    } else {
        return "Failed to retrieve OS version information";
    }
#else
    return "others";
#endif
}

void TuiTools::clearScreen() {
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}

void TuiTools::printVersion(const string& VERSION) {
    cout << VERSION << endl;
}

void TuiTools::timeSleep(int time) {
    sleep_for(milliseconds(time));
}

