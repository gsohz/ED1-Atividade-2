#include <iostream>
#include <iomanip>
#include<algorithm>
#include <string.h>
#include <time.h>
using namespace std;

class Data
{
private:
	int dia;
	int mes;
	int ano;

public:
	Data(int dia, int mes, int ano)
	{
		this->dia = dia;
		this->mes = mes;
		this->ano = ano;
	}

	Data()
	{
		this->dia = 28;
		this->mes = 9;
		this->ano = 1962;
	}

	void setDia(int dia)
	{
		this->dia = dia;
	}

	void setMes(int mes)
	{
		this->mes = mes;
	}

	void setAno(int ano)
	{
		this->ano = ano;
	}

	int getDia()
	{
		return this->dia;
	}

	int getMes()
	{
		return this->mes;
	}

	int getAno()
	{
		return this->ano;
	}

	string getData()
	{
		return to_string(this->dia) + "/" +
			   to_string(this->mes) + "/" +
			   to_string(this->ano);
	}

	Data* dia_seguinte()
	{
		Data *ds;
		int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		ds = new Data(this->dia, this->mes, this->ano);

		if (ds->ano % 4 == 0)
		{
			diasNoMes[1]++;
		}

		ds->dia++;
		if (ds->dia > diasNoMes[ds->mes - 1])
		{
			ds->dia = 1;
			ds->mes++;
			if(ds->mes > 12)
			{
				ds->mes = 1;
				ds->ano++;
			}
		}

		return ds;
	}

};

class Contato
{
private:
	string email;
	string nome;
	string tel;
	Data *dtnasc;
	
public:
	Contato(string nome, string email, string tel, int dia, int mes, int ano){
		this->email = email;
		this->nome = nome;
		this->tel = tel;
		this->dtnasc = new Data(dia, mes, ano);
	}
	
	void setNome(string nome){
		this->nome = nome;
	}
	
	void setEmail(string email){
		this->email = email;
	}
	
	void setTel(string tel){
		this->tel = tel;
	}
	
	void setNasc(int dia, int mes, int ano){
		this->dtnasc = new Data(dia, mes, ano);
	}
	
	string getNome(){
		return this->nome;
	}
	
	string getEmail(){
		return this->email;
	}
	
	string getTel(){
		return this->tel;
	}
	
	int getIdade(){
		time_t tempo;
	    tempo = time(NULL);
	    struct tm tm = *localtime(&tempo);
	    //printf("Data: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	    //int idade = (tm.tm_year + 1900) - this->dtnasc->getAno();
	    
  		int dtAt = (tm.tm_year + 1900) * 365 + (tm.tm_mon + 1) * 30 + tm.tm_mday;
		int dtN = this->dtnasc->getAno() * 365 + this->dtnasc->getMes() * 30 + this->dtnasc->getDia();
		
		int diferenca = dtAt - dtN;
		int idade = diferenca/365;
		
		return idade;
	}
	
	string getNasc(){
		return this->dtnasc->getData();
	}
	
	void getDados(){
		int e = 20;
		cout << "Nome: " << this->getNome() << "," << setw(e) << "Email: " << this->getEmail() << 
			"," << setw(e) << "Telefone: " << this->getTel() << "," << setw(e) << "Idade: " << this->getIdade() << 
			"," << setw(e*2) << "Data de nascimento: " << this->getNasc() << endl;
	}
	
};

int main(int argc, char** argv)
{
	Contato *contato1 = new Contato("Flavio", "flavin@hotmail.com", "13414144534", 01, 03, 2007);
	Contato *contato2 = new Contato("Paula", "paula@gmail.com", "1635363534", 04, 02, 2003);
	Contato *contato3 = new Contato("Francisnalda", "fran@outlook.com", "15414144534", 04, 05, 2002);
	Contato *contato4 = new Contato("Juberleison", "jubs@hotmail.com", "12414144534", 29, 05, 2001);
	Contato *contato5 = new Contato("Cleber", "cleber@gmail.com", "1141421454534", 07, 05, 1980);
	
	contato1->getDados();
	contato2->getDados();
	contato3->getDados();
	contato4->getDados();
	contato5->getDados();
	
	cout << endl << "Demonstracao de Alteracoes:" << endl;
	
	contato1->setNome(">>>alterado<<<");
	contato1->getDados();
	
	contato2->setEmail(">>>alterado<<<");
	contato2->getDados();
	
	contato3->setTel(">>>alterado<<<");
	contato3->getDados();
	
	contato4->setNasc(29, 05, 1920);
	contato4->getDados();
	
	contato5->setNome(">>>alterado<<<");
	contato5->setEmail(">>>alterado<<<");
	contato5->setTel(">>>alterado<<<");
	contato5->setNasc(00, 00, 00);
	contato5->getDados();

	return 0;
}