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

#ifndef WORKSPACE_H_
#define WORKSPACE_H_

#include <string>
#include <vector>

#define SPACE '#'
#define DEFAULT_TITLE "WORK SPACE"
#define DEFAULT_WIDTH 80
#define DEFAULT_HEIGHT 25

using std::string;
using std::vector;

class WorkSpace {
    private:
    int pWidth; // 宽度
    int pHeight; // 高度

    string pTitle; // 标题
    char pBackgroundChar; // 背景颜色

    vector<string> pDisplay;
    public:
    WorkSpace(int width, int height, const string& title, char backGroundColor);
    WorkSpace(int width, int height, const string& title);
	WorkSpace(int width, int height);
	WorkSpace();

    vector<int> size() const; // 获取尺寸

    string title() const; // 获取标题
    void title(const string& newTitle); // 设置标题

    char backgroundChar() const; // 获取背景颜色
    void backgroundChar(const char& backgroundChar); // 设置背景颜色

    void draw();

};


#endif
// WORKSPACE_H_