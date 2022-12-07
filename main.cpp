 #include <iostream>
#include "Graph.h"
#include "Graph.cpp"

using std::cout;

int main( ){
    Graph grafo( true );// é direcionado
    grafo.adicionarArestas( 'A', 'I', 10 );
    grafo.adicionarArestas( 'A', 'F', 4 );
    grafo.adicionarArestas( 'A', 'G', 5 );
    grafo.adicionarArestas( 'C', 'A', 4 );
    grafo.adicionarArestas( 'D', 'A', 6 );

    grafo.printListaAdjacencia( );
    //grafo.grauVerticeNaoDirecionado( 'A' );
    grafo.grauVerticeDirecionado( 'A');

    grafo.printListaAdjacencia( );
    grafo.retirarAresta( 'A', 'F', 6 );
    cout << "\n";
    grafo.printListaAdjacencia( );
    cout << "\n" << grafo.getNumArestas( ) << "\n";
    //cout << "\n" << grafo.getNumVertices( ); // em processo...
    grafo.obterListaAdjacencia( 'A' );
   
    return 0;
};
