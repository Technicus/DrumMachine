// Reference:
// < http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/2-C-adv-data/struct-pointer.html >
// < https://www.codesdope.com/cpp-structure/ >
// < https://stackoverflow.com/questions/26518681/how-to-reference-a-structure-member-through-variable?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa >
// < https://users.cs.cf.ac.uk/Dave.Marshall/C/node13.html >

#include <stdio.h>
#include <stdlib.h>

struct bits {
   unsigned int a:1;
   unsigned int b:1;
   unsigned int c:1;
   unsigned int d:1;
   unsigned int e:1;
   unsigned int f:1;
   unsigned int g:1;
   unsigned int h:1;
};
struct bits dataBits;

int bitOperation(bits &dataBits, unsigned int bit, unsigned int operation){
   switch(bit){
      case 0:
         switch (operation) {
            case 1: // Get
               printf("\n\tThe selected bit = ");
               printf("%d \n",dataBits.h);
               break;
            case 2: // Set
               dataBits.h = 1;
               break;
            case 3: // Unset | clear
               dataBits.h = 0;
               break;
            case 4: // Toggle any of the following methods work
               // dataBits.h = !dataBits.h;
               // dataBits.h = ~dataBits.h;
               dataBits.h ^= 1;
               break;
            case 5: // check if dataBits.h is non zero the next line below will execute
               if (dataBits.h){
                  printf("\n\tdataBits.h is non-zero.");
               }
               else{
                  printf("\n\tdataBits.h is not set.");
               }
               break;
            default:
               printf("\n\tYour choice was out of bounds.\nAs a result you will be ignored.\n\n");
               return 1;
            }
            break;
      case 1:
         switch (operation) {
            case 1: // Get
               printf("\n\tThe selected bit = ");
               printf("%d \n",dataBits.g);
               break;
            case 2: // Set
               dataBits.g = 1;
               break;
            case 3: // Unset | clear
               dataBits.g = 0;
               break;
            case 4: // Toggle any of the following methods work
               // dataBits.g = !dataBits.g;
               // dataBits.g = ~dataBits.g;
               dataBits.g ^= 1;
               break;
            case 5: // check if dataBits.g is non zero the next line below will execute
               if (dataBits.g){
                  printf("\n\tdataBits.g is non-zero.");
               }
               else{
                  printf("\n\tdataBits.g is not set.");
               }
               break;
            default:
               printf("\n\tYour choice was out of bounds.\nAs a result you will be ignored.\n\n");
               return 1;
         }
         break;
      case 2:
         switch (operation) {
            case 1: // Get
               printf("\n\tThe selected bit = ");
               printf("%d \n",dataBits.f);
               break;
            case 2: // Set
               dataBits.f = 1;
               break;
            case 3: // Unset | clear
               dataBits.f = 0;
               break;
            case 4: // Toggle any of the following methods work
               // dataBits.f = !dataBits.f;
               // dataBits.f = ~dataBits.f;
               dataBits.f ^= 1;
               break;
            case 5: // check if dataBits.f is non zero the next line below will execute
               if (dataBits.f){
                  printf("\n\tdataBits.f is non-zero.");
               }
               else{
                  printf("\n\tdataBits.f is not set.");
               }
               break;
            default:
               printf("\n\tYour choice was out of bounds.\nAs a result you will be ignored.\n\n");
               return 1;
         }
         break;
      case 3:
         switch (operation) {
            case 1: // Get
               printf("\n\tThe selected bit = ");
               printf("%d \n",dataBits.e);
               break;
            case 2: // Set
               dataBits.e = 1;
               break;
            case 3: // Unset | clear
               dataBits.e = 0;
               break;
            case 4: // Toggle any of the following methods work
               // dataBits.e = !dataBits.e;
               // dataBits.e = ~dataBits.e;
               dataBits.e ^= 1;
               break;
            case 5: // check if dataBits.e is non zero the next line below will execute
               if (dataBits.e){
                  printf("\n\tdataBits.e is non-zero.");
               }
               else{
                  printf("\n\tdataBits.e is not set.");
               }
               break;
            default:
               printf("\n\tYour choice was out of bounds.\nAs a result you will be ignored.\n\n");
               return 1;
         }
         break;
      case 4:
         switch (operation) {
            case 1: // Get
               printf("\n\tThe selected bit = ");
               printf("%d \n",dataBits.d);
               break;
            case 2: // Set
               dataBits.d = 1;
               break;
            case 3: // Unset | clear
               dataBits.d = 0;
               break;
            case 4: // Toggle any of the following methods work
               // dataBits.d = !dataBits.d;
               // dataBits.d = ~dataBits.d;
               dataBits.d ^= 1;
               break;
            case 5: // check if dataBits.d is non zero the next line below will execute
               if (dataBits.d){
                  printf("\n\tdataBits.d is non-zero.");
               }
               else{
                  printf("\n\tdataBits.d is not set.");
               }
               break;
            default:
               printf("\n\tYour choice was out of bounds.\nAs a result you will be ignored.\n\n");
               return 1;
         }
         break;
      case 5:
         switch (operation) {
            case 1: // Get
               printf("\n\tThe selected bit = ");
               printf("%d \n",dataBits.c);
               break;
            case 2: // Set
               dataBits.c = 1;
               break;
            case 3: // Unset | clear
               dataBits.c = 0;
               break;
            case 4: // Toggle any of the following methods work
               // dataBits.c = !dataBits.c;
               // dataBits.c = ~dataBits.c;
               dataBits.c ^= 1;
               break;
            case 5: // check if dataBits.c is non zero the next line below will execute
               if (dataBits.c){
                  printf("\n\tdataBits.c is non-zero.");
               }
               else{
                  printf("\n\tdataBits.c is not set.");
               }
               break;
            default:
               printf("\n\tYour choice was out of bounds.\nAs a result you will be ignored.\n\n");
               return 1;
         }
         break;
      case 6:
         switch (operation) {
            case 1: // Get
               printf("\n\tThe selected bit = ");
               printf("%d \n",dataBits.b);
               break;
            case 2: // Set
               dataBits.b = 1;
               break;
            case 3: // Unset | clear
               dataBits.b = 0;
               break;
            case 4: // Toggle any of the following methods work
               // dataBits.b = !dataBits.b;
               // dataBits.b = ~dataBits.b;
               dataBits.b ^= 1;
               break;
            case 5: // check if dataBits.b is non zero the next line below will execute
               if (dataBits.b){
                  printf("\n\tdataBits.b is non-zero.");
               }
               else{
                  printf("\n\tdataBits.b is not set.");
               }
               break;
            default:
               printf("\n\tYour choice was out of bounds.\nAs a result you will be ignored.\n\n");
               return 1;
         }
         break;
      case 7:
         switch (operation) {
            case 1: // Get
               printf("\n\tThe selected bit = ");
               printf("%d \n",dataBits.a);
               break;
            case 2: // Set
               dataBits.a = 1;
               break;
            case 3: // Unset | clear
               dataBits.a = 0;
               break;
            case 4: // Toggle any of the following methods work
               // dataBits.a = !dataBits.a;
               // dataBits.a = ~dataBits.a;
               dataBits.a ^= 1;
               break;
            case 5: // check if dataBits.a is non zero the next line below will execute
               if (dataBits.a){
                  printf("\n\tdataBits.a is non-zero.");
               }
               else{
                  printf("\n\tdataBits.a is not set.");
               }
               break;
            default:
               printf("\n\tYour choice was out of bounds.\nAs a result you will be ignored.\n\n");
               return 1;
         }
         break;
            default:
               printf("\n\tYour choice was out of bounds.\nAs a result you will be ignored.\n\n");
            return 1;
   }
}

int main(int argc, char *argv[]) {

   //    unsigned char dataBits=0xFF;
   int i = 0;
   int operation = 0;
   unsigned int bit = 1;

   printf("\n----------------------------------\n");

   while(1){
      printf("\n\tData = 0b ");
      printf("%d %d %d %d %d %d %d %d",dataBits.a,dataBits.b,dataBits.c,dataBits.d,dataBits.e,dataBits.f,dataBits.g,dataBits.h);
      //for (i = 0; i < 8; i++) {
      // printf("%d ", !!((dataBits << i) & 0x80));
      // }
      printf("\n");

      printf("\n\tChoose the bit you want to operate on.\n ");
      printf(  "\t   [7] [6] [5] [4] [3] [2] [1] [0]: ");
      scanf("%d",&bit);

      if (bit > 7 | bit < 0){
         printf("\n\tYour choice was out of bounds.\n\tAs a result you will be ignored.\n\n");
         return 1;
      }

      printf("\n\tChoose an operation:\n");
      printf("\t\t1 - Get    \n");
      printf("\t\t2 - Set    \n");
      printf("\t\t3 - Unset  \n");
      printf("\t\t4 - Toggle \n");
      printf("\t\t0 - Exit \n");
      printf("\tOperation = ");
      scanf("%d",&operation);

      if (operation == 0){
         printf("\n\tOkay, it's all over, have fun and stuff.\n\n");
         return 0;
      }



      bitOperation(dataBits, bit, operation);

      //       //Print the data
      //       printf("\n\tThe %dth bit of Data is = ",bit,dataBits);
      //       for (i = 0; i < 8; i++) {
      //          //          printf("%d ", !!((dataBits << i) & 0x80));
      //       }
      printf("\n");
      printf("----------------------------------\n");
   }

}


// for loop member through variable example
/* struct Pixel {
   *   unsigned char Red;
   *   unsigned char Green;
   *   unsigned char Blue;
} *;             *

unsigned char get_element(struct Pixel * sp, const char * label)
{
   if ( !strcmp(label, "Red") ) {
      return sp->Red;
   }
   else if ( !strcmp(label, "Green") ) {
      return sp->Green;
   }
   else if ( !strcmp(label, "Blue") ) {
      return sp->Blue;
   }
   else {
      assert(false);
   }
}

int main(void)
{
   const char * color[] = {"Red", "Green", "Blue"};
   struct Pixel p = {255, 255, 255};
   for ( size_t i = 0; i < 3; ++i ) {
      unsigned char element = get_element(&p, color[i]);
      /*  do stuff  */
 /*  }

   return 0;
}
                */

 //    switch (operation) {
 //       case 1:
 //          // Get
 //          // (dataBits >> iPos) & 1;
 //          //  if (dataBits.charPos){ //if dataBits.c is non zero the next line below will execute
 //          //     printf("\n\tThe %dth bit of Data is = ",iPos,dataBits);
 //          //  }
 //          //  break;
 //       case 2:
 //          // Set
 //          //             dataBits |= 1 << iPos;
 //          break;
 //       case 3:
 //          // Unset | clear
 //          //             dataBits &= ~(1 << iPos);
 //          break;
 //       case 4:
 //          // Toggle
 //          //             dataBits ^= 1 << iPos;
 //          break;
 //       default:
 //          printf("\n\tYour choice was out of bounds.\nAs a result you will be ignored.\n\n");
 //          return 1;
 //    }