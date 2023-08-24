#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <stdbool.h>
#include <math.h>
#include <algorithm>

class Node
{
    private:
        float share_price;
        float call_price;
        float put_price;

        float a_put_price;
        int n;
        int j;
    public:
        Node(){};
        Node(int n, int j);
        Node(int n, int j, float S);

        float get_call_price(){ return(this->call_price);};
        float get_put_price(){ return(this->put_price);};
        float get_a_put_price(){ return(this->a_put_price);};

        float get_share_price(){ return(this->share_price);};
        std::vector<int> get_pos();
        void calc_share_price(Node& prev, float factor);
        void calc_deriv_price(float K, float R, float pi, Node& next_up, Node& next_down);
        void calc_expiry_deriv_price(float K);
        void set_S(float S){this->share_price = S;};
        void set_pos(int n, int j){this->n = n; this->j = j;};
        ~Node(){};
};

#endif