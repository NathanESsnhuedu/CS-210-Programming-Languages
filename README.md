# CS-210-Programming-Languages
# Nathan E. Schmidt

# This program was designed for the user to choose to do three things. 
# 1. Recieve a text file, input the items listed, count how many times each item is listed in the file, and print the list of items with their frequency of appearance in the file
# 2. Input a specific item name from user, receive a text file, input the items listed, count how many times the user-specified item appears, print to user the item name and frequency of appearance.
# 3. Receive a text file, input the items listed, count how many times each item is listed in the file, write a new file storing this information, print information replacing the frequency number with a symbol printed as many times as the value of frequency. 

# The validation of input with the input for choice I believe was done fairly throughly. The integration of code between Python and C++ was also done sufficiently I believe. 

# The only mistake I can spot with the code so far is that when using the third option, I notice that the last item is printed twice. 
# I wonder if is because a while loop keeps continuing until there is nothing left in the written file, but the loop that wrote it had ended the file with an extra new line. 
# While I imagine there is a simple solution to this, I couldn't think of a clever way to resolve this issue. 

# The most challenging part of this project for me was the integration of both languages. 
# The functions in the C++ code designed to call Python functions were prewritten for me in this school project. 
# Part of the proccess of integreating languages are still complicated evade my understanding, but I could utilize them effectively to do what was necessary. 
# Checking a file for existance in Python was more difficult than expected, because of a syntax error that was difficult to spot as it didn't display in visual studio as such. 
# I had originally believed that the program wasn't opening the file as I had written it. 
# After testing with print statements throughout the problem area, I found it was opening, just not looping through my code within it. 
# I was able to investigate the issues and solve from there. 

# I've learned how to use integreated languages to read basic items names and information from a text file and write new information onto a new text file. 

# To make this program maintainable, readable, and adaptable, I've written comments throughout the code to help other see and understand how I've written the code. 
