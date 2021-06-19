
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

typedef int INT_ARRAY_10[10];
INT_ARRAY_10 array;
int size = 10;

int main() {
   array[0] = 12;
   array[1] = 9;
   array[2] = 4;
   array[3] = 99;
   array[4] = 120;
   array[5] = 1;
   array[6] = 3;
   array[7] = 10;
   array[8] = 67;
   array[9] = 32;

   printString("before:\n");
   for (int i = 0; i < size; i = i + 1) {
       printInt(array[i]);
       printChar(' ');
   }
   printChar('\n');

   bubble_srt((int *) array, size);
   printString("after:\n");
   for (int i = 0; i < size; i = i + 1) {
       printInt(array[i]);
       printChar(' ');
   }
   printChar('\n');
   return 0;
}
