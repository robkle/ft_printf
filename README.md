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
* #, 0, -, +,  and space flags<br />
* minimum field width<br />
* precision<br />
