/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int myAtoi1(char *str, int l, int r)
{
	int i, res = 0;
	for (i = l; i <= r; i++)
		res = res * 10 + str[i] - '0';
	return res;
}

int compareDate(char date1[], char date2[])
{
	int yr1, yr2;
	yr1 = myAtoi1(date1, 6, 9);
	yr2 = myAtoi1(date2, 6, 9);

	if (yr1 != yr2)
		return yr1 > yr2 ? 1 : -1;
	else
	{
		int m1, m2;
		m1 = myAtoi1(date1, 3, 4);
		m2 = myAtoi1(date2, 3, 4);

		if (m1 != m2)
			return m1 > m2 ? 1 : -1;
		else
		{
			int day1, day2;
			day1 = myAtoi1(date1, 0, 1);
			day2 = myAtoi1(date2, 0, 1);

			if (day1 != day2)
				return day1 > day2 ? 1 : -1;
			else
				return 0;
		}
	}
}


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL || B == NULL)
		return NULL;
	int i = 0, j = 0, k = 0;
	struct transaction *res = (struct transaction*)calloc(ALen + BLen, sizeof(struct transaction));

	while (i < ALen && j < BLen)
	{
		int r = compareDate(A[i].date, B[j].date);
		if (r == 0)
		{
			res[k] = A[i];
			k++;
			res[k] = B[j];
			k++;
			i++;
			j++;
		}
		else if (r>0)
			res[k++] = B[j++];
		else
			res[k++] = A[i++];
	}
	while (i < ALen)
		res[k++] = A[i++];
	while (j < BLen)
		res[k++] = B[j++];
	return res;
}