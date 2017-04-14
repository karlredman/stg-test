/* Program that demonstrates a solution the the problem below

   3. Given the partial definition for the "Thing" class below, there is a
   problem with the code in main().  Can you identify and explain the
   problem and propose a solution?

        #define NULL 0    // this is the standard definition of NULL
 
        class Thing {
 
        public:
            Thing();
            Thing(char *);
            Thing(char);
 
            // ...
 
        };
 
        Thing::Thing()
        {
            // ...
        }
 
        Thing::Thing(char *p)
        {
            // ...
        }
 
        Thing::Thing(char c)
        {
            // ...
        }
 
        int
        main(int argc, char *argv[])
        {
            Thing thing1(NULL);
            Thing thing2("hi there");
 
            // ...
 
            return 0;
        }
*/

#include <stdio.h>

int main()
{
  printf("please see the comments in the code 3.c\n");

  /*
    The problem with the main() function above is that
    thing1 is declared with NULL. The definition of 
    Thing::Thing(char *p) and Thing::Thing(char c) could 
    be changed to accomidate a NULL and we should type cast
    the declaration of thing1 to specify which Thing we're 
    dealing with here.  

    Personally, I would try both:

    Thing::Thing(char *p)
    {
	if(p == NULL)
	{
		//maybe declare some memory (malloc or an object)
	}

	// ...
    }

    Thing::Thing(char c)
    {
	if(c == NULL)
	{
		//something happens here
	}

	// ...
    }
  
    main(int argc, char *argv[])
    {
	Thing thing1((char)NULL);

	// OR

	// Thing thing1((char *)NULL);

	Thing thing2("hi there");
    }

  */
}
