#include <iostream>
#include <vector>
#include "Storage.h"
#include <stdio.h>
#include <ctime>
#include "test_minst.h"

int main()
{
    std::srand(std::time(0));
    MyGraph i_love_compute;
    //i_love_compute.create_root();//const or var or placeholder
    //i_love_compute.create_tree();//others
    //i_love_compute.graph_compute();//compute

    test_MINST();

    return 0;
}