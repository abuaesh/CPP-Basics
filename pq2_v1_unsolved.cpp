/*
CSCE 103 - Practical Quiz 2
----------------------------
There are 3 tasks you need to complete in this quiz:
	Task 1: [3 marks] You need to implement the function: search_names 
	Task 2: [5 marks] You need to implement the function: print_search_results 
	Task 3: [2 marks] You need to make appropriate calls to the functions.
To do this, follow the steps 0 through 8 given in comments in this file.
*/

//STEP 0: Write your name, ID and Section in the comment below:
/*
			Name:
			ID:
			Section:
*/

//Library Includes:
#include<iostream>
#include<string>
using namespace std;

//Globals Variables:
const int student_count=5;

//Function Prototypes:
void print_line(); //prints a separator line to the screen
void display_menu();
void take_grades(float[]);
void take_names(string[]);
void print_names_and_grades(const string[], const float[]);

int find_max_grade(const float[], int size);//returns the index of the maximum value in the array
int find_min_grade(const float[], int size);//returns the index of the minimum value in the array
int find_max_name(const string[], int size);//returns the index of the maximum value in the array
int find_min_name(const string[], int size);//returns the index of the minimum value in the array

bool swap(int , int, float[], string[]); // swaps the elements in the array at the given indices

void sort(string[], float[]);
void sort_grades(float[], bool descending, string[]);//sorts the given array in a ascending/descending order according to the given integer
void sort_names(string[], bool descending, float[]);//sorts the given array in a ascending/descending order according to the given bool

void search(const string[], const float[]);
void search_grades(const float[], float key, bool[]); //searches the float array for a key value(float),
										// and stores true in the results array at the indices where the key was found.
										
//STEP 1: [0.5 marks] Uncomment and copy the prototype for search_names below:
//void search_names(const string[], string , bool[]); //searches the string array for a key value(string),
												// and stores true in the results array at the indices where the key was found.
//STEP 4: [0.5 marks] Uncomment and copy the prototype for print_search_results below:												
//void print_search_results(const string[], const float[], const bool[]); //prints the information (name and grade) of the search results
												//that matched the key. To be called directly after any of the search functions.

//==============================Function: MAIN ===============================
int main()
{
	
	float grades[student_count];
	string names[student_count];

	int choice;
	
	while(true)
	{
		display_menu();
		cin >> choice;
		
		print_line();
		
		switch(choice)
		{
			case 1: //Input names
				cout << "INPUTING THE NAMES OF THE STUDENTS\n";
				print_line();
				take_names(names);
				break;
				
			case 2: //Input grades
				cout << "INPUTING THE GRADES OF THE STUDENTS\n";
				print_line();
				take_grades(grades);
				break;
				
			case 3: //Display data
				cout << "DISPLAYING THE DATA OF THE STUDENTS\n";
				print_line();
				print_names_and_grades(names,grades);
				break;
				
			case 4: //Sort
				cout << "SORTING\n";
				print_line();
				sort(names, grades);
				break;
				
			case 5: //Search
				cout << "SEARCHING\n";
				print_line();
				search(names, grades);
				break;
				
			case 6: //Exit program
				cout << "Bye bye!";
				return 0;
			default:
				cout << "I am not sure what you want. Please choose a number from the program menu.\n";
		} //end switch
		
		print_line();
		
	} //end while
	
} //end main
//==============================Function: display_menu =============================
void display_menu()
{
	cout << "Program Menu:\n";
	cout << "1. Input Student Names.\n";
	cout << "2. Input Student Grades.\n";
	cout << "3. Display Student Data.\n";
	cout << "4. Sorting.\n";
	cout << "5. Searching.\n";
	cout << "6. Exit.\n";
}
//==============================Function: take_grades =============================
void take_grades(float garray[])
{
		for(int i=0;i<student_count;i++)
	{
		cout << "Enter the grade for student " << i << ": ";
		cin >> garray[i];
	}
}
//==============================Function: take_names =============================
void take_names(string narray[])
{
		for(int i=0;i<student_count;i++)
	{
		cout << "Enter the name for student " << i << ": ";
		cin >> narray[i];
	}
}
//==============================Function: print_names_and_grades ===============================
void print_names_and_grades(const string narray[], const float garray[])
{
	for(int i=0;i<student_count;i++)
		cout << i << ": " << narray[i] << " - " << garray[i] <<endl;

}
//==============================Function: print_line ===============================
void print_line()
{
	cout <<"******************************************\n";
}
//==============================Function: find_max_grade ===============================
int find_max_grade(const float garray[], int size)
{
	int max_index = 0;
	for(int i=1; i<size; i++)
		if(garray[max_index] < garray[i])
			 max_index = i;
		
	return max_index;
}
//==============================Function: find_max_name ===============================
int find_max_name(const string narray[], int size)
{
	int max_index = 0;
	for(int i=1; i<size; i++)
		if(narray[max_index] < narray[i])
			 max_index = i;
		
	return max_index;
}
//==============================Function: find_min_grade ===============================
int find_min_grade(const float garray[], int size)
{
	int min_index = 0;
	for(int i=1; i<size; i++)
		if(garray[min_index] > garray[i])
			 min_index = i;
		
	return min_index;
}
//==============================Function: find_min_name ===============================
int find_min_name(const string narray[], int size)
{
	int min_index = 0;
	for(int i=1; i<size; i++)
		if(narray[min_index] > narray[i])
			 min_index = i;
		
	return min_index;
}
//==============================Function: swap ===============================
bool swap(int i1, int i2, float garray[], string narray[])
{
	//If given indices have illegal values(<0 or >array size), return false:
	if(i1 < 0 || i1 >= student_count || i2 < 0 || i2 >= student_count)
		return false;
	
	//Do the swap on both arrays:	
	float temp_grade = garray[i1];
	string temp_name = narray[i1];
	
	garray[i1] = garray[i2];
	narray[i1] = narray[i2];
	
	garray[i2] = temp_grade;
	narray[i2] = temp_name;
	
	return true;
}
//==============================Function: sort_grades ===============================
void sort_grades(float garray[], bool descending, string narray[])
{
	int index;
	
	for(int i = 0; i<student_count;i++)
	{
		index = i +  ((!descending)? find_min_grade(garray+i, student_count-i):find_max_grade(garray+i, student_count-i));
		
		swap(i,index, garray, narray);	
	}
}
//==============================Function: sort_names ===============================
void sort_names(string narray[], bool descending, float garray[])
{
	int index;
	
	for(int i = 0; i<student_count;i++)
	{
		index = i +  ((!descending)? find_min_name(narray+i, student_count-i):find_max_name(narray+i, student_count-i));
		
		swap(i,index, garray, narray);	
	}
}
//==============================Function: sort ===============================
void sort(string narray[], float garray[])
{
	int sort_by; //1 for names, any other value for grades
	bool order; //0 for ascending, any other value for descending
	
	cout << "Do you want to sort by:\n1. Names\t2. Grades\n";
	cin >> sort_by;
	
	cout << "Do you want to sort in:\n0. Ascending Order\t1. Descending Order\n";
	cin >> order;
	
	switch(sort_by)
	{
		case 1:	//Sort by names 
			sort_names(narray, order, garray);
			break;
		default: //2 (or any other value): Sort by  grades
			sort_grades(garray, order, narray);
	}
	
	//Print the data after sorting:
	print_names_and_grades(narray, garray);
}
//==============================Function: search ===============================
void search(const string narray[], const float garray[])
{
	int search_by; //1 for names, any other value for grades
	
	cout << "Do you want to search the:\n1. Names\t2. Grades\n";
	cin >> search_by;
	
	//Initialize the whole results array to false
	bool results[student_count] = {0};
	
	string key_name;
	float key_grade;
	
	switch(search_by)
	{
		case 1:	//Search the names
			cout << "Enter the name you are searching for: ";
			cin >> key_name;
			//STEP 7: [1 mark] Call the appropriate function to search for the entered key
			
			break;
		default: //2 (or any other value): Search the grades
			cout << "Enter the grade you are searching for: ";
			cin >> key_grade;
			search_grades(garray, key_grade, results);
	}
	
	//STEP 8: [1 mark] Call the appropriate function to display the results to the user

}
//==============================Function: search_grades ===============================
void search_grades(const float garray[], float key, bool results[])
{
	//Search garray for occurrences of key
	for(int i = 0; i<student_count;i++)
		if(garray[i] == key) //if the key is found in garray at index i,
			results[i] = true;	//assign true at index i in the results array
}
//==============================Function: search_names ===============================
//STEP 2: [0.5 mark] Paste the function prototype for search_names here, 
		//and do the needed changes to make it the header of the function definition

//STEP 3: [2 marks] Write the function body according to the following steps:
		
		//Step 3.1: Search narray for occurrences of key
		//Step 3.2: If the key is found in garray at index i,
					//assign true at index i in the results array





//==============================Function: print_search_results ===============================

//STEP 5: [0.5 mark] Paste the function prototype for print_search_results here, 
		//and do the needed changes to make it the header of the function definition

//STEP 6: [4 marks] Write the function body according to the following steps:
		
		//Step 6.1: Declare and initialize a counter to count the number of occurences
		//Step 6.2: Loop through the results array,
		//Step 6.3: If the result array element at index i was true, 
					//print the name and grade of this record, and increment the counter.
		//Step 6.4: Display how many total matching results were found.















