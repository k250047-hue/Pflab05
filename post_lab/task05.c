#include<stdio.h>

int main(){





int hasPrerequisite =0 , isCourseFull=0;
if(hasPrerequisite==0){
    if(isCourseFull==0) printf("Cannot enroll: prerequisite missing");
    else printf("Cannot enroll: prerequisite missing and course is full.");
}
else {
if(isCourseFull ==0) printf("Enrolled successfully");
else  printf("Cannot enroll: course is full");
}


    return 0;
}