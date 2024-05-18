stringstream
A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin).
​
GETLINE
getline(istream& is, string& str, char delim);
is: It is an object of istream class and tells the function about the stream from where to read the input from.
str: It is a string object, the input is stored in this object after being read from the stream.
delim: It is the delimitation character which tells the function to stop reading further input after reaching this character.