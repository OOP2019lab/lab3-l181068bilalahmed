#include <iostream>
#include <string>
#include <fstream>
#include "gitHubUser.h"

using namespace std;

void readDataFromFile( gitHubUser *&user, string filepath){
	ifstream fin("C:\\Users\\Bilal Ahmed\\Desktop\\sample.txt");
	if (fin.fail())
		cout << "Could not locate" << endl;
	//Storing Data whle reading each line
	else{
		char temp[500];
		fin.getline(temp, 500);
		int noOfEntries = temp[0] - 48; // Reading User count 
		user = new gitHubUser[noOfEntries];					
		for (int i = 0; i < noOfEntries; i++) {
			fin.getline(temp, 500);
			user[i].firstName = temp;
			fin.getline(temp, 500);
			user[i].userName = temp;
			fin.getline(temp, 500);
			user[i].email = temp;
			fin.getline(temp, 500);
			int noOfFiles = atoi(temp);
			user[i].gitHubFolders = new string[noOfFiles];//Since there are more than 1 folder
			for (int j = 0; j < noOfFiles; j++) {						
				fin.getline(temp, 50);
				user[i].gitHubFolders[j] = temp;
			}
		}
	}
}

void setEduBckGrnd(gitHubUser &user){
	user.qualification_level = new string;
	user.institute_name = new string;
	//Taking Data from user and storing it on heap using pointers made in stack
	cout << user.firstName << " enter your institution name: ";
	cin >> *user.institute_name; // De-allocating pointer to store data on heap, where the pointer points
	cout << user.firstName << " enter your qualification level: ";
	cin >> *user.qualification_level; // De-allocating pointer to store data on heap, where the pointer points
}

void print(gitHubUser &user){
	cout << "First Name: " << user.firstName << endl;
	cout <<  "User Name: " << user.userName << endl;
	cout << "Email Address: " << user.email << endl;
	if (user.qualification_level != nullptr)//Prints data only if the pointer points to something
		cout << "Qualification Level: " << *user.qualification_level << endl;
	if (user.institute_name != nullptr)//Prints data only if the pointer points to something
		cout << "Institute name: " << *user.institute_name << endl;
}

void remove(gitHubUser &user){
	if (user.qualification_level != nullptr){
		delete[] user.qualification_level;// Removes data from where the pointer points(heap)
		user.qualification_level = nullptr;//Pointer now ponts to nothing
	}
	if (user.institute_name != nullptr){
		delete [] user.institute_name;// Removes data from where the pointer points(heap)
		user.institute_name = nullptr;//Pointer now ponts to nothing
	}
}
 
void backup(gitHubUser *originalArry, gitHubUser *&backupArry, int userCount){
	backupArry = new gitHubUser[userCount];
	for (int i = 0; i < userCount ; i++){ //Taking a Deep Copy into a Back Up
	backupArry[i].firstName = originalArry[i].firstName;
	backupArry[i].userName = originalArry[i].userName;
	backupArry[i].email = originalArry[i].email;
	*backupArry[i].institute_name = *originalArry[i].institute_name; // Double Defrence while deep copying
	*backupArry[i].qualification_level = *originalArry[i].qualification_level;// Double Defrence while deep copying
	}
}

void menu(gitHubUser &user){
	int key = 0;
	string filepath;
	//Providing different options
	cout << "Press 1 to enter Background Educational Data" << endl;
	cout << "Press 2 to Print Data" << endl;
	cout << "Press 3 to Remove Background Educational information" << endl;
	cout << "Press 4 to take back up of all the data" << endl;
	cin >> key;

	if (key == 1 ){
		setEduBckGrnd(user);
		cout << endl;
		print(user);
		cout << endl;
		menu(user);//Re-Calling the 'menu' function
	}
	else if (key == 2){
		print(user);
		cout << endl;
		menu(user);//Re-Calling the 'menu' function
	}
	else if (key == 3){
		remove(user);
		cout << endl;
		menu (user);//Re-Calling the 'menu' function
	}
}

int main(){
	int userCount= 50;
	string filepath;
	gitHubUser * user;
	readDataFromFile(user, filepath);
	gitHubUser User;
	menu(User);
	system("pause");
}