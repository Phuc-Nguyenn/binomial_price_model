#include "Tree.hpp"
#include <iostream>

Tree::Tree(): pi(0), u(0), d(0), R(0), S(0), K(0){}

Tree::Tree(float S, float K, float R, int N, float u, float d): u(u), d(d), R(R), S(S), K(K), N(N){
    this->pi = (R-d)/(u-d);
}

void Tree::print_vars(){
    std::cout << "pi: " << pi << std::endl
        << "u: " << u << std::endl
        << "d: " << d << std::endl
        << "R: " << R << std::endl
        << "S: " << S << std::endl
        << "K: " << K << std::endl;
}