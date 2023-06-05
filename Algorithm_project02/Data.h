#ifndef DATA_H
#define DATA_H

class Data
{
private:
	struct Node{
		char ID[5];
		char name[100];
		char IC[12];
		int group;
		double CGPA;
		Node* link;
	};
	char target[5];
	int StudNum;
	int StudDelete;
	Node* pHead; 
	Node* pTail;
	Node* pCurr;
	Node* pBefore;
public:
	Data();
	~Data();
	void Insert(int opt);
	void Connect();
	void Display();
	void Display(double result);
	void Searching();
	void AssignID();
	void Select();
	void Update();
	void Delete();
	bool Search();
	void Sorting();
	void Lastest();
	
};
#endif