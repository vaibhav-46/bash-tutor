def main():
    from BeautifulSoup import BeautifulSoup
    import re
    f=open('/home/vaibhav/temp.txt','r+')
    f1=open('/home/vaibhav/ch.t',"r+")
    doc=f.readlines()
    soup=BeautifulSoup(''.join(doc))
    soup.prettify()
    for mysame in soup.findAll("red"):
        p=len(mysame)
        print p
        if p==3:
            mysame.contents[0].replaceWith("\033[0;31;40m"+mysame.contents[0])
            mysame.contents[2].replaceWith(mysame.contents[2]+fu(mysame.parent.name))
        elif p==1:
            mysame.contents[0].replaceWith("\033[0;31;40m"+mysame.contents[0]+fu(mysame.parent.name))
    for mysame in soup.findAll("green"):
        p=len(mysame)
        print p
        print mysame.parent.name
        if p==3:
            mysame.contents[0].replaceWith("\033[0;32;40m"+mysame.contents[0])
            mysame.contents[2].replaceWith(mysame.contents[2]+fu(mysame.parent.name))
        elif p==1:
            mysame.contents[0].replaceWith("\033[0;32;40m"+mysame.contents[0]+fu(mysame.parent.name))
    for mysame in soup.findAll("brown"):
        p=len(mysame)
        print p
        if p==3:
            mysame.contents[0].replaceWith("\033[0;33;40m"+mysame.contents[0])
            mysame.contents[2].replaceWith(mysame.contents[2]+fu(mysame.parent.name))
        elif p==1:
            mysame.contents[0].replaceWith("\033[0;33;40m"+mysame.contents[0]+fu(mysame.parent.name))
    for mysame in soup.findAll("blue"):
        p=len(mysame)
        print p
        if p==3:
            mysame.contents[0].replaceWith("\033[0;34;40m"+mysame.contents[0])
            mysame.contents[2].replaceWith(mysame.contents[2]+fu(mysame.parent.name))
        elif p==1:
            mysame.contents[0].replaceWith("\033[0;34;40m"+mysame.contents[0]+fu(mysame.parent.name))
    for mysame in soup.findAll("magenta"):
        p=len(mysame)
        print p
        if p==3:
            mysame.contents[0].replaceWith("\033[0;35;40m"+mysame.contents[0])
            mysame.contents[2].replaceWith(mysame.contents[2]+fu(mysame.parent.name))
        elif p==1:
             mysame.contents[0].replaceWith("\033[0;35;40m"+mysame.contents[0]+fu(mysame.parent.name))
    
    for mysame in soup.findAll("cyan"):
        p=len(mysame)
        print p
        if p==3:
            mysame.contents[0].replaceWith("\033[0;36;40m"+mysame.contents[0])
            mysame.contents[2].replaceWith(mysame.contents[2]+fu(mysame.parent.name))
        elif p==1:
            mysame.contents[0].replaceWith("\033[0;36;40m"+mysame.contents[0]+fu(mysame.parent.name))
    for mysame in soup.findAll("white"):
        p=len(mysame)
        print p
        if p==3:
            mysame.contents[0].replaceWith("\033[0;37;40m"+mysame.contents[0])
            mysame.contents[2].replaceWith(mysame.contents[2]+fu(mysame.parent.name))
        elif p==1:
            mysame.contents[0].replaceWith("\033[0;37;40m"+mysame.contents[0]+fu(mysame.parent.name))            
    print soup.prettify()          
    f1.write(soup.prettify())        
    

def fu(st):
    if st=="red":
        return "\033[0;31;40m"
    elif st=="[document]":
        return " "
    elif st=="green":
        return "\033[0;32;40m"
    elif st=="brown":
        return "\033[0;33;40m"
    elif st=="blue":
        return "\033[0;34;40m"
    elif st=="magenta":
        return "\033[0;35;40m"
    elif st=="cyan":
        return "\033[0;36;40m"
    elif st=="white":
        return "\033[0;37;40m"
                                       
        

    
