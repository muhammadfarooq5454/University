#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct 
   {
		int cell;
		unsigned long int ID;
		char name[50];
		char nlt[20];
		char gen[7];
		char date[16];
		char arrest[16];
		unsigned int age;
		char height[32];
		char weight[32];
		char color [7];
		char chg [60];
		float yrs;
		char prison [20];	
	}criminal;
	
typedef struct 
   {
		char name[50];
		char color[32];
		char height[7];
		char chg[60];
		char stars[6];
	} mwanted;

int login ( void );
int menu ( const int *, int );
int registeration ( const int * );
int delete_record ( const int * );
int search ( const int * );
void display ( criminal );
void display2 ( criminal );
int list ( const int * );
int add_most ( void );
int view_most( void );
void mostwanted ( mwanted );
int released( void );
int crime_rate( void );

int main ()
{
	login();
	return 0;
}

int login ( void )
{
	struct login 
	{
	char ID[16];
	char PW[16];
	};
	int i, a, b, q;
	struct login input;
	// login structures for five different police stations
	struct login admin = 
	{
		"ADMIN",
		"NOPASSWORD"
	};
	struct login PS1 = 
	{
		"PS_1",
		"1111"
	};
	struct login PS2 = 
	{
		"PS_2",
		"2222"
	};
	struct login PS3 = 
	{
		"PS_3",
		"3333"
	};
	struct login PS4 = {
		"PS_4",
		"4444"
	};
	struct login PS5 = 
	{
		"PS_5",
		"5555"
	};
	system("color 1F");
	while ( q>=0 )
	{
		q=1;
		static int login=0;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
		printf( "\n\t\t\t\t\t========================                              ========================" );
		printf( "\n\t\t\t\t\t========================   PRISON MANAGEMENT SYSTEM   ========================" );
		printf( "\n\t\t\t\t\t========================                              ========================" );
		printf( "\n\n\t\t\t\t\t\t\t\t      Enter Login Details" );
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
		printf( "\nID: " );
		scanf( "%s", &input.ID );
		printf( "\nPassword: " );
		scanf( "%s", &input.PW );

		for ( i=1;i<=6;i++ )
		{
			if ( i==1 )
			{
			a = strcmp ( input.ID, PS1.ID );
			b = strcmp ( input.PW, PS1.PW );
			}
			else if ( i==2 )
			{
			a = strcmp ( input.ID, PS2.ID );
			b = strcmp ( input.PW, PS2.PW );
			}
			else if ( i==3 )
			{
			a = strcmp ( input.ID, PS3.ID );
			b = strcmp ( input.PW, PS3.PW );
			}
			else if ( i==4 )
			{
			a = strcmp ( input.ID, PS4.ID );
			b = strcmp ( input.PW, PS4.PW );
			}
			else if ( i==5 )
			{
			a = strcmp ( input.ID, PS5.ID );
			b = strcmp ( input.PW, PS5.PW );
			}
			else if ( i==6 )
			{
			a = strcmp ( input.ID, admin.ID );
			b = strcmp ( input.PW, admin.PW );
			}
			
			if ( a==0 && b==0 )
			{
				login = i;
				q = 0;
				q = menu( &login, q );
			}
			else {
				continue;
			}
		}
		if ( q==1 )
		{
			printf( "\nIncorrect ID or Password!!!\n Try again?(yes=1, no=0)" );
			scanf( "%d", &q );
		}
	}
	return;
}

int menu ( const int *login, int q )
{
	if ( q == 9 )
	{
		return 2;
	}
	else {
		system ("cls");
		printf( "\n\n\n\t\t\t\t\t============================ MAIN MENU ============================\n\n\n" );

		if ( *login>=1 && *login<=5 )
		{
			printf( "\t\t\t\t\t\t    -------------- POLICE STATION %d --------------\n\n\n", *login );
		}
		else if ( *login==6 )
		{
			printf( "\t\t\t\t\t\t    -------------- MENU --------------\n\n\n" );
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
		printf( "\t\t\t\t\t\t\t\t1.Register a Criminal\n\n" );
		printf( "\t\t\t\t\t\t\t\t2.Release a Criminal\n\n" );
		printf( "\t\t\t\t\t\t\t\t3.Search a Criminal\n\n" );
		printf( "\t\t\t\t\t\t\t\t4.View the list of Criminals\n\n" );
		if ( *login == 6 )
		{
			printf( "\t\t\t\t\t\t\t\t5.Add a Most Wanted Criminal\n\n" );
			printf( "\t\t\t\t\t\t\t\t6.View Most Wanted Criminals\n\n" );
			printf( "\t\t\t\t\t\t\t\t7.View Released Criminals\n\n" );
			printf( "\t\t\t\t\t\t\t\t8.Crime Rate\n\n" );
		}
		printf( "\t\t\t\t\t\t\t\t9.Log Out\n\n" );
	
		scanf( "%d", &q );
		if ( q==1 )
		{
			q = registration(login);
		}
		if ( q==2 )
		{
			q = delete_record(login);
		}
		if ( q==3 )
		{
			q = search(login);
		}
		if ( q==4 )
		{
			q = list(login);
		}
		if ( *login==6 )
		{
				if ( q==5 )
			{
				q = add_most();
			}
			if ( q==6 )
			{
				q = view_most();
			}
			if ( q==7 )
			{
				q = released();
			}
			if ( q==8 )
			{
				q = crime_rate();
			}
		}
		q = menu( login, q );
	}
	return 2;
}

int registration ( const int *login )
{
	system ("cls");
	int i;
	FILE *fp;
	printf( "\n\n\n\t\t\t\t\t\t\t\t      Registration Of A Criminal\n\t\t\t\t\t\t\t\t     " ); 
	for ( i=0;i<28;i++ )
	{	printf( "_" );	}
	
	criminal c;
	
	fflush(stdin);
	printf("\n\n\nName: ");
	gets( c.name );
	
	printf( "\nID of Criminal: " );
	scanf( "%u", &c.ID );
	
	fflush(stdin);
	printf("\nNationality: ");
	gets( c.nlt );
	
	printf("\nGender: ");
	gets ( c.gen );
	
	printf("\nDate of Birth(DD/MM/YYYY): ");
	gets ( c.date );
	
	printf("\nAge: ");
	scanf( "%d" , &c.age );
	
	fflush(stdin);
	printf( "\nThe Height of the criminal: " );
	gets( c.height );
	
	printf( "\nThe Weight of the criminal: " );
	gets( c.weight );
	
	printf( "\nSkin color: " );
	gets( c.color );
	
	printf( "\nDate of Arrest: " );
	gets( c.arrest );
	
	printf("\nCharge on the criminal: ");
	gets ( c.chg );
	
	printf( "\nDuration in prison: " );
	scanf( "%f", &c.yrs);
	
	fflush(stdin);
	printf("\nCell No. of the criminal: ");
	scanf( "%d", &c.cell );
	
	strcpy( c.prison, "in prison" );
	
	if ( *login==6 )
	{
		printf( "\nFeed the criminal in Police Station No.: " );
		scanf( "%d", &i );
	}
	else {
		i = *login;
	}
	
	if ( i==1 )
	{
		fp = fopen( "data/PS1.dat", "ab" );
	}
	else if ( i==2 )
	{
		fp = fopen( "data/PS2.dat", "ab" );
	}
	else if ( i==3 )
	{
		fp = fopen( "data/PS3.dat", "ab" );
	}
	else if ( i==4 )
	{	
		fp = fopen( "data/PS4.dat", "ab" );
	}
	else if ( i==5 )
	{
		fp = fopen( "data/PS5.dat", "ab" );
	}
	fwrite( &c, sizeof(c), 1, fp );
	fclose(fp);
	
	
	printf( "\n\nThe Data of the Criminal has been Recorded.\n\nPress any key to continue..." );
	getch();
	
	return 0;
}

int delete_record ( const int *login )
{
	system("cls");
	char name[50];
	unsigned int id;
	criminal c[40];
	printf( "\n\n\n\t\t\t\t\t\t\t\t      Release a Criminal\n\t\t\t\t\t\t\t\t" );
	int i;
	for ( i=0;i<33;i++ )
	{	printf( "_" );	}
	printf("\n\n\tRemove a criminal by:");
	printf( "\n\n\t1. Name" );
	printf( "\n\n\t2. ID\n\n" );
	int o;
	scanf( "%d", &o );
	printf( "\n    ------------------------------------------\n\n" );
	FILE *ft, *fc, *fr;
	switch ( o )
	{
		case 1:
			printf( "\tEnter Name: " );
			fflush(stdin);
			gets( name );
			break;
		case 2:
			printf( "\tEnter ID: " );
			fflush(stdin);
			scanf( "%u", &id );
			break;
		default:
			return 0;
	}

	system("cls");
	printf( "\n\n\n\t\t\t\t\t\t\t\t      Release a Criminal\n\t\t\t\t\t\t\t\t" );
	for ( i=0;i<28;i++ )
	{	printf( "_" );	}		
	printf( "\n\n\t--------------Criminal/s Found--------------\n\n" );

	if ( *login>=1 && *login<=5 )
	{
		criminal c[40];	
		printf( "\tS.No\tName\t\t\t\tCriminal ID\t\tCharge on Criminal\n\n   " );
		if ( *login==1 )
		{
			fc = fopen( "data/PS1.dat", "rb" );
		}
		else if ( *login==2 )
		{
			fc = fopen( "data/PS2.dat", "rb" );
		}
		else if ( *login==3 )
		{
			fc = fopen( "data/PS3.dat", "rb" );
		}
		else if ( *login==4 )
		{	
			fc = fopen( "data/PS4.dat", "rb" );
		}
		else if ( *login==5 )
		{
			fc = fopen( "data/PS5.dat", "rb" );
		}
		
		if ( fc == NULL )
		{	
			system("cls");
			puts("\n\nfile could not open!");
			printf( "\npress any key to continue..." );
			getch();
			return 0;
		}
		else {
			i=0;
			rewind(fc);
			while ( fread( &c[0], sizeof(c[0]), 1, fc ) == 1 )		
			{
				if ( strcmp( c[0].name, name ) == 0 || c[0].ID == id )
				{
					i++;
					c[i]=c[0];
					if ( strlen(c[i].name)<16 )
					{
						printf( "\n\t%d\t%s\t\t\t%u\t\t%s\n", i, c[i].name, c[i].ID, c[i].chg );
					}
					else {
						printf( "\n\t%d\t%s\t\t%u\t\t%s\n", i, c[i].name, c[i].ID, c[i].chg );
					}
				}
			}
			if ( i == 0 )
			{
				system("cls");
				printf( "\n\n\n\t\t\t\t\t\t\t\t      Release a Criminal\n\t\t\t\t\t\t\t\t" );
				for ( i=0;i<33;i++ )
				{	printf( "_" );	}
				printf( "\n\n\nNo criminal found..." );
				printf( "\n\npress any key to continue..." );
				getch();
				return 0;
			}
			else {
				printf( "\n\nChoose S.No of a Criminal to release " );
				scanf( "%d", &i );
				printf( "\nAre you sure you want to release this record?(Yes=1, No=0)" );
				int j;
				scanf( "%d", &j );
				if ( j==1 )
				{
					fr = fopen( "data/released.dat", "ab" );
					ft = fopen( "data/temp.dat", "wb" );
					rewind(fc);
					while( fread( &c[0], sizeof(c[0]), 1, fc ) == 1 )
					{
						if ( strcmp( c[i].name, c[0].name ) != 0 )
						{
							fwrite( &c[0], sizeof(c[0]), 1, ft );
						}
						else {
							c[0].cell=0;
							strcpy( c[0].prison, "released" );
							fwrite( &c[0], sizeof(c[0]), 1, fr );
						}
					}
					fclose(fr);
					fclose(fc);
					fclose(ft);
					if ( *login == 1 )
					{
						remove( "data/PS1.dat" );
						rename( "data/temp.dat", "data/PS1.dat" );
					}
					else if ( *login == 2 )
					{
						remove( "data/PS2.dat" );
						rename( "data/temp.dat", "data/PS2.dat" );
					}
					else if ( *login == 3 )
					{
						remove( "data/PS3.dat" );
						rename( "data/temp.dat", "data/PS3.dat" );
					}
					else if ( *login == 4 )
					{
						remove( "data/PS4.dat" );
						rename( "data/temp.dat", "data/PS4.dat" );
					}
					else if ( *login == 5 )
					{
						remove( "data/PS5.dat" );
						rename( "data/temp.dat", "data/PS5.dat" );
					}
					printf( "\nCriminal Succesfully Removed from the prison" );
					printf( "\n\npress any key to continue..." );
					getch();
				}
			}
		}
	}
	else if ( *login == 6 )
	{
		int i, z;
		criminal c[40];
		int a[40];
		i=0;
		printf( "\n\n\n\tS.No\tName\t\t\t\tCriminal ID\t\tPolice Station\t\tCharge on Criminal\n\n   " );
		for ( z=1;z<=5;z++ )
		{
			if ( z == 1 )
			{
				fc = fopen( "data/PS1.dat", "rb" );
			}
			else if ( z == 2 )
			{
				fc = fopen( "data/PS2.dat", "rb" );
			}
			else if ( z == 3 )
			{
				fc = fopen( "data/PS3.dat", "rb" );
			}
			else if ( z == 4 )
			{
				fc = fopen( "data/PS4.dat", "rb" );
			}
			else if ( z == 5 )
			{
				fc = fopen( "data/PS5.dat", "rb" );
			}
			if ( fc == NULL )
			{
				printf( "file PS%d cannot open!", z );
				return 0;
			}
			else {
				rewind(fc);
				while ( fread( &c[0], sizeof(c[0]), 1, fc ) == 1 )
				{
					if ( strcmp( c[0].name, name ) == 0 || c[0].ID == id )
					{
						i++;
						c[i] = c[0];
						a[i] = z;
						if ( strlen(c[i].name)<16 )
						{
							printf( "\t%d\t%s\t\t\t%u\t\tPS 0%d\t\t\t%s\n\n", i, c[i].name, c[i].ID, z, c[i].chg );
						}
						else {
							printf( "\t%d\t%s\t\t%u\t\tPS 0%d\t\t\t%s\n\n", i, c[i].name, c[i].ID, z, c[i].chg );
						}
					}
				}
				fclose(fc);
			}
		}
		if ( i == 0 )
		{
			system("cls");
			printf( "\n\n\n\t\t\t\t\t\t\t\t      Release a Criminal\n\t\t\t\t\t\t\t\t  " );
			for ( i=0;i<33;i++ )
			{	printf( "_" );	}
			printf( "\n\n\nNo criminal found..." );
			printf( "\n\npress any key to continue..." );
			getch();
			fclose(fc);
			return 0;
		}
		else {
			printf( "\n\nChoose S.No of a Criminal to release " );
			scanf( "%d", &i );
			printf( "\nAre you sure you want to release the criminal?(Yes=1, No=0)" );
			int j;
			scanf( "%d", &j );
			if ( j==1 )
			{
				if ( a[i]==1 )
				{
					fc = fopen( "data/PS1.dat", "rb" );
				}
				else if ( a[i] == 2 )
				{
					fc = fopen( "data/PS2.dat", "rb" );
				}
				else if ( a[i] == 3 )
				{
					fc = fopen( "data/PS3.dat", "rb" );
				}
				else if ( a[i] == 4 )
				{
					fc = fopen( "data/PS4.dat", "rb" );
				}
				else if ( a[i] == 5 )
				{
					fc = fopen( "data/PS5.dat", "rb" );
				}
				fr = fopen( "data/released.dat", "ab" );
				ft = fopen( "data/temp.dat", "wb" );
				rewind(fc);
				while( fread( &c[0], sizeof(c[0]), 1, fc ) == 1 )
				{
					if ( strcmp( c[i].name, c[0].name ) != 0 )
					{
						fwrite( &c[0], sizeof(c[0]), 1, ft );
					}
					else {
						strcpy( c[0].prison, "released" );
						c[0].cell=0;
						fwrite( &c[0], sizeof(c[0]), 1, fr );
					}
				}
				fclose(fr);
				fclose(fc);
				fclose(ft);
				if ( a[i] == 1 )
				{
					remove( "data/PS1.dat" );
					rename( "data/temp.dat", "data/PS1.dat" );
				}
				else if ( a[i] == 2 )
				{
					remove( "data/PS2.dat" );
					rename( "data/temp.dat", "data/PS2.dat" );
				}
				else if ( a[i] == 3 )
				{
					remove( "data/PS3.dat" );
					rename( "data/temp.dat", "data/PS3.dat" );
				}
				else if ( a[i] == 4 )
				{
					remove( "data/PS4.dat" );
					rename( "data/temp.dat", "data/PS4.dat" );
				}
				else if ( a[i] == 5 )
				{
					remove( "data/PS5.dat" );
					rename( "data/temp.dat", "data/PS5.dat" );
				}
				printf( "\nCriminal Succesfully Removed from the prison" );
				printf( "\n\npress any key to continue..." );
				getch();
			}
		}
		return 0;
	}
}

int search ( const int *login )
{
	criminal c[100];
	unsigned int id = 0;
	char name[50] = {}, charge[60] = {};
	system("cls");
	printf( "\n\n\n\t\t\t\t\t\t\t\t      Criminal Search\n\t\t\t\t\t\t\t\t" );
	int i;
	for ( i=0;i<28;i++ )
	{	printf( "_" );	}
	printf( "\n\n\n\tSearch a criminal by:\n\n" );
	printf( "\t1. Name\n\n" );
	printf( "\t2. ID\n\n" );
	printf( "\t3. Charge\n\n" );
	int o;
	scanf( "%d", &o );
	printf( "\n    ------------------------------------------\n\n" );
	switch ( o )
	{
		case 1:
			printf( "\tEnter Name: " );
			fflush(stdin);
			gets( name );
			break;
		case 2:
			printf( "\tEnter ID: " );
			fflush(stdin);
			scanf( "%u", &id );
			break;
		case 3:
			printf( "\tEnter Charge: " );
			fflush(stdin);
			gets( charge );
			break;
		default:
			return 0;
	}
	FILE *fc;
	if ( *login>=1 && *login<=5 )
	{
		criminal c[40];
		if ( *login==1 )
		{
			fc = fopen( "data/PS1.dat", "rb" );
		}
		else if ( *login==2 )
		{
			fc = fopen( "data/PS2.dat", "rb" );
		}
		else if ( *login==3 )
		{
			fc = fopen( "data/PS3.dat", "rb" );
		}
		else if ( *login==4 )
		{	
			fc = fopen( "data/PS4.dat", "rb" );
		}
		else if ( *login==5 )
		{
			fc = fopen( "data/PS5.dat", "rb" );
		}
		
		if ( fc == NULL )
		{	
			system("cls");
			puts("\n\nfile could not open!");
			printf( "\npress any key to continue..." );
			getch();
			return 0;
		}
		else {
			while ( i>=0 )
			{
				system("cls");
				printf( "\n\n\n\t\t\t\t\t\t\t\t      Criminal Search\n\t\t\t\t\t\t\t\t" );
				for ( i=0;i<28;i++ )
				{	printf( "_" );	}
				printf( "\n\n\t--------------Your Searched Criminal/s--------------\n\n" );
				i=0;
				rewind(fc);
				printf( "\tS.No\tName\t\t\t\tCriminal ID\t\tCharge on Criminal\n   " );
		
				while ( fread( &c[i], sizeof(c[i]), 1, fc ) == 1 )
				{
					if ( strcmp( c[i].name, name ) == 0 || c[i].ID == id || strcmp( c[i].chg, charge ) == 0 )
					{
						if ( strlen(c[i].name)<16 )
						{
							printf( "\n\t%d\t%s\t\t\t%u\t\t%s\n", i+1, c[i].name, c[i].ID, c[i].chg );
						}
						else {
							printf( "\n\t%d\t%s\t\t%u\t\t%s\n", i+1, c[i].name, c[i].ID, c[i].chg );
						}
						i++;
					}
				}
				if ( i == 0 )
				{
					system("cls");
					printf( "\n\n\n\t\t\t\t\t\t\t\t      Criminal Search\n\t\t\t\t\t\t\t\t" );
					for ( i=0;i<28;i++ )
					{	printf( "_" );	}
					printf( "\n\n\nNo criminal found..." );
					printf( "\n\npress any key to continue..." );
					getch();
					break;
				}
				else{
					printf( "\n\nEnter S.No of a Criminal to view it's details(Enter -1 to go back): " );
					scanf( "%d", &i );
					if( i>0 )
					{
						display( c[i-1] );
					}
				}
			}
			fclose(fc);
		}
		return 0;
	}
	else if ( *login == 6 )
	{
		int i=1;
		while( i>=0 )
		{
			system("cls");
			printf( "\n\n\n\t\t\t\t\t\t\t\t      Criminal Search\n\t\t\t\t\t\t\t\t" );
			for ( i=0;i<28;i++ )
			{	printf( "_" );	}
			printf( "\n\n\t--------------Your Searched Criminal/s--------------\n\n" );
			printf( "\tS.No\tName\t\t\t\tCriminal ID\t\tPolice Station\t\tCharge on Criminal\n\n   " );
			int z;
			criminal c[120];
			FILE *fc;
			i=0;
			for ( z=1;z<=5;z++ )
			{
				if ( z == 1 )
				{
					fc = fopen( "data/PS1.dat", "rb" );
				}
				else if ( z == 2 )
				{
					fc = fopen( "data/PS2.dat", "rb" );
				}
				else if ( z == 3 )
				{
					fc = fopen( "data/PS3.dat", "rb" );
				}
				else if ( z == 4 )
				{
					fc = fopen( "data/PS4.dat", "rb" );
				}
				else if ( z == 5 )
				{
					fc = fopen( "data/PS5.dat", "rb" );
				}
				if ( fc == NULL )
				{
					printf( "file PS%d cannot open!", z );
					return 0;
				}
				else {
					rewind(fc);
					while ( fread( &c[i], sizeof(c[i]), 1, fc ) == 1 )
					{
						if ( strcmp( c[i].name, name ) == 0 || c[i].ID == id || strcmp( c[i].chg, charge ) == 0 )
						{
							if ( strlen(c[i].name)<16 )
							{
								printf( "\t%d\t%s\t\t\t%u\t\tPS 0%d\t\t\t%s\n\n", i+1, c[i].name, c[i].ID, z, c[i].chg );
							}
							else {
								printf( "\t%d\t%s\t\t%u\t\tPS 0%d\t\t\t%s\n\n", i+1, c[i].name, c[i].ID, z, c[i].chg );
							}
							i++;
						}
					}
					fclose(fc);
				}
			}
			if ( i == 0 )
				{
					system("cls");
					printf( "\n\n\n\t\t\t\t\t\t\t\t      Criminal Search\n\t\t\t\t\t\t\t\t" );
					for ( i=0;i<28;i++ )
					{	printf( "_" );	}
					printf( "\n\n\nNo criminal found..." );
					printf( "\n\npress any key to continue..." );
					getch();
					break;
				}
			else {
				printf( "\nEnter S.No of a Criminal to view it's details(Enter -1 to go back): " );
				scanf( "%d", &i );
				if( i>0 )
				{
					display( c[i-1] );
				}
			}
		}
		return 0; 
	}
}

void display ( criminal c )
{
	system("cls");
	printf( "\n\n\t--------------Criminal**********--------------" );
	printf("\n\n\nName: ");
	puts( c.name );
	
	printf( "\nCell No: %d", c.cell );
	printf( "\n\nID of Criminal: %u", c.ID );

	printf("\n\nNationality: ");
	puts( c.nlt );

	printf("\nGender: ");
	puts( c.gen );
	
	printf("\nDate of Birth(DD/MM/YYYY): ");
	puts( c.date );

	printf("\nAge: %d", c.age);

	printf( "\n\nThe Height of the criminal: " );
	puts( c.height );
	
	printf( "\nThe Weight of the criminal: " );
	puts( c.weight );
	
	printf( "\nSkin color: " );
	puts( c.color );
	
	printf("\nCharge on the criminal: ");
	puts( c.chg );
	
	printf( "\nDuration in prison: %.1f", c.yrs );
	
	printf("\n\nDate of Arrest(DD/MM/YYYY): ");
	puts( c.arrest );

	printf("\nCurrently in prison/not in prison?: ");
	puts( c.prison );

	printf( "\n\npress any key to continue..." );
	getch(); 
	return;
}

void display2 ( criminal c )
{
	system("cls");
	printf( "\n\n\t**********Criminal**********" );
	printf("\n\n\nName: ");
	puts( c.name );
	
	printf( "\nID of Criminal: %u", c.ID );

	printf("\n\nNationality: ");
	puts( c.nlt );

	printf("\nGender: ");
	puts( c.gen );
	
	printf("\nDate of Birth(DD/MM/YYYY): ");
	puts( c.date );

	printf("\nAge: %d", c.age);

	printf( "\n\nThe Height of the criminal: " );
	puts( c.height );
	
	printf( "\nThe Weight of the criminal: " );
	puts( c.weight );
	
	printf( "\nSkin color: " );
	puts( c.color );
	
	printf("\nCharge on the criminal: ");
	puts( c.chg );
	
	printf( "\nDuration in prison: %.1f", c.yrs );
	
	printf("\n\nDate of Arrest(DD/MM/YYYY): ");
	puts( c.arrest );

	printf("\nCurrently in prison/not in prison?: ");
	puts( c.prison );

	printf( "\n\npress any key to continue..." );
	getch(); 
	return;
}

int list ( const int *login )
{
	if ( *login>=1 && *login<=5 )
	{
		criminal c[40];
		FILE *fc;
		if ( *login==1 )
		{
			fc = fopen( "data/PS1.dat", "rb" );
		}
		else if ( *login==2 )
		{
			fc = fopen( "data/PS2.dat", "rb" );
		}
		else if ( *login==3 )
		{
			fc = fopen( "data/PS3.dat", "rb" );
		}
		else if ( *login==4 )
		{	
			fc = fopen( "data/PS4.dat", "rb" );
		}
		else if ( *login==5 )
		{
			fc = fopen( "data/PS5.dat", "rb" );
		}
		
		if ( fc == NULL )
		{	
			system("cls");
			puts("\n\nfile could not open!");
			printf( "\npress any key to continue..." );
			getch();
			return 0;
		}
		else {
			int i=0;
			while( i>=0 )
			{
				system("cls");
				printf( "\n\n\n\tS.No\tName\t\t\t\tCriminal ID\t\tCharge on Criminal\n   " );
				for ( i=0;i<150;i++ )
				{
					printf( "_" );
				}
				printf( "\n\n\n" );
				rewind(fc);
				for ( i=0 ; fread( &c[i], sizeof(c[i]), 1, fc ) == 1 ; )
				{
					if ( strlen(c[i].name)<16 )
					{
						printf( "\t%d\t%s\t\t\t%u\t\t%s\n\n", i+1, c[i].name, c[i].ID, c[i].chg );
					}
					else {
						printf( "\t%d\t%s\t\t%u\t\t%s\n\n", i+1, c[i].name, c[i].ID, c[i].chg );
					}
					i++;
				}
				printf( "Enter S.No of a Criminal to view it's details(Enter -1 to go back): " );
				scanf( "%d", &i );
				if( i>0 )
				{
					display( c[i-1] );
				}
			}
		fclose(fc);
		}
	}
	else if ( *login == 6 ) 
	{
		int i=1;
		while( i>=0 )
		{
			system("cls");
			printf( "\n\n\n\tS.No\tName\t\t\t\tCriminal ID\t\tPolice Station\t\tCharge on Criminal\n   " );
			for ( i=0;i<150;i++ )
			{
				printf( "_" );
			}
			printf( "\n\n\n" );
			int z;
			criminal c[120];
			FILE *fc;
			i=0;
			for ( z=1;z<=5;z++ )
			{
				if ( z == 1 )
				{
					fc = fopen( "data/PS1.dat", "rb" );
				}
				else if ( z == 2 )
				{
					fc = fopen( "data/PS2.dat", "rb" );
				}
				else if ( z == 3 )
				{
					fc = fopen( "data/PS3.dat", "rb" );
				}
				else if ( z == 4 )
				{
					fc = fopen( "data/PS4.dat", "rb" );
				}
				else if ( z == 5 )
				{
					fc = fopen( "data/PS5.dat", "rb" );
				}
				if ( fc == NULL )
				{
					printf( "file PS%d cannot open!", z );
					return 0;
				}
				else {
					rewind(fc);
					while ( fread( &c[i], sizeof(c[i]), 1, fc ) == 1 )
					{
						if ( strlen(c[i].name)<16 )
						{
							printf( "\t%d\t%s\t\t\t%u\t\tPS 0%d\t\t\t%s\n\n", i+1, c[i].name, c[i].ID, z, c[i].chg );
						}
						else {
							printf( "\t%d\t%s\t\t%u\t\tPS 0%d\t\t\t%s\n\n", i+1, c[i].name, c[i].ID, z, c[i].chg );
						}
						i++;
					}
					fclose(fc);
				}
			}
			printf( "Enter S.No of a Criminal to view it's details(Enter -1 to go back): " );
			scanf( "%d", &i );
			if( i>0 )
			{
				display( c[i-1] );
			}
		}
		return 0; 
	}
} //end of list function 

int add_most ( void )
{
	system ("cls");
	int i;
	printf( "\n\n\n\t\t\t\t\t\t\t    Registration Of A Most Wanted Criminal\n\t\t\t\t\t\t\t    " ); 
	for ( i=0;i<40;i++ )
	{	printf( "_" );	}
	mwanted m;
	fflush(stdin);
	printf("\n\n\nName: ");
	gets( m.name );
	fflush(stdin);
	printf( "\nThe Height of the criminal: " );
	gets( m.height );
	printf( "\nSkin color: " );
	gets( m.color );
	printf("\nCharge on the criminal: ");
	gets ( m.chg );
	printf("\nWanted Stars: ");
	gets ( m.stars );
	FILE *fm;
	fm = fopen( "data/most.DAT", "ab+" );
	if(fm==NULL) 
	{
		fm = fopen( "data/most.DAT", "wb+" );
	}
	printf( "\n\nThe Data of the Criminal has been Recorded.\n\nPress any key to continue..." );
	fwrite( &m, sizeof ( mwanted ), 1, fm );
	fclose(fm);
	getch();
	return 0;
}

int view_most ( void )
{
	system("cls");
	mwanted c[30];
	FILE *fp=fopen("data/most.DAT","rb+");
	if(fp==NULL) {
		puts("file does not exist");
		getche();
		return;
	}
	int i=0;
		while( i>=0 )
		{
			system("cls");
			printf( "\n\n\n\tS.No\tName\t\t\tWanted Stars\n   " );
			for ( i=0;i<150;i++ )
			{
				printf( "_" );
			}
			printf( "\n\n\n" );
			rewind(fp);
			for ( i=0 ; fread( &c[i], sizeof(c[0]), 1, fp ) == 1 ; )
			{
				if ( strlen(c[i].name)<16 )
				{
					printf( "\t%d\t%s\t\t%s\n\n", ++i, c[i].name, c[i].stars );
				}
				else {
					printf( "\t%d\t%s\t%s\n\n", ++i, c[i].name, c[i].stars );
				}
			}
			printf( "Enter serial No of a criminal to view it's details(Enter -1 to go back): " );
			scanf( "%d", &i );
				if( i>0 )
			{
				mostwanted( c[i-1] );
			}
		}
	fclose(fp);
	return 0;
}
void mostwanted ( mwanted m )
{
	system("cls");
	printf( "\n\n\t**********Most Wanted Criminal**********" );
	printf("\n\n\nName: ");
	puts( m.name );
	printf( "\nThe Height of the criminal: " );
	puts( m.height );
	printf( "\nSkin color: " );
	puts( m.color );
	printf("\nCharge on the criminal: ");
	puts( m.chg );
	printf( "\nWanted Stars: " );
	puts( m.stars );
	printf( "\n\npress any key to continue..." );
	getch(); 
	return;
}

int released( void )
{
	criminal c[60];
	FILE *fr = fopen("data/released.DAT","rb+");;
	
	if(fr==NULL) {
		printf("file not on disk\n");
		getche();
		return;
	}
	int i=0;
		while( i>=0 )
		{
			system("cls");
			printf( "\n\n\n\tS. No\tName\n   " );
			for ( i=0;i<150;i++ )
			{
				printf( "_" );
			}
			printf( "\n\n\n" );
			rewind(fr);
			for ( i=0 ; fread( &c[i], sizeof(c[0]), 1, fr ) == 1 ; )
			{
				if ( strlen(c[i].name)<16 )
				{
					printf( "\t%d\t%s\n\n", ++i, c[i].name );
				}
				else {
					printf( "\t%d\t%s\n\n", ++i, c[i].name );
				}
			}
			printf( "Enter serial No of a criminal to view it's details(Enter -1 to go back): " );
			scanf( "%d", &i );
			if( i>0 )
			{
				display2( c[i-1] );
			}
		}
	fclose(fr);
	return 0;
}

int crime_rate ( void )
{
	system("cls");
	printf( "\n\n\n\t\t\t\t\t\t\t\t\tCrime Rate\n\t\t\t\t\t\t\t    " ); 
	int z, *count;
	for ( z=0;z<40;z++ )
	{	printf( "_" );	}
	count = (int *)calloc ( 5, sizeof( int ) );
	float cr, total=0;
	criminal c;
	FILE *fc;
	for ( z=1;z<=5;z++ )
	{
		if ( z == 1 )
		{
			fc = fopen( "data/PS1.dat", "rb" );
		}
		else if ( z == 2 )
		{
			fc = fopen( "data/PS2.dat", "rb" );
		}
		else if ( z == 3 )
		{
			fc = fopen( "data/PS3.dat", "rb" );
		}
		else if ( z == 4 )
		{
			fc = fopen( "data/PS4.dat", "rb" );
		}
		else if ( z == 5 )
		{
			fc = fopen( "data/PS5.dat", "rb" );
		}
		if ( fc == NULL )
		{
			printf( "file PS%d cannot open!", z );
			return 0;
		}
		else {
			
			rewind(fc);
			while ( fread( &c, sizeof(c), 1, fc ) == 1 )
			{
				count[z-1]++;
				total++;
			}
			fclose(fc);
		}
	}
	for ( z=0;z<5;z++ )
	{
		printf( "\n\n\t########### Police Station %d ###########\n\n", z+1 );
		printf( "\t\tNumber of criminals: %d\n\n", count[z] );
		printf( "\t\tCrime Rate: %.2f\n\n", ( count[z] / total ) );	
	}
	free( count );
	printf( "\n\npress any key to go back..." );
	getch();
}
