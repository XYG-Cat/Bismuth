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

#include <string>
#include <vector>
#include <iostream>

#include "Bismuth/WorkSpace.h"
#include "Bismuth/TuiTools.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;



// -----$ 初始化的3种重载 $-----
// 1:宽度, 高度, 标题
// 2:宽度, 高度
// 3:无参, 既默认宽度, 默认高度

WorkSpace::WorkSpace(const int width, const int height, const string& title, char backGroundColor) {
    this->pWidth = width;
    this->pHeight = height;
    this->pTitle = title;
    this->pBackgroundChar = backGroundColor;

    for (int i = 0; i < this->pHeight; ++i) {
        pDisplay.emplace_back(pWidth, backGroundColor);
    }
}


WorkSpace::WorkSpace(const int width, const int height, const string& title)
: WorkSpace(width, height, title, SPACE) {}

WorkSpace::WorkSpace(const int width, const int height)
: WorkSpace(width, height, DEFAULT_TITLE, SPACE) {}

WorkSpace::WorkSpace()
: WorkSpace(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_TITLE, SPACE) {}


// 获得设置的WorkSpace尺寸, 返回一个向量
vector<int> WorkSpace::size() const {
    vector<int> workSpaceSize = {
        this->pWidth,
        this->pHeight
    }; 
	return workSpaceSize;
}


// 获得设置的WorkSpace标题
string WorkSpace::title() const {
    return this->pTitle;
}

// 设置WorkSpace标题
void WorkSpace::title(const string& newTitle) {
    this->pTitle = newTitle;
}


char WorkSpace::backgroundChar() const {
    return this->pBackgroundChar;
}

void WorkSpace::backgroundChar(const char& newBackgroundColor) {
    this->pBackgroundChar = newBackgroundColor;
    for (int i = 0; i < this->pHeight; ++i) {
        pDisplay.emplace_back(pWidth, newBackgroundColor);
    }
}

void WorkSpace::draw() {
    TuiTools::clearScreen();
    for (const auto& i : pDisplay) {
        for (const auto& j : i) {
            cout << j;
        }
        cout << endl;
    }
}


