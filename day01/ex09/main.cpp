#include "Logger.hpp"

int main(void) {
	Logger l("xxx");

	l.log("logToFile", "1st");
	l.log("logToFile", "2nd");
	l.log("logToFile", "3rd");
	l.log("logToConsole", "4th");
	l.log("logToConsole", "5th");
	l.log("logToConsole", "6th");
	return 0;
}
