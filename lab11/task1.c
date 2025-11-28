#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 200

struct Student {
    int roll;
    char name[50];
    int m[3];
    float perc;
    char grade[3];
};

struct Student s[MAX];
int count = 0;

float calc_perc(int m[]) {
    return (m[0] + m[1] + m[2]) / 3.0;
}

void set_grade(float p, char g[]) {
    if (p >= 90) strcpy(g, "A+");
    else if (p >= 80) strcpy(g, "A");
    else if (p >= 70) strcpy(g, "B+");
    else if (p >= 60) strcpy(g, "B");
    else if (p >= 50) strcpy(g, "C");
    else strcpy(g, "F");
}

void add_student() {
    struct Student t;
    printf("Roll: "); scanf("%d", &t.roll);
    printf("Name: "); scanf(" %[^\n]", t.name);
    printf("Marks (3): "); scanf("%d%d%d", &t.m[0], &t.m[1], &t.m[2]);
    t.perc = calc_perc(t.m);
    set_grade(t.perc, t.grade);
    s[count++] = t;
}

void show(struct Student *x) {
    printf("%d | %s | %d %d %d | %.2f | %s\n",
        x->roll, x->name, x->m[0], x->m[1], x->m[2], x->perc, x->grade);
}

void list() {
    for (int i = 0; i < count; i++) show(&s[i]);
}

void search_roll() {
    int r;
    printf("Roll: "); scanf("%d", &r);
    for (int i = 0; i < count; i++)
        if (s[i].roll == r) return show(&s[i]);
    printf("Not found\n");
}

void search_name() {
    char key[50], temp1[50], temp2[50];
    printf("Name: "); scanf(" %[^\n]", key);
    for (int i = 0; i < count; i++) {
        strcpy(temp1, s[i].name);
        strcpy(temp2, key);
        for (int j = 0; temp1[j]; j++) temp1[j] = tolower(temp1[j]);
        for (int j = 0; temp2[j]; j++) temp2[j] = tolower(temp2[j]);
        if (strstr(temp1, temp2)) show(&s[i]);
    }
}

void search_grade() {
    char g[3];
    printf("Grade: "); scanf("%s", g);
    for (int i = 0; i < count; i++)
        if (strcmp(s[i].grade, g) == 0) show(&s[i]);
}

void class_avg() {
    if (count == 0) return;
    float sum = 0; 
    for (int i = 0; i < count; i++) sum += s[i].perc;
    float avg = sum / count;
    printf("Average: %.2f\nAbove:\n", avg);
    for (int i = 0; i < count; i++)
        if (s[i].perc > avg) show(&s[i]);
    printf("Below:\n");
    for (int i = 0; i < count; i++)
        if (s[i].perc < avg) show(&s[i]);
}

int cmp(const void* a, const void* b) {
    float x = ((struct Student*)a)->perc;
    float y = ((struct Student*)b)->perc;
    return (y > x) - (y < x);
}

void ranks() {
    struct Student cpy[MAX];
    memcpy(cpy, s, sizeof(s));
    qsort(cpy, count, sizeof(struct Student), cmp);
    for (int i = 0; i < count; i++)
        printf("%d. %s (%.2f)\n", i+1, cpy[i].name, cpy[i].perc);
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Add\n2.List\n3.Search Roll\n4.Search Name\n5.Search Grade\n6.Average\n7.Ranks\n0.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) add_student();
        else if (ch == 2) list();
        else if (ch == 3) search_roll();
        else if (ch == 4) search_name();
        else if (ch == 5) search_grade();
        else if (ch == 6) class_avg();
        else if (ch == 7) ranks();
        else if (ch == 0) break;
        else printf("Invalid\n");
    }
}
