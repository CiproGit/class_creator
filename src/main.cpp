#include "class_creator.h"
#include "config.h"
#include <iostream>

using namespace std;

void print_about() {
	string version_string = to_string(VERSION_MAJOR) + "." + to_string(VERSION_MINOR) + "." + to_string(VERSION_PATCH);

	cout << "******************************\n";
	cout << "    CLASS CREATOR\n";
	cout << "    Version " + version_string + "\n";
	cout << "    Developed by\n";
	cout << "    Federico Cipressi\n";
	cout << "******************************\n" << endl;
}

void capitalize(QString &class_name) {
	cout << "Warning: class names should start with capital letters. I will handle that" << endl;
	class_name.replace(0, 1, class_name.at(0).toUpper()); // Capitalize first character
}

QString sanitize(string input) {
	if (input.back() == '\"') { // The last character of the input string is "
		input = input.substr(0, input.size() - 1); // Remove the last character
	}

	replace(input.begin(), input.end(), '\\', '/'); // Replace backslash with forward slash
	return QString::fromStdString(input);
}

int main(int argc, char *argv[]) {
	print_about();

	if (argc == 2) { // 1 argument
		QString class_name = argv[1];
		if (class_name.at(0).isLower()) capitalize(class_name);

		class_creator::Class_creator class_creator(class_name);
		class_creator.print_data();
		if (!class_creator.create_source()) return EXIT_FAILURE;
		if (!class_creator.create_header()) return EXIT_FAILURE;
	}
	else if (argc == 3) { // 2 arguments
		QString class_name = argv[1];
		if (class_name.at(0).isLower()) capitalize(class_name);

		QString project_directory = sanitize(argv[2]);

		class_creator::Class_creator class_creator(class_name, project_directory);
		class_creator.print_data();
		if (!class_creator.create_source()) return EXIT_FAILURE;
		if (!class_creator.create_header()) return EXIT_FAILURE;
	}
	else {
		cerr << "Error: I need 1 or 2 arguments\n";
		cerr << "Usage: class_creator [class name]\n";
		cerr << "Usage: class_creator [class name] [project directory]" << endl;
		return EXIT_FAILURE;
	}

	cout << "End" << endl;
	return EXIT_SUCCESS;
}
