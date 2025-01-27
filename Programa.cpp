#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

string elementoAleatorio(std::vector<std::string>diccionario){    
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribucion(0, diccionario.size() - 1);

    std::string nuevaPalabra;

    nuevaPalabra =  diccionario[distribucion(gen)];

    return nuevaPalabra;
}

std::vector<string> adivinarPalabra(const std::vector<string>& diccionario, const std::string& intento, const std::string& acierto) {
    std::vector<std::string> nuevasPalabras;
    for (const std::string& palabra : diccionario) {
        bool valido = true;

        for (int i = 0; i < 5; i++) {
            if (acierto[i] == 'B' && palabra[i] != intento[i]) {
                valido = false;
                break;
            } else if (acierto[i] == 'I' && palabra.find(intento[i]) != std::string::npos) {
                valido = false;
                break;
            } else if (acierto[i] == 'C') {
                if (palabra.find(intento[i]) == std::string::npos || palabra[i] == intento[i]) {
                    valido = false;
                    break;
                }
            }
        }
        if (valido) {
            nuevasPalabras.push_back(palabra);
        }
    }
    return nuevasPalabras;
}



int main(){
    std::vector<std::string> palabras;
    std::string linea;

    std::ifstream archivo("Palabras_espanol.txt");

    if(!archivo){
        std::cout<<"Error abrir archivo"<<endl;

        return 1;
    }

    while(std::getline(archivo, linea)){
        if(linea.length() == 5){
            palabras.push_back(linea);
        }
    }

    std::cout<<"Bienvenido!!"<<endl;

    std::string palabra;
    std::string acierto;



    for(int i = 1; i<=6; i++){

        palabra = elementoAleatorio(palabras);
        int cantidad;

        std::cout<<"Intento N "<<i<<" palabra: "<<palabra<<endl;
        std::cout<<"Ingrese: 'B', 'C' e 'I'\n==> ";
        std::cin>>acierto;



        if(acierto == "BBBBB"){
            std::cout<<"Fin.";
            break;
        }

        palabras = adivinarPalabra(palabras, palabra, acierto);

        if(palabras.empty()){
            std::cout<<"Lista vacia"<<endl;
            break;
        }

    }

    return 0;
}
