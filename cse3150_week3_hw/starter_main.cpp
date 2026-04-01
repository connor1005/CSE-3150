
#include <iostream>
#include <cstring>   // for strlen, strcpy

using std::cout, std::cin, std::endl;

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    // VLAs, not covered
    //char* names[capacity];
    //double gpas[capacity];
    int capacity = std::stoi(argv[1]);

    char** names = new char*[capacity];
    double* gpas = new double[capacity];
    int size = 0;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Add student\n";
        cout << "2. Update GPA\n";
	cout << "3. Print all students\n";
        cout << "4. Compute average GPA\n";
        cout << "5. Quit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
		char tempName[100];
		double tempGPA = 0.0;
		cout << "Please enter student name: ";
		cin >> tempName;
		cout << "Please enter student GPA: ";
		cin >> tempGPA;
		try{
		addStudent(tempName,tempGPA, names, gpas, size, capacity);
		} catch (const char* msg) {
			cout << msg << endl;
		}
		break;
            }
            case 2: {
		char searchName[100];
		double newGpa;
		int foundIndex = -1;

		cout << "Enter name of student to update GPA: ";
		cin >> searchName;

		for (int i = 0; i < size; i++) {
			if (std::strcmp(names[i], searchName) == 0) {
				foundIndex = i;
				break;
			}
		}
		if (foundIndex != -1){
			cout << "Enter the new GPA: ";
			cin >> newGpa;

			updateGPA(&gpas[foundIndex], newGpa);
			cout << "GPA updated!" << endl;
		}
		else{
			cout << "Student not found" << endl;
		}
		break;
            }
            case 3: {
		for (int i = 0; i < size; i++){
			printStudent(names[i], gpas[i]);
		}
                break;
            }
            case 4: {
		try{
			double avg = averageGPA(gpas, size);
			cout << "Average GPA: " << static_cast<int>(avg) << endl;
		}
		catch(const char* msg){
			cout << msg << endl;
		}
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    for (int i = 0; i < size; i++){
	    delete[] names[i];
    }
    delete[] names;
    delete[] gpas;

    return 0;
}



void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
	if (size >= capacity) {
		throw "Error: Capacity reached. Cannot add more students.";
	}
	
	gpas[size] = gpa;
	names[size] = new char[strlen(name) + 1];

	std::strcpy(names[size], name);
	size++;
}

void updateGPA(double* gpaPtr, double newGpa){
	if (gpaPtr != nullptr) *gpaPtr = newGpa;
}

void printStudent(const char* name, const double& gpa) {
	cout << "Student: " << name << " | GPA: " << gpa << endl;
}

double averageGPA(const double gpas[], int size){
	if (size == 0) {
		throw "Error: Cannot compute average GPA with zero students.";
	}
	double sum = 0.0;
	for (int i = 0; i < size; i++){
		sum += gpas[i];
	}
	return sum / size;
}



