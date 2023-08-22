# ifndef GRAPH_GRAPHWITHMATRIX_H
# define GRAPH_GRAPHWITHMATRIX_H
# include <vector>
# include <iostream>
# include <iomanip>
using namespace std ;

class GraphWithMatrix {
    int** edges ;
    int size ;

public:
    explicit GraphWithMatrix(int size){
        edges = new int* [size] ;

        for (int i = 0; i < size; ++i) {
            edges[i] = new int [size] ;
        }

        this->size = size ;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                edges[i][j] = 0 ;
            }
        }
    }

    void addEdge(int source, int destination){
        edges[source][destination] = 1 ;
        edges[destination][source] = 1 ;
    }

    void printGraph(){
        cout << "   " ;
        for (int i = 0; i < size; ++i) {
            cout << i << ' ' ;
        }
        cout << '\n' << setw(size * 2 + 2) << setfill('-') << '-' ;

        for (int i = 0; i < size; ++i) {
            cout << '\n' << i << "| " ;

            for (int j = 0; j < size; ++j) {
                cout << edges[i][j] << " " ;
            }
        }

        cout << '\n' ;
    }
};

#endif //GRAPH_GRAPHWITHMATRIX_H