#include <iostream>
#include <unistd.h> //delay

using namespace std;

void CloseTheProgram()
{
	cout << " Program kapat�l�yor..." << endl;
			
			int dongu = 3;
			while(dongu > 0)
			{
				cout << " -" << dongu << "-" << endl;
				sleep(1.5);
		
				dongu--;
			}
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	
	//--------------------s�re fiyat�--------------------------
	float kwh = 2.05; // 2022 kwh birimi (tl)
  	float saatbasikwh = 0.15; // e3v2 nin saat ba�� harcamas�
	
	float saat;
	float sonuc;
	//---------------------------------------------------------
	
	
	//---------------------filament fiyat�---------------------
	float filamenttl;
	float kacgram;
	float filamentnekadar;
	//---------------------------------------------------------
	while(1)
	{
		cout << " Filamentinizin kilosu ne kadar?: ";
		cin >> filamenttl;
		if (filamenttl < 0)
		{
			cout << endl << " Makara 0 dan k���k olamaz" << endl;
			CloseTheProgram();
			break;
		}
	
		cout << " Ka� gram harcanacak?: ";
		cin >> kacgram;
		
		if (kacgram > 1000 || kacgram < 0)
		{
			cout << " Bas�lacak �r�n makaradan b�y�k ya da eksik olamaz" << endl;
			CloseTheProgram();
			break;
		}
		
		filamentnekadar = (filamenttl * kacgram) / 1000;
	
		cout << " Bask� s�reniz ka� saat?: ";
		cin >> saat;
		if(saat < 0) 
		{
			cout << endl <<  " S�re eksiye d��emez" << endl;
			CloseTheProgram();
			break;
		}
		
		
		cout << " Sa�lamak istedi�iniz kazan�: %";
		int girilen;
		cin >> girilen;
		if(girilen < 0)
		{
			cout << endl << " Minimum kazan� %0 olabilir" << endl;
			CloseTheProgram();
			break;
		}
		
		
		cout << endl << " ---------------------------------------------------------";
		sonuc = kwh * saatbasikwh * saat; // sonu� de�i�keninin i�ine para * dk yi giriyoruz
		cout << " Harcanan elektrik fiyat�: " << sonuc << " TL";
		cout << endl << " Harcanan filament: " << filamentnekadar << " TL";
		
		float top = sonuc + filamentnekadar;
		cout << endl << " Toplam: " << top << " TL";
		
		float yuzde = (top * girilen) / 100;
		
		cout << endl << " Kazan�l� toplam " << yuzde + top << " TL";
		cout << endl << " ---------------------------------------------------------" << endl;
		sleep(3);
	}
}
