#include "class_creator.h"

#ifdef __APPLE__
#include "unix_os.h"
#endif
#ifdef __linux__
#include "unix_os.h"
#endif
#ifdef _WIN32
#include "windows_os.h"
#endif

#include <iostream>
#include <QFile>
#include <QTextStream>

using namespace std;

namespace class_creator {
	Class_creator::Class_creator(QString class_name) {
		this->project_directory = CURRENT_DIR;
		this->class_name = class_name;
		this->lower_class_name = this->class_name.toLower();
		this->upper_class_name = this->class_name.toUpper();
		this->source_file_name = this->lower_class_name + ".cpp";
		this->header_file_name = this->lower_class_name + ".h";
	}

	Class_creator::Class_creator(QString class_name, QString project_directory) {
		this->project_directory = project_directory;
		this->class_name = class_name;
		this->lower_class_name = this->class_name.toLower();
		this->upper_class_name = this->class_name.toUpper();
		this->source_file_name = this->lower_class_name + ".cpp";
		this->header_file_name = this->lower_class_name + ".h";
	}

	Class_creator::~Class_creator() {}

	void Class_creator::print_data() const {
		cout << "Project directory: " << this->project_directory.toStdString() << '\n';
		cout << "Class name: " << this->class_name.toStdString() << '\n';
		cout << "Source file name: " << this->source_file_name.toStdString() << '\n';
		cout << "Header file name: " << this->header_file_name.toStdString() << '\n' << endl;
	}

	bool Class_creator::create_source() const {
		cout << "Create source..." << endl;

		if (!directory::exist((this->project_directory + SOURCE_DIR).toStdString())) {
			cerr << "Error: " << (this->project_directory + SOURCE_DIR).toStdString() << " does not exist" << endl;
			return false;
		}

		QString source_file_path = this->project_directory + SOURCE_DIR + this->source_file_name;
		cout << "Creating " << source_file_path.toStdString() << endl;

		QFile source_file(source_file_path);
		if (!source_file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			cerr << "Error: failed to create source file" << endl;
			return false;
		}

		QTextStream source_stream(&source_file);
		source_stream << "#include \"" + this->header_file_name << "\"\n";
		source_stream << '\n';
		source_stream << "namespace " + this->lower_class_name + " {\n";
		source_stream << '\t' + this->class_name + "::" + this->class_name + "() {}\n";
		source_stream << '\n';
		source_stream << '\t' + this->class_name + "::" + '~' + this->class_name + "() {}\n";
		source_stream << "} // namespace " + this->lower_class_name << Qt::endl;

		source_file.close();

		cout << "Create source done\n" << endl;
		return true;
	}

	bool Class_creator::create_header() const {
		cout << "Create header..." << endl;

		if (!directory::exist((this->project_directory + HEADER_DIR).toStdString())) {
			cerr << "Error: " << (this->project_directory + HEADER_DIR).toStdString() << " does not exist" << endl;
			return false;
		}

		QString header_file_path = this->project_directory + HEADER_DIR + this->header_file_name;
		cout << "Creating " << header_file_path.toStdString() << endl;

		QFile header_file(header_file_path);
		if (!header_file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			cerr << "Error: failed to create header file" << endl;
			return false;
		}

		QTextStream header_stream(&header_file);
		header_stream << "#ifndef " + this->upper_class_name + "_H\n";
		header_stream << "#define " + this->upper_class_name + "_H\n";
		header_stream << '\n';
		header_stream << "namespace " + this->lower_class_name + " {\n";
		header_stream << "\tclass " + this->class_name + " {\n";
		header_stream << "\tprivate:\n";
		header_stream << "\t\t\n";
		header_stream << "\tpublic:\n";
		header_stream << "\t\t" + this->class_name + "();\n";
		header_stream << "\t\tvirtual ~" + this->class_name + "();\n";
		header_stream << "\t};\n";
		header_stream << "} // namespace " + this->lower_class_name + '\n';
		header_stream << '\n';
		header_stream << "#endif // " + this->upper_class_name + "_H" << Qt::endl;

		header_file.close();

		cout << "Create header done\n" << endl;
		return true;
	}
} // namespace class_creator
