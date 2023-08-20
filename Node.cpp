#include "Node.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

Node::Node(int n, int j): n(n), j(j), share_price(0), call_price(0), put_price(0){}

Node::Node(int n, int j, float S): n(n), j(j), share_price(S){}


std::vector<int> Node::get_pos(){
    std::vector<int> pos(2);
    pos.push_back(this->n);
    pos.push_back(this->j);
    return(pos);
}

void Node::calc_share_price(Node& prev, float factor){
    this->share_price = prev.share_price * factor;
}

void Node::calc_deriv_price(float R, float pi, Node& next_up, Node& next_down){
    this->call_price = (1/R) * (pi * next_up.call_price + (1-pi) * next_down.call_price);
    this->put_price = (1/R) * (pi * next_up.put_price + (1-pi) * next_down.put_price);
}

void Node::calc_expiry_deriv_price(float K){
    this->call_price = this->share_price-K > 0 ? this->share_price-K : 0;
    this->put_price = K-share_price > 0 ? K-share_price : 0;
}