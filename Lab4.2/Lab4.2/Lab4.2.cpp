#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string file_format(const string file_path_full) {
	size_t pos = file_path_full.rfind('.');
	if (pos <= 0) {
		return "";
	}
	return file_path_full.substr(pos + 1, string::npos);
}


void task1() {
	string file_path_full;

	cout << "enter full pyt file: " << endl;
	cin >> file_path_full;

	cout << file_format(file_path_full) << endl;
}


string file_name(const string file_path_full) {
	size_t pos = file_path_full.rfind('\\');
	if (pos <= 0) {
		return "";
	}
	size_t pos2 = file_path_full.rfind('.');
	if (pos2 <= 0) {
		return "";
	}
	return file_path_full.substr(pos + 1, pos2 - pos - 1);
}

void task2() {
	string file_path_full;

	cout << "enter full pyt file: " << endl;
	cin >> file_path_full;

	cout << file_name(file_path_full) << endl;
}

string file_path(const string file_path_full) {
	size_t pos = file_path_full.rfind('\\');
	if (pos <= 0) {
		return "";
	}
	return file_path_full.substr(0, pos + 1);
}

void task3() {
	string file_path_full;

	cout << "enter full pyt file: " << endl;
	cin >> file_path_full;

	cout << file_path(file_path_full) << endl;
}

char file_disk(const string file_path_full) {
	return file_path_full[0];
}

void task4() {
	string file_path_full;

	cout << "enter full pyt file: " << endl;
	cin >> file_path_full;

	cout << file_disk(file_path_full) << endl;
}

bool file_rename(const string file_path_full, const string new_file_path_full) {
	return rename(file_path_full.c_str(), new_file_path_full.c_str());
}

void task5() {
	string file_path_full;
	string new_file_name;
	cout << "enter full pyt file: " << endl;
	cin >> file_path_full;
	cout << "enter new name for file: " << endl;
	cin >> new_file_name;

	if (!file_rename(file_path_full, file_path(file_path_full) + new_file_name + '.' + file_format(file_path_full))) {
		cout << "file was successfully renamed" << endl;
	}
	else {
		cout << "failed to rename file" << endl;
	}
}

bool file_copy(const string file_path_full) {

	ifstream fin(file_path_full);

	if (!fin.is_open()) {
		return false;
	}


	ofstream fin_copy(file_path(file_path_full) + file_name(file_path_full) + "_copy." + file_format(file_path_full));
	if (!fin_copy.is_open()) {
		return false;
	}


	string line;

	while (fin) {
		getline(fin, line);
		if (fin.fail()) {
			break;
		}
		fin_copy << line << '\n';
	}


	fin.close();
	fin_copy.close();

	return true;
}

void task6() {
	string file_path_full;

	cout << "re-enter file location: " << endl;
	cin >> file_path_full;

	if (file_copy(file_path_full)) {
		cout << "file copy was successfully created" << endl;
	}
	else {
		cout << "failed to copy file" << endl;
	}
}

int main() {
	int choice = 0;
	while (true) {
		cout << "what do you want to use? \n 1 - 6 \n 7. exit \n";
		cin >> choice;
		switch (choice) {
		case 1: {
			task1();
			break;
		}
		case 2: {
			task2();
			break;
		}
		case 3: {
			task3();
			break;
		}
		case 4: {
			task4();
			break;
		}
		case 5: {
			task5();
			break;
		}
		case 6: {
			task6();
			break;
		}
		case 7: {
			return 0;
			break;
		}
		default: {
			cout << "invalid input, no such function!" << endl;
		}
		}
	}
	return 0;
}