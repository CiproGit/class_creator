#ifndef CLASS_CREATOR_H
#define CLASS_CREATOR_H

#include <QString>

namespace class_creator {
	const QString CURRENT_DIR = ".";
	const QString SOURCE_DIR = "/src/";
	const QString HEADER_DIR = "/include/";

	class Class_creator {
	private:
		QString project_directory;
		QString class_name;
		QString lower_class_name;
		QString upper_class_name;
		QString source_file_name;
		QString header_file_name;
	public:
		Class_creator(QString class_name);
		Class_creator(QString class_name, QString project_directory);
		virtual ~Class_creator();
		void print_data() const;
		bool create_source() const;
		bool create_header() const;
	};
} // namespace class_creator

#endif // CLASS_CREATOR_H
