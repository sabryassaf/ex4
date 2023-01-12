
#include <stdio.h>
#include <iostream>
#include "Dragon.h"

using std::cout;
using std::endl;

int main()
{
    cout << "Test" << endl;
    Dragon dragon("Dragon");
    Player player("mezdayen");
    dragon.applyCard(player);
    return 0;
}