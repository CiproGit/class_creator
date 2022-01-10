#include "unix_os.h"
#include <sys/stat.h>

using namespace std;

namespace directory {
	bool exist(string directory) {
		struct stat file_status;

		if (stat(directory.c_str(), &file_status) == -1) return false; // Directory does not exist
		if (S_ISDIR(file_status.st_mode)) return true; // Directory exists

		return false; // Directory does not exist
	}

	bool create(string directory) {
		if (mkdir(directory.c_str(), 0775) == 0) return true; // Directory created with read/write/execution permissions for owner and group and with read/search permissions for others
		else if (errno == EEXIST) return true; // Directory already exists
		else { // Error
			cerr << "Error: failed to create directory " << directory << endl;
			return false;
		}
	}
} // namespace directory
