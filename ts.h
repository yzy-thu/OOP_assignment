//
// Created by hwy on 2019/5/22.
//

#ifndef OOP_TS_H
#define OOP_TS_H

#include<utility>
#include<vector>
class Tensor;
class Matrix;

//namespace created for Tensor computation
namespace ts
{
    Matrix sin(const Matrix &);
    Matrix cos(const Matrix &);
    Matrix exp(const Matrix &);
    Matrix log(const Matrix &);
    Matrix sigmoid(const Matrix &);
    Matrix tanh(const Matrix &);
    Matrix abs(const Matrix &);
    Matrix point_mul(const Matrix &, const Matrix &);
    Matrix mat_mul(const Matrix&, const Matrix & );

    Matrix concat(const Matrix & a, const Matrix & b, const int catdim);
    Matrix trans(const Matrix &);

    Tensor max_T(Tensor, Tensor);
    Tensor sin(const Tensor &);
    Tensor cos(const Tensor &);
    Tensor exp(const Tensor &);
    Tensor log(const Tensor &);
    Tensor sigmoid(const Tensor &);
    Tensor tanh(const Tensor &);
    Tensor abs(const Tensor &);
    Tensor point_mul(const Tensor &, const Tensor &);

    Tensor randn(std::initializer_list<int> szlist = {1, 1});
    Tensor concat(const Tensor & a, const Tensor & b, const int catdim);
    Tensor trans(const Tensor &);

    bool need_broadcast(const Tensor &, const Tensor &);
    void broadcast(int now_dim, Tensor &new_A, const Tensor &A, int pos);
    void broadcast(int now_dim, Matrix &new_A, const Matrix &A, int pos);
    std::pair<Tensor, Tensor>broadcast(Tensor A, Tensor B);

    int get_max_pos_2d(Tensor& a);//for 2d Tensor, the position of the max element

    bool check_shape(const Tensor & obj1, const Tensor & obj2);
}

#endif //OOP_TS_H
