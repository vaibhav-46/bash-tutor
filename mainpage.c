#include<panel.h>
#include<ncurses.h>

main(int argc, char *argv[])
{
WINDOW *my_wins[3];
PANEL *my_panels[3];
PANEL *top;
int length,win_x,win_y,win1_x,win1_y,row=2;
int ch,i,column;

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
my_wins[3]=newwin(win_x-12,win_y-2*length-8,4,3);
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
my_wins[0]=newwin(win1_x-8,win1_y-2*length-6,2,2);
wborder(my_wins[0],' ',' ',' ',' ',' ',' ',' ',' ');
wattron(my_wins[0],COLOR_PAIR(2));
wattron(my_wins[0],A_UNDERLINE);
mvwprintw(my_wins[0],3,2,"Instructions:");
wattroff(my_wins[0],A_UNDERLINE);
mvwprintw(my_wins[0],5,2,"This application has been made with an idea of helping the user get accustomed to the terminal.\n");
wprintw(my_wins[0]," The way to move around in this tutorial is:\n\n");
wprintw(my_wins[0]," 1. Next Chapter:F2\n");
wprintw(my_wins[0]," 2.Prev Chapter:F3\n");
wprintw(my_wins[0]," 3.To goto a specific chapter type in g<number>:For example to goto 12th chapter press g12\n");
wprintw(my_wins[0]," 4.To resume: F4(to be done)\n");
wprintw(my_wins[0]," 5.To see the list of contents: F6(to be done)\n");
wprintw(my_wins[0]," 6.If at any instant the tutorial does not work you can always fall back on the default of pressing next or prev after q\n");
wprintw(my_wins[0]," 7.To exit the tutorial press Ctrl+a followed by \\ and y\n\n\n");
wattron(my_wins[0],A_BOLD);
mvwprintw(my_wins[0],18,2,"So what are you waiting for press F2 and get started");
wattroff(my_wins[0],A_BOLD);
wattroff(my_wins[0],COLOR_PAIR(2));
refresh();

/*Defining the panels*/
my_panels[0]=new_panel(my_wins[0]);
my_panels[1]=new_panel(my_wins[1]);
my_panels[2]=new_panel(my_wins[2]);
my_panels[3]=new_panel(my_wins[3]);


/*Setting pointers for Tab usage*/
set_panel_userptr(my_panels[0],my_panels[3]);
set_panel_userptr(my_panels[3],my_panels[0]);

update_panels();

/*End statements for instructions*/
attron(COLOR_PAIR(4));
mvprintw(win_x-3,0,"1.Press tab to see the instructions");
mvprintw(win_x-2,0,"2.To resume press F4(presently does not work)");
attroff(COLOR_PAIR(4));
doupdate();

/*While loop to use tab*/
top=my_panels[3];
while((ch=getch())!=KEY_F(2))
{
switch(ch)
{ 
 case 9:
    top=(PANEL *) panel_userptr(top);
    top_panel(top);
   
}
update_panels();
doupdate();
}
endwin();
return 0;
}

