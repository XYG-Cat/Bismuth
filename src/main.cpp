#include <iostream>

#include "Bismuth/Module.h"
#include "Bismuth/WorkSpace.h"


using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int main() {
    WorkSpace a;
    a.draw();
    vector<string> b_dis {"MMMMM",
                          "MMMMM"};
    Module b(b_dis, 10, 10);
    b.draw();

	cin.get();
}