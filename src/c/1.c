/* Program that demonstrates a solution to the following problem:

   1. Write a C function that takes an array of integers and reorders the
   array IN PLACE such that any zeroes are placed at the beginning of
   the array, followed by the nonzero elements in any order.  For
   example, if the original array contains

	43  9  0  -5  0  0  17

   a correct result would be
   
	0  0  0  -5  9  43  17
   
   Here's a skeleton definition for the function:

	void
	reorder(int *arr, int length)
   	{
   	}
   
   arr points to the array and length gives the number of elements.
   Remember that this must be done in place, meaning that you can't
   declare another array inside the function to use for reordering.

*/

#include <stdio.h>


// PROTOTYPES
void reorder(int *arr, int length);
void parray(int *arr, int length);

// MAIN
int main()
{
  /* demonstrate reordering of an array IN PLACE and detects
     if all zeros or no zeros
  */

  int array0[]={43,9,0,-5,0,0,17}; /* mixed bag */
  int array1[]={0,0,0,0,0,0,0};	/* all zeros */
  int array2[]={43,9,3,-5,7,1,17}; /* no zeros */
  int array3[]={0,0,0,0,0,0,9};	/* nonzero at the end */

  /*print the original array -and then...
    print the reordered array
    gcc warns "incompatible pointer" without cast
  */
  parray((int *)&array0,7);
  reorder((int *)&array0, 7);

  parray((int *)&array1,7);
  reorder((int *)&array1, 7);

  parray((int *)&array2,7);
  reorder((int *)&array2, 7);

  parray((int *)&array3,7);
  reorder((int *)&array3, 7);

  return 0;
}

void parray(int *arr, int length)
{
  int current;

  //print the initial array
  for(current = 0; current < length; current++)
    {
      printf("%d ", arr[current]);
    }
  printf("is a ");
}


void reorder(int *arr, int length)
{
  /* reorder an array IN PLACE. placing zeros at the beginning and
     whatever at the end. Also detect if the array is all zeros, no
     zeros, or a mixed bag.
  */
    
  int last=0,current=0, tmp=0;
  
  /* Sort array */
  for(;current < length;current++)
    {
      //find first zero
      if(arr[current] != 0)
	{
	  /* some compilers require braces. best to 
	     always use them for max compatability */
	  continue;
	}
      else
	{
	  if(arr[last] == arr[current])
	    {
	      last++;		/* superfluous if array type
				   detection is not needed */

	      continue;
	    }

	  tmp = arr[last];	/* save the value */

	  arr[last] = arr[current]; /* could have said arr[last]=0 here */

	  arr[current] = tmp;	/* current position holds saved value */

	  current = last + 1;	/* check forward from the last switch +1 */

	  last++;		/* incriment last to the next
				   available switch position */
	}
    }//end for

  //see if all zeros or no zeros
  /* superfluous if array type detection not needed */
  if( (tmp == 0) && (last == 0))
    {
      printf("no zeros found array: ");
    }
  else
    if( (tmp == 0) && (last != 0) &&
	(last != (length - 1)) )
      {
	printf("all zero array: ");
      }
    else
      {
	printf("mixed bag array: ");
      }
  /* end superfluous section */

  //print the final array
  for(current = 0; current < length; current++)
    {
      printf("%d ", arr[current]);
    }

  printf("\n");

}//end reorder()
