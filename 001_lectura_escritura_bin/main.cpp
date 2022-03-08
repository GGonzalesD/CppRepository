#include <iostream>
#include <fstream>

void generarArchivoBinario(const char * filename){
	int entero = 203;
	double real = -32.231;
	int numeros[] = { 2, 5, 1, 5 };
	float* ptr = new float[2];
	ptr[0] = 23.21;
	ptr[1] = 32.01;
	std::string str = "Hola mundo";

	std::ofstream oArchivo(filename, std::ios_base::out | std::ios_base::binary);
	oArchivo.write((char*)&entero, sizeof(int));
	oArchivo.write((char*)&real, sizeof(double));
	oArchivo.write((char*)numeros, sizeof(numeros));
	oArchivo.write((char*)ptr, sizeof(float)*2);
	{
		size_t len = str.size();
		oArchivo.write((char*)&len, sizeof(size_t));
		oArchivo.write(str.data(), sizeof(char)*len);
	}
	oArchivo.close();
}

void leerArchivoBinario(const char * filename){
/*
	int			entero
	double		real
	int			numeros[4]
	float*		ptr = new float[2]
	std::string str
*/

	int entero;
	double real;
	int numeros[4];
	float * ptr;
	std::string str;


	std::ifstream iArchivo(filename, std::ios_base::in | std::ios_base::binary);

	iArchivo.read((char*)&entero, sizeof(int));
	iArchivo.read((char*)&real, sizeof(double));

	iArchivo.read((char*)numeros, sizeof(numeros));
	ptr = new float[2];
	iArchivo.read((char*)ptr, sizeof(float)*2);
	{
		size_t len;
		iArchivo.read((char*)&len, sizeof(len));
		char tmp[len+1];
		iArchivo.read(tmp, sizeof(tmp));
		tmp[len] = '\0';
		str = tmp;
	}


	iArchivo.close();

	std::cout << "Entero: " << entero << std::endl;
	std::cout << "Real: " << real << std::endl;
	std::cout << "String: " << str << std::endl;

}

int main(int args, const char ** kargs)
{

	generarArchivoBinario("data");
	leerArchivoBinario("data");

	return 0;
}