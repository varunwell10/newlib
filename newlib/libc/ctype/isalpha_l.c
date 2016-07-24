/*
FUNCTION
	<<isalpha_l>>---alphabetic character predicate

INDEX
	isalpha_l

ANSI_SYNOPSIS
	#include <ctype.h>
	int isalpha_l(int <[c]>, locale_t <[locale]>);

DESCRIPTION
<<isalpha_l>> is a macro which classifies ASCII integer values by table
lookup in locale <[locale]>.  It is a predicate returning non-zero when
<[c]> represents an alphabetic ASCII character, and 0 otherwise.  It is
defined only if <[c]> is representable as an unsigned char or if <[c]> is EOF.

if <[locale]> is LC_GLOBAL_LOCALE or not a valid locale object, the behaviour
is undefined.

You can use a compiled subroutine instead of the macro definition by
undefining the macro using `<<#undef isalpha_l>>'.

RETURNS
<<isalpha_l>> returns non-zero if <[c]> is a letter (<<A>>--<<Z>> or
<<a>>--<<z>>).

PORTABILITY
<<isalpha_l>> is POSIX-1.2008.

No supporting OS subroutines are required.
*/

#include <_ansi.h>
#include <ctype.h>

#undef isalpha_l

int
isalpha_l (int c, struct __locale_t *locale)
{
  return __locale_ctype_ptr_l (locale)[c+1] & (_U|_L);
}
