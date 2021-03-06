/*
This file is part of VSGBE 
Copyright (c) 2020 Adriano Emidio

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

using namespace std;


#include "appInit.h"

//Método que carrega a bios e a rom na memória
void loadBiosROM(char bios_name[],char rom_name[],char* b_array, char* r_array)
{


	//Stream para leitura da bios
  	ifstream bios_file (bios_name, ios::in|ios::binary|ios::ate);

	//Guarda o tamanho do arquivo da bios
	streampos bios_size;

	//Verifica se o arquivo da rom lido corretamente
	if (bios_file.is_open())
  	{

		//Tamanho do arquuivo
    	bios_size = bios_file.tellg();

		//Inicializa do inicio
    	bios_file.seekg (0, ios::beg);

		//Lê todo conteudo do arquivo
    	bios_file.read (b_array, bios_size);

		//Fecha o arquivo
    	bios_file.close();

  }	



	//Guarda o tamanho do arquivo da rom
	streampos rom_size;

	//Stream para leitura da rom
  	ifstream rom_file (rom_name, ios::in|ios::binary|ios::ate);

  	
	//Verifica se o arquivo da rom lido corretamente
	if (rom_file.is_open())
  	{

		//Tamanho do arquuivo
    	rom_size = rom_file.tellg();

		//Inicializa do inicio
    	rom_file.seekg (0, ios::beg);

		//Lê todo conteudo do arquivo
    	rom_file.read (r_array, rom_size);

		//Fecha o arquivo
    	rom_file.close();


  }

}


int getFilesize(char file[])
{
	//Stream para leitura da bios
  	ifstream file_s (file, ios::in|ios::binary|ios::ate);

	//Verifica se o arquivo da rom lido corretamente
	if (file_s.is_open())
  	{

		//Tamanho do arquuivo
    	int tam  = file_s.tellg();

		return (int)tam;
	
	}

	return 0;

}