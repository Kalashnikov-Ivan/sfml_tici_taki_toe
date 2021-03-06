#include "Field.h"


Field::Field()
{
	short* sessionField = new short[9];
	for (short i = 0; i < 9; i++)
	{
		sessionField[i] = ' ';
	}
}

Field::~Field()
{
	for (short i = 0; i < 9; i++)
	{
		delete sessionField;
	}
}

char Field::checkFieldState()
{
	char winCh = 'x';
	for (short i = 0; i < 2; i++)
	{
		if (((sessionField[0] == winCh) && (sessionField[1] == winCh) && (sessionField[2] == winCh)) || ((sessionField[3] == winCh) && (sessionField[4] == winCh) && (sessionField[5] == winCh))
			|| ((sessionField[6] == winCh) && (sessionField[7] == winCh) && (sessionField[8] == winCh)) || ((sessionField[0] == winCh) && (sessionField[3] == winCh) && (sessionField[6] == winCh))
			|| ((sessionField[1] == winCh) && (sessionField[4] == winCh) && (sessionField[7] == winCh)) || ((sessionField[2] == winCh) && (sessionField[5] == winCh) && (sessionField[8] == winCh))
			|| ((sessionField[6] == winCh) && (sessionField[4] == winCh) && (sessionField[2] == winCh)) || ((sessionField[8] == winCh) && (sessionField[4] == winCh) && (sessionField[0] == winCh)))
		{
			return winCh;//winner char
		}
		winCh = '0';
	}
	for (short i = 0; i < 9; i++)
	{
		if (sessionField[i] == ' ')
			return 'n';//game continues
	}
	return 'd'; //standoff
}

char Field::getCellState(short cell)
{
	return sessionField[cell];
}

