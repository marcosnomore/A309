#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/*
string &  extraer_nombre(const string & fuente, string & resultado)
{
	size_t pos=fuente.find_last_of("/");
	if(pos!=string::npos)
	{
		resultado=fuente.substr(pos+1);
	}
	return resultado;
}

string & completar_path(string & str)
{
	//completar
	
	return str;
}
*/
int main(void) 
{
	/*
	string str("Hello World");
	string start=str.substr(0,5);
	string end=str.substr(6);
	cout<<str<<endl;
	cout<<end<<endl;
	
	string str1("How long is this string?");
	cout<<"Length of this string is: "<<str1.size()<<endl;
	cout<<"Length of this string is: "<<str1.length()<<endl;
	
	string str2("Hello, can you find Ben?");
	size_t pos=str2.find("Ben", 15, 2);
	if(pos!=string::npos)		//npos es un valor mucho más grande que el tamaño de la cadena, para que no haya colisión
		cout<<"First occurence of Ben was found at: "<<pos<<endl;
	
	string str3="C++ is an impressive language.";
	size_t pos2=str3.find_first_of(" .");
	while(pos2!=string::npos)
	{
		cout<<"Found space or dot at: "<<pos2<<endl;
		pos2=str3.find_first_of(" .", pos2+1);
	}
	*/
/*	string str("/home/pss/graphs/brock200_1.clq");
	string nombre;
	extraer_nombre(str, nombre);
	cout<<nombre<<endl;
*/
	int dato=10;
	string mi_str("");
	string str="hola";
	stringstream sstr("");
	
	sstr<<str<<" : "<<dato<<endl;
	sstr>>mi_str;
	
	cout<<mi_str<<endl;
}
