#include <stdio.h>
#include <stdlib.h>

static void do_head(FILE *f, long nlines);

/* #@@range_begin(main) */
int
main(int argc, char *argv[])
{
    long nlines;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s n [file file...]\n", argv[0]);
        exit(1);
    }
    nlines = atol(argv[1]);
    if (argc == 2) {
        do_head(stdin, nlines);
    } else {    /* �����᤬�ɲä��줿 */
        int i;

        for (i = 2; i < argc; i++) {
            FILE *f;

            f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[i]);
                exit(1);
            }
            do_head(f, nlines);
            fclose(f);
        }
    }
    exit(0);
}
/* #@@range_end(main) */

static void
do_head(FILE *f, long nlines)
{
    int c;

    if (nlines <= 0) return;
    while ((c = getc(f)) != EOF) {
        if (putchar(c) < 0) exit(1);
        if (c == '\n') {
            nlines--;
            if (nlines == 0) return;
        }
    }
}
