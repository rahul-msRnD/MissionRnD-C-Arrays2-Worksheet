/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int myAtoi(char *str, int l, int r)
{
	int i, res = 0;
	for (i = l; i <= r; i++)
		res = res * 10 + str[i] - '0';
	return res;
}

int compareDates(char date1[], char date2[])
{
	int yr1, yr2;
	yr1 = myAtoi(date1, 6, 9);
	yr2 = myAtoi(date2, 6, 9);

	if (yr1 != yr2)
		return yr1 > yr2 ? 1 : -1;
	else
	{
		int m1, m2;
		m1 = myAtoi(date1, 3, 4);
		m2 = myAtoi(date2, 3, 4);

		if (m1 != m2)
			return m1 > m2 ? 1 : -1;
		else
		{
			int day1, day2;
			day1 = myAtoi(date1, 0, 1);
			day2 = myAtoi(date2, 0, 1);

			if (day1 != day2)
				return day1 > day2 ? 1 : -1;
			else
				return 0;
		}
	}
}

int binSearch(struct transaction Arr[], int l, int r, char date[])
{
	if (l > r)
		return -1;
	int mid = (l + r) / 2;
	int flag = (compareDates(Arr[mid].date, date));
	if (flag == 0)
	{
		int flag2 = binSearch(Arr, mid + 1, r, date);
		if (flag2 > 0)
			return flag2;
		else
			return mid;
	}
	else  if (flag > 0)
		return binSearch(Arr, l, mid - 1, date);
	else
		return binSearch(Arr, mid + 1, r, date);

}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int res = binSearch(Arr, 0, len - 1, date);
	if (res < 0)
		return 0;
	return len - res - 1;
}
