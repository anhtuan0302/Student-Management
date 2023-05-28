#include <stdio.h> 
#include <string.h> 
#include <conio.h> 												//getch()
#include <stdlib.h> 											//exit ()

struct Student {
	int id;
	char name [50];
	char gender [10];
	int age;
	int phone;
	char address [50];
	char grade [10];
	float math;
	float physic;
	float chemistry;
	float gpa;
	char rank [10];
};

typedef Student ST;

void add_student (ST &st);
void show_student (ST st);
float gpa_student (ST &st);
void rank_student (ST &st);
void update_student (ST &st);
void add_list_student (ST a[], int &n);
void show_list_student (ST a[], int n);
void delete_student_by_id (ST a[], int &n, int delete_id);
void find_student_by_id (ST a[], int n, int find_id);
int find_student_by_name (ST a[], int n, char name[]);
float find_max_gpa (ST a[], int n);
float find_min_gpa (ST a[], int n);
int find_max_age (ST a[], int n);
int find_min_age (ST a[], int n);
void list_student_by_rank (ST a[], int n, char rank[]);
void list_student_by_grade (ST a[], int n, char grade[]);
void sort_list_student_by_name_a_z (ST a[], int n);
void sort_list_student_by_name_z_a (ST a[], int n);
void sort_list_student_by_gpa_0_10 (ST a[], int n);
void sort_list_student_by_gpa_10_0 (ST a[], int n);

void add_student (ST &st) {
	printf ("ID: "); scanf ("%d", &st.id);
	printf ("Name: "); fflush (stdin); gets (st.name);
	printf ("Gender: "); fflush (stdin); gets (st.gender);
	printf ("Age: "); scanf ("%d", &st.age);
	printf ("Phone: "); scanf ("%d", &st.phone);
	printf ("Address: "); fflush (stdin); gets (st.address);
	printf ("Class: "); fflush(stdin); gets(st.grade);
	printf ("Math: "); scanf("%f", &st.math);
	printf ("Physic: "); scanf("%f", &st.physic);
	printf ("Chemistry: "); scanf("%f", &st.chemistry);
}

void show_student (ST st) {
	printf("%d \t %s \t %s \t %d \t %d \t %s \t %s \t %.2f \t %.2f \t %.2f \t %.2f \t %s", st.id, st.name, st.gender, st.age, st.phone, st.address, st.grade, st.math, st.physic, st.chemistry, st.gpa, st.rank);
}

void gpa_student (ST *st) {
	st->gpa = (st->math+st->physic+st->chemistry)/3;
}
 
void rank_student (ST &st) {
	if (st.gpa > 8.0) {
		strcpy (st.rank, "Distinction");
	}
	else if (st.gpa > 6.5) {
		strcpy (st.rank, "Credit");
	}
	else if (st.gpa > 5.0) {
		strcpy (st.rank, "Pass");
	}
	else {
		strcpy (st.rank, "Fail");
	}
	
}

void update_student (ST &st) {
	add_student (st);
	gpa_student (&st);
	rank_student (st);
}

void add_list_student (ST a[], int &n) {
	do {
		printf("\nEnter the number of student to add: ");
		scanf("%d", &n);
		if (n<=0) {
			printf ("\nInvalid! Please re-enter!\n");
		}
	} while (n<=0);
	for(int i=0; i<n ; i++) {
		printf ("\nEnter information student %d: \n", i+1);
		update_student (a[i]);
	}
}

void show_list_student (ST a[], int n) {
	int found = 0;
	for (int i=0; i<n ; i++){
		printf("ID \t Name \t Gender \t Age \t Class \t Math \t Physic \t Chemistry \t GPA \t Rank\n");
		show_student (a[i]);
		printf("\n");
		found = 1;
	}
	if (found == 0) {
		printf ("\nList student is empty! Please add new student (Choice 1)\n");
		fflush (stdin);
	}
}

void delete_student_by_id (ST a[], int &n, int delete_id) {
	int found = 0;
	for (int i=0; i<n ; i++) {
		if (a[i].id == delete_id) {
			for(int j=i; j<n; j++) {
				a[j] = a[j+1];
			}
			n-=1;
			printf ("Delete successful student ID %d\n\n", delete_id);
			printf ("List student after delete:\n");
			show_list_student (a, n);
			found = 1;
			break;
		}
	}
	if (found == 0) {
		printf ("\nDelete failed! Not found student ID %d!\n", delete_id);
		fflush (stdin);	
	}
}

void edit_student_by_id (ST a[], int n, int edit_id) {
	int found = 0;
	for (int i=0; i<n; i++) {
		if (a[i].id==edit_id) {
			found = 1;
			printf ("Edit information student ID %d: \n", edit_id);
			update_student (a[i]);
			break;
		}
	}
	if (found==0) {
		printf ("\nEdit failed! Not found student ID %d!\n", edit_id);
	}
}
 
void find_student_by_id (ST a[], int n, int find_id) {
	int found = 0;
	for (int i=0; i<n; i++) {
		if (a[i].id==find_id) {
			printf ("Find successful student ID %d\n\n", find_id);
			printf ("Information of student to find:\n");
			show_student (a[i]);
			found = 1;
		}
	}
	if (found == 0) {
		printf ("\nFind failed! Not found student ID %d!\n", find_id);
		fflush (stdin);	
	}
}

int find_student_by_name (ST a[], int n, char name[]) {
	for (int i=0; i<n ; i++) {
		if (strstr(strupr(a[i].name), strupr(name))) {
			printf ("List student after find:\n");
			show_student(a[i]);
		return 1;
		}
	}
	return 0;
}

float find_max_gpa (ST a[], int n) {
	float max = a[0].gpa;
	for (int i=0; i<n; i++){
		if (max < a[i].gpa){
			max = a[i].gpa;
			show_student (a[i]);
			printf ("\n");
			return max;
		}
	}
}

float find_min_gpa (ST a[], int n){
	float min = a[0].gpa;
	for (int i=0; i<n; i++){
		if (min > a[i].gpa){
			min = a[i].gpa;
			show_student (a[i]);
			printf ("\n");
			return min;
		}
	}
}

int find_max_age (ST a[], int n) {
	int max = a[0].age;
	for (int i=0; i<n; i++) {
		if (max < a[i].age) {
			max = a[i].age;
			show_student (a[i]);
			printf ("\n");
			return max;
		}
	}
}

int find_min_age (ST a[], int n) {
	int min = a[0].age;
	for (int i=0; i<n; i++) {
		if (min > a[i].age) {
			min = a[i].age;
			show_student (a[i]);
			printf ("\n");
			return min;
		}
	}
}

void list_student_by_rank (ST a[], int n, char rank[]) {
	int found = 0;
	for (int i=0; i<n ; i++) {
		if (strcmp(strupr(a[i].rank), strupr(rank))==0) {
			printf("\nList of students by Rank %s:", rank);
			printf ("\nID \t Name \t\t Sex \t Age \t Phone \t\t Address \t\t Class \t Math \t Physic \t Chemistry \t\t GPA \t\t Rank\n");
			show_student (a[i]);
			printf("\n");
			found = 1;
		}
	}
	if (found == 0) {
		printf ("Find failed! Not found Rank %s!\n", rank);
		fflush (stdin);
	}
}

void list_student_by_grade (ST a[], int n, char grade[]) {
	int found = 0;
	for (int i=0; i<n ; i++) {
		if (strcmp(strupr(a[i].grade), strupr(grade))) {
			printf("\nList of students by Grade %s:", grade);
			printf ("ID \t Name \t\t Sex \t Age \t Phone \t\t Address \t\t Class \t Math \t Physic \t Chemistry \t\t GPA \t\t Rank");
			show_student (a[i]);
			printf("\n");
			found = 1;
		}
	}
	if (found == 0) {
		printf ("\nFind failed! Not found Grade %s!", grade);
		fflush (stdin);
	}
}

void sort_list_student_by_name_a_z (ST a[], int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			if (strcmp(strupr(a[i].name), strupr(a[j].name))>0) {
				ST temp;
				temp = a[i];
				a[i] = a[j];
				a[j]=temp;
			}
		}
	}
}

void sort_list_student_by_name_z_a (ST a[], int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			if (strcmp(strupr(a[i].name), strupr(a[j].name))<0) {
				ST temp;
				temp = a[i]; 
				a[i] = a[j];
				a[j]=temp;
			}
		}
	}
}

void sort_list_student_by_gpa_0_10 (ST a[], int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			if(a[i].gpa>a[j].gpa) {
				ST temp;
				temp = a[i];
				a[i] = a[j];
				a[j]=temp;
			}
		}
	}
}

void sort_list_student_by_gpa_10_0 (ST a[], int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			if (a[i].gpa<a[j].gpa) {
				ST temp;
				temp = a[i];
				a[i] = a[j];
				a[j]=temp;
			}
		}
	}
}

void press_any_key() {
	printf("\nPlease press any key: ");
    getch();
    printf ("\n");
	}

int main() {
	ST a[100];
	int n;
	int choice;
	while (1) {
		printf ("\n=====================================================\n");
		printf ("----------    STUDENT MANAGEMENT SYSTEM    ----------\n");
		printf ("=====================================================\n");
		printf ("\n1. Add new student");	
		printf ("\n2. Delete a student by ID");	
		printf ("\n3. Edit a student by ID");	
		printf ("\n4. Find a student by ID");		
		printf ("\n5. Find a student by Name");	
		printf ("\n6. Find Highest GPA");
		printf ("\n7. Find Lowest GPA");
		printf ("\n8. Find Highest Age");
		printf ("\n9. Find Lowest Age");	
		printf ("\n10. List of students by Rank");
		printf ("\n11. List of students by Class");
		printf ("\n12. Sort list of students by Name (A->Z)");
		printf ("\n13. Sort list of students by Name (Z->A)");
		printf ("\n14. Sort list of students by GPA (0->10)");
		printf ("\n15. Sort list of students by GPA (10->0)");
		printf ("\n16. View all students");
		printf ("\n0. Exit\n");
		printf ("\n-----------------------------------------------------");
		printf ("\nPlease enter choice: "); scanf ("%d", &choice);
		printf ("-----------------------------------------------------");
	
		switch (choice) {
			case 1:
				printf ("\nChoice: 1. Add new students\n");
				printf ("-----------------------------------------------------\n");
				add_list_student (a, n); 
				press_any_key();
				break;
			case 2:
				int delete_id;
				printf ("\nChoice: 2. Delete a student by ID\n");
				printf ("-----------------------------------------------------\n");
				printf ("\nEnter student ID to delete: "); scanf ("%d", &delete_id);
				delete_student_by_id (a, n, delete_id);
				press_any_key();
				break;
			case 3: 
				int edit_id;
				printf ("\nChoice: 3. Edit a student by ID\n");
				printf ("-----------------------------------------------------\n");
				printf ("\nEnter student ID to edit: "); scanf ("%d", &edit_id);
				edit_student_by_id (a, n, edit_id);
				press_any_key();
				break;
			case 4:
				int find_id;
				printf ("\nChoice: 4. Find a student by ID\n");
				printf ("-----------------------------------------------------\n");
				printf ("\nEnter student ID to find: "); scanf ("%d", &find_id);
				find_student_by_id (a, n, find_id);
				press_any_key();
				break;
			case 5:
				char name[50];
				printf ("\nChoice: 5. Find a student by Name\n");
				printf ("-----------------------------------------------------\n");
				printf ("\nEnter student Name to find: "); fflush(stdin); gets(name); 
				printf ("\nResult: %d\n", find_student_by_name (a, n, name));
				press_any_key();
				break;
			case 6: 
				printf ("\nChoice: 6. Find Highest GPA\n");
				printf ("-----------------------------------------------------\n");
				printf ("\nHighest GPA = %.2f\n", find_max_gpa (a, n));
				press_any_key();
				break;
			case 7: 
				printf ("\nChoice: 7. Find Lowest GPA\n");
				printf ("-----------------------------------------------------\n");
				printf ("\nLowest GPA = %.2f\n", find_min_gpa (a, n));;
				press_any_key();
				break;
			case 8:
				printf ("\nChoice: 8. Find Highest Age\n");
				printf ("-----------------------------------------------------\n");
				printf ("\nHighest Age = %d\n", find_max_age(a, n));
				press_any_key();
				break;
			case 9: 
				printf ("\nChoice: 9. Find Lowest Age\n");
				printf ("-----------------------------------------------------\n");
				printf ("\nLowest Age = %d\n", find_min_age(a, n));
				press_any_key();
				break;
			case 10:
				char rank [10];
				printf ("\nChoice: 10. List of students by Rank\n");
				printf ("-----------------------------------------------------\n");
				printf ("\nRank to look for: "); fflush(stdin); gets(rank); 
				printf ("\n");
				list_student_by_rank(a, n, rank);
				press_any_key();
				break;
			case 11: 
				char grade [10];
				printf ("\nChoice: 11. List of students by Class\n");
				printf ("-----------------------------------------------------\n");
				printf("\nClass to look for: "); fflush(stdin); gets(grade); 
				list_student_by_grade(a, n, grade);
				printf ("\n");
				press_any_key();
				break;
			case 12:
				printf ("\nChoice: 12. Sort list of students by Name (A->Z)\n");
				printf ("-----------------------------------------------------\n");
				sort_list_student_by_name_a_z (a, n);
				show_list_student (a, n);
				press_any_key();
				break;
			case 13:
				printf ("\nChoice: 13. Sort list of students by Name (Z->A)\n");	
				printf ("-----------------------------------------------------\n");
				sort_list_student_by_name_z_a (a, n);
				show_list_student (a, n);
				press_any_key();
				break;
			case 14:
				printf ("\nChoice: 14. Sort list of students by GPA (0->10)\n");
				printf ("-----------------------------------------------------\n");
				sort_list_student_by_gpa_0_10 (a, n);
				show_list_student (a, n);
				press_any_key();
				break;	
			case 15:
				printf ("\nChoice: 15. Sort list of students by GPA (10->0)\n");
				printf ("-----------------------------------------------------\n");
				sort_list_student_by_gpa_10_0 (a, n);
				show_list_student (a, n);
				press_any_key();
				break;
			case 16:
				printf ("\nChoice: 16. View all students\n");
				printf ("-----------------------------------------------------\n");
				show_list_student (a,n);
				press_any_key();
				printf ("\n");
				break;
			case 0:
				printf ("\nChoice: 0. Exit\n");
				printf ("-----------------------------------------------------\n");
				exit (0);
			default:
				printf ("\nInvalid! Please re-enter choice!\n");
				printf ("-----------------------------------------------------\n");
				press_any_key();
				break;
		}
	}
	return 0;
}
