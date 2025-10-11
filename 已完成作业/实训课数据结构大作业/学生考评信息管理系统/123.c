#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生结构体
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

// 链表头指针
Student* head = NULL;

// 计算综合分数
float calculateComprehensiveScore(Student* s) {
    return 0.7 * s->intellectualEducationScore + 0.2 * s->moralEducationScore + 0.1 * s->physicalEducationScore;
}

// 添加学生
void addStudent() {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    printf("请输入学生信息：\n");
    printf("学号: ");
    scanf("%d", &newStudent->studentID);
    printf("姓名: ");
    scanf("%s", newStudent->name);
    printf("性别: ");
    scanf("%s", newStudent->gender);
    printf("出生日期: ");
    scanf("%s", newStudent->birthDate);
    printf("专业: ");
    scanf("%s", newStudent->major);
    printf("所属学院: ");
    scanf("%s", newStudent->college);
    printf("德育分: ");
    scanf("%f", &newStudent->moralEducationScore);
    printf("体育分: ");
    scanf("%f", &newStudent->physicalEducationScore);
    printf("智育分: ");
    scanf("%f", &newStudent->intellectualEducationScore);

    newStudent->comprehensiveScore = calculateComprehensiveScore(newStudent);
    newStudent->next = head;
    head = newStudent;
    printf("学生信息添加成功。\n");
}

// 删除学生
void deleteStudentByID() {
    int studentID;
    printf("请输入要删除的学生学号：");
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
            printf("学生信息删除成功。\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("未找到该学号的学生。\n");
}

// 更新学生信息
void updateStudentInfoByID() {
    int studentID;
    printf("请输入要更新的学生学号：");
    scanf("%d", &studentID);
    Student* current = head;
    while (current != NULL) {
        if (current->studentID == studentID) {
            printf("要对哪项信息进行修改？\n");
            printf("1.德育分：\n");
            printf("2.体育分：\n");
            printf("3.智育分：\n");
            printf("请选择操作：\n");
            int choice;
            scanf("%d",&choice);
            switch(choice) {
                case 1:
                    printf("德育分: ");
                    scanf("%f", &current->moralEducationScore);
                    break;
                case 2:
                    printf("体育分: ");
                    scanf("%f", &current->physicalEducationScore);
                    break;
                case 3:
                    printf("智育分：");
                    scanf("%f", &current->intellectualEducationScore);
                    current->comprehensiveScore = calculateComprehensiveScore(current);
                    break;
                default:
                    printf("无效的选择\n");
            }
            printf("信息更新成功。\n");
            return;
        }
        current = current->next;
    }
    printf("未找到该学号的学生。\n");
}

// 查询学生信息
void queryStudentInfo() {
    int choice;
    printf("请选择查询方式：\n");
    printf("1. 按学号查询\n");
    printf("2. 按姓名查询\n");
    printf("3. 按专业查询\n");
    scanf("%d", &choice);
    Student* current = head;
    switch (choice) {
        case 1: {
            int studentID;
            printf("请输入学号：");
            scanf("%d", &studentID);
            while (current != NULL) {
                if (current->studentID == studentID) {
                    printf("查询结果：\n学号:%d 姓名:%s 性别:%s 出生日期:%s 专业:%s 所属学院:%s 德育分:%.2f 体育分:%.2f 智育分:%.2f 综合分:%.2f\n",
                           current->studentID, current->name, current->gender, current->birthDate,
                           current->major, current->college,
                           current->moralEducationScore, current->physicalEducationScore,
                           current->intellectualEducationScore, current->comprehensiveScore);
                    return;
                }
                current = current->next;
            }
            printf("未找到该学号的学生。\n");
            break;
        }
        case 2: {
            char queryStrname[50];
            printf("请输入姓名：");
            scanf("%s", queryStrname);
            while (current != NULL) {
                if (strcmp(current->name, queryStrname) == 0) {
                    printf("查询结果：\n学号:%d 姓名:%s 性别:%s 出生日期:%s 专业:%s 所属学院:%s 德育分:%.2f 体育分:%.2f 智育分:%.2f 综合分:%.2f\n",
                           current->studentID, current->name, current->gender, current->birthDate,
                           current->major, current->college,
                           current->moralEducationScore, current->physicalEducationScore,
                           current->intellectualEducationScore, current->comprehensiveScore);
                    current = current->next;
                    return;
                }
                current = current->next;
            }
            printf("未找到该姓名的学生。\n");
            break;
        }
        case 3: {
            char queryStrmajor[50];
            printf("请输入专业：");
            scanf("%s", queryStrmajor);
            while (current != NULL) {
                if (strcmp(current->major, queryStrmajor) == 0) {
                    printf("查询结果：\n学号:%d 姓名:%s 性别:%s 出生日期:%s 专业:%s 所属学院:%s 德育分:%.2f 体育分:%.2f 智育分:%.2f 综合分:%.2f\n",
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
            printf("无效的选择。\n");
    }
}

// 排序学生信息
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
    printf("排序完成。\n");
}

// 浏览所有学生信息
void browseAllStudents() {
    printf("所有学生信息如下：\n");
    Student* current = head;
    while (current != NULL) {
        printf("学号:%d 姓名:%s 性别:%s 出生日期:%s 专业:%s 所属学院:%s 德育分:%.2f 体育分:%.2f 智育分:%.2f 综合分:%.2f\n",
               current->studentID, current->name, current->gender, current->birthDate,
               current->major, current->college,
               current->moralEducationScore, current->physicalEducationScore,
               current->intellectualEducationScore, current->comprehensiveScore);
        current = current->next;
    }
}

// 统计不及格学生人数
void countFailingStudentsInCollegeAndMajor() {
    char college[50], major[50];
    printf("请输入学院：");
    scanf("%s", college);
    printf("请输入专业：");
    scanf("%s", major);
    int count = 0;
    Student* current = head;
    while (current != NULL) {
        if (strcmp(current->college, college) == 0 && strcmp(current->major, major) == 0 && current->comprehensiveScore < 60) {
            count++;
        }
        current = current->next;
    }
    printf("不及格学生人数：%d\n", count);
}

// 保存数据到文件
void saveDataToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("无法打开文件。\n");
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
    printf("数据保存成功。\n");
}

// 从文件读取数据
void loadDataFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("无法打开文件。\n");
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
    printf("数据读取成功。\n");
}

int main() {
    // 主菜单
    while (1) {
        printf("\n学生考评信息管理系统\n");
        printf("1. 添加学生\n");
        printf("2. 删除学生\n");
        printf("3. 更新学生信息\n");
        printf("4. 查询学生信息\n");
        printf("5. 排序学生信息\n");
        printf("6. 浏览所有学生信息\n");
        printf("7. 统计不及格学生人数\n");
        printf("8. 保存数据\n");
        printf("9. 读取数据\n");
        printf("0. 退出\n");

        printf("请输入操作编号：");
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
            default: printf("无效的选择\n");
        }
    }

    return 0;
}

