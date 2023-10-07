#ifndef __FLOYD_ALGORITHM_HPP__
#define __FLOYD_ALGORITHM_HPP__

#include <stack>
#include <utility>
#include <valarray>

#include "graph.hpp"
#include "graph_utils.hpp"

/**
 * @brief Compute the weight matrix.
 * @arg[in] g is a weighted graph.
 * @arg[out] W is the Weight matrix.
 */
template<class T>
void compute_weight_matrix(WGraph<T>& g, FMatrix& W){
    W=FMatrix(g.size(), g.size(), std::numeric_limits<float>::infinity());

    //Hint: scan all the edges. Use the node.label() to index the matrix.
    //Hint: Assume the graph is directed.
    //Hint: Review how to move the cursors.
 	typename WGraph<T>::NodeRef u, v;  
    for(size_t x=0; x<g.size(); x++){
        for(size_t y=0; y<g.size(); y++){
            if(x!=y){
                u=g.node(x);
                v=g.node(y);
                if(g.are_adjacent(u, v))
                    W[x][y]=g.weight(u, v);
            }
        }
    }
}

/**
 * @brief Search for the minium path between vertices using the Floyd's algorithm.
 * @arg[in] g is a weighted graph.
 * @arg[out] D is the Distances matrix.
 * @arg[out] I is the Intermediate matrix.
 * @pre the weigths meet the triangular inequality: d(u,v) <= d(u,k) + d(k,v) for all u!=v!=k.
 * @post if none path between u,v exists then D[u][v]==inf and I[u][v]==-1
 * @post if an edge (u,v:w) exists then D[u][v]==w and I[u][v]==-1
 * @post if a path between u,v exits then D[u][v]<inf and D[u][v]==k, k is vertex in the minimum path linking u with v.
 */
template<class T>
void floyd_algorithm(WGraph<T>& g, FMatrix& D, IMatrix& I){
    compute_weight_matrix<T>(g, D);
    //Set self-distances to zero.
    for (size_t i=0;i<g.size();++i)
        D[i][i]=0.0;

    I=IMatrix(g.size(), g.size(), -1);

 	for(size_t x=0; x<g.size(); x++){
        for(size_t y=0; y<g.size(); y++){
            for(size_t z=0; z<g.size(); z++){
                if(D[y][x]+D[x][z]<D[y][z]){
                    D[y][z]=D[y][x]+D[x][z];
                    I[y][z]=x;
                }
            }
        }
    }
}

/**
 * @brief Given the Floyd's Intermidiate matrix, compute the path.
 * @arg[in] u is the label of the start vertex.
 * @arg[in] v is the label of the end vertex.
 * @arg[in] I is the Floyd's Intermidiate matrix.
 * @arg[out] path is a vector with the sequence of vertex's labels for
 *           the minimum path linking u with v.
 * @pre Let D be the Floyd's D matrix corresponding with I, D[u][v]<inf.
 * @post u is the first item of path.
 * @post v is the last item of path.
 */
inline void
floyd_compute_path(size_t u, size_t v, IMatrix const& I,
                   std::vector<size_t>& path){
    //Prec: distance (u,v)<inf
    std::stack<std::pair<size_t, size_t>> s;
    path.resize(0);
 
    //Hint: Think first. Is it necessary to build a binary tree? or it
    //is enough to do an in-depth search using an iterative approach with
    //a stack of pairs (u->v).
    std::pair <size_t,size_t> node (u,v);
    std::vector<size_t>::iterator ite;
    size_t origen, destino;
    bool computed=false;
    s.push(std::make_pair(u,v));
    while(!s.empty()){
    	origen=(s.top()).first;
        destino=(s.top()).second;
        s.pop();
        if(I[origen][destino]==-1){
            computed=false;
            for(ite=path.begin(); ite!=path.end(); ite++){
            	if(*ite==origen)
                	computed=true;
            }
            if(computed==false){
            	path.push_back(origen);
            }
            path.push_back(destino);
        }
        else{
        	s.push(std::make_pair(I[origen][destino],destino));
        	s.push(std::make_pair(origen,I[origen][destino]));
        }
    }
}


#endif //__FLOYD_ALGORITHM_HPP__
