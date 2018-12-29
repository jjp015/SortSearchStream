#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void input(int[], int&, int);
void selectionSort(int[], int);
void bubbleSort(int[], int);
void show(int[], int);
int binarySearch(int[], int, int);
int linearSearch(int[], int, int);
float mean(int[], int);
int const SIZE = 50;

int main() {
	char select;
	int list[SIZE] = {};
	int list_size, find, result;
	float avg;
	ifstream infile;
	string filename;

	cout << "Integers needed. 'f' to input from file or 'i' to input values "
		<< "yourself: ";
	cin >> select;
	while (toupper(select) != 'F' && toupper(select) != 'I') {
		cout << "Pressed an incorrect key\n";
		cout << "Integers needed. 'f' to input from file or 'i' to input values "
			<< "yourself: ";
		cin >> select;
	}
	if (toupper(select) == 'F') {
		cout << "Enter the filename: \n";
		cin >> filename;
		infile.open(filename);

		if (infile) {
			cout << "Reading values in the file...\n";
			infile >> list_size;
			if (list_size > 50) {
				cout << "There can be a max of 50 elements. Please correct the "
					<< "first line in the file.\n";
				system("pause");
				exit(-1);
			}
			infile >> find;
			for (int i = 0; i < list_size; i++)
				infile >> list[i];
			infile.close();
			cout << "List filled\n\n";
		}
		else {
			cout << "Error opening the file. Please check file name.\n";
			system("pause");
			exit(-1);
		}

	}
	else {
		input(list, list_size, SIZE);
		cout << endl;
	}


	cout << "The numbers are: ";
	show(list, list_size);
	cout << endl;

	cout << "Select a sorting algorithm. 's' for selection sort or 'b' for "
		<< "bubble sort: ";
	cin >> select;
	while (toupper(select) != 'S' && toupper(select) != 'B') {
		cout << "Pressed an incorrect key\n";
		cout << "Select a sort algorithm: 's' for selection sort or 'b' for "
			<< "bubble sort: ";
		cin >> select;
	}
	if (toupper(select) == 'S')
		selectionSort(list, list_size);
	else
		bubbleSort(list, list_size);

	cout << endl;
	cout << "After sorting the list, we have: ";
	show(list, list_size);

	avg = mean(list, list_size);
	cout << endl << endl;

	cout << "The mean of the numbers in the list is: " << avg << endl << endl;

	cout << "Enter the number you want to search for in the list: ";
	cin >> find;

	cout << "Select a search algorithm. 'b' for binary search or 'l' for linear "
		<< "search: ";
	cin >> select;
	while (toupper(select) != 'B' && toupper(select) != 'L') {
		cout << "Pressed an incorrect key" << endl;
		cout << "Select a search algorithm. 'b' for binary search or 'l' for "
			"linear search: ";
		cin >> select;
	}
	if (toupper(select) == 'B')
		result = binarySearch(list, list_size, find);
	else
		result = linearSearch(list, list_size, find);

	if (result == -1)
		cout << find << " does not exist.\n";
	else
		cout << "The number is found in array " << result << endl;

	system("pause");
	return 0;
}

void input(int li[], int &u, int s) {
	do {
		cout << "How many elements are in the list? (max is 50 elements)\n";
		cin >> u;
	} while (u > 50);

	for (int i = 0; i < u; i++) {
		cout << "Please enter the value for element " << (i + 1) << " in the "
			<< "list.\n";
		cin >> li[i];
	}
}

void selectionSort(int li[], int u) {
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (u - 1); startScan++) {
		minIndex = startScan;
		minValue = li[startScan];
		for (int index = startScan + 1; index < u; index++) {
			if (li[index] < minValue) {
				minValue = li[index];
				minIndex = index;
			}
		}
		li[minIndex] = li[startScan];
		li[startScan] = minValue;
	}
}

void bubbleSort(int li[], int u) {
	bool swap;
	int temp;

	do {
		swap = false;
		for (int i = 0; i < (u - 1); i++) {
			if (li[i + 1] < li[i]) {
				temp = li[i];
				li[i] = li[i + 1];
				li[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

void show(int li[], int u) {
	for (int i = 0; i < u; i++)
		cout << li[i] << ' ';
}

int binarySearch(int li[], int u, int f) {
	int first = 0, last = u - 1, middle, position = -1;
	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (li[middle] == f) {
			found = true;
			position = middle;
		}
		else if (li[middle] > f)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}

int linearSearch(int li[], int u, int f) {
	int i = 0;
	int position = -1;
	bool found = false;

	while (!found && i < u) {
		if (li[i] == f) {
			found = true;
			position = i;
		}
		i += 1;
	}
	return position;
}

float mean(int li[], int u) {
	float total = 0;

	for (int i = 0; i < u; i++)
		total += li[i];

	return (total / u);
}