#include<panel.h>
#include<ncurses.h>

int main()
{
WINDOW *my_wins[2];
PANEL *my_panels[2];
PANEL *top;
int length,win_x,win_y,win1_x,win1_y;
int ch;
char intro[500];


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

/*Creating the first window*/
my_wins[1]=newwin(win_x-4,win_y-2,1,1);
box(my_wins[1],0,0);
length=strlen("BASH TUTOR");
wattron(my_wins[1],A_BOLD);
wattron(my_wins[1],COLOR_PAIR(1));
mvwprintw(my_wins[1],(win_x-4)/2,(win_y/2-length)/2,"BASH TUTOR");
wattroff(my_wins[1],COLOR_PAIR(1));
wattroff(my_wins[1],A_BOLD);
refresh();

my_wins[0]=newwin(win1_x-4,win1_y-2,1,1);
box(my_wins[0],0,0);

wattron(my_wins[0],COLOR_PAIR(1));
mvwprintw(my_wins[0],2,2,"Instructions ");
mvwprintw(my_wins[0],3,2,"This application has been made with an idea of helping the user get accustomed to the terminal.");
mvwprintw(my_wins[0],4,2,"The way to move around in this tutorial is:");
mvwprintw(my_wins[0],6,2,"Next Chapter:F2");
mvwprintw(my_wins[0],7,2,"Prev Chapter:F3");
mvwprintw(my_wins[0],8,2,"To goto a specific chapter type in g<number>");
mvwprintw(my_wins[0],9,2,"For example to goto 12th chapter press g12");
mvwprintw(my_wins[0],10,2,"To resume: F4");
mvwprintw(my_wins[0],11,2,"To see the list of contents: F6");
wattron(my_wins[0],A_BOLD);
mvwprintw(my_wins[0],15,2,"So what are you waiting for press F2 and get started");
wattroff(my_wins[0],A_BOLD);
mvwprintw(my_wins[0],12,2,"To exit the tutorial press Ctrl+a followed by \\ and y");
wattroff(my_wins[0],COLOR_PAIR(1));
refresh();


my_panels[0]=new_panel(my_wins[0]);
my_panels[1]=new_panel(my_wins[1]);

set_panel_userptr(my_panels[0],my_panels[1]);
set_panel_userptr(my_panels[1],my_panels[0]);

update_panels();

attron(COLOR_PAIR(4));
mvprintw(win_x-3,0,"1.Press tab to see the instructions");
mvprintw(win_x-2,0,"2.To resume press F4");
attroff(COLOR_PAIR(4));
doupdate();


top=my_panels[1];
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

