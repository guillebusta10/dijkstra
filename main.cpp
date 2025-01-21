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
vector<vector<int>> leerTxT(string Archivo, int& cantidadnodos){
    ifstream file(Archivo);
    file>>cantidadnodos;

    vector<vector<int>>matriz(cantidadnodos,vector<int>(cantidadnodos));
    for(int i=0;i<cantidadnodos;i++){
        for(int j=0;j<cantidadnodos;j++){
            file>>matriz[i][j];
            if(file.peek()==','){
                file.ignore();
            }
        }
    }
    
    return matriz;






}
void Algoritmodijkstra(vector<vector<int>>& grafo, int inicio,int destino,vector<char>&nodos){
    int n=grafo.size();
    vector<int> distanciasNodos(n,9999);
    vector<bool> visitados(n,false);
    vector<int> padres(n,-1);
    distanciasNodos[inicio]=0;
    for(int i=0; i<n-1;i++){
        int NOvisitado=-1;//indice para verificar los nodos que no se puede acceder
        int distanciaMin=9999;
        for(int j=0;j<n;j++){
            if(!visitado[j] && distanciasNodos[j]<distanciaMin){
                distanciaMin=distanciasNodos[j];
                NOvisitado=j;
            }
        }
        if(NOvisitado==-1){
            break;// nodos que no se pueden acceder
        }
        visitado[NOvisitado]=true;

        for(int z=0;z<n;z++){
            if(!visitado[z] && grafo[NOvisitado][z] && distanciasNodos[NOvisitado]!=9999 && grafo[NOvisitado][z]+distanciasNodos[NOvisitado]<distanciasNodos[z]){
                distanciasNodos[z]=grafo[NOvisitado][z]+distanciasNodos[NOvisitado];
                padres[z]=NOvisitado;
            }
        }
    }
    

}
int main(){
    int cantidadnodos;
    vector<vector<int>> grafo=leerTxT("matriz.txt",cantidadnodos);//creamos el grafo

    vector<char> nodos(cantidadnodos);
    
    cout<<"Nodos disponibles: "<<endl;
    for(int i=0;i<cantidadnodos;i++){
        nodos[i]='A'+i; //asignamos cada caracter
        
        cout<<nodos[i]<<" , ";// imprimimos los disponibles
    }
    char destino;
    cout<<"Ingrese el nodo destino: "<<endl;
    cin>>destino;
    int indiceDestino=destino-'A';//obtenemos el "inidice del nodo"
    Algoritmodijkstra(grafo,0,indiceDestino,nodos);


    return 0;
}