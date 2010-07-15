def parser(x,NAME):
    """Parse a file and print it in colour in bash"""

    from BeautifulSoup import BeautifulSoup
    import re

    f=open(NAME+'/'+str(x)+'.txt','r+')
    f1=open(NAME+'/temp.txt',"w+")

    doc=f.readlines()
    soup=BeautifulSoup(''.join(doc))
    soup.prettify()

    maincolor={							#dictionary with the colours and their tags
	"red":"\033[0;31m",
	"green":"\033[0;32m",
 	"brown":"\033[0;33m",
	"blue":"\033[0;34m",
	"magenta":"\033[0;35m",
	"cyan":"\033[0;36m",
	"white":"\033[0;37m",
	"[document]":""
	}

    for colour in maincolor.keys():
        for mysame in soup.findAll(colour):
            p=len(mysame)
            if p>=3:
                mysame.contents[0].replaceWith(maincolor[colour]+mysame.contents[0])
                mysame.contents[p-1].replaceWith(mysame.contents[p-1]+maincolor[mysame.parent.name])                                   
            elif p==1:
                mysame.contents[0].replaceWith(maincolor[colour]+mysame.contents[0]+maincolor[mysame.parent.name])
    f1.write(soup.renderContents())
 
if __name__=="__main__":
	import sys
	parser(int(sys.argv[1]),str(sys.argv[2])) 
    
