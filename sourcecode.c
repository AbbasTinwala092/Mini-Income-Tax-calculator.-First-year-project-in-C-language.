#include<stdio.h>
#include<stdlib.h>

char fname[26];
int age;
double contact_no;
int occupation;
char company[50];
int gender;
int exempt1 = 250000; int exempt2 = 300000; int exempt3 = 500000;
int business_type;

double profit; double income;
double cashInHand; double taxable_amount; double salary;
double turnover; double tax; double cess;

void welcome()
{
    printf("-----------------------------------------------------------\n");
    printf("*-*-*-*Welcome to the mini tax calculating programme VIIT*-*-*-*\n");
    printf("-----------------------------------------------------------\n\n");
}

void tax_amount_business_1() //Function to calculate taxable amount for Self-Proprietor Business
{
    printf("\nEnter Total profit earned this year: ");
    scanf("%lf", &profit);

    printf("\nEnter Total profit earned through Cash: ");
    scanf("%lf", &cashInHand);

    taxable_amount = profit - cashInHand;
}

void tax_amount_business_2()  //Function to calculate taxable amount for Partnership Business
{
    printf("\nEnter this year's Turnover: ");
    scanf("%lf",&turnover);
    taxable_amount = turnover;
}

void tax_amount_business_3()  //Function to calculate taxable amount for Indian company
{
    printf("\nEnter this year's Turnover: ");
    scanf("%lf",&turnover);

    printf("\nEnter the profit: ");
    scanf("%lf",&profit);

    taxable_amount = profit;
}

void tax_amount_business_4()  //Function to calculate taxable amount for Foreign company
{
    printf("\nEnter this year's turnover: ");
    scanf("%lf", &turnover);

    printf("\nEnter profit earned: ");
    scanf("%lf", &profit);

    taxable_amount = profit;
}

void tax_amount_salaried()  //Function to calculate taxable amount for salaried people
{
    printf("\nEnter annual salary earned\n(Excluding all the allowances): ");
    scanf("%lf", &salary);

    printf("NO TAX SAVING OPTIONS AVAILABLE!");

    taxable_amount = salary;
}

void get_info() //Getting basic information of the user
{
    printf("Enter your Name: ");
    fgets(fname, 26, stdin);

    printf("\nEnter your age: ");
    scanf("%d", &age);

    printf("\nPlease select your gender:\n1. - MALE\n2. - FEMALE\n---> ");
    scanf("%d",&gender);

    printf("\nEnter your Contact Number: ");
    scanf("%lf",&contact_no);

    printf("\nEnter Occupation type:\n1. Business\n2. Salaried\n---> ");
    scanf("%d", &occupation);

    if(occupation==2)
    {
        printf("\nEnter the name of company you work in: \n--->");
        scanf("%s",&company);
        tax_amount_salaried();


    }
    else if(occupation==1)
    {
        printf("Enter the type of business: \n1. Sole-Proprietorship.\n2. Partnership Firm.\n3. Indian Company.\n4. Foreign Company.\n--->");
        scanf("%d",&business_type);
        
        switch (business_type)
        {
        case 1:
        {
            tax_amount_business_1();
            break;
        }
        case 2:
        {
            tax_amount_business_2();
            break;
        }
        case 3:
        {
            tax_amount_business_3();
            break;
        }
        case 4:
        {
            tax_amount_business_4();
            break;
        }
        }
        
    }
}

void tax_business()
{
    switch(business_type)
    {
        case 1:
        {
            printf("You won't be taxed for amount of 250000 RS\n");

            if(taxable_amount < 250000)
                tax = 0;
            else if(taxable_amount >= 250000 && taxable_amount < 500001)
                tax =( (taxable_amount - 250000)*0.05 );
            else if(taxable_amount>500000 && taxable_amount<1000001)
                tax = ( 250000*0.05 + (taxable_amount-500000)*0.20 );
            else if(taxable_amount > 1000000)
                tax = ( 250000*0.05 + 500000*0.20 + (taxable_amount - 1000000)*0.30 );

            break;
        }
        case 2:
        {
            tax = ( taxable_amount * 0.30 ) ;
            break;
        }
        case 3:
        {
            if(turnover < 500000001){
                tax = ( taxable_amount * 0.25 );
                break; }

            else if(turnover > 500000000){
                tax = ( taxable_amount * 0.30 );
                break; }
        }
        case 4:
        {
            tax =( taxable_amount * 0.40 );
            break;
        }

    }
}

void tax_salaried()
{
    if(age<60 && age>0)
    {
        
        printf("\nYou wont be taxed for the amount of %dRS\n", exempt1);
        
        if(taxable_amount < 250000)
            tax = 0;
        else if(taxable_amount >= 250000 && taxable_amount < 500001)
            tax =( (taxable_amount - 250000)*0.05 );
        else if(taxable_amount>500000 && taxable_amount<1000001)
            tax = ( 250000*0.05 + (taxable_amount-500000)*0.20 );
        else if(taxable_amount > 1000000)
            tax = ( 250000*0.05 + 500000*0.20 + (taxable_amount - 1000000)*0.30 );
        
        
    }

    if(age>=60 && age<80)
    {
        
        printf("\nYou wont be taxed for the amount of %dRS\n", exempt2);
        
        if(taxable_amount<300000)
            tax = 0;
        else if(taxable_amount>300000 && taxable_amount<500001)
            tax = (taxable_amount-300000)*0.05;
        else if(taxable_amount>500000 && taxable_amount<1000001)
            tax = 200000*0.05 + (taxable_amount-500000)*0.20;
        else if(taxable_amount > 1000000)
            tax =( 200000*0.05 + 500000*0.20 + (taxable_amount - 1000000)*0.30 );
        
    }

    if(age >= 80)
    {
        
        printf("\nYou wont be taxed for the amount of %dRS\n", exempt3);
        
        if(taxable_amount<exempt3)
            tax = 0;
        else if(taxable_amount>500000 && taxable_amount<1000001)
            tax =(taxable_amount-500000)*0.20;
        else if(taxable_amount > 1000000)
            tax =500000*0.20 + (taxable_amount - 1000000)*0.30;
        
    }
}

void cess_business()
{
    switch(business_type)
    {
        case 1:
        {
            cess = tax * 0.04;
            break;
        }
        case 2:
        {
            cess = tax * 0.02;
            break;
        }
        case 3: 
        {
            cess = tax * 0.02;
            break;
        }
        case 4: 
        {
            cess = tax * 0.04;
            break;
        }
    }
}

void cess_salaried()
{
    cess = tax * 0.04;
}

void store_info() //Create a file named "tax.txt" in the folder in which your .c file and .exe file is created. 
{
    FILE *ptr = NULL;
    ptr = fopen("tax.txt", "a");

    fprintf(ptr, "\n\n\n***Costumer Information***\n");
    fprintf(ptr, "Name: %s", fname);

    if(gender == 1)
    {
        fprintf(ptr, "Gender: Male\n");
    }
    else if(gender == 2)
    {
        fprintf(ptr, "Gender: Female\n");
    }
    else
    {
        fprintf(ptr, "Gender: Other\n");
    }
    fprintf(ptr, "Age: %d\n", age);
    fprintf(ptr, "Contact Number:+91 %.0lf\n", contact_no);

    if(age<60 && age>0)
    {
        fprintf(ptr, "Exempt Category: 1\n");
    }
    else if(age<80 && age>=60)
    {
        fprintf(ptr, "Exempt Category: 2\n");
    }
    else if(age>80)
    {
        fprintf(ptr, "Exempt Category: 3\n");
    }


    if(occupation==1)
    {
        fprintf(ptr, "Occupation: Business\n");
        if(business_type==1) {
            fprintf(ptr, "Business Type: Self-Proprietor\n");
            fprintf(ptr, "Profit: %.1lf\n", profit);
            fprintf(ptr, "Cash Earned: %.1lf\n", cashInHand);
            }
        if(business_type==2)
            {
                fprintf(ptr, "Business Type: Partnership Firm\n");
                fprintf(ptr, "Turnover: %.1lf\n", turnover);
            }
        if(business_type==3)
        {
            fprintf(ptr, "Business Type: Indian Company\n");
            fprintf(ptr, "Turnover: %.1lf\n", turnover);
            fprintf(ptr, "Profit: %.1lf\n", profit);
        }
        if(business_type==4)
        {
            fprintf(ptr, "Business Type: Foreign Company\n");
            fprintf(ptr, "Turnover: %.0lf\n", turnover);
            fprintf(ptr, "Profit: %.0lf\n", profit);
        }    
        
        fprintf(ptr, "Taxable amount: %.2lf\n", taxable_amount);
        
    }
    else if(occupation == 2)
    {
        fprintf(ptr, "Occupation: Salaried\n");
        fprintf(ptr, "Company: %s\n", company);
        fprintf(ptr, "Salary = Taxable amount: %.0lf\n", taxable_amount);
        

    }

    fprintf(ptr, "Tax Calculated: %.2lf\n", tax);
    fprintf(ptr, "Cess Calculated: %.2lf\n", cess);
    fprintf(ptr, "Total amount to be paid: %.2lf", tax + cess);

}

void end()
{
    printf("\nAfter overviewing all the values, the following details are calculated!\n\nCALCULATED SUCCESSFULLY!!!\n");

    printf("Tax to be paid--> %.2lf\n", tax);
    printf("Cess to be paid--> %.2lf\n", cess);
    printf("Total amount to  be paid--> %.2lf", tax + cess);
    printf("\n\n**Thank you for using our Mini Tax Calculator**\n\n");

}


void main()
{
    welcome();
    get_info();
    
    if(occupation==1)
        tax_business();

    else if(occupation==2)
        tax_salaried();

    if(occupation==1)
        cess_business();
    else if(occupation==2)
        cess_salaried();

    store_info();

    end();

}
