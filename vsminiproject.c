#include <stdio.h>                                                                                                                                     
#include <stdlib.h>    
#include <string.h>

struct employee                                                                                                                                         
{                                                                                                                                                      
   char empid[100];
   char name[100];
   char age[3];
   char dept[100];
   char desig[100];
   char gender[3];
   char salary[100];                                                                                                                                 
};                                                                                                                                                     
                                                                                                                                                       
typedef struct employee empl; 

empl emp[1000];
int n;
                                                                                                                                                       
FILE *write(int num,FILE *a)                                                                                                          
{                                      
    if (a != NULL)
    {                                                                                                                
    for (int i=0 ; i<num ; i++)                                                                                                                    
    {                                                                                                                                              
        printf("Enter details of employee %d\n",i+1);                                                                                           
        printf("Enter the employee id : ");                                                                                                        
        scanf("%s",emp[i].empid);                                                                                                                 
        printf("Enter the name : ");                                                                                                           
        scanf("%s",emp[i].name);                                                                                                                 
        printf("Enter the age : ");                                                                                                            
        scanf("%s",emp[i].age); 
        printf("Enter the department : ");                                                                                                            
        scanf("%s",emp[i].dept); 
        printf("Enter the designation : ");                                                                                                            
        scanf("%s",emp[i].desig); 
        printf("Enter the gender : ");                                                                                                            
        scanf("%s",emp[i].gender); 
        printf("Enter the salary : ");                                                                                                            
        scanf("%s",emp[i].salary); 
        printf("\n");                                                                                                                                                                                                                                          
    }                                                                                                       
    if (a != NULL)                                                                                                                                 
    {                                                                                                                                              
        fprintf(a,"%s","\t\t\tEmployee records\t\t\t");                                                                                         
        for (int i=0 ; i<num ; i++)                                                                                                            
        {
            fprintf(a,"\n*Employee id : %s\n Employee Name : %s\n Employee Age : %s\n Employee Department : %s\n Employee Designation : %s\n Employee Gender : %s\n Employee Salary : %s\n",emp[i].empid,emp[i].name,emp[i].age,emp[i].dept,emp[i].desig,emp[i].gender,emp[i].salary);         
        }                                                                                                                                      
    }                                                                                                                                             
    return a;  
    }                                                                                                                                    
}
int number_of_records(FILE *a)                                                                                                                         
{                                                                                                                                                      
    int n=0 ;                                                                                                                                      
    char ch = getc(a);                                                                                                                             
    while (ch != EOF)                                                                                                                              
    {                                                                                                                                              
        if (ch == '*')                                                                                                                         
        {                                                                                                                                      
            n++;                                                                                                                           

        }                                                                                                                                      
        ch = getc(a);                                                                                                                          
    }                                                                                                                                              
    return n;                                                                                                                                      
}              

void delete(FILE *fp,char fn[])
{             
    fseek(fp,24,SEEK_SET);
   char data[100];
   empl search[10];
   int i=0,j=0;
   while(fgets(data,100,fp) != NULL)
   {
   char separator = ':';
   char *sep_at = strchr(data, separator);
   if(sep_at != NULL)
   {
      sep_at[strlen(sep_at)-1] = '\0';
   }
   if (j == 0)
   {
      strcpy(search[i].empid,sep_at+2);
   }
   else if(j==1)
   {
      strcpy(search[i].name,sep_at+2);
   }
   else if(j==2)
   {
      strcpy(search[i].age,sep_at+2);
   }
   else if(j==3)
   {
      strcpy(search[i].dept,sep_at+2);
   }
   else if(j==4)
   {
      strcpy(search[i].desig,sep_at+2);
   }
   else if(j==5)
   {
      strcpy(search[i].gender,sep_at+2);
   }
   else if(j==6)
   {
      strcpy(search[i].salary,sep_at+2);
   }
   j++;
   if (j == 7)
   {
      fseek(fp,2,SEEK_CUR);
      j=0;
      i++;
   }
   }         
   fclose(fp);
   fp = fopen(fn,"w");         
    char e[10];;
    printf("Enter employee id of employee to delete ");
    scanf("%s",e);
    fprintf(fp,"%s","\t\t\tEmployee records\t\t\t");
    for (int h=0 ; h<i ; h++)                                                                                                                               
    {    
        if (strcmp(search[h].empid,e) != 0)
        {                                                                                                                                                                                                                                                                                                                                             
            fprintf(fp,"\n*Employee id : %s\n Employee Name : %s\n Employee Age : %s\n Employee Department : %s\n Employee Designation : %s\n Employee Gender : %s\n Employee Salary : %d\n",search[h].empid,search[h].name,search[h].age,search[h].dept,search[h].desig,search[h].gender,search[h].salary);
        }
    }    
}
                                                                                                                                                       
void read(FILE *a)                                                                                                                                     
{                                                                                                                                                      
    char word[1000] ;                                                                                                                              
    while (fgets(word,1000,a))                                                                                                                     
    {                                                                                                                                              
        printf("%s",word);                                                                                                                     
    }                                                                                                                                              
}         

void add(FILE *a)
{
    int n;
    printf("Enter number of employees to add ");                                                                                           
    scanf("%d",&n);
    for (int i=0 ; i<n ; i++)
    {
        printf("Enter details of employee %d\n",i+1);                                                                                           
        printf("Enter the employee id : ");                                                                                                        
        scanf("%s",emp[i].empid);                                                                                                                 
        printf("Enter the name : ");                                                                                                           
        scanf("%s",emp[i].name);                                                                                                                 
        printf("Enter the age : ");                                                                                                            
        scanf("%s",emp[i].age); 
        printf("Enter the department : ");                                                                                                            
        scanf("%s",emp[i].dept); 
        printf("Enter the designation : ");                                                                                                            
        scanf("%s",emp[i].desig); 
        printf("Enter the gender : ");                                                                                                            
        scanf("%s",emp[i].gender); 
        printf("Enter the salary : ");                                                                                                            
        scanf("%s",emp[i].salary); 
        printf("\n");
    }
    if (a != NULL)                                                                                                                                 
    {                                                                                                                                                                                                                                       
        for (int i=0 ; i<n ; i++)                                                                                                            
        {
            fprintf(a,"\n*Employee id : %s\n Employee Name : %s\n Employee Age : %s\n Employee Department : %s\n Employee Designation : %s\n Employee Gender : %s\n Employee Salary : %s\n",emp[i].empid,emp[i].name,emp[i].age,emp[i].dept,emp[i].desig,emp[i].gender,emp[i].salary);          
        }                                                                                                                                      
    }                                                                                                                                              
}

void update(FILE *fp,char fn[])
{
    fseek(fp,24,SEEK_SET);
   char data[1000];
   empl search[10];
   int i=0,j=0;
   while(fgets(data,1000,fp) != NULL)
   {
   char separator = ':';
   char *sep_at = strchr(data, separator);
   if(sep_at != NULL)
   {
      sep_at[strlen(sep_at)-1] = '\0';
   }
   if (j == 0)
   {
      strcpy(search[i].empid,sep_at+2);
   }
   else if(j==1)
   {
      strcpy(search[i].name,sep_at+2);
   }
   else if(j==2)
   {
      strcpy(search[i].age,sep_at+2);
   }
   else if(j==3)
   {
      strcpy(search[i].dept,sep_at+2);
   }
   else if(j==4)
   {
      strcpy(search[i].desig,sep_at+2);
   }
   else if(j==5)
   {
      strcpy(search[i].gender,sep_at+2);
   }
   else if(j==6)
   {
      strcpy(search[i].salary,sep_at+2);
   }
   j++;
   if (j == 7)
   {
      fseek(fp,2,SEEK_CUR);
      j=0;
      i++;
   }
   }
   fclose(fp);
   fp = fopen(fn,"w");
    char k[20];
    printf("Enter empid of employee to update ");
    scanf("%s",k);
    int key;
    for (int h=0 ; h<i ; h++)
    {
        if (strcmp(search[h].empid,k) == 0)
        {
            key = h;
            break;
        }
    }
    printf("Enter 1 to change name\nEnter 2 to change age\nEnter 3 to change department\nEnter 4 to change designation\nEnter 5 to change salary\n");
    int o;
    printf("Enter your option ");
    scanf("%d",&o);
    if (o == 1)
    {
        char c[100];
        printf("Enter new name : ");
        scanf("%s",c);
        strcpy(search[key].name,c);
    }
    else if (o == 2)
    {
        char c[100];
        printf("Enter new age : ");
        scanf("%s",c);
        strcpy(search[key].age,c);
    }
    else if (o == 3)
    {
        char c[100];
        printf("Enter new department : ");
        scanf("%s",c);
        strcpy(search[key].dept,c);
    }
    else if (o == 4)
    {
        char c[100];
        printf("Enter new designation : ");
        scanf("%s",c);
        strcpy(search[key].desig,c);
    }
    else if (o == 5)
    {
        char c[100];
        printf("Enter new salary : ");
        scanf("%s",c);
        strcpy(search[key].salary,c);
    }
    fprintf(fp,"%s","\t\t\tEmployee records\t\t\t");                                                                                         
    for (int l=0 ; l<i ; l++)                                                                                                            
    {
        fprintf(fp,"\n*Employee id : %s\n Employee Name : %s\n Employee Age : %s\n Employee Department : %s\n Employee Designation : %s\n Employee Gender : %s\n Employee Salary : %s\n",search[l].empid,search[l].name,search[l].age,search[l].dept,search[l].desig,search[l].gender,search[l].salary);         
    }
}

void display(FILE *fp,int flag)
{
    fseek(fp,24,SEEK_SET);
   char data[100];
   empl search[10];
   int i=0,j=0;
   while(fgets(data,100,fp) != NULL)
   {
   char separator = ':';
   char *sep_at = strchr(data, separator);
   if(sep_at != NULL)
   {
      sep_at[strlen(sep_at)-1] = '\0';
   }
   if (j == 0)
   {
      strcpy(search[i].empid,sep_at+2);
   }
   else if(j==1)
   {
      strcpy(search[i].name,sep_at+2);
   }
   else if(j==2)
   {
      strcpy(search[i].age,sep_at+2);
   }
   else if(j==3)
   {
      strcpy(search[i].dept,sep_at+2);
   }
   else if(j==4)
   {
      strcpy(search[i].desig,sep_at+2);
   }
   else if(j==5)
   {
      strcpy(search[i].gender,sep_at+2);
   }
   else if(j==6)
   {
      strcpy(search[i].salary,sep_at+2);
   }
   j++;
   if (j == 7)
   {
      fseek(fp,2,SEEK_CUR);
      j=0;
      i++;
   }
   }
   int m=i;
    if (flag == 1)
    {
        char key[40];
        printf("Enter the department : ");
        scanf("%s",key);
        for (int i=0 ; i<m ; i++)
        {
            if (strcmp(search[i].dept , key) == 0)
            {
                printf("Employee id : %s",search[i].empid);
                printf("\nName : %s",search[i].name);
                printf("\nAge : %s",search[i].age);
                printf("\nDepartment : %s",search[i].dept);
                printf("\nDesignation : %s",search[i].desig);
                printf("\nGender : %s",search[i].gender);
                printf("\nSalary : %s",search[i].salary);
                printf("\n");
            }
        }
    }
    else if (flag == 2)
    {
        printf(" ");
        char key[40];
        printf("Enter the designation : ");
        scanf("%s",key);
        for (int i=0 ; i<m ; i++)
        {
            if (strcmp(search[i].desig , key) == 0)
            {
                printf("\nEmployee id : %s",search[i].empid);
                printf("\nName : %s",search[i].name);
                printf("\nAge : %s",search[i].age);
                printf("\nDepartment : %s",search[i].dept);
                printf("\nDesignation : %s",search[i].desig);
                printf("\nGender : %s",search[i].gender);
                printf("\nSalary : %s",search[i].salary);
            }
        }
    }
    else if (flag == 3)
    {
        printf(" ");
        for (int i=0 ; i<m ; i++)
        {
            if (strcmp(search[i].gender,"F") == 0)
            {
                printf("\nEmployee id : %s",search[i].empid);
                printf("\nName : %s",search[i].name);
                printf("\nAge : %s",search[i].age);
                printf("\nDepartment : %s",search[i].dept);
                printf("\nDesignation : %s",search[i].desig);
                printf("\nGender : %s",search[i].gender);
                printf("\nSalary : %s",search[i].salary);
            }
        }
    }
    else if (flag == 4)
    {
        printf(" ");
        for (int i=0 ; i<m ; i++)
        {
            if (strcmp(search[i].gender,"M") == 0)
            {
                printf("\nEmployee id : %s",search[i].empid);
                printf("\nName : %s",search[i].name);
                printf("\nAge : %s",search[i].age);
                printf("\nDepartment : %s",search[i].dept);
                printf("\nDesignation : %s",search[i].desig);
                printf("\nGender : %s",search[i].gender);
                printf("\nSalary : %s",search[i].salary);
            }
        }
    }
    else if (flag == 5)
    {
        printf(" ");
        for (int i=0 ; i<m ; i++)
        {
            printf("\nSalary of Employee %d is : %s",search[i].empid,search[i].salary);
        }
    }
    else if (flag == 6)
    {
        printf(" ");
        char key[100];
        printf("Enter the empid : ");
        scanf("%s",key);
        for (int i=0 ; i<m ; i++)
        {
            if (strcmp(search[i].empid,key) == 0)
            {
                printf("\nEmployee id : %s",search[i].empid);
                printf("\nName : %s",search[i].name);
                printf("\nAge : %s",search[i].age);
                printf("\nDepartment : %s",search[i].dept);
                printf("\nDesignation : %s",search[i].desig);
                printf("\nGender : %s",search[i].gender);
                printf("\nSalary : %s",search[i].salary);
                break;
            }
        }
    }
    else if (flag == 7)
    {
        printf(" ");
        for (int i=0 ; i<m ; i++)
        {
            for (int j=0 ; j<m-1 ; j++)
            {
                if (strcmp(search[j].salary,search[j+1].salary) > 0)
                {
                    char temp[100];
                    strcpy(temp,search[j].empid);
                    strcpy(search[j].empid,search[j+1].empid);
                    strcpy(search[j+1].empid,temp);
                    strcpy(temp,search[j].name);
                    strcpy(search[j].name,search[j+1].name);
                    strcpy(search[j+1].name,temp);
                    strcpy(temp,search[j].age);
                    strcpy(search[j].age,search[j+1].age);
                    strcpy(search[j+1].age,temp);
                    strcpy(temp,search[j].dept);
                    strcpy(search[j].dept,search[j+1].dept);
                    strcpy(search[j+1].dept,temp);
                    strcpy(temp,search[j].desig);
                    strcpy(search[j].desig,search[j+1].desig);
                    strcpy(search[j+1].desig,temp);
                    strcpy(temp,search[j].gender);
                    strcpy(search[j].gender,search[j+1].gender);
                    strcpy(search[j+1].gender,temp);
                    strcpy(temp,search[j].salary);
                    strcpy(search[j].salary,search[j+1].salary);
                    strcpy(search[j+1].salary,temp);
                }

            }
        }
        for (int i=0 ; i<m ; i++)
        {
            printf("\nEmployee id : %s",search[i].empid);
            printf("\nName : %s",search[i].name);
            printf("\nAge : %s",search[i].age);
            printf("\nDepartment : %s",search[i].dept);
            printf("\nDesignation : %s",search[i].desig);
            printf("\nGender : %s",search[i].gender);
            printf("\nSalary : %s",search[i].salary);
            
        }

    }
    else if (flag == 8)
    {
        for (int i=0 ; i<m ; i++)
        {
            for (int j=0 ; j<m-1 ; j++)
            {
                if (strcmp(search[j].name,search[j+1].name) > 0)
                {
                    char temp[100];
                    strcpy(temp,search[j].empid);
                    strcpy(search[j].empid,search[j+1].empid);
                    strcpy(search[j+1].empid,temp);
                    strcpy(temp,search[j].name);
                    strcpy(search[j].name,search[j+1].name);
                    strcpy(search[j+1].name,temp);
                    strcpy(temp,search[j].age);
                    strcpy(search[j].age,search[j+1].age);
                    strcpy(search[j+1].age,temp);
                    strcpy(temp,search[j].dept);
                    strcpy(search[j].dept,search[j+1].dept);
                    strcpy(search[j+1].dept,temp);
                    strcpy(temp,search[j].desig);
                    strcpy(search[j].desig,search[j+1].desig);
                    strcpy(search[j+1].desig,temp);
                    strcpy(temp,search[j].gender);
                    strcpy(search[j].gender,search[j+1].gender);
                    strcpy(search[j+1].gender,temp);
                    strcpy(temp,search[j].salary);
                    strcpy(search[j].salary,search[j+1].salary);
                    strcpy(search[j+1].salary,temp);
                }

            }
        }
        for (int i=0 ; i<m ; i++)
        {
            
            printf("\nEmployee id : %s",search[i].empid);
            printf("\nName : %s",search[i].name);
            printf("\nAge : %s",search[i].age);
            printf("\nDepartment : %s",search[i].dept);
            printf("\nDesignation : %s",search[i].desig);
            printf("\nGender : %s",search[i].gender);
            printf("\nSalary : %s",search[i].salary);
            
        }
    }
}
                                                                                                                                                       
int main()                                                                                                                                             
{                                                                                                                                                      
    printf("\n");                                                                                                                                  
    while (1)                                                                                                                                 
    {                
        printf("\n");                                                                                                                             
        FILE *fp;                                                                                                                                      
        char fname[30] ;                                                                                                                                                                                 
        printf("Enter 1 to create new file and write employee data records \nEnter 2 to count number of employee records\n");
        printf("Enter 3 to delete data records of employees\nEnter 4 to update employee records\n");
        printf("Enter 5 to display all employee records\nEnter 6 to add more employee details to existing file\n");
        printf("Enter 7 for particular queries\nEnter 8 to exit\n");                                                                                                                
        int opt;                                                                                                                                       
        printf("Enter you option ");                                                                                                                   
        scanf("%d",&opt);                                                                                                                              
        if (opt != 8)                                                                                                                                  
        {                                                                                                                                              
        printf("Enter file name : ");                                                                                                                  
        scanf("%s",fname);                                                                                                                             
        }
        if (opt == 1)
        {
            fp = fopen(fname,"w");                                                                                                         
            printf("Enter number of employees ");                                                                                          
            scanf("%d",&n);                                                                                                                
            fp = write(n,fp);                                                                                                          
            fclose(fp);                                                                                                                    
        }
        else if (opt == 2)
        {
            fp = fopen(fname,"r");
            printf("Number of record is %d\n ",number_of_records(fp));                                                                     
            fclose(fp); 
        }
        else if (opt == 3)
        {
            fp = fopen(fname,"r");
            delete(fp,fname);
            fclose(fp);
        }
        else if (opt == 4)
        {
            fp = fopen(fname,"r");
            update(fp,fname);
            fclose(fp);
        }
        else if (opt == 5)
        {
            fp = fopen(fname,"r");
            read(fp);
            fclose(fp);
        }
        else if (opt == 6)
        {
            fp = fopen(fname,"a");
            add(fp);
            fclose(fp);
        }
        else if (opt == 8)
        {
            exit(0);
        }
        else if (opt == 7)
        {
            printf("Enter 1 to display employee records belonging to a particular department\nEnter 2 to diplay employee records with particular designation\n");
            printf("Enter 3 to display all female employee details\nEnter 4 to display all male employees\n");
            printf("Enter 5 to display salary of all employee\nEnter 6 to display details of particular employee\n");
            printf("Enter 7 to display employees in order of salary\nEnter 8 to display employees in alphabetical order of names\n");
            int op;
            printf("Enter your option ");
            scanf("%d",&op);
            fp = fopen(fname,"r");
            display(fp,op);
            fclose(fp);
        }                                       
        else 
        {
            printf("Enter a valid option");
        }                                                                                 
    }        
    return 0;
}                 