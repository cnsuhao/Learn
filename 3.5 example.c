#include <stdio.h>
main()
{
    int x, y, t;
    printf ( " Enter x & y : \n" );
    scanf ( "%d%d", &x, &y );
    printf ( "x = %d y = %d\n ");
    t = x; x = y; y = t;
    printf ( "x = %d y = %d\n", x, y);
}
