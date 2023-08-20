#include "Tree.hpp"
#include "Node.hpp"
#include <iostream>


int main(){
    float S = 4;
    float K = 3;
    int N = 3;
    float u = 2;
    float d = 0.5;
    float R = 1.25;

    Tree Tree(S, K, R, N, u, d);


    Tree.print_vars();
    Tree.init_nodes();
    float premium = Tree.find_premium();

    std::cout << premium << std::endl;
    std::cout << "done" << std::endl;
    return(0);
}