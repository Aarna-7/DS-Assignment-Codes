#include <stdio.h>
#include <string.h>

struct stud {
    int SrNo;
    char BookName[50];
    float Price;
};

void accept(struct stud s1[100],int n){
    for (int i=0;i<n;i++){
        printf("\nEnter the Sr. No. : ");
        scanf("%d",&s1[i].SrNo);
        printf("Enter the name of the book : ");
        scanf("%s",s1[i].BookName);
        printf("Enter the price:  ");
        scanf("%f",&s1[i].Price);
        printf("\n");
    }
}

void display(struct stud s1[100],int n){
    for (int i=0;i<n;i++){
        printf("\nBook No. : ");
        printf("%d",s1[i].SrNo);
        printf("\nName of the book is : ");
        printf("%s",s1[i].BookName);
        printf("\nThe price of the book is:  ");
        printf("%f",s1[i].Price);
        printf("\n");
    }
}

int linear_search(struct stud s1[100],int n,char elem[50]){
    int i=0;
    while (i<n) {
        if (strcmp(s1[i].BookName, elem)==0){
            return i;
        }
        i++;
    }
    return -1;
}

int binarysearch(struct stud s1[100],int n, int xyz){
    int l=0,h=n-1;
    while (l<=h){
        int m=((l+h)/2);
        if(s1[m].SrNo == xyz){
            return m;
        }
        else{
            if(s1[m].SrNo > xyz){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
    }
    if (l>h){
        return -1;
    }
}

void bubblesort(struct stud s1[100],int n){
    for (int j=0;j<n-1;j++){
        for (int k=0;k<n-j-1;k++){
            if(s1[k].Price > s1[k+1].Price){
                float c=s1[k].Price;
                s1[k].Price=s1[k+1].Price;
                s1[k+1].Price=c;
                int s=s1[k].SrNo;
                s1[k].SrNo=s1[k+1].SrNo;
                s1[k+1].SrNo=s;
                char d[50];
                strcpy(d,s1[k].BookName);
                strcpy(s1[k].BookName, s1[k+1].BookName);
                strcpy(s1[k+1].BookName, d);
            }
        }
    }
}

//Selection Sort
void selection_sort(struct stud s1[100],int n){
    for (int i=0;i<n-1;i++){
        int min=s1[i].SrNo,idx=i;
        for (int j=i+1;j<n;j++){
            if (s1[j].SrNo<min){
                min=s1[j].SrNo;
                idx=j;}
            }
        int temp=s1[i].SrNo;
        s1[i].SrNo=s1[idx].SrNo;
        s1[idx].SrNo=temp; 
        char d[50];
        strcpy(d,s1[i].BookName);
        strcpy(s1[i].BookName, s1[idx].BookName);
        strcpy(s1[idx].BookName, d);
        float c=s1[i].Price;
        s1[i].Price=s1[idx].Price;
        s1[idx].Price=c;
        }
    }

//Insertion Sort
void insertion_sort(struct stud s1[100],int n){
    for(int i=1;i<n;i++){
      float key=s1[i].Price;
      char x[50];
      strcpy(x,s1[i].BookName);
      int key_no=s1[i].SrNo;
      int j=i-1;
      while (j>=0 && s1[j].Price>key){
        s1[j+1].Price = s1[j].Price;
        s1[j+1].SrNo=s1[j].SrNo;
        strcpy(s1[j+1].BookName,s1[j].BookName);
        j=j-1;
      }
      s1[j+1].Price = key;
      strcpy(s1[j+1].BookName,x);
      s1[j+1].SrNo=key_no;
    }
}

//Shell Sort
void shell_sort(struct stud s1[100],int n){
    int gap=n/2,swap=0;
    while (gap>0){
        do {
            swap=0;
            int i=0;
            while(i<n-gap){
                if (s1[i].SrNo>s1[i+gap].SrNo){
                    float c=s1[i].Price;
                    s1[i].Price=s1[i+gap].Price;
                    s1[i+gap].Price=c;
                    int s=s1[i].SrNo;
                    s1[i].SrNo=s1[i+gap].SrNo;
                    s1[i+gap].SrNo=s;
                    char d[50];
                    strcpy(d,s1[i].BookName);
                    strcpy(s1[i].BookName, s1[i+gap].BookName);
                    strcpy(s1[i+gap].BookName, d);
                    swap=1;
                }
                i++;
            }
        }while (swap==1);
        gap=gap/2;
    }
}

int main(){
    struct stud s[100];
    int n=0,y,k,xyz;
    char e[50];
    int flag=1;
    while (flag==1){
        printf("\nPlease select the required operation:\n");
        printf("1.Accept\n2.Display\n3.Search\n4.Sort\n5.Exit\n");
        scanf("%d",&y);
        switch(y) {
            case 1: {
                printf("Enter the number of records: ");
                scanf("%d",&n);
                accept(s,n);
                break;}
            case 2: {
                printf("All the entered records are: ");
                display(s,n);  
                break;}
            case 3: {
                printf("\nPlease select the type of search operation:\n");
                printf("1.Linear Search\n2.Binary Search\n");
                scanf("%d",&k);
                switch(k){
                    case 1:{
                        printf("\nEnter the book name to be searched for: ");
                        scanf("%s",e);
                        int x=linear_search(s,n,e);
                        if (x==-1){
                            printf("Record not found.\n");}
                        else{
                            printf("\nRecord found. \nThe Sr No is: %d",s[x].SrNo);
                            printf("\nThe name is: %s",s[x].BookName);
                            printf("\nThe price is: %f",s[x].Price);
                            printf("\n");}
                        break;
                        }
                    case 2: {
                        selection_sort(s,n);
                        printf("\nEnter the serial number of the book to be searched for: ");
                        scanf("%d",&xyz);
                        int x=binarysearch(s,n,xyz);
                        if (x==-1){
                            printf("Record not found.\n");
                        }
                        else{
                            printf("\nRecord found. \nThe Sr No is: %d",s[x].SrNo);
                            printf("\nThe name is: %s",s[x].BookName);
                            printf("\nThe price is: %f",s[x].Price);
                            printf("\n");}
                        break;
                        }
                    default: printf("Invalid Choice.");
                    }
                break;}
            case 4:{
                printf("\nPlease select the type of sorting operation:\n");
                printf("1.Bubble Sort (Sorts Price)\n2.Selection Sort (Sorts Sr No)\n3.Insertion Sort (Sorts Price)\n4.Shell Sort(Sorts Sr No)\n");
                scanf("%d",&k);
                switch(k){
                    case 1:{
                        printf("The records after sorting in the ascending order of the price is: ");
                        bubblesort(s,n);
                        display(s,n); 
                        break;
                    }
                    case 2:{
                        printf("The records after sorting in the ascending order of the Sr No is: ");
                        selection_sort(s,n);
                        display(s,n); 
                        break;
                    }
                    case 3:{
                        printf("The records after sorting in the ascending order of the price is: ");
                        insertion_sort(s,n);
                        display(s,n); 
                        break;
                    }
                    case 4:{
                        printf("The records after sorting in the ascending order of the Sr No is: ");
                        shell_sort(s,n);
                        display(s,n); 
                        break;
                    }
                    default: printf("Invalid Choice.");
                }
                break;
            }
            case 5: flag=0;
                    break;
            default: printf("Invalid Choice.");
        }
    }
    return 0;
}
