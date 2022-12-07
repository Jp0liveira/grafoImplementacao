#include "Graph.h"

// Inicio - Primeira parte 

int Graph::numArestas = 0;
int Graph::numVertices = 0;

Graph::Graph( ){ this->digrafo = true; };

Graph::Graph( bool digrafo ){
    this->digrafo = digrafo;
};

// adicionar arestas e seu peso
void Graph::adicionarArestas( Vertice posicaoX, Vertice posicaoY, Peso peso ){
    listaAdjacencias[ posicaoX ].push_back( std::make_pair( posicaoY, peso ) );
    if( !digrafo && listaAdjacencias[ posicaoX ] == listaAdjacencias[ posicaoY ] ){// digrafo ( direcionado ) - não digrafo - false - ( não aceita self-loop )
        cout << "\n[ERRO!] Grafos NÃO DIRECIONADOS não aceitam Self-Loops ";
        return;
    } 
    if ( !digrafo ){
        listaAdjacencias[ posicaoY ].push_back( std::make_pair( posicaoX, peso ) );
    }
    numArestas++;
};

// remove arestas e o peso
void Graph::retirarAresta( Vertice arestaX, Vertice arestaY, Peso peso ){
    for ( auto key: listaAdjacencias ){
        if ( key.first == arestaX ){
            for ( auto arestas: key.second ){
                if ( arestas.first == arestaY && arestas.second == peso ){
                    listaAdjacencias[ arestaX ].remove( std::make_pair( arestaY, peso ) );
                }
            }
        }
    }
 };

// verifica a existencia de arestas
bool Graph::existeAresta( Vertice arestaX, Vertice arestaY ){
    for ( auto key: listaAdjacencias ){
        if ( key.first == arestaX ){
            for ( auto value: key.second ){
                if ( value.first == arestaY ){
                     cout << "Aresta: " << value.first << "[" <<value.second << "]-> ";
                }
            }
        }
    }
    return false;
};

// obtem o grau de um vertice não direcionado
void Graph::grauVerticeNaoDirecionado( Vertice verticeX ){
    int grauVertice = 0;
    if ( !digrafo ){
        for ( auto key: listaAdjacencias ){
            if ( key.first == verticeX ){
                for ( auto value: key.second ){
                    grauVertice++;
                }
                cout << "\n" << grauVertice << "\n";
                return;
            }
        }
    }else{
        grauVerticeDirecionado( verticeX );
    }
};

// obtem o grau de entrada e saida de um grafo direcionado
void Graph::grauVerticeDirecionado( Vertice verticeX ){
     int grauEntrada = 0;
     int grauSaida = 0;
     if ( digrafo ){
        for ( auto key: listaAdjacencias ){
            for ( auto value: key.second ){ 
                if ( key.first == verticeX ){
                        grauSaida++;
                } 
                if ( value.first == verticeX ){
                    grauEntrada++;
                }          
            }
        }
        cout << "\nGrau de Entrada: " << grauEntrada;
        cout << "\nGrau de Saida: " << grauSaida<< "\n";
     }else{
        grauVerticeNaoDirecionado( verticeX );
     }
};

// obtem a lista de adjacencias de um vertice
void Graph::obterListaAdjacencia( Vertice vertice ){
    for ( auto key: listaAdjacencias ){
        if ( key.first == vertice ){
             cout << key.first << "--> ";
            for ( auto adjacencias: key.second ){
                 cout << adjacencias.first << "[" << adjacencias.second << "]-> ";
            }
            cout << "\n";
            return;
        }
    }
};

// exibir a lista de adjacencias 
void Graph::printListaAdjacencia( ){
    for ( auto key: listaAdjacencias ){
        cout << key.first << " --> ";// vertice a ser percorrido ( vertice -> aresta -> )
        for ( auto adjacencias: key.second ){
            // lista de adjacencias[peso] ( vertice, peso )
            cout << adjacencias.first << "[" << adjacencias.second << "]-> ";
        }
        cout << "\n";
    }
};
// Fim - Primeira parte 

// Inicio - Segunda parte 
    // Busca em profundidade_DFS

    //Busca em Largura_BFS




