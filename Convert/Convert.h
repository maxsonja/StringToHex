#ifndef Convert_h
#define Convert_h

#include "Arduino.h"

class Convert
{
	public:
		byte intValue(char);
		byte toHex(String);
		float toFloat(String);
		long toInt(String);
};
#endif
