
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void showVec();
void emptyVec();

//Funciones para cada Hash
int hashMod();
int hashPow();
int hashTrunc();
int hashPleg();

//Funciones para agregar al array y evitar colisiones
void addToArray(int index, int num,int vector1[]);
void printArray(int arr_length, int vector1[]);

const int ARRAY_LENGTH = 100;
int vector1[ARRAY_LENGTH];


int main(){
    
    int choice;
    bool restart_hash = true;
    bool select_metod = true;
    
    while(restart_hash){//While para poder elegir distintos Hash
        emptyVec();
        cout<<"Ingrese que metodo de hash quiere usar: \n1.- Hash por modulo \n2.- Hash cuadrado \n3.- Hash plegamiento \n4.- Hash por truncamiento \n5.-Salir"<<endl;
        cin>>choice;
        select_metod = true;
        int num;
        
        
        //Creamos un switch para poder elegir entre los metodos que se deseen utilizar
        switch(choice){
            case 1:
                
                while(select_metod){//while para seleccionar que es lo que se quiere hacer respecto a cada metodo
                    while(choice){
                        
                        cout << "+-------Hash por Modulo-------+\n";
                        cout << "|1.- Agregar un valor         |\n";
                        cout << "|2.- Cambiar de Metodo        |\n";
                        cout << "+-----------------------------+\n";
                        cin >> choice;
                        
                        switch(choice){
                            case 1:
                                
                                hashMod();
                                cout << "\n\n";
                                
                                break;
                                
                            case 2:
                                select_metod = false;
                                choice = false;
                                break;
                                
                        }
                    }
                }
                
                break;
                
                
            case 2:
                
                while(select_metod){//while para seleccionar que es lo que se quiere hacer respecto a cada metodo
                    while(choice){
                        
                        cout << "+------Hash por Cuadrado------+\n";
                        cout << "|1.- Agregar un valor         |\n";
                        cout << "|3.- Cambiar de Metodo        |\n";
                        cout << "+-----------------------------+\n";
                        cin >> choice;
                        
                        switch(choice){
                            case 1:
                                hashPow();
                                cout << "\n\n";
                                
                                break;
                                
                                
                            case 2:
                                select_metod = false;
                                choice = false;
                                break;
                                
                        }
                    }
                }
                
                
                break;
                
                
            case 3:
                
                while(select_metod){//while para seleccionar que es lo que se quiere hacer respecto a cada metodo
                    while(choice){
                        
                        cout << "+-----Hash por plegamiento----+\n";
                        cout << "|1.- Agregar un valor         |\n";
                        cout << "|2.- Cambiar de Metodo        |\n";
                        cout << "+-----------------------------+\n";
                        cin >> choice;
                        
                        switch(choice){
                            case 1:
                                
                                hashPleg();
                                cout << "\n\n";
                                
                                break;
                                
                            case 2:
                                select_metod = false;
                                choice=false;
                                break;
                                
                        }
                    }
                }
                
                break;
                
                
            case 4:
                while(select_metod){//while para seleccionar que es lo que se quiere hacer respecto a cada metodo
                    while(choice){
                        
                        cout << "+----Hash por Truncamiento----+\n";
                        cout << "|1.- Agregar un valor         |\n";
                        cout << "|2.- Cambiar de Metodo        |\n";
                        cout << "+-----------------------------+\n";
                        cin >> choice;
                        
                        switch(choice){
                            case 1:
                                
                                hashTrunc();
                                cout << "\n\n";
                                
                                break;
                            case 2:
                                select_metod = false;
                                choice = false;
                                break;
                        }
                    }
                }
                break;
                
            default:
                cout<<"Metodo no encontrado :("<<endl;
                restart_hash = false;
        }
        
        
    }
    
    
    
    return 0;
}

//Funcion que vacia el vector11
void emptyVec(){
    
    int vec [100] ;
    
    for(int i=0;i<100;i++){
        vec [i] = 0;
    }
}
//Funcion para agregar hash por modulo
int hashMod(){
    int num;
    int index;
    cout<<"Ingresa un numero: "<<endl;
    cin>>num;
    
    index = (num%97)+1;
    
    addToArray( index, num, vector1);
    return 1;
    
}

//Funcion para agregar hash por cuadrado

int hashPow(){
    int num;
    string num1;
    string num2;
    string num_pow;
    string num1_last;
    string num2_first;
    int half;
    int index;
    
    
    cout << "Ingresa un numero: ";
    cin >> num;
    
    // Encontrar el cuadrado y convertirlo a un string
    num_pow = to_string(pow(num, 2));
    num_pow = num_pow.substr(0, (num_pow.length() / 2) + 1);
    
    // Encontrar la mitad
    half = num_pow.length() / 2;
    
    // Dividirlos en 2 variables
    num1 = num_pow.substr(0, half);
    num2 = num_pow.substr(half, num_pow.length());
    
    // Encontrar el numero medio
    num1_last = num1[num1.length() - 1];
    num2_first = num2[0];
    
    index = stoi(num1_last + num2_first) + 1;
    
    // Llamar a la funcion recursiva para aÒadirlo al vector111
    addToArray(index, num, vector1);
    return 1;
}

int hashPleg(){
    int num;
    string num1;
    string num2;
    string num_pleg;
    string num_lasts;
    string num1_last;
    int half;
    int index;
    
    cout << "Ingresa un numero: ";
    cin >> num;
    
    // Convertirlo a un string
    num_pleg = to_string(num);
    
    // Encontrar la mitad
    half = num_pleg.length() / 2;
    
    // Dividirlos en 2 variables
    num1 = num_pleg.substr(0, half);
    num2 = num_pleg.substr(half, num_pleg.length());
    
    //Convertir ambas varibles a int y sumar
    index = (stoi(num1)+stoi(num2))+1;
    
    //Volver a transformar en string para los ultimos dos digitos
    num_lasts = to_string(index);
    
    num1_last = num_lasts.substr(num_lasts.length()-2);
    //transformamos a int
    index = stoi(num1_last);
    // Llamar a la funcion recursiva para aÒadirlo al vector111
    addToArray(index, num, vector1);
    
    
    return 1;
}


int hashTrunc(){
    int num;
    string num1;
    string num2;
    string num_trunc;
    string num_last;
    string num1_first;
    string num2_first;
    int half;
    int index;
    
    cout << "Ingresa un numero: ";
    cin >> num;
    
    // Convertirlo a un string
    num_trunc= to_string(num);
    
    // Encontrar la mitad
    half = num_trunc.length() / 2;
    
    // Dividirlos en 2 variables
    num1 = num_trunc.substr(0, half);
    num2 = num_trunc.substr(half, num_trunc.length());
    
    //Obtenemos el primer digito de ambas divisiones
    num1_first = num1[0];
    num2_first = num2[0];
    
    //concatenar y hacer int para sumar
    num_last = (num1_first + num2_first);
    index = (stoi(num_last))+1;
    
    addToArray(index, num, vector1);
    
    return 1;
}


void addToArray(int index, int num,int vector1[]) {
    if(vector1[index] == 0) {
        vector1[index] = num;
        printArray(ARRAY_LENGTH, vector1);
    } else {
        index = (index == ARRAY_LENGTH - 1) ? -1 : index;
        addToArray(index + 1, num, vector1);
    }
}


void printArray(int arr_length, int vector1[]) {
    for (int i = 0; i < arr_length; i++) {
        cout << "Posicion " << i << ": " << vector1[i] << endl;
    }
}
