#include <iostream>
#include <sys/time.h>
#include <sgtty.h>
#include <curses.h>
#include <signal.h>
#include <stdlib.h>

const int SEC_DELAY = 0;
const int USEC_DELAY = 800000;
static char lastc = ' ';
void die( void );
char get_char( void );

static int checkinput(int fd, long secDelay, long usecDelay )
/* File descriptor and delay (in seconds) */
{
     int	rdmask;
     struct timeval tvec;
     
     if (fd < 0 || secDelay < 0 || usecDelay < 0 )
	  return(-1);
     rdmask = ( 1 << fd );

     tvec.tv_sec = secDelay;
     tvec.tv_usec = usecDelay;
     int val = select(1, (fd_set *) &rdmask, NULL, NULL, &tvec);
     return val;
}

char get_char( )
{
     int	x;
     char	c;
     
     if ( ( x = checkinput(0, SEC_DELAY, USEC_DELAY ) ) < 0 )
	 die();
     if ( x != 0 ) {
         if ( read(0, &c, 1) < 0)
             die();
         /* if( c == LEFT || c == RIGHT || c == UP || c == DOWN ) */
         lastc = c;
     }
     return( lastc );
}

void die( void )
{
     signal( SIGINT, SIG_IGN );
     mvcur( 0, COLS - 1, LINES - 1, 0 );
     endwin();
     exit( 1 );
}
