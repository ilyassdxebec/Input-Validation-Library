#include <iostream>
#include"clsInputValidate.h"

using namespace std;

int main()
{    

	clsDate Date;

	clsInputValidate Validate;

	cout << ((Validate.IsValidDate(Date)) ? "Yeah The Date is valid!\n" : "No The Date is Invalid!\n");

	Date.Print();

	Date.PrintYearCalendar();
}
