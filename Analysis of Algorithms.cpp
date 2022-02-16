

//libraries
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


//function prototype 
int main();
void bubbleSort(int arr[], int n);
void swap(int *xp, int *yp);
int partition(int arr[], int low, int high);


// the fuction part the array send to ti using last element as pivot
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];	// pivot 
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		//please note that if current element is smaller than pivot, increment the low element
	
		if (arr[j] <= pivot) // if arr[j] <= pivot we swap 
		{
			i++;	// increment index of smaller element 
			swap(&arr[i], &arr[j]);//call swap function 
		}
	}

	swap(&arr[i + 1], &arr[high]);//call swap function 
	return (i + 1);
}





//This fuction write the sorted arraies to spreadsheet file
void printArray(int arr[], int size, int sortType, int sortRecords)
{
	//variables
	int i, temp, count = 0;
	ofstream myFile;

/*	  for (i = 1; i < size; i++){
        cout << arr[i]<<",";
        

}*/

	

	if (sortType == 1)
	{
		if (sortRecords == 1)
		{
			//open file
			myFile.open("bubblesort1000Record.csv");

		}

		if (sortRecords == 2)
		{
			//open file
			myFile.open("bubblesort2000Records.csv");

		}
		else
		{
			//open file
			myFile.open("bubblesort30000Records.csv");
		}
	}

	if (sortType == 2)
	{
		if (sortRecords == 1)
		{
			//open file 
			myFile.open("quicksort1000Records.csv");

		}

		if (sortRecords == 2)
		{
			//open file
			myFile.open("quicksort2000Records.csv");

		}
		else
		{
			//open file
			myFile.open("quicksort30000Records.csv");
		}
	}


	for (i = 1; i < size; i++)
	{
		
		temp = arr[i];
		myFile << temp << ","; //right array to the file 

	}


}





//Menu fuction that give the user a menu
void displaymenu()
{
	cout << "===================================================== \n";
	cout << " \t\tMENU \t \n ";
	cout << "===================================================== \n";
	cout << " 1.Bubble Sort\n";
	cout << " 2.Quick Sort\n";
	cout << " 3.Bubble Sort and Quick Sort\n";


}	



//this fuction sort the array using bubble sort

int bubblesort(int size)
{

	//variables
	ifstream recordfiles;
	int recordarray[size];
	int num, count, sortType, sortRecords;
	int size2 = 15000;
	chrono::time_point<std::chrono::system_clock > start, end;


	if (size == 1000)
	{
		ifstream recordfiles("1000Records.txt");// read file 
		if (recordfiles.is_open()) // test if file open correctly 
		{
			while (recordfiles >> num) // get records from file 
			{
				recordarray[count] = num; // store the data from file to an array
				count++;
			}

			recordfiles.close();  // close file after data is read
			
			start = std::chrono::system_clock::now(); // start the clock fuction 
			
			for (int i = 0; i < count - 1; i++) //loop
			{
				for (int j = 0; j < count - i - 1; j++) //loop
				{
					if (recordarray[j] > recordarray[j + 1]) //test to see if records or less than
					{
						//swap data 
						int temp = recordarray[j];
						recordarray[j] = recordarray[j + 1];
						recordarray[j + 1] = temp;
					}
				}
			}

			end = std::chrono::system_clock::now(); // end clock 

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			cout<<"\nbubblesort\n";
			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";// print out time

			sortType = 1;
			sortRecords = 1;

			printArray(recordarray, count, sortType, sortRecords);

		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 2000)
	{
		ifstream recordfiles("2000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			for (int i = 0; i < count - 1; i++)
			{
				for (int j = 0; j < count - i - 1; j++)
				{
					if (recordarray[j] > recordarray[j + 1])
					{
						//swap(&arr[j], &arr[j+1]);
						int temp = recordarray[j];
						recordarray[j] = recordarray[j + 1];
						recordarray[j + 1] = temp;
					}
				}
			}

			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			cout<<"\nbubblesort\n";
			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 1;
			sortRecords = 2;
			printArray(recordarray, count, sortType, sortRecords);

		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 30000)
	{
		ifstream recordfiles("3000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			for (int i = 0; i < count - 1; i++)
			{
				for (int j = 0; j < count - i - 1; j++)
				{
					if (recordarray[j] > recordarray[j + 1])
					{
						//swap(&arr[j], &arr[j+1]);
						int temp = recordarray[j];
						recordarray[j] = recordarray[j + 1];
						recordarray[j + 1] = temp;
					}
				}
			}

			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			cout<<"\nbubblesort\n";
			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 1;
			sortRecords = 3;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else
	{
		cout << "Can't open the file";
		exit;
	}
}

// Swap two elements - Utility function  
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


//quicksort algorithm
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//part the array 
		int pivot = partition(arr, low, high);

		//sort the sub arrays independently 
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);

	}
}

//quickSort2

void quickSort2(int size)
{
	ifstream recordfiles;
	int recordarray[size];
	int num, count, sortType, sortRecords;
	chrono::time_point<std::chrono::system_clock > start, end;


	if (size == 1000)
	{
		ifstream recordfiles("fairlysorted1000.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now(); // start the clock fuction 
			
			quickSort(recordarray, 0, count - 1);
			
			end = std::chrono::system_clock::now(); // end clock 
			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			cout<<"\nQuicksort\n";
			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";// print out time
		
			sortType = 2;
			sortRecords = 1;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 2000)
	{
		ifstream recordfiles("fairlysorted2000.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			quickSort(recordarray, 0, count - 1);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
				cout<<"\nQuicksort\n";
			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 2;
			sortRecords = 2;
			printArray(recordarray, count, sortType, sortRecords);

		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 30000)
	{
		ifstream recordfiles("fairlysorted3000.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			
			quickSort(recordarray, 0, count - 1);
			end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
				cout<<"\nQuicksort\n";
			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 2;
			sortRecords = 3;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else
	{
		cout << "Can't open the file";
		exit;
	}
}



//exitcode

void exitProgram()
{
	cout << " Good Bye";
	exit(0);
}

//display menu allow user to pick the amount of records
void displaymenu2(int choice)
{
	int confirm;
	int records;

	if (choice == 1)
	{
		cout << " \n\t\t\t Bubble Sort\n";
		cout << " 1: 1,000 array record entries\n";
		cout << " 2: 2,000 array record entries\n";
		cout << " 3. 3,000 array record entries \n";
		cout << " 4. Exit \n";
		cin >> confirm;
		if (confirm == 1)
		{
			records = 1000;
		}
		else if (confirm == 2)
		{
			records = 2000;

		}
		else if (confirm == 3)
		{
			records = 30000;

		}
		else if (confirm == 4)
		{
			exitProgram();

		}

		bubblesort(records);
		main();

	}
	else if (choice == 2)
	{
		cout << " \n\t\t\t Quick Sort\n";
		cout << " 1: 1,000 array record entries\n";
		cout << " 2: 2,000 array record entries\n";
		cout << " 3. 3,000 array record entries \n";
		cout << " 4. Back \n";
		cout << " 5. Exit \n";
		cin >> confirm;
		if (confirm == 1)
		{
			records = 1000;
		}
		else if (confirm == 2)
		{
			records = 2000;

		}
		else if (confirm == 3)
		{
			records = 30000;

		}
		else if (confirm == 4)
		{
			exitProgram();

		}

		quickSort2(records);
		main();

	}
	
		else if (choice == 3)
	{
		cout << " \n\t\t\t bubblesort + Quick Sort\n";
		cout << " 1: 1,000 array record entries\n";
		cout << " 2: 2,000 array record entries\n";
		cout << " 3. 3,000 array record entries \n";
		cout << " 4. Back \n";
		cout << " 5. Exit \n";
		cin >> confirm;
		if (confirm == 1)
		{
			records = 1000;
		}
		else if (confirm == 2)
		{
			records = 2000;

		}
		else if (confirm == 3)
		{
			records = 30000;

		}
		else if (confirm == 4)
		{
			exitProgram();

		}

		bubblesort(records);
		quickSort2(records);
		main();
	}
	
	else{
		
		exit(0);
	}

	}


int main()
{
	string st[20];
	int itemcount = 0;

	//function to display Menu

	displaymenu();
	int yourchoice;
	string confirm;
	do {
		cout << "Enter your choice(1-3):";
		cin >> yourchoice;

		if (yourchoice >= 1 || yourchoice <= 4)
		{
			displaymenu2(yourchoice);

		}
		else
		{
			cout << "Wrong Choice";
			cout << "Press y or Y to continue, Press any other Key to Exit:";
			cin >> confirm;
		}
	} while (confirm == "y" || confirm == "Y");
	return 0;
}























