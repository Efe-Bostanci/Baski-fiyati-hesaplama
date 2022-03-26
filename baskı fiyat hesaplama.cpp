#include <iostream>
#include <unistd.h> //delay

using namespace std;

void CloseTheProgram()
{
	cout << " Program kapatýlýyor..." << endl;
			
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
	
	//--------------------süre fiyatý--------------------------
	float kwh = 2.05; // 2022 kwh birimi (tl)
  	float saatbasikwh = 0.15; // e3v2 nin saat baþý harcamasý
	
	float saat;
	float sonuc;
	//---------------------------------------------------------
	
	
	//---------------------filament fiyatý---------------------
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
			cout << endl << " Makara 0 dan küçük olamaz" << endl;
			CloseTheProgram();
			break;
		}
	
		cout << " Kaç gram harcanacak?: ";
		cin >> kacgram;
		
		if (kacgram > 1000 || kacgram < 0)
		{
			cout << " Basýlacak ürün makaradan büyük ya da eksik olamaz" << endl;
			CloseTheProgram();
			break;
		}
		
		filamentnekadar = (filamenttl * kacgram) / 1000;
	
		cout << " Baský süreniz kaç saat?: ";
		cin >> saat;
		if(saat < 0) 
		{
			cout << endl <<  " Süre eksiye düþemez" << endl;
			CloseTheProgram();
			break;
		}
		
		
		cout << " Saðlamak istediðiniz kazanç: %";
		int girilen;
		cin >> girilen;
		if(girilen < 0)
		{
			cout << endl << " Minimum kazanç %0 olabilir" << endl;
			CloseTheProgram();
			break;
		}
		
		
		cout << endl << " ---------------------------------------------------------";
		sonuc = kwh * saatbasikwh * saat; // sonuç deðiþkeninin içine para * dk yi giriyoruz
		cout << " Harcanan elektrik fiyatý: " << sonuc << " TL";
		cout << endl << " Harcanan filament: " << filamentnekadar << " TL";
		
		float top = sonuc + filamentnekadar;
		cout << endl << " Toplam: " << top << " TL";
		
		float yuzde = (top * girilen) / 100;
		
		cout << endl << " Kazançlý toplam " << yuzde + top << " TL";
		cout << endl << " ---------------------------------------------------------" << endl;
		sleep(3);
	}
}
