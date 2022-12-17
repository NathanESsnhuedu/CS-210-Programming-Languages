#include <Python.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

void displayFrequency(int frequency, string item) 
{
	// PRINT frequency of item found in file
	cout << item << " appears " << frequency << " times." << endl;
}

void passInputToPython()
{
	string userString = "nothing";
	int frequency = 0;
	cout << "Which item would you like the frequency of purchase for?" << endl;
	// INPUT item name from user keyboard
	cin >> userString;
	// SET frequency equal to what is returned from python function "ItemFrequency" with parameter 'userString'
	frequency = callIntFunc("ItemFrequency", userString);
	// CALL function 'displayFrequency' to display frequency
	displayFrequency(frequency, userString);
}

void printNewWrittenFile() {
	ifstream inFS;
	string product;
	int frequency;
	int i;

	//cout << "Opening file for reading..." << endl;
	// OPEN file "frequency.dat" for reading
	inFS.open("frequency.dat");
	// IF file is NOT open, THEN
	if (!inFS.is_open()) {
		// PRINT error message
		cout << "Could not open file frequency.dat" << endl;
	}
	//cout << "Reading file..." << endl;
	// LOOP WHILE file doesn't end
	while (!inFS.fail()) {
		//cout << "Reading new product name..." << endl;
		// INPUT item name from file
		inFS >> product;
		//cout << "Reading new frequency..." << endl;
		// INPUT frequency of appearance from file
		inFS >> frequency;
		// PRINT item name with space
		cout << product << " ";
		// LOOP FOR as many times as the value of 'frequency'
		for (i = 0; i < frequency; i++) {
			// PRINT a star
			cout << "*";
		}
		// PRINT a new line
		cout << endl;
	}
	//cout << "Closing file..." << endl;
	// CLOSE file for reading
	inFS.close();

}

void menu() 
{
	int userInput = 0;
	// LOOP WHILE variable 'userInput' does NOT equal four
	while (userInput != 4)
	{
		// PRINT list of options and prompt for input
		cout << "Menu" << endl;
		cout << "1: Produce list of purchases" << endl;
		cout << "2: Determine frequency of purchases of a specific item" << endl;
		cout << "3: Display data file as a text-based histogram" << endl;
		cout << "4: End program" << endl;
		cout << "Enter a number to perform the corresponding action." << endl;
		// LOOP WHILE 'userInput' has nothing
		while (!(cin >> userInput)) {
			// PRINT error message
			cout << "Error: Enter a number." << endl;
			// CLEAR input
			cin.clear();
			// INGORE previous input
			cin.ignore(123, '\n');
		}
		// PRINT input 
		cout << "You chose " << userInput << endl;
		// IF 'userInput' is LESS THAN one OR GREATER THAN four 
		if ((userInput < 1) || (userInput > 4)) {
			// PRINT error message
			cout << "Number must correspond to an action" << endl;
		}
		// EXECUTE the code associated with the corresponding case number using 'userInput'
		switch (userInput)
		{
		// IF 'userInput' is equal to one
		case 1:
			// CALL python function "ListPurchases" 
			CallProcedure("ListPurchases");
			// BREAK from SWITCH
			break;
		case 2:
			// CALL function "passInputToPython"
			passInputToPython();
			break;
		case 3:
			// CALL python function "readInputWriteNewFile"
			CallProcedure("readInputWriteNewFile");
			// function "printNewWrittenFile"
			printNewWrittenFile();
			break;
		case 4:
			cout << "Goodbye" << endl;
			break;
		}
	}
}

void main()
{
	// CALL function "menu"
	menu();
}