def parser(x):
    from BeautifulSoup import BeautifulSoup
    import re
    f1=open(str(x)+'.txt',"r+")
    f=open("temp.txt","w+")
    doc=f1.readlines()
    soup=BeautifulSoup(''.join(doc))
    for mysame in soup.findAll("red"):
        mysame.contents[0].replaceWith("\033[0;31;40m"+mysame.contents[0])
    for mysame in soup.findAll("green"):
        mysame.contents[0].replaceWith("\033[0;32;40m"+mysame.contents[0])
    for mysame in soup.findAll("brown"):
        mysame.contents[0].replaceWith("\033[0;33;40m"+mysame.contents[0])
    for mysame in soup.findAll("blue"):
        mysame.contents[0].replaceWith("\033[0;34;40m"+mysame.contents[0])
    for mysame in soup.findAll("magenta"):
        mysame.contents[0].replaceWith("\033[0;35;40m"+mysame.contents[0])
    for mysame in soup.findAll("cyan"):
        mysame.contents[0].replaceWith("\033[0;36;40m"+mysame.contents[0])
    f.write(soup.prettify())
    f.close
    f1.close

if __name__=="__main__":
	import sys
        parser(int(sys.argv[1])) 
