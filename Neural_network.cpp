//
// Created by yzy on 2019/5/3.
//

#include "Neural_network.h"
#include <algorithm>
#include <iostream>
#define INF 1E9
int Neural_network::output(int j)
{
    return seq[seq.size() - 1]->output(j);
}
void Neural_network::add_Input(int num, MyGraph& G)
{
    seq.push_back(new Input(num, G));
}
void Neural_network::add_Dense(int num, MyGraph &G)
{
    Layer* tmp = seq.back();
    seq.push_back(new Dense(tmp->get_size(), num, *tmp, G));
}

void Neural_network::train(const std::vector<std::vector<double>> &InputData, const std::vector<double> &TargetData, MyGraph &G, int epoch, int batchsize)
{
    double learn_rate = 0.3;int out_num = seq[seq.size() - 1]->get_size();
    for(int time = 1; time <= epoch; time++)
    {
        double cnt_correct = 0.0;
        for(int num = 0; num < InputData.size(); num++)
        {
            std::vector<double>labels(out_num);
            labels[TargetData[num]] = 1.0;

            seq[0]->change_input(InputData[num], G);
            for (auto i: G.NodeInfoVec)
            {
                i.NodePos->rev_der(0);
            }

            G.erase_mark();
            double mx = -INF; int id = 0;
            for (int i = 0; i < out_num; i++)
            {
                int pos = output(i);
                Node *OutputNode = G.NodeInfoVec[pos].NodePos;
                OutputNode->Compt(G, pos);
                if(OutputNode->Val() > mx)
                {
                    mx = OutputNode->Val();
                    id = i;
                }
            }
            if(id == TargetData[num])cnt_correct += 1.0;
            for (int i = 0; i < out_num; i++)
            {
                int pos = output(i);
                G.DerVec.clear();
                G.erase_der();
                Node *OutputNode = G.NodeInfoVec[pos].NodePos;
                OutputNode->rev_der(1);
                reverse(G.DerVec.begin(), G.DerVec.end());
                for (auto j: G.DerVec) {
                    G.NodeInfoVec[j].NodePos->Derivate(G);
                }
                double delta = G.NodeInfoVec[pos].NodePos->Val() - labels[i];
                for (auto j: G.NodeInfoVec)
                {
                    j.NodePos->add_dersum(delta * j.NodePos->Der());
                }
            }



            if((num + 1) % batchsize == 0 || num == InputData.size() - 1)
            {
                for (int i = 1; i < out_num; i++)
                {
                    auto nowd = dynamic_cast<Dense *>(seq[i]);
                    for (auto j: nowd->W)
                    {
                        Node *nown = G.NodeInfoVec[j].NodePos;
                        nown->add_val(-nown->DerSum() * learn_rate / batchsize);
                    }
                }
                for (auto i: G.NodeInfoVec)i.NodePos->rev_dersum(0);
            }
        }
        std::cout << "epoch::" << time << " " << "accuracy:" << cnt_correct/InputData.size() << std::endl;
    }
}

void Neural_network::test(const std::vector<std::vector<double>> &InputData, const std::vector<double> &TargetData, MyGraph &G)
{
    double cnt_correct = 0.0;int out_num = seq[seq.size() - 1]->get_size();
    for(int num = 0; num < InputData.size(); num++)
    {
        seq[0]->change_input(InputData[num], G);
        G.erase_mark();
        double mx = -INF; int id = 0;
        for (int i = 0; i < out_num; i++)
        {
            int pos = output(i);
            Node *OutputNode = G.NodeInfoVec[pos].NodePos;
            OutputNode->Compt(G, pos);
            if(OutputNode->Val() > mx)
            {
                mx = OutputNode->Val();
                id = i;
            }
        }
        if(id == TargetData[num])cnt_correct += 1.0;
    }
    std::cout << "accuracy:" << cnt_correct/InputData.size() << std::endl;
}