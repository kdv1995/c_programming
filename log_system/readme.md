Log System

Build a logger that writes timestamps and messages into a log file each time an event occurs.
//What kind of events should be logged?
//Examples include user actions, system errors, or application status updates.

time()	Returns the current calendar time as a time_t value (seconds since Jan 1, 1970)
localtime()	Converts a time_t value to local time and returns a pointer to a struct tm
gmtime()	Converts a time_t value to UTC time (also as a struct tm)
ctime()	Converts a time_t value into a readable string (e.g. Thu Jun 26 10:30:00 2025)
asctime()	Converts a struct tm to a string in a standard date/time format
strftime()	Formats a struct tm into a custom date and time string
difftime()	Calculates the difference (in seconds) between two time_t values
mktime()	Converts a filled struct tm into a time_t value
clock()	Returns the number of processor clock ticks used by the program (can be used to measure execution time)
