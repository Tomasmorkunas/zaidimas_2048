#include<conio.h>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int Patikra(int PlytelesKopija[4][4], int Plytele[4][4])
{
	int fl = 1;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (PlytelesKopija[i][j] != Plytele[i][j])
			{
				fl = 0;
				break;
			}
	return fl;
}

int ArZaidimasBaigtas(int Plytele[4][4])
{
	int fl = 0, gl = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (Plytele[i][j] == 0) //jeigu dar yra neuzimtu poziciju zaidimas tesiamas toliau
			{
				fl = 1;
				break;
			}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (Plytele[i + 1][j] == Plytele[i][j] || Plytele[i][j + 1] == Plytele[i][j])
			{
				gl = 1;
				break;
			}

	if (fl || gl) return 1;
	else return 0;
}

int main()
{	

	int pozicija1;
	int pozicija2;
	int pozicija3;
	int pozicija4;
	int klavisas;
	int Plytele[4][4] = {};
	int PlytelesKopija[4][4] = {};
	int taskai = 0;

	srand(time(0));

	pozicija1 = rand() % 4;
	pozicija2 = rand() % 4;

	while (1)
	{
		pozicija3 = rand() % 4;
		pozicija4 = rand() % 4;
		if (pozicija1 != pozicija3 && pozicija2 != pozicija4) //negali buti tos pacios pozicijos 2 blokam
		break; 
	}

	Plytele[pozicija1][pozicija2] = 2; //1 skaiciaus x ir y pozicijos paleidus zaidima
	Plytele[pozicija3][pozicija4] = 4; //2 skaiciaus x ir y pozicijos paleidus zaidima
	
	cout << "Zaidimas 2048" << "\n\n";
	cout << "Paspauskite Esc, noredami nutraukti zaidima.\n";
	cout << "\n\n";

	//dvimatis masyvas, skirtas uzpildyti lentele eilutemis ir stulpeliais
	for (int i = 0; i < 4; i++)
	{
		cout << "*****************\n";
		for (int j = 0; j < 4; j++)
		{
			if (Plytele[i][j] == 0) cout << "|   ";
			else
				cout << "| " << Plytele[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "*****************\n";

	cout << "\n\n";
	cout << "Taskai: " << taskai;

	while (1)
	{
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		PlytelesKopija[i][j] = Plytele[i][j];
		klavisas = _getch(); //konsole laukia kol bus paspaustas reikiamas klavisas
		system("cls");



		
		if (klavisas == 72) //arrow_up
		{
			int li, ri;
			for (int j = 0; j < 4; j++)
			{
				li = 0, ri = j;
				for (int i = 1; i < 4; i++)
				{
					if (Plytele[i][j] != 0) //jeigu kazkokia reiksme jau yra laukelyje
					{
						if (Plytele[i - 1][j] == 0 || Plytele[i - 1][j] == Plytele[i][j])
						{
							if (Plytele[li][ri] == Plytele[i][j]) //jeigu lygios reiksmes susijungia
							{
								Plytele[li][ri] *= 2; //naujo bloko reiksme dvigubinasi
								taskai += Plytele[li][ri]; //tasku prisideda tiek, koks gaunas naujas skaitmuo sujungus du blokus
								Plytele[i][j] = 0; //sena skaiciaus pozicija nusinuliuoja - tampa tuscia
							}
							else
							{
								if (Plytele[li][ri] == 0)
								{
									Plytele[li][ri] = Plytele[i][j];
									Plytele[i][j] = 0;
								}
								else
								{
									Plytele[++li][ri] = Plytele[i][j];
									Plytele[i][j] = 0;
								}
							}
						}
						else li++;
					}
				}
			}
		}

		if (klavisas == 80) //arrow_down
		{
			int li, ri;
			for (int j = 0; j < 4; j++)
			{
				li = 3, ri = j;
				for (int i = 2; i >= 0; i--)
				{
					if (Plytele[i][j] != 0)
					{
						if (Plytele[i + 1][j] == 0 || Plytele[i + 1][j] == Plytele[i][j])
						{
							if (Plytele[li][ri] == Plytele[i][j])
							{
								Plytele[li][ri] *= 2;
								taskai += Plytele[li][ri];
								Plytele[i][j] = 0;
							}
							else
							{
								if (Plytele[li][ri] == 0)
								{
									Plytele[li][ri] = Plytele[i][j];
									Plytele[i][j] = 0;
								}
								else
								{
									Plytele[--li][ri] = Plytele[i][j];
									Plytele[i][j] = 0;
								}
							}
						}
						else li--;
					}
				}
			}
		}

		if (klavisas == 75) //arrow_left
		{
			int li, ri;
			for (int i = 0; i < 4; i++)
			{
				li = i, ri = 0;
				for (int j = 1; j < 4; j++)
				{
					if (Plytele[i][j] != 0)
					{
						if (Plytele[i][j - 1] == 0 || Plytele[i][j - 1] == Plytele[i][j])
						{
							if (Plytele[li][ri] == Plytele[i][j])
							{
								Plytele[li][ri] *= 2;
								taskai += Plytele[li][ri];
								Plytele[i][j] = 0;
							}
							else
							{
								if (Plytele[li][ri] == 0)
								{
									Plytele[li][ri] = Plytele[i][j];
									Plytele[i][j] = 0;
								}
								else
								{
									Plytele[li][++ri] = Plytele[i][j];
									Plytele[i][j] = 0;
								}
							}
						}
						else ri++;
					}
				}
			}
		}

		if (klavisas == 77) //arrow_right
		{
			int li, ri;
			for (int i = 0; i < 4; i++)
			{
				li = i, ri = 3;
				for (int j = 2; j >= 0; j--)
				{
					if (Plytele[i][j] != 0)
					{
						if (Plytele[i][j + 1] == 0 || Plytele[i][j + 1] == Plytele[i][j])
						{
							if (Plytele[li][ri] == Plytele[i][j])
							{
								Plytele[li][ri] *= 2;
								taskai += Plytele[li][ri];
								Plytele[i][j] = 0;
							}
							else
							{
								if (Plytele[li][ri] == 0)
								{
									Plytele[li][ri] = Plytele[i][j];
									Plytele[i][j] = 0;
								}
								else
								{
									Plytele[li][--ri] = Plytele[i][j];
									Plytele[i][j] = 0;
								}
							}
						}
						else ri--;
					}
				}
			}
		}

		if (klavisas == 27) //ESC
		{
			break;
		} 


		if (!Patikra(PlytelesKopija, Plytele))
		{
			int li, ri;
			srand(time(0));
			while (1)
			{
				li = rand() % 4;
				ri = rand() % 4;
				if (Plytele[li][ri] == 0) //jeigu laukelis tuscias
				{
					Plytele[li][ri] = pow(2, li % 2 + 1); //spawninimas naujo bloko tuscioje pozicijoje
					break;
				}
			}
		}

		cout << "Zaidimas 2048" << "\n\n";
		cout << "Paspauskite Esc, noredami nutraukti zaidima.\n";
		cout << "\n\n";

		//dvimatis masyvas, skirtas uzpildyti lentele eilutemis ir stulpeliais
		for (int i = 0; i < 4; i++)
		{
			cout << "*****************\n";
			for (int j = 0; j < 4; j++)
			{
				if (Plytele[i][j] == 0) cout << "|   ";
				else
					cout << "| " << Plytele[i][j] << " ";
			}
			cout << "|" << endl;
		}
		cout << "*****************\n";

		cout << "\n\n";
		cout << "Taskai: " << taskai;

		if (!ArZaidimasBaigtas(Plytele))
		{
			cout << "Zaidimas baigtas\n\n\n\n";
			break;
		}
	}

	return 0;
}		
