#include <stdio.h>
int main()
{
    int rows = 9;
    int seat_matrix[9][4] = {0}; // 9 rows and 4 seats on each row
    int total_reserved = 0; // initially
    int total_unreserved = 36; // initially
    int row, seat;

// Function to update the seat matrix
    void update()
    {
	seat_matrix[row - 1][seat - 1] = 1; // adjusting for for loop
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

// Function to take input seat from the user
    void input_seat()
    {
    
Row:
	printf("Enter row number: ");
	scanf("%d", &row);
	// Handling invalid input
	if (row < 1 || row > 9)
	{
	    printf("Enter valid row number (from 1 to 9)\n"); 
	    goto Row;
	}
	
Seat:
	printf("Enter seat number: ");
	scanf("%d", &seat);
	// Handling invalid input
	if (seat < 1 || seat > 4)
	{
	    printf("Enter valid seat number (from 1 to 4)\n");  
	    goto Seat;
	}
	
Reserve_check:
	if (seat_matrix[row - 1][seat - 1] == 1)
	{
	    printf("Seat is taken. Choose another.\n"); // Handling reserved seats
	    goto Row;
	}
	
Update:
	total_reserved++; // Updating 
	total_unreserved--; // Updating 
	printf("+------------------+\n");
	update();
	printf("+------------------+\n");
	printf("Seats reserved: %d, Seats unreserved: %d\n", total_reserved, total_unreserved);
    
    }

// Implementing a do-while loop to take inputs until no more unreserved seats are left
    do 
    {
		input_seat();
    }
    while (total_unreserved != 0);

    return 0;
}

