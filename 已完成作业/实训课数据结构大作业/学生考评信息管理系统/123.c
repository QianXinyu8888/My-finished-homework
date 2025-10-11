#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ѧ���ṹ��
typedef struct Student {
    int studentID;
    char name[50];
    char gender[10];
    char birthDate[20];
    char major[50];
    char college[50];
    float moralEducationScore;
    float physicalEducationScore;
    float intellectualEducationScore;
    float comprehensiveScore;
    struct Student* next;
} Student;
typedef struct node{
  Student data;
  struct student* next;
}newstudent;

// ����ͷָ��
Student* head = NULL;

// �����ۺϷ���
float calculateComprehensiveScore(Student* s) {
    return 0.7 * s->intellectualEducationScore + 0.2 * s->moralEducationScore + 0.1 * s->physicalEducationScore;
}

// ���ѧ��
void addStudent() {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    printf("������ѧ����Ϣ��\n");
    printf("ѧ��: ");
    scanf("%d", &newStudent->studentID);
    printf("����: ");
    scanf("%s", newStudent->name);
    printf("�Ա�: ");
    scanf("%s", newStudent->gender);
    printf("��������: ");
    scanf("%s", newStudent->birthDate);
    printf("רҵ: ");
    scanf("%s", newStudent->major);
    printf("����ѧԺ: ");
    scanf("%s", newStudent->college);
    printf("������: ");
    scanf("%f", &newStudent->moralEducationScore);
    printf("������: ");
    scanf("%f", &newStudent->physicalEducationScore);
    printf("������: ");
    scanf("%f", &newStudent->intellectualEducationScore);

    newStudent->comprehensiveScore = calculateComprehensiveScore(newStudent);
    newStudent->next = head;
    head = newStudent;
    printf("ѧ����Ϣ��ӳɹ���\n");
}

// ɾ��ѧ��
void deleteStudentByID() {
    int studentID;
    printf("������Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%d", &studentID);
    Student *current = head, *previous = NULL;
    while (current != NULL) {
        if (current->studentID == studentID) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("ѧ����Ϣɾ���ɹ���\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("δ�ҵ���ѧ�ŵ�ѧ����\n");
}

// ����ѧ����Ϣ
void updateStudentInfoByID() {
    int studentID;
    printf("������Ҫ���µ�ѧ��ѧ�ţ�");
    scanf("%d", &studentID);
    Student* current = head;
    while (current != NULL) {
        if (current->studentID == studentID) {
            printf("Ҫ��������Ϣ�����޸ģ�\n");
            printf("1.�����֣�\n");
            printf("2.�����֣�\n");
            printf("3.�����֣�\n");
            printf("��ѡ�������\n");
            int choice;
            scanf("%d",&choice);
            switch(choice) {
                case 1:
                    printf("������: ");
                    scanf("%f", &current->moralEducationScore);
                    break;
                case 2:
                    printf("������: ");
                    scanf("%f", &current->physicalEducationScore);
                    break;
                case 3:
                    printf("�����֣�");
                    scanf("%f", &current->intellectualEducationScore);
                    current->comprehensiveScore = calculateComprehensiveScore(current);
                    break;
                default:
                    printf("��Ч��ѡ��\n");
            }
            printf("��Ϣ���³ɹ���\n");
            return;
        }
        current = current->next;
    }
    printf("δ�ҵ���ѧ�ŵ�ѧ����\n");
}

// ��ѯѧ����Ϣ
void queryStudentInfo() {
    int choice;
    printf("��ѡ���ѯ��ʽ��\n");
    printf("1. ��ѧ�Ų�ѯ\n");
    printf("2. ��������ѯ\n");
    printf("3. ��רҵ��ѯ\n");
    scanf("%d", &choice);
    Student* current = head;
    switch (choice) {
        case 1: {
            int studentID;
            printf("������ѧ�ţ�");
            scanf("%d", &studentID);
            while (current != NULL) {
                if (current->studentID == studentID) {
                    printf("��ѯ�����\nѧ��:%d ����:%s �Ա�:%s ��������:%s רҵ:%s ����ѧԺ:%s ������:%.2f ������:%.2f ������:%.2f �ۺϷ�:%.2f\n",
                           current->studentID, current->name, current->gender, current->birthDate,
                           current->major, current->college,
                           current->moralEducationScore, current->physicalEducationScore,
                           current->intellectualEducationScore, current->comprehensiveScore);
                    return;
                }
                current = current->next;
            }
            printf("δ�ҵ���ѧ�ŵ�ѧ����\n");
            break;
        }
        case 2: {
            char queryStrname[50];
            printf("������������");
            scanf("%s", queryStrname);
            while (current != NULL) {
                if (strcmp(current->name, queryStrname) == 0) {
                    printf("��ѯ�����\nѧ��:%d ����:%s �Ա�:%s ��������:%s רҵ:%s ����ѧԺ:%s ������:%.2f ������:%.2f ������:%.2f �ۺϷ�:%.2f\n",
                           current->studentID, current->name, current->gender, current->birthDate,
                           current->major, current->college,
                           current->moralEducationScore, current->physicalEducationScore,
                           current->intellectualEducationScore, current->comprehensiveScore);
                    current = current->next;
                    return;
                }
                current = current->next;
            }
            printf("δ�ҵ���������ѧ����\n");
            break;
        }
        case 3: {
            char queryStrmajor[50];
            printf("������רҵ��");
            scanf("%s", queryStrmajor);
            while (current != NULL) {
                if (strcmp(current->major, queryStrmajor) == 0) {
                    printf("��ѯ�����\nѧ��:%d ����:%s �Ա�:%s ��������:%s רҵ:%s ����ѧԺ:%s ������:%.2f ������:%.2f ������:%.2f �ۺϷ�:%.2f\n",
                           current->studentID, current->name, current->gender, current->birthDate,
                           current->major, current->college,
                           current->moralEducationScore, current->physicalEducationScore,
                           current->intellectualEducationScore, current->comprehensiveScore);
                }
                current = current->next;
            }
            return;
        }
        default:
            printf("��Ч��ѡ��\n");
    }
}

// ����ѧ����Ϣ
void sortStudentsByID() {
    if (head == NULL || head->next == NULL) return;
    Student* sorted = NULL;
    Student* current = head;
    while (current != NULL) {
        Student* next = current->next;
        if (sorted == NULL || sorted->studentID >= current->studentID) {
            current->next = sorted;
            sorted = current;
        } else {
            Student* temp = sorted;
            while (temp->next != NULL && temp->next->studentID < current->studentID) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
    printf("������ɡ�\n");
}

// �������ѧ����Ϣ
void browseAllStudents() {
    printf("����ѧ����Ϣ���£�\n");
    Student* current = head;
    while (current != NULL) {
        printf("ѧ��:%d ����:%s �Ա�:%s ��������:%s רҵ:%s ����ѧԺ:%s ������:%.2f ������:%.2f ������:%.2f �ۺϷ�:%.2f\n",
               current->studentID, current->name, current->gender, current->birthDate,
               current->major, current->college,
               current->moralEducationScore, current->physicalEducationScore,
               current->intellectualEducationScore, current->comprehensiveScore);
        current = current->next;
    }
}

// ͳ�Ʋ�����ѧ������
void countFailingStudentsInCollegeAndMajor() {
    char college[50], major[50];
    printf("������ѧԺ��");
    scanf("%s", college);
    printf("������רҵ��");
    scanf("%s", major);
    int count = 0;
    Student* current = head;
    while (current != NULL) {
        if (strcmp(current->college, college) == 0 && strcmp(current->major, major) == 0 && current->comprehensiveScore < 60) {
            count++;
        }
        current = current->next;
    }
    printf("������ѧ��������%d\n", count);
}

// �������ݵ��ļ�
void saveDataToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("�޷����ļ���\n");
        return;
    }
    Student* current = head;
    while (current != NULL) {
        fprintf(file,"%d %s %s %s %s %s %.2f %.2f %.2f %.2f\n",current->studentID, current->name, current->gender, current->birthDate,
               current->major, current->college,
               current->moralEducationScore, current->physicalEducationScore,
               current->intellectualEducationScore, current->comprehensiveScore);
        current = current->next;
    }
    fclose(file);
    printf("���ݱ���ɹ���\n");
}

// ���ļ���ȡ����
void loadDataFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("�޷����ļ���\n");
        return;
    }
    while (1) {
        Student* newStudent = (Student*)malloc(sizeof(Student));
        if (fscanf(file, "%d %s %s %s %s %s %f %f %f %f\n",
                   &newStudent->studentID, newStudent->name, newStudent->gender, newStudent->birthDate,
                   newStudent->major, newStudent->college,
                   &newStudent->moralEducationScore, &newStudent->physicalEducationScore,
                   &newStudent->intellectualEducationScore, &newStudent->comprehensiveScore) == 10) {
            newStudent->next = head;
            head = newStudent;
        } else {
            free(newStudent);
            break;
        }
    }
    fclose(file);
    printf("���ݶ�ȡ�ɹ���\n");
}

int main() {
    // ���˵�
    while (1) {
        printf("\nѧ��������Ϣ����ϵͳ\n");
        printf("1. ���ѧ��\n");
        printf("2. ɾ��ѧ��\n");
        printf("3. ����ѧ����Ϣ\n");
        printf("4. ��ѯѧ����Ϣ\n");
        printf("5. ����ѧ����Ϣ\n");
        printf("6. �������ѧ����Ϣ\n");
        printf("7. ͳ�Ʋ�����ѧ������\n");
        printf("8. ��������\n");
        printf("9. ��ȡ����\n");
        printf("0. �˳�\n");

        printf("�����������ţ�");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudentByID(); break;
            case 3: updateStudentInfoByID(); break;
            case 4: queryStudentInfo(); break;
            case 5: sortStudentsByID(); break;
            case 6: browseAllStudents(); break;
            case 7: countFailingStudentsInCollegeAndMajor(); break;
            case 8: saveDataToFile(); break;
            case 9: loadDataFromFile(); break;
            case 0: return 0;
            default: printf("��Ч��ѡ��\n");
        }
    }

    return 0;
}

