#include "class_creator.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "**********************\n";
	cout << "*   CLASS CREATOR    *\n";
	cout << "**********************\n" << endl;

	if (argc == 2) { // 1 argument
		QString class_name = argv[1];
		if (class_name.at(0).isLower()) {
			cout << "Warning: class names should start with capital letters. I will handle that" << endl;
			class_name.replace(0, 1, class_name.at(0).toUpper()); // Capitalize first character
		}

		class_creator::Class_creator class_creator(class_name);
		class_creator.print_data();
		if (!class_creator.create_source()) return EXIT_FAILURE;
		if (!class_creator.create_header()) return EXIT_FAILURE;
	}
	else if (argc == 3) { // 2 arguments
		QString class_name = argv[1];
		if (class_name.at(0).isLower()) {
			cout << "Warning: class names should start with capital letters. I will handle that" << endl;
			class_name.replace(0, 1, class_name.at(0).toUpper()); // Capitalize first character
		}

		QString project_directory = argv[2];

		class_creator::Class_creator class_creator(class_name, project_directory);
		class_creator.print_data();
		if (!class_creator.create_source()) return EXIT_FAILURE;
		if (!class_creator.create_header()) return EXIT_FAILURE;
	}
	else {
		cerr << "Error: I need 1 or 2 arguments\n";
		cerr << "Usage: class_creator.exe [class name]\n";
		cerr << "Usage: class_creator.exe [class name] [project directory]" << endl;
		return EXIT_FAILURE;
	}

	cout << "End" << endl;
	return EXIT_SUCCESS;
}
