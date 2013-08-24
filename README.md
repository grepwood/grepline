What is this?
=============

Re-write of GNU getline, aiming for wide cross-platform implementation.
It has been written from scratch, being based on observed behavior of getline.

Difference
==========

getline is licensed under GPL and its return type is a signed integer.

grepline is licensed under BSD and its return type is an unsigned integer.

Why use it?
===========

Both functions give a return value that is the length of the line that has been read. Because of grepline's different return type, this value is less likely to overflow, and will never compute a line length that is a negative integer.

Besides that, grepline can be compiled for and used on a wider variety of systems than getline.
