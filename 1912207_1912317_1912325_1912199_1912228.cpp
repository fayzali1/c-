#include <fstream>
#include<conio.h>
#include <iostream>
using namespace std;

typedef	struct Node* Nodeptr;
class Object
{
	private:
		string name, ID, brand;
		double price;
	public:
	
	Object()
	{
		name = "NULL";
		ID = "NULL";
		brand = "NULL";
		price = 0;
	
	}
	
	void assignInfo(string v, string w, string x, double y)
	{
		name = v;
		ID = w;
		brand = x;
		price = y;
	}
	string returnName()
	{
		return name;
	}
	
	string returnID()
	{
		return ID;
	}
	string returnBrand()
	{
		return brand;
	}
	double returnPrice()
	{
		return price;
	}
};

class Queue
{
	private:
		int front;
		int rear;
		int maxQue;
		int count;
		int* quantity;
		Object* items; // Dynamic array implementations
	
	public:
	
	Queue()
	{
		maxQue = 501;
		front = 0;
		rear = 0;
		count = 0;
		quantity = new int[maxQue];
		items = new Object[maxQue]; //Dynamically allocates
	}
	
	
	Queue(int max)
	{
		maxQue = max + 1;
		front = 0;
		rear = 0;
		count = 0;
		quantity = new int[maxQue];
		items = new Object[maxQue]; //Dynamically allocates
	}
	~Queue()
	{
		delete[] items; // Deallocates array
	}
	
	int isEmpty() const
	{
		return (count == 0);
	}
	
	
	int isFull() const
	{
		return (count == maxQue);
	}
	
	
	void insert(Object newItem, int quan)
	{
		if (isFull())
		{
			cout << "Over Flow";
		}
	
		else
		{
			items[rear] = newItem;
			quantity[rear] = quan;
			rear = (rear + 1) % maxQue;
			++count;
		}
	}
	
	
	void remove(Object& item, int& quan)
	{
		if (isEmpty())
		{
			cout << "Under Flow";
		}
	
		else
		{
			item = items[front];
			quan = quantity[front];
			front = (front + 1) % maxQue;
			--count;
		}
	}
	
	void show()
	{
		int Tfront = front;
		int Tcount = count;
		cout << "Name\tID\tBrand\tPrice\tQuantity\n";
		while (Tcount != 0)
		{
			cout << items[Tfront].returnName() << "\t";
			cout << items[Tfront].returnID() << "\t";
			cout << items[Tfront].returnBrand() << "\t";
			cout << items[Tfront].returnPrice() << "\t";
			cout << "x" << quantity[Tfront];
			cout << endl;
			Tfront = (Tfront + 1) % maxQue;
			Tcount--;
		}
	}
};


class Node
{
private:
	Object product;
	Nodeptr next;
	Nodeptr list = NULL;

public:
	void insertAtStart(string v, string w, string x, double y)
	{
		Nodeptr p;
		p = new Node;
		p->product.assignInfo(v, w, x, y);
		p->next = list;
		list = p;
	}
	
	
	void deleteAtStart()
	{
		if (list != NULL)
		{
			Node* p = list;
			list = list->next;
			delete p;
			cout << "\tProduct has been deleted\n\n";
		}
		else
		{
			cout << "List Already Empty\n\n";
		}
	}
	
	
	void deleteAtMiddle(string key)
	{
		if (list->product.returnName() == key || list->product.returnID() == key)
		{
			(deleteAtStart());
		}
		else
		{
			Nodeptr q = NULL;
			Nodeptr p;
			for (p = list; p->next != NULL && (p->product.returnName() != key || p->product.returnID() != key); p = p->next)
			{
				q = p;
			}
			if (p->product.returnName() == key || p->product.returnID() == key)
			{
	
				q->next = p->next;
				delete p;
				cout << "\tProduct has been deleted\n\n";
			}
			else
			{
				cout << "Product Not found\n\n";
			}
		}
	
	
	}
	
	bool search(string key, Object& product)
	{
		int found = 0;
		Nodeptr p = list;
		
			for (Nodeptr p = list; p != NULL; p = p->next)
			{
				if (p->product.returnName() == key || p->product.returnID() == key)
				{
					product = p->product;
					found++;
					return true;
				}
			}
	
		if (found == 0)
		{
			
			return false;
		}
	}
	
	void searchBrand(string key)
	{
		int found = 0;
		Nodeptr p = list;
	
	
		for (p = list; p != NULL; p = p->next)
		{
			if (p->product.returnBrand() == key)
			{
				cout << p->product.returnName() << "\t";
				cout << p->product.returnID() << "\t";
				cout << p->product.returnBrand() << "\t";
				cout << p->product.returnPrice() << "\n";
				found++;
			}
		}
		if (found == 0)
		{
			cout << "No such Brand\n";
		}
	}
	
	void showAllProducts()
	{
		for (Nodeptr p = list; p != NULL; p = p->next)
		{
			cout << p->product.returnName() << "\t";
			cout << p->product.returnID() << "\t";
			cout << p->product.returnBrand() << "\t";
			cout << p->product.returnPrice() << "\n";
		}
	}
	
	Object sendProduct(string key)
	{
		Object temp;
		Nodeptr p = list;
		
	
			for (p; p != NULL && (p->product.returnName() != key || p->product.returnID() != key); p = p->next)
			{
				if (p->product.returnName() == key || p->product.returnID() == key)
				{
					temp.assignInfo(p->product.returnName(), p->product.returnID(), p->product.returnBrand(), p->product.returnPrice());
					break;
				}
			}
		
		if (p->product.returnName() == key || p->product.returnID() == key)
			{
				temp.assignInfo(p->product.returnName(),p->product.returnID(),p->product.returnBrand(),p->product.returnPrice());
				return temp;
			}
	
		else
		{
			cout << "Product not found\n";
		}
	
	
	}
	
	void rewriteFile()
	{
		ofstream onFile;
		onFile.close();
		onFile.open("Product.txt");
		Nodeptr p = list;
	
		
		for (p = list; p != NULL; p = p->next)
		{
				onFile << p->product.returnName() << " ";
				onFile << p->product.returnID() << " ";
				onFile << p->product.returnBrand() << " ";
				onFile << p->product.returnPrice() << "\n";
		}
		onFile.close();
	}
};
int main()
{
	string password, username;
	Node shop;
	Queue cart;
	char choice;
	string name, ID, brand;
	double price;
	int quantity, attempt=0;
	double sum = 0;
	bool cond;
	Object product;
	ifstream inFile;
	ofstream onFile;


	inFile.open("Product.txt");
	if (!inFile)
	{
		cout << "Can't Open File" << endl;
		system("pause");
	}
	while (!inFile.eof())
	{
		inFile >> name >> ID >> brand >> price;
		shop.insertAtStart(name, ID, brand, price);
	}
	inFile.close();

	do {



		system("cls");
		cout << "1. for Admin\n";
		cout << "2. for Customer\n";
		cout << "0. to Exit\n";
		cin >> choice;
		system("cls");



		if (choice == '1')
		{
			do {


				cout << "Enter Username: ";
				cin >> username;
				cout << "Enter Password: ";
				cin >> password;

				if (username == "admin" && password == "admin")
				{
					system("cls");
					do {
						
						cout << "1.Check Receipt\n";
						cout << "2.Delete Product\n";
						cout << "3.Add Product\n";
						cout << "0.Exit\n";
						cin >> choice;
						system("cls");

						if (choice == '1')
						{
							inFile.close();
							inFile.open("Receipt.txt");
							if (!inFile)
							{
								cout << "Can't Open File" << endl;
								system("pause");
							}
							cout << "Name\tID\tBrand\tPrice\tQuantity\n";
							while (!inFile.eof())
							{
								inFile >> name >> ID >> brand >> price >> quantity;
								
								cout << name << "\t" << ID << "\t" << brand << "\t" << price << "\t" << quantity << endl;
							
								
							}
							inFile.close();
							system("pause");
							system("cls");
						}

						else  if (choice == '2')
						{
							cout << "Input product ID or name:";
							cin >> name;
							
								shop.deleteAtMiddle(name);
								shop.rewriteFile();
								system("pause");
								system("cls");

						}

						else if (choice == '3')
						{
							onFile.close();
							cout << "Input new product name: ";
							cin >> name;
							if (shop.search(name, product))
							{
								cout << "Product with same name or ID exists\n";
								system("pause");
								system("cls");
							}
							else
							{


								cout << "\nInput new product ID: ";
								cin >> ID;
								if (shop.search(ID,product))
								{
									cout << "Product with same name or ID exists\n";
									system("pause");
									system("cls");
								}
								else
								{
									cout << "\nInput new product Brand: ";
									cin >> brand;
									cout << "\nInput new product price: ";
									cin >> price;

									if (cin.fail())
									{
										cout << "Wrong Input\n";
										system("pause");
										system("cls");
									}
									else
									{
										shop.insertAtStart(name, ID, brand, price);
										onFile.open("Product.txt", fstream::app);
										onFile << endl << name << " " << ID << " " << brand << " " << price;
										onFile.close();
										system("cls");
									}
								}
							}

						}

						else if (choice == '0')
						{
							return 0;
						}
						else
						{

							cout << "invalid choice\n";
							system("pause");
							system("cls");
						}
						system("cls");
					} while (choice != '0');
				}

				else
				{
					system("cls");
					cout << "you username or password is incorrect, please try again\n";
					attempt++;
					system("pause");
					system("cls");
				}
			} while (attempt != 3);

			if (attempt >= 3)
			{
				return 0;
			}
		}



		if (choice == '2')
		{

			do {

				cout << "Please enter the desired number\n";
				cout << "1.Buy whats in shopping cart\n";
				cout << "2.Show all products\n";
				cout << "3.Search by name or by ID\n";
				cout << "4.Search by brand\n";
				cout << "5.Check shopping cart\n";
				cout << "0.Exit\n";
				cin >> choice;
				system("cls");

				if (choice == '1')
				{
					if (cart.isEmpty())
					{
						cout << "Cart is empty\n";
						system("pause");
						system("cls");
					}
					else
					{
						sum = 0;
						price = 0;
						cout << "Name\tID\tBrand\tPrice\n";
						onFile.close();
						onFile.open("Receipt.txt", fstream::app);
						while (!cart.isEmpty())
						{
							cart.remove(product, quantity);
							cout << product.returnName() << "\t";
							onFile << product.returnName() << " ";

							cout << product.returnID() << "\t";
							onFile << product.returnID() << " ";

							cout << product.returnBrand() << "\t";
							onFile << product.returnBrand() << " ";

							cout << product.returnPrice() << "\t";


							cout << "x" << quantity << endl;
							price = product.returnPrice() * quantity;

							onFile << product.returnPrice() << " ";
							onFile << quantity << endl;

							sum += price;
						}
						onFile << endl;

						cout << "The total prince will be: " << sum << endl;

						onFile.close();

						system("pause");
						system("cls");
					}
				}

				else if (choice == '2')
				{
					cout << "Name\tID\tBrand\tPrice\n";
					shop.showAllProducts();
					system("pause");
				}

				else if (choice == '3')
				{
					cout << "Please enter the name or ID of the product you want to add to cart: ";
					cin >> name;
					cout << "Name\tID\tBrand\tPrice\n";
					if (shop.search(name,product))
					{
						cout << endl <<product.returnName() << "\t";
						cout << product.returnID() << "\t";
						cout << product.returnBrand() << "\t";
						cout << product.returnPrice() << "\t";


						cout << "\nDo wish to add this product to your cart:\ny. for yes\nn. for no\n";
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							cout << "How much would you like to buy: ";
							cin >> quantity;
							if (cin.fail())
							{
								cout << "Wrong input\n" << endl;
								system("pause");
								system("cls");
							}
							else
							{
								cart.insert(shop.sendProduct(name), quantity);
								cout << "Product has been1 added\n";
								system("pause");
								system("cls");
							}
						}

						else if (choice == 'n' || choice == 'N')
						{
							cout << "Returning to menu\n";
							system("pause");
							system("cls");
						}

						else
						{
							cout << "Wrong input\n";
							system("pause");
							system("cls");
						}
					}

					else
					{
						cout << "Product not found\n";
						system("pause");
						system("cls");
					}

				}
				else if (choice == '4')
				{
					cout << "Please Enter name of brand: ";
					cin >> brand;
					cout << "Name\tID\tBrand\tPrice\n";
					shop.searchBrand(brand);
					system("pause");
					system("cls");
				}

				else if (choice == '5')
				{
					cart.show();
					system("pause");
					system("cls");
				}

				else if (choice == '0')
				{
					return 0;
				}

				else
				{
					cout << "Invalid input\n";
					system("pause");
					system("cls");
				}
				system("cls");
			} while (choice != '0');

		}

		else if (choice == '0')
		{
			return 0;
		}

		else
		{
			cout << "invalid choice\n"; 
			system("pause");
		}
		system("cls");
	} while (choice != '0');
}

