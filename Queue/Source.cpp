#include<iostream>
#include<string>
#include<iomanip>
#include<locale.h>
using namespace std;
int front = -1, rear = -1, queue_size;
int *Queue;
/** brief The function added a new item to Queue
*param value
*return 0
*/
int EnQueue(int value)
{
	if (queue_size - 1 == rear)
	{
		cout << "\nYou cannot add. The queue is full.!!!";
		return 0;
	}
	else
	{
		if (front == -1)
			front = 0;
		rear++;
		Queue[rear] = value;
		cout << "You added " << value << " to the queue.";
	}
}
/** brief The function to delete a head value of array
*if array is empty give a error message
*/
void deQueue()
{
	if (front == rear)
	{
		cout << "You removed the " << Queue[front] << " element from the queue " << endl;
		cout << "\nKuyruk boþtur !!";
	}
	else
	{
		int sildi = Queue[front];
		cout << "You removed the " << sildi << " element from the queue ";
		Queue[front] = Queue[front + 1];
		front++;
		queue_size++;
	}
}
/** brief The function to show the array as a list.
*/
void listele() {
	if (rear == -1)
		cout << "\nQueue is empty!!!";
	else {
		int i;
		cout << ("\nElements in the queue:\n");
		for (i = front; i <= rear; i++)
			cout << Queue[i] << "\t";
	}
}
/** brief The function show in how many elements of array
*/
void say()
{
	int sayaç = 0;
	for (int i = front; i <= rear; i++)
	{
		sayaç++;
	}
	cout << "There are" << sayaç << " elements in the list. ";
}
/** The function is clean screen.
*/
void ekranTemizle()
{
	system("cls");
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	int  deðer, secim;
	/** brief The queue size is defined by user.
	*/
	cout << " Please enter the queue size. : ";
	cin >> queue_size;
	if (queue_size <= 0)
	{
		cout << " Wrong size!!\n";
		return 0;
	}
	/** brief Dynamic queue is created.
	*/
	Queue = new int[queue_size];
	do
	{
		cout << "\n\n\n\t******** MENU *******\n\n";
		cout << "\n\t1 - Enqueue \n";
		cout << "\t2 - Dequeue \n";
		cout << "\t3 - List \n";
		cout << "\t4 - Count \n";
		cout << "\t0 - Exit \n";
		cout << "\t\n\n\nPlease enter the function:\n";
		cin >> secim;
		ekranTemizle();
		/** brief Make a choice from menu.
		*/
		switch (secim)
		{
			/** brief Want a value from user
			* The function of "EnQueue" is called.
			*/
		case 1:
			cout << "Please enter the number : ";
			cin >> deðer;
			EnQueue(deðer);
			break;
			/** brief The function of "deQueue" is called
			*/
		case 2:
			deQueue();
			cout << endl;
			break;
			/** brief The function of "listele" is called
			*/
		case 3:
			listele();
			break;
			/** breif The function of "say" is called.
			*/
		case 4:
			say();
			break;
		case 0:
			break;
			/** brief For wrong choice
			*/
		default:
			cout << "Wrong choice ";
			break;
		}
	} 
	while (secim = !0);
	system("pause");
}