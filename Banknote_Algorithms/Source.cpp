#include<iostream>
#include<locale.h>
using namespace std;

void ekranTemizle() {
	system("cls");
}

int toplamiktar(int parasayýsý[], int banknot[]) {
	int toplam = 0;
	//Toplam miktarý sýrayla paralarýn ttugumuz miktarlarý
	//ve banknot deðerleriyle çarparak hesaplýyoruz
	for (int i = 0; i < 6; i++) {
		toplam += parasayýsý[i] * banknot[i];
	}
	return toplam;
}
//En az sayýda banknot kullanarak yapýlan iþlem
void enazbanknot(int girilenparasayýsý[], int banknot[], int miktar)
{
	int temp;
	int parasayýsý[6] = { 0,0,0,0,0,0 };
	//Eðer girilen sayý eldeki toplam paradan büyükse hata mesajý
	if (toplamiktar(girilenparasayýsý, banknot) < miktar || miktar < 0)
	{
		cout << "The amount of money entered is too much or a negative amount!!" << endl;
	}

	temp = miktar;
	//Girilen paradan bir yükseðini bulmak için
	//5 e bölünebilsin diye ekleme yapýyoruz
	if (miktar % 5 != 0)
		miktar -= (miktar % 5) - 5;

	for (int i = 5; i >= 0; i--) {
		if (girilenparasayýsý[i] == 0)
			miktar += banknot[i];
		else
			break;
	}
	//Sýrayla büyükten küçüðe doðru 
	//banknotlarý veriyoruz ve verdiðimiz banknot deðerini miktardan düþüyoruz
	for (int i = 0; i < 6;) {
		if (miktar >= banknot[i] && girilenparasayýsý[i] > parasayýsý[i]) {
			parasayýsý[i]++;
			miktar -= banknot[i];
		}
		else
			i++;
	}
	//Tam olarak tüm parayý hala verememiþse
	//elinde kalan en küçük parayý ekliyoruz
	if (miktar > 0) {
		for (int i = 0; i < 6; i++)
			parasayýsý[i] = 0;
		for (int i = 5; i >= 0; i--)
			if (banknot[i] > temp) {
				parasayýsý[i]++;
				break;
			}
	}
	//Fonksiyonu ekrana yazdýrma
	cout << girilenparasayýsý[0] << " banknote 200$," << " " << girilenparasayýsý[1] << " banknote 100$," << " " << girilenparasayýsý[2] << " banknote 50$, " << " " << girilenparasayýsý[3] << " banknote 20$, " << " " << girilenparasayýsý[4] << " banknote 10$, " << " " << girilenparasayýsý[5] << " banknote 5$, " << endl;
	cout << "Target\t:" << temp << endl;
	cout << "Result\t:" << parasayýsý[0] << " banknote 200$" << " " << parasayýsý[1] << " banknote 100$" << " " << parasayýsý[2] << " banknote 50$" << " " << parasayýsý[3] << " banknote 20$" << " " << parasayýsý[4] << " banknote 10$" << " " << parasayýsý[5] << " banknote 5$" << " " << endl;
}
//Önce en yüksek banknotlarý veren fonskiyon
void yuksekparakullan(int girilenparasayýsý[], int banknot[], int miktar)
{
	int temp;
	int parasayýsý[6] = { 0,0,0,0,0,0 };
	//Girilen toplam miktar eldeki paradan büyükse uyarý 
	if (toplamiktar(girilenparasayýsý, banknot) < miktar || miktar < 0)
	{
		cout << "The amount of money entered is too much or a negative amount!!" << endl;
	}
	temp = miktar;
	//Önce en yüksek banknotu elimizde kalmayana kadar verip
	//toplam miktara ulaþma
	for (int i = 0; i < 6;) {
		if (miktar > 0 && girilenparasayýsý[i] > parasayýsý[i]) {
			miktar -= banknot[i];
			parasayýsý[i]++;
		}
		else
			i++;
	}
	//Fonsiyonu ekrana yazdýrma
	cout << girilenparasayýsý[0] << " banknote 200$," << " " << girilenparasayýsý[1] << " banknote 100$," << " " << girilenparasayýsý[2] << " banknote 50$, " << " " << girilenparasayýsý[3] << " banknote 20$, " << " " << girilenparasayýsý[4] << " banknote 10$, " << " " << girilenparasayýsý[5] << " banknote 5$, " << endl;
	cout << "Target\t:" << temp << endl;
	cout << "Result\t:" << parasayýsý[0] << " banknote 200$" << " " << parasayýsý[1] << " banknote 100$" << " " << parasayýsý[2] << " banknote 50$" << " " << parasayýsý[3] << " banknote 20$" << " " << parasayýsý[4] << " banknote 10$" << " " << parasayýsý[5] << " banknote 5$" << " " << endl;
}
//En fazla banknotu veren fonksiyon
void encokbanknot(int girilenparasayýsý[], int banknot[], int miktar)
{
	int temp;
	int parasayýsý[6];
	//Girilen toplam miktar eldeki paradan büyükse uyarý 
	if (toplamiktar(girilenparasayýsý, banknot) < miktar || miktar < 0)
	{
		cout << "The amount of money entered is too much or a negative amount!!" << endl;
	}
	temp = miktar;
	//Parayý 5 e tam bölünebilir hale getirme
	if (miktar % 5 != 0)
		miktar -= (miktar % 5) + 5;
	//Eldeki banknot sayýlarýný bir diziye atama
	for (int i = 0; i < 6; i++)
		parasayýsý[i] = girilenparasayýsý[i];
	//Öncelikle küçük banknot verecek þekilde en fazla
	//en fazla banknotu vererek istenen miktara ulaþma
	for (int i = 0; i < 6;) {
		if (toplamiktar(parasayýsý, banknot) - banknot[i] >= miktar && parasayýsý[i] > 0) {
			parasayýsý[i]--;
		}
		else
			i++;
	}
	//fonksiyonu ekrana yazdýrma
	cout << girilenparasayýsý[0] << " banknote 200$," << " " << girilenparasayýsý[1] << " banknote 100$," << " " << girilenparasayýsý[2] << " banknote 50$, " << " " << girilenparasayýsý[3] << " banknote 20$, " << " " << girilenparasayýsý[4] << " banknote 10$, " << " " << girilenparasayýsý[5] << " banknote 5$, " << endl;
	cout << "Target\t:" << temp << endl;
	cout << "Result\t:" << parasayýsý[0] << " banknote 200$" << " " << parasayýsý[1] << " banknote 100$" << " " << parasayýsý[2] << " banknote 50$" << " " << parasayýsý[3] << " banknote 20$" << " " << parasayýsý[4] << " banknote 10$" << " " << parasayýsý[5] << " banknote 5$" << " " << endl;
}
int main()
{
	int miktar;
	int secim;
	setlocale(LC_ALL, "Turkish");
	int banknot[] = { 200,100,50,20,10,5 };
	int parasayýsý[6] = { 0,0,0,0,0,0 };
	//Banknot deðerlerini ve kaç tane bulunduðunu tutan iki dizi oluþturuyoruz
	//Kullanýcýdan sýrayla kaç adet banknot deðerleri olmasýný istiyoruz 
	//Kullanýcýdan ulaþmak istenen miktarý istiyoruz
	cout << "How many get $200 banknotes : ";
	cin >> parasayýsý[0];
	cout << endl;
	cout << "How many get $100 banknotes : ";
	cin >> parasayýsý[1];
	cout << endl;
	cout << "How many get $50 banknotes : ";
	cin >> parasayýsý[2];
	cout << endl;
	cout << "How many get $20 banknotes : ";
	cin >> parasayýsý[3];
	cout << endl;
	cout << "How many get $10 banknotes : ";
	cin >> parasayýsý[4];
	cout << endl;
	cout << "How many get $5 banknotes: ";
	cin >> parasayýsý[5];
	cout << endl;
	cout << "Enter the total amount you've targeted. ";
	cin >> miktar;
	cout << endl;
	//Do-while ile bir menü oluþturuyoruz
	do
	{
		cout << "\n\n\n\t******** MENÜ *******\n\n";
		cout << "\n\t1 - Minimum Number of Banknotes \n";
		cout << "\t2 - Using High Banknotes \n";
		cout << "\t3 - Maximum Number of Banknotes \n";
		cout << "\t0 - Çýkýþ \n";
		cout << "\t\n\n\nPlease choose the function:\n";
		cin >> secim;
		    //Kullanýcýdan seçim deðiþkeninin deðerini alýyoruz
		switch (secim) {
			//1. seçim için en az banknot hesaplama
		case 1:
			ekranTemizle();
			enazbanknot(parasayýsý, banknot, miktar);
			break;
			//2. seçim için yüksek paralarla hesaplama
		case 2:
			ekranTemizle();
			yuksekparakullan(parasayýsý, banknot, miktar);
			break;
			//3. seçim için en çok banknotu kullanarak hesaplama
		case 3:
			ekranTemizle();
			encokbanknot(parasayýsý, banknot, miktar);
			break;
		case 0:
			break;
			//Hatalý seçim için uyarý
		default:
			cout << "Wrong choice ";   //hatalý seçim için uyarý oluþturuyoruz
			break;
		}
	} while (secim != 0);
	system("pause");
	return 0;
}