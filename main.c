#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 300

typedef struct {
    int id;         // 学生序号
    int chinese;  // 语文成绩
    int math;     // 数学成绩
    int english;  // 英语成绩
    int total;    // 总成绩
} Student;

// 比较函数，用于排序
int compare(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    if (studentA->total < studentB->total) return 1; // 降序
    else if (studentA->total > studentB->total) return -1;
    else return 0;
}

int main() {
    int n;
    Student students[MAX_STUDENTS];

    
    scanf_s("%d", &n);

    // 输入学生成绩
    for (int i = 0; i < n; i++) {
        students[i].id = i + 1; // 学生序号从1开始
        scanf_s("%d\n", &students[i].chinese);
        scanf_s("%d\n", &students[i].math);
        scanf_s("%d", &students[i].english);

        // 计算总成绩
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }

    // 按总成绩排序
    qsort(students, n, sizeof(Student), compare);

    // 输出前五名
    for (int i = 0; i < n && i < 5; i++) {
        printf("%d %d\n", students[i].id, students[i].total);
    }

    return 0;
}
