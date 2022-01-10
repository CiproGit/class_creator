#ifndef UNIX_OS_H
#define UNIX_OS_H

#include <iostream>

namespace directory {
	bool exist(std::string directory); // It checks if the given directory exists
	bool create(std::string directory); // It creates the given directory
} // namespace directory

#endif // UNIX_OS_H
