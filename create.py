def parser(x,NAME,width):
    from BeautifulSoup import BeautifulSoup
    import re
    from termcolor import colored
    

    def color(present):
        p1=len(present)
        j=0
        if p1==1:
                print  colored (wrap(present.contents[j],width),present.name),
        elif p1>1:
            while j<p1:
                if j%2==0:
                    print colored(wrap(present.contents[j],width),present.name),
                elif j%2==1:
                    color(present.contents[j])
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
    
    f=open(NAME+'/'+str(x)+'.txt','r+') 
   
    doc=f.readlines()
    soup=BeautifulSoup(''.join(doc))
    soup.prettify()
    for tag in soup.start.findAll(recursive=False):
       color(tag)
                   
                        
if __name__=="__main__":
	import sys
	parser(int(sys.argv[1]),str(sys.argv[2]),int(sys.argv[3]))

                   
