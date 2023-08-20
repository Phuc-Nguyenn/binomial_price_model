#include "Tree.hpp"
#include <iostream>

using namespace std;

Tree::Tree(): pi(0), u(0), d(0), R(0), S(0), K(0){}

Tree::Tree(float S, float K, float R, int N, float u, float d): u(u), d(d), R(R), S(S), K(K), N(N){
    this->pi = (R-d)/(u-d);
    init_nodes();
    calc_deriv_prices();
}

void Tree::print_vars(){
    std::cout << "pi: " << pi << std::endl
        << "u: " << this->u << std::endl
        << "d: " << this->d << std::endl
        << "R: " << this->R << std::endl
        << "S: " << this->S << std::endl
        << "K: " << this->K << std::endl
        << "N: " << this->N << std::endl;
}

/*initialises nodes and calculates underlying*/
void Tree::init_nodes(){
    //set values of first
    vector<Node> first_col(1);
    first_col[0].set_pos(0,0);
    first_col[0].set_S(this->S);
    this->tree.push_back(first_col);
    //loop for this number of time steps
    for(int n = 1; n <= this->N; n++){
        //for each time step add the right amount of nodes
        vector<Node> col(n+1);
        for(int j = 0; j < col.size(); j++){
            col[j].set_pos(n,j);
            if(j == 0 && n > 0) col[j].calc_share_price(this->tree[n-1][0], this->d);
            else col[j].calc_share_price(this->tree[n-1][j-1], this->u);   
        }
        this->tree.push_back(col);
    }

    //out put share prices
    // for(int n = 0; n <= this->N; n++){
    //     for(int j = 0; j < this->tree[n].size(); j++){
    //         std::cout << this->tree[n][j].get_share_price() << " \t";
    //     }
    //     std::cout << std::endl;
    // }
}

void Tree::calc_deriv_prices(){
    for(int n = this->N; n >= 0; n--){
        for(int j = 0; j < this->tree[n].size(); j++){
            if(n == this->N){
                this->tree[n][j].calc_expiry_deriv_price(this->K);
            }
            else
                this->tree[n][j].calc_deriv_price(R, pi, this->tree[n+1][j+1], this->tree[n+1][j]);
        }
    }
    //testing deriv price
    // std::cout << "\n";
    // for(int n = 0; n <= this->N; n++){
    //     for(auto node : this->tree[n]){
    //         std::cout << node.get_deriv_price() << " \t";
    //     }
    //     std::cout << std::endl;
    // }
}

Node &Tree::get_node(int n, int j){
    if(n >= 0 && n <= N && j >= 0 && j <= this->tree[n].size()){
        return(this->tree[n][j]);
    }
    else
        std::cout << "(n,j) bad parameters." << std::endl;
    return(this->tree[n][j]);
}

vector<float> Tree::get_node_info(int n, int j){
    vector<float> info;
    if(n >= 0 && n <= N && j >= 0 && j <= this->tree[n].size()){
        info.push_back(n);
        info.push_back(j);
        info.push_back(this->tree[n][j].get_share_price());
        info.push_back(this->tree[n][j].get_call_price());
        info.push_back(this->tree[n][j].get_put_price());
    }
    else
        std::cout << "(n,j) bad parameters." << std::endl;
    return(info);
}

void Tree::print_node_info(int n, int j){
    std::cout << "info for node (" << n << "," << j << ")" << std::endl;
    vector<float> node_info = get_node_info(n,j);
    std::cout << "(n,j) :\t\t" << "(" << node_info[0] << "," << node_info[1] << ")" << std::endl;
    std::cout << "S(n,j) :\t" << node_info[2] << std::endl;
    std::cout << "C(n,j) :\t" << node_info[3] << std::endl;
    std::cout << "P(n,j) :\t" << node_info[4] << std::endl;
}