#include <stdio.h>

#define SIZE 100000

void mix_up(int nums[], int size);
void print_list(int nums[], int size);
void bubble_sort(int nums[], int size);
void selection_sort(int nums[], int size);
void my_swap(int* a, int* b);
void insertion_sort(int nums[], int size);
void shell_sort(int nums[], int size);

int main(int argc, char* argv[])
{
	int nums[SIZE];

	printf("Size = %d\n\n", SIZE);

	mix_up(nums, SIZE);
	bubble_sort(nums, SIZE);
	printf("\nBubble Sorted\n");

	mix_up(nums, SIZE);
	selection_sort(nums, SIZE);
	printf("\nSelection Sorted\n");

	mix_up(nums, SIZE);
	insertion_sort(nums, SIZE);
	printf("\nInsertion Sorted\n");

	mix_up(nums, SIZE);
	shell_sort(nums, SIZE);
	printf("\nShell Sorted\n");
	
	return 0;
}

/*
wicked fast
	Shell Sort:
		h-sort a list with decreasing values of h until h is one;
		Whereas h-sort is insertion sort, but rather than comparing values 1 away
		we compare values h away.
*/
void shell_sort(int nums[], int size)
{
	int h, b;
	for (h = size - 1; h > 0; h /= 2)
	{
		for (b = h; b < size; b++)
		{
			int c = b;
			while (c-h + 1 > 0 && nums[c] < nums[c - h])
			{
				my_swap(&nums[c], &nums[c - h]);
				c-=h;
			}
		}
	}
}

/*
	Insertion Sort:
		Consider the first element in the array to be a sorted list.
		For each index in the remaining unsorted array swap them
		to their left until they are in the correct position.
*/
void insertion_sort(int nums[], int size)
{
	int a, b, c;
	for (a = 1; a < size; a++)
	{
		c = a;
		while(nums[c] < nums[c - 1])
		{
			my_swap(&nums[c], &nums[c - 1]);
			c--;
		}
	}
}

/*
	Selection Sort:
		Whereas i starts at the beginning of the list,
		for all i except the last, iterate through the list finding
		the index that holds the smallest value and swap it into the
		i'th position.
*/
void selection_sort(int nums[], int size)
{
	int a, b, min = 0;
	for (a = 0; a < size - 1; a++)
	{
		min = a;
		for (b = a; b < size; b++)
		{
			if (nums[b] < nums[min])
				min = b;
		}
		my_swap(&nums[a], &nums[min]);
	}
}

/*
	Bubble Sort:
		Starting at the beginning of the list, iterate through the
		list comparing adjacent pairs, swapping them if they are out of order.
		Do this n-1 times.
*/
void bubble_sort(int nums[], int size)
{
	int a;
	for (int b = 0; b < size - 1; b++)
	{
		for (a = 0; a < size - 1; a++)
		{
			if (nums[a] > nums[a + 1])
				my_swap(&nums[a], &nums[a + 1]);
		}
	}
}

//gives us worst case scenario
void mix_up(int nums[], int size)
{
	int a, b = size-1;
	for (int a = 0; a < size; a++, b--)
	{
		nums[a] = b;
	}
}

void print_list(int nums[], int size)
{
	int a;
	for (a = 0; a < size; a++)
	{
		printf("%d\n", nums[a]);
	}
}

void my_swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}