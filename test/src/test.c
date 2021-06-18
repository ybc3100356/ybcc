//int main() {
//    int c[10][20][30];
//    int a = 10;
//    int *p = &a;
//    int *p2 = &a;
//    int **pp = &p;
//    int **k;
//    k = &p2;
//    a = c[1][2][3];
//    c[1][2][3] =3;
//    p = c;
//    p = c[1];
//    p = c[1][2];
////    p = c[1][2][3];
//    p = &c[1][2][3];
//    *pp = c;
//    *pp = c[1];
//    *pp = c[1][2];
////    &c[1];
////    &c[1][1];
//    &c[1][1][1];
//    p + 1 + 2 + 3 - p + p;
//    2 + 3 + p;
//    2 + p + 3;
//    int d = p2 - p;
//    *(1+p);
//    //&(1+p)
//    **(1+pp);
//    pp = (int**)c;
//}

//int main() {
//    char c = 't';
//    char str[12];
//    str[0] = 'H';
//    str[1] = 'e';
//    str[2] = 'l';
//    str[3] = 'l';
//    str[4] = 'o';
//    str[5] = ' ';
//    str[6] = 'W';
//    str[7] = 'o';
//    str[8] = 'r';
//    str[9] = 'l';
//    str[10] = 'd';
//    str[11] = (char) 0;
//    printString(str);
//    return 0;
//}
//
//typedef char* string;
//
//int main() {
//    string str ="Hello World!";
//    char newLine = '\n';
//    printString(str);
//    printChar(newLine);
//    int x = 21;
//    printInt(x);
//    return x;
//}

int bubble_srt(int *a, int n) {
    int i, j;
    for (i = 0; i < n; i = i + 1) {
        for (j = 1; j < (n - i); j = j + 1) {
            if (a[j - 1] > a[j]) {
                int t;
                t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
        }
    }
    return 0;
}

int main() {
    int array[8];
    array[0] = 12;
    array[1] = 9;
    array[2] = 4;
    array[3] = 99;
    array[4] = 120;
    array[5] = 1;
    array[6] = 3;
    array[7] = 10;

    printString("before:\n");
    for (int i = 0; i < 8; i = i + 1) {
        printInt(array[i]);
        printChar(' ');
    }
    printChar('\n');

    bubble_srt((int *) array, 8);
    printString("after:\n");
    for (int i = 0; i < 8; i = i + 1) {
        printInt(array[i]);
        printChar(' ');
    }
    return 0;
}