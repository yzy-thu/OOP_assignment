//
// Created by player1 on 2019/4/1.
//

#ifndef BIGHOMEWORK_OPERATOR_0_H
#define BIGHOMEWORK_OPERATOR_0_H

#include "../Node.h"
#include "../ts.h"

class Operator_0 : public Node{
public:
    Operator_0(std::string &name, Tensor x = 0.0):Node(name,x){}
    virtual int Compt(MyGraph &g, int x);
    virtual int Calc(MyGraph &g) = 0;
    virtual int Derivate(MyGraph& g){return 0;}

    virtual ~Operator_0(){};
};




#endif //BIGHOMEWORK_OPERATOR_0_H

