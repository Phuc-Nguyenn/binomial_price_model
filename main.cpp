#include "Tree.hpp"
#include "Node.hpp"
#include <iostream>


int main(){
    float S = 15;
    float K = 13;
    int N = 10;
    float u = 1.03;
    float d = 0.96;
    float R = 1.02;

    Tree Tree(S, K, R, N, u, d);
    Tree.print_vars();
    Tree.init_nodes();
    float premium = Tree.find_premium();
    
    std::cout << "\nthe premium of the call option is: " << premium << std::endl;
    return(0);
}