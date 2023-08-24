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
        std::vector<std::vector<Node>> tree;
        float pi;
        float u;
        float d;
        float R;
        float S;
        float K;
        int N;
        void init_nodes();
        void calc_deriv_prices();

    public:
        /*Tree(share price, strike price, return, time_steps, up factor, down factor)*/
        Tree();
        Tree(float S, float K, float R, int N, float u, float d);
        void print_vars();

        float get_call_premium() {return(this->tree[0][0].get_call_price());};
        float get_put_premium() {return(this->tree[0][0].get_put_price());};
        float get_a_put_premium() {return(this->tree[0][0].get_a_put_price());};

        Node &get_node(int n, int j);
        std::vector<float> get_node_info(int n, int j);
        void print_node_info(int n, int j);
};

#endif