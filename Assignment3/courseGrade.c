#include <stdio.h>
#include<string.h>

int main()
{
//Declare variables
char firtName[20], lastName[20],filename[20];
int mid1, mid2, fin,cnt=0;
char grade;
double mid1Avg=0, mid2Avg=0, finAvg=0,totalAvg=0;

//Prompt for filename
printf("Enter file name: ");
scanf("%s", filename);

//File path set for read
FILE* file;
file = fopen(filename, "r");

//File open error check
if (file == NULL) {
   printf("File not found!!\n");
} else {
//Write file
   FILE* writeFile;
   writeFile=fopen("report.txt", "w");
//Read line by line
   while (fscanf(file, "%s\t%s\t%d\t%d\t%d", firtName, lastName,&mid1,&mid2,&fin)!=EOF) {
//Calculate grade
   totalAvg = (mid1 + mid2 + fin) / 3;
   mid1Avg += mid1;
   mid2Avg += mid2;
   finAvg += fin;
   cnt++;
      if (totalAvg >= 90) {
         grade = 'A';
      }
      else if (totalAvg >= 80) {
         grade = 'B';
      }
      else if (totalAvg >= 70) {
         grade = 'C';
      }
      else if (totalAvg >= 60) {
       grade = 'D';
      }
      else {
         grade = 'F';
      }
//Write into file
   fprintf(writeFile, "%s\t%s\t%d\t%d\t%d\t%c\n", firtName, lastName, mid1, mid2, fin, grade);
}
//Write averages into file
fprintf(writeFile, "%s%s%.2f%s%.2f%s%.2f\n", "\nAverages: ", "midterm1 ", mid1Avg / cnt, ", midterm2 ", mid2Avg / cnt, ", final ", finAvg/cnt);
//Close files
fclose(file);
fclose(writeFile);
}
   return 0;
}