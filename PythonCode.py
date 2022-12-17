import re
import os
import string


def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v


def ListPurchases():
    # Some comments in this and other functions were commands that were used for testing...
    # CREATE variables to store values found in file
    products = {}
    product = "none"
    line = "none"
    #isExist = False
    #print("Checking if file exists...")
    #isExist = os.path.isfile("U:\\Project Three CS-210 Corner Grocer\\Release\\PurchasesInput.txt")
    #print(isExist)
    #print("Opening file...")
    # OPEN file "PurchasesInput.txt" for reading
    with open("U:\\Project Three CS-210 Corner Grocer\\Release\\PurchasesInput.txt", "r") as f:
        #print("Reading file...")
        # LOOP WHILE content is found when reading file
        while True:
            # SET variable 'line' equal to line of text within file
            line = f.readline()
            # IF variable 'line' is empty, THEN
            if not line:
                # BREAK from loop
                break;
            # SET variable 'product' equal to 'line' without the whitespace or newline
            product = line.strip()
            # IF 'product' is found in the keys for dictionary 'products', THEN
            if product in products.keys():
                # SET value of element from dictionary 'products' with key 'product' equal to itself plus one
                products[product] += 1
            # ELSE, THEN
            else:
                # SET value of element from dictionary 'products' with key 'product' equal to one
                products[product] = 1
    #print("Closing file...")
    #print(products)
    print("Products Purchased")
    # LOOP FOR each item in dictionary 'products' with key and value of each item
    for key, value in products.items():
        # PRINT item from 'products'
        print(key + ": " + str(value))
    print("All products in input file have been printed.")

def ItemFrequency(userItem):
    frequency = 0
    isExist = False
    #print("Checking if file exists...")
    #isExist = os.path.isfile("U:\\Project Three CS-210 Corner Grocer\\Release\\PurchasesInput.txt")
    #print(isExist)
    #print("Opening file...")
    with open("U:\\Project Three CS-210 Corner Grocer\\Release\\PurchasesInput.txt", "r") as f:
        #print("Reading file...")
        while True:
            line = f.readline()
            if not line:
                break;
            fileItem = line.strip()
            # IF item compared to in file is equal to item given from user, THEN
            if fileItem == userItem:
                # SET variable 'frequency' equal to itself plus one
                frequency = frequency + 1
    #print("Closing file...")
    return frequency

def readInputWriteNewFile():
    products = {}
    product = "Nothing"
    #isExist = False
    #print("Checking if file PurchasesInput.txt exists...")
    #isExist = os.path.isfile("U:\\Project Three CS-210 Corner Grocer\\Release\\PurchasesInput.txt")
    #print(isExist)
    #print("Opening file...")
    with open("U:\\Project Three CS-210 Corner Grocer\\Release\\PurchasesInput.txt", "r") as fileRead:
        #print("Reading file...")
        while True:
            line = fileRead.readline()
            if not line:
                break;
            product = line.strip()
            if product in products.keys():
                products[product] += 1
            else:
                products[product] = 1
    #print("Closing file...")
    #print(products)
    #print("Opening file frequency.dat")
    # OPEN file 'frequency.dat' creating a new file if it isn't found as object 'fileWrite'
    with open('frequency.dat', 'w+') as fileWrite:
        #print("Looping through products...")
        for key, value in products.items():
            #print("Writing a line")
            # WRITE item from dictionary 'products' onto file
            fileWrite.write(key + " " + str(value) + "\n")
            #print("wrote \"" + key + " " + str(value) + "\"")
    #print("Closing file...")
    fileWrite.close()