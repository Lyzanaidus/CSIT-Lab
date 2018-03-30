i=0;
value_keys=dict();
for x in range(97,122+1):
    value_keys.update({chr(x):i});
    i=i+1;
def encipher(string,key):
    cipertext="";
    for value in string.lower():
        if(value==' '):
            cipertext=cipertext+' ';
        else:
            cal=(key+value_keys[value])%26;
            index="";
            for a,b in enumerate(value_keys):
                if(cal==a):
                    index=b;
                    break;
            cipertext=cipertext+index;
    return cipertext.upper();
def decipher(string,key):
    plaintext="";
    for value in string.lower():
        if(value==' '):
            plaintext=plaintext+' ';
        else:
            cal=(value_keys[value]-key)%26;
            index="";
            for a,b in enumerate(value_keys):
                if(cal==a):
                    index=b;
                    break;
            plaintext=plaintext+index;
    return plaintext.lower();
def printnow():
    print("Enter 1 for encrption!");
    print("Enter 2 for decrption!");
    print("Enter 3 to exit the program!");
while(True):
    printnow();
    ch=int(input("Choosed Item is : "));
    if(ch==1):
        string=str(input("Enter the string(a-z) to encrpt: "));
        keys=int(input("Enter the key value to encrypt(must be in integer) : "));
        print("Encrpted Message is : "+encipher(string,keys));
    elif(ch==2):
        string=str(input("Enter the string(A-Z to decrpt: "));
        keys=int(input("Enter the key value to decrypt(must be in integer) :"));
        print("Decrpted Message is : "+decipher(string,keys));
    else:
        print("sucessfully Exited");
        break;
