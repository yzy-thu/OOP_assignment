//
// Created by HWY on 2019/3/30.
//INPUT
#include <iostream>
#include <map>
#include <string>
#include "Storage.h"
#include "CreateFunc.h"
//map string func*  ScanfMap

//create the map

void create_root(MyGraph& g)
{
    int n = 0;
    std::cin>>n;
    std::string tmpscanf[2];
    while(n--)
    {
        std::cin>>tmpscanf[0]>>tmpscanf[1];
        if(tmpscanf[1]=="P") create_placeholder(tmpscanf[0], g);
        if(tmpscanf[1]=="C") create_const(tmpscanf[0], g);
        if(tmpscanf[1]=="V") create_var(tmpscanf[0], g);
    }

}

void create_tree(MyGraph& g)
{

    std::map <std::string, void (std::string, MyGraph&)> ScanfMap1 = {
            {"SIN", create_sin},
            {"LOG", create_log},
            {"EXP", create_exp},
            {"TANH", create_tanh},
            {"SIGMOID", create_sigmoid},
            {"PRINT", create_print},
            {"COND", create_cond}
    };//match the func

    std::map <std::string, void (std::string, std::string, MyGraph&)> ScanfMap2 = {
            {"+", create_plus},
            {"-", create_minus},
            {"*", create_mul},
            {"/", create_div},
            {">", create_greater},
            {"<", create_lesser},
            {">=", create_greaterequal},
            {"<=", create_lessequal},
            {"==", create_equal}
    };// match the operator node build func

    std::string MyScanf[4]; //input string
    int m = 0;
    std::cin>>m;    //number of inputs
    while(m--)
    {
        std::cin>>MyScanf[0]>>MyScanf[1]>>MyScanf[2];//name & "=" & first word
        if(ScanfMap1.find(MyScanf[2]) == ScanfMap1.end())
        {
            std::cin>>MyScanf[3];
            ScanfMap2[MyScanf[3]](MyScanf[0], MyScanf[2], g);//怎么写...
        }
        else
        {
            ScanfMap1[MyScanf[2]](MyScanf[0], g);
        }
    }
}

