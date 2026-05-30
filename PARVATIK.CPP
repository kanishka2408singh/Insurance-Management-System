#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


class Admin {
public:
void login() {
int id;
char pass[20];
char correct[20] = "kanishka";
int success = 0;

for (int attempts = 1; attempts <= 3; attempts++) {
clrscr();
cout << "\n\t\t************************************************";
cout << "\n\t\t*                                              *";
cout << "\n\t\t*             ADMIN LOGIN PORTAL               *";
cout << "\n\t\t*                                              *";
cout << "\n\t\t************************************************\n";
cout << "\n\t\tAttempt " << attempts << " of 3\n";
cout << "\t\tEnter Admin ID (4-digit)        : ";
cin >> id;

if (id < 1000 || id > 9999) {
cout << "\t\ Invalid ID! Must be 4-digit number.\n";
getch();
continue;
}
int show = 0;
cout << "\n\t\tPress 1 to show password while typing, or any other key to hide: ";
show = getch();
cout << "\n\t\tEnter Admin Password (8 letters): ";
int i = 0;
char ch;
while (i < 8) {
ch = getch();
if (ch == 13)
break;
if (ch == 8 && i > 0) {
cout << "\b \b";
i--;
}
else if (ch >= 32 && ch <= 126 && i < 8) {
pass[i] = ch;
if (show == '1')
cout << ch;
else
cout << "*";
i++;
}
}
pass[i] = '\0';
if (strlen(pass) != 8) {
cout << "\n\t\t Password must be exactly 8 letters!\n";
getch();
continue;
}

if (id == 2408 && strcmp(pass, correct) == 0) {
cout << "\n\n\t\t Login Successful!\n";
getch();            
clrscr();           
success = 1;
break;
}

else {
cout << "\n\t\t Incorrect ID or Password!";
if (attempts < 3)
cout << " Try again.";
getch();
}
}
if (!success) {
clrscr();
cout << "\n\n\t\t Too many failed attempts. Exiting system...";
getch();
exit(0);
}
}
};



class Customer
{
public:
int id;
char name[30];
int age;
char contact[15];
char date[15];


void input() {
cout << "\n\nAdd Customer Record";

cout << "\n\nEnter Customer ID: ";
while (!(cin >> id) || id <= 0) {
cout << "\n Invalid ID!   \n\nEnter positive number: ";
cin.clear();
cin.ignore(1000, '\n');
}

cin.ignore();
do {
cout << "\nEnter Name: ";
cin.getline(name, 30);
if (strlen(name) == 0)
cout << "\nName cannot be empty!\n";
} while (strlen(name) == 0);

cout << "\nEnter Age: ";
while (!(cin >> age) || age <= 0 || age > 120) {
cout << " \nInvalid Age! \n\n Enter between 1 to 120: ";
cin.clear();
cin.ignore(1000, '\n');
}

cin.ignore();
do {
cout << "\nEnter Contact No.:";
cin.getline(contact, 15);
if (strlen(contact) != 10)
cout << " Must be 10 digits!\n";
} while (strlen(contact) != 10);

do {
cout << "\nEnter Date (dd-mm-yyyy): ";
cin.getline(date, 15);
if (strlen(date) != 10)
cout << " Enter 10-char date!\n";
} while (strlen(date) != 10);
}


void show()
{
cout<<"\n\nCustomer ID : "<<id;
cout<<"\nName : "<<name;
cout<<"\nAge : "<<age;
cout<<"\nContact No. : "<<contact;
cout<<"\nRegistration Date : "<<date;
}

};


class Plan
{
public:
int pid;
int cid;
char pname[30];
float premium;
int duration;
float coverage;
char date[15];

void input() {

cout << "\n\nEnter Plan ID: ";
while (!(cin >> pid) || pid <= 0) {
cout << "\n Invalid Plan ID! \n\nTry again: ";
cin.clear();
cin.ignore(1000, '\n');
}
cin.ignore();

do {
cout << "\nEnter Plan Name: ";
cin.getline(pname, 30);
if (strlen(pname) == 0)
cout << "\nPlan name cannot be empty!\n";
} while (strlen(pname) == 0);

cout << "\nEnter Premium Amount: ";
while (!(cin >> premium) || premium <= 0) {
cout << "\n Invalid Premium! \n\nTry again: ";
cin.clear();
cin.ignore(1000, '\n');
}

cout << "\nEnter Duration (in years): ";
while (!(cin >> duration) || duration <= 0) {
cout << "\n Invalid Duration! \n\nTry again: ";
cin.clear();
cin.ignore(1000, '\n');
}

cout << "\nEnter Coverage Amount: ";
while (!(cin >> coverage) || coverage <= 0) {
cout << "\n Invalid Coverage! \n\nTry again: ";
cin.clear();
cin.ignore(1000, '\n');
}
cin.ignore();

do {
cout << "\nEnter Plan Date (dd-mm-yyyy): ";
cin.getline(date, 15);
if (strlen(date) != 10)
cout << "\n Enter 10-char date!\n";
} while (strlen(date) != 10);
}



void show()
{
cout<<"\n\nCustomer ID : "<<cid;
cout<<"\nPlan ID : "<<pid;
cout<<"\nPlan Name : "<<pname;
cout<<"\nPremium : "<<premium;
cout<<"\nDuration : "<<duration<<" years";
cout<<"\nCoverage : "<<coverage;
cout<<"\nStart Date : "<<date;
}

};


class Payment
{
public:
int cid;
float amount;
char status[10];
char date[15];

void input() {

cout << "\n\nEnter Customer ID for Payment: ";
while (!(cin >> cid) || cid <= 0) {
cout << " \nInvalid ID! \n\nTry again: ";
cin.clear();
cin.ignore(1000, '\n');
}

char ch;
cout << "\n\nDo you want to make payment? (y/n): ";
cin >> ch;

if (ch == 'y' || ch == 'Y') {
cout << "\nEnter Payment Amount: ";
while (!(cin >> amount) || amount <= 0) {
cout << "\n Invalid Amount!\n\n Try again: ";
cin.clear();
cin.ignore(1000, '\n');
}
strcpy(status, "Complete");
} else {
amount = 0;
strcpy(status, "Pending");
}

cin.ignore();

do {
cout << "\nEnter Payment Date (dd-mm-yyyy): ";
cin.getline(date, 15);
if (strlen(date) != 10)
cout << "\n Enter 10-char date!\n";
} while (strlen(date) != 10);
}


void show()
{
cout<<"\n\nCustomer ID : "<<cid;
cout<<"\nPayment Date : "<<date;

cout<<"\nPayment Status : "<<status;
cout<<"\nAmount Paid : Rs. "<<amount;
}

};



class Agent
{
public:
int cid;
char name[30];
char contact[15];

void input() {

cout << "\n\nEnter Customer ID: ";
while (!(cin >> cid) || cid <= 0) {
cout << " \nInvalid ID!\n\n Try again: ";
cin.clear();
cin.ignore(1000, '\n');
}

cin.ignore();
do {
cout << "\nEnter Agent Name: ";
cin.getline(name, 30);
if (strlen(name) == 0)
cout << "\nName cannot be empty!\n";
} while (strlen(name) == 0);

do {
cout << "\nEnter Agent Contact No.: ";
cin.getline(contact, 15);
if (strlen(contact) != 10)
cout << " Must be 10 digits!\n";
} while (strlen(contact) != 10);

}


void show()
{
cout<<"\n\nCustomer ID : "<<cid;
cout<<"\nAgent Name : "<<name;
cout<<"\nContact No. : "<<contact;
}

};



class Nominee
{
public:
int cid;
char name[30];
int age;
char relation[20];
char contact[15];



void input() {

cout << "\n\nEnter Customer ID: ";
while (!(cin >> cid) || cid <= 0) {
cout << " \nInvalid ID! \n\nTry again: ";
cin.clear();
cin.ignore(1000, '\n');
}

cin.ignore();
do {
cout << "\nEnter Nominee Name: ";
cin.getline(name, 30);
if (strlen(name) == 0)
cout << "\nName cannot be empty!\n";
} while (strlen(name) == 0);

cout << "\nEnter Nominee Age: ";
while (!(cin >> age) || age <= 0 || age > 120) {
cout << " Invalid Age! \n\nEnter between 1-120: ";
cin.clear();
cin.ignore(1000, '\n');
}

cin.ignore();
do {
cout << "\nEnter Relation with Customer: ";
cin.getline(relation, 20);
if (strlen(relation) == 0)
cout << "\nRelation cannot be empty!\n";
} while (strlen(relation) == 0);


do {
cout << "\nEnter Nomimee Contact No.: ";
cin.getline(contact, 15);
if (strlen(contact) != 10)
cout << " \nMust be 10 digits!\n";
} while (strlen(contact) != 10);

}


void show()
{
cout<<"\n\nCustomer ID : "<<cid;
cout<<"\nNominee Name : "<<name;
cout<<"\nNominee Age : "<<age;
cout<<"\nRelation : "<<relation;
cout<<"\nContact No. : "<<contact;
}

};




class Insurance
{
public:
Customer c;
Plan p;
Payment pay;
Agent a;
Nominee n;


void addCustomer() {
Customer c;
int duplicate;
do {
duplicate = 0;
cout<<"\n\n=== Add New Customer ===";
cout<<"\n\nEnter Customer ID: ";
cin>>c.id;
ifstream f("customer.txt",ios::binary);
Customer temp;
while(f.read((char*)&temp,sizeof(temp))) {
if(temp.id == c.id) {
duplicate = 1;
cout<<"\nCustomer ID already exists! Please enter a unique ID.\n";
break;
}
}
f.close();
} while(duplicate == 1);
cin.ignore();
c.input();
ofstream f2("customer.txt",ios::app|ios::binary);
f2.write((char*)&c,sizeof(c));
f2.close();
cout<<"\nCustomer Added Successfully!";
getch();
clrscr();
}



void viewCustomer()
{
Customer c;
int id,found=0;
ifstream f("customer.txt",ios::binary);
cout<<"\n\nEnter Customer ID to view: ";
cin>>id;
while(f.read((char*)&c,sizeof(c)))
{
if(c.id==id)
{
c.show();
found=1;
}
}
f.close();
if(found==0)
{
cout<<"\n\nCustomer not found.";
}
}


void searchCustomer()
{
Customer c;
int id,found=0;
ifstream f("customer.txt",ios::binary);
cout<<"\n\nEnter Customer ID to search: ";
cin>>id;
while(f.read((char*)&c,sizeof(c)))
{
if(c.id==id)
{
cout<<"\n\nCustomer Found:\n";
c.show();
found=1;
break;
}
}
f.close();
if(found==0)
{
cout<<"\n\nCustomer not found.";
}
}


void updateCustomer() {
Customer c;
int id, found = 0, duplicate = 0;
cout << "\n\nEnter Customer ID to update: ";
cin >> id;
ifstream f("customer.txt", ios::binary);
ofstream t("temp.txt", ios::binary);
Customer temp;
while (f.read((char*)&c, sizeof(c))) {
if (c.id == id) {
found = 1;
Customer updated;
cout << "\n\nEnter New Customer ID: ";
while (!(cin >> updated.id) || updated.id <= 0) {
cout << "Invalid ID! Try again: ";
cin.clear(); cin.ignore(1000, '\n');
}
ifstream check("customer.txt", ios::binary);
Customer checkC;
while (check.read((char*)&checkC, sizeof(checkC))) {
if (checkC.id == updated.id && checkC.id != id) {
duplicate = 1;
break;
}
}
check.close();
if (duplicate) {
cout << "\n\nThis Customer ID already exists! Update aborted.\n";
t.write((char*)&c, sizeof(c));
continue;
}
cin.ignore();
do {
cout << "\n\nEnter Name: ";
cin.getline(updated.name, 30);
} while (strlen(updated.name) == 0);
cout << "\n\nEnter Age: ";
while (!(cin >> updated.age) || updated.age <= 0 || updated.age > 120) {
cout << "\nInvalid Age! Enter between 1-120: ";
cin.clear(); cin.ignore(1000, '\n');
}
cin.ignore();
do {
cout << "\n\nEnter Contact: ";
cin.getline(updated.contact, 15);
} while (strlen(updated.contact) != 10);
do {
cout << "\n\nEnter Registration Date (dd-mm-yyyy): ";
cin.getline(updated.date, 15);
} while (strlen(updated.date) != 10);
t.write((char*)&updated, sizeof(updated));
} else {
t.write((char*)&c, sizeof(c));
}
}
f.close();
t.close();
remove("customer.txt");
rename("temp.txt", "customer.txt");
if (!found) 
cout << "\n\nCustomer ID not found.";
else if (!duplicate) 
cout << "\n\nCustomer updated successfully!";
getch();
clrscr();
}



void deleteCustomer() {
Customer c;
int id,found=0;
cout<<"\n\nEnter Customer ID to delete: ";
cin>>id;
ifstream f("customer.txt",ios::binary);
ofstream t("temp.txt",ios::binary);
while(f.read((char*)&c,sizeof(c))) {
if(c.id!=id) {
t.write((char*)&c,sizeof(c));
} else {
found=1;
}
}
f.close();
t.close();
remove("customer.txt");
rename("temp.txt","customer.txt");
if(found==0) {
cout<<"\n\nCustomer not found.";
} else {
cout<<"\n\nCustomer deleted successfully!";
}
getch();
clrscr();
}



void viewCustomerByDate()
{
Customer c;
char d[15];
int found=0;
cout<<"\nEnter Date (dd-mm-yyyy) to search customers: ";
cin.ignore();
cin.getline(d,15);
ifstream f("customer.txt",ios::binary);
while(f.read((char*)&c,sizeof(c)))
{
if(strcmp(c.date,d)==0)
{
c.show();
found=1;
}
}
f.close();
if(found==0)
{
cout<<"\nNo customers found for this date.";
}
}



void addPlan() {
Plan p;
ofstream f("plan.txt", ios::app | ios::binary);
int duplicate = 0;
int cid;
cout << "\n\nEnter Customer ID to link this plan: ";
while (!(cin >> cid) || cid <= 0) {
cout << "\n\nInvalid Customer ID! Try again: ";
cin.clear();
cin.ignore(1000, '\n');
}
p.cid = cid;
do {
cin.ignore();
p.input(); // input me cid ka input nahi hoga
Plan temp;
ifstream fin("plan.txt", ios::binary);
while(fin.read((char*)&temp, sizeof(temp))) {
if(temp.cid == p.cid && temp.pid == p.pid) {
duplicate = 1;
break;
}
}
fin.close();
if(duplicate) {
cout << "\nPlan already exists with same Plan ID for this customer!";
cout << "\nPlease re-enter details.\n";
duplicate = 0;
} else {
break;
}
} while(1);
f.write((char*)&p, sizeof(p));
f.close();
cout << "\n Plan added successfully!";
getch();
clrscr();
}



void viewPlan() {
int id, found = 0, count = 0;
cout << "\n\nEnter Customer ID to view all plans: ";
cin >> id;
Plan p;
ifstream fin("plan.txt", ios::binary);
while(fin.read((char*)&p, sizeof(p))) {
if(p.cid == id) {
p.show();
found = 1;
count++;
if(count % 2 == 0) {
cout << "\n\n(Press any key to view next...)";
getch();
clrscr();
}
}
}
fin.close();
if(found == 0) {
cout << "\n No plans found for this Customer ID!";
}
cout << "\n\n(Press any key to continue...)";
getch();
clrscr();
}



void searchPlan() {
int cid, pid, found = 0;
cout << "\n\nEnter Customer ID: ";
cin >> cid;
cout << "\n\nEnter Plan ID to search: ";
cin >> pid;
Plan p;
ifstream fin("plan.txt", ios::binary);
while(fin.read((char*)&p, sizeof(p))) {
if(p.cid == cid && p.pid == pid) {
cout << "\n Plan Found:\n";
p.show();
found = 1;
break;
}
}
fin.close();
if(found == 0) {
cout << "\n Plan not found!";
}
getch();
clrscr();
}



void updatePlan() {
int cid, pid, found = 0;
cout << "\n\nEnter Customer ID: ";
cin >> cid;
cout << "\n\nEnter Plan ID to update: ";
cin >> pid;
Plan p, newp;
ifstream fin("plan.txt", ios::binary);
ofstream fout("temp.txt", ios::binary);
while(fin.read((char*)&p, sizeof(p))) {
if(p.cid == cid && p.pid == pid) {
cout << "\n\nEnter new details for the plan:\n";
newp.cid = cid;
cin.ignore();
newp.input();
fout.write((char*)&newp, sizeof(newp));
found = 1;
} else {
fout.write((char*)&p, sizeof(p));
}
}
fin.close();
fout.close();
remove("plan.txt");
rename("temp.txt", "plan.txt");
if(found == 0){
cout << "\n\n Plan not found or update failed!";
}else {
cout << "\n\n Plan updated successfully!";
}
getch();
clrscr();
}



void deletePlan() {
int cid, pid, found = 0;
cout << "\n\nEnter Customer ID: ";
cin >> cid;
cout << "\n\nEnter Plan ID to delete: ";
cin >> pid;
Plan p;
ifstream fin("plan.txt", ios::binary);
ofstream fout("temp.txt", ios::binary);
while(fin.read((char*)&p, sizeof(p))) {
if(p.cid == cid && p.pid == pid) {
found = 1;
continue;
}
fout.write((char*)&p, sizeof(p));
}
fin.close();
fout.close();
remove("plan.txt");
rename("temp.txt", "plan.txt");
if(found == 0) {
cout << "\nPlan not found!";
} else {
cout << "\nPlan deleted successfully!";
}
getch();
clrscr();
}





void addPayment()
{
ofstream f("payment.txt",ios::app|ios::binary);
Payment pay;
pay.input();
f.write((char*)&pay,sizeof(pay));
f.close();
}


void viewPayment()
{
Payment pay;
int id,found=0;
ifstream f("payment.txt",ios::binary);
cout<<"\n\nEnter Customer ID to view payment: ";
cin>>id;
while(f.read((char*)&pay,sizeof(pay)))
{
if(pay.cid==id)
{
pay.show();
found=1;
}
}
f.close();
if(found==0)
{
cout<<"\n\nNo payment found.";
}
}


void searchPayment()
{
Payment pay;
int id,found=0;
ifstream f("payment.txt",ios::binary);
cout<<"\n\nEnter Customer ID to search payment: ";
cin>>id;
while(f.read((char*)&pay,sizeof(pay)))
{
if(pay.cid==id)
{
cout<<"\n\nPayment Found:\n";
pay.show();
found=1;
break;
}
}
f.close();
if(found==0)
{
cout<<"\n\nPayment not found.";
}
}


void updatePayment()
{
Payment pay;
int id,found=0;
cout<<"\n\nEnter Customer ID to update payment: ";
cin>>id;
ifstream f("payment.txt",ios::binary);
ofstream t("temp.txt",ios::binary);
while(f.read((char*)&pay,sizeof(pay)))
{
if(pay.cid==id)
{
pay.input();
found=1;
}
t.write((char*)&pay,sizeof(pay));
}
f.close();
t.close();
remove("payment.txt");
rename("temp.txt","payment.txt");
if(found==0)
{
cout<<"\n\nPayment not found.";
}
else
{
cout<<"\n\nPayment updated successfully!";
}
}


void deletePayment() {
Payment pay;
int id,found=0;
cout<<"\n\nEnter Customer ID to delete payment: ";
cin>>id;
ifstream f("payment.txt",ios::binary);
ofstream t("temp.txt",ios::binary);
while(f.read((char*)&pay,sizeof(pay))) {
if(pay.cid!=id) {
t.write((char*)&pay,sizeof(pay));
} else {
found=1;
}
}
f.close();
t.close();
remove("payment.txt");
rename("temp.txt","payment.txt");
if(found==0) {
cout<<"\n\nPayment not found.";
} else {
cout<<"\n\nPayment deleted successfully!";
}
getch();
clrscr();
}



void viewPaymentByDate()
{
Payment pay;
char d[15];
int found=0;
cout<<"\n\nEnter Payment Date (dd-mm-yyyy): ";
cin.ignore();
cin.getline(d,15);
ifstream f("payment.txt",ios::binary);
while(f.read((char*)&pay,sizeof(pay)))
{
if(strcmp(pay.date,d)==0)
{
pay.show();
found=1;
}
}
f.close();
if(found==0)
{
cout<<"\n\nNo payments found for this date.";
}
}



void addAgent()
{
ofstream f("agent.txt",ios::app|ios::binary);
Agent a;
a.input();
f.write((char*)&a,sizeof(a));
f.close();
}

void viewAgent()
{
Agent a;
int id,found=0;
ifstream f("agent.txt",ios::binary);
cout<<"\n\nEnter Customer ID to view agent: ";
cin>>id;
while(f.read((char*)&a,sizeof(a)))
{
if(a.cid==id)
{
a.show();
found=1;
}
}
f.close();
if(found==0)
{
cout<<"\n\nNo agent found.";
}
}


void searchAgent()
{
Agent a;
int id,found=0;
ifstream f("agent.txt",ios::binary);
cout<<"\n\nEnter Customer ID to search agent: ";
cin>>id;
while(f.read((char*)&a,sizeof(a)))
{
if(a.cid==id)
{
cout<<"\n\nAgent Found:\n";
a.show();
found=1;
break;
}
}
f.close();
if(found==0)
{
cout<<"\n\nAgent not found.";
}
}


void updateAgent()
{
Agent a;
int id,found=0;
cout<<"\n\nEnter Customer ID to update agent: ";
cin>>id;
ifstream f("agent.txt",ios::binary);
ofstream t("temp.txt",ios::binary);
while(f.read((char*)&a,sizeof(a)))
{
if(a.cid==id)
{
a.input();
found=1;
}
t.write((char*)&a,sizeof(a));
}
f.close();
t.close();
remove("agent.txt");
rename("temp.txt","agent.txt");

if(found==0)
{
cout<<"\n\nAgent not found.";
}
else
{
cout<<"\n\nAgent updated successfully!";
}
}


void deleteAgent() {
Agent a;
int id,found=0;
cout<<"\n\nEnter Customer ID to delete agent: ";
cin>>id;
ifstream f("agent.txt",ios::binary);
ofstream t("temp.txt",ios::binary);
while(f.read((char*)&a,sizeof(a))) {
if(a.cid!=id) {
t.write((char*)&a,sizeof(a));
} else {
found=1;
}
}
f.close();
t.close();
remove("agent.txt");
rename("temp.txt","agent.txt");
if(found==0) {
cout<<"\n\nAgent not found.";
} else {
cout<<"\n\nAgent deleted successfully!";
}
getch();
clrscr();
}



void addNominee()
{
ofstream f("nominee.txt",ios::app|ios::binary);
Nominee n;
n.input();
f.write((char*)&n,sizeof(n));
f.close();
}

void viewNominee()
{
Nominee n;
int id,found=0;
ifstream f("nominee.txt",ios::binary);
cout<<"\n\nEnter Customer ID to view nominee: ";
cin>>id;
while(f.read((char*)&n,sizeof(n)))
{
if(n.cid==id)
{
n.show();
found=1;
}
}
f.close();
if(found==0)
{
cout<<"\n\nNo nominee found.";
}
}


void searchNominee()
{
Nominee n;
int id,found=0;
ifstream f("nominee.txt",ios::binary);
cout<<"\n\nEnter Customer ID to search nominee: ";
cin>>id;
while(f.read((char*)&n,sizeof(n)))
{
if(n.cid==id)
{
cout<<"\n\nNominee Found:\n";
n.show();
found=1;
break;
}
}
f.close();
if(found==0)
{
cout<<"\n\nNominee not found.";
}
}


void updateNominee()
{
Nominee n;
int id,found=0;
cout<<"\n\nEnter Customer ID to update nominee: ";
cin>>id;
ifstream f("nominee.txt",ios::binary);
ofstream t("temp.txt",ios::binary);
while(f.read((char*)&n,sizeof(n)))
{
if(n.cid==id)
{
n.input();
found=1;
}
t.write((char*)&n,sizeof(n));
}
f.close();
t.close();
remove("nominee.txt");
rename("temp.txt","nominee.txt");
if(found==0)
{
cout<<"\n\nNominee not found.";
}
}


void deleteNominee() {
Nominee n;
int id,found=0;
cout<<"\n\nEnter Customer ID to delete nominee: ";
cin>>id;
ifstream f("nominee.txt",ios::binary);
ofstream t("temp.txt",ios::binary);
while(f.read((char*)&n,sizeof(n))) {
if(n.cid!=id) {
t.write((char*)&n,sizeof(n));
} else {
found=1;
}
}
f.close();
t.close();
remove("nominee.txt");
rename("temp.txt","nominee.txt");
if(found==0) {
cout<<"\n\nNominee not found.";
} else {
cout<<"\n\nNominee deleted successfully!"; // 🔥 Fixed message
}
getch();
clrscr();
}


};






class PlanInfo
{
public:


void showInfo() {
clrscr();

cout << "\n\t========== PREDEFINED INSURANCE PLANS ==========\n";

cout << "\n\t[1] Health Protect Plan";
cout << "\n\t- Covers medical expenses";
cout << "\n\t- Premium   : Rs. 3000 / year";
cout << "\n\t- Duration  : 5 years";
cout << "\n\t- Coverage  : Rs. 5,00,000";

cout << "\n\n\t[2] Life Secure Plan";
cout << "\n\t- Life cover for family";
cout << "\n\t- Premium   : Rs. 4500 / year";
cout << "\n\t- Duration  : 10 years";
cout << "\n\t- Coverage  : Rs. 10,00,000";

cout << "\n\n\t(Press any key to continue...)";
getch();
clrscr();

cout << "\n\t========== PREDEFINED INSURANCE PLANS (Cont.) ==========\n";

cout << "\n\t[3] Vehicle Protect Plan";
cout << "\n\t- Covers accidental vehicle damage";
cout << "\n\t- Premium   : Rs. 2500 / year";
cout << "\n\t- Duration  : 3 years";
cout << "\n\t- Coverage  : Rs. 3,00,000";

cout << "\n\n\t[4] Property Cover Plan";
cout << "\n\t- Covers disaster damage to property";
cout << "\n\t- Premium   : Rs. 3500 / year";
cout << "\n\t- Duration  : 7 years";
cout << "\n\t- Coverage  : Rs. 7,50,000";

cout << "\n\n\t(Press any key to show your custom plans...)";
getch();

viewAllCustomPlans();
}





void addCustomPlan()
{
Plan p;
ofstream f("customplans.txt", ios::app|ios::binary);
cout<<"\n\nEnter Plan ID       : ";
cin>>p.pid;
cin.ignore();
cout<<"\n\nEnter Plan Name     : ";
cin.getline(p.pname,30);
cout<<"\nEnter Premium       : ";
cin>>p.premium;
cout<<"\nEnter Duration (yr) : ";
cin>>p.duration;
cout<<"\nEnter Coverage Amt  : ";
cin>>p.coverage;
f.write((char*)&p, sizeof(p));
f.close();
cout<<"\n\nCustom Plan Added!";
getch();
clrscr();
}


void viewAllCustomPlans()
{
Plan p;
ifstream f("customplans.txt", ios::binary);
int found=0, count=0;
clrscr();
cout<<"\n\n========= ALL CUSTOM PLANS =========";

while(f.read((char*)&p, sizeof(p)))
{
found=1;
cout<<"\n\n--------------------------------";
cout<<"\nPlan ID     : "<<p.pid;
cout<<"\nName        : "<<p.pname;
cout<<"\nPremium     : "<<p.premium;
cout<<"\nDuration    : "<<p.duration<<" years";
cout<<"\nCoverage    : "<<p.coverage;

count++;
if(count % 2 == 0)
{
cout<<"\n\n(Press any key to view next plans...)";
getch();
clrscr();
cout<<"\n\n========= ALL CUSTOM PLANS =========";
}
}
f.close();
if(found==0)
cout<<"\n\n(No custom plans found)";

cout<<"\n\n====================================";
cout<<"\nPress any key to return.";
getch();
clrscr();
}


void searchCustomPlan()
{
int id,found=0;
Plan p;
ifstream f("customplans.txt", ios::binary);
cout<<"\n\nEnter Plan ID to search: ";
cin>>id;
while(f.read((char*)&p, sizeof(p)))
{
if(p.pid==id)
{
found=1;
cout<<"\nPlan Found:";
cout<<"\nPlan ID     : "<<p.pid;
cout<<"\nName        : "<<p.pname;
cout<<"\nPremium     : "<<p.premium;
cout<<"\nDuration    : "<<p.duration<<" years";
cout<<"\nCoverage    : "<<p.coverage;
break;
}
}
f.close();
if(found==0) cout<<"\nPlan not found!";
getch();
clrscr();
}



void updateCustomPlan()
{
int id,found=0;
Plan p;
cout<<"\n\nEnter Plan ID to update: ";
cin>>id;
ifstream f("customplans.txt", ios::binary);
ofstream t("temp.txt", ios::binary);
while(f.read((char*)&p, sizeof(p)))
{
if(p.pid==id)
{
cout<<"\n\nEnter New Details:";
cout<<"\n\nEnter Plan Name     : "; 
cin.ignore(); 
cin.getline(p.pname,30);
cout<<"\nEnter Premium       : ";
cin>>p.premium;
cout<<"\nEnter Duration (yr) : ";
cin>>p.duration;
cout<<"\nEnter Coverage Amt  : ";
cin>>p.coverage;
found=1;
}
t.write((char*)&p, sizeof(p));
}
f.close();
t.close();
remove("customplans.txt");
rename("temp.txt", "customplans.txt");
if(found==0) cout<<"\n\nPlan not found!";
else cout<<"\n\nPlan updated successfully!";
getch();
clrscr();
}



void deleteCustomPlan()
{
int id,found=0;
Plan p;
cout<<"\n\nEnter Plan ID to delete: ";
cin>>id;
ifstream f("customplans.txt", ios::binary);
ofstream t("temp.txt", ios::binary);
while(f.read((char*)&p, sizeof(p)))
{
if(p.pid!=id)
{
t.write((char*)&p, sizeof(p));
}
else found=1;
}
f.close();
t.close();
remove("customplans.txt");
rename("temp.txt", "customplans.txt");
if(found==0) cout<<"\nPlan not found!";
else cout<<"\n\nPlan deleted successfully!";
getch();
clrscr();
}



void viewCustomPlanByID()
{
int id,found=0;
Plan p;
cout<<"\n\nEnter Plan ID to view: ";
cin>>id;
ifstream f("customplans.txt", ios::binary);
while(f.read((char*)&p, sizeof(p)))
{
if(p.pid==id)
{
found=1;
cout<<"\nPlan ID     : "<<p.pid;
cout<<"\nName        : "<<p.pname;
cout<<"\nPremium     : "<<p.premium;
cout<<"\nDuration    : "<<p.duration<<" years";
cout<<"\nCoverage    : "<<p.coverage;
break;
}
}
f.close();
if(found==0)
cout<<"\n\nPlan not found!";
getch();
clrscr();
}

};




class Report
{
public:
void generateReport(int cid)
{
clrscr();
Customer c;
Plan p;
Payment pay;
Agent a;
Nominee n;
int found=0;


// ---------- Customer ----------

ifstream f1("customer.txt",ios::binary);
while(f1.read((char*)&c,sizeof(c)))
{
if(c.id==cid)
{
cout<<"\n=========== CUSTOMER DETAILS ===========\n";
cout<<"\nCustomer ID   : "<<c.id;
cout<<"\nName          : "<<c.name;
cout<<"\nAge           : "<<c.age;
cout<<"\nContact No.   : "<<c.contact;
cout<<"\nDate Added    : "<<c.date;
found=1;
break;
}
}
f1.close();

if(found==0)
{
cout<<"\n\nCustomer ID not found!";
cout<<"\n\nPress any key to return...";
getch();
return;
}
cout<<"\n\nPress any key to continue to Plan Details...";
getch();
clrscr();


// ---------- Plan ----------

ifstream f2("plan.txt",ios::binary);
int planFound=0;
cout<<"\n=========== PLAN DETAILS ===========\n";
while(f2.read((char*)&p,sizeof(p)))
{
if(p.cid==cid)
{
cout<<"\nPlan ID       : "<<p.pid;
cout<<"\nPlan Name     : "<<p.pname;
cout<<"\nPremium       : "<<p.premium;
cout<<"\nDuration      : "<<p.duration<<" years";
cout<<"\nCoverage      : "<<p.coverage<<"\n";
planFound=1;
}
}
f2.close();
if(planFound==0) cout<<"\n\nNo plans linked to this customer.";
cout<<"\n\nPress any key to continue to Payment Details...";
getch();
clrscr();


// ---------- Payment ----------

ifstream f3("payment.txt",ios::binary);
int payFound=0;
cout<<"\n=========== PAYMENT DETAILS ===========\n";
while(f3.read((char*)&pay,sizeof(pay)))
{
if(pay.cid==cid)
{
cout<<"\nPayment Status : "<<pay.status;
cout<<"\nAmount Paid    : "<<pay.amount;
cout<<"\nDate           : "<<pay.date;
payFound=1;
break;
}
}
f3.close();
if(payFound==0) cout<<"\n\nNo payment found for this customer.";
cout<<"\n\nPress any key to continue to Agent Details...";
getch();
clrscr();


// ---------- Agent ----------

ifstream f4("agent.txt",ios::binary);
int agentFound=0;
cout<<"\n=========== AGENT DETAILS ===========\n";
while(f4.read((char*)&a,sizeof(a)))
{
if(a.cid==cid)
{
cout<<"\nAgent Name     : "<<a.name;
cout<<"\nContact No.    : "<<a.contact;
agentFound=1;
break;
}
}
f4.close();
if(agentFound==0)
cout<<"\n\nNo agent assigned to this customer.";
cout<<"\n\nPress any key to continue to Nominee Details...";
getch();
clrscr();


// ---------- Nominee ----------

ifstream f5("nominee.txt",ios::binary);
int nomFound=0;
cout<<"\n=========== NOMINEE DETAILS ===========\n";
while(f5.read((char*)&n,sizeof(n)))
{
if(n.cid==cid)
{
cout<<"\nNominee Name   : "<<n.name;
cout<<"\nNominee Age    : "<<n.age;
cout<<"\nRelation       : "<<n.relation;
cout<<"\nContact No.    : "<<n.contact;
nomFound=1;
break;
}
}
f5.close();
if(nomFound==0) cout<<"\n\nNo nominee linked with this customer.";

cout<<"\n\n==============================================";
cout<<"\n\nPress any key to return to main menu...";
getch();
clrscr();
}

};





void goodbye() {
clrscr();
cout<<"\n\n\t\t********************************************";
cout<<"\n\t\t*                                          *";
cout<<"\n\t\t*       THANK YOU FOR USING MY SYSTEM      *";
cout<<"\n\t\t*                                          *";
cout<<"\n\t\t********************************************";
cout<<"\n\n\tDeveloped By   : KANISHKA SINGH";
cout<<"\n\t\tRoll Number    : 120924097";
cout<<"\n\t\tGuide Name     : DR. MADHU CHAUHAN";
cout<<"\n\n\t\t Project Title: INSURANCE MANAGEMENT SYSTEM";
cout<<"\n\n\t\t Press any key to exit...";
getch();
}




void welcome()
{
clrscr();

cout<<"\n\n\n";
cout<<"                            *********************************************\n";
cout<<"                            *                                           *\n";
cout<<"                            *         WELCOME TO INSURANCE SYSTEM       *\n";
cout<<"                            *                                           *\n";
cout<<"                            *********************************************\n";

cout<<"\n";
cout<<"                            +-------------------------------------------+\n";
cout<<"                            |  Student Name : Kanishka Singh            |\n";
cout<<"                            |  Course       : BCA                       |\n";
cout<<"                            |  Section      : B                         |\n";
cout<<"                            |  Roll Number  : 120924097                 |\n";
cout<<"                            |  Batch        : 2024 - 2027               |\n";
cout<<"                            |  Guide Name   : Dr. Madhu Chauhan         |\n";
cout<<"                            +-------------------------------------------+\n";

cout<<"\n\n";
cout<<"                               Press any key to continue...";
getch();
clrscr();

Admin a;
a.login();
}





void main()
{
clrscr();

welcome();
clrscr();

Insurance ins;
Report r;
PlanInfo pi;

int ch, sub;

do {
cout<<"\n\n===== INSURANCE MANAGEMENT MENU =====";
cout<<"\n\n1. Customer";
cout<<"\n2. Plan";
cout<<"\n3. Payment";
cout<<"\n4. Agent";
cout<<"\n5. Nominee";
cout<<"\n6. Report";
cout<<"\n7. Exit";
cout<<"\n\nEnter your choice: ";
cin>>ch;

switch(ch)
{
case 1:
do {
cout<<"\n\n--- CUSTOMER MENU ---";
cout<<"\n\n1. Add Customer";
cout<<"\n2. View Customer";
cout<<"\n3. Search Customer";
cout<<"\n4. Update Customer";
cout<<"\n5. Delete Customer";
cout<<"\n6. View Customers By Date";
cout<<"\n7. Back";
cout<<"\n\nEnter choice: ";
cin>>sub;
switch(sub)
{
case 1: ins.addCustomer();
break;
case 2: ins.viewCustomer();
break;
case 3: ins.searchCustomer();
break;
case 4: ins.updateCustomer();
break;
case 5: ins.deleteCustomer();
break;
case 6: ins.viewCustomerByDate();
break;
case 7:
break;
default:
cout << "\n\nInvalid choice! Please try again.";
}
} while(sub != 7);
break;


case 2:
int pch;
do {
cout<<"\n\n\t\t========= PLAN MENU =========";
cout<<"\n\t1. Add Plan (linked to Customer ID)";
cout<<"\n\t2. View Plan by Customer ID";
cout<<"\n\t3. Search Plan (Customer ID + Plan ID)";
cout<<"\n\t4. Update Plan";
cout<<"\n\t5. Delete Plan";
cout<<"\n\t6. Plan Information (Predefined + Custom)";
cout<<"\n\t7. Back to Main Menu";
cout<<"\n\n\tEnter your choice: ";
cin>>pch;

switch(pch)
{
case 1: ins.addPlan();
break;
case 2: ins.viewPlan();
break;
case 3: ins.searchPlan();
break;
case 4: ins.updatePlan();
break;
case 5: ins.deletePlan();
break;
default:
cout << "\n\nInvalid choice! Please try again.";
case 6:
int sub2;
do {
cout<<"\n\n\t\t--- PLAN INFO MENU ---";
cout<<"\n\t1. Show Predefined Plans";
cout<<"\n\t2. Add Custom Plan";
cout<<"\n\t3. View Custom Plans";
cout<<"\n\t4. Search Custom Plan by Plan ID";
cout<<"\n\t5. Update Custom Plan";
cout<<"\n\t6. Delete Custom Plan";
cout<<"\n\t7. Back to Plan Menu";
cout<<"\n\n\tEnter your choice: ";
cin>>sub2;

switch(sub2)
{
case 1: pi.showInfo();
break;
case 2: pi.addCustomPlan();
break;
case 3: pi.viewAllCustomPlans();
break;
case 4: pi.searchCustomPlan();
break;
case 5: pi.updateCustomPlan();
break;
case 6: pi.deleteCustomPlan();
break;
case 7:
break;
default:
cout << "\n\nInvalid choice! Please try again.";
}
} while(sub2 != 7);
break;
}
} while(pch != 7);
break;


case 3:
do {
cout<<"\n\n--- PAYMENT MENU ---";
cout<<"\n\n1. Add Payment";
cout<<"\n2. View Payment";
cout<<"\n3. Search Payment";
cout<<"\n4. Update Payment";
cout<<"\n5. Delete Payment";
cout<<"\n6. View Payments By Date";
cout<<"\n7. Back";
cout<<"\n\nEnter choice: ";
cin>>sub;
switch(sub)
{
case 1: ins.addPayment();
break;
case 2: ins.viewPayment();
break;
case 3: ins.searchPayment();
break;
case 4: ins.updatePayment();
break;
case 5: ins.deletePayment();
break;
case 6: ins.viewPaymentByDate();
break;
case 7:
break;
default:
cout << "\n\nInvalid choice! Please try again.";
}
} while(sub != 7);
break;


case 4:
do {
cout<<"\n\n--- AGENT MENU ---";
cout<<"\n\n1. Add Agent";
cout<<"\n2. View Agent";
cout<<"\n3. Search Agent";
cout<<"\n4. Update Agent";
cout<<"\n5. Delete Agent";
cout<<"\n6. Back";
cout<<"\n\nEnter choice: ";
cin>>sub;
switch(sub)
{
case 1: ins.addAgent();
break;
case 2: ins.viewAgent();
break;
case 3: ins.searchAgent();
break;
case 4: ins.updateAgent();
break;
case 5: ins.deleteAgent();
break;
case 6:
break;
default:
cout << "\n\nInvalid choice! Please try again.";
}
} while(sub != 6);
break;


case 5:
do {
cout<<"\n\n--- NOMINEE MENU ---";
cout<<"\n\n1. Add Nominee";
cout<<"\n2. View Nominee";
cout<<"\n3. Search Nominee";
cout<<"\n4. Update Nominee";
cout<<"\n5. Delete Nominee";
cout<<"\n6. Back";
cout<<"\n\nEnter choice: ";
cin>>sub;
switch(sub)
{
case 1: ins.addNominee();
break;
case 2: ins.viewNominee();
break;
case 3: ins.searchNominee();
break;
case 4: ins.updateNominee();
break;
case 5: ins.deleteNominee();
break;
case 6:
break;
default:
cout << "\n\nInvalid choice! Please try again.";
}
} while(sub != 6);
break;


case 6:
int cid;
cout<<"\n\nEnter Customer ID to Generate Report: ";
cin>>cid;
r.generateReport(cid);
break;


case 7:
goodbye();
break;


default:
cout<<"\n\nInvalid choice. Try again.";
}


} while(ch != 7);

getch();
}