#include<iostream>               
#include<locale.h>               
using namespace std;             
typedef struct stack_element {    
	int value;                   
	struct stack_element *next;  


}Element;

Element *temp, *dolaþan;       
Element *son = NULL;               
bool  Warn(int &boyut) {       


	cout << "How many numbers do you want to add? : ";  
	cin >> boyut;                               
	if (boyut <= 0)                              
		return false;
	else
	{
		return true;
	}
}
void Create_List(int &x, int boyut) {                     
														
	cout << "Enter the numbers you want to add : " << endl;  
	int sayac = 0;                                     
													


	while (sayac != boyut)                         
	{                                                 

		temp = new Element;                           
		cin >> x;                                   
		temp->value = x;                            
		temp->next = son;                              
		son = temp;                                  
		sayac++;                                      
	}

}

void Pop()                                          
{                                                    
													 
	if (son == NULL)
	{                                                
		cout << "There is no element in the list";  
	}
	else                                             
	{
		temp = son;                                 
		son = son->next;                             
		cout << "Number pop from list : " << temp->value;
		free(temp);                                

	}
}

void listele(int sec)                               
{
	dolaþan = son;                                  
	if (son == NULL && sec == 2)                   
	{                                           
		cout << "There is no element in the list. You must add!"; 
		system("pause");                                
	}
	else                                            
		cout << "Elements in list : " << "\t";    
	while (dolaþan != NULL)                         
	{                                               
		cout << dolaþan->value << "\t";             
		dolaþan = dolaþan->next;                    
	}

}
void Say()                                         
{                                                  
	int i = 0;                                 
	dolaþan = son;                               
	while (dolaþan != NULL) {                     
		dolaþan = dolaþan->next;                  
		i++;                                       
	}                                             
	cout << "Number of elements in list : " << i;    
}                                                  

void ekranTemizle() {             
	system("cls");               
}

int main()
{


	int  size, eklenecek, secim;          
	                                      
	                                      
	setlocale(LC_ALL, "Turkish");

	do
	{

		cout << "\n\n\n\t******** MENÜ *******\n\n";          
		cout << "\n\t1 - Push \n";                        
		cout << "\t2 - Pop \n";
		cout << "\t3 - List \n";                           
		cout << "\t4 - Count \n";                               
		cout << "\t0 - Exit \n";

		cout << "\t\n\n\nPlease select the function : \n";
		cin >> secim;                                        

		switch (secim)                                       
		{                                                  

		case 1:                                             
			ekranTemizle();                                  
			if (!Warn(size)) {                              
				cout << "You entered an wrong size!!";      
				cout << endl;                               
				system("pause");                            
				return 1;                                    
			}
			Create_List(eklenecek, size);                     
			listele(secim);                                 -
			break;                                          
			                                  
		case 2:                               
			ekranTemizle();                   
			Pop();                            
			cout << endl;                     
			listele(secim);                   
			break;                            

		case 3:                               
			ekranTemizle();                  
			listele(secim);                  
			break;                           
		case 4:                              
			ekranTemizle();                  
			Say();                            
			break;                            
		case 0:                               
			break;



		default:
			cout << "Wrong choice ";  
			break;
		}
	} while (secim = !0);                           

	system("pause");                              

}





