//
// Created by player0 on 2019/3/31.
//

#include "myexp.h"
MyExp::MyExp(std::string &s, int x) : Operator_1(s, x){}

int MyExp::Calc(MyGraph &v) {
    val = ts::exp(v[num].NodePos->Val());
    return 0;
}

int MyExp::Derivate(MyGraph& v)
{
    v[num].NodePos-> add_der(ts::point_mul(ts::exp(v[num].NodePos->Val()), der));
    return 0;
}