# binomial_price_model~~~~~~~~~~~~~~~~~~~~~~~~~~
options pricing model based on the Cox Ross Reubenstein model

Binomial Price Model for Options Pricing
Overview
This project implements the Cox Ross Reubenstein model, a binomial options pricing model. It calculates the premium of call and put options based on user-defined parameters like share price, strike price, number of time steps, up factor, down factor, and the risk-free return rate.

Parameters~~~~~~~~~~~~~~~~~~~~~~~~~~
The model takes the following parameters:

S: Share price
K: Strike price
N: Number of time steps
u: Up factor
d: Down factor
R: Risk-free return rate
Functions
The implemented functions are:

Tree.get_call_premium(): Calculates the premium of a call option with given parameters.
Tree.get_put_premium(): Calculates the premium of a put option with given parameters.
Tree.print_node_info(n,j): Prints the information of node n,j in the binomial tree.
Tree.get_node_info(n,j): Similar to print_node_info(n,j) but returns a vector with node information.
Tree.print_vars(): Prints the parameters of the derivative.


Usage~~~~~~~~~~~~~~~~~~~~~~~~~~
Type make in the terminal to compile. Then simply run the executable.

To use this binomial price model, follow these steps:

Set the parameters (S, K, N, u, d, R) in the main or your desired program file.
Create a Tree object.
Call the necessary functions to calculate option premiums or print node information as needed.
