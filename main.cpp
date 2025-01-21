#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Nodo{
    public:
        char letra;
        int distancia;
        vector<Nodo*> hijos;
    Nodo(char _letra, int _distancia){
        letra=_letra;
        distancia=_distancia;

    }
};
vector<vector<int>> leerTxT(string Archivo, int nodos){
    ifstream file(Archivo);
    file>>nodos;

    vector<vector<int>>matriz(nodos,vector<int>(nodos));
    for(int i=0;i<nodos;i++){
        for(int j=0;j<nodos;j++){
            file>>matriz[i][j];
            if(file.peek()==','){
                file.ignore();
            }
        }
    }
    
    return matriz;






}
int main(){
    int nodos;
    vector<vector<int>> matriz=leerTxT("matriz.txt",nodos);

    return 0;
}