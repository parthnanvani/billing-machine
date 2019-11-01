#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<dos.h>


void startprogram()
{
	textbackground(RED);
	clrscr();
	double A;
	textcolor(YELLOW);
	textbackground(GREEN);
	gotoxy(30,17);
	cout<<" PASSWORD = ";
	cin>>A;
	textcolor(YELLOW);
	textbackground(BLUE);
	for(int j=1;j<=100;++j)
	{
		clrscr();
		gotoxy(30,17);
		cout<<"Loading:: "<<j<<"%";
		delay(10);
	}
	if(A!=69)
	{
		clrscr();
		textbackground(10);
		textcolor(9);
		{
			gotoxy(35,17);
			cout<<" Wrong Password";
		}
		getch();
		exit(0);
	}
	else
	{
		clrscr();
		textcolor(YELLOW);
		textbackground(BLACK);
		gotoxy(35,17);
		cout<<"\a\a\a PASSWORD ACCEPTED\n";
		getch();
		clrscr();
	}
}
void box(int x)
{
	for(int k=1;k<(x+1);k++)
	{
		textcolor(14);
		textbackground(5);
		delay(500);
		gotoxy((k),(k)) ;
		cout<<"É";
		for(int i=0;i<(80-(k*2));i++)
		{
			cout<<"Í";
		}
		cout<<"»";
		int c;
		for(int j=0;j<(25-(k*2));j++)
		{
			c=j+2;
			cout<<"º";
			gotoxy(k,(c+k-1));
		}
		cout<<"È";
		gotoxy((k+1),(25-k));
		for( i=0;i<(80-(k*2));i++)
		{
			cout<<"Í";
		}

		cout<<"¼";
		for( j=0;j<(24-(k*2));j++)
		{
			c=j+2;
			gotoxy((81-k),(c+k-1));
			cout<<"º";

		}
	}

}

void box1( )
{
	clrscr();
	int i;
	gotoxy(2,4);

	cout<<"Sr.no             Item               Quantity         Price          Total";

	gotoxy(1,4);
	for( i=0;i<17;i++)
	{

		cout<<"º";
		gotoxy(1,4+i);

	}


	gotoxy(8,4);
	for( i=0;i<17;i++)
	{

		cout<<"º";
		gotoxy(8,4+i);

	}


	gotoxy(35,4);
	for( i=0;i<17;i++)
	{

		cout<<"º";
		gotoxy(35,4+i);

	}

	gotoxy(50,4);
	for( i=0;i<17;i++)
	{

		cout<<"º";
		gotoxy(50,4+i);

	}

	gotoxy(65,4);
	for( i=0;i<17;i++)
	{

		cout<<"º";
		gotoxy(65,4+i);

	}

	gotoxy(80,4);
	for( i=0;i<17;i++)
	{

		cout<<"º";
		gotoxy(80,4+i);

	}

	gotoxy(1,3);
	cout<<"É";          //201
	for( i=0;i<78;i++)
	{

		cout<<"Í";

	}
	cout<<"»";      //187

	gotoxy(1,5);
	cout<<"Ì";
	for( i=0;i<78;i++)
	{

		cout<<"Í";

	}
	cout<<"¹";

	gotoxy(1,20);
	cout<<"È";      //200
	for( i=0;i<78;i++)
	{

		cout<<"Í";

	}
	cout<<"¼";      //188

	gotoxy(8,3);
	cout<<"Ë";

	gotoxy(8,5);
	cout<<"Î";

	gotoxy(8,20);
	cout<<"Ê";

	gotoxy(35,3);
	cout<<"Ë";

	gotoxy(35,5);
	cout<<"Î";

	gotoxy(35,20);
	cout<<"Ê";

	gotoxy(50,3);
	cout<<"Ë";

	gotoxy(50,5);
	cout<<"Î";

	gotoxy(50,20);
	cout<<"Ê";

	gotoxy(65,3);
	cout<<"Ë";

	gotoxy(65,5);
	cout<<"Î";

	gotoxy(65,20);
	cout<<"Ê";


}


class var
{
	private:
	char name[20][10],date[11];
	int quantity[10],billno;
	double  price[10],tot,grandtot;
	public:

	var()
	{
		tot=0;
		grandtot=0;

	}

	void createbill();
	void printbill();
	void accessbill();
	void deletebill();
	void biggestbill();
	void totsales();
	void delallbills();
	void editbill();

	~var()
	{

	}
}v1,v2;

void var:: createbill()
{
	clrscr();
	ofstream fout;
	fout.open("parthpro.txt",ios::app);
	cout<<"\nDate (DD.MM.YYYY) : " ;
	gets(date);
	cout<<"\nenter the bill no.";
	cin>>billno;
	cout<<"\nenter the  no.of items: ";
	cin>>tot;
	for( int i=0;i<tot;i++)
	{


		{
			cout<<"\n\n Enter the product name : ";
			gets(name[i]);
			cout<<"\n Enter the  quantity : ";
			cin>>quantity[i];
			cout<<"\n Enter the price  : ";
			cin>>price[i];
			grandtot=grandtot+(price[i]*quantity[i]);

		}
	}

	fout.write((char*)&v1,sizeof(v1));
	fout.close();

	getch();
}
void var::printbill()
{

	gotoxy(25,17);
	cout<<"printing bill..........";
	delay(1000);

	clrscr();

	box1();
	gotoxy(60,2);
	cout<<"DATE : ";
	puts(date);
	gotoxy(30,2);
	cout<<"Bill no.:";
	cout<<billno;
	for( int s=0;s<tot;s++)
	{

		gotoxy(2,6+s);
		cout<<s+1;

		gotoxy(9,6+s);
		puts(name[s]);

		gotoxy(36,6+s);
		cout<<quantity[s];

		gotoxy(51,6+s);
		cout<<price[s];

		gotoxy(66,6+s);
		cout<<price[s]*quantity[s];


	}


	gotoxy(55,21);
	cout<<"grand total: "<<grandtot ;

	getch();




}
void var:: accessbill()
{
	int pn;
	char found='n',cdate[11];
	cout<<"\nEnter the date when bill was created :";
	gets(cdate);
	cout<<"\nEnter the bill  number  you want to search  : ";
	cin>>pn;
	ifstream fin ;
	fin.open("parthpro.txt",ios::in);
	fin.seekg(0);
	while(!fin.eof())
	{
		fin.read((char*)&v1,sizeof(v1));
		if( (billno==pn) && ( strcmp(date,cdate)==0 ) )
		{
			found='y';

			box1();
			gotoxy(60,2);
			cout<<"DATE :";
			puts(date);
			gotoxy(30,2);
			cout<<"Bill no.:";
			cout<<billno;
			for(int k=0;k<tot;k++)
			{

				gotoxy(2,6+k);
				cout<<k+1;

				gotoxy(9,6+k);
				puts(name[k]);

				gotoxy(36,6+k);
				cout<<quantity[k];

				gotoxy(51,6+k);
				cout<<price[k];

				gotoxy(66,6+k);
				cout<<price[k]*quantity[k];


			}
			gotoxy(55,21);
			cout<<"grand total: "<<grandtot ;

		}

	}
		if(found=='n')
		cout<<"\n::::Data not found:::::";

		getch();
		fin.close();

}
void var :: biggestbill()
{
	int sbill=0;
	double gtot=0;
	char found1='n',bdate[11];
	cout<<"\nEnter the date  :";
	gets(bdate);
	ifstream fin2 ;
	fin2.open("parthpro.txt",ios::in);
	fin2.seekg(0);
	while(!fin2.eof())
	{
		fin2.read((char*)&v1,sizeof(v1));
		if(  strcmp(date,bdate)==0 )
		{

			if(gtot<grandtot)
			{
				sbill=billno;
				gtot=grandtot;
			}

		}
	}
	fin2.close();

	ifstream fin3 ;
	fin3.open("parthpro.txt",ios::in);
	fin3.seekg(0);
	while(!fin3.eof())
	{
		fin3.read((char*)&v1,sizeof(v1));
		if( (billno==sbill) && ( strcmp(date,bdate)==0 ) )
		{
			found1='y';

			box1();
			gotoxy(60,2);
			cout<<"DATE :";
			puts(date);
			gotoxy(30,2);
			cout<<"Bill no.:";
			cout<<billno;
			for(int k=0;k<tot;k++)
			{

				gotoxy(2,6+k);
				cout<<k+1;

				gotoxy(9,6+k);
				puts(name[k]);

				gotoxy(36,6+k);
				cout<<quantity[k];

				gotoxy(51,6+k);
				cout<<price[k];

				gotoxy(66,6+k);
				cout<<price[k]*quantity[k];


			}
			gotoxy(55,21);
			cout<<"grand total: "<<grandtot ;

			getch();
		}

	}
		if(found1=='n')
		cout<<"\n::::Data not found:::::";
		fin3.close();

}


void  var :: deletebill()
{
	int dbill,cb=0,nb=0,rbill=-1;
	char found3='n',ddate[11],rdate[11]="00.00.0000",confirm='n',cd[11];
	cout<<"\nEnter the date when bill was created :";
	gets(ddate);
	cout<<"\nEnter the bill  number  : ";
	cin>>dbill;
	ifstream fin4 ;
	ofstream fout2;
	fin4.open("parthpro.txt",ios::in);
	fout2.open("temppro.txt",ios::out);
	fin4.seekg(0);

	while(!fin4.eof())
	{
		fin4.read((char*)&v1,sizeof(v1));

		if( (rbill!=billno) && (strcmp(rdate,date)!=0) )
		{
			rbill=billno;
			strcpy(rdate,date);

			if( (billno==dbill) && ( strcmp(date,ddate)==0 )  )
			{
				found3='y';
				box1();
				gotoxy(60,2);
				cout<<"DATE :";
				puts(date);
				gotoxy(30,2);
				cout<<"Bill no.:";
				cout<<billno;
				for(int k=0;k<tot;k++)
				{

					gotoxy(2,6+k);
					cout<<k+1;

					gotoxy(9,6+k);
					puts(name[k]);

					gotoxy(36,6+k);
					cout<<quantity[k];

					gotoxy(51,6+k);
					cout<<price[k];

					gotoxy(66,6+k);
					cout<<price[k]*quantity[k];

				}
				gotoxy(55,21);
				cout<<"grand total: "<<grandtot ;

				gotoxy(10,23);
				cout<<"Are you sure you want to delete this record?(y/n)..";
				cin>>confirm;
				if(confirm=='n')
				fout2.write((char*)&v1,sizeof(v1));
			}
			else
			{
				fout2.write((char*)&v1,sizeof(v1));
			}
		}
	}

	if(found3=='n')
	cout<<"Record not found!!!\n";

	fout2.close();
	fin4.close();

	remove("parthpro.txt");
	rename("temppro.txt","parthpro.txt");

	if( ( found3=='y') && ( confirm=='y') )
	{
		clrscr();
		gotoxy(20,17);
		cout<<"......................Record is being deleted...........................";
		delay(1000);
		clrscr();
		gotoxy(20,17);
		cout<<"......................Record is deleted..........................." ;
		delay(1000);
	}

	ifstream fin5;
	fin5.open("parthpro.txt",ios::in);
	fin5.seekg(0);
	while (!fin5.eof())
	{

		fin5.read((char*)&v2,sizeof(v2));
		if((cb!=billno) &&  (strcmp(cd,date)!=0 ) )
		{
			clrscr();
			cb=billno;
			strcpy(cd,date);

			if(fin5.eof())
			{
				gotoxy(35,17);
				cout<<"now file is empty";
				break;
			}
			nb++;
		}
	}
	if(nb==1)
	{
		cout<<"now file contains "<<nb<<" bill ";
	}
	else if(nb>1)
	{
		cout<<"now file contains "<<nb<<" bills ";
	}
	delay(750);

	fin5.close();
	getch();


}

void var :: delallbills()
{
	ifstream fin5 ;
	int b=0;
	fin5.open("parthpro.txt",ios::in);
	fin5.seekg(0);
	while(!fin5.eof())
	{
		fin5.read((char*)&v1,sizeof(v1));
		b++;


	}

	if(b==0)
	{
		gotoxy(25,17);
		cout<<"File is already empty ";
		delay(1000);
		exit(2);
	}
	else
	{
		remove("parthpro.txt");
		gotoxy(35,17);
		cout<<"All the bills have been deleted ";
		getch();
	}
	fin5.close();
}

void var :: totsales()
{
	double tsales=0,bno=0;
	char found2='n',sdate[11];
	cout<<"\nEnter the date :";
	gets(sdate);
	ifstream fin1 ;
	fin1.open("parthpro.txt",ios::in);
	fin1.seekg(0);
	while(!fin1.eof())
	{
		fin1.read((char*)&v1,sizeof(v1));
		if ( strcmp(date,sdate)==0 && (bno!=billno))
		{
			found2='y';
			tsales=tsales+grandtot;
			bno=billno;
		}



	}

	if(found2=='n')
	{
		cout<<"\n::::Date not found:::::";
	}
	else
	{
		clrscr();
		gotoxy(27,17);
		cout<<"TOTAL SALES ON ";
		puts(sdate);
		gotoxy(53,17);
		cout<< " IS : "<<tsales;
	}

	getch();
	fin1.close();

}

void var :: editbill()
{
	int ebill,r2bill=-1;
	char found4='n',edate[11],r2date[11];
	cout<<"enter the date when bill was created: ";
	gets(edate);
	cout<<"\nenter the bill no: ";
	cin>>ebill;
	fstream fio;
	fio.open("parthpro.txt",ios::in | ios::out );
	fio.seekg(0);
	while(!fio.eof())
	{
		fio.read((char*)&v1,sizeof(v1));
		if( (r2bill!=billno) && (strcmp(r2date,date)!=0) )
		{
			r2bill=billno;
			strcpy(r2date,date);

			if ( (ebill==billno) && (strcmp(edate,date)==0) )
			{
				clrscr();
				gotoxy(35,17);
				cout<<"Old bill ";
				delay(1000);
				found4='y';

				box1();
				gotoxy(60,2);
				cout<<"DATE :";
				puts(date);
				gotoxy(30,2);
				cout<<"Bill no.:";
				cout<<billno;
				for(int k=0;k<tot;k++)
				{

					gotoxy(2,6+k);
					cout<<k+1;

					gotoxy(9,6+k);
					puts(name[k]);

					gotoxy(36,6+k);
					cout<<quantity[k];

					gotoxy(51,6+k);
					cout<<price[k];

					gotoxy(66,6+k);
					cout<<price[k]*quantity[k];


				}
				gotoxy(55,21);
				cout<<"grand total: "<<grandtot ;
				getch();

				clrscr();
				cout<<"enter the new data ";
				delay(750);
				clrscr();

				char nm[20][10],ndate[11];
				int nquantity[10],nbillno;
				double  nprice[10],ntot=0;

				cout<<"\nDate (DD.MM.YYYY) (enter '.' to retain old one): " ;
				gets(ndate);
				cout<<"\nenter the bill no. (enter -1 to retain old one)";
				cin>>nbillno;
				cout<<"\nenter the  no.of items (enter -1 to retain old one) : ";
				cin>>ntot;
				if(ntot!=-1)
				{
					tot=ntot;
				}

				for( int p=0;p<tot;p++)
				{

					if(ntot==-1)
					{
						cout<<"\n\n Enter the product name (enter '.' to retain old one): ";
						gets(nm[p]);
						cout<<"\n Enter the  quantity (enter -1 to retain old one) : ";
						cin>>nquantity[p];
						cout<<"\n Enter the price (enter -1 to retain old one): ";
						cin>>nprice[p];
					}
					else
					{
						cout<<"\n\n Enter the product name: ";
						gets(nm[p]);
						cout<<"\n Enter the  quantity  : ";
						cin>>nquantity[p];
						cout<<"\n Enter the price : ";
						cin>>nprice[p];

					}

				}

				if(strcmp(ndate,".")!=0)
				{
					strcpy(date,ndate);
				}
				if(nbillno!=-1)
				{
					billno=nbillno;
				}
				for(int q=0;q<tot;q++)
				{
					if(strcmp(nm[q],".")!=0)
					{
						strcpy(name[q],nm[q]);
					}
					if (nquantity[q]!= -1)
					{
						quantity[q]=nquantity[q];
					}
					if (nprice[q]!=-1)
					{
						price[q]=nprice[q];
					}
				}
				grandtot=0;
				for(int y=0;y<tot;y++)
				{
					grandtot=(grandtot + (price[y]*quantity[y]) );
				}
				clrscr();
				gotoxy(30,16);
				cout<<"Bill has been successfully edited ";
				delay(1000);
				fio.write((char*)&v1,sizeof(v1));

			}
		}

	}
	if(found4=='n')
	{
		cout<<"\n::::Data not found:::::";
	}
	else
	{
		clrscr();
		printbill();
	}
	fio.close();
	getch();

}

void main()
{
	clrscr();
	int ch1,ch2;

	startprogram();
	box(1);
	gotoxy(28,2);
	cout<<":::::::Menu::::::::\n";
	gotoxy(5,5);
	cout<<"1)NEW BILL\n";
	gotoxy(5,6);
	cout<<"2)ACCESS OLD DATA\n";
	gotoxy(5,7);
	cout<<"3)Exit\n";
	gotoxy(5,9);
	cout<<"Enter your choice:";
	gotoxy(24,9);
	cin>>ch1;
	clrscr();
	textcolor(14);
	textbackground(10);
	switch(ch1)
	{
		case 1: clrscr();
			v1.createbill();
			clrscr();
			v1.printbill();
			break;

		case 2: clrscr();

			//box(1);
			gotoxy(28,2);
			cout<<":::::::Menu::::::::\n";
			gotoxy(5,4);
			cout<<"1)ACCESS A PARTICULAR BILL\n";
			gotoxy(5,5);
			cout<<"2)BIGGEST BILL OF A PARTICULAR DAY\n";
			gotoxy(5,6);
			cout<<"3)DELETE A BILL\n";
			gotoxy(5,7);
			cout<<"4)TOTAL SALES OF A DAY";
			gotoxy(5,8);
			cout<<"5)DELETE ALL THE BILLS";
			gotoxy(5,9);
			cout<<"6)EDIT A BILL ";
			gotoxy(5,11);
			cout<<"Enter your choice: ";
			cin>>ch2;
			clrscr();
			switch(ch2)
			{
				case 1:  v1.accessbill();
					 break;

				case 2:  v1.biggestbill();
					 break;

				case 3:  v1.deletebill();
					 break;

				case 4:  v1.totsales();
					 break;

				case 5:  v1.delallbills();
					 break;

				case 6:  v1.editbill();
					 break;

				default: cout<<"...............wrong choice ..........";
					 delay (1000);
					 exit(1);
			}
			break;

		case 3: clrscr();
			gotoxy(15,15);
			cout<<"Program is being terminated.......";
			delay(1000);
			break;

		default: clrscr();
			 cout<<"............. Wrong choice.........";
			 delay(1000);
			 exit(0);

	}


}
