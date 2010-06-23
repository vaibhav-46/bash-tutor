def parser(x):
    from BeautifulSoup import BeautifulSoup
    import re
    f=open('/home/vaibhav/final/'+str(x)+'txt','r+')
    f1=open('/home/vaibhav/final/temp.t',"r+")
    doc=f.readlines()
    soup=BeautifulSoup(''.join(doc))
    soup.prettify()
    for mysame in soup.findAll("red"):
        p=len(mysame)                                                               #This command helps us know whether there are tags within the tag
        print p
        if p==3:
            mysame.contents[0].replaceWith("\033[0;31;40m"+mysame.contents[0])                                              #contents[0] contains data before the inserted tag,contents[1] contains the whole next
            mysame.contents[2].replaceWith(mysame.contents[2]+fu(mysame.parent.name))                               #tag,contents[2]  contains the part after the inserted tags
        elif p==1:
            mysame.contents[0].replaceWith("\033[0;31;40m"+mysame.contents[0]+fu(mysame.parent.name))    #parent gives the tag just before the given tag this way we remember the previous tag
    for mysame in soup.findAll("green"):
        p=len(mysame)
        print p
        print mysame.parent.name
        if p==3:
            mysame.contents[0].replaceWith("\033[0;32;40m"+mysame.contents[0])
            mysame.contents[2].replaceWith(mysame.contents[2]+fu(mysame.parent.name))                                   #fu is a func that reads the parent name and returns the tag for the given colour
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
                                       
        

    
