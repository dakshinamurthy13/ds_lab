#include<stdio.h>
struct student{
    int age;
    int id;
    int marks;
};
struct student inputData(int i){
    struct student s1;
    printf("Enter the student No.%d id \n",i+1);
    scanf("%d",&s1.id);
    printf("ENter the student No.%d age\n",i+1);
    scanf("%d",&s1.age);
    printf("Please enter the marks of student No.%d\n",i+1);
    scanf("%d",&s1.marks);
    return s1;
}
void outputEligibleStudents(struct student s[],int n){
    for(int i=0;i<n;i++){
        if(s[i].age>20){
            if(s[i].marks>=0&&s[i].marks<=100){
                if(s[i].marks>=65){
                    printf("The student with id %d is eligible for addmission\n",s[i].id);
                }else{
                    printf("The student with id %d is  not eligible for addmission\n",s[i].id);
                }
            }else{
                printf("The student with id %d has invalid marks\n",s[i].id);
            }
        }else{
            printf("The student with id %d has invalid age\n",s[i].id);
        }
    }
}
int main(){
    int n;
    printf("ENter the number of students\n");
    scanf("%d",&n);
    struct student s[n];
    for(int i=0;i<n;i++)
        s[i]=inputData(i);
    outputEligibleStudents(s,n);
    return 0;
}
