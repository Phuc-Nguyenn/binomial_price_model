#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <stdbool.h>
#include <math.h>
#include <algorithm>

using namespace std;

class Node
{
    private:
        float share_price;
        float deriv_price;
        int n;
        int j;
    public:
        Node(){};
        Node(int n, int j);
        Node(int n, int j, float S);

        float get_deriv_price(){ return(this->deriv_price);}
        float get_share_price(){ return(this->share_price);}
        vector<int> get_pos();
        void calc_share_price(Node& prev, int factor);
        void calc_deriv_price(float R, float pi, Node& next_up, Node& next_down);
        void calc_expiry_deriv_price(float K);
        void set_S(float S){this->share_price = S;};
        void set_pos(int n, int j){this->n = n; this->j = j;};
        ~Node(){};
};

#endif