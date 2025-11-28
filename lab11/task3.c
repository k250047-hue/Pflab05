#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max_emp 100

struct date {
    int day, month, year;
};

struct emp {
    int id;
    char name[50];
    char dept[20];
    char role[20];
    double salary;
    struct date join;
    char phone[15];
    char email[50];
};

int total = 0;
struct emp staff[max_emp];

int exp(struct date d) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int y = tm.tm_year + 1900 - d.year;
    if (tm.tm_mon + 1 < d.month || (tm.tm_mon + 1 == d.month && tm.tm_mday < d.day)) y--;
    return y;
}

void add_emp() {
    if(total >= max_emp) {printf("Employee limit reached\n"); return;}
    struct emp *e = &staff[total];
    printf("Enter id: "); scanf("%d", &e->id); getchar();
    printf("Enter name: "); fgets(e->name, 50, stdin); e->name[strcspn(e->name,"\n")]=0;
    printf("Enter department: "); scanf("%s", e->dept);
    printf("Enter role: "); scanf("%s", e->role);
    printf("Enter salary: "); scanf("%lf", &e->salary);
    printf("Enter joining date (dd mm yyyy): "); scanf("%d %d %d",&e->join.day,&e->join.month,&e->join.year); getchar();
    printf("Enter phone: "); fgets(e->phone,15,stdin); e->phone[strcspn(e->phone,"\n")]=0;
    printf("Enter email: "); fgets(e->email,50,stdin); e->email[strcspn(e->email,"\n")]=0;
    total++;
    printf("Employee added successfully\n");
}

void show_all() {
    printf("\nId Name Dept Role Salary Join Phone Email Exp\n");
    for(int i=0;i<total;i++) {
        struct emp e = staff[i];
        printf("%d %s %s %s %.2lf %02d-%02d-%04d %s %s %d\n",
               e.id,e.name,e.dept,e.role,e.salary,e.join.day,e.join.month,e.join.year,
               e.phone,e.email,exp(e.join));
    }
}

void dept_salary() {
    char dlist[5][20] = {"IT","HR","Finance","Marketing","Operations"};
    for(int i=0;i<5;i++) {
        double sum=0; int c=0;
        for(int j=0;j<total;j++) if(strcmp(staff[j].dept,dlist[i])==0){sum+=staff[j].salary;c++;}
        if(c>0) printf("%s dept: avg salary=%.2lf, total=%.2lf\n",dlist[i],sum/c,sum);
    }
}

void annual_appraisal() {
    for(int i=0;i<total;i++) {
        int p;
        printf("Enter performance %% for %s: ", staff[i].name);
        scanf("%d",&p);
        if(p<5) p=5;
        if(p>15) p=15;
        staff[i].salary += staff[i].salary*p/100.0;
    }
    printf("Appraisal updated\n");
}

void search() {
    int ch;
    printf("Search by 1.department 2.role 3.experience: "); scanf("%d",&ch);
    if(ch==1){
        char d[20]; printf("Enter department: "); scanf("%s",d);
        for(int i=0;i<total;i++) if(strcmp(staff[i].dept,d)==0) printf("%s\n",staff[i].name);
    } else if(ch==2){
        char r[20]; printf("Enter role: "); scanf("%s",r);
        for(int i=0;i<total;i++) if(strcmp(staff[i].role,r)==0) printf("%s\n",staff[i].name);
    } else if(ch==3){
        int y; printf("Enter minimum experience: "); scanf("%d",&y);
        for(int i=0;i<total;i++) if(exp(staff[i].join)>=y) printf("%s\n",staff[i].name);
    }
}

void promote() {
    printf("Promotion eligible (>3 years in role):\n");
    for(int i=0;i<total;i++) if(exp(staff[i].join)>3) printf("%s (%s)\n",staff[i].name,staff[i].role);
}

int main() {
    int choice;
    do {
        printf("\n1.Add employee\n2.Show all\n3.Department salary stats\n4.Annual appraisal\n5.Search\n6.Promotion eligible\n0.Exit\nChoice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:add_emp();break;
            case 2:show_all();break;
            case 3:dept_salary();break;
            case 4:annual_appraisal();break;
            case 5:search();break;
            case 6:promote();break;
            case 0:break;
            default:printf("Invalid choice\n");
        }
    } while(choice!=0);
    return 0;
}
