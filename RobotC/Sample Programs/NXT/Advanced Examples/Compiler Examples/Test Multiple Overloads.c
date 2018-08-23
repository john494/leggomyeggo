

void testIt(char *pChars)
{
	return;
}

//intrinsic void sprintfxx(string &sDest, const char *pzFormatString, ...)
//                asm(opcdStringOps, strOp_snprintf,  variableRefString(sDest),
//                                byte(parmSourceConstant), byte(20), byte(0),    // constant value 20
//                                variableRefCharPtr(pzFormatString),
//                                varArgListOfLongs);

intrinsic void sprintfxx(char *pzCharsString, const char *pzFormatString, ...)
                asm(opcdStringOps, strOp_sprintf,
                                variableRefCharPtr(pzCharsString),
                                variableRefCharPtr(pzFormatString),
                                varArgListOfLongs);

void test_sprintf()
{
	int	x = 10;
	char  str[20];
	string str1;

	testIt(str);
	memset(str, ' ', sizeof(str));

	for (x = 0; x < 30; x += 10)
	{
		sprintf(str,   "%3d", x + 0);
		sprintf(str,    "%3d", x + 1);
		sprintf(str,    "%3d", x + 2);
		sprintfxx(str, "%3d", x + 3);
		sprintfxx(str,  "%3d", x + 4);
		sprintfxx(str,  "%3d", x + 5);

		sprintf(str1,   "%3d", x + 0);
		sprintf(str1,    "%3d", x + 1);
		sprintf(str1,    "%3d", x + 2);
		sprintfxx(str1, "%3d", x + 3);
		sprintfxx(str1,  "%3d", x + 4);
		sprintfxx(str1,  "%3d", x + 5);
	}
}

void test_strcat()
{
	string A = "Test";
	string B = "ing";

	strcat(A,B);
	stringConcatenate(A, B); //Shouldn't these be the same?
}

void test_strcpy()
{
	string A = "Test";
	char B[] = "ing";
	string C = "MoreTest";
	char D[] = "                    ";

	strcpy(A, B);
	strcpy(A, C);

	strcpy(D, A);
	strcpy(D, B);
	strcpy(D, C);
}

void test_strtrim()
{
	string A = "Test  ";
	char B[] = "   ing";
	strTrim(A);
	strTrim(B);
}

void test_srand()
{
	//word A1 = "212313";				// These should generate errors. No conversion possible from 'char *' to 'short'
	//long B2 = "432432423";		// These should generate errors. No conversion possible from 'char *' to 'short'
	//long B3 = "";							// These should generate errors. No conversion possible from 'char *' to 'short'

	//srand(A1);
	//srand(B2);
	srand(1000);
	srand(100000);
}

void test_display()
{
	string A = "Test";
	string B = "ing";

	displayString(0, A);
	displayString(1, "Test%s", B);

	displayTextLine(0, B);
	displayTextLine(1, "  Test%s", B);

	displayBigTextLine(0, A);
	displayBigTextLine(2, "Test%s", B);

	displayCenteredTextLine(0, A);
	displayCenteredTextLine(1, "Test%s", B);

	displayCenteredBigTextLine(0, A);
	displayCenteredBigTextLine(2, "Test%s", B);

	displayStringAt(0, 8, A);
	displayStringAt(20,8, "Test%s", B);

	displayBigStringAt(0, 16, A);
	displayStringAt(20,   16, "Test%s", B);

	scrollText(A);
	scrollText("Test%s", B);
}


void test_DebugStream()
{
	string A = "Test";
	char B[] = "ing";
	writeDebugStream(A);
	writeDebugStream(B);	//Different Error - No WriteDebugStream support for chars?
	writeDebugStreamLine(A);
	writeDebugStreamLine(B);
}

void test_math()
{
	int A = 5;
	long B = 123456;
	float C = 3.1415;

	int returnA = 0;
	int returnB = 0;
	short returnCShort = 0;
	float returnCFloat = 0;

	returnA = sqrt(A);
	returnB = sqrt(B);
	returnCShort = sqrt(C);
	returnCFloat = sqrt(C);

	returnA = abs(A);
	returnB = abs(B);
	returnCShort = abs(C);
	returnCFloat = abs(C);

	returnA = sgn(A);
	returnB = sgn(B);
	returnCShort = sgn(C);
	returnCFloat = sgn(C);
}

void test_stringManip()
{
  string resultString;
	char A = 'A';
	short B = 123;
	long C = 123456;
	float D = 3.1415;
	string E = "Hello World";
	char F[] = "Good Morning";
	string G = "523";
	char H[] = "354";
	string I = "3.412";
	char J[] = "223.512";

  stringAssign(resultString, A);
	stringAssign(resultString, B);
	stringAssign(resultString, C);
	stringAssign(resultString, D);
	stringAssign(resultString, E);
	stringAssign(resultString, F);

	stringConcatenate(resultString, E);
	stringConcatenate(E,F);
	stringConcatenate(E,A);

	reverseChars(E);
	reverseChars(F);

	atoi(G);
	atoi(H);

	atof(I);
	atof(J);

	strlen(E);
	strlen(F);

	stringFromChars(resultString, E);
	stringFromChars(resultString, F);

}

void test_sscanf()
{
  string baseData = "25 December 2012";
  char baseDataChar[] = "1 January 2013";

  short dayShort;
  short yearShort;

  long dayLong;
  long yearLong;
  string monthname;

  sscanf(baseData, 			"%hd %s %hd", &dayShort, &monthname, &yearShort);
  sscanf(baseDataChar, 	"%hd %s %hd", &dayShort, &monthname, &yearShort);

  sscanf(baseData, 			"%d %s %d",   &dayLong,  &monthname, &yearLong);
  sscanf(baseDataChar,  "%d %s %d",   &dayLong,  &monthname, &yearLong);

}

task main()
{
	test_sprintf();
	test_sscanf();
	test_strcat();
	test_strcpy();

	test_strtrim();
	test_srand();
	test_display();
	test_stringManip();
	test_DebugStream();
	test_math();
}
