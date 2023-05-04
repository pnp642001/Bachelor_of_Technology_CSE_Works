#CS 346 -> CRNS
#PRACTICAL-3
#NAME: PARTH N PATEL
#ID: 19DCS098

#ALGORITHM NAME: RAIL FENCE CIPHER

#ENCRYPTION FUNCTION
#TWO PARAMETERS: PLAIN_TEXT AND KEY WHICH IS DEFAULT PARAMETER
#THE KEY=3 BECAUSE MENTIONED IN THE QUESTION TO TAKE ROW=3
#TO AVOID CONFUSION I TOOK KEY AS THIS ALGORITHM IS ALSO OF 2 TYPES: 
#                       1. KEY 2. KEYLESS


def encryption(plain_Text, key=3):
 
 #MATRIX WHERE WE WILL STORE THE LETTERS OF THE MESSAGE
    rail_Matrix = [['\n' for i in range(len(plain_Text))]
                  for j in range(key)]
     
# DIRECTION VARIABLE TO DETERMINE THE DIRECTION OF THE FLOW
    direction = False
    row=0
    column = 0
     
    #MAIN LOGIC
    for i in range(len(plain_Text)):
         
        # FIRST, CHECK THE DIRECTION OF THE FLOW
        #IF WE HAVE FILLED THE TOP/BOTTOM ELEMENT OF THE COLUMN
        #THEN, CHANGE THE DIRECTION
        if (row == 0) or (row == key - 1):
            direction = not direction
         
        #FILL THE ALPHABET ON THE LOCATION
        rail_Matrix[row][column] = plain_Text[i]
        column += 1
         
        #WE WILL ALSO USE DIRECTION TO FIND THE NEXT ROW:
        #IF DIRECTION == TRUE, ROW IS INCREMENTED
        #ELSE ROW IS DECREMENTED.
        if direction:
            row += 1
        else:
            row -= 1
    # ONCE THE MATRIX IS READY, WE CAN FIND THE CIPHER TEXT.
    result = []
    for i in range(key):
        for j in range(len(plain_Text)):
            if rail_Matrix[i][j] != '\n':
                result.append(rail_Matrix[i][j])
    return("" . join(result))
     
# CIPHER TEXT IS RETURNED IN THE FORM OF STRING

#DECRYPTION FUNCTION
def decryption(cipher_Text, key=3):
 
    #AGAIN, WE WILL CREATE THE CIPHER MATRIX FOR THE DECRYPTION PROCESS
    rail_Matrix = [['\n' for i in range(len(cipher_Text))]
                  for j in range(key)]
     
    
    direction = None
    row=0
    column = 0
     
    # MARK THE PLACES WITH '#'
    for i in range(len(cipher_Text)):
        if row == 0:
            direction = True
        if row == key - 1:
            direction = False
         
        #PLACING THE MARKER
        rail_Matrix[row][column] = '#'
        column += 1
         
        # FINDING THE NEXT ROW USING DIRECTION
        if direction:
            row += 1
        else:
            row -= 1
             
    # FILL THE CIPHER MATRIX
    index = 0
    for i in range(key):
        for j in range(len(cipher_Text)):
            if ((rail_Matrix[i][j] == '#') and
               (index < len(cipher_Text))):
                rail_Matrix[i][j] = cipher_Text[index]
                index += 1
         
    # THE READING THE MATRIX IN ZIG-ZAG MANNER TO GET THE PLAIN_TEXT
    result = []
    row, column = 0, 0
    for i in range(len(cipher_Text)):
         
        # SAME DIRECTION RULES AS ENCRYPTION
        if row == 0:
            direction = True
        if row == key-1:
            direction = False
             
        # PLACING THE MARKER
        if (rail_Matrix[row][column] != '#'):
            result.append(rail_Matrix[row][column])
            column += 1
             
        # FINDING THE NEXT ROW
        if direction:
            row += 1
        else:
            row -= 1
    return("".join(result))
 
 
plain_Text=input("Enter the plain Text: ")
plain_Text=plain_Text.replace(" ","")
cipher_Text=encryption(plain_Text)

print("The cipher text after Encryption : "+cipher_Text)
print("\nThe decrypted Text: "+decryption(cipher_Text))

print("\nPARTH PATEL\n19DCS098")


