#include <stdio.h>
int main()
{
    int rows = 9;
    int seat_matrix[9][4] = {0};
    int total_reserved = 0; 
    int total_unreserved = 36;
    int row, seat;

    void update()
    {
	seat_matrix[row - 1][seat - 1] = 1;
	for (int x = 0; x < rows; x++) 
	{
	    for (int y = 0; y < 4; y++)
	    {
		if (seat_matrix[x][y] == 1)
		{
		    printf(" (*) ");
		}
		else 
		{
		    printf(" ( ) ", x+y);
		}
	    }
	    printf("\n");
	}
    }

    void input_seat()
    {
Row:
	printf("Enter row number: ");
	scanf("%d", &row);
	if (row < 1 || row > 9)
	{
	    printf("Enter valid row number (from 1 to 9)\n");
	    goto Row;
	}
Seat:
	printf("Enter seat number: ");
	scanf("%d", &seat);
	if (seat < 1 || seat > 4)
	{
	    printf("Enter valid seat number (from 1 to 4)\n");
	    goto Seat;
	}

Reserve_check:
	if (seat_matrix[row - 1][seat - 1] == 1)
	{
	    printf("Seat is taken. Choose another.\n");
	    goto Row;
	}
Update:
	total_reserved++;
	total_unreserved--;
	printf("+------------------+\n");
	update();
	printf("+------------------+\n");
	printf("Seats reserved: %d, Seats unreserved: %d\n", total_reserved, total_unreserved);
    }

    do 
    {
	input_seat();
    }
    while (total_unreserved != 0);

    return 0;
}

