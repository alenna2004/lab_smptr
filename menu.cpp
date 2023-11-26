#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include "unptr.h"
#include "shptr.h"
#include "seq.h"
#include "listseq.h"
#include "arseq.h"


using std::cout;
using std::cin;
using std::endl;


const char* HELLO_PART = """Welcome to our programm which provides access to unique pointers and shared pointers.\n\
All avaliable functions are shown in our menu.\n\
The pointers created with options 1 and 2 will be added to array and all of them\n\
will have their own number starting from 1 (the second created pointer will have number 2 and so on).\n\
Please, be a good user and don't try to do anything unexpected or not permited.\n""";


void print_base_options()
{
	cout << "Choose what to do and enter the appropriate number:\n";
	cout << "1. Create Shared Pointer\n";
	cout << "2. Create Unique Pointer\n";
	cout << "3. Get original pointer\n";
	cout << "4. Reset pointer\n";
	cout << "5. Swap two pointers\n";
	cout << "6. Quit\n";

}


template<typename T>
void create_and_print_menu()
{
	system("clear");
	cout << HELLO_PART;
	ArraySequence<UniquePtr<T>*>* uniq_ptrs= new ArraySequence<UniquePtr<T>*>;
	ArraySequence<SharedPtr<T>*>* shared_ptrs= new ArraySequence<SharedPtr<T>*>;
	int choice;
	do {
		print_base_options();
		cin >> choice;
		while(cin.fail()){
			cout << "Wrong value. Try again\n";
			cin.clear();
			cin.ignore();
			cin >> choice;
		}
		switch(choice) {
			case 1:{
				system("clear");
				int opt;
				cout << "Choose the way of creation:\n";
				cout << "1. Create from item\n";
				cout << "2. Create as a copy of another pointer\n";
				cin >> opt;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> opt;
				}
				switch(opt){
					case 1:{
						system("clear");
						T item;
						cout << "Enter item\n";
						cin >> item;
						while(cin.fail()){
							cout << "Wrong value. Try again\n";
							cin.clear();
							cin.ignore();
							cin >> item;
						}
						SharedPtr<T>* new_pointer = new SharedPtr<T>(new T(item));
						shared_ptrs->append(new_pointer);
						cout << "The pointer was successfully created. Its number is " << shared_ptrs->get_length() << "\n";
						break;
					}
					case 2:{
						system("clear");
						int number;
						cout << "Enter the number of shared pointer you want to copy\n";
						cin >> number;
						while(cin.fail()){
							cout << "Wrong value. Try again\n";
							cin.clear();
							cin.ignore();
							cin >> number;
						}
						if(number > shared_ptrs->get_length()){
							cout << "OOPS! We don't have a shared pointer with this number.";
							cout <<" Number must be poitive and less than " << shared_ptrs->get_length() <<"\n";
						}
						else{
							SharedPtr<T>* new_pointer = new SharedPtr<T>();
							new_pointer = (*shared_ptrs)[number-1];
							shared_ptrs->append(new_pointer);
							cout << "The pointer was successfully created. Its number is " << shared_ptrs->get_length() << "\n";
						}
						break;
					}
					default:
					int new_opt;
					cout << "Please choose an integer between 1 and 2\n";
					cin >> new_opt;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> new_opt;
					}
					opt = new_opt;
					break;
				}
				break;
			}
	        case 2:{
	        	system("clear");
				T item;
				cout << "Enter item\n";
				cin >> item;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> item;
				}
				UniquePtr<T>* new_pointer = new UniquePtr<T>(new T(item));
				uniq_ptrs->append(new_pointer);
				cout << "The pointer was successfully created. Its number is " << uniq_ptrs->get_length() << "\n";
				break;
			}
			case 3:{
				system("clear");
				int opt;
				cout << "Choose the type of pointer:\n";
				cout << "1. Shared pointer\n";
				cout << "2. Unique pointer\n";
				cin >> opt;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> opt;
				}
				switch(opt){
					case 1:{
						system("clear");
						int number;
						cout << "Enter the number of shared pointer\n";
						cin >> number;
						while(cin.fail()){
							cout << "Wrong value. Try again\n";
							cin.clear();
							cin.ignore();
							cin >> number;
						}
						if(number > shared_ptrs->get_length()){
							cout << "OOPS! We don't have a shared pointer with this number.";
							cout <<" Number must be poitive and less than " << shared_ptrs->get_length() <<"\n";
						}
						else{
							cout << "The pointer is " << (*shared_ptrs)[number-1]->get() << "\n";
						}
						break;
					}
					case 2:{
						system("clear");
						int number;
						cout << "Enter the number of unique pointer\n";
						cin >> number;
						while(cin.fail()){
							cout << "Wrong value. Try again\n";
							cin.clear();
							cin.ignore();
							cin >> number;
						}
						if(number > uniq_ptrs->get_length()){
							cout << "OOPS! We don't have a unique pointer with this number.";
							cout <<" Number must be poitive and less than " << uniq_ptrs->get_length() <<"\n";
						}
						else{
							cout << "The pointer is " << (*uniq_ptrs)[number-1]->get() << "\n";
						}
						break;
					}
					default:
					int new_opt;
					cout << "Please choose an integer between 1 and 2\n";
					cin >> new_opt;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> new_opt;
					}
					opt = new_opt;
					break;
				}
				break;
			}
			case 4:{
				system("clear");
				int opt;
				cout << "Choose the type of pointer:\n";
				cout << "1. Shared pointer\n";
				cout << "2. Unique pointer\n";
				cin >> opt;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> opt;
				}
				switch(opt){
					case 1:{
						system("clear");
						int number;
						cout << "Enter the number of shared pointer\n";
						cin >> number;
						while(cin.fail()){
							cout << "Wrong value. Try again\n";
							cin.clear();
							cin.ignore();
							cin >> number;
						}
						if(number > shared_ptrs->get_length()){
							cout << "OOPS! We don't have a shared pointer with this number.";
							cout <<" Number must be poitive and less than " << shared_ptrs->get_length() <<"\n";
						}
						else{
							system("clear");
							cout << "Enter the item to reset\n";
							T item;
							cout << "Enter item\n";
							cin >> item;
							while(cin.fail()){
								cout << "Wrong value. Try again\n";
								cin.clear();
								cin.ignore();
								cin >> item;
							}
							(*shared_ptrs)[number-1]->reset(new T(item));
							cout << "The item was successfully reseted\n";
						}
						break;
					}
					case 2:{
						system("clear");
						int number;
						cout << "Enter the number of unique pointer\n";
						cin >> number;
						while(cin.fail()){
							cout << "Wrong value. Try again\n";
							cin.clear();
							cin.ignore();
							cin >> number;
						}
						if(number > uniq_ptrs->get_length()){
							cout << "OOPS! We don't have a unique pointer with this number.";
							cout <<" Number must be poitive and less than " << uniq_ptrs->get_length() <<"\n";
						}
						else{
							system("clear");
							cout << "Enter the item to reset\n";
							T item;
							cout << "Enter item\n";
							cin >> item;
							while(cin.fail()){
								cout << "Wrong value. Try again\n";
								cin.clear();
								cin.ignore();
								cin >> item;
							}
							(*uniq_ptrs)[number-1]->reset(new T(item));
							cout << "The item was successfully reseted\n";
						}
						break;
					}
					default:
					int new_opt;
					cout << "Please choose an integer between 1 and 2\n";
					cin >> new_opt;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> new_opt;
					}
					opt = new_opt;
					break;
				}
				break;
			}
			case 5:{
				system("clear");
				int opt;
				cout << "Choose the type of pointer:\n";
				cout << "1. Shared pointer\n";
				cout << "2. Unique pointer\n";
				cin >> opt;
				while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> opt;
				}
				switch(opt){
					case 1:{
						system("clear");
						int number_1;
						cout << "Enter the number of first shared pointer\n";
						cin >> number_1;
						while(cin.fail()){
							cout << "Wrong value. Try again\n";
							cin.clear();
							cin.ignore();
							cin >> number_1;
						}
						if(number_1 > shared_ptrs->get_length()){
							cout << "OOPS! We don't have a shared pointer with this number.";
							cout <<" Number must be poitive and less than " << shared_ptrs->get_length() <<"\n";
						}
						else{
							int number_2;
							cout << "Enter the number of second shared pointer\n";
							cin >> number_2;
							while(cin.fail()){
								cout << "Wrong value. Try again\n";
								cin.clear();
								cin.ignore();
								cin >> number_2;
							}
							if(number_2 > shared_ptrs->get_length()){
								cout << "OOPS! We don't have a shared pointer with this number.";
								cout <<" Number must be poitive and less than " << shared_ptrs->get_length() <<"\n";
							}
							else{
								(*shared_ptrs)[number_1-1]->swap(*((*shared_ptrs)[number_2-1]));
								cout << "The pointers were successfully swapped\n";
							}
						}
						break;
					}
					case 2:{
						system("clear");
						int number_1;
						cout << "Enter the number of first unique pointer\n";
						cin >> number_1;
						while(cin.fail()){
							cout << "Wrong value. Try again\n";
							cin.clear();
							cin.ignore();
							cin >> number_1;
						}
						if(number_1 > uniq_ptrs->get_length()){
							cout << "OOPS! We don't have a unique pointer with this number.";
							cout <<" Number must be poitive and less than " << uniq_ptrs->get_length() <<"\n";
						}
						else{
							int number_2;
							cout << "Enter the number of second unique pointer\n";
							cin >> number_2;
							while(cin.fail()){
								cout << "Wrong value. Try again\n";
								cin.clear();
								cin.ignore();
								cin >> number_2;
							}
							if(number_2 > uniq_ptrs->get_length()){
								cout << "OOPS! We don't have a unique pointer with this number.";
								cout <<" Number must be poitive and less than " << uniq_ptrs->get_length() <<"\n";
							}
							else{
								(*uniq_ptrs)[number_1-1]->swap(*((*uniq_ptrs)[number_2-1]));
								cout << "The pointers were successfully swapped\n";
							}
						}
						break;
					}
					default:
					int new_opt;
					cout << "Please choose an integer between 1 and 2\n";
					cin >> new_opt;
					while(cin.fail()){
						cout << "Wrong value. Try again\n";
						cin.clear();
						cin.ignore();
						cin >> new_opt;
					}
					opt = new_opt;
					break;
				}
				break;
			}
			case 6:{
				break;
			}
			default:
			int new_choice;
			cout << "Please choose an integer between 1 and 6\n";
			cin >> new_choice;
			while(cin.fail()){
					cout << "Wrong value. Try again\n";
					cin.clear();
					cin.ignore();
					cin >> new_choice;
			}
			choice = new_choice;
			break;
		}
	}while (choice != 6);
}


int main()
{
	int var = 0;
	system("clear");
	cout << "Choose variable type for work\n";
	cout << "1. Integer\n";
	cout << "2. Double\n";
	cout << "3. Char\n";
	cin >> var;
	if(var  == 1){
		create_and_print_menu<int>();
	}
	else if(var == 2){
		create_and_print_menu<double>();
	}
	else if(var == 3){
		create_and_print_menu<char>();
	}
	else{
		cout << "You entered bad value. The programm is over. Try again\n";
	}
	return 0;
}