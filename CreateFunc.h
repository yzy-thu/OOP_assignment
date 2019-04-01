//
// Created by WLY on 2019/4/1.
//

#ifndef BIGHOMEWORK_CREATEFUNC_H
#define BIGHOMEWORK_CREATEFUNC_H
#include "Storage.h"

void create_placeholder(std::string& name, MyGraph& g);
void create_const(std::string& name, MyGraph& g);
void create_var(std::string& name, MyGraph& g);
void create_sin(std::string& name, MyGraph& g);
void create_log(std::string& name, MyGraph& g);
void create_exp(std::string& name, MyGraph& g);
void create_tanh(std::string& name, MyGraph& g);
void create_sigmoid(std::string& name, MyGraph& g);
void create_print(std::string& name, MyGraph& g);
void create_plus(std::string& name, MyGraph& g);
void create_minus(std::string& name, MyGraph& g);
void create_mul(std::string& name, MyGraph& g);
void create_div(std::string& name, MyGraph& g);
void create_greater(std::string& name, MyGraph& g);
void create_lesser(std::string& name, MyGraph& g);
void create_greaterequal(std::string& name, MyGraph& g);
void create_lessequal(std::string& name, MyGraph& g);
void create_equal(std::string& name, MyGraph& g);
void create_cond(std::string& name, MyGraph& g);

#endif //BIGHOMEWORK_CREATEFUNC_H
