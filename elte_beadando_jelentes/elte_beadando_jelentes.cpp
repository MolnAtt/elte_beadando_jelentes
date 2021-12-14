/*
Jelentés
========
Egy vállalat hierarchikus felépítésű, 
tehát az igazgató kivételével (akinek nincs főnöke) minden dolgozónak pontosan egy közvetlen főnöke van, 
továbbá az igazgató mindenkinek a főnöke (közvetlenül, vagy közvetve). 
Ha egy dolgozó jelentést akar küldeni az igazgatónak, 
akkor be kell tartania a szolgálati utat, 
ami azt jelenti, 
hogy a jelentés egy lépésben, 
azaz egy nap alatt a dolgozó közvetlen főnökéhez kerül, 
aki azt továbbítja a közvetlen főnökének, 
és így tovább, 
amíg az üze-net meg nem érkezik az igazgatóhoz.

Készíts programot, 
amely kiszámítja, 
hogy legrosszabb esetben hány nap kell ahhoz, 
hogy az igazgató megkapja dolgozója jelentését! 
A program adjon is meg egy ilyen dolgozót!
*/


#include <iostream>
#include <vector>
#include <tuple> 

using namespace std;

class Fa
{
public:
	/// <summary>
	/// A standard bemenet első sorában a dolgozók száma van (1≤N≤10000). 
	/// A dolgozókat az 1,…,N számokkal azonosítjuk, 
	/// az igazgató azonosítója az 1. 
	/// A második pontosan N egész szá-mot tartalmaz (egy-egy szóközzel elválasztva), 
	/// ami a vállalati hierarchiát írja le. 
	/// Az i-edik szám az i-edik dolgozó közvetlen főnökének a sorszáma. 
	/// A sorban az első szám 0, ami azt jelenti, hogy az igazgatónak nincs főnöke.
	/// </summary>
	Fa()
	{
		cin >> N;
		szuloje = new vector<int>(N+1);
		gyerekei = new vector<vector<int>>(N+1, vector<int>());
		melysege = new vector<int>(N + 1);
		
		for (int i = 1; i <= N; i++)
		{
			cin >> szuloje->at(i);
			gyerekei->at(szuloje->at(i)).push_back(i);
		}
	}
	void melyseg_felterkepezese()
	{
		melysegcimkezes_innentol(1,0);
	}

	void legmelyebb_dolgozo_felkutatasa()
	{
		maxi = 1;
		max = melysege->at(1);
		for (int i = 2; i <= N; i++)
		{
			if (max < melysege->at(i))
			{
				maxi = i;
				max = melysege->at(i);
			}
		}
	}

	~Fa()
	{
	}

	int max;
	int maxi;
private:
	int N;
	vector<int>* szuloje;
	vector<vector<int>>* gyerekei;
	vector<int>* melysege;

	void melysegcimkezes_innentol(int i, int m)
	{
		melysege->at(i) = m;
		for (int& gy : gyerekei->at(i))
			melysegcimkezes_innentol(gy, m + 1);
	}

};


int main()
{
	Fa fa;
	fa.melyseg_felterkepezese();
	fa.legmelyebb_dolgozo_felkutatasa();
	cout << fa.max << endl;
	cout << fa.maxi;
}

/*
======== peldainput pdf-ről ========
9 
0 1 1 3 3 7 3 2 8

------------------------------------
3
6
====================================
*/