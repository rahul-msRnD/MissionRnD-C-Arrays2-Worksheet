/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j = 0, k = 0;
	struct transaction *t = NULL;
	while (A && B && i < ALen && j < BLen)
	{
		if (A[i].amount < B[i].amount)
			i++;
		else if (A[i].amount > B[i].amount)
			j++;
		else
		{
			if (k == 0)
			{
				t = (struct transaction *)malloc(sizeof(struct transaction));
				t[k].amount = A[i].amount;
				strcpy(t[k].date, A[i].date);
				strcpy(t[k].description, A[i].description);
			}
			else
			{
				t = (struct transaction *)realloc(t, (k + 1)*sizeof(struct transaction));
				t[k].amount = A[i].amount;
				strcpy(t[k].date, A[i].date);
				strcpy(t[k].description, A[i].description);
			}
			i++;
			k++;
		}
	}
	return t;
}