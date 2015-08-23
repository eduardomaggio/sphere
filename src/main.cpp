#include <iostream>
#include <string>
#include "angle.h"

using namespace maggio;
using namespace std;

int main ( int argc, char** argv )
{
	double entry = 190;

	if ( argc > 1 )
		entry = stod(string(argv[1]));

	cout << DEG2RAD(180) << endl;

	cout << NormalizeAngleDeg(entry) << endl;

	return 0;
}
