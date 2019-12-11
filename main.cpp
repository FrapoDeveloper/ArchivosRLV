#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define DELIM_C "*"
#define DELIM_R "#"
using namespace std;

FILE *archivoDiscoDuro;
char espacioArchivo[10];
char op;

void crearArchivo(){
    char nombre[20],apellido[20],cargo[20];
    int edad;
    int ID=1000;
    if ((archivoDiscoDuro=fopen("archivo.txt","wt"))==NULL){ //crear el archivo
    cout<<"Error de registro";return;}

    do{
            char idChar[6];
            sprintf(idChar,"%d",ID);
            fwrite(idChar,1,strlen(idChar),archivoDiscoDuro);
            fwrite(DELIM_C,1,1,archivoDiscoDuro);

            fflush(stdin);
            cout<<"Ingrese el nombre del empleado(maximo 8 caracteres):  ";
            gets(nombre);
            if(strlen(nombre)<=8){
            fwrite(nombre,1,8,archivoDiscoDuro);
            fwrite(DELIM_C,1,1,archivoDiscoDuro);
            }else{
                 cout<<"Numero de caracteres invalido"<<endl;

            }

            fflush(stdin);
            cout<<"Ingrese la edad del empleado: "<<endl;
            cin>>edad;

            char numchar[4];
            sprintf(numchar,"%d",edad); //casting convertimos edad(int) a char
            if(strlen(numchar)<=8){
            fwrite(numchar,1,8,archivoDiscoDuro);
            fwrite(DELIM_C,1,1,archivoDiscoDuro);
            }else{
                cout<<"Numero de caracteres invalido"<<endl;
            }
            fflush(stdin);
            cout<<"Ingrese el cargo del empleado: ";
            gets(cargo);
            if(strlen(cargo)<=8){
            fwrite(cargo,1,8,archivoDiscoDuro);
            fwrite(DELIM_R,1,1,archivoDiscoDuro);
            }else{
                 cout<<"Numero de caracteres invalido";
            }

            cout<<endl;
            fflush(stdin);
            cout<<"DESEA INGRESAR MAS ARCHIVOS? (s/n): ";
            cin>>op;
            ID++;
        }while(op=='s');
        fclose(archivoDiscoDuro);
}

void leerRegistro(){
    char elementoR;
    if((archivoDiscoDuro=fopen("archivo.txt","rt"))==NULL){
    return;}
    cout<<"\n ID                NOMBRE              EDAD                  CARGO ";
    cout<<"\n";
    while(!feof(archivoDiscoDuro)) //mientras no sea el final del archivo
    {
        elementoR = fgetc(archivoDiscoDuro); //cada elemento y caracteres del archivo
        if(elementoR == '*'){
            cout<<"|              |";continue;
        }
        if(elementoR == '#'){
            cout<<"\n";continue;
        }
        cout<<elementoR;
    }
    fclose(archivoDiscoDuro);

}


void buscarInformacion(){
    char almacena, Id[5], id[5], nombre[30],edad[30],cargo[30];
    int c=0,x=0,y=0,z=0,w=0;
    if((archivoDiscoDuro=fopen("archivo.txt","rt"))==NULL){
        return;
    }
    fflush(stdin);
    cout<<"\nIngrese el Id: ";
    gets(Id);
    while(!feof(archivoDiscoDuro)){
        almacena = fgetc(archivoDiscoDuro);
        if(almacena=='*'){
            c++;
            id[x]='\0';
            nombre[y]='\0';
            edad[z]='\0';
            continue;
        }
        if(almacena=='#'){
            cargo[w]='\0';
            if(strcmp(Id,id)==0){
                int op;
                cout<<"Que desea buscar? : \n1.Nombre\n2.Edad\n3.Cargo\n\nIngrese una opcion: ";
                cin>>op;
                if(op==1){
                cout<<"Nombre: "<<nombre;
                break;
                }else if(op==2){
                cout<<"Edad: "<<edad;
                break;} else if(op==3){
                cout<<"Cargo: "<<cargo;
                break;}

            }
            c=0;x=0;y=0;z=0,w=0;continue;
        }

        if(c==0){
            id[x++]=almacena;
        }
        if(c==1){
            nombre[y++]=almacena;
        }
        if(c==2){
            edad[z++]=almacena;
        }
        if(c==3){
            cargo[w++]=almacena;
        }
    }
}



void Menu(){

int op;
    do{
        system("cls");
        cout<<"\t\t\t\t\t******************************"<<endl;
        cout<<"\t\t\t\t\t\t    ++  MENU ++"<<endl<<endl;
        cout<<"\t\t\t\t\t1. Informacion"<<endl;
        cout<<"\t\t\t\t\t2. Crear  registro"<<endl;
        cout<<"\t\t\t\t\t3. Ver el archivo "<<endl;
        cout<<"\t\t\t\t\t4. Buscar Informacion "<<endl;
        cout<<"\t\t\t\t\t5. Salir "<<endl;
        cout<<"\t\t\t\t\t******************************"<<endl;
        cout<<"\nINGRESE UNA OPCION: ";
        cin>>op;

        switch(op){

             case 1: MessageBox(HWND_DESKTOP, "En este programa aprenderemos el funcionamiento de los ARLV (archivos de registro de longitud variable), el proposito de esta investigacion se basa en la manipulacion de archivos que desemos crear en nuestras aplicaciones sin perder informacion a la hora de cerrar el programa. \n\nDocente: DANIEL ALVAREZ CAMPOS\n\nIntegrantes: FRAN ESPINO,NAYELI CALCUNA,CRISTIAN QUIROZ ","INFORMACION DEL PROGRAMA",MB_ICONASTERISK);
                     system("cls");
                     cout<<"\n"<<endl;
                     break;

             case 2: system("cls");
                    cout<<"\n-------------------REGISTRO DE LONGITUD VARIABLE--------------------"<<endl;
                    crearArchivo();
                    cout<<"\n"<<endl;
                    break;
             case 3:
                    system("cls");
                    cout<<"\n-------------------REGISTRO DE LONGITUD VARIABLE--------------------"<<endl;
                    leerRegistro();
                    cout<<"\n"<<endl;
                    system("pause");
                    break;

            case 4: system("cls");
                    cout<<"\n-------------------REGISTRO DE LONGITUD VARIABLE--------------------"<<endl;
                    buscarInformacion();
                    cout<<"\n"<<endl;
                    system("pause");
                    break;


        }
    }while(op!=5);

}




 int WINAPI WinMain(HINSTANCE ins,HINSTANCE ins2,LPSTR cmd, int estado){

    system("color 4B");


    Menu();


}
