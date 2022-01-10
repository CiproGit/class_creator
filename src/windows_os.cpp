#include "windows_os.h"
#include <Windows.h>

using namespace std;

namespace directory {
	bool exist(string directory) {
		LPCSTR dir = const_cast<char *>(directory.c_str());

		DWORD file_attributes = GetFileAttributes(dir);
		if (file_attributes == INVALID_FILE_ATTRIBUTES) return false; // Directory does not exist
		if (file_attributes & FILE_ATTRIBUTE_DIRECTORY) return true; // Directory exists

		return false; // Directory does not exist
	}

	bool create(string directory) {
		LPCSTR dir = const_cast<char *>(directory.c_str());

		if (CreateDirectory(dir, nullptr)) return true; // Directory created
		else if (GetLastError() == ERROR_ALREADY_EXISTS) return true; // Directory already exists
		else { // Error
			cerr << "Error: failed to create directory " << directory << endl;
			return false;
		}
	}
} // namespace directory
