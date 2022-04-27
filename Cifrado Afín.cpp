#include <iostream>
#include <locale.h>
#include <string>
using namespace std;
string alfabeto="abcdefghijklmn@opqrstuvwxyz";
int modulo(int a, int b){
     int q=a/b;
   int r;
   if (a<0){
     q=q-1;
   }
   return r=a-(q*b);
   }
int euclides(int a, int b){
int q;
int r=1;
int eu;
while(r!=0){
  q=a/b;
  r=modulo(a,b);
  a=b;
  eu=b;
  b=r;}

return eu;
}
int inv_m(int a,int b){
    int r=1;
  int q;
  int x0=1,y0=0;
  int x1=0,y1=1;
  int auxx,auxy;
  int auxa=a,auxb=b;
  while(r!=0){
    auxx=x1;auxy=y1;
    q=auxa/auxb;
    r=modulo(auxa,auxb);
    x1=x0-(q*x1);y1=y0-(q*y1);
    x0=auxx;y0=auxy;
    auxa=auxb;
    auxb=r;
  }
return x0;}
int buscar(char x){
      for(int j=0;j<alfabeto.length();j++){
        if(x==alfabeto[j]){
          return j;
        }
    }}
string afin_cifrado(string mensaje,int a, int b){
  int v,res;
  string respuesta;
  char f;
  for(int i=0;i<mensaje.length();i++){
    v=buscar(mensaje[i]);
    res=modulo(a*v-b,alfabeto.length());
    f=alfabeto[res];
    respuesta=respuesta+f;
  }
  return respuesta;
}
string afin_descifrado(string mensaje,int a, int b){
   int v,res;
  string respuesta;
  char f;
  for(int i=0;i<mensaje.length();i++){
    v=buscar(mensaje[i]);
    res=modulo((v-b)*inv_m(a,alfabeto.length()),alfabeto.length());
    f=alfabeto[res];
    respuesta=respuesta+f;
  }
  return respuesta;
} 

int main() {
  setlocale(LC_ALL,"Spanish");
  int a,b;
  string mensaje;
  string accion;
  cout<<"Ingrese la clave 1: ";
  cin>>a;cout<<endl;
  while(euclides(a,alfabeto.length())!=1){
  cout<<"Valor no aceptado, ingrese otro:";
  cin>>a;cout<<endl;
  }
  cout<<"Ingrese la clave 2: ";
  cin>>b;cout<<endl;
  while(b>alfabeto.length()){
  cout<<"Valor no aceptado, ingrese otro:";
  cin>>b;cout<<endl;}
  cout<<"¿Desea cifrar o descifrar?"<<endl;
  cin>>accion;cout<<endl;
  if(accion=="cifrar"){
  cout<<"Ingrese el mensaje a cifrar: "<<endl;
  cin>>mensaje;  
  cout<<afin_cifrado(mensaje,a,b); 
  }
 else if (accion=="descifrar"){
  cout<<"Ingrese el mensaje a descifrar: "<<endl;
  cin>>mensaje;  
  cout<<afin_descifrado(mensaje,a,b); 
 }
  }
