//
// Created by player0 on 2019/3/31.
//

#include "mylog.h"

MyLog::MyLog(std::string &s, int x): Operator_1(s, x){}

int MyLog::Calc(MyGraph &v) {
    val = ts::log(v[num].NodePos->Val());
    return 0;
}

int MyLog::Derivate(MyGraph& v){
    v[num].NodePos-> add_der(Tensor(1.0)/v[num].NodePos->Val() * der);
    return 0;
}