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

#include "Bismuth/Module.h"
#include "Bismuth/TuiTools.h"

#include <vector>
#include <string>
#include <stdexcept>  // 包含 std::runtime_error
#include <iostream>

using std::vector;
using std::string;
using std::cout;

Module::Module(const vector<string> &appearance, int xPosition, int yPosition) {
    if (appearance.empty()) throw std::runtime_error("A empty appearance vector");
    for (int i = 0; i != appearance.size(); ++i) {
        if (i == 0) continue;
        if (appearance[i].size() != appearance[i - 1].size()) throw std::runtime_error("Strings are not equal in length");
    }
    this->pAppearance = appearance;
    this->pHeight = static_cast<int>(this->pAppearance.size());
    this->pWidth = static_cast<int>(appearance[0].size());

    this->pXPosition = xPosition;
    this->pYPosition = yPosition;
}

Module::Module(const vector<string>& appearance) {
    if (appearance.empty()) throw std::runtime_error("A empty appearance vector");
    for (int i = 0; i != appearance.size(); ++i) {
        if (i == 0) continue;
        if (appearance[i].size() != appearance[i - 1].size()) throw std::runtime_error("Strings are not equal in length");
    }
    this->pAppearance = appearance;
    this->pHeight = static_cast<int>(this->pAppearance.size());
    this->pWidth = static_cast<int>(appearance[0].size());

    this->pXPosition = 0;
    this->pYPosition = 0;
}

Module::Module() {
    this->pHeight = 5;
    this->pWidth = 5;
    for (int i = 0; i < this->pHeight; ++i) {
        pAppearance.emplace_back(pWidth, EMPTY);
    }

    this->pXPosition = 0;
    this->pYPosition = 0;
}

vector<int> Module::size() const {
    vector<int> sizeVec = {
        pWidth,
        pHeight
    }; return sizeVec;
}

void Module::appearance(const vector<string>& appearance) {
    this->pAppearance = appearance;
    this->pHeight = static_cast<int>(this->pAppearance.size());
    this->pWidth = static_cast<int>(appearance[0].size());
}

vector<string> Module::appearance() const {
    return this->pAppearance;
}

auto Module::position() const -> vector<int> {
    vector<int> value = {pXPosition, pYPosition};
    return value;
}

void Module::position(int newXPosition, int newYPosition) {
    this->pXPosition = newXPosition;
    this->pYPosition = newYPosition;
}

void Module::draw() const {
    TuiTools::movCursorTo(this->pXPosition, this->pYPosition);

    int temp = this->pYPosition;
    for (const auto& i : this->pAppearance) {
        cout << i;
        temp++;
        TuiTools::movCursorTo(pXPosition, temp);
    }
}




