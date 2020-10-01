# ft_printf
**Problem:** At Hive Helsinki coding school students are not allowed to use the C library function *printf* !<br />
**Solution:** Code your own *printf* function!<br />
<br />
This is a simplified version of the C library function *printf* that can handle:<br />
* csp conversions<br />
* diouxX conversions with hh,h, l and ll length modifiers<br />
* f conversion with l and L length modifiers<br />
* e and g conversions<br />
* b (binary) conversion (non-existent in real printf)<br />
* %%<br />
* \#0-+<code />and space flags<br />
* minimum field width<br />
* precision<br />
<br />
## Usage
\#include "printf.h"<br />
<br />
int ft_printf(const char \*format, ...);<br />
<br />
Repository contains a Makefile for:<br /> 
* compiling executable (**make all**)<br />
* removing object files (**make clean**)<br />
* deleting executable (**make fclean**)<br />
* recompiling (**make re**)<br /><br />
