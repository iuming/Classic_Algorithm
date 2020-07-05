#include<stdio.h>
#include<string.h>
#define EPS 1e-6
 
const int max1 = 512;
const int max2 = 85;
char sid[max1][max2], name[max1][max2];
int cid[max1], score[max1][5], rank[max1], removed[max1];
int n = 0;
 
void print_students() 
{
    printf("Current student num: %d\n", n);
    for(int i = 0; i < n; i++) {
        printf("Student %d: sid = %s cid = %d name = %s rank = %d removed = %d score[0] = %d score[1] = %d score[2] = %d score[3] = %d\n",
            i, sid[i], cid[i], name[i], rank[i], removed[i], score[i][0], score[i][1], score[i][2], score[i][3]);
    }
    printf("\n");
}
 
 
void print_menu() 
{
    printf("Welcome to Student Performance Management System (SPMS).\n\n");
    printf("1 - Add\n");
    printf("2 - Remove\n");
    printf("3 - Query\n");
    printf("4 - Show ranking\n");
    printf("5 - Show Statistics\n");
    printf("0 - Exit\n\n");
}
 
void add() 
{
    char s[max2];
    bool dup;
    
    for(;;) {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        dup = false;
        //print_students();
        scanf("%s", s);
        if(strcmp(s, "0") == 0) break;
        strcpy(sid[n], s);
        scanf("%d%s%d%d%d%d", &cid[n], name[n], &score[n][0], &score[n][1], &score[n][2], &score[n][3]);
        for(int i = 0; i < n; i++) {
            if(!removed[i] && strcmp(sid[i], s) == 0) {
                printf("Duplicated SID.\n");
                dup = true;
                break;
            }
        }
        if(dup) continue;
 
        score[n][4] = score[n][0] + score[n][1] + score[n][2] + score[n][3];
        int cnt = 0; // cnt记录成绩比score[n][4]更高的学生数量
        for(int i = 0; i < n; i++) {
            if(!removed[i]) {
                if(score[i][4] < score[n][4]) rank[i]++;
                if(score[i][4] > score[n][4]) cnt++;
            }
        }
        rank[n] = cnt + 1;
        n++;
        //print_students();
    }
}
 
void DQ(int isq)
{
    char s[max2];
    for(;;) {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", s);
        if(strcmp(s, "0") == 0) return;
        int r = 0; // record the num of removed students
        for(int i = 0; i < n; i++) {
            if(!removed[i]) {
                if(strcmp(sid[i], s) == 0 || strcmp(name[i], s) == 0) {
                    if(isq) // For query
                        printf("%d %s %d %s %d %d %d %d %d %.2f\n", rank[i], sid[i], cid[i], name[i], score[i][0],
                            score[i][1], score[i][2], score[i][3], score[i][4], score[i][4]/4.0+EPS);
                    else {
                        removed[i] = 1;
                        r++;
                        for(int j = 0; j < n; j++)
                            if(!removed[j] && rank[j] > rank[i]) rank[j]--;
                    }
                }
            }
        }
        if(!isq) printf("%2d student(s) removed.\n", r);
    }
}
 
void stat() 
{
    printf("Please enter class ID, 0 for the whole statistics.\n");
    int c;
    scanf("%d", &c);
    
    int cnt = 0, pass4=0, pass3=0, pass2=0, pass1=0, pass0=0;
    int sum[4], pass[4];
    memset(sum, 0, sizeof(sum));
    memset(pass, 0, sizeof(pass));
    for(int i = 0; i < n; i++) {
        if(!removed[i]) {
            if(c == 0 || cid[i] == c) {
                cnt++;
                int pass_cnt = 0;
                for(int k = 0; k < 4; k++) {
                    sum[k] += score[i][k];
                    if(score[i][k] >= 60) { pass[k]++; pass_cnt++; }
                }
                if(pass_cnt == 4) pass4++;
                if(pass_cnt == 3) pass3++;
                if(pass_cnt == 2) pass2++;
                if(pass_cnt == 1) pass1++;
                if(pass_cnt == 0) pass0++;
            }    
        }
    }
    for(int k = 0; k < 4; k++) {
        // k 是课程编号
        if(k == 0) printf("%s\n", "Chinese");
        if(k == 1) printf("%s\n", "Mathematics");
        if(k == 2) printf("%s\n", "English");
        if(k == 3) printf("%s\n", "Programming");
        if(cnt > 0) printf("Average Score: %.2f\n", (float)sum[k]/cnt);
        else printf("Average Score: %.2f\n", (float)0.00);
        printf("Number of passed students: %d\n", pass[k]);
        printf("Number of failed students: %d\n\n", cnt - pass[k]);
    }
    printf("Overall:\n");
    printf("Number of students who passed all subjects: %d\n", pass4);
    printf("Number of students who passed 3 or more subjects: %d\n", pass4 + pass3);
    printf("Number of students who passed 2 or more subjects: %d\n", pass4 + pass3 + pass2);
    printf("Number of students who passed 1 or more subjects: %d\n", pass4 + pass3 + pass2 + pass1);
    printf("Number of students who failed all subjects: %d\n\n", pass0);
}
 
int main() 
{
    memset(removed, 0, sizeof(removed));
    for(;;) {
        int choice;
        print_menu();
        scanf("%d", &choice);
        if(choice == 0) break;
        if(choice == 1) add();
        if(choice == 2) DQ(0); // Remove student record
        if(choice == 3) DQ(1); // Query student record
        if(choice == 4) printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
        if(choice == 5) stat();
    }
    return 0;
}