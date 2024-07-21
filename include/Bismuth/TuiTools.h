// This program is free software: you can redistribute it and/or modify it under the terms of the license, subject to the author's approval.
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


#ifndef TUITOOLS_H_
#define TUITOOLS_H_

#include <string>
#include <memory>

#ifdef _WIN32
#include <windows.h>
#endif

#define ANSI_CLEAR "\033[2J\033[1;1H"

using std::string;
using std::unique_ptr;

class TuiTools {
    private:
#ifdef _WIN32
    static unique_ptr<string> caseWindowsVersion(OSVERSIONINFOEX& osvi);
#endif

    public:
#ifdef _WIN32
    static void hideCursor();
    static void showCursor();
    static void movCursorTo(int x, int y);
#endif
    static void clearScreen();
    static void printVersion(const string& VERSION);
	static string systemVersion();
	static void timeSleep(int time); // 毫秒为单位的sleep
};

#endif // TUITOOLS_H_