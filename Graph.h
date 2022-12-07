#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <string>

using std::cout;
using std::string;
using std::list;
using std::map;
using std::pair;

typedef char Vertice;
typedef int Peso;

class Graph{
    public:
        //   vertice -> aresta -> ( vertice, peso ) 
        map< Vertice, list< pair< Vertice, Peso >>> listaAdjacencias;
        Graph( );
        Graph( bool digrafo );// o numero de vertices cresce dinamicamente
        
        void adicionarArestas( Vertice posicaoX, Vertice posicaoY, Peso peso );
        
        void retirarAresta( Vertice, Vertice, Peso );
        bool existeAresta( Vertice, Vertice );
        void grauVerticeNaoDirecionado( Vertice );
        void grauVerticeDirecionado( Vertice );
        
        // exibir 
        void obterListaAdjacencia( Vertice );
        void printListaAdjacencia( );

        // get's
        bool getDigrafo( ){ return this->digrafo; }
        static int getNumVertices( ){ return numVertices; }// falta resolver 
        static int getNumArestas( ){ return numArestas; } 
    private:
        bool digrafo;
        static int numVertices;
        static int numArestas;
};

#endif /* GRAPH_H */ 