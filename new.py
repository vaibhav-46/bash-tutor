def new(NAME):
    f=open(NAME+"/temp.txt","r+")
    f2=open(NAME+"/out.txt","a+")
    for line in f:
        sys=line+"\\n"
        f2.write(sys)
       
        
if __name__ == "__main__":
    import sys
    new(str(sys.argv[1]))

        
