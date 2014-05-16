What is this?
=============

Re-write of GNU getline, aiming for wide cross-platform implementation.
It has been written from scratch, being based on observed behavior of GNU getline.
It is important to notice that this function is not Windows getline and it has a different call syntax.

Difference
==========

getline is licensed under GPL and its return type is a signed integer.
grepline is licensed under BSD and its return type is an unsigned integer.
This means that grepline can be used even in proprietary projects for as long as its use conforms with the BSD license, which pretty much means "give credit where it's due and that's all".

Why use it?
===========

* Both functions give a return value that is the length of the line that has been read. Because of grepline's different return type, this value is less likely to overflow, and will never compute a line length that is a negative integer.
* grepline can actually read lines of files written on old Macintosh computers (pre OS9), whereas GNU getline would treat all such lines as one line
* GNU getline would return -1 if we have reached end of file. In grepline, this will cause a return of 1 because I believe it's not meant for indicating whether we've reached end of file. There is a function for that already.
* grepline can be compiled for and used on a wider variety of systems than getline because it's written in standard C.
