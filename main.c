#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 300

typedef struct {
    int id;         // ѧ�����
    int chinese;  // ���ĳɼ�
    int math;     // ��ѧ�ɼ�
    int english;  // Ӣ��ɼ�
    int total;    // �ܳɼ�
} Student;

// �ȽϺ�������������
int compare(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    if (studentA->total < studentB->total) return 1; // ����
    else if (studentA->total > studentB->total) return -1;
    else return 0;
}

int main() {
    int n;
    Student students[MAX_STUDENTS];

    
    scanf_s("%d", &n);

    // ����ѧ���ɼ�
    for (int i = 0; i < n; i++) {
        students[i].id = i + 1; // ѧ����Ŵ�1��ʼ
        scanf_s("%d\n", &students[i].chinese);
        scanf_s("%d\n", &students[i].math);
        scanf_s("%d", &students[i].english);

        // �����ܳɼ�
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }

    // ���ܳɼ�����
    qsort(students, n, sizeof(Student), compare);

    // ���ǰ����
    for (int i = 0; i < n && i < 5; i++) {
        printf("%d %d\n", students[i].id, students[i].total);
    }

    return 0;
}
