#include "Tree.hpp"
#include "Node.hpp"
#include <iostream>

/*documentation:
 * the parameters
 *      S: share price
 *      K: strike price
 *      N: number of time steps
 *      u: up factor
 *      d: downfactor
 *      R: risk free return rate
 *
 *  functions
 *  Tree.get_call_premium()     gets the premium of a call option with given parameters
 *  Tree.get_put_premium()      gets the premium of a put option with given parameters
 *  Tree.print_node_info(n,j)   prints the information of node n,j
 *  Tree.get_node_info(n,j)     similar to print_node_info(n,j) except it returns a vector 
 *  Tree.print_vars()           prints the parameters of the derivative
 */


int main(){
    float   S = 2.0f;
    float   K = 19.0f;
    int     N = 2;
    float   u = 2/3;
    float   d = 0.96;
    float   R = 1.1;
    Tree Tree(S, K, R, N, u, d);
    
    std::cout << "\nthe premium of the European call option C(0,0) is: " << Tree.get_call_premium() << std::endl;
    std::cout << "the premium of the European put option P(0,0) is: " << Tree.get_put_premium() << "\n";
    std::cout << "the premium of the American put option P(0,0) is: " << Tree.get_a_put_premium() << "\n\n";
    while(1){
        std::cout << "info for what node..? n [enter] j" << std::endl;
        int n;
        int j;
        std::cin >> n >> j;
        Tree.print_node_info(n,j);
        std::cout<< std::endl;
    }

    return(0);
}