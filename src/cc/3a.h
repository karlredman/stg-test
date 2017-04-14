/* 3a.h
Program that demonstrates a solution the the problem below
*/

#ifndef __3a_H

/* definitions of the kind of 
   things we have
*/
#define THING		0
#define THING_CHAR	1
#define THING_STRING	2

/* some systems allow you to 
   define NULL. More importantly
   you are not garanteed that NULL 
   will always be ZERO. 
*/ 
#ifndef NULL
	#define NULL 0
#endif

class Thing {

public:
  Thing();
  Thing(char *);
  Thing(char);

  ~Thing();

  char *get_thing_string();	/* return the string */

  char get_thing_char();	/* return the char */

  char *set_thing_string(char *); /* set the string. A NULL argument
				     does nothing and returns NULL
				  */
  
  char set_thing_char(char);	/* set the char */

  const int get_thing_type();	/* return the type of thing */
  
private:
  char *thing_string;
  char thing_char;
  const int thing_type;
};

#endif
