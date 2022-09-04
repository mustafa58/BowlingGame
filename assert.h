//
// Created by mustafa58 on 16.08.2022.
//

#ifndef _ASSERT_H
#define _ASSERT_H
//Global definitions
static unsigned int __FAIL__ = 0;
static unsigned int __PASS__ = 0;

/* assert.h standard header */
//#undef assert	/* remove existing definition */

#ifdef NDEBUG
#define assert(test)	((void)0)
#else			/* NDEBUG not defined */
void _Assert(const char *, const char *, char *);
void _Assert_Equals(const char*, const char*, int, int);
void _Report(int, int);
/* macros */
#define _STR(x)	_VAL(x)
#define _VAL(x)	#x

#define assert(test)	((test) ? ({ ++__PASS__, (void)0; }) : \
        ({++__FAIL__, _Assert(__FILE__ ":" _STR(__LINE__), __func__, #test);}) )
#define assertEquals(test, res)  ((test) == (res) ? ({++__PASS__, (void)0;}) : \
        ({++__FAIL__, _Assert_Equals(__FILE__ ":" _STR(__LINE__), __func__, test, res);}) )
#endif

#endif //_ASSERT_H
