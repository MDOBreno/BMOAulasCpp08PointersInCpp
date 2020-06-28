//
//  main.cpp
//  BMOAulasCpp08PointersInCpp
//
//  Created by Breno Medeiros on 28/06/20.
//  Copyright © 2020 ProgramasBMO. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //Na memoria de computador, todos os tipos da dados são representados por numeros
    // Nesta linha abaixo estamos apenas definindo que não importa como seja definido
    // para nos humanos, apenas aloque algum espaco na memoria minimo para preenchermos
    // com alguma indormação.
    void* ptrNull = nullptr; //Quando inicializamos com '0' ou 'nullptr', dizemos que é invalido
    
    int var = 5;
    
    //Repare que, pelo processador/memoria ter enereco de 64bis(=8 Bytes), os 8 primeiros Bytes...
    void* ptrVoid = &var;      //...dessa variavel e da proxima são exatamente iguais.
    int*  ptrInt = &var;      //Note(Debug) tb que não há diferença entre esse ponteiro e o anterior...
    // ...independentemente do tipo[int, void,..] escolhido para armazenar o ponteiro.
    //Reflexão: Se podemos compilar o mesmo codigo tanto para processadores com endereço
    // 64bit(=8 Bytes) quanto para 32bits(=4 Bytes), como saber qual tipo de dado devemos usar
    // para conseguir o numero certo de bytes que contenham o mesmo numero de bytes de endereço em
    // cada ponteiro? Conclusão: O tipo que voce define não importa, o compilador vera para qual
    // processador/target(seja x64 ou x86) você esta compilando, e definirá isso em tempo de compilação.
    
    //No entanto, a seguinte linha dará erro, pois ao armazenar um valor ele precisa saber do tipo de dado.
    //*ptrVoid = 10;
    *ptrInt = 10;
    
    //Lembrando que char(e não char*) tem tamanho de 1 Byte.
    char* ptrBuffer = new char[8];     //E um array com 8 char's te 8 Bytes.
    memset(ptrBuffer, 0, 8);           //Preenche um bloco de memoria com um valor que especificarmos.
    
    char** ptrPtrBuffer = &ptrBuffer;//Isso é um ponteiro que aponta para outro ponteiro
    
    //Como nos alocamos essa informação em uma pilha, quando não precisarmos mais dela, desalocaremos:
    delete[] ptrBuffer;
    
    
    return 0;
}
