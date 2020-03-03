// Tema OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Hirhui Calin - Tema 7

#include <iostream>
#include <string>
using namespace std;


class Nod {
	char info;
	Nod* next;

public:
	//constructor
	Nod(char a = ' ', Nod* b = NULL) {
		info = a;
		next = b;
	}

	//constructor de copiere
	Nod(Nod* x) {
		info = x->info;
		next = x->next;
	}

	//destructor
	~Nod() {
		next = NULL;
	}

	//metode de accesare a var, deoarece sunt private
	void setInfo(char a) {
		info = a;
	}
	
	char getInfo() {
		return info;
	}

	void setNext(Nod* a) {
		next = a;
	}

	Nod* getNext() {
		return next;
	}

};



class Stiva_de_caractere {
	Nod* varf;

public:
	//Constructor care initializeaza varful stivei cu NULL
	Stiva_de_caractere(Nod* a = NULL) {
		varf = a;
	}

	//Destructor care dezaloca toate elementele stivei
	~Stiva_de_caractere() {
		Nod* varfActual;
		while (!isEmpty()) {
			varfActual = varf->getNext();
			delete varf;
		}
	}

	//metode de accesare a varfului
	void setTop(char a) {
		varf->setInfo(a);
	}

	char getTop() {
		return varf->getInfo();
	}

	//metoda de adaugare
	void push(char a) {
		Nod* p = new Nod;
		p->setInfo(a);
		p->setNext(NULL);
		if (varf != NULL)
			p->setNext(varf);
		varf = p;
	}

	//metoda de stergere
	void pop() {
		varf = varf->getNext();
	}

	//metoda de afisare a varfului stivei
	char top() {
		return varf->getInfo();
	}
	
	//metoda de testare a stivei (daca este vida)
	int isEmpty() {
		if (varf == NULL)
			return 1;
		return 0;
	}

	//supraincarcarea operatorului <<, afisare + golire
	friend ostream& operator<<(ostream& x, Stiva_de_caractere& p) {
		while (!p.isEmpty()) {
			x << p.getTop();
			p.pop();
		}
		return x;
	}

	//supraincarcarea operatorului >>, push-uri succesive
	friend istream& operator>>(istream& x, Stiva_de_caractere& p) {
		char a;
		x >> a;
		while (a != '~') {
			p.push(a);
			x >> a;
		}
		return x;
	}

	//metoda de inversare a unui sir folosind o stiva
	void flip(char v[]) {
		for (int i = 0; v[i]; i++)
			this->push(v[i]);
		for (int i = 0; v[i]; i++)
			v[i] = this->getTop();
	}

	//supraincarcarea operatorului -
	Stiva_de_caractere& operator-(Stiva_de_caractere& p) {
		Stiva_de_caractere* dif;
		dif = new Stiva_de_caractere;
		while (!this->isEmpty() && !p.isEmpty()) {
			if (this->getTop() > p.getTop())
				(*dif).push(this->getTop());
			else
				(*dif).push(p.getTop());
			p.pop();
			this->pop();
		}

		return (*dif);
	}

};

int main()
{

	cout << "Citeste o stiva. (se termina cu '~')" << endl;
	Stiva_de_caractere S;
	cin >> S;
	cout << "Stiva ta este: " << S << endl;
	
	cout << endl << "Citeste un sir de caractere." << endl;
	Stiva_de_caractere S1;
	char v[10];
	cin >> v;
	S1.flip(v);
	cout << "Sirul inversat este: " << S1 << endl << endl;
	
	cout << "Citeste dous stive." << endl;
	Stiva_de_caractere S3, S4, rez;
	cout << "Stiva 1: ";  cin >> S3;
	cout << "Stiva 2: "; cin >> S4;
	rez	= S3 - S4;
	cout << "Stiva rezultata prin scadere este: " << rez << endl;
	

	return 0;
}