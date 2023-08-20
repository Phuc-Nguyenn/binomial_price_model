#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <algorithm>
#include <math.h>
#include "Node.hpp"
#include <iostream>

class Tree
{
    private:
        vector<vector<Node>> tree;
        float pi;
        float u;
        float d;
        float R;
        float S;
        float K;
        int N;

    public:
        /*Tree(share price, strike price, return, time_steps, up factor, down factor)*/
        Tree();
        Tree(float S, float K, float R, int N, float u, float d);
        void print_vars();

        void init_nodes();
        float find_premium();
};

#endif