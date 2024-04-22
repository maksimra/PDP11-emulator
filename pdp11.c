#include "pdp11.h"

byte mem [MEMSIZE];

void b_write (Adress adr, byte b)
{
    mem[adr] = b;
}

byte b_read (Adress adr)
{
    return mem[adr];
}

word w_read (Adress a)
{
    word w = ((word) mem[a+1]) << 8;
    w = w | mem[a];
    printf ("w = %x\n", w);
    return w;
}

void test_mem ()
{
    byte b0 = 0x0a;
    b_write (2, b0);
    byte bres = b_read (2);
    printf ("%02hhx = %02hhx\n", b0, bres);
    assert (b0 == bres);

    Adress a = 4;
    byte b1 = 0x0b;
    word w = 0x0b0a;
    b_write (a, b0);
    b_write (a + 1, b1);
    word wres = w_read (a);
    printf ("ww/br \t %04hx=%02hhx%02hhx\n", wres, b1, b0);
    assert (wres == w);
}
