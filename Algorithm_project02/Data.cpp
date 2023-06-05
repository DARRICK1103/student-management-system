#include <iostream>
#include "Data.h"
#include <stack>
#include <string>
#include <iomanip>
using namespace std;

Data::Data() //Constructor
{
	pHead = NULL; //initialize pHead, pTail, pCurr and pBefore as NULL
	pTail = NULL;
	pCurr = NULL;
	pBefore = NULL;
	StudNum = 0; //Number of students that have been inserted
	StudDelete = 0; //Number of students that have been deleted

}

Data::~Data() //Destructor
{}

void Data::Insert(int opt) //This function is to insert the data(name, IC, group and CGPA)
{
	switch (opt) {
	case 1:
	{
		Node* pNew = new Node; //Define a new node
		string Name_string; //Declare a string
		getline(cin >> ws, Name_string); //Input name
		const char* Name = Name_string.c_str(); //change the datatype of string to const char *
		strcpy_s(pNew->name, Name); //copy the name into the pNew->name
		pNew->link = NULL; //point the next link to null
		pCurr = pNew;
		if (pTail == NULL) //if there is no data in the list
		{

			pHead = pNew; //pHead points to the first data
			pTail = pNew;

		}
		else
		{
			pTail->link = pNew; //The pointer of the previous data points to the new data
			pTail = pNew; //pTail points to the pNew 

		}
		break;
	}

	case 2:
	{
		cin >> pCurr->IC; //Input IC to pCurr->IC
		break;
	}

	case 3:
	{
		cin >> pCurr->group; //Input group to pCurr->group
		break;
	}

	case 4:
	{
		cin >> pCurr->CGPA; //Input CGPA to pCurr->CGPA
		break;
	}

	}
}


void Data::Connect() //To display and ask user to insert data one by one
{
	cout << "Enter name: ";
	Insert(1); //Input name and store it in the new node
	cout << "Enter IC: ";
	Insert(2); //Input IC
	cout << "Enter group: ";
	Insert(3); //Input group
	cout << "Enter CGPA: ";
	Insert(4); //Input CGPA
	AssignID(); //Assign a new ID for the student
	Display(); //Display all the students in the list
}

void Data::Display() //This is to display all the students' information
{
	if (pHead == NULL && pTail == NULL) //if the list is empty
	{
		cout << "The list is empty" << endl << "Please insert some data" << endl;
		Select(); // Go to main menu
	}
	else
	{
		cout << endl << "There are " << StudNum - StudDelete << " students in the list." << endl << endl;
		cout << endl << setw(5) << "ID" << setw(30) << "NAME" << setw(25) << "IC" << setw(25) << "GROUP" << setw(25) << "CGPA" << endl;
		pCurr = pHead;
		while (pCurr != NULL) //while the list is not empty
		{
			cout << setw(5) << pCurr->ID << setw(30) << pCurr->name << setw(25) << pCurr->IC << setw(25) << pCurr->group << setw(25) << pCurr->CGPA << endl;
			pCurr = pCurr->link; //To the next pointer
		}
		cout << endl;
	}

}

void Data::Display(double result) //Display a particular student's information based on its CGPA
{
	pCurr = pHead; //Set pCurr to pHead
	while (pCurr->CGPA != result && pCurr != NULL) //while CGPA in the pCurr is not equal to result + pCurr is not equal to null
	{
		pCurr = pCurr->link; //pCurr points to the next pointer
	}
	cout << setw(5) << pCurr->ID << setw(30) << pCurr->name << setw(25) << pCurr->IC << setw(25) << pCurr->group << setw(25) << pCurr->CGPA << endl;
}

void Data::Searching() //To search and display a particular student's information
{
	if (pHead == NULL && pTail == NULL) //if the list is empty
	{
		cout << "The list is empty" << endl << "Please insert some data" << endl;
		Select(); // Go to main menu
	}
	else
	{
		cout << endl << "This is to search the information of the students in the list." << endl;
		cout << "Enter the ID of the student" << endl;
		cin >> target; //Enter target ID
		bool result = Search();
		if (result == true) //if the ID is found
		{
			cout << endl << setw(5) << "ID" << setw(30) << "NAME" << setw(25) << "IC" << setw(25) << "GROUP" << setw(25) << "CGPA" << endl;
			cout << setw(5) << pCurr->ID << setw(30) << pCurr->name << setw(25) << pCurr->IC << setw(25) << pCurr->group << setw(25) << pCurr->CGPA << endl;
		}
		else
		{
			cout << "The ID is not in the list" << endl;
			Select(); //Go back to main menu
		}
	}

}

void Data::AssignID() //This is to assign the ID to each student automatically
{
	StudNum++; //Datatype of StudNum is int
	string s = to_string(StudNum); //change datatype int to string
	s = string(4 - s.size(), '0') + s;  //Add leading zeroes to the StudNum

	const char* IDstore = s.c_str(); //change string datatype to const char * and store it in IDstore
	strcpy_s(pTail->ID, IDstore); //copy the content in IDstore to pTail->ID
}

void Data::Select() //This function is for user to select 
{
	int selection;
	do
	{
		cout << endl << endl << "*******************************************************" << endl;
		cout << "*    This is BITI student database system             *" << endl;
		cout << "*                                                     *" << endl;
		cout << "*    1. Insert new student's information              *" << endl;
		cout << "*    2. Update a particular student's information     *" << endl;
		cout << "*    3. Delete a student's information                *" << endl;
		cout << "*    4. Search the information of a student           *" << endl;
		cout << "*    5. Display all the students' information         *" << endl;
		cout << "*    6. Arrange according to CGPA (descending order)  *" << endl;
		cout << "*    7. Display the 3 lastest students in the list    *" << endl;
		cout << "*                                                     *" << endl;
		cout << "*    **Enter any key to exit                          *" << endl;
		cout << "*                                                     *" << endl;
		cout << "*******************************************************" << endl << endl;
		cout << "Enter your option(1, 2, 3, 4, 5, 6 or 7)" << endl;
		cin >> selection;

		switch (selection)
		{
		case 1:
			Connect(); //if user select 1, new node will be formed and user will be requested to enter data
			break;
		case 2:
			Update(); //if user select 2, user will be requested to enter the ID of the student and can update the student's information
			break;
		case 3:
			Delete(); //if user select 3, user is able to delete a particular student after entering the student ID
			break;
		case 4:
			Searching(); //if user select 4, user is able to search the information of a student
			break;
		case 5:
			Display(); //if user select 5, then the system will all the students in the list
			break;
		case 6:
			Sorting(); //if user select 6, the system will sort the data from the highest CGPA to the lowest
			break;
		case 7:
			Lastest();
			break;
		default:
			cout << endl << "***********************************************" << endl;
			cout << "     Thank you for using this system :)      " << endl; //if user does not enter 1, 2, 3,4 or 5
			cout << "***********************************************" << endl;
			break;
		}

	} while (selection == 1 || selection == 2 || selection == 3 || selection == 4 || selection == 5 || selection == 6 || selection == 7);
}


void Data::Update() //Update student's information 
{
	char option;
	if (pHead == NULL && pTail == NULL) //if the list is empty
	{
		cout << "There are " << StudNum - StudDelete << " students in the list." << endl;
		cout << "The list is empty." << endl << "Please insert some data." << endl;
		Select(); //Go back to main menu
	}
	else
	{
		cout << endl << "This is to update student's information" << endl;
		Display();
		cout << "Enter the ID of the student" << endl;
		cin >> target; //Enter target ID
		bool confirm = Search(); //find the pointer of the target and store it in pCurr
		if (confirm == true) //if the target is found
		{
			do
			{
				cout << endl << "Select 1, 2, 3, 4 or 5" << endl;
				cout << "1. Update student's name" << endl;
				cout << "2. Update student's IC" << endl;
				cout << "3. Update student's group" << endl;
				cout << "4. Update student's CGPA" << endl;
				cout << "5. Go back to main menu" << endl;
				cin >> option;
				switch (option)
				{
				case '1':
				{
					string Name_string;
					cout << "Update new name: ";
					getline(cin >> ws, Name_string); //Input name and store in Name_string
					const char* Name = Name_string.c_str(); //change dataype string to const char *
					strcpy_s(pCurr->name, Name); //copy the content of Name to pCurr->name
					cout << endl << setw(5) << "ID" << setw(30) << "NAME" << setw(25) << "IC" << setw(25) << "GROUP" << setw(25) << "CGPA" << endl;
					Display(pCurr->CGPA); // Display the information of the updated student
					break;
				}

				case '2':
				{
					cout << "Update new IC: ";
					cin >> pCurr->IC; //Input IC into pCurr->IC
					cout << endl << setw(5) << "ID" << setw(30) << "NAME" << setw(25) << "IC" << setw(25) << "GROUP" << setw(25) << "CGPA" << endl;
					Display(pCurr->CGPA); //Display the information of the updated student
					break;
				}

				case '3':
				{
					cout << "Update new group: ";
					cin >> pCurr->group; //Input group into pCurr->group
					cout << endl << setw(5) << "ID" << setw(30) << "NAME" << setw(25) << "IC" << setw(25) << "GROUP" << setw(25) << "CGPA" << endl;
					Display(pCurr->CGPA); //Display the information of the updated student
					break;
				}

				case '4':
				{
					cout << "Update new CGPA: ";
					cin >> pCurr->CGPA; //Input CGPA into pCurr->CGPA
					cout << endl << setw(5) << "ID" << setw(30) << "NAME" << setw(25) << "IC" << setw(25) << "GROUP" << setw(25) << "CGPA" << endl;
					Display(pCurr->CGPA); //Display the information of the updated student
					break;
				}
				case'5':
					Select();
					break;
				default:
				{
					cout << "You are not entering 1, 2, 3, 4 or 5.";
					break;
				}
				}

				 


			} while (option == 1 || option == 2 || option == 3 || option == 4);

		}

		else
		{
			cout << "There is no ID " << target << " in the list. " << endl;
			Select(); //Go back to main menu
		}
	}
}

void Data::Delete() //To delete a particular student's information
{
	if (pHead == NULL && pTail == NULL) //if the list is empty
	{
		cout << "There are " << StudNum - StudDelete << " students in the list." << endl;
		cout << "The list is empty." << endl << "Please insert some data." << endl;
		Select();

	}
	else
	{
		cout << endl << "This is to delete the information of a student" << endl;
		Display();
		cout << "Enter the ID of the student" << endl;
		cin >> target; //Enter target ID
		bool confirm = Search(); //search the ID if it is true, return true and vice verssa
		if (confirm == true)
		{
			if (pCurr == pHead && pCurr != pTail) //pCurr is the first item
			{
				pHead = pCurr->link; //pHead points to the next pointer
			}
			else if (pCurr == pTail && pCurr != pHead) //pCurr is the last item
			{
				pBefore->link = NULL; //pBefore points to null
				pTail = pBefore; //pTail equals to pBefore

			}
			else if (pCurr != pHead || pCurr != pTail) //pCurr is in the middle of the list
			{
				pBefore->link = pCurr->link; //pBefore's link points to the pCurr's link
			}
			else //pCurr = pHead and pCurr = pTail which means that there is only 1 item in the list
			{
				pHead = NULL; //pHead and pTail points to NULL
				pTail = NULL;
			}
			StudDelete++; //number of student deleted increases
			cout << endl << "The information of student with ID " << target << " has successfully been deleted." << endl;
			Display();

		}

		else
		{
			cout << "Target is not found!!!" << endl;
			Select(); //Go back to main menu
		}

	}
}

bool Data::Search()
{
	
	int Result = strcmp(pHead->ID, target); //compare pHead->ID and target
	if (Result == 0) //if pHead->ID = target
	{
		pCurr = pHead;
		return true;
	}
	else
	{
		pCurr = pHead; //starts to traverse from pHead


		for (int current = 0; current < StudNum - StudDelete; current++) //Number of student = StudNum - StudDelete
		{
			if (Result == 0) //if pCurr->ID = target
				return true;
			pBefore = pCurr;
			pCurr = pCurr->link; //go to the next pointer
			if (pCurr != NULL)
			{
				Result = strcmp(pCurr->ID, target);
			}
			else //if the pointer is pointing to null
				return false;
		}
	}
}

void Data::Sorting() //Arrange the students' CGPA in descending order
{

	if (pHead == NULL && pTail == NULL) //if the list is not empty
	{
		cout << "There are " << StudNum - StudDelete << " students in the list." << endl;
		cout << "The list is empty." << endl << "Please insert some data." << endl;
		Select();

	}
	else
	{
		int NumOfStud, count = 0;
		double array[9999], temp;
		NumOfStud = StudNum - StudDelete; //Total number of student = number of students inserted - number of students deleted
		pCurr = pHead;
		while (pCurr != NULL) //while the list is not empty
		{
			array[count] = pCurr->CGPA; //store CGPA in an array
			pCurr = pCurr->link; //go to the next pointer
			count++;
		}


		cout << endl << setw(5) << "ID" << setw(30) << "NAME" << setw(25) << "IC" << setw(25) << "GROUP" << setw(25) << "CGPA" << endl;

		for (int current = 0; current < NumOfStud; current++)
		{
			for (int next = current + 1; next < NumOfStud; next++)
			{
				if (array[current] < array[next]) //compare the current CGPA and the next CGPA in the array//descending
				{
					temp = array[current];
					array[current] = array[next]; //change the place of the current CGPA with the next CGPA 
					array[next] = temp;
				}
			}

		}

		for (int current = 0; current < NumOfStud; current++) //Display the result 
		{
			double storeResult = array[current];
			Display(storeResult);
		}
	}


}

void Data::Lastest() //using stack to store 
{

	if (StudNum - StudDelete > 2) //if the list have at least 3 data
	{
		pCurr = pHead;
		stack <string> latest;
		while (pCurr != NULL)
		{
			string storeID = pCurr->ID; //To store ID
			latest.push(storeID);
			pCurr = pCurr->link;
		}
		cout << endl << "This is to display the lastest 3 students in the list" << endl;
		cout << endl << setw(5) << "ID" << setw(30) << "NAME" << setw(25) << "IC" << setw(25) << "GROUP" << setw(25) << "CGPA" << endl;


		
		for (int current = 0; current < 3; current++)
		{
			string storeID = latest.top();
			const char* TARGET = storeID.c_str(); //change dataype string to const char *
			strcpy_s(target, TARGET); //copy TARGET to target
			bool result = Search(); //Search the target
			if (result == true) //if the target is found
			{
				cout << setw(5) << pCurr->ID << setw(30) << pCurr->name << setw(25) << pCurr->IC << setw(25) << pCurr->group << setw(25) << pCurr->CGPA << endl;
				latest.pop(); //Delete the data on the top
			}
			else //if the data is not found
			{
				cout << "Error!!!" << endl;
				break;
			}
			
		}

		while (!latest.empty()) //To clear all the data in the stack
		{
			latest.pop(); //Delete all the remaining data
		}
		Select(); //Gp back to main menu

	}
	else //if the list does not have 3 data
	{

		cout << "There are " << StudNum - StudDelete << " students in the list." << endl;
		int total = StudNum - StudDelete;
		if (total == 0) //if the list is empty
		{
			cout << "The list is empty." << endl << "Please insert some data." << endl;
		}
		else
		{
			cout << "Please insert " << 3 - total << " more data" << endl; 
		}
		Select(); //Go back to main menu
	}

}



