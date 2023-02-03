# Disk-Killer
Funny little C++ script that essentially fills up a hard drive with hidden and read-only text files. Linux and Windows version.

This program uses the mt19937 random number generator from the C++ Standard Library to generate random strings. The length of the strings and the characters used in the strings are defined as constants in the beginning of the program. The randomString function generates a random string of the specified length. The main function generates 100 text files with random names (e.g. "file0.txt", "file1.txt", ...) and random contents. The contents of each file are the result of calling the randomString function.

Note that this program will run indefinitely and generate an infinite number of text files until it is stopped manually. The fileCount variable is used to keep track of the number of files generated, and its value is incremented after each file is generated. The program uses an infinite while loop to generate text files repeatedly, with each iteration creating a new text file with a unique nam

For safety reasons, there is a line of code:

const int FILE_COUNT = 1;

It is set to create ONE single file. To make a live file with unlimited files, just remove that line of code.

WINDOWS VERSION
===============

In this version of the program, the SetFileAttributes function from the Windows.h library is used to set the file attributes to both FILE_ATTRIBUTE_HIDDEN and FILE_ATTRIBUTE_READONLY, which makes the files hidden and read-only in Windows. The names of the files are changed to start with a dot (.), which makes them hidden files in Windows as well.

You need to compile and run this program in a Windows environment to generate the text files.
