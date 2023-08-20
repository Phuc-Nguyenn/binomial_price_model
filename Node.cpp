#include "Node.hpp"
#include <vector>
#include <algorithm>

Node::Node(int n, int j): n(n), j(j), share_price(0), deriv_price(0){}

Node::Node(int n, int j, float S): n(n), j(j), share_price(S){}


std::vector<int> Node::get_pos(){
    std::vector<int> pos(2);
    pos.push_back(this->n);
    pos.push_back(this->j);
    return(pos);
}

void Node::calc_share_price(Node& prev, int factor){
    this->share_price = prev.share_price * factor;
}

void Node::calc_deriv_price(float R, float pi, Node& next_up, Node& next_down){
    this->deriv_price = (1/R) * (pi * next_up.deriv_price + (1-pi) * next_down.deriv_price);
}

void Node::calc_expiry_deriv_price(float K){
    this->deriv_price =K-this->share_price > 0 ? K-this->share_price : 0;
}