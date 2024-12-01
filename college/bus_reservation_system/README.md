# Case study on: Bus reservation system

### 1. Introduction:
This case study explores the design and implementation of a basic bus reservation system using the C programming language. The system allows users to reserve seats in a bus, ensuring input validation and maintaining an updated seating arrangement throughout the process. By employing fundamental programming concepts like arrays, loops, and user-defined functions, this system demonstrates practical applications of C for solving real-world problems efficiently.

### 2. Objectives:
- Develop a simple, user-friendly bus reservation system using the C programming language.
- Implement seat selection functionality with real-time updates to the seating arrangement.
- Ensure input validation to handle invalid seat or row numbers and already reserved seats.
- Maintain and display the total count of reserved and unreserved seats dynamically.
- Utilize foundational programming techniques such as arrays, loops, and functions for practical problem-solving.

### 3. Program:
```C
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
	// Handling reserved seats
	if (seat_matrix[row - 1][seat - 1] == 1)
	{
	    printf("Seat is taken. Choose another.\n"); 
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
```

### 4. Expected output:
```
Enter row number: 1
Enter seat number: 2
+------------------+
 ( )  (*)  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
+------------------+
Seats reserved: 1, Seats unreserved: 35
Enter row number: 3
Enter seat number: 3
+------------------+
 ( )  (*)  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  (*)  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
+------------------+
Seats reserved: 2, Seats unreserved: 34
Enter row number: 3
Enter seat number: 10
Enter valid seat number (from 1 to 4)
Enter seat number: 2
+------------------+
 ( )  (*)  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  (*)  (*)  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
+------------------+
Seats reserved: 3, Seats unreserved: 33
Enter row number: 10
Enter valid row number (from 1 to 9)
Enter row number: 2
Enter seat number: 2
+------------------+
 ( )  (*)  ( )  ( )
 ( )  (*)  ( )  ( )
 ( )  (*)  (*)  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
+------------------+
Seats reserved: 4, Seats unreserved: 32
Enter row number: 2
Enter seat number: 2
Seat is taken. Choose another.
Enter row number: 3
Enter seat number: 1
+------------------+
 ( )  (*)  ( )  ( )
 ( )  (*)  ( )  ( )
 (*)  (*)  (*)  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
 ( )  ( )  ( )  ( )
+------------------+
Seats reserved: 5, Seats unreserved: 31
Enter row number: 
```

### 5. Conclusion:
The program above is a simple implementation of a bus reservation system implemented in C using simple ASCII characters, and compiled with the `GNU Compiler Collection (GCC) 14.2.1`, tested on an `x86_64` system. 
