def new():
    f=open("temp.txt","r+")
    f2=open("/home/vaibhav/final/out.txt","a+")
    for line in f:
        sys=line+"\\n"
        f2.write(sys)
       
        
if __name__ == "__main__":
    import sys
    new()

        
