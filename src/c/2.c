/* Program which demonstrates a solution to the following prblem:

   2. Write a C function to return the number of 1 bits contained in a
   one byte value.  Here are some example sets of input and output
   values:

        Input           Output
        ----------------------
        5               2
        0               0
        32              1
        127             7

   Your initial approach will probably involve using an
   iterative method of some sort (which is fine).  After you do it
   that way, see if you can come up with a method that doesn't require
   any repetitive operations (i.e., a method that doesn't loop, doesn't
   examine each bit to determine how many are set to 1, doesn't do anything
   8 times, etc.). The goal of this non-iterative method is to produce the
   count of 1 bits as fast as possible.

   Here's a skeleton definition for the function:

        int
        count_bits(unsigned char value)
        {

        }
*/



#include <stdlib.h>
#include <stdio.h>

//PROTOTYPES
unsigned int get_num_char_bits(unsigned char word);
unsigned char cheezy_getopt(int argc, char *argv[]);


//MAIN
int main(int argc, char *argv[])
{
  int i, num_ones = 0;
  unsigned char in;

  //obtain the the number from the command line
  in = cheezy_getopt(argc, argv);

  //print number
  printf("\nnumber: %d\n", in);


  /* iteratively obtain the number of 1 bits in a byte 
   */
  for(i = 0; i < sizeof(unsigned int)*8; i++)
    {
      /* shift 1 by i positions, then see if the bits match */
      if(in & (1 << i) )
	{
	  /* an on bit was found, report it */
	  printf("a one was found in position %d\n",i);
	  num_ones++;
	}
    }

  printf("total number of ones from iterative algorythm = %d\n",num_ones);

  /* obtain the number of 1 bits in a byte non-iteratively
   */
  printf("total number of ones from non-iterative algorythm = %d\n",get_num_char_bits(in));

  return 0;
}


/* return the number of bits set in an unsigned char
 without using iteration
*/
unsigned int get_num_char_bits(unsigned char word)
{
  //NOTE: THIS IS INTENDED FOR 1 BYTE ONLY
  word -= (word >> 1) & 0x55;
  word = (word & 0x33) + ((word >> 2) & 0x33);
  word += (word >> 4);

  return word & 15;
}


/* get arguments from the command line 
   -this is a throw away
*/
unsigned char cheezy_getopt(int argc, char *argv[])
{
  unsigned char tmpC;
  switch(argc)
    {
    case 2:
      //check that we're within range
      if( (tmpC = strtol(argv[1],NULL, 10)) < 256)
	{
	  //return the number
	  return(tmpC);
	}
      break;
    default:
      //nothing here -just go below
      break;
    }

      printf("usage: program_name number (where number is <= 255)\n");

      //default to running the program using a 0 for input
      return 0;
}
