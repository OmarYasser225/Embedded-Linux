# Calender 

import calendar
from termcolor  import colored

year  = int (input ("Input the year : "))
m = int(input ("Input the month : "))
print (colored( calendar.month(year, m),'red'))    

