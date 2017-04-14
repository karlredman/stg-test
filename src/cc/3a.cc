/* 3a.c
   Class definitions for Thing
*/
 
#include <string.h>
#include "3a.h"

Thing::Thing()
  :  thing_string(NULL),
     thing_char((char)NULL),
     thing_type(THING)
{
  //do something maybe.
}

Thing::Thing(char *p)
  : thing_string(NULL),
    thing_char((char)NULL),
    thing_type(THING_STRING)
{
  //if we got a NULL than just initialize.
  if(p == NULL)
    return;

  //allocate some memory
  thing_string = new char[strlen(p)+1];

  if(thing_string != NULL)
    {
      //save p data
      strcpy(thing_string, p);
    }
}

Thing::Thing(char c)
  : thing_string(NULL),
    thing_char((char)NULL),
    thing_type(THING_CHAR)
{
  if(c == (char)NULL)
    {
      //we thing c should be zero
      c = 0;
    }
  // ...
}

Thing::~Thing()
{
  if(thing_string != NULL)
    {
      //dealocate memory
      delete [] thing_string;
    }
}

char *
Thing::get_thing_string()
{
  return thing_string;
}

char 
Thing::get_thing_char()
{
  return thing_char;
}

char 
Thing::set_thing_char(char c)
{
  return thing_char = c;
}

char *
Thing::set_thing_string(char *s)
{
  //if we got a NULL just return null,
  //  do nothing.
  if(s == NULL)
    {
      return NULL;
    }

  if(thing_string != NULL)
    {
      delete [] thing_string;
      thing_string = NULL;
    }

  thing_string = new char[strlen(s)+1];

  if(thing_string != NULL)
    {
      strcpy(thing_string, s);
    }

  return thing_string;
}

const int
Thing::get_thing_type()
{
  return thing_type;
}
