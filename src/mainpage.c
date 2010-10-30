#include<stdio.h>
#include<string.h>
#include<panel.h>
#include<ncurses.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
    WINDOW *my_wins[5];
    PANEL *my_panels[5];
    PANEL *top;
    int length,win_x,win_y,win1_x,win1_y,row=2;
    int ch,i,column,value;
    size_t nbytes=9;
    char *ch2,*link;
    int temp_chnum;
    int bytes_read,temp;


    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);

    getmaxyx(stdscr,win_x,win_y);
    win1_x=win_x;
    win1_y=win_y;

    init_pair(1, COLOR_RED , COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_CYAN);
    init_pair(6, COLOR_WHITE, COLOR_BLUE);

    length=strlen("BASH TUTOR");


    /*Creating the first window that has the title*/
    my_wins[1]=newwin(win_x-4,2*length,1,win_y-2*length-1);
    wborder(my_wins[1],' ',' ',' ',' ',' ',' ',' ',' ');
    wattron(my_wins[1],A_BOLD);
    wattron(my_wins[1],A_UNDERLINE);
    wattron(my_wins[1],COLOR_PAIR(1));
    mvwprintw(my_wins[1],(win_x-4)/2,(length)/2,"BASH TUTOR");
    wattroff(my_wins[1],COLOR_PAIR(1));
    wattroff(my_wins[1],A_BOLD);
    wattroff(my_wins[1],A_UNDERLINE);

    /*Creating the open page border*/
    my_wins[2]=newwin(win_x-4,win_y-2*length-2,0,0);
    box(my_wins[2],0,0);

    /*Creating the text window*/
    my_wins[3]=newwin(win_x-6,win_y-2*length-6,1,2);
    wborder(my_wins[3],' ',' ',' ',' ',' ',' ',' ',' ');
    wattron(my_wins[3],COLOR_PAIR(3));
    wattron(my_wins[3],A_BOLD);
    mvwprintw(my_wins[3],3,(win_y-2*length-21)/2,"Hello Everybody\n");
    wattroff(my_wins[3],COLOR_PAIR(3));
    wattroff(my_wins[3],A_BOLD);
    wattron(my_wins[3],COLOR_PAIR(2));
    wprintw(my_wins[3],"\tThis application has been made with the very simple idea that the most feared thing for a linux newbie is *the* terminal.The main  reason that terminal is feared by a new user is his ignorance of the various commands.But once you get used to the commands in the terminal you will find that the terminal is a very useful tool and it helps a regular user use the computer more effectively.\n\n\n");
    wprintw(my_wins[3],"\tThis tutorial is meant to help you understand various commands that you might use in the course of using the terminal.Once you are used to these commands it will become a lot easier for you to be able to run the computer.Note that the main point to remember while studying this tutorial is to keep trying out the commands that are given in the tutorial.There are a lot of examples in this tutorial and it is very important that you do try them out and make sure that you understand what is going on.This way you will not only learn but have a lot of practice along the way.\n");
    wattroff(my_wins[3],COLOR_PAIR(3));
    refresh();



    /*Creating the Instructions Page*/
    my_wins[0]=newwin(win1_x-6,win1_y-2*length-6,1,2);
    wborder(my_wins[0],' ',' ',' ',' ',' ',' ',' ',' ');
    wattron(my_wins[0],COLOR_PAIR(2));
    wattron(my_wins[0],A_UNDERLINE);
    mvwprintw(my_wins[0],3,2,"Instructions:");
    wattroff(my_wins[0],A_UNDERLINE);
    mvwprintw(my_wins[0],5,2,"This application has been made with an idea of helping the user get accustomed to the terminal.\n");
    wprintw(my_wins[0]," The way to move around in this tutorial is:\n\n");
    wprintw(my_wins[0]," 1. Next Chapter:F3\n");
    wprintw(my_wins[0]," 2.Prev Chapter:F2\n");
    wprintw(my_wins[0]," 3.To goto a specific chapter type in g<number>:For example to goto 12th chapter press g12\n");
    wprintw(my_wins[0]," 4.To resume: F4\n");
    wprintw(my_wins[0]," 5.To see the list of contents: F6(to be done)\n");
    wprintw(my_wins[0]," 6.If at any instant the tutorial does not work you can always fall back on the default of pressing next or prev after q\n");
    wprintw(my_wins[0]," 7.To exit the tutorial press Ctrl+a followed by \\ and y\n\n\n");
    wattron(my_wins[0],A_BOLD);
    mvwprintw(my_wins[0],18,2,"So what are you waiting for press F2 and get started");
    wattroff(my_wins[0],A_BOLD);
    wattroff(my_wins[0],COLOR_PAIR(2));
    refresh();

    my_wins[4]=newwin(win_x-6,win_y-2*length-6 ,1, 2);
    wborder(my_wins[4],' ',' ',' ',' ',' ',' ',' ',' ');

    wattron(my_wins[4],COLOR_PAIR(6));
    mvwhline (my_wins[4],1,0,'=',win_y-2*length-8);
    mvwprintw (my_wins[4],1, (win_y-2*length-8)/2-10, "INDEX" );
    mvwhline (my_wins[4],2, 1,' ',win_y-2*length-10);
    mvwprintw (my_wins[4],2, 5, "A small list of the commands : ");
    wattron(my_wins[4],COLOR_PAIR(5));
    mvwhline (my_wins[4],3, 0,' ',win_y-2*length-8);
    mvwprintw (my_wins[4],3,(win_y-2*length-10)/4 , "Commands");
    mvwprintw (my_wins[4],3, 2, "No.");
    mvwvline (my_wins[4],2,0,'|',win_x-4);
    mvwvline (my_wins[4],3,6,'|',win_x-3);
	mvwprintw (my_wins[4],3,(win_y-2*length-10)/2+2,"No.");
	mvwprintw(my_wins[4],3,3*(win_y-2*length-10)/4,"Commands");
    mvwvline (my_wins[4],3,(win_y-2*length-10)/2,'|',win_x-3);
	mvwvline (my_wins[4],3,(win_y-2*length+2)/2,'|',win_x-3);
	mvwvline (my_wins[4],2,(win_y-2*length-9),'|',win_x-2);
    mvwhline (my_wins[4],win_x-7,0,'=',win_y-2*length-8);
    wattroff(my_wins[4],COLOR_PAIR(4));
    wattron(my_wins[4],COLOR_PAIR(2));

    mvwprintw(my_wins[4],5,3,"1");
    mvwprintw(my_wins[4],5,8,"Help Sources");
    mvwprintw(my_wins[4],6,3,"2");
    mvwprintw(my_wins[4],6,8,"ls and cd ");
    mvwprintw(my_wins[4],7,3,"3");
    mvwprintw(my_wins[4],7,8,"Directory related commands");
    mvwprintw(my_wins[4],8,3,"4");
    mvwprintw(my_wins[4],8,8,"Copy,Paste,Delete for terminal");
    mvwprintw(my_wins[4],9,3,"5");
    mvwprintw(my_wins[4],9,8,"Cat and Echo commands");
    mvwprintw(my_wins[4],10,3,"6");
    mvwprintw(my_wins[4],10,8,"Mount");
    mvwprintw(my_wins[4],11,3,"7");
    mvwprintw(my_wins[4],11,8,"Input and Output redirections");
    mvwprintw(my_wins[4],12,3,"8");
    mvwprintw(my_wins[4],12,8,"Filters");
    mvwprintw(my_wins[4],13,3,"9");
    mvwprintw(my_wins[4],13,8,"basename,rename,dirname etc.");
    mvwprintw(my_wins[4],14,3,"10");
    mvwprintw(my_wins[4],14,8,"Regular expressions");
	mvwprintw(my_wins[4],15,3,"11");
    mvwprintw(my_wins[4],15,8,"Grep");
    mvwprintw(my_wins[4],16,3,"12");
    mvwprintw(my_wins[4],17,8,"Stream Editor(SED)");
    mvwprintw(my_wins[4],17,3,"13");
    mvwprintw(my_wins[4],17,8,"AWK-The Programming Language");
    mvwprintw(my_wins[4],18,3,"14");
    mvwprintw(my_wins[4],18,8,"Archieve file operation");
    mvwprintw(my_wins[4],19,3,"15");
    mvwprintw(my_wins[4],19,8,"Various Processes");
    mvwprintw(my_wins[4],5,(win_y-2*length-10)/2+2,"16");
    mvwprintw(my_wins[4],5,(win_y-2*length-10)/2+8,"du and Ownership commands");
    mvwprintw(my_wins[4],6,(win_y-2*length-10)/2+2,"17");
    mvwprintw(my_wins[4],6,(win_y-2*length-10)/2+8,"Apt commands");
    mvwprintw(my_wins[4],7,(win_y-2*length-10)/2+2,"18");
    mvwprintw(my_wins[4],7,(win_y-2*length-10)/2+8,"Info on text editors");
    mvwprintw(my_wins[4],8,(win_y-2*length-10)/2+2,"19");
    mvwprintw(my_wins[4],8,(win_y-2*length-10)/2+8,"Date,id and bashrc introduction");
    mvwprintw(my_wins[4],9,(win_y-2*length-10)/2+2,"20");
    mvwprintw(my_wins[4],9,(win_y-2*length-10)/2+8,"Path,alias,dircolors and sleep");
    mvwprintw(my_wins[4],10,(win_y-2*length-10)/2+2,"21");
    mvwprintw(my_wins[4],10,(win_y-2*length-10)/2+8,"Crontab");
    mvwprintw(my_wins[4],11,(win_y-2*length-10)/2+2,"22");
    mvwprintw(my_wins[4],11,(win_y-2*length-10)/2+8,"Alsamixer Output redirections");
    mvwprintw(my_wins[4],12,(win_y-2*length-10)/2+2,"23");
    mvwprintw(my_wins[4],12,(win_y-2*length-10)/2+8,"Diff and patch");
    mvwprintw(my_wins[4],13,(win_y-2*length-10)/2+2,"24");
    mvwprintw(my_wins[4],13,(win_y-2*length-10)/2+8,"Speeding up process nice,renice");
    mvwprintw(my_wins[4],14,(win_y-2*length-10)/2+2,"25");
    mvwprintw(my_wins[4],14,(win_y-2*length-10)/2+8,"Important Bash files");
	mvwprintw(my_wins[4],15,(win_y-2*length-10)/2+2,"26");
    mvwprintw(my_wins[4],15,(win_y-2*length-10)/2+8,"Bashrc file introduction");
    mvwprintw(my_wins[4],16,(win_y-2*length-10)/2+2,"27");
    mvwprintw(my_wins[4],16,(win_y-2*length-10)/2+8,"Various Shells");
    mvwprintw(my_wins[4],17,(win_y-2*length-10)/2+2,"28");
    mvwprintw(my_wins[4],17,(win_y-2*length-10)/2+8,"Bang introduction");
    mvwprintw(my_wins[4],18,(win_y-2*length-10)/2+2,"29");
    mvwprintw(my_wins[4],18,(win_y-2*length-10)/2+8,"Variables usage in bash");
    mvwprintw(my_wins[4],19,(win_y-2*length-10)/2+2,"30");
    mvwprintw(my_wins[4],19,(win_y-2*length-10)/2+8,"Quoting in programs");
	
	wattroff(my_wins[4],COLOR_PAIR(5));
    wattroff(my_wins[4],COLOR_PAIR(6));



    /*Defining the panels*/
    my_panels[0]=new_panel(my_wins[0]);
    my_panels[1]=new_panel(my_wins[1]);
    my_panels[2]=new_panel(my_wins[2]);
    my_panels[3]=new_panel(my_wins[3]);
    my_panels[4]=new_panel(my_wins[4]);

    /*Setting pointers for Tab usage*/
    set_panel_userptr(my_panels[3],my_panels[0]);
    set_panel_userptr(my_panels[0],my_panels[3]);
    set_panel_userptr(my_panels[4],my_panels[3]);

    update_panels();

    /*End statements for instructions*/
    attron(COLOR_PAIR(4));
    mvprintw(win_x-3,0,"1.Press tab to see the instructions");
    mvprintw(win_x-2,0,"2.To start press F2 or to resume the previous chapter press F4");
    mvprintw(win_x-1,0,"3.To see the list of content of chapters press F6");
    attroff(COLOR_PAIR(4));
    refresh();
    doupdate();

    /*While loop to use tab*/
    top=my_panels[3];
    top_panel(top);
    update_panels();
    doupdate();

    while((ch=getch())!=KEY_F(2))
    {
        switch(ch)
        {
        case 9:
            top=(PANEL *) panel_userptr(top);
            top_panel(top);
            attron(COLOR_PAIR(4));
            mvprintw(win_x-3,0,"1.Press tab to see the instructions");
            mvprintw(win_x-2,0,"2.To start press F2 or to resume the previous chapter press F4");
            mvprintw(win_x-1,0,"3.To see the list of content of chapters press F6");
            attroff(COLOR_PAIR(4));
            refresh();
            break;


        case KEY_F(4):
            endwin();
            system("screen -c ../browser/screenrc bash bashtutor.sh `cat ../chapters/chapter.txt`");
            return 0;

        case KEY_F(6):
            top=my_panels[4];
            top_panel(top);
            update_panels();
            doupdate();
            attron(COLOR_PAIR(4));
            mvprintw(win_x-3,0,"1.Press tab followed by enter to see the welcome page again");
            mvprintw(win_x-2,0,"2.To start press F2 or to resume the previous chapter press F4");
            mvprintw(win_x-1,0,"3.Press number followed by enter to go to chapter");
            attroff(COLOR_PAIR(4));
            refresh();
            ch2 = (char*) malloc (sizeof(char)*25);
            scanw("%s",ch2);
            sscanf(ch2,"%d",&temp_chnum);
            if((*ch2)!='9')
            {
                if(temp_chnum<=32)
                {
                    endwin();
                    link = (char*)malloc(sizeof(char)*100);
                    sprintf(link,"screen -c ../browser/screenrc bash ../browser/bashtutor.sh %d", temp_chnum);
                    system(link);
                    return 0;
                }
            }

            {

                top=my_panels[3];
                top_panel(top);
                update_panels();
                doupdate();
                break;

            }
            break;



        }
        update_panels();
        doupdate();
    }
    endwin();
    system("screen -c ../browser/screenrc bash ../browser/bashstart.sh ");
    return 0;
}

