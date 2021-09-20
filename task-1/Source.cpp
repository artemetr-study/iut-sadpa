#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student;
void mainMenu();
vector<Student> getStudents();
void searchByLastName(vector<Student>& students);
string getStudentsData();
void printStudentData(Student student);
Student getStudentByString(string data);
void printStudentsThatTable(vector<Student>& students);
vector<string> split(string datas, char needle);
int countSplit(string data, string needle);
string getPath();

struct Student {
	string lastName;
	string firstName;
	string secondName;
	int marks[5];
	int group_id;
	float middleMarks;
};

void main() {
	setlocale(LC_ALL, "Russian");
	mainMenu();
	system("pause");
}

//DONE//
vector<Student> getStudents() {
	vector<Student> result;
	vector<string> studentDatasStr = split(getStudentsData(), '!');
	for (int i = 0; i < studentDatasStr.size(); i++) {
		result.push_back(getStudentByString(studentDatasStr[i]));
	}
	return result;
}

//DONE//
string getStudentsData() {
	string result = "";
	string path, line;
	path = getPath();
	ifstream in(path);
	if (in.is_open()) {
		while (getline(in, line)) {
			result += (line + "!");
		}
	}
	else {
		cout << "Файл не найден!" << '\n';
		system("exit");
	}
	in.close();
	return result;
}

//DONE//
int countSplit(string data, string needle) {
	int count = 0;
	for (size_t pos = 0; pos < data.size(); pos += needle.size()) {
		pos = data.find(needle, pos);
		if (pos != string::npos) count++;
	}
	return count;
}

//DONE//
vector<string> split(string datas, char needle) {
	vector<string> studList;
	string curStr = "";

	for (int i = 0; i < datas.size(); i++) {
		if (datas[i] == needle) {
			studList.push_back(curStr);
			curStr = "";
			continue;
		}
		curStr.push_back(datas[i]);
	}

	return studList;
}

//DONE//
Student getStudentByString(string data) {
	Student student;
	vector<string> strList = split(data, ';');

	for (int i = 0; i < strList.size(); i++) {
		switch (i) {
		case (0):
			student.lastName = strList[i];
			break;
		case (1):
			student.firstName = strList[i];
			break;
		case (2):
			student.secondName = strList[i];
			break;
		case (3):
			student.marks[0] = stoi(strList[i]);
			break;
		case (4):
			student.marks[1] = stoi(strList[i]);
			break;
		case (5):
			student.marks[2] = stoi(strList[i]);
			break;
		case (6):
			student.marks[3] = stoi(strList[i]);
			break;
		case (7):
			student.marks[4] = stoi(strList[i]);
			break;
		case (8):
			student.group_id = stoi(strList[i]);
			break;
		}
	}

	student.middleMarks = 0;
	for (int i = 0; i < 5; i++) {
		student.middleMarks += student.marks[i] * 1.0;
	}
	student.middleMarks /= 5;

	return student;
}

//TODO//
string getPath() {
	string path, exp;
	do {
		exp = "";
		cout << "Please enter the path to the file .txt:" << endl;
		cin >> path;
		/*TODO*/
		/*Какая то хрень, не ловит ошибки*/
		try {
			exp.push_back(path[path.size() - 4]);
			exp.push_back(path[path.size() - 3]);
			exp.push_back(path[path.size() - 2]);
			exp.push_back(path[path.size() - 1]);
		}
		catch (int e) {
			cout << "Please try again!" << endl;
		}
	} while (path.size() < 5 && exp.size() != 4 && ".txt" != exp);
	return path;
}

void printStudentData(Student student) {
	string result = "";

	result += "\n\n----------Student----------\n";
	result += "Lastname:\t";
	result += student.lastName;
	result += "\nFirstname:\t";
	result += student.firstName;
	result += "\nSecondname:\t";
	result += student.secondName;
	result += "\nMarks:\t";
	result += to_string(student.marks[0]);
	result += "\t";
	result += to_string(student.marks[1]);
	result += "\t";
	result += to_string(student.marks[2]);
	result += "\t";
	result += to_string(student.marks[3]);
	result += "\t";
	result += to_string(student.marks[4]);
	result += "\nMiddle Marks:\t";
	result += to_string(student.middleMarks);
	result += "\n---------------------------\n";

	cout << result << endl;
}

void searchByLastName(vector<Student>& students) {
	string needle;
	int count;
	cout << "Please enter the student's last name:" << endl;
	cin >> needle;
	for (int i = 0; i < students.size(); i++) {
		count = 0;
		for (int j = 0; j < students[i].lastName.size(); j++) {
			if (students[i].lastName[j] == needle[count]) {
				count++;
			}
		}
		if (count / needle.size() >= 0.5) {
			printStudentData(students[i]);
		}
	}
}

void sortByMiddleMark(vector<Student>& students) {
	Student temp;
	for (int i = 0; i < students.size() - 1; i++) {
		for (int j = 0; j < students.size() - i - 1; j++) {
			if (students[j].middleMarks > students[j + 1].middleMarks) {
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}
	printStudentsThatTable(students);
}

void printStudentsThatTable(vector<Student>& students) {
	string result = "";

	result += "\n\n---------Students table---------\n№\tLastname\tFirstname\tSecondname\tMiddleMarks";
	for (int i = 0; i < students.size(); i++) {
		result += "\n" + to_string(i + 1);
		result += "\t" + students[i].lastName;
		result += "\t" + students[i].firstName;
		result += "\t" + students[i].secondName;
		result += "\t" + to_string(students[i].middleMarks);
	}
	result += "\n--------------------------------";

	cout << result << endl;
}

void mainMenu() {
	vector<Student> students = getStudents();
	int num = 0;
	while (num >= 0) {
		cout << "\nДоступные действия: \n";
		cout << "№\tComment\n";
		cout << "1\t\nОтсортировать по возрастанию средней оценки.\n";
		cout << "2\t\nПоиск по фамилии.\n";
		cout << "\nВыберете действие и введите его номер:\n";
		cin >> num;
		switch (num) {
		case 1:
			sortByMiddleMark(students);
			break;
		case 2:
			searchByLastName(students);
			break;
		}
	}

}