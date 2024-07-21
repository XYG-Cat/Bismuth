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


#ifndef MODULE_H_
#define MODULE_H_

#define EMPTY '#'

#include <vector>
#include <string>

using std::vector;
using std::string;

class Module {
    private:
    int pWidth;
    int pHeight;
    vector<string> pAppearance; // 模块的形状

    int pXPosition;
    int pYPosition;
        
    public:
    Module(const vector<string>& appearance, int xPosition, int yPosition);
    // 如果传入空vector会抛出run_time_error "A empty appearance vector"
    // 如果传入不整齐的vector会抛出run_time_error "Strings are not equal in length"
    explicit Module(const vector<string>& appearance);
    Module();

    vector<int> size() const;

    auto appearance() const -> vector<string>;
    void appearance(const vector<string>& appearance);

    auto position() const -> vector<int>;
    void position(int newXPosition, int newYPosition);

    void draw() const;

    void loadInText() const;
};

#endif
// MODULE_H_