/*!
 * Este é um código para medir o tempo de execução dos algoritmos de busca(linear search, binary search e binary search recursive), aumentando progressivamente o tamanho da matriz de entrada e armazenando o tempo de execução dessa instância.
 * I'm using the chrono C++ library.
 * \file timing_template.cpp
 * \author Neylane Lopes
 * \date June 22th, 2021.
 */

#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
#include <fstream>

#include "searching.h"


/**
 * @brief Enum para representar cada algoritmo de busca
 * 
 */
enum tipo_de_busca
{   
    linear_search,
    binary_search,
    binary_search_recursive,
};

/**
 * @brief Mede o tempo de execusão do algoritmo de busca e salva em um arquivo no formato csv
 * 
 * @param funcao_de_busca Qual função de busca deve ser executada
 * @param arquivo Stream associada a um arquivo
 * @param first Ponteiro para o primeiro elemento do vetor
 * @param last Ponteiro para a posição logo após o último elemento do vetor
 * @param destino_de_busca Valor que deve ser procurado no vetor
 * 
 */
void MedirESalvarTempo (int * ( * funcao_de_busca ) ( int * first, int * last, int value ), std::ofstream &arquivo, int * first, int * last, int &destino_de_busca)
{
    for ( int i=0; i<10; ++i){
        auto start = std::chrono::steady_clock::now();
        last = funcao_de_busca( first , last, destino_de_busca);

        std::chrono::time_point<std::chrono::steady_clock> end  = std::chrono::steady_clock::now();

        std::chrono::duration<double> diff = end - start;
        arquivo << "_" << std::chrono::duration <double, std::milli> (diff).count();
    }
}

/**
 * @brief Decide qual algoritmo de busca deve ser executado e realiza a chamada da função MedirESalvarTempo
 * 
 * @param enumBusca Enum para identificar qual algoritmo de busca deve ser executada
 * @param arquivo Stream associada a um arquivo
 * @param first Ponteiro para o primeiro elemento do vetor
 * @param last Ponteiro para a posição logo após o último elemento do vetor
 * @param tamanho Tamanho do vetor
 * @param destino_de_busca Valor que deve ser procurado no vetor
 * 
 */
void ExecutarBusca (const tipo_de_busca &enumBusca, std::ofstream &arquivo, int * first, int * last, size_t &tamanho, int &destino_de_busca)
{
    arquivo << std::endl << tamanho;

    if(enumBusca == linear_search){
        MedirESalvarTempo (sa::lsearch, arquivo, first, last, destino_de_busca);
    }
    else if(enumBusca == binary_search){
        MedirESalvarTempo (sa::bsearch, arquivo, first, last, destino_de_busca);
    }
    else if(enumBusca == binary_search_recursive){
        MedirESalvarTempo (sa::bsearchR, arquivo, first, last, destino_de_busca);
    }
}

/**
 * @brief Cria um aquivo no formato csv com o nome de acordo com o algoritmo de busca que vai ser executado
 * 
 * @param enumBusca Enum para identificar qual algoritmo de busca deve ser executada
 * @param arquivo Uma variável do tipo ofstream, ou seja, stream associada a um arquivo
 * 
 */
void CriarArquivo (const tipo_de_busca &enumBusca, std::ofstream &arquivo)
{   
    if(enumBusca == linear_search){
        arquivo.open("csv/linear_search.csv");
    }
    else if(enumBusca == binary_search){
        arquivo.open("csv/binary_search.csv");
    }
    else if(enumBusca == binary_search_recursive){
        arquivo.open("csv/binary_search_recursive.csv");
    }
    arquivo << "#_tempo1_tempo2_tempo3_tempo4_tempo5_tempo6_tempo7_tempo8_tempo9_tempo10";
}

/**
 * @brief Adiciona elementos de um intervalo no vetor de entrada, além disso, chama as funções CriarArquivo e ExecutarBusca
 * 
 * @param enumBusca Enum para identificar qual algoritmo de busca deve ser executada
 * @param minimo Primeiro elemento do vetor
 * @param maximo Último elemento do vetor(tamanho do vetor)
 * @param intervalo Valores que vão ser incrementados no vetor
 * 
 */
void ProduzirEntrada (const tipo_de_busca &enumBusca, size_t &minimo, size_t &maximo, size_t &intervalo)
{
    std::ofstream arquivo;
    CriarArquivo (enumBusca, arquivo);

    std::vector <int> vetor(minimo);
    int destino_de_busca = -1;

    for (size_t i=minimo; i<=maximo; i+=intervalo){
        if (i != minimo){
            vetor.resize(i);
            for (size_t j=0; j<intervalo; ++j){
                vetor.push_back(j);
            }  
        }
        else if(i == minimo){
            for (size_t k=0; k<minimo; ++k){
                vetor.push_back(k);
            }
        }
        
        ExecutarBusca (enumBusca, arquivo, &vetor[0], &vetor[i], i, destino_de_busca);
    }
        
    vetor.clear();
    arquivo.close();
}

int main (void)
{   
    size_t minimo = pow(10, 4);
    size_t maximo = pow(10, 8);
    size_t intervalo = (maximo-minimo)/80;

    ProduzirEntrada (linear_search, minimo, maximo, intervalo);

    ProduzirEntrada (binary_search, minimo, maximo, intervalo);

    ProduzirEntrada (binary_search_recursive, minimo, maximo, intervalo);

    return 0;
}