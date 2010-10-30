from BeautifulSoup import BeautifulSoup
import re
from termcolor import colored
    
def color(present,pf):
        p1=len(present)
        j=0
        if p1==1:
                pf.write(colored(present.contents[j],present.name))

        elif p1>1:
            while j<p1:
                if j%2==0:
                    pf.write(colored(present.contents[j],present.name))
                elif j%2==1:
                    color(present.contents[j],pf)
                j=j+1

                
def wrap(text,width):
           return reduce(lambda line, word, width=width: '%s%s%s' %
                  (line,
                   ' \n'[(len(line)-line.rfind('\n')-1
                         + len(word.split('\n',1)[0]
                              ) >= width)],
                   word),
                  text.split(' ')
                 )
    

def parser(x,NAME,size):

    temp=open(NAME+'/temp.txt','r+')     
    f=open(NAME+'/'+str(x)+'.txt','r+') 
    out=open(NAME+'/out.txt','r+')
    doc=f.readlines()
    soup=BeautifulSoup(''.join(doc))
    soup.prettify()
    for tag in soup.start.findAll(recursive=False):
        if tag.name=="title":
                name=len(tag.contents[0])
                for i in range(1,(size-name)/2):
                        temp.write(" "),
                temp.write(colored(tag.contents[0],'cyan'))
        else:
                color(tag,temp)
    temp.close()
    final=open(NAME+'/temp.txt','r+')
    for line in final:
       out.write(wrap(line,size))
                           
                        
if __name__=="__main__":
	import sys
	parser(int(sys.argv[1]),str(sys.argv[2]),int(sys.argv[3]))

                   
