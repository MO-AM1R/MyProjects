# ifndef GRAPH_GRAPHWITHLIST_H
# define GRAPH_GRAPHWITHLIST_H
# include <vector>
# include <iostream>
using namespace std ;

class GraphWithList {
    vector<int>* edges ;
    int size ;

public:
    explicit GraphWithList(int size){
            edges = new vector<int> [size] ;
        this->size = size ;
    }

    void addEdge(int source, int destination){
        edges[source].push_back(destination) ;
        edges[destination].push_back(source) ;
    }

    void printGraph(){
        for (int i = 0; i < size; ++i) {
            cout << "\n Adjacency list of vertex " << i
                 << "\n head";

            if ((int)edges[i].size() > 0) {
                for (int ele: edges[i]) {
                    cout << " -> " << ele;
                }

                cout << "\n";
            }
            else{
                cout << " -> No Edges\n" ;
            }
        }
    }
};

#endif //GRAPH_GRAPHWITHLIST_H