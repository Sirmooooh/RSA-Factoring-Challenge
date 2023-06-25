#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *stream;                  // File stream
	char *line = NULL;             // Line buffer for getline()
	size_t len = 0;                // Length of the line
	long long flag = 1, div, rest, number, counter; // Variables for calculations
	ssize_t nread;                 // Number of characters read by getline()

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);  // Display usage if incorrect arguments provided
		exit(EXIT_FAILURE);        // Exit program with failure status
	}

	stream = fopen(argv[1], "r");   // Open the file in read mode
	if (stream == NULL) {
		perror("fopen");           // Display error if file opening fails
		exit(EXIT_FAILURE);        // Exit program with failure status
	}

	while ((nread = getline(&line, &len, stream)) != -1) {
		flag = 1;
		div = 2;
		number = atoll(line);       // Convert the read line to a long long integer

		while (flag) {
			rest = number % div;    // Calculate remainder
			if (!rest) {
				counter = number / div;
				printf("%lld=%lld*%lld\n", number, counter, div);  // Print the factors of the number
				flag = 0;            // Exit the loop
			}
			div++;
			// Increment divisor for finding factors
		}
	}

	free(line);                     // Free the allocated memory for line buffer
	fclose(stream);                 // Close the file
	exit(EXIT_SUCCESS);             // Exit program with success status
}
