//This is just notes

//There are 4 basic sorting algorithms to learn here

/* Selection Sorting
* Its sort of brute forcing
* You take the minimum value and place it at the beginning
* Then you take the second minimum value and place it after the first
* And so on until the vector is completely sorted
*/


/* Bubble Sorting
* You compare adjacent pairs, moving the larger number to the right if one exists
* Basically the opposite of selection sorting in that you place the largest at the end in the first iteration and then keep iterating
* Very easy to write
* It can be improved with removing iterations based on how many iterations have already occured and by checking if a swap occurs at all
* GENERALLY, this is a bad algorithm bc it is slow (uses too many swaps)
*/


/* Insertion Sorting
* You need a partially sorted vector (or base)
* You take out a value, shift everything that should be right of it to the right and then place it in the empty spot
* Sort of complicated, Basically, you have two variables.
* One stores the previous value and one stores the current value
*/


/* Merge Sorting (MOST IMPORTANT)
* Merge Sorting contains two parts, the Merge operation, and the actual Merge Sort algorithm
* 
* Merge operation
* How do you merge two sorted vectors into a single sorted vector
* THESE TWO VECTORS MUST BE SORTED
* You iterate over the vectors in parallel, placing the smaller value from one of the vectors into the output vector and then incrementing the (pointer) from the array pulled from
* Then you finish whichever vector is not at its end
* 
* Merge Sort algorithm
* Split a vector in two
* Sort the left half
* Sort the right half
* Merge the sorted left and right half
* THIS IS RECURSIVE
* Basically, you split left half and sort it by continuing to split the left half
* Do the same for the right half until there is only 1 element in the vector in both sides
* You merge each half after splitting them
*/